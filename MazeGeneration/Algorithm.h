#ifndef ALGORITHM_H
#define ALGORITHM_H

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <cmath>

#include "Array2D.h"
#include "MazeCell.h"

class Algorithm
{
public:
	Algorithm(MazeCell*);

	virtual bool update(Array2D<MazeCell*>&);

protected:
	MazeCell* curCell;
	MazeCell* startingCell;
	int iteration = 0;

	MazeCell* getNextCell(Array2D<MazeCell*>&, MazeCell*);
	
private:
	bool hasAdjacentCells(Array2D<MazeCell*>&, MazeCell*);
};

#endif