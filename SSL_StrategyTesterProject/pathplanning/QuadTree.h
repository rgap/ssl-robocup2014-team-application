#ifndef QUADTREE_H
#define QUADTREE_H

#include <vector>
#include <stack>
#include <fstream>
#include "QuadTreeNode.h"

class QuadTree
{
    public:
    vector<QuadTreeNode> roots;
    QuadTreeNode *root;
    int depth;

    // max distance to closed obstacle
    double maxDistTrans;
    // grid be initially devided into resolution * resolution

    QuadTree();
    ~QuadTree();

    void showNeighbors();

    QuadTreeNode* locateNode(double x, double y);
    void testNeighbors();
};

#endif // QUADTREE_H
