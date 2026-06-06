#pragma once

#include <game/phase.h>

namespace game::phase {

class StartFight : public PhaseBase {
 public:
  static constexpr std::string_view kName = "StartFightPhase";

  void Run(Core& core) override;
  std::string_view GetName() const override;
};

} // namespace game::phase
