#include "slashing_damage_protection.h"

#include <stdexcept>

#include <game/damage.h>
#include <game/unit.h>
#include <game/weapon.h>
#include <configs/damage_types.h>

namespace game::ability {

std::string_view SlashingDamageProtection::GetName() const {
  return SlashingDamageProtection::kName;
}

void SlashingDamageProtection::OnDefend(Damage& damage, Core& core) const {
  UnitAbilityBase::OnDefend(damage, core);

  if (damage.dealer.expired()) {
    throw std::runtime_error("SlashingDamageProtection: damage dealer not exists");
  }

  auto weapon = damage.dealer.lock()->GetWeapon();
  if (!weapon) {
    return;
  }

  if (weapon->GetConfig().damage_type == game::config::kSlashingDamageType) {
    damage.weapon_damage = 0;
  }
}

}  // namespace game::ability
