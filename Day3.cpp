#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void day3()
{
	const int SIZEOFARRAY = 800;
	//Part1 Variables
	std::ifstream file("Day3.txt");
	std::string line;
	std::string mul = "mul(";
	int position [SIZEOFARRAY], sumPart1 = 0;
	
	//Part2 Variables
	std::string noMultiply = "don't()";
	std::string multiply = "do()";
	int positionMul[SIZEOFARRAY], positionNoMul[SIZEOFARRAY], sumPart2 = 0;

	//Part1
	while (std::getline(file, line))
	{
		std::size_t length = line.length();
		std::size_t found = line.find(mul);
		int index = 0, first = 0;
		std::fill(position, position + SIZEOFARRAY, -1);
		
		for (int i = 0;i < (length);i++)
		{
			std::size_t foundMul = line.find(mul, i);
			if (foundMul != std::string::npos && foundMul<=length)
			{
				if (first == 0)
				{
					position[index] = foundMul;
					first++;
				}
				else if (foundMul != position[index])
				{
					index++;
					position[index] = foundMul;
				}
			}
			std::size_t foundNoMultiply = line.find(noMultiply, i);
			std::size_t foundMultiply = line.find(multiply, i);
		}

		for (int i = 0;i <= index;i++)
		{
			int tempNum1= 0, tempNum2 = 0, isComma = 0;
			std::string combineNumber = "";
			std::size_t posComma = line.find(',', position[i]);
			std::size_t posPar = line.find(')', position[i]);

			for (int j = 4;j <= 11;j++)
			{
				if (std::isxdigit(line[position[i] + j]))
				{
					combineNumber += line[position[i] + j];
				}
				else if (line[position[i] + j] == ',')
				{
					tempNum1 = std::stoi(combineNumber);
					isComma = 1;
					combineNumber.clear();
				}
				else if (line[position[i] + j] == ')' && isComma == 1)
				{
					tempNum2 = std::stoi(combineNumber);
					sumPart1 += (tempNum1 * tempNum2);
					break;
				}
			}
		}

		//Part2
		std::fill(positionNoMul, positionNoMul + SIZEOFARRAY, -1);
		std::fill(positionMul, positionMul + SIZEOFARRAY, -1);
		int index1 = 0, index2 = 0;
		int tempPosNoMul = 0, tempPosMul = 0;
		bool go = true;

		for (int i = 0;i < length;i++)
		{
			std::size_t foundNoMultiply = line.find(noMultiply, i);
			if (foundNoMultiply != std::string::npos && foundNoMultiply <= length)
			{
				if (first == 1)
				{
					positionNoMul[index1] = foundNoMultiply;
					first++;
				}
				else if (foundNoMultiply != positionNoMul[index1])
				{
					index1++;
					positionNoMul[index1] = foundNoMultiply;
				}
			}
			

			std::size_t foundMultiply = line.find(multiply, i);
			if (foundMultiply != std::string::npos && foundMultiply <= length)
			{
				if (first == 2)
				{
					positionMul[index2] = foundMultiply;
					first++;
				}
				else if (foundMultiply != positionMul[index2])
				{
					index2++;
					positionMul[index2] = foundMultiply;
				}
			}
		}


		for (int i = 0;i <= index;i++)
		{
			int tempNum1 = 0, tempNum2 = 0, isComma = 0;
			std::string combineNumber = "";
			std::size_t posComma = line.find(',', position[i]);
			std::size_t posPar = line.find(')', position[i]);



			if (position[i] > positionNoMul[tempPosNoMul] && positionNoMul[tempPosNoMul] != -1)
			{
				go = false;
				tempPosNoMul++;
			}
			else if (position[i] > positionMul[tempPosMul] && positionMul[tempPosMul] != -1)
			{
				go = true;
				tempPosMul++;
			}

			if (go)
			{
				for (int j = 4;j <= 11;j++)
				{
					if (std::isxdigit(line[position[i] + j]))
					{
						combineNumber += line[position[i] + j];
					}
					else if (line[position[i] + j] == ',')
					{
						tempNum1 = std::stoi(combineNumber);
						isComma = 1;
						combineNumber.clear();
					}
					else if (line[position[i] + j] == ')' && isComma == 1)
					{
						tempNum2 = std::stoi(combineNumber);
						sumPart2 += (tempNum1 * tempNum2);
						break;
					}
				}
			}
		}
	}
	std::cout << "sumPart1: " << sumPart1 << std::endl;
	std::cout << "sumPart2: " << sumPart2 << std::endl;
}