#include "Matrix.h"
Matrix::Matrix() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {


			resultAdd.m[i][j] = 0.0f;
			resultMultiply.m[i][j] = 0.0f;
			resultSubtract.m[i][j] = 0.0f;
			inverseM1.m[i][j] = 0.0f;
			inverseM2.m[i][j] = 0.0f;
			transposeM1.m[i][j] = 0.0f;
			transposeM2.m[i][j] = 0.0f;
			identity.m[i][j] = 0.0f;
		}
	}
	m1 = { 3.2f,0.7f,9.6f,4.4f,
		  5.5f,1.3f,7.8f,2.1f,
		  6.9f,8.0f,2.6f,1.0f,
		  0.5f,7.2f,5.1f,3.3f, };

	m2 = { 4.1f,6.5f,3.3f,2.2f,
		  8.8f,0.6f,9.9f,7.7f,
		  1.1f,5.5f,6.6f,0.0f,
		  3.3f,9.9f,8.8f,2.2f, };
}

Matrix4x4 Matrix::Add(const Matrix4x4& mat1, const Matrix4x4& mat2) {
	Matrix4x4 result = { 0.0f };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = mat1.m[i][j] + mat2.m[i][j];
		}
	}
	return result;
}

Matrix4x4 Matrix::Subtract(const Matrix4x4& mat1, const Matrix4x4& mat2) {
	Matrix4x4 result = { 0.0f };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = mat1.m[i][j] - mat2.m[i][j];
		}
	}
	return result;
}

Matrix4x4 Matrix::Multiply(const Matrix4x4& mat1, const Matrix4x4& mat2) {
	Matrix4x4 result = { 0.0f };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = mat1.m[i][0] * mat2.m[0][j] +
				mat1.m[i][1] * mat2.m[1][j] +
				mat1.m[i][2] * mat2.m[2][j] +
				mat1.m[i][3] * mat2.m[3][j];
		}
	}
	return result;
}

Matrix4x4 Matrix::Inverce(const Matrix4x4& mat) {
	float A = 0.0f;
	Matrix4x4 result = { 0.0f };
	//s—ñŽ®‚ÌŒvŽZ
	A = mat.m[0][0] * mat.m[1][1] * mat.m[2][2] * mat.m[3][3] +
		mat.m[0][0] * mat.m[1][2] * mat.m[2][3] * mat.m[3][1] +
		mat.m[0][0] * mat.m[1][3] * mat.m[2][1] * mat.m[3][2] -
		mat.m[0][0] * mat.m[1][3] * mat.m[2][2] * mat.m[3][1] -
		mat.m[0][0] * mat.m[1][2] * mat.m[2][1] * mat.m[3][3] -
		mat.m[0][0] * mat.m[1][1] * mat.m[2][3] * mat.m[3][2] -
		mat.m[0][1] * mat.m[1][0] * mat.m[2][2] * mat.m[3][3] -
		mat.m[0][2] * mat.m[1][0] * mat.m[2][3] * mat.m[3][1] -
		mat.m[0][3] * mat.m[1][0] * mat.m[2][1] * mat.m[3][2] +
		mat.m[0][3] * mat.m[1][0] * mat.m[2][2] * mat.m[3][1] +
		mat.m[0][2] * mat.m[1][0] * mat.m[2][1] * mat.m[3][3] +
		mat.m[0][1] * mat.m[1][0] * mat.m[2][3] * mat.m[3][2] +
		mat.m[0][1] * mat.m[1][2] * mat.m[2][0] * mat.m[3][3] +
		mat.m[0][2] * mat.m[1][3] * mat.m[2][0] * mat.m[3][1] +
		mat.m[0][3] * mat.m[1][1] * mat.m[2][0] * mat.m[3][2] -
		mat.m[0][3] * mat.m[1][2] * mat.m[2][0] * mat.m[3][1] -
		mat.m[0][2] * mat.m[1][1] * mat.m[2][0] * mat.m[3][3] -
		mat.m[0][1] * mat.m[1][3] * mat.m[2][0] * mat.m[3][2] -
		mat.m[0][1] * mat.m[1][2] * mat.m[2][3] * mat.m[3][0] -
		mat.m[0][2] * mat.m[1][3] * mat.m[2][1] * mat.m[3][0] -
		mat.m[0][3] * mat.m[1][1] * mat.m[2][2] * mat.m[3][0] +
		mat.m[0][3] * mat.m[1][2] * mat.m[2][1] * mat.m[3][0] +
		mat.m[0][2] * mat.m[1][1] * mat.m[2][3] * mat.m[3][0] +
		mat.m[0][1] * mat.m[1][3] * mat.m[2][2] * mat.m[3][0];

	//‹ts—ñ‚ÌŒvŽZ
	result.m[0][0] = (mat.m[1][1] * mat.m[2][2] * mat.m[3][3] + mat.m[1][2] * mat.m[2][3] * mat.m[3][1] + mat.m[1][3] * mat.m[2][1] * mat.m[3][2]
		- mat.m[1][3] * mat.m[2][2] * mat.m[3][1] - mat.m[1][2] * mat.m[2][1] * mat.m[3][3] - mat.m[1][1] * mat.m[2][3] * mat.m[3][2]) / A;

	result.m[0][1] = (-mat.m[0][1] * mat.m[2][2] * mat.m[3][3] - mat.m[0][2] * mat.m[2][3] * mat.m[3][1] - mat.m[0][3] * mat.m[2][1] * mat.m[3][2]
		+ mat.m[0][3] * mat.m[2][2] * mat.m[3][1] + mat.m[0][2] * mat.m[2][1] * mat.m[3][3] + mat.m[0][1] * mat.m[2][3] * mat.m[3][2]) / A;

	result.m[0][2] = (mat.m[0][1] * mat.m[1][2] * mat.m[3][3] + mat.m[0][2] * mat.m[1][3] * mat.m[3][1] + mat.m[0][3] * mat.m[1][1] * mat.m[3][2]
		- mat.m[0][3] * mat.m[1][2] * mat.m[3][1] - mat.m[0][2] * mat.m[1][1] * mat.m[3][3] - mat.m[0][1] * mat.m[1][3] * mat.m[3][2]) / A;

	result.m[0][3] = (-mat.m[0][1] * mat.m[1][2] * mat.m[2][3] - mat.m[0][2] * mat.m[1][3] * mat.m[2][1] - mat.m[0][3] * mat.m[1][1] * mat.m[2][2]
		+ mat.m[0][3] * mat.m[1][2] * mat.m[2][1] + mat.m[0][2] * mat.m[1][1] * mat.m[2][3] + mat.m[0][1] * mat.m[1][3] * mat.m[2][2]) / A;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	result.m[1][0] = (-mat.m[1][0] * mat.m[2][2] * mat.m[3][3] - mat.m[1][2] * mat.m[2][3] * mat.m[3][0] - mat.m[1][3] * mat.m[2][0] * mat.m[3][2]
		+ mat.m[1][3] * mat.m[2][2] * mat.m[3][0] + mat.m[1][2] * mat.m[2][0] * mat.m[3][3] + mat.m[1][0] * mat.m[2][3] * mat.m[3][2]) / A;

	result.m[1][1] = (mat.m[0][0] * mat.m[2][2] * mat.m[3][3] + mat.m[0][2] * mat.m[2][3] * mat.m[3][0] + mat.m[0][3] * mat.m[2][0] * mat.m[3][2]
		- mat.m[0][3] * mat.m[2][2] * mat.m[3][0] - mat.m[0][2] * mat.m[2][0] * mat.m[3][3] - mat.m[0][0] * mat.m[2][3] * mat.m[3][2]) / A;

	result.m[1][2] = (-mat.m[0][0] * mat.m[1][2] * mat.m[3][3] - mat.m[0][2] * mat.m[1][3] * mat.m[3][0] - mat.m[0][3] * mat.m[1][0] * mat.m[3][2]
		+ mat.m[0][3] * mat.m[1][2] * mat.m[3][0] + mat.m[0][2] * mat.m[1][0] * mat.m[3][3] + mat.m[0][0] * mat.m[1][3] * mat.m[3][2]) / A;

	result.m[1][3] = (mat.m[0][0] * mat.m[1][2] * mat.m[2][3] + mat.m[0][2] * mat.m[1][3] * mat.m[2][0] + mat.m[0][3] * mat.m[1][0] * mat.m[2][2]
		- mat.m[0][3] * mat.m[1][2] * mat.m[2][0] - mat.m[0][2] * mat.m[1][0] * mat.m[2][3] - mat.m[0][0] * mat.m[1][3] * mat.m[2][2]) / A;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	result.m[2][0] = (mat.m[1][0] * mat.m[2][1] * mat.m[3][3] + mat.m[1][1] * mat.m[2][3] * mat.m[3][0] + mat.m[1][3] * mat.m[2][0] * mat.m[3][1]
		- mat.m[1][3] * mat.m[2][1] * mat.m[3][0] - mat.m[1][1] * mat.m[2][0] * mat.m[3][3] - mat.m[1][0] * mat.m[2][3] * mat.m[3][1]) / A;

	result.m[2][1] = (-mat.m[0][0] * mat.m[2][1] * mat.m[3][3] - mat.m[0][1] * mat.m[2][3] * mat.m[3][0] - mat.m[0][3] * mat.m[2][0] * mat.m[3][1]
		+ mat.m[0][3] * mat.m[2][1] * mat.m[3][0] + mat.m[0][1] * mat.m[2][0] * mat.m[3][3] + mat.m[0][0] * mat.m[2][3] * mat.m[3][1]) / A;

	result.m[2][2] = (mat.m[0][0] * mat.m[1][1] * mat.m[3][3] + mat.m[0][1] * mat.m[1][3] * mat.m[3][0] + mat.m[0][3] * mat.m[1][0] * mat.m[3][1]
		- mat.m[0][3] * mat.m[1][1] * mat.m[3][0] - mat.m[0][1] * mat.m[1][0] * mat.m[3][3] - mat.m[0][0] * mat.m[1][3] * mat.m[3][1]) / A;

	result.m[2][3] = (-mat.m[0][0] * mat.m[1][1] * mat.m[2][3] - mat.m[0][1] * mat.m[1][3] * mat.m[2][0] - mat.m[0][3] * mat.m[1][0] * mat.m[2][1]
		+ mat.m[0][3] * mat.m[1][1] * mat.m[2][0] + mat.m[0][1] * mat.m[1][0] * mat.m[2][3] + mat.m[0][0] * mat.m[1][3] * mat.m[2][1]) / A;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	result.m[3][0] = (-mat.m[1][0] * mat.m[2][1] * mat.m[3][2] - mat.m[1][1] * mat.m[2][2] * mat.m[3][0] - mat.m[1][2] * mat.m[2][0] * mat.m[3][1]
		+ mat.m[1][2] * mat.m[2][1] * mat.m[3][0] + mat.m[1][1] * mat.m[2][0] * mat.m[3][2] + mat.m[1][0] * mat.m[2][2] * mat.m[3][1]) / A;

	result.m[3][1] = (mat.m[0][0] * mat.m[2][1] * mat.m[3][2] + mat.m[0][1] * mat.m[2][2] * mat.m[3][0] + mat.m[0][2] * mat.m[2][0] * mat.m[3][1]
		- mat.m[0][2] * mat.m[2][1] * mat.m[3][0] - mat.m[0][1] * mat.m[2][0] * mat.m[3][2] - mat.m[0][0] * mat.m[2][2] * mat.m[3][1]) / A;

	result.m[3][2] = (-mat.m[0][0] * mat.m[1][1] * mat.m[3][2] - mat.m[0][1] * mat.m[1][2] * mat.m[3][0] - mat.m[0][2] * mat.m[1][0] * mat.m[3][1]
		+ mat.m[0][2] * mat.m[1][1] * mat.m[3][0] + mat.m[0][1] * mat.m[1][0] * mat.m[3][2] + mat.m[0][0] * mat.m[1][2] * mat.m[3][1]) / A;

	result.m[3][3] = (mat.m[0][0] * mat.m[1][1] * mat.m[2][2] + mat.m[0][1] * mat.m[1][2] * mat.m[2][0] + mat.m[0][2] * mat.m[1][0] * mat.m[2][1]
		- mat.m[0][2] * mat.m[1][1] * mat.m[2][0] - mat.m[0][1] * mat.m[1][0] * mat.m[2][2] - mat.m[0][0] * mat.m[1][2] * mat.m[2][1]) / A;




	return result;
}
//
Matrix4x4 Matrix::Transpose(const Matrix4x4& mat) {
	Matrix4x4 result = { 0.0f };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = mat.m[j][i];
		}
	}
	return result;
}

Matrix4x4 Matrix::MakeIdentity4x4() {
	Matrix4x4 result = { 0.0f };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ( i < 1 && j < 1) {
				result.m[i][j] = 1.0f;
			}
			else if (i = j) {
				result.m[i][j] = 1.0f;
			}
			else {
				result.m[i][j] = 0.0f;
			}
		}
	}
	return result;
}


void Matrix::Update() {
	resultAdd = Add(m1, m2);
	resultSubtract = Subtract(m1, m2);
	resultMultiply = Multiply(m1, m2);
	inverseM1 = Inverce(m1);	
	inverseM2 = Inverce(m2);
	transposeM1 = Transpose(m1);
	transposeM2 = Transpose(m2);
	identity = MakeIdentity4x4();
}
