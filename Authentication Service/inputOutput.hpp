//inputOutput.hpp
#ifndef INPUTOUTPUT_HPP
#define INPUTOUTPUT_HPP

#include "HashMap.hpp"
#include "Command.hpp"
#include <string>

class inputOutput
{
public:
    inputOutput();
    std::string getInput();

    //these three functions parse through the user input
    std::string getCmdWord(std::string s);
    std::string getFirstWord(std::string s);
    std::string getSecondWord(std::string s);

    //executeCmd() checks if command matches word count requirement, then
    //calls function to update HashMap object
    void executeCmd(std::string s, Command &c, HashMap& hm1);


private:
    HashMap hm1;

    void printInvalid();

};

#endif