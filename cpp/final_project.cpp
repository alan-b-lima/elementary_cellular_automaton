#include <iostream>

#define ALIVE_CELL " "
#define DEAD_CELL "\u2588"

int main() {

   const int width = 45;
   const int height = (width - 1) / 2;
   bool gens[2][width];

   int rule;

   while (true) {

      for (int i = 0; i < width; i++) {
         gens[0][i] = false;
      }

      gens[0][height] = true;

      std::cout << ">Insert the rule (0 to 255): ";
      std::cin >> rule;
      if (rule < 0) break;

      system("cls");
      std::cout << "Rule " << (rule & 0xff) << '\n';

      for (int x = 0; x < width; x++)
         std::cout << (gens[0][x] ? ALIVE_CELL : DEAD_CELL);
      std::cout << '\n';

      char index = 0;
      char topLayer;

      for (int y = 0; y < height; y++) {

          topLayer = 0;
          if (gens[index][width - 1]) topLayer |= 4;
          if (gens[index][0]) topLayer |= 2;

          for (int x = 0; x < width - 1; x++) {

              if (gens[index][x + 1]) topLayer |= 1;

              gens[index ^ 1][x] = rule & (1 << topLayer);
              std::cout << (gens[index ^ 1][x] ? ALIVE_CELL : DEAD_CELL);

              topLayer &= 0b11;
              topLayer <<= 1;
          }

          if (gens[index][0]) topLayer |= 1;

          index ^= 1;

          gens[index][width - 1] = rule & (1 << topLayer);
          std::cout << (gens[index][width - 1] ? ALIVE_CELL : DEAD_CELL) << '\n';
      }
   }

   return 0;
}
