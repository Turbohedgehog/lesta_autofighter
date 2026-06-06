#include "rage.h"

#include <stdexcept>

#include <game/core.h>
#include <game/damage.h>

#include "../hero_factories/barbarian_factory.h"

namespace game::ability {

void Rage::OnAttack(Damage& damage, Core& core) const {
  UnitAbilityBase::OnAttack(damage, core);

  if (damage.dealer.expired()) {
    throw std::runtime_error("Rage: damage dealer not exists");
  }

  const auto& fight = core.GetFight();
  if (!fight) {
    throw std::runtime_error("Rage: no fight yet!");
  }

  if (fight->turn < 3) {
    damage.ability_damage += 2;
  } else {
    damage.ability_defense += 1;
  }
}

std::string_view Rage::GetName() const {
  return Rage::kName;
}

std::string_view Rage::GetGroupName() const {
  return game::hero::BarbarianFactory::kUnitTypeName;
}

}  // namespace game::ability
