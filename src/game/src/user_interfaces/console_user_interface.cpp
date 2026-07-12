#include "console_user_interface.h"

#include <iostream>
#include <limits>

namespace game::user_interface {

std::optional<size_t> ConsoleUserInterface::Ask(
  std::string_view prompt,
    std::span<const std::string_view> options,
    std::string_view cancel_option) {
  while (true) {
    std::cout << prompt << "\n";
    for (size_t i = 0; i < options.size(); ++i) {
      std::cout << (i + 1) << ": " << options[i] << "\n";
    }

    if (!cancel_option.empty()) {
      std::cout << "\n0: " << cancel_option << "\n";
    }

    std::flush(std::cout);

    size_t choice;
    std::cin >> choice;

    if (choice == 0) {
      break;
    }

    if (choice <= options.size()) {
      return choice - 1;
    }
  }

  return std::nullopt;
}

void ConsoleUserInterface::Exclaim(std::string_view sentence, bool wait_enter_key) {
  std::cout << sentence << std::endl;

  if (wait_enter_key) {
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
  }
}

}  // namespace game