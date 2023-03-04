#pragma once

#include "libmath/point.h"

namespace libmath {

/** @brief Linear interpolation in 1 dimension. */
class LinearInterpolator {
  public:
    explicit LinearInterpolator(const PointWithValue& p1, const PointWithValue& p2) : p1_(p1), p2_(p2) {}

    /** @brief Interpolates the value at the specified point. */
    double Interpolate(const Point& p);

  private:
    PointWithValue p1_;
    PointWithValue p2_;
};

/** @brief Linear interpolation in 2 dimensions, assumes the 4 reference points form a rectangle. */
class BilinearInterpolator {
  public:
    explicit BilinearInterpolator(const PointWithValue& p00, const PointWithValue& p10,
                                  const PointWithValue& p11, const PointWithValue& p01)
                                      : p00_(p00), p10_(p10), p11_(p11), p01_(p01) {}

    /** @brief Interpolates the value at the specified point. */
    double Interpolate(const Point& p);

  private:
    PointWithValue p00_;
    PointWithValue p10_;
    PointWithValue p11_;
    PointWithValue p01_;
};

}