#include "hidden_attack.h"

#include <stdexcept>

#include <game/unit.h>

#include "../hero_factories/rogue_factory.h"

namespace game::ability {

void HiddenAttack::OnAttack(Damage& damage, Core& core) const {
  UnitAbilityBase::OnAttack(damage, core);

  if (damage.dealer.expired()) {
    throw std::runtime_error("HiddenAttack: damage dealer not exists");
  }

  if (damage.receiver.expired()) {
    throw std::runtime_error("HiddenAttack: damage receiver not exists");
  }

  if (damage.dealer.lock()->GetAgility() > damage.receiver.lock()->GetAgility()) {
    ++damage.ability_damage;
  }
}

std::string_view HiddenAttack::GetName() const {
  return HiddenAttack::kName;
}

std::string_view HiddenAttack::GetGroupName() const {
  return game::hero::RogueFactory::kUnitTypeName;
}

}  // namespace game::ability