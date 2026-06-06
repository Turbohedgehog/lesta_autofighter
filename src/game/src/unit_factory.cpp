#include <game/unit_factory.h>

#include <numeric>

#include <game/unit.h>
#include <game/unit_ability.h>

namespace game {

size_t UnitFactoryBase::CalculateAbilityGroupsCount(const Unit& unit) const {
  const auto& abilities = unit.GetAbilities();
  return std::accumulate(abilities.begin(), abilities.end(), size_t{}, [this](size_t total, const auto& ability) {
    auto group_name = ability->GetGroupName();
    if (group_name.empty()) {
      return total;
    }

    return group_name == GetUnitTypeName() ? ++total : total;
  });
}


}  // namespace game
