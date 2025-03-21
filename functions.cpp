#include "header.hpp"

void dice(int chance, unsigned int amount, unsigned int throws, std::atomic<int>& highest) {
	int hit = 0, high = 0, tAmount = 0, tThrows = 0;
	std::mt19937 generator(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count())); //mersenne twister engine, seeding with chrono
	std::uniform_int_distribution<int> distribution(1, 100);
	while (amount > tAmount) {
		hit = 0;
		while (throws > tThrows) {
			if (distribution(generator) < chance) {
				hit++;
			}
			tThrows++;
		}
		tThrows = 0;
		if (hit > high)	{
			high = hit;
		}
		tAmount++;
	}
	highest.store(high);
}

