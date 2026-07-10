#pragma once

#include <game/unit_ability.h>
#include <game/unit_config.h>

namespace game::ability {

class ModifyConfig : public UnitAbilityBase {
 public:
  static constexpr std::string_view kName = "ModifyConfig";

  ModifyConfig(UnitConfig config);
  void ModifyUnitConfig(UnitConfig& config, Core& core) const override;
  std::string_view GetName() const override;

 private:
  UnitConfig config_;
};

}  // namespace game::ability
