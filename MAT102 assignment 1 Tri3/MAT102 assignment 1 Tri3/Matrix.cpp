#include "Matrix.h"
#include <iostream>
using namespace std;

CMatrix3::CMatrix3()
{
}

CMatrix3::~CMatrix3()
{
}

float CMatrix3::SetElement(int _iX, int _iY, float _fValue)
{
	m_fMatrix[_iX][_iY] = _fValue;
	return _fValue;
	// TODO: create test
}

float CMatrix3::GetElement(int _iX, int _iY)
{
	float _rResult = m_fMatrix[_iX][_iY];
	return _rResult;
	// TODO: create test
}

CMatrix3 & CMatrix3::Identity(CMatrix3 & _rResult)
{
	_rResult = Zero(_rResult);
	for (int i = 0; i < 3; i++) {
		_rResult.m_fMatrix[i][i] = 1.0f;
	}
	return _rResult;
	// TODO: create function body
}

CMatrix3 & CMatrix3::Zero(CMatrix3 & _rResult)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_rResult.SetElement(i,j, 0.0f);
		}
	}
	return _rResult;
	// TODO: create function body
}

bool CMatrix3::Equals(CMatrix3& _rA, CMatrix3& _rB)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (_rA.GetElement(i,j) != _rB.GetElement(i,j)) {
				return false;
			}
		}
	}
	return true;
	//TODO: create test
}

CMatrix3 & CMatrix3::Add(CMatrix3 & _rA, CMatrix3 & _rB, CMatrix3 & _rResult)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_rResult.m_fMatrix[i][j] = _rA.m_fMatrix[i][j] + _rB.m_fMatrix[i][j];
		}
	}

	return _rResult;
	// TODO: create test
}

CMatrix3 & CMatrix3::Subtract(CMatrix3 & _rA, CMatrix3 & _rB, CMatrix3 & _rResult)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_rResult.m_fMatrix[i][j] = _rA.m_fMatrix[i][j] - _rB.m_fMatrix[i][j];
		}
	}
	return _rResult;
	// TODO: create test
}

CMatrix3 & CMatrix3::Multiply(float _fScalar, CMatrix3 & _rA, CMatrix3 & _rResult)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_rResult.m_fMatrix[i][j] = _rA.m_fMatrix[i][j] * _fScalar;
		}
	}
	return _rResult;
	// TODO: create test
}

CMatrix3 & CMatrix3::Multiply(CMatrix3 & _rA, CMatrix3 & _rB, CMatrix3 & _rResult)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_rResult.m_fMatrix[i][j] = 0.0f;
			for (int k = 0; k < 3; k++) {
				_rResult.m_fMatrix[i][j] += _rA.m_fMatrix[i][k] * _rB.m_fMatrix[k][j];
			}
		}
	}
	return _rResult;
	// TODO: create test
}

CMatrix3 & CMatrix3::Transpose(CMatrix3 & _rA, CMatrix3 & _rResult)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_rResult.m_fMatrix[i][j] = _rA.m_fMatrix[j][i];
		}
	}
	return _rResult;
	// TODO: create test
}

float CMatrix3::Detriminant(CMatrix3 & _rA)
{
	float DetriminantValue = 0.0f;
	/*for (int i = 0; i < 3; i++) {
		DetriminantValue += (_rA.m_fMatrix[0][i] * (_rA.m_fMatrix[1][(i + 1) % 3] * _rA.m_fMatrix[2][(i + 2) % 3] - _rA.m_fMatrix[1][(i + 2) % 3] * _rA.m_fMatrix[2][(i + 1) % 3]));
	}*/
	DetriminantValue = _rA.m_fMatrix[0][0] * (_rA.m_fMatrix[1][1] * _rA.m_fMatrix[2][2] - _rA.m_fMatrix[1][2] * _rA.m_fMatrix[2][1]);
	DetriminantValue -= _rA.m_fMatrix[0][1] * (_rA.m_fMatrix[1][0] * _rA.m_fMatrix[2][2] - _rA.m_fMatrix[1][2] * _rA.m_fMatrix[2][0]);
	DetriminantValue += _rA.m_fMatrix[0][2] * (_rA.m_fMatrix[1][0] * _rA.m_fMatrix[2][1] - _rA.m_fMatrix[1][1] * _rA.m_fMatrix[2][0]);
	return DetriminantValue;
	// TODO: create function body
}

CMatrix3 & CMatrix3::Inverse(CMatrix3 & _rA, CMatrix3 & _rResult)
{




	return _rResult;
	// TODO: create function body
}
