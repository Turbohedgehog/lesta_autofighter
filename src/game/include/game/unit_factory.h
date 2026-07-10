#pragma once

#include <string_view>

#include <types/forward_declarations.h>

namespace game {

class UnitFactoryBase {
 public:
  virtual ~UnitFactoryBase() = default;
  virtual bool CanModifyUnit(const Unit& unit) const = 0;
  virtual void ModifyUnit(Unit& unit, Core& core) const = 0;
  virtual std::string_view GetUnitTypeName() const = 0;

  size_t CalculateAbilityGroupsCount(const Unit& unit) const;
};

}  // namespace game
