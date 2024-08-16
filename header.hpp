#ifndef HEADER_HPP
#define HEADER_HPP
#include <future>
#include <chrono>
#include <iostream>
#include <thread>
#include <random>
#include <algorithm>

void dice(int chance, unsigned int amount, unsigned int instance, std::promise<int> promise);

#endif // !HEADER_HPP
