#include "warrior_factory.h"

#include <stdexcept>
#include <format>

#include <configs/hero_configs.h>
#include <game/core.h>
#include <game/unit.h>
#include <game/weapon.h>
#include <configs/weapon_configs.h>

#include "../abilities/action_surge.h"
#include "../abilities/shield.h"
#include "../abilities/append_strength.h"
#include "../abilities/append_health.h"

namespace game::hero {

void WarriorFactory::ModifyUnit(Unit& unit, Core& core) const {
  auto current_level = CalculateAbilityGroupsCount(unit);

  if (!unit.GetWeapon()) {
    unit.SetWeapon(Weapon(game::config::kSwordConfig), core);
  }

  auto allocator = core.GetAllocator();
  switch (current_level) {
    case 0:
      unit.AppendAbility(std::allocate_shared<game::ability::ActionSurge>(allocator), core);
      unit.AppendAbility(std::allocate_shared<game::ability::AppendHealth>(allocator, game::config::kWarriorConfig.health), core);
      break;
    case 1:
      unit.AppendAbility(std::allocate_shared<game::ability::Shield>(allocator), core);
      unit.AppendAbility(std::allocate_shared<game::ability::AppendHealth>(allocator, game::config::kWarriorConfig.health), core);
      break;
    case 2:
      unit.AppendAbility(std::allocate_shared<game::ability::AppendStrength>(allocator), core);
      unit.AppendAbility(std::allocate_shared<game::ability::AppendHealth>(allocator, game::config::kWarriorConfig.health), core);
      break;
    default:
      throw std::runtime_error(std::format("WarriorFactory: Unsupported unit grade = {}", current_level));
  }
}

std::string_view WarriorFactory::GetUnitTypeName() const {
  return WarriorFactory::kUnitTypeName;
}

bool WarriorFactory::CanModifyUnit(const Unit& unit) const {
  auto c = CalculateAbilityGroupsCount(unit);
  return c < game::config::kMaxAbilityGroupsPerHero;
  return CalculateAbilityGroupsCount(unit) < game::config::kMaxAbilityGroupsPerHero;
}

}  // namespace game::hero
