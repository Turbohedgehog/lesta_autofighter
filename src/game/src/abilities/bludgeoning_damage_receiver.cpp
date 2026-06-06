#include "bludgeoning_damage_receiver.h"

#include <stdexcept>

#include <game/damage.h>
#include <game/unit.h>
#include <game/weapon.h>
#include <configs/damage_types.h>

namespace game::ability {

std::string_view BludgeoningDamageReceiver::GetName() const {
  return BludgeoningDamageReceiver::kName;
}

void BludgeoningDamageReceiver::OnDefend(Damage& damage, Core& core) const {
  UnitAbilityBase::OnDefend(damage, core);

  if (damage.dealer.expired()) {
    throw std::runtime_error("BludgeoningDamageReceiver: damage dealer not exists");
  }

  auto weapon = damage.dealer.lock()->GetWeapon();
  if (!weapon) {
    return;
  }

  if (weapon->GetConfig().damage_type == game::config::kBludgeoningDamageType) {
    damage.weapon_damage *= 2;
    damage.ability_damage *= 2;
  }
}

}  // namespace game::ability
