#pragma once
#include "vec4.h"
namespace rt4 {
class Object4D {
public:
  virtual int vec4Collides(vec4 vec) = 0;
};
} // namespace rt4
