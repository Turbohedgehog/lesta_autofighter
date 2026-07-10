#include "append_stamina.h"

#include <game/unit_config.h>

#include "../hero_factories/barbarian_factory.h"

namespace game::ability {

void AppendStamina::ModifyUnitConfig(UnitConfig& config, Core& core) const {
  UnitAbilityBase::ModifyUnitConfig(config, core);

  ++config.stamina;
}

std::string_view AppendStamina::GetName() const {
  return AppendStamina::kName;
}

std::string_view AppendStamina::GetGroupName() const {
  return game::hero::BarbarianFactory::kUnitTypeName;
}

}  // namespace game::ability