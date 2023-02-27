#pragma once

#include "libmath/point.h"

namespace libmath {

/** @brief A vector in 3 dimensional space. */
class Vector {
  public:
    Vector() = default;
    Vector(double ii, double jj, double kk = 0) : i(ii), j(jj), k(kk) {}
    Vector(const Point& p1, const Point& p2) : i(p2.x - p1.x), j(p2.y - p1.y), k(p2.z - p1.z) {}

    double i = 0;
    double j = 0;
    double k = 0;

    /** Computes the magnitude of this vector. */
    double Magnitude() const;

    /** Modifies this vector to be unit magnitude while retaining the direction. */
    void Normalize();

    /** Computes the dotproduct of 2 vectors. */
    double DotProduct(const Vector& o) const;

    /** Computes the cross product of 2 vectors. */
    Vector CrossProduct(const Vector& o) const;

    /** Computes the angle between 2 vectors. */
    double Angle(const Vector& o) const;

    /** Computes the new set of points by moving the specified point by the specified distance along the axis. */
    Point Project(double distance, const Point& start) const;

    /** Adds 2 vectors. */
    friend Vector operator+(const Vector& v1, const Vector& v2) {
      Vector v(v1.i + v2.i, v1.j + v2.j, v1.k + v2.k);
      return v;
    }
};

}