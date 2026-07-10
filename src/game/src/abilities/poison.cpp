#include "poison.h"

#include <stdexcept>

#include <game/core.h>
#include <game/damage.h>

#include "../hero_factories/rogue_factory.h"

namespace game::ability {

std::string_view Poison::GetName() const {
  return Poison::kName;
}

void Poison::OnAttack(Damage& damage, Core& core) const {
  UnitAbilityBase::OnAttack(damage, core);

  const auto& fight = core.GetFight();
  if (!fight) {
    throw std::runtime_error("Poison: no fight yet!");
  }

  damage.ability_damage += fight->turn;
}

std::string_view Poison::GetGroupName() const {
  return game::hero::RogueFactory::kUnitTypeName;
}

}  // namespace game::ability