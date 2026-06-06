#include "action_surge.h"

#include <stdexcept>

#include <game/core.h>
#include <game/damage.h>

#include "../hero_factories/warrior_factory.h"

namespace game::ability {

void ActionSurge::OnAttack(Damage& damage, Core& core) const {
  UnitAbilityBase::OnAttack(damage, core);

  const auto& fight = core.GetFight();
  if (!fight) {
    throw std::runtime_error("Poison: no fight yet!");
  }

  if (fight->turn == 0) {
    damage.weapon_damage *= 2;
  }
}

std::string_view ActionSurge::GetName() const {
  return ActionSurge::kName;
}

std::string_view ActionSurge::GetGroupName() const {
  return game::hero::WarriorFactory::kUnitTypeName;
}

}  // namespace game::ability
