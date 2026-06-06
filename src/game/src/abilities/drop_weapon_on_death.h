#pragma once

#include <game/unit_ability.h>

#include <game/weapon_config.h>

namespace game::ability {

class DropWeaponOnDeath : public UnitAbilityBase {
 public:
  inline static constexpr std::string_view kName = "DropWeaponOnDeath";

  DropWeaponOnDeath(WeaponConfig weapon_config);
  void OnDeath(Damage& damage, Core& core) const override;
  std::string_view GetName() const override;

 private:
  WeaponConfig weapon_config_;
};

}  // namespace game::ability
