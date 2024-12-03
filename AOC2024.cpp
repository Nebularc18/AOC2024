#include <iostream>
#include "Days.h"
#include <vector>
#include <chrono>


int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	int whatDay = 3;
	std::vector<void(*)()> days = { day1, day2, day3};
	std::cout << "Advent of Code 2024" << std::endl;
	//day3();
	std::cout << std::endl << std::endl;
	
	for (int i = 1;i <= whatDay;i++)
	{
		std::cout << "Day" << i << std::endl;
		days[i -1]();
		std::cout << std::endl << std::endl;
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
	return 0;
}
