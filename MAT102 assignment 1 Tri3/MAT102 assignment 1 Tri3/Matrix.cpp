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

CMatrix4::CMatrix4(){}

CMatrix4::~CMatrix4(){}

float CMatrix4::SetElement4(int _iX, int _iY, float _fValue)
{
	m_f4Matrix[_iX][_iY] = _fValue;
	return _fValue;
}

float CMatrix4::GetElement4(int _iX, int _iY)
{
	return m_f4Matrix[_iX][_iY];
}

CMatrix4 & CMatrix4::Identity4(CMatrix4 & _rResult)
{
	_rResult.Zero4(_rResult);
	for (int i = 0; i < 4; i++) {
		_rResult.m_f4Matrix[i][i] = 1;
	}
	return _rResult;
	// TODO: insert return statement here
}

CMatrix4 & CMatrix4::Zero4(CMatrix4 & _rResult)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			_rResult.SetElement4(i, j, 0);
		}
	}
	return _rResult;
	//TODO: write test
}

bool CMatrix4::Equals4(CMatrix4 & _rA, CMatrix4 & _rB)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (_rA.GetElement4(i, j) != (_rB.GetElement4(i, j))) {
				return false;
			}
		}
	}
	return true;
	//TODO: write test
}

CMatrix4 & CMatrix4::Add4(CMatrix4 & _rA, CMatrix4 & _rB, CMatrix4 & _rResult)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			_rResult.SetElement4(i, j, (_rA.GetElement4(i, j) + _rB.GetElement4(i, j)));
		}
	}

	return _rResult;
	//TODO: wite test
}

CMatrix4 & CMatrix4::Subtract4(CMatrix4 & _rA, CMatrix4 & _rB, CMatrix4 & _rResult)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			_rResult.SetElement4(i, j, (_rA.GetElement4(i, j) - _rB.GetElement4(i, j)));
		}
	}
	return _rResult;

	// TODO: write test
}

CMatrix4 & CMatrix4::Multiply4(float _fScalar, CMatrix4 & _rA, CMatrix4 & _rResult)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			_rResult.SetElement4(i, j, (_rA.GetElement4(i, j) * _fScalar));
		}
	}
	return _rResult;

	// TODO: write test
}

CMatrix4 & CMatrix4::Multiply4(CMatrix4 & _rA, CMatrix4 & _rB, CMatrix4 & _rResult)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			_rResult.SetElement4(i, j, 0.0f);
			for (int k = 0; k < 3; k++) {
				_rResult.SetElement4(i, j, (_rResult.GetElement4(i, j) + _rA.GetElement4(i, k) * _rB.GetElement4(k, j)));
			}
		}
	}
	return _rResult;

	// TODO: write test
}

CMatrix4 & CMatrix4::Transpose4(CMatrix4 & _rA, CMatrix4 & _rResult)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			_rResult.SetElement4(i, j, _rA.GetElement4(j, i));
		}
	}
	return _rResult;
	// TODO: insert return statement here
}

float CMatrix4::Detriminant4(CMatrix4 & _rA)
{
	return 0.0f;
}

CMatrix4 & CMatrix4::Inverse4(CMatrix4 & _rA, CMatrix4 & _rResult)
{
	// TODO: insert return statement here
	return _rResult;
}

CMatrix4 & CMatrix4::Translate(CMatrix4 & _rA, CMatrix4 & _rResult, int xTranslate, int yTranslate, int zTranslate)
{
	_rResult.SetElement4(0, 3, (_rA.GetElement4(0, 3) + xTranslate));
	_rResult.SetElement4(1, 3, (_rA.GetElement4(1, 3) + yTranslate));
	_rResult.SetElement4(2, 3, (_rA.GetElement4(2, 3) + zTranslate));

	return _rResult;
}

CMatrix4 & CMatrix4::Scaling(CMatrix4 & _rA, CMatrix4 & _rResult, int scale)
{
	_rResult.SetElement4(0, 0, (_rA.GetElement4(0, 0) * scale));
	_rResult.SetElement4(1, 1, (_rA.GetElement4(1, 1) * scale));
	_rResult.SetElement4(2, 2, (_rA.GetElement4(2, 2) * scale));
	return _rResult;
	// TODO: insert return statement here
}

CMatrix4 & CMatrix4::RotateX(CMatrix4 & _rA, CMatrix4 & _rResult, int rAngle)
{
	_rResult.SetElement4(1, 1, _rA.GetElement4(1, 1) + cos(rAngle));
	_rResult.SetElement4(1, 2, _rA.GetElement4(1, 2) + sin(rAngle));
	_rResult.SetElement4(2, 1, _rA.GetElement4(2, 1) + sin(rAngle));
	_rResult.SetElement4(2, 2, _rA.GetElement4(2, 2) + cos(rAngle));

	return _rResult;

	// TODO: insert return statement here
}

CMatrix4 & CMatrix4::RotateY(CMatrix4 & _rA, CMatrix4 & _rResult, int rAngle)
{
	_rResult.SetElement4(0, 0, _rA.GetElement4(0, 0) + cos(rAngle));
	_rResult.SetElement4(2, 0, _rA.GetElement4(2, 0) + sin(rAngle));
	_rResult.SetElement4(0, 2, _rA.GetElement4(0, 2) + sin(rAngle));
	_rResult.SetElement4(2, 2, _rA.GetElement4(2, 2) + cos(rAngle));

	return _rResult;


	// TODO: insert return statement here
}

CMatrix4 & CMatrix4::RotateZ(CMatrix4 & _rA, CMatrix4 & _rResult, int rAngle)
{

	_rResult.SetElement4(0, 0, _rA.GetElement4(0, 0) + cos(rAngle));
	_rResult.SetElement4(0, 1, _rA.GetElement4(0, 1) + cos(rAngle));
	_rResult.SetElement4(1, 0, _rA.GetElement4(1, 0) + cos(rAngle));
	_rResult.SetElement4(1, 1, _rA.GetElement4(1, 1) + cos(rAngle));
	// TODO: insert return statement here
}

