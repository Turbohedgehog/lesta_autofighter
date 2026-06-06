#include <game/bootstrap.h>


#include <game/core.h>

#include "phases/start_game_phase.h"
#include "phases/setup_hero.h"
#include "phases/setup_monster.h"
#include "phases/start_fight.h"
#include "phases/fight.h"
#include "phases/end_fight.h"
#include "phases/end_game.h"

#include "user_interfaces/console_user_interface.h"

#include "hero_factories/barbarian_factory.h"
#include "hero_factories/rogue_factory.h"
#include "hero_factories/warrior_factory.h"

namespace game {

void Bootstrap::InitCore(Core& core) {
  auto allocator = core.GetAllocator();

  core.RegisterHeroFactory(std::allocate_shared<game::hero::BarbarianFactory>(allocator));
  core.RegisterHeroFactory(std::allocate_shared<game::hero::RogueFactory>(allocator));
  core.RegisterHeroFactory(std::allocate_shared<game::hero::WarriorFactory>(allocator));

  core.RegisterPhase(std::allocate_shared<game::phase::StartGame>(allocator));
  core.RegisterPhase(std::allocate_shared<game::phase::SetupHero>(allocator));
  core.RegisterPhase(std::allocate_shared<game::phase::SetupMonster>(allocator));
  core.RegisterPhase(std::allocate_shared<game::phase::StartFight>(allocator));
  core.RegisterPhase(std::allocate_shared<game::phase::Fight>(allocator));
  core.RegisterPhase(std::allocate_shared<game::phase::EndFight>(allocator));
  core.RegisterPhase(std::allocate_shared<game::phase::EndGame>(allocator));
  core.SetUserInterface(std::allocate_shared<game::user_interface::ConsoleUserInterface>(allocator));
}

}  // namespace game