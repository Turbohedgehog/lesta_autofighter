#include "start_fight.h"

#include <stdexcept>

#include <game/core.h>
#include <game/unit.h>
#include <game/fight.h>
#include <game/user_interface.h>
#include <configs/hero_configs.h>

#include "fight.h"

namespace game::phase {

void StartFight::Run(Core& core) {
  auto hero_ptr = core.GetHero();
  if (hero_ptr.expired()) {
    throw std::runtime_error("StartFight: hero is not set");
  }

  auto monster_ptr = core.GetMonster();
  if (monster_ptr.expired()) {
    throw std::runtime_error("StartFight: monster is not set");
  }

  game::Fight fight;
  if (core.GetFight().has_value()) {
    fight = *core.GetFight();
    ++fight.round;
    fight.turn = 0;
  }

  std::tie(fight.attacker, fight.defender) = hero_ptr.lock()->GetStamina() >= monster_ptr.lock()->GetStamina()
    ? std::make_tuple(hero_ptr, monster_ptr)
    : std::make_tuple(monster_ptr, hero_ptr);
  core.SetFight(fight);

  auto user_interface = core.GetUserInterfaceChecked();
  user_interface.get().Exclaim("\nRound begins in... 3... 2... 1...");
  user_interface.get().Exclaim("Fight!\n");

  core.SetPhase(Fight::kName);
}

std::string_view StartFight::GetName() const {
  return StartFight::kName;
}

} // namespace game::phase
