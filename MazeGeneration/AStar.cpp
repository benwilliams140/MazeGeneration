#include "AStar.h"

Node::Node(MazeCell* _cell, Node* _parent, int _costToNode, float _costToEnd) : cell(_cell), costToNode(_costToNode), parent(_parent)
{
	totalCost = _costToNode + _costToEnd;
}

std::vector<Node*> Node::open(Array2D<MazeCell*>& _maze)
{
	std::vector<Node*> _adjList;
	Node* _node;

	for (int i = 0; i < 4; ++i)
	{
		if (!cell->getWall(i))
		{
			int _nextCol = cell->getCol() + (int)sin(i * M_PI_2 + M_PI_2);
			int _nextRow = cell->getRow() + (int)sin(i * M_PI_2);

			int _dCol = _maze.getCols() - _nextCol - 1;
			int _dRow = _maze.getRows() - _nextRow - 1;

			float _costToEnd = sqrt(_dCol * _dCol + _dRow * _dRow);

			_node = new Node(_maze[_nextCol][_nextRow], this, costToNode + 1, _costToEnd);
			_adjList.push_back(_node);
		}
	}

	cell->close();
	cell->update();

	//std::cout << "Node Opened" << std::endl;

	return _adjList;
}

AStar::AStar(MazeCell* _start) : Algorithm(_start)
{

}

bool AStar::update(Array2D<MazeCell*>& _maze)
{
	//std::cout << "ASTAR" << std::endl;

	if (closed.empty())
	{
		int _dCol = _maze.getCols() - 1;
		int _dRow = _maze.getCols() - 1;
		float _costToEnd = sqrt(_dCol * _dCol + _dRow * _dRow);

		Node* _node = new Node(_maze[0][0], NULL, 0, _costToEnd);
		open.push_back(_node);
	}

	if (!open.empty())
	{
		float _minCost = sqrt(_maze.getCols() * _maze.getCols() + _maze.getRows() * _maze.getRows());
		Node* _node = NULL;
		
		for (auto it = open.begin(); it != open.end(); ++it)
		{
			if ((*it)->totalCost < _minCost)
			{
				_node = *it;
				_minCost = _node->totalCost;
			}
		}

		if (_node)
		{
			std::vector<Node*> _adjList = _node->open(_maze);
			open.insert(open.end(), _adjList.begin(), _adjList.end());
		}
	}
}