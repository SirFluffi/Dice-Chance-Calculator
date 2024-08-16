#include "header.hpp"
#include <chrono>
#include <iostream>

int main() {
    int ch = 25, amount = 1000000000,rch = ch + 1; /*Set any values you wish ch is chance in % so 100 == 100 %, amount is Dice throws.
    Saving on computing time by adding 1 to chance to reduce comparrison operations by 1 on each iteration*/
    auto start = std::chrono::high_resolution_clock::now(); //start timer
    dice(rch, amount);
    auto end = std::chrono::high_resolution_clock::now(); //end timer
    std::chrono::duration<double> duration = end - start; //time wasted ;3
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl; // hurray :D
    std::cout << "Press Enter to exit..."; 
    std::cin.get(); //so you can actually see the results without the cl closing imidiately
    return 0;
}