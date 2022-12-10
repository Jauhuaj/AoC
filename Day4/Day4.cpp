// Day4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream Sections("Sections.txt");
    std::string Pair;
    int VituiksMeniCount = 0;
    while (getline(Sections, Pair))
    {
        // x-x, x-x. substrings around ","
        std::string Tonttu1Section = Pair.substr(0, Pair.find(','));
        std::string Tonttu2Section = Pair.substr(Pair.find(',')+1);
        // then substrings around "-", and convert to int
        int Tonttu1Start = stoi(Tonttu1Section.substr(0, Tonttu1Section.find('-')));
        int Tonttu1End = stoi(Tonttu1Section.substr(Tonttu1Section.find('-')+1));
        int Tonttu2Start = stoi(Tonttu2Section.substr(0, Tonttu2Section.find('-')));
        int Tonttu2End = stoi(Tonttu2Section.substr(Tonttu2Section.find('-')+1));

        // if Section 1 fully contains Section 2 or vice versa. Or if they overlap at all
        if (Tonttu1Start >= Tonttu2Start && Tonttu1End <= Tonttu2End || Tonttu1Start <= Tonttu2Start && Tonttu1End >= Tonttu2End)
        {
            VituiksMeniCount++;
        } else if (Tonttu1Start <= Tonttu2Start && Tonttu1End >= Tonttu2Start || Tonttu2Start <= Tonttu1Start && Tonttu2End >= Tonttu1Start) VituiksMeniCount++;
      

        std::cout << Tonttu1Start << std::endl;
        std::cout << Tonttu1End << std::endl;
        std::cout << Tonttu2Start << std::endl;
        std::cout << Tonttu2End << std::endl;
        std::cout << VituiksMeniCount << std::endl << std::endl;
        
    }
    std::cout << VituiksMeniCount << std::endl;
}

