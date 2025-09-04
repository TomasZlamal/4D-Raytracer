#include "../include/Hypersphere.h"
#include <cmath>
namespace rt4 {

int Hypersphere::vec4Collides(vec4 vec) {
  float a, b, c;
  a = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w;
  b = -2 * (m_center.x * vec.x + m_center.y * vec.y + m_center.z * vec.z +
            m_center.w * vec.w);
  c = -(m_r * m_r) + m_center.x * m_center.x + m_center.y * m_center.y +
      m_center.z * m_center.z + m_center.w * m_center.w;
  if ((b * b - 4 * a * c) > 0) {
    // check if t1, t2 are negative. Stop returning negative values, since that would mean going behing the camera.
    // then return the value closest to the camera, so it should actually be std::min, not std::max.
    float D = (b * b - 4 * a * c);
    float t1 = (-b + std::sqrt(D)) / (2 * a);
    float t2 = (-b - std::sqrt(D)) / (2 * a);
    return std::max(t1, t2);
  }
  return 0;
}
} // namespace rt4
