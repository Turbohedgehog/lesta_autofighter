#pragma once

#include <string_view>

namespace game {

struct WeaponConfig {
  std::string_view name; 
  uint32_t damage_amount {};
  std::string_view damage_type;
};

}  // namespace game
