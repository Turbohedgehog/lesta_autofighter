#include "barbarian_factory.h"

#include <stdexcept>
#include <format>

#include <configs/hero_configs.h>
#include <game/core.h>
#include <game/unit.h>
#include <game/weapon.h>
#include <configs/weapon_configs.h>

#include "../abilities/rage.h"
#include "../abilities/stone_skin.h"
#include "../abilities/append_stamina.h"
#include "../abilities/append_health.h"

namespace game::hero {

void BarbarianFactory::ModifyUnit(Unit& unit, Core& core) const {
  auto current_level = CalculateAbilityGroupsCount(unit);

  if (!unit.GetWeapon()) {
    unit.SetWeapon(Weapon(game::config::kClubConfig), core);
  }

  auto allocator = core.GetAllocator();
  switch (current_level) {
    case 0:
      unit.AppendAbility(std::allocate_shared<game::ability::Rage>(allocator), core);
      unit.AppendAbility(std::allocate_shared<game::ability::AppendHealth>(allocator, game::config::kBarbarianConfig.health), core);
      break;
    case 1:
      unit.AppendAbility(std::allocate_shared<game::ability::StoneSkin>(allocator), core);
      unit.AppendAbility(std::allocate_shared<game::ability::AppendHealth>(allocator, game::config::kBarbarianConfig.health), core);
      break;
    case 2:
      unit.AppendAbility(std::allocate_shared<game::ability::AppendStamina>(allocator), core);
      unit.AppendAbility(std::allocate_shared<game::ability::AppendHealth>(allocator, game::config::kBarbarianConfig.health), core);
      break;
    default:
      throw std::runtime_error(std::format("BarbarianFactory: Unsupported unit grade = {}", current_level));
  }
}

std::string_view BarbarianFactory::GetUnitTypeName() const {
  return BarbarianFactory::kUnitTypeName;
}

bool BarbarianFactory::CanModifyUnit(const Unit& unit) const {
  auto c = CalculateAbilityGroupsCount(unit);
  return c < game::config::kMaxAbilityGroupsPerHero;
  return CalculateAbilityGroupsCount(unit) < game::config::kMaxAbilityGroupsPerHero;
}

}  // namespace game::hero