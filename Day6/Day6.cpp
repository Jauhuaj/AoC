// Day6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <algorithm>
#include <set>

int main()
{
    std::ifstream bruh("DatastreamBuffer.txt");

    char c = bruh.get();
    while (c != EOF) {
        // Do something with the character
        std::cout << c << std::endl;

        // Read the next character
        c = bruh.get();
    }

    std::string FuckIt;
    getline(bruh, FuckIt);

    // hmm a deque of chars
    std::deque<char> Nelj�toista;
    int Vastaus = -1;
    for (int i = 0; i < FuckIt.size(); i++)
    {
        Nelj�toista.push_back(FuckIt[i]);
        if (Nelj�toista.size() < 14) continue;
        if (Nelj�toista.size() > 14) Nelj�toista.pop_front();
        std::set<char> Nelj�toistaSet(Nelj�toista.begin(), Nelj�toista.end());
        if (Nelj�toistaSet.size() == 14)
        {
            Vastaus = i+1;
            for (char c : Nelj�toistaSet)
            {
                std::cout << c;
            }
            break;
        } 
    }
    Vastaus != -1 ? std::cout << Vastaus : std::cout << "vittu";

    return 0;
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
