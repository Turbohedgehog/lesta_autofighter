#pragma once

#include <optional>
#include <span>
#include <string_view>

namespace game {

class UserInterfaceBase {
 public:
  virtual ~UserInterfaceBase() = default;

  virtual std::optional<size_t> Ask(
    std::string_view prompt,
    std::span<const std::string_view> options,
    std::string_view cancel_option = std::string_view()) = 0;

  virtual void Exclaim(std::string_view sentence, bool wait_enter_key = false) = 0;
};

}  // namespace game