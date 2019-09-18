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
	return 0.0f;
	// TODO: create function body
}

CMatrix3 & CMatrix3::Inverse(CMatrix3 & _rA, CMatrix3 & _rResult)
{
	return _rResult;
	// TODO: create function body
}
