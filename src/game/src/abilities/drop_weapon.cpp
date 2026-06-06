#include "drop_weapon.h"

#include <stdexcept>

#include <game/core.h>
#include <game/damage.h>
#include <game/unit.h>
#include <game/weapon.h>


namespace game::ability {

DropWeapon::DropWeapon(WeaponConfig weapon_config)
    : weapon_config_(weapon_config) {}

std::string_view DropWeapon::GetName() const {
  return DropWeapon::kName;
}

void DropWeapon::OnDeath(Damage& damage, Core& core) const {
  UnitAbilityBase::OnDeath(damage, core);

  damage.dealer.lock()->SetWeapon(Weapon(weapon_config_), core);
}

}  // namespace game::ability