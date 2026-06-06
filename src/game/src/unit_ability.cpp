#include <game/unit_ability.h>

#include <format>

#include <game/core.h>
#include <game/user_interface.h>
#include <game/unit_config.h>

namespace game {

void UnitAbilityBase::ModifyUnitConfig(UnitConfig& config, Core& core) const {
  auto user_interface = core.GetUserInterfaceChecked();

  user_interface.get().Exclaim(std::format("Unit '{}' achieved ability '{}'", config.name, GetName()));
}

}  // namespace game
