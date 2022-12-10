// Day5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    // open file
    std::ifstream BoxStacks("BoxStacks.txt");
    std::string Line;

    std::string LettersUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    std::vector<std::vector<char>> CharStacks(9);
    std::vector<char> CrateMover9001;

    while (getline(BoxStacks, Line))
    {
    // code to parse and process initial stacks. SHOULD WORK
        if (Line.size() > 0 && Line.front() != 'm') // check if line has boxes
        {
            for (int i = 0; i < Line.size(); i++) // loop through the line
            {
                if (LettersUpper.find(Line[i]) != std::string::npos) // Check if char is an upper case letter.
                {
                    // add c to front of the correct char stack. stack positions: 1, 5, 9, n+4
                    int StackPos = (i - 1) / 4;
                    CharStacks[StackPos].insert(CharStacks[StackPos].begin(), Line[i]);
                }
            }
        }
        // code to parse and process crane instructions. SHOULD WORK
            // find "move", "from" and "to". then +5, +5 and +3 to pos for substr. then stoi.
        if (Line.size() > 0 && Line.front() == 'm')
        {
            int MoveCount = stoi(Line.substr(Line.find("move") + 5));
            int FromStack = stoi(Line.substr(Line.find("from") + 5)) - 1;
            int ToStack = stoi(Line.substr(Line.find("to") + 3)) - 1;
            std::cout << MoveCount << ' ' << FromStack << ' ' << ToStack << std::endl;

            
          
            // crane moves MoveCount boxes from FromStack to ToStack. PLEASE WORK
                //insert MoveCount items from the back of FromStack to CraneMover9001
            CrateMover9001.insert(CrateMover9001.begin(), CharStacks[FromStack].end() - MoveCount, CharStacks[FromStack].end());
                //erase MoveCount items from back of FromStack.
            CharStacks[FromStack].erase(CharStacks[FromStack].end() - MoveCount, CharStacks[FromStack].end());
                //insert crane contents to end of ToStack
            CharStacks[ToStack].insert(CharStacks[ToStack].end(), CrateMover9001.begin(), CrateMover9001.end());
                // clear crane
            CrateMover9001.clear();
            
        }
    }
    // read top boxes. PLEASE WORK
    for (std::vector<char> Stack : CharStacks)
    {
        std::cout << Stack.back();
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
