#pragma once

#include <types/forward_declarations.h>

namespace game {

struct Damage {
  UnitWeakPtr dealer;
  UnitWeakPtr receiver;
  uint32_t weapon_damage {};
  uint32_t ability_damage {};
  uint32_t ability_defense {};
};

}  // namespace game
