#pragma once

#include <string_view>

#include <configs/damage_types.h>
#include <game/weapon_config.h>

namespace game::config {

inline static constexpr WeaponConfig kSwordConfig = {
  .name = "Sword",
  .damage_amount = 3,
  .damage_type = kSlashingDamageType,
};

inline static constexpr WeaponConfig kClubConfig = {
  .name = "Club",
  .damage_amount = 3,
  .damage_type = kBludgeoningDamageType,
};

inline static constexpr WeaponConfig kDaggerConfig = {
  .name = "Dagger",
  .damage_amount = 2,
  .damage_type = kPiercingDamageType,
};

inline static constexpr WeaponConfig kAxeConfig = {
  .name = "Axe",
  .damage_amount = 4,
  .damage_type = kSlashingDamageType,
};

inline static constexpr WeaponConfig kSpearConfig = {
  .name = "Spear",
  .damage_amount = 3,
  .damage_type = kPiercingDamageType,
};

inline static constexpr WeaponConfig kLegendarySwordConfig = {
  .name = "Legendary Sword",
  .damage_amount = 10,
  .damage_type = kSlashingDamageType,
};

}  // namespace game::config
