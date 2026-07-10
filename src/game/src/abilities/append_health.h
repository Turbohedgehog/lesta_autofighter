#pragma once

#pragma once

#include <game/unit_ability.h>

namespace game::ability {

class AppendHealth : public UnitAbilityBase {
 public:
  inline static constexpr std::string_view kName = "AppendHealth";

  AppendHealth(int health);
  std::string_view GetName() const override;
  void ModifyUnitConfig(UnitConfig& config, Core& core) const override;

 private:
  int health_ {};
};

}  // namespace game::ability
