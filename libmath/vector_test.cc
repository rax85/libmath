#include "libmath/vector.h"

#include <cmath>

#include "gtest/gtest.h"

namespace libmath {
namespace {

TEST(VectorTest, FromPoints3d) {
  Vector v(Point(2, 2, 1), Point(6, 3, 2));
  EXPECT_DOUBLE_EQ(v.i, 4);
  EXPECT_DOUBLE_EQ(v.j, 1);
  EXPECT_DOUBLE_EQ(v.k, 1);
}

TEST(VectorTest, FromPoints2d) {
  Vector v(Point(2, 2), Point(6, 3));
  EXPECT_DOUBLE_EQ(v.i, 4);
  EXPECT_DOUBLE_EQ(v.j, 1);
  EXPECT_DOUBLE_EQ(v.k, 0);
}

TEST(VectorTest, Magnitude) {
  Vector v(1, 1, 1);
  EXPECT_FLOAT_EQ(v.Magnitude(), 1.732051);
}

TEST(VectorTest, Normalize) {
  Vector v(3, 4, 5);
  v.Normalize();
  EXPECT_FLOAT_EQ(v.i, 0.424264068711928);
  EXPECT_FLOAT_EQ(v.j, 0.565685424949238);
  EXPECT_FLOAT_EQ(v.k, 0.707106781186547);
}

TEST(VectorTest, DotProduct) {
  Vector v1(2, 3, 4);
  Vector v2(7, 2, 5);
  EXPECT_FLOAT_EQ(v1.DotProduct(v2), 40);
}

TEST(VectorTest, CrossProduct) {
  Vector v1(2, 3, 4);
  Vector v2(7, 2, 5);
  Vector xp = v1.CrossProduct(v2);
  EXPECT_FLOAT_EQ(xp.i, 7);
  EXPECT_FLOAT_EQ(xp.j, 18);
  EXPECT_FLOAT_EQ(xp.k, -17);
}

TEST(VectorTest, ComputeAngle) {
  Vector v1(3, 4, 2);
  Vector v2(4, 3, 7);
  EXPECT_FLOAT_EQ(v1.Angle(v2), 0.608874);
}

TEST(VectorTest, Addition3d) {
  Vector v1(2, 3, 4);
  Vector v2(3, 4, 5);
  Vector v3 = v1 + v2;
  EXPECT_DOUBLE_EQ(v3.i, 5);
  EXPECT_DOUBLE_EQ(v3.j, 7);
  EXPECT_DOUBLE_EQ(v3.k, 9);
}

TEST(VectorTest, Addition2d) {
  Vector v1(2, 3);
  Vector v2(3, 4);
  Vector v3 = v1 + v2;
  EXPECT_DOUBLE_EQ(v3.i, 5);
  EXPECT_DOUBLE_EQ(v3.j, 7);
  EXPECT_DOUBLE_EQ(v3.k, 0);
}

TEST(VectorTest, ProjectForward) {
  Point s(2, 2, 1);
  Point e(6, 3, 2);
  Vector v(s, e);

  Point projected = v.Project(v.Magnitude(), s);

  EXPECT_DOUBLE_EQ(e.x, projected.x);
  EXPECT_DOUBLE_EQ(e.y, projected.y);
  EXPECT_DOUBLE_EQ(e.z, projected.z);
}

TEST(VectorTest, ProjectBackward) {
  Point s(2, 2, 1);
  Point e(6, 3, 2);
  Vector v(s, e);

  Point projected = v.Project(-1 * v.Magnitude(), e);

  EXPECT_DOUBLE_EQ(projected.x, s.x);
  EXPECT_DOUBLE_EQ(projected.y, s.y);
  EXPECT_DOUBLE_EQ(projected.z, s.z);
}

TEST(VectorTest, Project2d) {
  Point s(2, 2);
  Point e(6, 3);
  Vector v(s, e);

  Point projected = v.Project(v.Magnitude(), s);

  EXPECT_DOUBLE_EQ(projected.x, e.x);
  EXPECT_DOUBLE_EQ(projected.y, e.y);
  EXPECT_DOUBLE_EQ(projected.z, 0);
}

TEST(VectorTest, Decompose) {
  Vector v(13, 7, 19);
  double x_mag = 0;
  double y_mag = 0;
  double z_mag = 0;

  v.Decompose(x_mag, y_mag, z_mag);
  double reconstituted = std::sqrt(x_mag * x_mag + y_mag * y_mag + z_mag * z_mag);
  EXPECT_DOUBLE_EQ(v.Magnitude(), reconstituted);
}

}
}