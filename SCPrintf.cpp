#include "SCPrintf.h"
SCPrintf::SCPrintf() {
	matrix = new Matrix;

	kRowHeight = 20;
	kColumnWidth = 60;
}

SCPrintf::~SCPrintf() {
	delete matrix;
}

void SCPrintf::MatrixScreenPrintf(int x, int y, const Matrix4x4& mat, const char* label) {
	Novice::ScreenPrintf(x, y, "%s", label);

	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight + kRowHeight, "%0.2f", mat.m[row][column]);
		}
	}
}

void SCPrintf::Update() {
	matrix->Update();

	MatrixScreenPrintf(0, 0, matrix->resultAdd, "Add");
	MatrixScreenPrintf(0, kRowHeight * 5, matrix->resultSubtract, "Subtract");
	MatrixScreenPrintf(0, kRowHeight * 10, matrix->resultMultiply, "Multiply");
	MatrixScreenPrintf(0, kRowHeight * 15, matrix->inverseM1, "inverseM1");
	MatrixScreenPrintf(0, kRowHeight * 20, matrix->inverseM2, "inverseM2");
	MatrixScreenPrintf(kColumnWidth * 5, 0, matrix->transposeM1, "transposeM1");
	MatrixScreenPrintf(kColumnWidth * 5, kRowHeight * 5, matrix->transposeM2, "transposeM2");
	MatrixScreenPrintf(kColumnWidth * 5, kRowHeight * 10, matrix->identity, "identity");
}