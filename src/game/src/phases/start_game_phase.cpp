#include "start_game_phase.h"

#include <game/core.h>
#include <game/unit.h>
#include <configs/hero_configs.h>

#include "setup_hero.h"
namespace game::phase {

void StartGame::Run(Core& core) {
  auto& random_engine = core.GetRandomEngine();
  UnitConfig hero_config = {
    .name = "Hero",
    .strength = std::uniform_int_distribution<decltype(game::config::kHeroConfig.strength)>(1, game::config::kHeroConfig.strength)(random_engine),
    .agility = std::uniform_int_distribution<decltype(game::config::kHeroConfig.agility)>(1, game::config::kHeroConfig.agility)(random_engine),
    .stamina = std::uniform_int_distribution<decltype(game::config::kHeroConfig.stamina)>(1, game::config::kHeroConfig.stamina)(random_engine),
  };

  auto hero = std::allocate_shared<Unit>(core.GetAllocator(), hero_config);
  core.SetHero(hero);

  core.SetPhase(SetupHero::kName);
}

std::string_view StartGame::GetName() const {
  return StartGame::kName;
}

} // namespace game::phase
