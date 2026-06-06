#pragma once

#include <game/phase.h>

#include <types/forward_declarations.h>

namespace game::phase {

class Fight : public PhaseBase {
 public:
  static constexpr std::string_view kName = "FightPhase";

  void Run(Core& core) override;
  std::string_view GetName() const override;
};

}  // namespace game::phase
