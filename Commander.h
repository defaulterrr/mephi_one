#include "Command.h"
using namespace std;



enum containerType{arrayLike,list};
enum sortType{shell,input};
enum sortOrder{up,down};
enum inputMode{automatic,manual,file};

class Commander{
    struct container {
        Sequence<int>* value;
        string name;
        string type;
        bool sorted;

        container(Sequence<int>* value, string name, string type, bool sorted){
            this->value = Sequence(value);
            this->name = name;
            this->type = type;
            this->sorted = sorted;
        }

        ~container(){
            
        }
    };
    const float version = 0.2;
    containerType ContainerMode;
    sortType SortType;
    sortOrder SortMode;
    inputMode Mode;

    string currentTopLevelCommand;

    vector<container> containers;

    void addContainer(container toAdd){
        containers.push_back(toAdd);
    }

    void removeContainer(string withName){
        int index;
        for (int i = 0; i<containers.size();i++) {
            if (containers[i].name == withName){
                index = i; break;
            }
        }
        containers.erase(containers.begin()+index);
    }

    void listContainers(){
        cout << "Number     Name        Type        Sorted\n";
        for (int i=0;i<containers.size();i++) {
            cout.width(12);
            cout << i << containers[i].name << containers[i].type << containers[i].sorted << endl;
        }
    }
    /*
    first level:
        help    
        container [2-nd level] [name] [List or Array]
            create
            select
            list
            delete
        sort      [2-nd level]
            shell
            input
        test      [2-nd level]
            test1
            ...
    */
    const string helpCom = "help";
    const string containerCom = "container";
    const string sortCom = "sort";
    const string testCom = "test";

    const string help = "\nCommand Processor v0.1\n\nList of all available commands:\nhelp - shows this very menu\ncontainer - allows you to control your container, which are needed for the algorithms to work\nsort - allows you to sort containers with the algorithm of your choice\ntest - allows you to run included internal test\n\nAll commands are case-sensitive. Please, don\'t make it harder than it needs to be\n\n";
        

    void print(string message){
        cout << message << endl;
    }

    string getCommand(){
        string commandToGet;
        getline(cin,commandToGet);
        if (commandToGet.empty()) {return "unkn";}
        else
        return commandToGet;
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

            if (task.getLevel(0) == containerCom){
                //cout << "Catched container command\n";
                if (task.getLevel(1) == "list") {
                    Array<int> cont;
                    for (unsigned int i = 0 ; i < 100; i++){
                        cont.append(rand()%150);
                    }
                    container contT = container(&cont,"First","Array",false);
                    addContainer(contT);
                    listContainers();
                }
                cout << task.getLevel(2) << endl;
                continue;
            }

            if (currentTopLevelCommand == sortCom){
                continue;
            }

            if (currentTopLevelCommand == testCom){
                continue;
            }

            if (currentTopLevelCommand != "exit" && currentTopLevelCommand!="q" && currentTopLevelCommand!="quit" && currentTopLevelCommand!="^C") cout << "Unknown Command, please refer to instructions when inputting a command string\n";
        }
    }
};