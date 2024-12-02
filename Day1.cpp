#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

void day1()
{
    //PART1
    std::ifstream file("Day1.txt");
    std::string line;

    const int NUMBERLINES = 1000;
    int numArray1[NUMBERLINES], numArray2[NUMBERLINES];
    int n = sizeof(numArray1) / sizeof(numArray1[0]);
    int sum = 0, num3 = 0;

    while (std::getline(file, line))
    {
        std::istringstream stream(line);
        int num1, num2;
        stream >> num1 >> num2;

        numArray1[num3] = num1;
        numArray2[num3] = num2;
        num3++;
    }

    std::sort(numArray1, numArray1 + n);
    std::sort(numArray2, numArray2 + n);

    for (int i = 0;i < NUMBERLINES;i++)
    {
        sum += abs(numArray2[i] - numArray1[i]);
    }
    std::cout << sum << std::endl;

    //PART2
    int sumPart2 = 0;
    for (int i = 0;i < NUMBERLINES;i++)
    {
        int count = 0;
        for (int j = 0;j < NUMBERLINES;j++)
        {
            if (numArray1[i] == numArray2[j])
            {
                count++;
            }
        }
        sumPart2 += numArray1[i] * count;
    }

    std::cout << sumPart2 << std::endl;
}
