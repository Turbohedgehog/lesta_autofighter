#pragma once

#include <game/unit_ability.h>

namespace game::ability {

class Shield : public UnitAbilityBase {
 public:
  inline static constexpr std::string_view kName = "Shield";

  void OnDefend(Damage& damage, Core& core) const override;
  std::string_view GetName() const override;
  std::string_view GetGroupName() const override;
};

}  // namespace game::ability
