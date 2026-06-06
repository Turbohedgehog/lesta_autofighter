#include "shield.h"

#include <stdexcept>

#include <game/unit.h>

#include "../hero_factories/warrior_factory.h"

namespace game::ability {

void Shield::OnDefend(Damage& damage, Core& core) const {
  UnitAbilityBase::OnDefend(damage, core);

  if (damage.dealer.expired()) {
    throw std::runtime_error("HiddenAttack: damage dealer not exists");
  }

  if (damage.receiver.expired()) {
    throw std::runtime_error("HiddenAttack: damage receiver not exists");
  }

  if (damage.receiver.lock()->GetStrength() > damage.dealer.lock()->GetStrength()) {
    damage.ability_defense += 3;
  }
}

std::string_view Shield::GetName() const {
  return Shield::kName;
}

std::string_view Shield::GetGroupName() const {
  return game::hero::WarriorFactory::kUnitTypeName;
}

}  // namespace game::ability
