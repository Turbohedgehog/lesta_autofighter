#pragma once

#include <game/unit_ability.h>

namespace game::ability {

class BludgeoningDamageReceiver : public UnitAbilityBase {
 public:
  static constexpr std::string_view kName = "BludgeoningDamageReceiver";

  std::string_view GetName() const override;
  void OnDefend(Damage& damage, Core& core) const override;
};

}  // namespace game::ability