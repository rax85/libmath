#pragma once

namespace libmath {

/** @brief A point in 3 dimensional space. */
class Point {
  public:
    Point() = default;
    Point(double xx, double yy, double zz = 0) : x(xx), y(yy), z(zz) {}

    double Distance(const Point& p);

    double x = 0;
    double y = 0;
    double z = 0;
};

/** Point with storage for a value. */
class PointWithValue : public Point {
  public:
    PointWithValue() = default;
    PointWithValue(double xx, double yy, double zz, double val) : Point(xx, yy, zz), value(val) {}
    PointWithValue(const Point& p, double val) : Point(p), value(val) {}

    double value = 0;
};


}