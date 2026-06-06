#pragma once

#include <string_view>
#include <vector>

#include <types/forward_declarations.h>

namespace game {

class PhaseBase {
 public:
  virtual ~PhaseBase() = default;

  virtual void Run(Core& core) = 0;
  virtual std::string_view GetName() const = 0;
};

}  // namespace game
