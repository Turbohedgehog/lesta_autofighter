#include <exception>
#include <iostream>

#include <game/bootstrap.h>

int main() {
  try {
    game::Core core;
    game::Bootstrap::InitCore(core);

    return core.Run();
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}