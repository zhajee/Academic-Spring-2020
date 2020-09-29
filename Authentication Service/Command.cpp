//Command.cpp
#include "Command.hpp"
#include "HashMap.hpp"
#include <string>
#include <iostream>


Command::Command()
    : firstWord{""}, secondWord{""}, debugMode{false}
{
}

void Command::updateWords(std::string fw, std::string sw)
{
    //stores parsed commands to update HashMap accordingly
    firstWord = fw;
    secondWord = sw;
}

bool Command::exists(std::string key, std::string value, HashMap& hm)
{
    if (hm.contains(key) == true && hm.value(key) == value)
    {
        return true;
    }
    return false;
}

void Command::create(HashMap& hm)
{
    
    if (hm.contains(firstWord) == false)
    {
        
        hm.add(firstWord,secondWord);
        std::cout << "CREATED" << std::endl;
    }
    else
    {
        std::cout << "EXISTS" << std::endl;
    }
}

void Command::login(HashMap& hm)
{
    if (exists(firstWord, secondWord, hm))
    {
        std::cout << "SUCCEEDED" << std::endl;
    }
    else
    {
        std::cout << "FAILED" << std::endl;
    }
    
}

void Command::remove(HashMap &hm)
{
    if (hm.contains(firstWord))
    {
        if (hm.remove(firstWord))
        {
            std::cout << "REMOVED" << std::endl;
        }
        
    }
    else
    {
        std::cout << "NONEXISTENT" << std::endl;
    }
    
}

void Command::clear(HashMap& hm)
{
    hm.clearArray();
    std::cout << "CLEARED" << std::endl;
}

void Command::debug()
{
    if (firstWord == "ON")
    {
        if (debugMode == true)
        {
            std::cout << "ON ALREADY" << std::endl;
        }
        else
        {
            debugMode = true;
            std::cout << "ON NOW" << std::endl;
        }
    }
        else if (firstWord == "OFF")
        {
            if (debugMode == false)
            {
                std::cout << "OFF ALREADY" << std::endl;
            }
            else
            {
                debugMode = false;
                std::cout << "OFF NOW" << std::endl;
            }
        }
        else
        {
            std::cout << "INVALID" << std::endl;
        }
}

void Command::logincount(HashMap& hm)
{
    if (firstWord == "COUNT" && debugMode == true)
    {
        std::cout << hm.size() << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
    
}

void Command::bucketc(HashMap& hm)
{
    if (firstWord == "COUNT" && debugMode == true)
    {
        std::cout <<hm.bucketCount() << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

void Command::loadFac(HashMap& hm)
{
    if (firstWord == "FACTOR" && debugMode == true)
    {
        std::cout <<hm.loadFactor() << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}

void Command::maxBuckSz(HashMap& hm)
{
    if (firstWord == "BUCKET" && secondWord == "SIZE" && debugMode == true)
    {
        std::cout <<hm.maxBucketSize() << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }
}
