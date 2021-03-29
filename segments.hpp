#include <vector>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

#define INF 100000.0

typedef Eigen::Vector2d Point;

typedef struct {
    Point A;
    Point B;
} Segment;

typedef struct {
    std::vector<Segment> seg;
} Polygon;

int orientation(Point A, Point B, Point C);
bool onSegment(Point P, Segment S);
int intersect(Segment sA, Segment sB);

bool isInPolygon(Polygon polygon, Point P);