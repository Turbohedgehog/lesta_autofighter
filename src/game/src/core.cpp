#include <game/core.h>

#include <algorithm>
#include <format>
#include <stdexcept>

#include <game/phase.h>
#include <game/unit_factory.h>

namespace game {

Core::Core(std::optional<int> random_seed)
  : buffer_(Core::kBufferSize)
  , arena_(buffer_.data(), buffer_.size())
  , pool_(&arena_) {
  if (random_seed.has_value()) {
    random_engine_ = std::mt19937(random_seed.value());
  } else {
    std::random_device rd;
    random_engine_ = std::mt19937(rd());
  }
}

int Core::Run() {
  while (!IsPendingShutdown()) {
    current_phase_.lock()->Run(*this);
  }

  return 0;
}

bool Core::RegisterPhase(PhasePtr phase) {
  if (!phases_.try_emplace(phase->GetName(), phase).second) {
    return false;
  }

  if (current_phase_.expired()) {
    current_phase_ = phase;
  }

  return true;
}

void Core::SetPhase(std::string_view phase_name) {
  auto it = phases_.find(phase_name);
  if (it == phases_.end()) {
    throw std::runtime_error(std::format("Core: Phase '{}' not found", phase_name));
  }

  current_phase_ = it->second;
}

std::string_view Core::GetCurrentPhaseName() const {
  return current_phase_.expired() ? std::string_view() : current_phase_.lock()->GetName();
}

void Core::Shutdown() {
  is_pending_shutdown_ = true;
}

bool Core::IsPendingShutdown() const {
  return is_pending_shutdown_;
}

void Core::SetUserInterface(UserInterfacePtr user_interface) {
  user_interface_ = user_interface;
}

// UserInterfaceWeakPtr Core::GetUserInterface() const {
//   return user_interface_;
// }

std::reference_wrapper<UserInterfaceBase> Core::GetUserInterfaceChecked() const {
  if (!user_interface_) {
    throw std::runtime_error("Core: User interface not set");
  }

  return std::ref(*user_interface_);
}

bool Core::RegisterHeroFactory(UnitFactoryPtr hero_factory) {
  return hero_factories_.try_emplace(hero_factory->GetUnitTypeName(), hero_factory).second;
}

bool Core::RegisterEnemyFactory(UnitFactoryPtr enemy_factory) {
  return enemy_factories_.try_emplace(enemy_factory->GetUnitTypeName(), enemy_factory).second;
}

const std::map<std::string_view, UnitFactoryPtr>& Core::GetHeroFactories() const {
  return hero_factories_;
}

const std::map<std::string_view, UnitFactoryPtr>& Core::GetEnemyFactories() const {
  return enemy_factories_;
}

void Core::SetHero(UnitPtr hero) {
  hero_ = hero;
}

UnitWeakPtr Core::GetHero() const {
  return hero_;
}

void Core::SetMonster(UnitPtr monster) {
  monster_ = monster;
}

UnitWeakPtr Core::GetMonster() const {
  return monster_;
}

std::mt19937& Core::GetRandomEngine() {
  return random_engine_;
}

void Core::SetFight(Fight fight) {
  fight_ = std::move(fight);
}

const std::optional<Fight>& Core::GetFight() const {
  return fight_;
}

std::pmr::polymorphic_allocator<> Core::GetAllocator() {
  return std::pmr::polymorphic_allocator<>{&pool_};
}

}  // namespace game
