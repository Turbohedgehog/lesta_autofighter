#pragma once

#include <game/unit_ability.h>

namespace game::ability {

class AppendStrength : public UnitAbilityBase {
 public:
  static constexpr std::string_view kName = "AppendStrength";

  void ModifyUnitConfig(UnitConfig& config, Core& core) const override;
  std::string_view GetName() const override;
  std::string_view GetGroupName() const override;
};

}  // namespace game::ability
