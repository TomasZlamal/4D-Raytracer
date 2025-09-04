#pragma once
#include "Object4D.h"
#include <memory>
#include <optional>
#include <vector>
namespace rt4 {
#define TAKES_OWNERSHIP
class ObjectWorld {
  std::vector<std::shared_ptr<Object4D *>> objects;

public:
  bool addObject(TAKES_OWNERSHIP Object4D *object) {
    objects.push_back(std::make_shared<Object4D *>(object));
    return true;
  }
  std::optional<std::weak_ptr<Object4D *>> borrowNthObject(int n) {
    if (n >= objects.size()) {
      return {};
    }
    return std::weak_ptr<Object4D *>(objects[n]);
  }
};
} // namespace rt4
