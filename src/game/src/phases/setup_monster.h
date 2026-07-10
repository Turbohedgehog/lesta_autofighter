#pragma once

#include <game/phase.h>

#include <types/forward_declarations.h>

namespace game::phase {

class SetupMonster : public PhaseBase {
 public:
  static constexpr std::string_view kName = "SetupMonsterPhase";

  void Run(Core& core) override;
  std::string_view GetName() const override;
};

}  // namespace game::phase
