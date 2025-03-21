#ifndef HEADER_HPP
#define HEADER_HPP
#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <random>
#include <algorithm>

void dice(int chance, unsigned int amount, unsigned int throws, std::atomic<int>& highest);

#endif // !HEADER_HPP
