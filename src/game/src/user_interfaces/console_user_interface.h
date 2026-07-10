#pragma once

#include <game/user_interface.h>

#include <string_view>

namespace game::user_interface {

class ConsoleUserInterface : public UserInterfaceBase {
 public:
  std::optional<size_t> Ask(
    std::string_view prompt,
    std::span<const std::string_view> options,
    std::string_view cancel_option = std::string_view()) override;

  void Exclaim(std::string_view sentence, bool wait_enter_key = false) override;
};

}  // namespace game::user_interface
