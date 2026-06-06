#include "fight.h"

#include <stdexcept>
#include <format>

#include <game/core.h>
#include <game/fight.h>
#include <game/unit.h>

#include <types/forward_declarations.h>
#include <game/user_interface.h>

#include "end_fight.h"

namespace game::phase {

void Fight::Run(Core& core) {
  if (!core.GetFight().has_value()) {
    throw std::runtime_error("Fight: fight is not presented!");
  }

  auto fight = *core.GetFight();
  if (fight.attacker.expired() || fight.defender.expired()) {
    throw std::runtime_error("Fight: attacker or defender is not presented!");
  }

  auto user_interface = core.GetUserInterfaceChecked();

  while (true) {
    auto attacker = fight.attacker.lock();
    auto defender = fight.defender.lock();

    auto attacker_stat_str = attacker->Stats();
    auto defender_stat_str = defender->Stats();
    user_interface.get().Exclaim(
      std::format(
        "{:><50}\n"
        "Attacker:\n{}\n"
        "Defender:\n{}\n",
        "",
        attacker_stat_str,
        defender_stat_str
      )
    );
    auto damage = attacker->AttackTo(defender, core);

    // user_interface.Exclaim(
    //   std::format(
    //     "{:><50}\n"
    //     "{}\n"
    //     "{} attacks {} with damage {}\n\n"
    //     "{}\n"
    //     "{} defends with protection {}\n"
    //     "{:<<50}\n",
    //     "",
    //     attacker_stat_str,
    //     attacker->GetConfig().name,
    //     defender->GetConfig().name,
    //     (damage.weapon_damage + damage.ability_damage),
    //     defender_stat_str,
    //     defender->GetConfig().name,
    //     damage.ability_defense,
    //     ""
    //   )
    // );

    if (fight.defender.lock()->IsDead()) {
      break;
    }

    std::swap(fight.attacker, fight.defender);
    core.SetFight(fight);
  }

  core.SetPhase(EndFight::kName);
}

std::string_view Fight::GetName() const {
  return Fight::kName;
}

}  // namespace game::phase
