#pragma once

#include <game/unit_ability.h>

namespace game::ability {

class AppendAgility : public UnitAbilityBase {
 public:
  inline static constexpr std::string_view kName = "AppendAgility";

  std::string_view GetName() const override;
  std::string_view GetGroupName() const override;
  void ModifyUnitConfig(UnitConfig& config, Core& core) const override;
};

}  // namespace game::ability
