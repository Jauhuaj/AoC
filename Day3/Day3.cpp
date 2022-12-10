// Day3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream Kamat("Kamat.txt");
    std::string Reppu;

    std::string PrioVals = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int PrioValTotal = 0;
    /* Puzzle 1
    while (getline(Kamat, Reppu))
    {
        // 2 saman pitusta stringiä yhestä stringistä.
        std::string Etutasku = Reppu.substr(0, Reppu.size() / 2);
        std::string Takatasku = Reppu.substr(Reppu.size() / 2);

        // löydä taskujen yhteinen item ja merkkaa ylös numero
        char item = Etutasku[Etutasku.find_first_of(Takatasku)];
        int value = PrioVals.find(Etutasku[Etutasku.find_first_of(Takatasku)])+1;
        PrioValTotal += value;
        


        std::cout << Reppu << std::endl;
        std::cout << Etutasku << std::endl;
        std::cout << Takatasku << std::endl;
        std::cout << item << value << std::endl;
        std::cout << PrioValTotal << std::endl << std::endl;
    } */
    // Puzzle 2
    std::vector<std::string> Reput;
    int BadgeValTotal = 0;
    while (getline(Kamat, Reppu)) // Kommentoi Puzzle 1 et tää toimii
    {
        // kolme ekaa reppua vectoriin
        Reput.push_back(Reppu);
        if (Reput.size() < 3) continue;
        // löydä 3 repun yhteinen badgeitem
        char BadgeItem;
        for (char c : Reput.at(0))
        {
            if (Reput[1].find(c) != -1)
            {
                if (Reput[2].find(c) != -1)
                {
                    BadgeItem = c;
                    break;
                }
            }
        }
        // lisää löydetyn badgen priority numero yhteissummaan.
        BadgeValTotal += PrioVals.find(BadgeItem) + 1;
        //tyhjennä Reput Vectori, jotta voi käyttää seuraavaa kolmea.
        Reput.clear();

        std::cout << BadgeValTotal << std::endl;
        
    }
    Kamat.close();
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
