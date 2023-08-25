#ifndef PLANNER_H
#define PLANNER_H

#include <vector>
#include <queue>
#include <set>
#include <math.h>
#include "Environment.h"

struct PointCost{
    int y;
    int x;
    double cost;
    PointCost(){}
    PointCost(int y,int x):y(y),x(x),cost(0){}
    ~PointCost(){}

    bool operator< (const PointCost& point1) const
    {
        return point1.cost > cost;
    }

    bool operator> (const PointCost& point1)const
    {
        return point1.cost < cost;
    }

    bool operator== (const PointCost& point1)const
    {
        return (point1.x == x) && (point1.y == y);
    }
};

struct QuadTreePoint{
    double centerX;
    double centerY;
    double gridSize;
    double cost;
    QuadTreeNode* node;

    QuadTreePoint(){}
    QuadTreePoint(QuadTreeNode* node):
        centerX(node->centerX),
        centerY(node->centerY),
        gridSize(node->gridSize),
        cost(0),
        node(node){}
    ~QuadTreePoint(){}

    bool operator< (const QuadTreePoint& point1)const
    {
        return point1.cost > cost;
    }

    bool operator> (const QuadTreePoint& point1)const
    {
        return point1.cost < cost;
    }

    bool operator== (const QuadTreePoint& point1)const
    {
        return (point1.centerX == centerX)
            && (point1.centerY == centerY);
    }
};

class Planner
{
    public:

    //set<Point> closedSet;
    vector<PointCost> openSetVec;
    int openSetSize;
    priority_queue<PointCost> openSet;
    int numberOfNodeExpand;
    double *g_score[RESOLUTION];
    //double *f_score[RESOLUTION];
    int *came_fromY[RESOLUTION];
    int *came_fromX[RESOLUTION];
    //int *t[RESOLUTION];
    //1 for open, -1 for close;
    int *open_close[RESOLUTION];


    int a_star(Environment &env);
    int reconstructPath(Environment &env, int y, int x);
    int StarQuadTree(Environment &env);


    /* Quadtree related*/
    priority_queue<QuadTreePoint> qOpenSet;

    int AStarQuadTree(Environment &env);
    double reconstructPathQuadTree(Environment &env,
            QuadTreeNode* node);
};


#endif /* PLANNER_H */
