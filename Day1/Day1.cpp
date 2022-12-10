// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string food;
    int Calories = 0;
    int TopTonttuCalories = 0;
    std::vector<int> Tont;

    std::ifstream Bruh("tontut.txt");
    while (getline(Bruh, food))
    {
        if (!food.empty()) Calories += stoi(food);
        else
        {
            Tont.push_back(Calories);
            Calories = 0;
        }
    }
    std::sort(Tont.begin(), Tont.end(), std::greater<>());
    std::cout << Tont[0]+Tont[1]+Tont[2] << std::endl;
    Bruh.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
