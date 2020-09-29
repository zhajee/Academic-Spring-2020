//inputOutput.cpp
#include "inputOutput.hpp"
#include <string>
#include <sstream>
#include <iostream>

namespace{
    int countWords(std::string line)
    {
        std::istringstream in{line};
        std::string word;
        int count = 0;
        while (in >> word)
        {
            count++;
        }
        return count;
    }
}

inputOutput::inputOutput()
    : hm1{HashMap()}
    //, invalid{false}
{
}
void inputOutput::printInvalid()
{
    std::cout << "INVALID" << std::endl;
}

std::string inputOutput::getInput()
{
    std::string s;
    std::getline(std::cin, s);
    return s;
}

std::string inputOutput::getCmdWord(std::string s)
{
    std::istringstream in{s};
    std::string command;
    in >> command;
    return command;
}

std::string inputOutput::getFirstWord(std::string s)
{
    std::istringstream in{s};
    std::string command;
    std::string firstWord;
    in >> command;
    in >> firstWord;
    return firstWord;
}
std::string inputOutput::getSecondWord(std::string s)
{
    std::istringstream in{s};
    std::string command;
    std::string firstWord;
    std::string secondWord;
    in >> command;
    in >> firstWord;
    in >> secondWord;
    return secondWord;
}

void inputOutput::executeCmd(std::string s, Command &c, HashMap& hm1)
{
    //checks if command matches word count requirement, then
    //calls function to update HashMap object
    std::string command;
    std::string firstWord;
    std::string secondWord;

    std::istringstream in{s};

    in >> command;
    if (command == "CREATE")
        {
            //check word count, must equal three or else invalid.
            if (countWords(s) != 3)
            {
                printInvalid();
            }
            else
            {
                c.create(hm1);
            }
            
        }
        else if (command == "LOGIN")
        {
            if (countWords(s) == 3)
            {
                c.login(hm1);   
            }
            else if (countWords(s) == 2)
            {
                c.logincount(hm1);
            }
            else 
            {
                printInvalid();
            }
        }
        else if (command == "REMOVE")
        {
            if (countWords(s) != 2)
            {
                printInvalid();
            }
            else
            {
                c.remove(hm1);
            }

        }
        else if (command == "CLEAR")
        {
            if (countWords(s) != 1)
            {
                printInvalid();
            }   
            else
            {
                c.clear(hm1);
            } 
        }
        else if (command == "DEBUG")
        {
            if (countWords(s) != 2)
            {
                printInvalid();
            }   
            else
            {
                c.debug();
            } 
        }
        else if (command == "BUCKET")
        {
            if (countWords(s) != 2)
            {
                printInvalid();
            } 
            else
            {
                c.bucketc(hm1);
            }
              
        }
        else if (command == "LOAD")
        {
            if (countWords(s) != 2)
            {
                printInvalid();
            }
            else
            {
                c.loadFac(hm1);
            }
        }
        else if (command == "MAX")
        {
            if (countWords(s) != 3)
            {
                printInvalid();
            }
            else
            {
                c.maxBuckSz(hm1);
            }
        }
        else
        {
            if (command != "QUIT")
            {
                printInvalid();
            }

        }

}

