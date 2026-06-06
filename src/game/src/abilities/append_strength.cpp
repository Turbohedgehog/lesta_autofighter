#include "append_strength.h"

#include <game/unit_config.h>

#include "../hero_factories/warrior_factory.h"

namespace game::ability {

void AppendStrength::ModifyUnitConfig(UnitConfig& config, Core& core) const {
  UnitAbilityBase::ModifyUnitConfig(config, core);

  ++config.strength;
}

std::string_view AppendStrength::GetName() const {
  return AppendStrength::kName;
}

std::string_view AppendStrength::GetGroupName() const {
  return game::hero::WarriorFactory::kUnitTypeName;
}

}  // namespace game::ability