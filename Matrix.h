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

	//ŒvZ‚ÌŠÖ”
	//‰ÁZ
	Matrix4x4 Add(const Matrix4x4& mat1, const Matrix4x4& mat2);
	////Œ¸Z
	Matrix4x4 Subtract(const Matrix4x4& mat1, const Matrix4x4& mat2);
	////Ï
	Matrix4x4 Multiply(const Matrix4x4& mat1, const Matrix4x4& mat2);
	////‹ts—ñ
	Matrix4x4 Inverce(const Matrix4x4& mat);
	////“]’us—ñ
	Matrix4x4 Transpose(const Matrix4x4& mat);
	////’PˆÊs—ñ‚Ìì¬
	Matrix4x4 MakeIdentity4x4();

	//ŒvZŒ‹‰Ê‚ğ“ü‚ê‚é” 
	Matrix4x4 resultAdd;
	Matrix4x4 resultMultiply;
	Matrix4x4 resultSubtract;
	Matrix4x4 inverseM1;
	Matrix4x4 inverseM2;
	Matrix4x4 transposeM1;
	Matrix4x4 transposeM2;
	Matrix4x4 identity;

	//‘ã“ü,ŒvZˆ—
	void Update();

};

