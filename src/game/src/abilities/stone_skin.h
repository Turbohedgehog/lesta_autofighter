#pragma once

#include <game/unit_ability.h>

namespace game::ability {

class StoneSkin : public UnitAbilityBase {
 public:
  inline static constexpr std::string_view kName = "StoneSkin";

  void OnDefend(Damage& damage, Core& core) const override;
  std::string_view GetName() const override;
  std::string_view GetGroupName() const override;
};

}  // namespace game::ability
