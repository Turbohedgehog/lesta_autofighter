#pragma once

#include <game/unit_config.h>

namespace game::config {

static constexpr inline UnitConfig kGoblinConfig = {
  .name = "Goblin",
  .strength = 1,
  .agility = 1,
  .stamina = 1,
  .health = 5,
  .default_damage = 2,
};

static constexpr inline UnitConfig kSkeletonConfig = {
  .name = "Skeleton",
  .strength = 2,
  .agility = 2,
  .stamina = 1,
  .health = 10,
  .default_damage = 2,
};

static constexpr inline UnitConfig kSlimeConfig = {
  .name = "Slime",
  .strength = 3,
  .agility = 1,
  .stamina = 2,
  .health = 8,
  .default_damage = 1,
};

static constexpr inline UnitConfig kGhostConfig = {
  .name = "Ghost",
  .strength = 1,
  .agility = 3,
  .stamina = 1,
  .health = 6,
  .default_damage = 3,
};

static constexpr inline UnitConfig kGolemConfig = {
  .name = "Golem",
  .strength = 3,
  .agility = 1,
  .stamina = 3,
  .health = 10,
  .default_damage = 1,
};

static constexpr inline UnitConfig kDragonConfig = {
  .name = "Dragon",
  .strength = 3,
  .agility = 3,
  .stamina = 3,
  .health = 20,
  .default_damage = 4,
};

}  // namespace game::config
