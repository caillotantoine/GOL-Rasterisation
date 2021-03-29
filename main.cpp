#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <boost/foreach.hpp>

// #include "opencv2/opencv.hpp"
// #include "opencv2/highgui/highgui.hpp"

#include "pgm_out.hpp"
#include "segments.hpp"

#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/highgui/highgui.hpp"

#define MAP_W 800
#define MAP_H 800

using namespace std;
//using namespace cv;


int main(int argc, char *argv[])
{
    Map map;
    vector<unsigned char> map_data(MAP_H*MAP_W);
    fill(map_data.begin(), map_data.end(), 255);

    map.data = map_data;
    map.height = MAP_H;
    map.width = MAP_W;
    map.cpm = 8.0;

    Point A, B, C, D, E;
    A << 400, 300;
    B << 500, 350;
    C << 500, 450;
    D << 300, 450;
    E << 300, 350;

    Segment sA, sB, sC, sD, sE;
    sA.A = A;
    sA.B = B;
    sB.A = B;
    sB.B = C;
    sC.A = C;
    sC.B = D;
    sD.A = D;
    sD.B = E;
    sE.A = E;
    sE.B = A;

    Polygon polygon;
    polygon.seg.push_back(sA);
    polygon.seg.push_back(sB);
    polygon.seg.push_back(sC);
    polygon.seg.push_back(sD);
    polygon.seg.push_back(sE);

    Point F, G, H, I, J;
    F << 600, 390;
    G << 500, 400;
    H << 430, 430;
    I << 400, 600;
    J << 350, 330;

    vector<Point> points;
    points.push_back(F);
    points.push_back(G);
    points.push_back(H);
    points.push_back(I);
    points.push_back(J);

    BOOST_FOREACH(Point p, points)
    {
        cout << p << endl;
        if(isInPolygon(polygon, p))
            cout << "is in polygon.\n\n";
        else
            cout << "is not polygon.\n\n";
    }

    cout << "error : " << write_pgm("./map.pgm", map) << endl;

    cv::namedWindow("Output",1);
    cv::Mat output = cv::Mat::zeros(MAP_H, MAP_W, CV_8UC3);

    cv::Point pts2draw[1][5];
    pts2draw[0][0] = cv::Point(400, 300);
    pts2draw[0][1] = cv::Point(500, 350);
    pts2draw[0][2] = cv::Point(500, 450);
    pts2draw[0][3] = cv::Point(300, 450);
    pts2draw[0][4] = cv::Point(300, 350);

    const cv::Point* ptset[1] = {pts2draw[0]};

    int npts[] = {5};
    cv::fillPoly(output, ptset, npts, 1, cv::Scalar(255, 255, 255), cv::LINE_8);

    cv::imshow("Output", output);
    cv::waitKey(0);

    return 0;
}