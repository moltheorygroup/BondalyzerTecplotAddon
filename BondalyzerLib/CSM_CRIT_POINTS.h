#pragma once
#ifndef CSMCRITPOINTS_H_
#define CSMCRITPOINTS_H_

// #include <gsl/gsl_vector.h>
// #include <gsl/gsl_matrix.h>
// #include <gsl/gsl_multiroots.h>

#include "CSM_DATA_SET_INFO.h"
#include "CSM_DATA_TYPES.h"

#include <vector>

#include <armadillo>
using namespace arma;



#define MaxCPIter 100
#define CheckPosIter 5
#define DefaultCellSpacing 0.05

using std::vector;

enum CPType_e{
	ATOMCP = -3,
	BONDCP = -1,
	RINGCP = 1,
	CAGECP = 3,
	RINGCPFF = 11,
	CAGECPFF = 13
};

// const static char CPTypeList[] = { -3, -1, 1, 3, 11, 13 };
const static char CPTypeList[] = { ATOMCP, BONDCP, RINGCP, CAGECP, RINGCPFF, CAGECPFF };

const static vector<string> CPNameList = { "Nuclear", "Bond", "Ring", "Cage", "Ring FF", "Cage FF" };

const static vector<ColorIndex_t> CPColorList = { White_C, Red_C, Green_C, Cyan_C, Custom5_C, Custom6_C };

/*
	*	Group of critical points
	*/
class CritPoints_c
{
public:
	CritPoints_c();
	// Specify a cutoff value during construction
	CritPoints_c(const double & RhoCutoff, const int & NumDimensions);
	// Construct from a set of other CritPoints_c's
	CritPoints_c(const vector<CritPoints_c> & CPLists);
	// Construct from existing CP zone
	CritPoints_c(const int & CPZoneNum, const vector<int> & XYZVarNums, const int & RhoVarNum, const int & CPTypeVarNum);
	~CritPoints_c();

	/*
		*	Operator overloads
		*/
	CritPoints_c & operator+=(const CritPoints_c & rhs);

	/*
		*	Getter methods
		*/
	const double GetRhoCutoff() const { return m_RhoCutoff; }

	const int NumCPs() const { return m_TotNumCPs; }
	const int NumCPs(const int & TypeNum) const { return m_NumCPs[TypeNum]; }
	const int NumAtoms() const { return m_NumCPs[0]; }
	const int NumBonds() const { return m_NumCPs[1]; }
	const int NumRings() const { return m_NumCPs[2]; }
	const int NumCages() const { return m_NumCPs[3]; }
	const int NumFFRings() const { return m_NumCPs[4]; }
	const int NumFFCages() const { return m_NumCPs[5]; }
	const int NumDimensions() const { return m_Dimensions; }

	vector<int> GetTypeNumOffsetFromTotOffset(const int & TotOffset) const;
	const int GetTotOffsetFromTypeNumOffset(const int & TypeNum, const int & TypeOffset) const;

	const double GetMinCPDist();

	const double GetRho(const int & TypeNum, const int & Offset) const { return m_Rho[TypeNum][Offset]; }
	const double GetRho(const int & TotOffset) const;
	vec3 GetXYZ(const int & TypeNum, const int & Offset) const { return m_XYZ[TypeNum][Offset]; }
	vec3 GetXYZ(const int & TotOffset) const;
	vec3 GetPrincDir(const int & TypeNum, const int & Offset) const { return m_PrincDir[TypeNum][Offset]; }
	vec3 GetPrincDir(const int & TotOffset) const;

	const Boolean_t IsValid() const;

	/*
		*	Setter methods
		*/
	void SetMinCPDist(const double & MinCPDist){ m_MinCPDist = MinCPDist; }
	const Boolean_t AddPoint(const double & Rho,
		const vec3 & Pos,
		const vec3 & PrincDir,
		const char & Type);
	const Boolean_t RemPoint(const int & PointIndex);
	const Boolean_t RemPoint(const int & PointIndex,
		const char & Type);
	void Append(const CritPoints_c & rhs);

	/*
		*	Mutators and other methods
		*/

	const Boolean_t FindMinCPDist();
	
	const vector<int> SaveAsOrderedZone(const vector<int> & XYZVarNum, const int & RhoVarNum, const Boolean_t & SaveCPTypeZones = FALSE);

private:


	/*
		*	m_Rho, m_XYZ, m_PrincDir, and m_NumCPs are length 6 so they store
		*	information for the 6 types of critical points.
		*/
	vector<double> m_Rho[6];
	vector<vec3> m_XYZ[6], m_PrincDir[6];
	int m_Dimensions;
	int m_TotNumCPs, m_NumCPs[6];
	double m_MinCPDist;
	Boolean_t m_MinCPDistFound;
	double m_RhoCutoff;

};

const Boolean_t FindCPs(CritPoints_c & CPs,
	VolExtentIndexWeights_s VolInfo,
	const Boolean_t & IsPeriodic,
	const vector<int> & StartIJK,
	const vector<int> & EndIJK,
	const FieldDataPointer_c & RhoPtr,
	const vector<FieldDataPointer_c> & GradPtrs,
	const vector<FieldDataPointer_c> & HessPtrs);

const Boolean_t FindCPs(CritPoints_c & CPs,
	const VolExtentIndexWeights_s & VolInfo,
	const double & CellSpacing,
	const double & RhoCutoff,
	const Boolean_t & IsPeriodic,
	const FieldDataPointer_c & RhoPtr,
	const vector<FieldDataPointer_c> & GradXYZPtrs,
	const vector<FieldDataPointer_c> & HessPtrs);

const Boolean_t CritPointInCell(const vector<int> & IJK,
	vec3 & Point,
	vec3 & PrincDir,
	double & RhoValue,
	const double & RhoCutoff,
	char & Type,
	MultiRootParams_s & RootParams,
	MultiRootObjects_s & MR);

const Boolean_t CritPointInCell(
	const vec3 & CellMinXYZ,
	const vec3 & CellMaxXYZ,
	vec3 & Point,
	vec3 & PrincDir,
	double & RhoValue,
	const double & RhoCutoff,
	char & Type,
	MultiRootParams_s & RootParams,
	MultiRootObjects_s & MR);

#endif