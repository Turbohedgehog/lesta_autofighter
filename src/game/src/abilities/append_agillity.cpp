#include "append_agillity.h"

#include <game/unit_config.h>

#include "../hero_factories/rogue_factory.h"

namespace game::ability {

std::string_view AppendAgility::GetName() const {
  return AppendAgility::kName;
}

void AppendAgility::ModifyUnitConfig(UnitConfig& config, Core& core) const {
  UnitAbilityBase::ModifyUnitConfig(config, core);
  
  ++config.agility;
}

std::string_view AppendAgility::GetGroupName() const {
  return game::hero::RogueFactory::kUnitTypeName;
}

}  // namespace game::ability
