#include "deepsrc.h"
using namespace std;

struct Command{
    string wholeCommand;
    // string firstLevel;
    // string secondLevel;
    // string thirdLevel;
    // string fourthLevel;

    vector<string> commandList;

    

    Command(string command){
        if (command.empty()) {} else {
        this->wholeCommand = command;
        wholeCommand += ' ';
        analyze();
        }
    }

    string getLevel(int index){
        if (index >= commandList.size()) {
            return "Insufficient amount of arguments for command";
        } 
        else
            return commandList[index];
    }

private:
    void analyze(){
        string minimalWhiteSpace = string();
        for (unsigned int i=0; i< wholeCommand.size()-1;i++){
            if(wholeCommand[i] != ' ' && wholeCommand[i]!='\n'){
                minimalWhiteSpace += wholeCommand[i];
            }
            else if (wholeCommand[i]==' ' && wholeCommand[i+1]!= ' '){
                minimalWhiteSpace += wholeCommand[i];
            }
            else if (wholeCommand[i+1]!=' ' && wholeCommand[i+2] == '\n') {
                minimalWhiteSpace += wholeCommand[i+1];
            }

        }

        minimalWhiteSpace += ' ';
        if(minimalWhiteSpace[0] == ' ') {} else
        {minimalWhiteSpace = ' ' + minimalWhiteSpace;}

        for (unsigned int i=0;i<minimalWhiteSpace.size();i++){
            int first = minimalWhiteSpace.find_first_of(' ',i);
            //cout << first;
            int last = minimalWhiteSpace.find_first_of(' ',first+1);
            //cout << " To " << last << endl;
            i = first;
            int length = last - first;
            string message = minimalWhiteSpace.substr(first+1,length);
            //cout << message << endl;
            if (message == "") {} else
            {commandList.push_back(message);}
        }

        // for (int i = 0; i < commandList.size(); i++){
        //     cout << commandList[i] << endl;
        // }

        for (int i = 0; i < commandList.size(); i++) {
            string message = commandList[i].substr(0,commandList[i].size()-1);
            commandList[i] = message;
            //cout << message << endl;
        }

        //cout << "minimal white space is : " << minimalWhiteSpace << endl;
    }
    
};