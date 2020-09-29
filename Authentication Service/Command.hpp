//Command.hpp
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include "HashMap.hpp"

class Command
{
public:
    Command();
    void updateCmd(std::string cmd);

    void create(HashMap& hm);

    void login(HashMap& hm);

    void remove(HashMap& hm);

    void clear(HashMap& hm);

    void debug();

    void logincount(HashMap& hm);

    void bucketc(HashMap& hm);

    void loadFac(HashMap& hm);

    void maxBuckSz(HashMap& hm);

    void updateWords(std::string firstWord, std::string secondWord);

private:
    
    std::string firstWord;
    std::string secondWord;

    bool debugMode;

    bool exists(std::string key, std::string value, HashMap &hm);

};

#endif