#include "header.hpp"


int main() {
	unsigned int ch, attempts, amount, threadCount = 4;
	std::atomic<int> highscore = 0;
	std::cout << "There is no error handleing, so please only use valid numbers :3" << std::endl;
	std::cout << "Enter the Chance to hit (0<x<100)";
	std::cin >> ch;
	ch++; // to cut down repeated comparisons
	std::cout << "Amount of dice thrown per Attempt (1 - 4294967294)" << std::endl;
	std::cin >> amount;
	std::cout << "Attempts performed (1 - 4294967294)" << std::endl;
	std::cin >> attempts;
	std::cout << "Lets start rolling dice :3\nThis may take a while - and no its not frozen" << std::endl;
	int thAttempts = attempts / threadCount;
	auto start = std::chrono::high_resolution_clock::now(); //start timer
	std::thread t1(dice, ch, thAttempts, amount, highscore);
	std::thread t2(dice, ch, thAttempts, amount, highscore);
	std::thread t3(dice, ch, thAttempts, amount, highscore);
	std::thread t4(dice, ch, thAttempts, amount, highscore);
	if (t1.joinable()&& t2.joinable()&& t3.joinable()&& t4.joinable()) {
		t1.join();
		t2.join();
		t3.join();
		t4.join();
	} else {
		std::cout << "Could not join Threads";
		return 1;
	}
	
	auto end = std::chrono::high_resolution_clock::now(); //end timer
	std::cout << "\n=== FINAL RESULTS ===\n" << std::endl;
	std::cout << "Threads Used: "<< threadCount << std::endl;
	std::cout << "Attempted Dice Runs: " << attempts << std::endl;
	std::cout << "Dice throws per Attempt: " << amount << std::endl;
	std::cout << "Chance of a hit each throw: " << ch << "%" << std::endl;
	std::cout << "Highest Hit count per Attempt: " << highscore.load() << std::endl;
	
	std::chrono::duration<double> duration = end - start; //time wasted ;3
	std::cout << "Time taken: " << duration.count() << " seconds" << std::endl; // hurray :D
	std::cout << "Press Enter to exit...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear cin
	std::cin.get(); //so you can actually see the results without the cl closing imidiately
	return 0;
