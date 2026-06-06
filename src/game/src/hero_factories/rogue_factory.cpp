#include "rogue_factory.h"

#include <stdexcept>
#include <format>

#include <configs/hero_configs.h>
#include <game/core.h>
#include <game/unit.h>
#include <game/weapon.h>
#include <configs/weapon_configs.h>

#include "../abilities/hidden_attack.h"
#include "../abilities/append_agillity.h"
#include "../abilities/poison.h"
#include "../abilities/append_health.h"

namespace game::hero {

void RogueFactory::ModifyUnit(Unit& unit, Core& core) const {
  auto current_level = CalculateAbilityGroupsCount(unit);

  if (!unit.GetWeapon()) {
    unit.SetWeapon(Weapon(game::config::kDaggerConfig), core);
  }

  auto allocator = core.GetAllocator();
  switch (current_level) {
    case 0:
      unit.AppendAbility(std::allocate_shared<game::ability::HiddenAttack>(allocator), core);
      unit.AppendAbility(std::allocate_shared<game::ability::AppendHealth>(allocator, game::config::kRogueConfig.health), core);
      break;
    case 1:
      unit.AppendAbility(std::allocate_shared<game::ability::AppendAgility>(allocator), core);
      unit.AppendAbility(std::allocate_shared<game::ability::AppendHealth>(allocator, game::config::kRogueConfig.health), core);
      break;
    case 2:
      unit.AppendAbility(std::allocate_shared<game::ability::Poison>(allocator), core);
      unit.AppendAbility(std::allocate_shared<game::ability::AppendHealth>(allocator, game::config::kRogueConfig.health), core);
      break;
    default:
      throw std::runtime_error(std::format("RogueFactory: Unsupported unit grade = {}", current_level));
  }
}

std::string_view RogueFactory::GetUnitTypeName() const {
  return RogueFactory::kUnitTypeName;
}

bool RogueFactory::CanModifyUnit(const Unit& unit) const {
  auto c = CalculateAbilityGroupsCount(unit);
  return c < game::config::kMaxAbilityGroupsPerHero;
  return CalculateAbilityGroupsCount(unit) < game::config::kMaxAbilityGroupsPerHero;
}

}  // namespace game::hero