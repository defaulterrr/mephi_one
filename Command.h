#include "deepsrc.h"
using namespace std;

struct Command{
    string wholeCommand;
    string firstLevel;
    string secondLevel;
    string thirdLevel;
    string fourthLevel;

    string *commandList;

    

    Command(string command){
        this->wholeCommand = command;
        getFirstLevel();
    }

private:
    void getFirstLevel(){
        /*bool lastWhitespaceBit = false;
        bool lastNotWhiteSpace = false;
        string tempfirstLevel = string();
        for (unsigned int i=0;i<wholeCommand.length()-1;i++){
            if (!lastWhitespaceBit){
                if(wholeCommand[i+1] == ' '){}
                    else {
                        lastWhitespaceBit = true;
                    }
            }
            else {
                if()
                tempfirstLevel+=wholeCommand[i];
            }
        }
        */
        int firstSymbolIndex;
        int counter=0;
        while(wholeCommand[counter]==' '){
           counter++;
        }
        firstSymbolIndex = counter;
        int lastSymbolIndex = wholeCommand.find_first_of(' ',counter);
        this->firstLevel = wholeCommand.substr(firstSymbolIndex,lastSymbolIndex);
    }

    void analyze(){
        for (unsigned int i =0 ; i < wholeCommand.length() - 1; i++) {
            
        }
    }
    
};