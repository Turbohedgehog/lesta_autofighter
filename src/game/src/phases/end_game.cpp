#include "end_game.h"

#include <game/core.h>

#include <types/forward_declarations.h>
#include <game/user_interface.h>

namespace game::phase {

void EndGame::Run(Core& core) {
  auto user_interface = core.GetUserInterfaceChecked();
  user_interface.get().Exclaim("Game over", true);
  core.Shutdown();
}

std::string_view EndGame::GetName() const {
  return EndGame::kName;
}

}  // namespace game::phase
