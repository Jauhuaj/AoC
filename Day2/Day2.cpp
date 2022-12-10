// Day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

int main()
{
    /* strat 1
    X=1 + A3 / B0 / C6
    Y=2 + A6 / B3 / C0
    Z=3 + A0 / B6 / C3
    */
    /* strat 2
    X=Lose + A-3 / B-1 / C-2
    Y=Draw3 + A-A1 / B-B2 / C-C3
    Z=Win + A-8 / B-9 / C-7
    */
    std::map<std::string, int> KPSResult1{ {"A X",4},{"A Y", 8}, {"A Z", 3}, {"B X" , 1}, {"B Y" , 5}, {"B Z" , 9}, {"C X" , 7}, {"C Y" , 2}, {"C Z" , 6} };
    std::map<std::string, int> KPSResult2{ {"A X",3},{"A Y", 4}, {"A Z",8}, {"B X" ,1}, {"B Y" , 5}, {"B Z" ,9}, {"C X" ,2}, {"C Y" , 6}, {"C Z" ,7} };
    std::string Round;
    int Result(0);
    std::ifstream Strat("StrategyGuide.txt");
    while (getline(Strat, Round))
    {
        Result += KPSResult2[Round];
        std::cout << Result << std::endl;
    }
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
