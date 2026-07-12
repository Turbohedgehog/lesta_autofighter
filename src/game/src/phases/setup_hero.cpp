#include "setup_hero.h"

#include <algorithm>
#include <vector>
#include <iterator>

#include <ranges>
#include <array>
#include <string_view>
#include <vector>
#include <stdexcept>
#include <format>

#include <game/core.h>
#include <game/user_interface.h>
#include <game/unit_factory.h>
#include <game/unit.h>
#include <configs/hero_configs.h>

#include "setup_monster.h"

using namespace std::literals;

namespace game::phase {

void PrintUnitSpec(const Unit& unit, UserInterfaceBase& user_interface) {
  auto unit_spec = std::format(
    "{:=<50}\n"
    "Hero stats:\n"
    "{:.>2}\n"
    "{:=<50}\n",
    "",
    unit.Stats(),
    "");

  user_interface.Exclaim(unit_spec);
}

void SetupHero::Run(Core& core) {
  auto user_interface = core.GetUserInterfaceChecked();

  auto hero_ptr = core.GetHero();
  if (hero_ptr.expired()) {
    throw std::runtime_error("SetupHero: hero is not set");
  }

  auto& hero = *hero_ptr.lock();
  PrintUnitSpec(hero, user_interface.get());

  const auto& hero_factories = core.GetHeroFactories();
  auto allowed_factories = hero_factories
      | std::views::filter([&](const auto& factory) {
        return factory.second->CanModifyUnit(hero);
      })
      | std::views::keys;

  auto allocator = core.GetAllocator();
  std::pmr::vector<std::string_view> hero_types(allowed_factories.begin(), allowed_factories.end(), allocator);

  auto answer = user_interface.get().Ask(
    "Select hero type",
    hero_types
  );

  if (!answer.has_value()) {
    throw std::runtime_error("SetupHero: hero type is not selected");
  }

  auto factory_name = hero_types[*answer];
  hero_factories.find(factory_name)->second->ModifyUnit(hero, core);

  hero.ResetStatsToConfig();

  core.SetPhase(SetupMonster::kName);
}

std::string_view SetupHero::GetName() const {
  return kName;
}

}  // namespace game::phase