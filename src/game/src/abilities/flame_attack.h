#pragma once

#include <game/unit_ability.h>

namespace game::ability {

class FlameAttack : public UnitAbilityBase {
 public:
  inline static constexpr std::string_view kName = "FlameAttack";

  void OnAttack(Damage& damage, Core& core) const override;
  std::string_view GetName() const override;
};

}  // namespace game::ability
