#pragma once

#include <types/forward_declarations.h>

namespace game {

struct Fight {
  UnitWeakPtr attacker;
  UnitWeakPtr defender;
  uint32_t round {};
  uint32_t turn {};
};

}  // namespace game
