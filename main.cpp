#include "header.hpp"
#include <chrono>
#include <iostream>

int main() {
    int ch, amount; /*Set any values you wish ch is chance in % so 100 == 100 %, amount is Dice throws.
    Saving on computing time by adding 1 to chance to reduce comparrison operations by 1 on each iteration*/
    std::cout << "There is no error handleing, so please only use valid numbers :3" << std::endl;
    std::cout << "Enter a chance (0 - 99): ";
    std::cin >> ch;
    std::cout << "Now Enter the amount of dice to be thrown (0 - 4294967294)" << std::endl;
    std::cin >> amount;
    std::cout << "Lets start rolling dice :3" << std::endl;
    int rch = ch + 1;
    auto start = std::chrono::high_resolution_clock::now(); //start timer
    dice(rch, amount);
    auto end = std::chrono::high_resolution_clock::now(); //end timer
    std::chrono::duration<double> duration = end - start; //time wasted ;3
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl; // hurray :D
    std::cout << "Press Enter to exit..."; 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // otherwise the one below doesnt work
    std::cin.get(); //so you can actually see the results without the cl closing imidiately
    return 0;
}