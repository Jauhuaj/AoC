// Day8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void PrintScenicScore(std::vector<std::vector<int>*> TreeGrid)
{
	// for loop to count the scenic score of every tree
	int HighestScenicScore = 0;
	for (int i = 0; i < TreeGrid.size(); i++) // for loop through every row index i
	{
		for (int j = 0; j < TreeGrid[i]->size(); j++) // for loop through every column index j
		{
			int TreeToCheckSize = TreeGrid[i]->at(j);
			int NorthScore = 0, EastScore = 0, SouthScore = 0, WestScore = 0;

			// Check Tree Count from every cardinal direction
			for (int NorthTreeIndex = i - 1; NorthTreeIndex >= 0; NorthTreeIndex--) // for loop through every OtherTree North of tree
			{
				int OtherTreeSize = TreeGrid[NorthTreeIndex]->at(j);
				NorthScore++;
				if (OtherTreeSize >= TreeToCheckSize) break; // stop if OtherTree is bigger than or equal to TreeHouseTreeSize
			}
			for (int WestTreeIndex = j - 1; WestTreeIndex >= 0; WestTreeIndex--) // for loop through every OtherTree West of tree
			{
				int OtherTreeSize = TreeGrid[i]->at(WestTreeIndex);
				WestScore++;
				if (OtherTreeSize >= TreeToCheckSize) break; // stop if OtherTree is bigger than or equal to TreeHouseTreeSize
			}
			for (int EastTreeIndex = j + 1; EastTreeIndex < TreeGrid[i]->size(); EastTreeIndex++) // for loop through every OtherTree East of tree
			{
				int OtherTreeSize = TreeGrid[i]->at(EastTreeIndex);
				EastScore++;
				if (OtherTreeSize >= TreeToCheckSize) break; // stop if OtherTree is bigger than or equal to TreeHouseTreeSize
			}
			for (int SouthTreeIndex = i + 1; SouthTreeIndex < TreeGrid.size(); SouthTreeIndex++) // for loop through every OtherTree South of tree
			{
				int OtherTreeSize = TreeGrid[SouthTreeIndex]->at(j);
				SouthScore++;
				if (OtherTreeSize >= TreeToCheckSize) break; // stop if OtherTree is bigger than or equal to TreeHouseTreeSize
			}
			int TreeScore = NorthScore * EastScore * WestScore * SouthScore; // total score is counted by multiplying all cardinal directions' tree count
			if (TreeScore > HighestScenicScore) HighestScenicScore = TreeScore;
		}
	}
	std::cout << std::endl << std::endl;
	std::cout << HighestScenicScore;
}

void PrintVisibleTreeCount(std::vector<std::vector<int>*> TreeGrid)
{
	// for loop to Check visibility of every tree and count the total.
	int VisibleTreeCount = 0;
	for (int i = 0; i < TreeGrid.size(); i++) // for loop through every row index i
	{
		for (int j = 0; j < TreeGrid[i]->size(); j++) // for loop through every column index j
		{
			int TreeToCheckSize = TreeGrid[i]->at(j);
			bool NorthVisible = true, EastVisible = true, SouthVisible = true, WestVisible = true; // initially tree is assumed to be visible. Then 4 for loops check if any are false.

			// Check visibility of tree from every Cardinal direction with 4 for loops.
			for (int NorthTreeIndex = i - 1; NorthTreeIndex >= 0; NorthTreeIndex--) // for loop through every OtherTree North of tree
			{
				int OtherTreeSize = TreeGrid[NorthTreeIndex]->at(j);
				if (OtherTreeSize >= TreeToCheckSize) //if other tree blocks the view to tree
				{
					NorthVisible = false;
					break;
				}
			}
			for (int WestTreeIndex = j - 1; WestTreeIndex >= 0; WestTreeIndex--) // for loop through every OtherTree West of tree
			{
				int OtherTreeSize = TreeGrid[i]->at(WestTreeIndex);
				if (OtherTreeSize >= TreeToCheckSize) //if other tree blocks the view to tree
				{
					WestVisible = false;
					break;
				}
			}
			for (int EastTreeIndex = j + 1; EastTreeIndex < TreeGrid[i]->size(); EastTreeIndex++) // for loop through every OtherTree East of tree
			{
				int OtherTreeSize = TreeGrid[i]->at(EastTreeIndex);
				if (OtherTreeSize >= TreeToCheckSize) //if other tree blocks the view to tree
				{
					EastVisible = false;
					break;
				}
			}
			for (int SouthTreeIndex = i + 1; SouthTreeIndex < TreeGrid.size(); SouthTreeIndex++) // for loop through every OtherTree South of tree
			{
				int OtherTreeSize = TreeGrid[SouthTreeIndex]->at(j);
				if (OtherTreeSize >= TreeToCheckSize) //if other tree blocks the view to tree
				{
					SouthVisible = false;
					break;
				}
			}
			if (NorthVisible || WestVisible || EastVisible || SouthVisible)
			{
				VisibleTreeCount++;
				std::cout << 'A';
			}
			else std::cout << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
	std::cout << VisibleTreeCount;
}


int main()
{
	std::vector<std::vector<int>*> TreeGrid; // vector of int* vectors
	// code to populate TreeGrid from Trees.txt
	std::ifstream TreeData("Trees.txt");
	std::string Line;
	while (getline(TreeData, Line))
	{
		TreeGrid.push_back(new std::vector<int>);
		for (char Tree : Line)
		{
			TreeGrid.back()->push_back(std::atoi(&Tree)); // int from char*
		}
	}
	PrintVisibleTreeCount(TreeGrid);
	PrintScenicScore(TreeGrid);

}

