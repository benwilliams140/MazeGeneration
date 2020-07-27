#ifndef A_STAR_H
#define A_STAR_H

#include "Algorithm.h"
#include <iostream>

class Node
{
public:
	Node(MazeCell*, Node*, int, float);
	std::vector<Node*> open(Array2D<MazeCell*>&);
	
	MazeCell* cell;
	int costToNode;
	float totalCost;
	Node* parent;
};

class AStar : public Algorithm
{
public:
	AStar(MazeCell*);

	bool update(Array2D<MazeCell*>&) override;

private:
	std::vector<Node*> open;
	std::vector<Node*> closed;
};

#endif