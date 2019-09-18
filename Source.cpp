#include "Matrix.h"
#include <iostream>

using namespace std;


void EchoMatrixToScreen(CMatrix3& _rPrintable) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << _rPrintable.GetElement(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	CMatrix3 M1, M2, R1;
	int Matrixumber = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			M1.SetElement(i, j, Matrixumber);
			Matrixumber++;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			M2.SetElement(i, j, Matrixumber);
			Matrixumber++;
		}
	}

	EchoMatrixToScreen(M1);
	EchoMatrixToScreen(M2);
	system("pause");

	R1 = R1.Add(M1, M2, R1);
	EchoMatrixToScreen(R1);
	R1 = R1.Subtract(M1, M2, R1);
	EchoMatrixToScreen(R1);
	system("pause");

	R1.Zero(R1);
	EchoMatrixToScreen(R1);
	system("pause");

	cout << R1.Equals(R1, M1) << endl;
	system("pause");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			R1.SetElement(i, j, M1.GetElement(i, j));
		}
	}
	cout << R1.Equals(R1, M1) << endl;
	system("pause");

	R1.Multiply(2.0f, M1, R1);
	EchoMatrixToScreen(R1);
	system("pause");

	R1.Multiply(M1, M2, R1);
	EchoMatrixToScreen(R1);
	system("pause");

	R1.Transpose(M1, R1);
	EchoMatrixToScreen(R1);
	system("pause");

}