#pragma once

// 사각 영역을 표현하는 클래스
class Bounds
{
public:

private:
	// 위치(콘솔 좌표계 기준)
	int x = 0;
	int y = 0;

	// 크기
	int Width = 1;
	int height = 1;
};

