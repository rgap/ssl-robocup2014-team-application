#include "QuadTree.h"

using namespace std;

QuadTree::QuadTree():depth(0){}
QuadTree::~QuadTree(){}

    void
QuadTree::showNeighbors() // for debug
{
    /*	for(unsigned int i = 0; i<roots.size(); i++)
        {
        roots[i].showNeighbors();
        }
        */

    root->showNeighbors();
}

    QuadTreeNode*
QuadTree::locateNode(double x, double y)
{
    return root->locateNode(x,y);
}

    void
QuadTree::testNeighbors()
{
    root->testNeighbors();
}
