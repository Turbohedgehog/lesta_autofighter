#include <game/weapon.h>

namespace game {

Weapon::Weapon(WeaponConfig config)
    : config_(std::move(config)) {}

const WeaponConfig& Weapon::GetConfig() const {
  return config_;
}

}  // namespace game