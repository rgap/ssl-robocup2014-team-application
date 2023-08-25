#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>
#include <stack>
#include <fstream>
#include "Obstacle.h"
#include "QuadTree.h"
#include "QuadTreeNode.h"

#define RESOLUTION 1000

class Environment
{
    public:
    double x0,y0,x1,y1;
    double x_start, y_start;
    double x_end, y_end;
    int baseResolution; // default as 10 in constructor

    double radius_robot; // to be configured

    int grid[RESOLUTION][RESOLUTION];
    double gridSize;

    vector<Obstacle> obsContainer;
    QuadTree quadTree;

    Environment();
    ~Environment();

    void addObstacle(Obstacle obs);

    void regularCellDecomposite();
    /* QuadTree related */
    double qResolution;
    int** qGrid;

    void initialTree();
    void ApproxCellDecomposite(int depth);
    void splitToDepth(QuadTreeNode& node, int depth);
    void labelNode(QuadTreeNode& node);
    double dist(const double ax,const double ay,
            const double bx,const double by)const;

    int** QuadTreeToMatrix(int matrixSize);

    QuadTreeNode* locateNode(double x, double y);

    /* planning */
    stack<QuadTreeNode*> path;
    void outputPath(ofstream& fout);
    void clearTree();
};


#endif /* ENVIRONMENT_H */
