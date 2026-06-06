#pragma once

#include <game/unit_ability.h>

namespace game::ability {

class Rage : public UnitAbilityBase {
 public:
  static constexpr std::string_view kName = "Rage";

  void OnAttack(Damage& damage, Core& core) const override;
  std::string_view GetName() const override;
  std::string_view GetGroupName() const override;

};

}  // namespace game::ability