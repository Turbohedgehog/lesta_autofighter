#include "stone_skin.h"

#include <stdexcept>

#include <game/unit.h>

#include "../hero_factories/barbarian_factory.h"

namespace game::ability {

void StoneSkin::OnDefend(Damage& damage, Core& core) const {
  UnitAbilityBase::OnDefend(damage, core);

  if (damage.dealer.expired()) {
    throw std::runtime_error("StoneSkin: damage dealer not exists");
  }

  damage.ability_defense += damage.dealer.lock()->GetStamina();
}

std::string_view StoneSkin::GetName() const {
  return StoneSkin::kName;
}

std::string_view StoneSkin::GetGroupName() const {
  return game::hero::BarbarianFactory::kUnitTypeName;
}

}  // namespace game::ability
