#include <game/unit_factory.h>

namespace game::hero {

class BarbarianFactory : public UnitFactoryBase {
 public:
  static constexpr std::string_view kUnitTypeName = "Barbarian";

  void ModifyUnit(Unit& unit, Core& core) const override;
  std::string_view GetUnitTypeName() const override;
  bool CanModifyUnit(const Unit& unit) const override;
};

}  // namespace game::hero
