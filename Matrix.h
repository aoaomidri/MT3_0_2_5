#pragma once
#include"Matrix4x4.h"
#include<Novice.h>
class Matrix
{
public:
	Matrix();

private:
	Matrix4x4 m1;
	Matrix4x4 m2;

public:

	//�v�Z�̊֐�
	//���Z
	Matrix4x4 Add(const Matrix4x4& mat1, const Matrix4x4& mat2);
	////���Z
	Matrix4x4 Subtract(const Matrix4x4& mat1, const Matrix4x4& mat2);
	////��
	Matrix4x4 Multiply(const Matrix4x4& mat1, const Matrix4x4& mat2);
	////�t�s��
	Matrix4x4 Inverce(const Matrix4x4& mat);
	////�]�u�s��
	Matrix4x4 Transpose(const Matrix4x4& mat);
	////�P�ʍs��̍쐬
	Matrix4x4 MakeIdentity4x4();

	//�v�Z���ʂ����锠
	Matrix4x4 resultAdd;
	Matrix4x4 resultMultiply;
	Matrix4x4 resultSubtract;
	Matrix4x4 inverseM1;
	Matrix4x4 inverseM2;
	Matrix4x4 transposeM1;
	Matrix4x4 transposeM2;
	Matrix4x4 identity;

	//���,�v�Z����
	void Update();

};

