#include "libmath/interpolate.h"

#include <cmath>

#include "gtest/gtest.h"

namespace libmath {
namespace {

TEST(InterpolateTests, LinearInterpolation) {
  PointWithValue p1(1, 1, 1, 10);
  PointWithValue p2(2, 2, 2, 20);
  LinearInterpolator interpolator(p1, p2);
  EXPECT_DOUBLE_EQ(interpolator.Interpolate({1.5, 1.5, 1.5}), 15);
}

TEST(InterpolateTests, LinearInterpolationPositiveBackward) {
  PointWithValue p1(2, 2, 2, 20);
  PointWithValue p2(1, 1, 1, 10);
  LinearInterpolator interpolator(p1, p2);
  EXPECT_DOUBLE_EQ(interpolator.Interpolate({1.5, 1.5, 1.5}), 15);
}

TEST(InterpolateTests, LinearInterpolationNegative) {
  PointWithValue p1(-1, -1, -1, -10);
  PointWithValue p2(-2, -2, -2, -20);
  LinearInterpolator interpolator(p1, p2);
  EXPECT_DOUBLE_EQ(interpolator.Interpolate({-1.5, -1.5, -1.5}), -15);
}

TEST(InterpolateTests, LinearInterpolationNegativeBackward) {
  PointWithValue p1(-2, -2, -2, -20);
  PointWithValue p2(-1, -1, -1, -10);
  LinearInterpolator interpolator(p1, p2);
  EXPECT_DOUBLE_EQ(interpolator.Interpolate({-1.5, -1.5, -1.5}), -15);
}

TEST(InterpolateTests, BilinearInterpolation) {
  PointWithValue p00({0, 0}, 0);
  PointWithValue p10({1, 0}, 1);
  PointWithValue p11({1, 1}, 2);
  PointWithValue p01({0, 1}, 1);

  BilinearInterpolator interpolator(p00, p10, p11, p01);
  EXPECT_DOUBLE_EQ(interpolator.Interpolate({0.5, 0.5}), 1);
}

}
}