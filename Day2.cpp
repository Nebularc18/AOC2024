#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void day2()
{
	std::ifstream file("Day2.txt");
	std::string line;
	int numbers[10], safeNum1 = 0, safeNum2 = 0;

	while (std::getline(file, line))
	{
		int number = 0, index = 0, tempnum = 0, go = 0;
		std::istringstream stream(line);

		
		while (stream >> number)
		{
			numbers[index++] = number;
		}
		//Part1
		if (numbers[1] > numbers[0])
		{
			for (int i = 0;i < index - 1;i++)
			{				
				if (numbers[i] == numbers[i + 1] - 1 or numbers[i] == numbers[i + 1] - 2 or numbers[i] == numbers[i + 1] - 3)
				{
					tempnum = 1;
				}
				else
				{
					tempnum = 0;
					break;
				}
			}
		}
		else
		{
			for (int i = 0;i < index - 1;i++)
			{
				if (numbers[i] == numbers[i + 1] + 1 or numbers[i] == numbers[i + 1] + 2 or numbers[i] == numbers[i + 1] + 3)
				{
					tempnum = 1;
				}
				else
				{
					tempnum = 0;
					break;
				}
			}
		}
		safeNum1 += tempnum;

		//Part2
		if (numbers[1] > numbers[0] or numbers[2] > numbers[1])
		{
			for (int i = 0;i < index - 1;i++)
			{
				if (numbers[i] == numbers[i + 1] - 1 or numbers[i] == numbers[i + 1] - 2 or numbers[i] == numbers[i + 1] - 3)
				{
					tempnum = 1;
				}
				else if (go == 0)
				{
					go++;
				}
				else
				{
					tempnum = 0;
					break;
				}
			}
		}
		else
		{
			for (int i = 0;i < index - 1;i++)
			{
				if (numbers[i] == numbers[i + 1] + 1 or numbers[i] == numbers[i + 1] + 2 or numbers[i] == numbers[i + 1] + 3)
				{
					tempnum = 1;
				}
				else if (go == 0)
				{
					go++;
				}
				else
				{
					tempnum = 0;
					break;
				}
			}
		}
		safeNum2 += tempnum;
	}
	std::cout << safeNum1 << std::endl;
	std::cout << safeNum2 << std::endl;
}