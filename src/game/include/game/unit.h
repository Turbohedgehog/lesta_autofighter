#pragma once

#include <vector>
#include <optional>

#include <types/forward_declarations.h>

#include <game/unit_config.h>
#include <game/damage.h>
#include <game/weapon.h>

namespace game {

class Unit : public std::enable_shared_from_this<Unit> {
 public:
  Unit(UnitConfig config);
  virtual ~Unit() = default;

  void AppendAbility(UnitAbilityPtr ability, Core& core);
  const std::vector<UnitAbilityPtr>& GetAbilities() const;

  void SetWeapon(Weapon weapon, Core& core);
  const std::optional<Weapon>& GetWeapon() const;

  int GetStrength() const;
  int GetAgility() const;
  int GetStamina() const;
  int GetHealth() const;
  bool IsDead() const;

  Damage AttackTo(UnitWeakPtr other, Core& core);
  void Defend(Damage& damage, Core& core);

  std::string Stats() const;

  const UnitConfig& GetConfig() const;
  void ResetStatsToConfig();

 private:
  std::vector<UnitAbilityPtr> abilities_;
  std::optional<Weapon> weapon_;

  int strength_ {};
  int stamina_ {};
  int agility_ {};
  int health_ {};

  UnitConfig config_;
};

}  // namespace game
