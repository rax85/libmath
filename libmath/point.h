#pragma once

namespace libmath {

/** @brief A point in 3 dimensional space. */
class Point {
  public:
    Point() = default;
    Point(double xx, double yy, double zz = 0) : x(xx), y(yy), z(zz) {}

    double x = 0;
    double y = 0;
    double z = 0;
};

}