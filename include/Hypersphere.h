#pragma once
#include "Object4D.h"
namespace rt4 {
class Hypersphere : public Object4D {
  vec4 m_center;
  float m_r;

public:
  int vec4Collides(vec4 vec);
  Hypersphere(vec4 center, float r) : m_center(center), m_r(r) {}
};
} // namespace rt4
