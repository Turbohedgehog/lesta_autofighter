#include "setup_monster.h"

#include <game/core.h>
#include <game/unit.h>

#include "../monster_factory.h"

#include "start_fight.h"

namespace game::phase {

std::string_view SetupMonster::GetName() const {
  return SetupMonster::kName;
}

void SetupMonster::Run(Core& core) {
  auto monster = std::allocate_shared<Unit>(core.GetAllocator(), UnitConfig());
  MonsterFactory monster_factory;
  monster_factory.ModifyUnit(*monster, core);
  monster->ResetStatsToConfig();
  core.SetMonster(monster);

  core.SetPhase(StartFight::kName);
}

}  // namespace game::phase
