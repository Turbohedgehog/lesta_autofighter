#include "modify_config.h"

#include <game/unit_config.h>

namespace game::ability {

ModifyConfig::ModifyConfig(UnitConfig config)
  : config_(std::move(config)) {}

void ModifyConfig::ModifyUnitConfig(UnitConfig& config, Core& core) const {
  config = config_;
  
  UnitAbilityBase::ModifyUnitConfig(config, core);
}

std::string_view ModifyConfig::GetName() const {
  return ModifyConfig::kName;
}

}  // namespace game::ability