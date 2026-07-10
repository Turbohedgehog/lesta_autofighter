#include <game/unit.h>

#include <format>
#include <iterator>

#include <game/core.h>
#include <game/unit_ability.h>
#include <game/user_interface.h>

namespace game {

Unit::Unit(UnitConfig config)
    : strength_(config.strength)
    , stamina_(config.stamina)
    , agility_(config.agility)
    , health_(config.health)
    , config_(std::move(config)) {}

int Unit::GetStrength() const {
  return strength_;
}

int Unit::GetAgility() const {
  return agility_;
}

int Unit::GetStamina() const {
  return config_.stamina;
}

int Unit::GetHealth() const {
  return health_;
}

bool Unit::IsDead() const {
  return health_ <= 0;
}

void Unit::SetWeapon(Weapon weapon, Core& core) {
  weapon_ = std::move(weapon);
}

const std::optional<Weapon>& Unit::GetWeapon() const {
  return weapon_;
}

void Unit::AppendAbility(UnitAbilityPtr ability, Core& core) {
  ability->ModifyUnitConfig(config_, core);
  abilities_.push_back(std::move(ability));
}

const std::vector<UnitAbilityPtr>& Unit::GetAbilities() const {
  return abilities_;
}

Damage Unit::AttackTo(UnitWeakPtr other, Core& core) {
  if (other.expired()) {
    return {};
  }

  auto weapon_damage = config_.default_damage;

  if (weapon_) {
    weapon_damage += weapon_->GetConfig().damage_amount;
  }

  auto damage = Damage {
    .dealer = shared_from_this(),
    .receiver = other,
    .weapon_damage = weapon_damage,
  };

  for (const auto& ability : abilities_) {
    ability->OnAttack(damage, core);
  }

  other.lock()->Defend(damage, core);

  return damage;
}

void Unit::Defend(Damage& damage, Core& core) {
  for (const auto& ability : abilities_) {
    ability->OnDefend(damage, core);
  }


  auto user_interface = core.GetUserInterfaceChecked();

  auto damage_value = static_cast<int>(damage.weapon_damage + damage.ability_damage);
  auto defense_value = static_cast<int>(damage.ability_defense);

  const auto& attacker = *damage.dealer.lock();

  user_interface.get().Exclaim(std::format("{} attacks {} with damage {}", attacker.GetConfig().name, GetConfig().name, damage_value));
  user_interface.get().Exclaim(std::format("{} defends with protection {}", GetConfig().name, defense_value));

  health_ -= (damage_value - defense_value);
  user_interface.get().Exclaim(std::format("{} health is {}", GetConfig().name, health_));

  if (IsDead()) {
    user_interface.get().Exclaim(std::format("{} is dead", GetConfig().name));
    for (const auto& ability : abilities_) {
      ability->OnDeath(damage, core);
    }
  }
}

std::string Unit::Stats() const {
  std::string abilities_str = "Abilities: None";
  if (!abilities_.empty()) {
    abilities_str.clear();
    auto abilities_it = abilities_.begin();
    std::format_to(std::back_inserter(abilities_str), "Abilities:\n - {}\n", (*abilities_it)->GetName());
    for (++abilities_it; abilities_it != abilities_.end(); ++abilities_it) {
      std::format_to(std::back_inserter(abilities_str), " - {}\n", (*abilities_it)->GetName());
    }
  }

  std::string weapon_str;
  if (weapon_) {
    weapon_str = std::format("Weapon: {} (damage: {})\n", weapon_->GetConfig().name, weapon_->GetConfig().damage_amount);
  }
  
  return std::format(
    "Name: {}\n"
    "Strength: {}\n"
    "Agility: {}\n"
    "Stamina: {}\n"
    "Health: {}\n"
    "{}"
    "{}\n",
    config_.name,
    GetStrength(),
    GetAgility(),
    GetStamina(),
    GetHealth(),
    weapon_str,
    abilities_str);
}

const UnitConfig& Unit::GetConfig() const {
  return config_;
}

void Unit::ResetStatsToConfig() {
  strength_ = config_.strength;
  agility_ = config_.agility;
  stamina_ = config_.stamina;
  health_ = config_.health + config_.stamina;
}

}  // namespace game