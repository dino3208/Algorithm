#pragma once

// 그리드의 좌표를 저장하는 클래스
class Position
{
public:
	Position(int x = 0, int y = 0)
		:x(x),y(y)
	{
	}

	bool operator==(const Position& other) const
	{
		return x == other.x && y == other.y;
	}

public:
	// 가로와 세로 위치
	int x;
	int y;
};

// A* 탐색에 사용하는 노드 클래스
class Node
{
public:
	Node(const Position& position, Node* parentNode = nullptr)
		: position(position),
		gCost(0.0f), hCost(0.0f), fCost(0.0f),
		parentNode(parentNode)
	{
	}

public:
	// 노드의 위치와 비용 정보
	Position position;
	float gCost;
	float hCost;
	float fCost;

	// 최종 경로를 역추적하기 위한 부모 노드
	Node* parentNode;
};
