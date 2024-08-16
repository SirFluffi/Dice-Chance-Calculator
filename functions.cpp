#include "header.hpp"
#include <iostream>
#include <random>
#include <chrono>

void dice(int chance, int amount) {
	bool miss = false;
	int hit = 0, high = 0, tAmount = amount;
	std::mt19937 generator(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count())); //mersenne twister engine, seeding with chrono
	std::uniform_int_distribution<int> distribution(1, 100);
	while (0 < amount)
	{
		while (miss == false)
		{
			int randomNumber = distribution(generator);
			if (chance > randomNumber) { // if we hit the chance or not, here you can see why chance + 1, because now we can skip the = part and just do > instead of 2 operations >=
				hit++;
			} else {
				if (hit > high) {
					high = hit; //new high score
				}
				hit = 0;
				miss = true;
			}
		}
		amount--;
		if (amount % 10000000 == 0)
		{
			std::cout << amount << " Attempts Remaining" << std::endl; // to let you know that the program didnt get hung up x3
		}
		miss = false;
	}
	system("cls"); //fancy shmancy expensive syscall to clear up the console for the results, speed is important but so is presentation ^^
	std::cout << "Amount of attempts for consecutive hits: " << tAmount << std::endl; // how many attempts were made to get a new high score
	std::cout << "Chance: " << chance - 1 << "%" << std::endl; //chance to hit the wanted face, die face, not an actual face
	std::cout << "Most consecutive Hits: " << high << std::endl; // amount of 1 throws on a once sided die with current chances in a row
}