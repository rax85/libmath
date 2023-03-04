#include "libmath/point.h"

#include <cmath>

#include "gtest/gtest.h"

namespace libmath {
namespace {

TEST(PointTests, DistanceX) {
  Point p1(1, 0, 0);
  Point p2(3, 0, 0);
  EXPECT_DOUBLE_EQ(p1.Distance(p2), 2);
}

TEST(PointTests, DistanceY) {
  Point p1(0, 1, 0);
  Point p2(0, 3, 0);
  EXPECT_DOUBLE_EQ(p1.Distance(p2), 2);
}

TEST(PointTests, DistanceZ) {
  Point p1(0, 0, 1);
  Point p2(0, 0, 3);
  EXPECT_DOUBLE_EQ(p1.Distance(p2), 2);
}

TEST(PointTests, DistanceXYZ) {
  Point p1(1, 2, 3);
  Point p2(7, 8, 9);
  EXPECT_DOUBLE_EQ(p1.Distance(p2), 10.39230484541326);
}

}
}