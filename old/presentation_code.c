#include <stdbool.h>
#include <stdio.h>

#define ALIVE_CELL " "
#define DEAD_CELL "\u2588"

int mod(int num, int mod) {
	int result = num % mod;
	return result < 0 ? result + mod : result;
}

#define width 45

int main() {
	const int height = (width - 1) / 2;
	bool gens[2][width];

	bool ruleBits[8];
	int rule;

	while (true) {
      
		for (int i = 0; i < width; i++) {
			gens[0][i] = false;
		}

		gens[0][height] = true;

		printf("Insert the rule (0 to 255): ");
		scanf("%d", &rule);

		if (rule < 0 || 255 < rule) break;

		printf("\e[2J\e[1;1H");

		printf("Rule \e[33m%d\e[m\n", rule);

		for (int i = 0; i < 8; i++) {
			ruleBits[i] = rule % 2;
			rule /= 2;
		}

		for (int x = 0; x < width; x++)
			printf(gens[0][x] ? ALIVE_CELL : DEAD_CELL);
      putchar('\n');
      
		char index = 0;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {

				char topLayer = 0;
				if (gens[index][mod(x - 1, width)]) topLayer += 4;
				if (gens[index][mod(x + 1, width)]) topLayer += 1;
				if (gens[index][x]) topLayer += 2;

				gens[index ^ 1][x] = ruleBits[topLayer];
				printf(ruleBits[topLayer] ? ALIVE_CELL : DEAD_CELL);
			}
         
         putchar('\n');
			index ^= 1;
		}
	}

	return 0;
}
