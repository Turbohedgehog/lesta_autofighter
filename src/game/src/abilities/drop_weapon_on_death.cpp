#include "drop_weapon_on_death.h"

#include <format>
#include <stdexcept>

#include <game/core.h>
#include <game/unit.h>
#include <game/user_interface.h>
#include <game/weapon.h>

namespace game::ability {

DropWeaponOnDeath::DropWeaponOnDeath(WeaponConfig weapon_config)
  : weapon_config_(std::move(weapon_config)) {}

std::string_view DropWeaponOnDeath::GetName() const {
  return DropWeaponOnDeath::kName;
}

void DropWeaponOnDeath::OnDeath(Damage& damage, Core& core) const {
  UnitAbilityBase::OnDeath(damage, core);

  if (damage.dealer.expired()) {
    throw std::runtime_error("DropWeaponOnDeath: damage dealer not exists");
  }

  auto& damage_dealer = *damage.dealer.lock();

  auto user_interface = core.GetUserInterfaceChecked();
  user_interface.get().Exclaim(std::format("{} gets weapon {}", damage_dealer.GetConfig().name, weapon_config_.name));

  damage_dealer.SetWeapon(Weapon(weapon_config_), core);
}

}  // namespace game::ability
