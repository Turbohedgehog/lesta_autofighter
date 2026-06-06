#include <game/bootstrap.h>

int main() {
  game::Core core;
  game::Bootstrap::InitCore(core);

  return core.Run();
}