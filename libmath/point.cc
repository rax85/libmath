#include "libmath/point.h"

#include <cmath>

namespace libmath {

double Point::Distance(const Point& p) {
  double dx = x - p.x;
  double dy = y - p.y;
  double dz = z - p.z;
  return std::sqrt(dx * dx + dy * dy + dz * dz);
}

}