#pragma once

#include <string_view>

#include <types/forward_declarations.h>

namespace game {

class UnitAbilityBase {
 public:
  virtual ~UnitAbilityBase() = default;
  virtual void OnAttack(Damage& damage, Core& core) const {};
  virtual void OnDefend(Damage& damage, Core& core) const {};
  virtual void OnDeath(Damage& damage, Core& core) const {};
  virtual void ModifyUnitConfig(UnitConfig& config, Core& core) const;
  virtual std::string_view GetName() const = 0;
  virtual std::string_view GetGroupName() const {
    return {};
  }
};

}  // namespace game
