#include <game/unit_factory.h>

namespace game::hero {

class WarriorFactory : public UnitFactoryBase {
 public:
  static constexpr std::string_view kUnitTypeName = "Warrior";

  bool CanModifyUnit(const Unit& unit) const override;
  void ModifyUnit(Unit& unit, Core& core) const override;
  std::string_view GetUnitTypeName() const override;
};

}  // namespace game::hero
