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
    const string helpCom = "help";
    const string containerCom = "help";
    const string sortCom = "help";
    const string testCom = "help";

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
        return commandToGet;
    }

    void eventLoop(){
        while (currentTopLevelCommand != "exit" && currentTopLevelCommand!="q" && currentTopLevelCommand!="quit" && currentTopLevelCommand!="^C"){
            currentTopLevelCommand = getCommand();
            Command task = Command(currentTopLevelCommand);

            if (task.firstLevel == helpCom){
                cout << help;
            }

            if (currentTopLevelCommand == containerCom){

            }

            if (currentTopLevelCommand == sortCom){

            }

            if (currentTopLevelCommand == testCom){

            }
        }
    }
};