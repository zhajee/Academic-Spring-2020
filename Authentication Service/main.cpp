#include "HashMap.hpp"
#include "Command.hpp"
#include "inputOutput.hpp"
#include <iostream>

int main()
{
    //initialize objects
    HashMap hm = HashMap();
    inputOutput user = inputOutput();
    Command cmd = Command();
    
    std::string line;
    do {
        line = user.getInput();
        
        //updates words Command object stores after user object parses through
        cmd.updateWords(user.getFirstWord(line), user.getSecondWord(line));
        
        //calls functions that update HashMap in Command class 
        //after determining if command call is INVALID
        user.executeCmd(line, cmd, hm);

    } while(user.getCmdWord(line) != "QUIT");
    std::cout << "GOODBYE" << std::endl;

    return 0;
}

