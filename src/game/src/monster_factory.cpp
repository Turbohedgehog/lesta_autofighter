#include "monster_factory.h"

#include <array>

#include <game/core.h>
#include <game/unit.h>

#include <configs/monster_configs.h>
#include <configs/weapon_configs.h>

#include "abilities/modify_config.h"
#include "abilities/bludgeoning_damage_receiver.h"
#include "abilities/slashing_damage_protection.h"
#include "abilities/hidden_attack.h"
#include "abilities/stone_skin.h"
#include "abilities/flame_attack.h"
#include "abilities/drop_weapon_on_death.h"

namespace game {

void CreateGoblin(Unit& unit, Core& core) {
  auto allocator = core.GetAllocator();

  unit.AppendAbility(std::allocate_shared<game::ability::ModifyConfig>(allocator, game::config::kGoblinConfig), core);
  unit.AppendAbility(std::allocate_shared<game::ability::DropWeaponOnDeath>(allocator, game::config::kDaggerConfig), core);
}

void CreateSkeleton(Unit& unit, Core& core) {
  auto allocator = core.GetAllocator();

  unit.AppendAbility(std::allocate_shared<game::ability::ModifyConfig>(allocator, game::config::kSkeletonConfig), core);
  unit.AppendAbility(std::allocate_shared<game::ability::BludgeoningDamageReceiver>(allocator), core);
  unit.AppendAbility(std::allocate_shared<game::ability::DropWeaponOnDeath>(allocator, game::config::kClubConfig), core);
}

void CreateSlime(Unit& unit, Core& core) {
  auto allocator = core.GetAllocator();

  unit.AppendAbility(std::allocate_shared<game::ability::ModifyConfig>(allocator, game::config::kSlimeConfig), core);
  unit.AppendAbility(std::allocate_shared<game::ability::SlashingDamageProtection>(allocator), core);
  unit.AppendAbility(std::allocate_shared<game::ability::DropWeaponOnDeath>(allocator, game::config::kSpearConfig), core);
}

void CreateGhost(Unit& unit, Core& core) {
  auto allocator = core.GetAllocator();

  unit.AppendAbility(std::allocate_shared<game::ability::ModifyConfig>(allocator, game::config::kGhostConfig), core);
  unit.AppendAbility(std::allocate_shared<game::ability::HiddenAttack>(allocator), core);
  unit.AppendAbility(std::allocate_shared<game::ability::DropWeaponOnDeath>(allocator, game::config::kSwordConfig), core);
}

void CreateGolem(Unit& unit, Core& core) {
  auto allocator = core.GetAllocator();

  unit.AppendAbility(std::allocate_shared<game::ability::ModifyConfig>(allocator, game::config::kGolemConfig), core);
  unit.AppendAbility(std::allocate_shared<game::ability::SlashingDamageProtection>(allocator), core);
  unit.AppendAbility(std::allocate_shared<game::ability::DropWeaponOnDeath>(allocator, game::config::kAxeConfig), core);
}

void CreateDragon(Unit& unit, Core& core) {
  auto allocator = core.GetAllocator();

  unit.AppendAbility(std::allocate_shared<game::ability::ModifyConfig>(allocator, game::config::kDragonConfig), core);
  unit.AppendAbility(std::allocate_shared<game::ability::FlameAttack>(allocator), core);
  unit.AppendAbility(std::allocate_shared<game::ability::DropWeaponOnDeath>(allocator, game::config::kLegendarySwordConfig), core);
}

bool MonsterFactory::CanModifyUnit(const Unit&) const {
  return true;
}

void MonsterFactory::ModifyUnit(Unit& unit, Core& core) const {
  auto factories = std::array {
    &CreateGoblin,
    &CreateSkeleton,
    &CreateSlime,
    &CreateGhost,
    &CreateGolem,
    &CreateDragon,
  };

  auto& random_engine = core.GetRandomEngine();
  auto idx = std::uniform_int_distribution<size_t>(0, factories.size() - 1)(random_engine);
  factories[idx](unit, core);
}

std::string_view MonsterFactory::GetUnitTypeName() const {
  return MonsterFactory::kUnitTypeName;
}

}  // namespace game
