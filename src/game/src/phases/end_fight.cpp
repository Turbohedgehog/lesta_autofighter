#include "end_fight.h"

#include <format>
#include <stdexcept>

#include <game/core.h>
#include <game/unit.h>
#include <game/fight.h>
#include <game/user_interface.h>
#include <configs/fight_configs.h>

#include "setup_hero.h"
#include "end_game.h"

#include "fight.h"

namespace game::phase {

void EndFight::Run(Core& core) {
  auto hero_ptr = core.GetHero();
  if (hero_ptr.expired()) {
    throw std::runtime_error("EndFight: hero is not set");
  }

  auto monster_ptr = core.GetMonster();
  if (monster_ptr.expired()) {
    throw std::runtime_error("EndFight: monster is not set");
  }


  if (!core.GetFight()) {
    throw std::runtime_error("EndFight: fight is not set");
  }

  const auto& monster = *monster_ptr.lock();
  auto user_interface = core.GetUserInterfaceChecked();

  if (!monster.IsDead()) {
    user_interface.get().Exclaim(std::format("Monster {} wins!", monster.GetConfig().name));
    user_interface.get().Exclaim("You lose!");
    core.SetPhase(EndGame::kName);

    return;
  }

  if (!core.GetFight().has_value()) {
    throw std::runtime_error("Fight: fight is not presented!");
  }
  const auto& fight = *core.GetFight();

  user_interface.get().Exclaim("Hero wins!");
  if (fight.round >= config::kFightsCount) {
    core.SetPhase(EndGame::kName);
    return;
  }

  core.SetPhase(SetupHero::kName);
}

std::string_view EndFight::GetName() const {
  return EndFight::kName;
}

} // namespace game::phase
