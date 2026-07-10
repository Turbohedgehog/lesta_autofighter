#include "append_health.h"

#include <game/unit_config.h>

#include "../hero_factories/rogue_factory.h"

namespace game::ability {

AppendHealth::AppendHealth(int health)
  : health_(health) {}

std::string_view AppendHealth::GetName() const {
  return AppendHealth::kName;
}

void AppendHealth::ModifyUnitConfig(UnitConfig& config, Core& core) const {
  UnitAbilityBase::ModifyUnitConfig(config, core);

  ++config.health;
}

}  // namespace game::ability
