#include <iostream>
#include "Days.h"
#include <vector>


int main()
{
	int whatDay = 2;
	std::vector<void(*)()> days = { day1, day2};
	std::cout << "Advent of Code 2024" << std::endl;
	//std::cout << "Day1" << std::endl;
	//day1();
	std::cout << std::endl << std::endl;
	
	for (int i = 1;i <= whatDay;i++)
	{
		std::cout << "Day" << i << std::endl;
		days[i -1]();
		std::cout << std::endl << std::endl;
	}

	return 0;
}
