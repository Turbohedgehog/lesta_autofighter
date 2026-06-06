#pragma once

#include <string_view>

namespace game {

struct UnitConfig {
  std::string_view name;
  uint32_t strength {};
  uint32_t agility {};
  uint32_t stamina {};
  uint32_t health {};
  uint32_t default_damage {};
};

}  // namespace game
