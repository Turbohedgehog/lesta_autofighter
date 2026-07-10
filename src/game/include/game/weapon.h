#pragma once

#include <string>

#include <types/forward_declarations.h>

#include <game/weapon_config.h>
#include <game/damage.h>

namespace game {

class Weapon {
 public:
  Weapon(WeaponConfig config);
  const WeaponConfig& GetConfig() const;

 private:
  WeaponConfig config_;
};

}  // namespace game
