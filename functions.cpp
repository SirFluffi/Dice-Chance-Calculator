#include "header.hpp"
#include <iostream>
#include <random>
#include <chrono>

void dice(int chance, int amount, int instance) {
	int hit = 0, high = 0, tAmount = amount, tInstance = instance;
	std::mt19937 generator(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count())); //mersenne twister engine, seeding with chrono
	std::uniform_int_distribution<int> distribution(1, 100);
	while (amount > 0)
	{
		while (instance > 0)
		{
			int randomNumber = distribution(generator);
			if (randomNumber < chance)
			{
				hit++;
			}
			instance--;
		}
		if (hit > high)
		{
			high = hit;
		}
		if (amount % 10000000 == 0) {
			std::cout << amount << " Attempts remaining..." << std::endl; // so you know the program has not gotten stuck
		}
		instance = tInstance;
		hit = 0;
		amount--;
	}
	std::cout << "\n=== FINAL RESULTS ===\n" << std::endl;
	std::cout << "Attempted Dice Runs: " << tAmount << std::endl;
	std::cout << "Dice throws per Attempt: " << tInstance << std::endl;
	std::cout << "Chance of a hit each throw: " << chance-1 << "%" << std::endl;
	std::cout << "Highest Hit count per Attempt: " << high << std::endl;
}