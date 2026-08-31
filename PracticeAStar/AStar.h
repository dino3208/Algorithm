#pragma once

#include "Node.h"
#include <vector>

class AStar
{
private:
	// 이동 방향과 해당 방향의 이동 비용
	struct Direction
	{
		int x;
		int y;
		float cost;
	};

public:
	AStar();
	~AStar();

	// 시작 위치에서 목표 위치까지 경로를 탐색
	std::vector<Position> FindPath(
		const Position& startPosition,
		const Position& goalPosition,
		std::vector<std::vector<int>>& grid);

private:
	// 이전 탐색에서 생성한 노드와 목록 정리
	void Clear();

	// AStar가 소유할 탐색 노드 생성
	Node* CreateNode(
		const Position& position,
		Node* parentNode = nullptr);

	// 부모 노드를 역추적하여 경로 구성
	std::vector<Position> ConstructPath(Node* destinationNode);

	// 목표 위치까지의 예상 비용 계산
	float CalculateHeuristic(
		const Position& currentPosition, const Position& goalPosition) const;

	// 그리드와 좌표가 유효한지 확인
	bool IsValidGrid(const std::vector<std::vector<int>>& grid) const;
	bool IsInRange(int x, int y, std::vector<std::vector<int>>& grid) const;

	// 대각선 이동이 장애물 모서리를 통과하는지 확인
	bool IsDiagonalBlocked(
		const Position& currentPosition,
		const Direction& direction,
		const std::vector<std::vector<int>>& grid) const;

	// 이전 탐색 표시를 지우고 그리드를 출력
	void ClearVisualization(std::vector<std::vector<int>>& grid) const;
	void DisplayGrid(std::vector<std::vector<int>>& grid) const;

private:
	// 동적 할당한 모든 노드를 소유
	std::vector<Node*> allocatedNodes;

	// 탐색할 노드와 탐색을 마친 노드 목록
	std::vector<Node*> openList;
	std::vector<Node*> closedList;

	Node* startNode;
	Node* goalNode;
};

