#include "libmath/interpolate.h"

#include <cmath>

#include "libmath/vector.h"

namespace libmath {
namespace {

/**
 * @brief Projects a point onto the line formed by the other 2 points.
 * Assumes that the point will be projected within the segment.
 */
Point Project(const Point& p1, const Point& p2, const Point p) {
  Vector adjacent(p1, p2);
  Vector hypotenuse(p1, p);
  double angle = adjacent.Angle(hypotenuse);
  double length_along_line = hypotenuse.Magnitude() * std::sin(angle);
  return adjacent.Project(length_along_line, p1);
}

PointWithValue InterpolateIntermediate(const PointWithValue& p1, const PointWithValue& p2, const Point& p) {
  LinearInterpolator interpolator(p1, p2);
  return PointWithValue(p, interpolator.Interpolate(p));
}

}

double LinearInterpolator::Interpolate(const Point& p) {
  double ratio = p1_.Distance(p) / p1_.Distance(p2_);
  double delta = p2_.value - p1_.value;
  return p1_.value + delta * ratio;
}

double BilinearInterpolator::Interpolate(const Point& p) {
  Point p_00_10 = Project(p00_, p10_, p);
  Point p_01_11 = Project(p01_, p11_, p);

  PointWithValue intermediate1 = InterpolateIntermediate(p00_, p10_, p_00_10);
  PointWithValue intermediate2 = InterpolateIntermediate(p01_, p11_, p_01_11);

  LinearInterpolator interpolator(intermediate1, intermediate2);
  return interpolator.Interpolate(p);
}

}