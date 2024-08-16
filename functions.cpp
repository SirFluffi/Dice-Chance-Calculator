#include "header.hpp"

void dice(int chance, unsigned int amount, unsigned int instance, std::promise<int> promise) {
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
	promise.set_value(high);
}
