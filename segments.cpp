#include "segments.hpp"

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

#include <boost/foreach.hpp>


using namespace std;

int orientation(Point A, Point B, Point C)
{
    int val = (B[1] - A[1]) * (C[0] - B[0]) - (B[0] - A[0]) * (C[1] - B[1]);
    return val == 0 ? 0 : (val > 0 ? 1 : 2);
}

bool onSegment(Point P, Segment S) //P collinear with S
{
    if (P[0] <= std::max(S.A[0], S.B[0]) &&
        P[0] >= std::min(S.A[0], S.B[0]) &&
        P[1] <= std::max(S.A[1], S.B[1]) &&
        P[1] >= std::min(S.A[1], S.B[1]) )
    {
        return true;
    }
    return false;
}


int intersect(Segment sA, Segment sB)
{
    Point PA = sA.A, QA = sA.B, PB = sB.B, QB = sB.B;
    int o1 = orientation(PA, QA, PB);
    int o2 = orientation(PA, QA, QB);
    int o3 = orientation(PB, QB, PA);
    int o4 = orientation(PB, QB, QA);

    if (o1 != o2 && o3 != o4) 
        return 1;

    if (o1 == 0 && onSegment(PB, sA)) return 1;
    if (o2 == 0 && onSegment(QB, sA)) return 1;
    if (o3 == 0 && onSegment(PA, sB)) return 1;
    if (o4 == 0 && onSegment(QA, sB)) return 1;

    return 0;

}

bool isInPolygon(Polygon polygon, Point P)
{
    Point Q = P;
    Q[0] = INF;
    int nInter = 0;
    Segment halfLine;
    halfLine.A = P;
    halfLine.B = Q;

    BOOST_FOREACH(Segment seg, polygon.seg)
    {
        if (orientation(seg.A, P, seg.B) == 0)
            return onSegment(P, seg);
        nInter += intersect(seg, halfLine);
    }

    return nInter&1;
}