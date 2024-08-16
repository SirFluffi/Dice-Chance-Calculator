#include "header.hpp"


int main() {
	int ch, attempts, amount, threadCount = 4;
	std::promise<int> promise1;
	std::future<int> future1 = promise1.get_future();
	std::promise<int> promise2;
	std::future<int> future2 = promise2.get_future();
	std::promise<int> promise3;
	std::future<int> future3 = promise3.get_future();
	std::promise<int> promise4;
	std::future<int> future4 = promise4.get_future();
	std::cout << "There is no error handleing, so please only use valid numbers :3" << std::endl;
	std::cout << "Enter the Chance to hit (0-99)";
	std::cin >> ch;
	std::cout << "Amount of dice thrown per Attempt (0 - 4294967294)" << std::endl;
	std::cin >> amount;
	std::cout << "Attempts performed (0 - 4294967294)" << std::endl;
	std::cin >> attempts;
	std::cout << "Lets start rolling dice :3" << std::endl;
	int rch = ch + 1; // to cut down repeated computations
	int thAttempts = attempts / threadCount;
	auto start = std::chrono::high_resolution_clock::now(); //start timer
	std::thread t1(dice, rch, thAttempts, amount, std::move(promise1));
	std::thread t2(dice, rch, thAttempts, amount, std::move(promise2));
	std::thread t3(dice, rch, thAttempts, amount, std::move(promise3));
	std::thread t4(dice, rch, thAttempts, amount, std::move(promise4));
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	int result1 = future1.get();
	int result2 = future2.get();
	int result3 = future3.get();
	int result4 = future4.get();
	int max = std::max({ result1, result2, result3, result4});
	std::cout << "\n=== FINAL RESULTS ===\n" << std::endl;
	std::cout << "Threads Used: "<< threadCount << std::endl;
	std::cout << "Attempted Dice Runs: " << attempts << std::endl;
	std::cout << "Dice throws per Attempt: " << amount << std::endl;
	std::cout << "Chance of a hit each throw: " << ch << "%" << std::endl;
	std::cout << "Highest Hit count per Attempt: " << max << std::endl;
	auto end = std::chrono::high_resolution_clock::now(); //end timer
	std::chrono::duration<double> duration = end - start; //time wasted ;3
	std::cout << "Time taken: " << duration.count() << " seconds" << std::endl; // hurray :D
	std::cout << "Press Enter to exit...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // otherwise the one below doesnt work
	std::cin.get(); //so you can actually see the results without the cl closing imidiately
	return 0;
}
