#include "libmath/vector.h"

#include <algorithm>
#include <cmath>

namespace libmath {
namespace {
  const Vector kAxisX(Point(0, 0, 0), Point(1, 0, 0));
  const Vector kAxisY(Point(0, 0, 0), Point(0, 1, 0));
  const Vector kAxisZ(Point(0, 0, 0), Point(0, 0, 1));
}

double Vector::Magnitude() const {
  return sqrt(i * i + j * j + k * k);
}

void Vector::Normalize() {
  double magnitude = Magnitude();
  i /= magnitude;
  j /= magnitude;
  k /= magnitude;
}

double Vector::DotProduct(const Vector& o) const {
  return i * o.i + j * o.j + k * o.k;
}

Vector Vector::CrossProduct(const Vector& o) const {
  Vector cross_product(j * o.k - k * o.j,
                       -1 * (i * o.k - k * o.i),
                       i * o.j - j * o.i);
  return cross_product;
}

double Vector::Angle(const Vector& o) const {
  // angle = acos((v1.v2) / (|v1| * |v2|))
  double mv1 = Magnitude();
  double mv2 = o.Magnitude();
  if (mv1 == 0 || mv2 == 0) {
    return 0;
  }

  double normalized_dotproduct = DotProduct(o) / (mv1 * mv2);
  normalized_dotproduct = std::clamp(normalized_dotproduct, -1.0, 1.0);
  return std::acos(normalized_dotproduct);
}

Point Vector::Project(double distance, const Point& start) const {
  Vector normalized = *this;
  normalized.Normalize();
  Point p(std::fma(distance, normalized.i, start.x),
          std::fma(distance, normalized.j, start.y),
          std::fma(distance, normalized.k, start.z));  // fma is x * y + z
  return p;
}

double Vector::MagnitudeX() const {
  return Magnitude() * std::cos(Angle(kAxisX));
}

double Vector::MagnitudeY() const {
  return Magnitude() * std::cos(Angle(kAxisY));
}

double Vector::MagnitudeZ() const {
  return Magnitude() * std::cos(Angle(kAxisZ));
}

void Vector::Decompose(double& x, double& y, double& z) const {
  x = MagnitudeX();
  y = MagnitudeY();
  z = MagnitudeZ();
}

void Vector::Decompose(double& x, double& y) const {
  x = MagnitudeX();
  x = MagnitudeY();
}

}