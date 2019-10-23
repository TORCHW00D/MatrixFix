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
class CMatrix4 {
private:
	float m_f4Matrix[4][4];

public:
	CMatrix4();
	~CMatrix4();

	float SetElement4(int _iX, int _iY, float _fValue);
	float GetElement4(int _iX, int _iY);
	static CMatrix4& Identity4(CMatrix4& _rResult);
	static CMatrix4& Zero4(CMatrix4& _rResult);
	static bool Equals4(CMatrix4& _rA, CMatrix4& _rB);
	static CMatrix4& Add4(CMatrix4& _rA, CMatrix4& _rB, CMatrix4& _rResult);
	static CMatrix4& Subtract4(CMatrix4& _rA, CMatrix4& _rB, CMatrix4& _rResult);
	static CMatrix4& Multiply4(float _fScalar, CMatrix4& _rA, CMatrix4& _rResult);
	static CMatrix4& Multiply4(CMatrix4& _rA, CMatrix4& _rB, CMatrix4& _rResult);
	static CMatrix4& Transpose4(CMatrix4& _rA, CMatrix4& _rResult);
	static float Detriminant4(CMatrix4& _rA);
	static CMatrix4& Inverse4(CMatrix4& _rA, CMatrix4& _rResult);

	static CMatrix4& Translate(CMatrix4 & _rA, CMatrix4& _rResult, int xTranslate, int yTranslate, int zTranslate);
	static CMatrix4& Scaling(CMatrix4& _rA, CMatrix4 & _rResult, int scale);
	static CMatrix4& RotateX(CMatrix4& _rA, CMatrix4& _rResult, int rAngle);
	static CMatrix4& RotateY(CMatrix4& _rA, CMatrix4& _rResult, int rAngle);
	static CMatrix4& RotateZ(CMatrix4& _rA, CMatrix4& _rResult, int rAngle);
};