#include "Command.h"
using namespace std;



enum containerType{arrayLike,list};
enum sortType{shell,input};
enum sortOrder{up,down};
enum inputMode{automatic,manual,file};

class Commander{
    const float version = 0.1;
    containerType ContainerMode;
    sortType SortType;
    sortOrder SortMode;
    inputMode Mode;

    string currentTopLevelCommand;
    /*
    first level:
        help
        container
        sort
        test
    */
    string helpCom = "help";
    const string containerCom = "container";
    const string sortCom = "sort";
    const string testCom = "test";

    const string help = "\nCommand Processor v0.1\n\nList of all available commands:\nhelp - shows this very menu\ncontainer - allows you to control your container, which are needed for the algorithms to work\nsort - allows you to sort containers with the algorithm of your choice\ntest - allows you to run included internal test\n\nAll commands are case-sensitive. Please, don\'t make it harder than it needs to be\n\n";
        

    void print(string message){
        cout << message << endl;
    }


public: 
    Commander(){
        ContainerMode = arrayLike;
        SortType = shell;
        SortMode = up;
        Mode = automatic;


        cout << "Lab MEPhi 1.1 \n";
        cout << "Command Processor v" << version << endl;
        cout << "For the list of all available commands enter \"help\"" << endl;
    }

    string getCommand(){
        string commandToGet;
        getline(cin,commandToGet);
        if (commandToGet.empty()) {return "unkn";}
        else
        return commandToGet;
    }

    void eventLoop(){
        while (currentTopLevelCommand != "exit" && currentTopLevelCommand!="q" && currentTopLevelCommand!="quit" && currentTopLevelCommand!="^C"){
            cout << ">> ";
            currentTopLevelCommand = getCommand();
            
            Command task = Command(currentTopLevelCommand);
            //cout << "external access is equal to {" <<task.commandList[0]<< "}"<< endl;
            //helpCom = task.commandList[0];
            if (task.getLevel(0) == helpCom){
                //cout << "Catched help command" << endl;
                cout << help;
                continue;
            }

            if (currentTopLevelCommand == containerCom){
                continue;
            }

            if (currentTopLevelCommand == sortCom){
                continue;
            }

            if (currentTopLevelCommand == testCom){
                continue;
            }

            cout << "Unknown Command, please refer to instructions when inputting a command string\n";
        }
    }
};