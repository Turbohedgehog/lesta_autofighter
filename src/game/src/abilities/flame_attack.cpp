#include "flame_attack.h"

#include <stdexcept>

#include <game/core.h>
#include <game/damage.h>

#include "../hero_factories/rogue_factory.h"

namespace game::ability {

std::string_view FlameAttack::GetName() const {
  return FlameAttack::kName;
}

void FlameAttack::OnAttack(Damage& damage, Core& core) const {
  UnitAbilityBase::OnAttack(damage, core);

  const auto& fight = core.GetFight();
  if (!fight) {
    throw std::runtime_error("FlameAttack: no fight yet!");
  }

  if ((fight->turn + 1) % 3 == 0) {
    damage.ability_damage += 3;
  }
}

}  // namespace game::ability