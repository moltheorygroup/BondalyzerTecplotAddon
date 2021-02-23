
#include "TECADDON.h"
#include "ADDGLBL.h"
#include "GUIDEFS.h"
#if !defined (MSWIN)
#include <unistd.h>
#endif

#include <string>
#include <sstream>
#include <vector>
#include <map>

#include <armadillo>

#include "CSM_DATA_SET_INFO.h"
#include "CSM_CRIT_POINTS.h"
#include "CSM_GBAGUI.h"

using std::vector;
using std::string;
using std::stringstream;
using std::to_string;

using namespace arma;

std::map<string, int> NuclearNameToCPNum;

void ListDeselect(LgIndex_t ListID){
	vector<string> StrList;
	for (int i = 1; i <= TecGUIListGetItemCount(ListID); ++i){
		StrList.push_back(TecGUIListGetString(ListID, i));
	}
	TecGUIListDeleteAllItems(ListID);
	for (auto const & s : StrList){
		TecGUIListAppendItem(ListID, s.c_str());
	}
}

vector<string> ListGetSelectedStrings(LgIndex_t ListID){
	LgIndex_t * SelItemNums;
	LgIndex_t NumSelItems;

	vector<string> StrList;

	TecGUIListGetSelectedItems(ListID, &SelItemNums, &NumSelItems);
	if (NumSelItems > 0){
		for (int i = 0; i < NumSelItems; ++i)
			StrList.push_back(TecGUIListGetString(ListID, SelItemNums[i]));

		TecUtilArrayDealloc(reinterpret_cast<void**>(&SelItemNums));
	}
	
	return StrList;
}

vector<int> ListGetSelectedItemNums(LgIndex_t ListID){
	LgIndex_t * SelItemNums;
	LgIndex_t NumSelItems;

	vector<int> IntList;

	TecGUIListGetSelectedItems(ListID, &SelItemNums, &NumSelItems);
	if (NumSelItems > 0){
		for (int i = 0; i < NumSelItems; ++i)
			IntList.push_back(SelItemNums[i]);

		TecUtilArrayDealloc(reinterpret_cast<void**>(&SelItemNums));
	}

	return IntList;
}

void ListPopulateWithVarNames(LgIndex_t ListID, int StartVarNum){
	EntIndex_t NumVars = TecUtilDataSetGetNumVars();
	for (int i = StartVarNum; i <= NumVars; ++i){
		char * VarName;
		TecUtilVarGetName(i, &VarName);
		TecGUIListAppendItem(ListID, VarName);
		TecUtilStringDealloc(&VarName);
	}
}

vec3 GetCoordsFromListItem(LgIndex_t ItemIndex, 
	LgIndex_t ListIndex,
	string* ItemFullString,
	string* ItemNameString,
	int* ItemNumber,
	int* ZoneNumber, 
	bool*  IsCP, 
	vector<int>* NumberOfCPs)
{
	vec3 Out;

	char * ItemStringCStr = TecGUIListGetString(ListIndex, ItemIndex);

	int ItemNum;
	string ItemString = ItemStringCStr;
	string ItemName = ItemString.substr(0, ItemString.find_last_of(' '));
	ItemNum = stoi(ItemString.substr(ItemString.find_last_of(' '), ItemString.length()));

	if (ItemFullString != nullptr)
		*ItemFullString = ItemString;
	if (ItemNameString != nullptr)
		*ItemNameString = ItemName;
	if (ItemNumber != nullptr)
		*ItemNumber = ItemNum;

	EntIndex_t ItemZoneNum = -1;
	
	if (SearchVectorForString(CPNameList, ItemName) >= 0 && ItemName.find_first_of(' ') == string::npos){
		if (IsCP != nullptr)
			*IsCP = true;
		ItemZoneNum = ZoneNumByName(string("Critical Points"));
		EntIndex_t CPVarNum = VarNumByName(string("CritPointType"));

		int Ranks[4] = { -3, -1, 1, 3 };
		LgIndex_t IJK[3];
		vector<int> NumCPs;
		if (NumberOfCPs != nullptr && NumberOfCPs->size() == 4)
			NumCPs = *NumberOfCPs;
		else{
			NumCPs = { 0, 0, 0, 0 };
			if (ItemZoneNum > 0 && CPVarNum > 0){
				for (int i = 0; i < 4; ++i){
					NumCPs[i] = stoi(AuxDataZoneGetItem(ItemZoneNum, CCDataNumCPs[i]));
				}
			}
			if (NumberOfCPs != nullptr)
				*NumberOfCPs = NumCPs;
		}

		for (int j = 0; j < 4; ++j){
			if (ItemName == CPNameList[j]){
				int RealCPNum = 0;
				for (int k = 0; k < j; ++k){
					RealCPNum += NumCPs[k];
				}
				ItemNum = RealCPNum + ItemNum;
				break;
			}
		}
	}
	else{
		if (IsCP != nullptr)
			*IsCP = false;
		for (int ZoneNum = 1; ZoneNum <= TecUtilDataSetGetNumZones() && ItemZoneNum < 0; ++ZoneNum){
			char* ZoneNameCStr;
			if (TecUtilZoneGetName(ZoneNum, &ZoneNameCStr)){
				if (ItemName.compare(ZoneNameCStr) == 0){
					ItemZoneNum = ZoneNum;
				}

				TecUtilStringDealloc(&ZoneNameCStr);
			}
		}
	}

	if (ZoneNumber != nullptr)
		*ZoneNumber = ItemZoneNum;

	EntIndex_t XYZVarNums[3] = { -1, -1, -1 };
	TecUtilAxisGetVarAssignments(&XYZVarNums[0], &XYZVarNums[1], &XYZVarNums[2]);
	if (XYZVarNums[0] < 0 || XYZVarNums[1] < 0 || XYZVarNums[2] < 0){
		for (int i = 1; i <= 3; ++i){
			XYZVarNums[i - 1] = i;
		}
	}

	for (int j = 0; j < 3; ++j){
		Out[j] = TecUtilDataValueGetByZoneVar(ItemZoneNum, XYZVarNums[j], ItemNum);
	}

	TecUtilStringDealloc(&ItemStringCStr);

	return Out;
}