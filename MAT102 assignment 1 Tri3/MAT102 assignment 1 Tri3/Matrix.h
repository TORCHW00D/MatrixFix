#pragma once
using namespace std;

class CMatrix3 {
private:
	float m_fMatrix[3][3];

public:
	CMatrix3();
	~CMatrix3();

	float SetElement(int _iX, int _iY, float _fValue);
	float GetElement(int _iX, int _iY);
	static CMatrix3& Identity(CMatrix3& _rResult);
	static CMatrix3& Zero(CMatrix3& _rResult);
	static bool Equals(CMatrix3& _rA, CMatrix3& _rB);
	static CMatrix3& Add(CMatrix3& _rA, CMatrix3& _rB, CMatrix3& _rResult);
	static CMatrix3& Subtract(CMatrix3& _rA, CMatrix3& _rB, CMatrix3& _rResult);
	static CMatrix3& Multiply(float _fScalar, CMatrix3& _rA, CMatrix3& _rResult);
	static CMatrix3& Multiply(CMatrix3& _rA, CMatrix3& _rB, CMatrix3& _rResult);
	static CMatrix3& Transpose(CMatrix3& _rA, CMatrix3& _rResult);
	static float Detriminant(CMatrix3& _rA);
	static CMatrix3& Inverse(CMatrix3& _rA, CMatrix3& _rResult);

};