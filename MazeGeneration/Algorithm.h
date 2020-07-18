#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Array2D.h"
#include "MazeCell.h"

class Algorithm
{
public:
	Algorithm();

	virtual bool update(Array2D<MazeCell*>&);

protected:
	MazeCell* curCell;
	int iteration = 0;
};

#endif