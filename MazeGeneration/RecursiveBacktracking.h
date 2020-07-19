#ifndef RECURSIVE_BACKTRACKING_H
#define RECURSIVE_BACKTRACKING_H

#include "Algorithm.h"

class RecursiveBacktracking : public Algorithm
{
public:
	RecursiveBacktracking(MazeCell*);

	bool update(Array2D<MazeCell*>&) override;

private:
	std::vector<MazeCell*> prevCells;
};

#endif