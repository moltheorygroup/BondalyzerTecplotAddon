/*
*****************************************************************
*****************************************************************
*******                                                  ********
*******    (C) Copyright 1988-2013 by TECPLOT INC.       *******
*******                                                  ********
*****************************************************************
*****************************************************************
*/

#ifndef  ENGINE_H_
#define ENGINE_H_ /* Only include once */

#include <fstream>
#include <vector>

#include "CSM_CRIT_POINTS.h"
#include "CSM_GRAD_PATH.h"
#include "CSM_GUI.h"

using std::vector;
using std::string;

enum BondalyzerCalcType_e{
	BondalyzerCalcType_CriticalPoints,
	BondalyzerCalcType_BondPaths,
	BondalyzerCalcType_RingLines,
	BondalyzerCalcType_CageNuclearPaths,
	BondalyzerCalcType_InteratomicSurfaces,
	BondalyzerCalcType_RingSurfaces,
	BondalyzerCalcType_BondBundleSurfaces,
	BondalyzerCalcType_RingBundleSurfaces,

	BondalyzerCalcType_GBA,

	BondalyzerCalcType_Batch,

	BondalyzerCalcType_Invalid
};

static vector<string> const BondalyzerStepGUITitles = {
	"critical points",
	"bond paths",
	"ring lines",
	"cage-nuclear paths",
	"interatomic surfaces",
	"ring surfaces",
	"bond bundle surfaces",
	"ring bundle surfaces",
	"gradient bundle analysis",
	"batch analysis"
};


void RefineActiveZones();
void GetClosedIsoSurfaceFromPoints();
void GetClosedIsoSurfaceFromNodes();
void GetAllClosedIsoSurfaces();
void ConnectCPsGetUserInfo();
void DrawEigenvectorArrowsGetUserInfo();
class FieldDataPointer_c;
void GetClosedIsoSurface(int IsoZoneNum, const std::vector<FieldDataPointer_c> & IsoReadPtrs, std::vector<int> & NodeNums);
void MakeSurfaceFromPathZonesGetUserInfo();
void MakeSliceFromPointSelectionGetUserInfo();

void GradientPathsOnSphereGetUserInfo();

void BondalyzerGetUserInfo(BondalyzerCalcType_e CalcType, vector<GuiField_c> const PassthroughFields = vector<GuiField_c>());

void VarNameFindReplaceGetUserInfo();
void ZoneNameFindReplaceGetUserInfo();

void GradientPathToolGetUserInfo();

Boolean_t FindCritPoints(int VolZoneNum,
	vector<int> const & XYZVarNums,
	int RhoVarNum,
	vector<int> const & GradVarNums,
	vector<int> const & HessVarNums,
	Boolean_t IsPeriodic,
	double const & CellSpacing);

void DeleteCPsGetUserInfo();
void ExtractCPsGetUserInfo();
void CombineCPZonesGetUserInfo();

Boolean_t BondalyzerBatch(int VolZoneNum,
	vector<int> const & CPZoneNums,
	int CPTypeVarNum,
	vector<int> const & XYZVarNums,
	int RhoVarNum,
	vector<int> const & GradVarNums,
	vector<int> const & HessVarNums,
	Boolean_t IsPeriodic,
	int RidgeFuncVarNum,
	vector<bool> const & CalcSteps);

Boolean_t FindBondRingLines(int VolZoneNum,
	vector<int> const & OtherCPZoneNums,
	int SelectedCPZoneNum,
	vector<int> SelectedCPNums,
	int CPTypeVarNum,
	CPType_e const & CPType,
	vector<int> const & XYZVarNums,
	int RhoVarNum,
	vector<int> const & GradVarNums,
	vector<int> const & HessVarNums,
	Boolean_t IsPeriodic);

Boolean_t FindCageNuclearPaths(int VolZoneNum,
	vector<int> const & OtherCPZoneNums,
	int SelectedCPZoneNum,
	vector<int> SelectedCPNums,
	int CPTypeVarNum,
	vector<int> const & XYZVarNums,
	int RhoVarNum,
	vector<int> const & GradVarNums,
	vector<int> const & HessVarNums,
	Boolean_t IsPeriodic);

Boolean_t FindBondRingSurfaces(int VolZoneNum,
	vector<int> const & OtherCPZoneNums,
	int SelectedCPZoneNum,
	vector<int> SelectedCPNums,
	int CPTypeVarNum,
	CPType_e const & CPType,
	vector<int> const & XYZVarNums,
	int RhoVarNum,
	vector<int> const & GradVarNums,
	vector<int> const & HessVarNums,
	int RCSFuncVarNum,
	Boolean_t IsPeriodic);

void ExtractRadiusContourLinesToIOrderedPoints(vector<int> const & ZoneNums,
	vec3 const & Origin, 
	double const & Radius,
	vector<int> const & XYZVarNums);

void ExtractRSIntersectionsGetUserInfo();
void ExtractSurfaceSphereIntersections(
	int VolZoneNum,
	int CPTypeVarNum,
	int AllCPZoneNum,
	vector<int> const & CPList,
	int CPZoneNum,
	double const & Radius,
	int ResampleNumPoints,
	vector<int> const & XYZVarNums,
	vector<GradPath_c> & Intersections);

Boolean_t GBA_Generation(
	int VolZoneNum,
	int CPZoneNum,
	int CPTypeVarNum,
	vector<int> const & XYZVarNums,
	int RhoVarNum,
	vector<int> const & GradVarNums,
	vector<int> const & HessVarNums,
	Boolean_t IsPeriodic,
	vector<int> const & SelectedCPNums,
	double const & SphereRadius,
	int RadiusMode,
	int RefinementLevel,
	double const & RhoCutoff,
	int NumGBEdgePoints,
	int GPNumPoints
	);

Boolean_t CPNumbersMapBetweenZones(int AllCPsZoneNum,
	int SelectedCPZoneNum,
	vector<int> const & XYZVarNums,
	vector<int> const & SelectedCPNums,
	vector<int> & MappedCPNums);

void TestFunction();


#endif /* ENGINE_H_ */
