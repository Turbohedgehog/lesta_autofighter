#pragma once

#include <vector>
#include <map>
#include <memory>
#include <memory_resource>
#include <random>
#include <optional>
#include <functional>

#include <types/forward_declarations.h>
#include <game/fight.h>

namespace game {

class Core {
 public:
  Core(std::optional<int> random_seed = std::nullopt);

  int Run();

  bool RegisterPhase(PhasePtr phase);
  void SetPhase(std::string_view phase_name);
  std::string_view GetCurrentPhaseName() const;

  void Shutdown();
  bool IsPendingShutdown() const;

  void SetUserInterface(UserInterfacePtr user_interface);
  // UserInterfaceWeakPtr GetUserInterface() const;
  std::reference_wrapper<UserInterfaceBase> GetUserInterfaceChecked() const;
  
  bool RegisterHeroFactory(UnitFactoryPtr hero_factory);
  bool RegisterEnemyFactory(UnitFactoryPtr enemy_factory);

  const std::map<std::string_view, UnitFactoryPtr>& GetHeroFactories() const;
  const std::map<std::string_view, UnitFactoryPtr>& GetEnemyFactories() const;

  void SetHero(UnitPtr hero);
  UnitWeakPtr GetHero() const;
  void SetMonster(UnitPtr monster);
  UnitWeakPtr GetMonster() const;

  std::mt19937& GetRandomEngine();

  void SetFight(Fight fight);
  const std::optional<Fight>& GetFight() const;

  std::pmr::polymorphic_allocator<> GetAllocator();

 private:
  std::mt19937 random_engine_;
  bool is_pending_shutdown_ {};
  std::map<std::string_view, PhasePtr> phases_;
  PhaseWeakPtr current_phase_;
  UserInterfacePtr user_interface_;
  std::map<std::string_view, UnitFactoryPtr> hero_factories_;
  std::map<std::string_view, UnitFactoryPtr> enemy_factories_;

  UnitPtr hero_;
  UnitPtr monster_;
  std::optional<Fight> fight_;

  std::vector<char> buffer_;
  std::pmr::monotonic_buffer_resource arena_;
  std::pmr::unsynchronized_pool_resource pool_;
};

}  // namespace game
