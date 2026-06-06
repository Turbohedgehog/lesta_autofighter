#pragma once

#include <memory>
#include <string>

namespace game {

class Core;
class Bootstrap;

class PhaseBase;

using PhasePtr = std::shared_ptr<PhaseBase>;
using PhaseWeakPtr = std::weak_ptr<PhaseBase>;

class UserInterfaceBase;
using UserInterfacePtr = std::shared_ptr<UserInterfaceBase>;
using UserInterfaceWeakPtr = std::weak_ptr<UserInterfaceBase>;

class Unit;
using UnitPtr = std::shared_ptr<Unit>;
using UnitWeakPtr = std::weak_ptr<Unit>;

class UnitFactoryBase;
using UnitFactoryPtr = std::shared_ptr<UnitFactoryBase>;
using UnitFactoryWeakPtr = std::weak_ptr<UnitFactoryBase>;

class WeaponBase;
using WeaponPtr = std::shared_ptr<WeaponBase>;
using WeaponWeakPtr = std::weak_ptr<WeaponBase>;

class UnitAbilityBase;
using UnitAbilityPtr = std::shared_ptr<UnitAbilityBase>;
using UnitAbilityWeakPtr = std::weak_ptr<UnitAbilityBase>;

struct Damage;
struct UnitConfig;

}  // namespace game
