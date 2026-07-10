#pragma once

#include <types/forward_declarations.h>

#include <game/unit_ability.h>
#include <configs/weapon_configs.h>

namespace game::ability {

class DropWeapon : public UnitAbilityBase {
 public:
  inline static constexpr std::string_view kName = "DropWeapon";

  DropWeapon(WeaponConfig weapon_config);
  void OnDeath(Damage& damage, Core& core) const override;
  std::string_view GetName() const override;

 private:
  WeaponConfig weapon_config_;
};

}  // namespace game::ability
