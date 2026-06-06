#pragma once

#include <game/unit_config.h>

namespace game::config {

static constexpr inline size_t kMaxAbilityGroupsPerHero = 3;

static constexpr inline UnitConfig kHeroConfig = {
  .name = "Hero",
  .strength = 3,
  .agility = 3,
  .stamina = 3,
};

static constexpr inline UnitConfig kRogueConfig = {
  .health = 4,
};

static constexpr inline UnitConfig kWarriorConfig = {
  .health = 5,
};

static constexpr inline UnitConfig kBarbarianConfig = {
  .health = 6,
};

}  // namespace game::config
