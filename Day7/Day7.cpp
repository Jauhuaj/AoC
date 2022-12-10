// Day7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class TonttuDirectory
{
public:
    TonttuDirectory(std::string InName, TonttuDirectory* InLocation = nullptr)
    {
        Name = InName;
        if (InLocation)
        {
            Location = InLocation;
            InLocation->AddContent(this);
        }
    }

    virtual void AddContent(TonttuDirectory* InCont) { Contents.push_back(InCont); Size += InCont->GetSize(); }
    
    std::string GetName() { return Name; }
    std::string GetType() { return Type; }
    virtual int GetSize()
    {
        int TotalSize = 0;
        for (TonttuDirectory* Cont : Contents)
        {
            TotalSize += Cont->GetSize();
        }
        return TotalSize;
    }
    std::vector<TonttuDirectory*> GetContents() { return Contents; }

protected:
    std::string Name = "Unnamed";
    std::string Type = "Dir";
    std::vector<TonttuDirectory*> Contents;
    int Size = 0;
    TonttuDirectory* Location = nullptr;
};

class TonttuFile : public TonttuDirectory
{
public:
    TonttuFile(std::string InName, int InSize, TonttuDirectory* InLocation = nullptr)
        : TonttuDirectory(InName, InLocation) // this be a constructor that also calls the constructor of the parent class.
    {
        Size = InSize;
        Type = "File";
    }
    virtual void AddContent(TonttuDirectory* InCont) override { std::cout << "a file can't be used as a directory" << std::endl; }
    virtual int GetSize() override { return Size; }
};

int main()
{
    std::string NumCheck = "1234567890";

    std::ifstream Stuff("Stuff.txt");
    std::string Line;

    std::vector<TonttuDirectory*> TonttuContent;
    std::vector<TonttuDirectory*> CurrentDir; // use CurrentDir.back() for current directory. should only be filled with already created directories
    while (getline(Stuff, Line))
    {
        if (Line == "$ cd /")
        {
            TonttuContent.push_back(new TonttuDirectory("Root"));
            CurrentDir.push_back(TonttuContent[0]);
            continue;
        }
        if (Line.ends_with("cd .."))
        {
            CurrentDir.pop_back();
            continue;
        }
        if (Line.starts_with("$ ls")) continue;
        std::string Name = Line.substr(Line.find_last_of(' ')+1);
        if (Line.starts_with("$ cd"))
        {
            for (TonttuDirectory* dir : CurrentDir.back()->GetContents())
            {
                if (dir->GetName() == Name && dir->GetType() == "Dir")
                {
                    CurrentDir.push_back(dir);
                    break;
                }
            }
            continue;
        }

        if (Line.starts_with("dir "))
        {
            TonttuContent.push_back(new TonttuDirectory(Name, CurrentDir.back())); // i assume this use of a pointer vector works.
            continue;
        }
        if (NumCheck.find(Line.front()) != -1) // if first character is a number
        {
            int Size = std::stoi(Line);
            TonttuContent.push_back(new TonttuFile(Name, Size, CurrentDir.back()));
        }
    }
    int TonttuDiskSpace = 70000000;
    int UnusedSpace = TonttuDiskSpace - TonttuContent[0]->GetSize();
    int NeededSpace = 30000000;
    int MinSpaceToDelete = NeededSpace - UnusedSpace;
    int DirsUnder10kSize = 0;
    TonttuDirectory* SmallestOverMinSize = TonttuContent[0];
    for (TonttuDirectory* i : TonttuContent)
    {
        
        if (i->GetType() == "Dir" && i->GetSize() >= MinSpaceToDelete)
        {
            if (i->GetSize() < SmallestOverMinSize->GetSize()) SmallestOverMinSize = i;
        }
    }
    std::cout << SmallestOverMinSize->GetName() << ' ' << SmallestOverMinSize->GetSize();
}

