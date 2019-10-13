#include "deepsrc.h"
using namespace std;

struct Command{
    string wholeCommand;
    string firstLevel;
    string secondLevel;
    string thirdLevel;
    string fourthLevel;

    vector<string> commandList;

    

    Command(string command){
        this->wholeCommand = command;
        analyze();
        //getFirstLevel();
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
        /*for (unsigned int i =0 ; i < wholeCommand.length() - 1; i++) {
            if (wholeCommand[i] != ' ') {
                string command;
                int index = i;
                int lastIndex = wholeCommand.find(i,' ');
                command = wholeCommand.substr(i,lastIndex);
                commandList.push_back(command);
                cout << "Current iterator is " << i <<  endl;
                i += lastIndex;
            }
        }*/

        for (unsigned int i = 0; i<wholeCommand.size()-1;i++) {
            if(wholeCommand[i] == ' ' && wholeCommand[i+1] == '\n'){ break;} else { 
                if (wholeCommand[i] == ' ') {
                    cout << "Skipped whitespace" << endl;
                    continue;

                } else {
                    int firstIndex = i;
                    int lastIndex;
                    for (unsigned int j = i;j<wholeCommand.size();j++) {
                        if (wholeCommand[j] == ' ' or wholeCommand[j] == '\n') {
                            lastIndex = j;
                            break;
                        }
                    }
                    string command = wholeCommand.substr(firstIndex, lastIndex);
                    commandList.push_back(command);
                    cout << "Added command " << command << endl;
                    i = lastIndex-1;
                }
            }
        }
    }
    
};