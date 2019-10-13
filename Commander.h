#include "Command.h"
using namespace std;



enum containerType{arrayLike,list};
enum sortType{shell,input};
enum sortOrder{up,down};
enum inputMode{automatic,manual,file};

class Commander{
    struct container {
        Sequence<int>* value = nullptr;
        string name;
        string type;
        bool sorted;

        container(Array<int>* value, string name, string type, bool sorted){
            if (type == "Array") {
                this->value = new Array<int>(value);
            }
            if (type == "List") {
                this->value = new List<int>(value);
            }
            
            this->name = name;
            this->type = type;
            this->sorted = sorted;
            //cout << "Got here" << endl;
            // for (unsigned int i =0 ;i<value->getLength();i++){
            //     cout << this->value->get(i) << endl;
            // }
        }

        container(List<int>* value, string name, string type, bool sorted){
            if (type == "Array") {
                this->value = new Array<int>(value);
            }
            if (type == "List") {
                this->value = new List<int>(value);
            }
            
            this->name = name;
            this->type = type;
            this->sorted = sorted;
            //cout << "Got here" << endl;
            // for (unsigned int i =0 ;i<value->getLength();i++){
            //     cout << this->value->get(i) << endl;
            // }
        }

        ~container(){
            // if (value!=nullptr) {
            //     delete [] value;
            // }
        }
    };
    const int contsize = 10;
    const float version = 0.2;
    containerType ContainerMode;
    sortType SortType;
    sortOrder SortMode;
    inputMode Mode;

    string currentTopLevelCommand;

    vector<container> containers;

    void addContainer(container toAdd){
        containers.push_back(toAdd);
        //cout << "DEBUG_________Added container" << endl;
    }

    void outputContainer(string withName){
        int index;
        for (int i = 0; i<containers.size();i++) {
            if (containers[i].name == withName) {
                index = i; break;
            }
        }
        container activeContainer = containers[index];

        if (activeContainer.type == "Array") {
            Sequence<int> *outputSequence = activeContainer.value; 
            //print("Getting length");
            for (unsigned int i=0;i<outputSequence->getLength();i++){
            //print("Output command");
            cout << outputSequence->get(i) << endl;
            }
        }
        // print("Starting output");
        // for (unsigned int i=0;i<activeContainer.value->getLength();i++){
        //     cout << activeContainer.value->get(i) << endl;
        // }
    }

    void shellSortContainer(string withName){
        ShellSort<int> shellSorter;

        int index;
        for (int i = 0; i<containers.size();i++) {
            if (containers[i].name == withName) {
                index = i; break;
            }
        }

        container activeContainer = containers[index];

        std::cout << "\n\n SORTING NOW \n\n" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    shellSorter.sort(activeContainer.value,[](int i, int j){
        if (i > j) {
            return 1; //You can change it to -1
        } else if (i < j) {
            return -1; //You can change it to 1
        } else if (i == j) {
            return 0;
        }
        throw std::logic_error("Unexpected error!");
    });


    

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsedTime =std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    //  for (int i = 0; i<100; i++){
    //     std::cout << activeContainer.value->get(i) << std::endl;
    // }

    std::cout << "Elapsed time is: "<< elapsedTime.count() << " microseconds"<< std::endl;
        
    }

    void insertSortContainer(string withName){
        InsertSort<int> shellSorter;

        int index;
        for (int i = 0; i<containers.size();i++) {
            if (containers[i].name == withName) {
                index = i; break;
            }
        }

        container activeContainer = containers[index];

        std::cout << "\n\n SORTING NOW \n\n" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    shellSorter.sort(activeContainer.value,[](int i, int j){
        if (i > j) {
            return 1; //You can change it to -1
        } else if (i < j) {
            return 0; //You can change it to 1
        } else if (i == j) {
            return 0;
        }
        throw std::logic_error("Unexpected error!");
    });


    

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsedTime =std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    //  for (int i = 0; i<100; i++){
    //     std::cout << activeContainer.value->get(i) << std::endl;
    // }

    std::cout << "Elapsed time is: "<< elapsedTime.count() << " microseconds"<< std::endl;
        
    }

    void removeContainer(string withName){
        int index;
        for (int i = 0; i<containers.size();i++) {
            if (containers[i].name == withName) {
                index = i; break;
            }
        }
        containers.erase(containers.begin()+index);
    }

    void listContainers(){
        // cout << "DEBUG_________Called for listing" << endl;
        // cout << "DEBUG_________Now " << containers.size() << " Allocated" << endl;
        cout << "Number      Name        Type        Sorted\n";
        cout << "––––––––––––––––––––––––––––––––––––––––––\n";
        for (int i=0;i<containers.size();i++) {
            // cout.width(8);cout.left;
            // cout << i << containers[i].name << containers[i].type << containers[i].sorted << endl;

            cout.width(12);
            cout.left;
            cout << std::left << i+1;
            cout.width(12);
            cout.left;
            cout << std::left << containers[i].name;
            cout.width(12);
            cout.left;
            cout << std::left <<containers[i].type;
            cout.width(12);
            cout.left;
            if (containers[i].sorted) {
                cout << std::left <<"Sorted";
            }
            else {
                cout << std::left << "Not Sorted";
            }
            cout << endl;
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
                if (task.commandList.size()==1) {
                    cout << "Wrong implementation of the command - go check it in the help menu\n";
                    continue;
                }
                //cout << "Catched container command\n";
                        if (task.getLevel(1) == "list") {
                            if (task.commandList.size()!= 2) {
                                cout << "Wrong implementation of the command - go check it in the help menu\n";
                            }

                            if (containers.size() == 0 ) {
                                cout << "No containers are available at this moment, you may want to create some\n";
                                continue;
                            }

                            else listContainers();
                        }

                        if (task.getLevel(1) == "create") {
                            if (task.commandList.size()<4 or task.commandList.size() > 4) {
                                cout << "Wrong implementation of the command - go check it in the help menu\n";
                            }
                            else {
                                if (task.getLevel(3) == "array") {
                                    Array<int> cont = Array<int>();
                                    for (unsigned int i=0; i<contsize; i++) {
                                        cont.append(rand()%150+ i*10%rand());
                                    }

                                    // for (unsigned int i=0;i<cont.getLength();i++){
                                    //     cout << cont.get(i) << endl;
                                    // }
                                    //print("And here");
                                    container contT = container(&cont,task.getLevel(2),"Array",false);
                                    addContainer(contT);
                                    //print("Succesfully added container");
                                    print("Succesfully created container with Array type sequence with name:" + task.getLevel(2) + "\n");
                                    continue;
                                    }
                                
                                    else if (task.getLevel(3) == "list") {
                                            List<int> cont;
                                            for (unsigned int i=0; i<contsize; i++) {
                                                cont.append(rand()%150+ i*10%rand());
                                            }
                                    container contT = container(&cont,task.getLevel(2),"Array",false);
                                    addContainer(contT);
                                }
                                else cout << "Unknown type of sequential container: available type are: array OR list\n";
                            }
                        }
                                

                        if (task.getLevel(1) == "show") {
                            if (task.commandList.size() != 3 ) {
                                cout << "Wrong implementation of the command - go check it in the help menu\n";
                                continue;
                            }
                            else {
                                outputContainer(task.getLevel(2));
                            }
                        }

                        if (task.getLevel(1) == "delete") {
                            if (task.commandList.size() != 3) {
                                cout << "Wrong implementation of the command - go check it in the help menu\n";
                                continue;
                            }
                            else {
                                removeContainer(task.getLevel(1));
                                cout << "Removed container with name \"" << task.getLevel(1) << "\"\n";
                            }
                        }
                        //cout << task.getLevel(2) << endl;
                        continue;
            }

            if (task.getLevel(0) == sortCom){
                if (task.commandList.size() != 3) {
                    cout << "Wrong implementation of the command - go check it in the help menu\n";
                    continue;
                }
                else {

                    if (task.getLevel(1) == "shell") {
                        //print("Catched shell command");
                        if (task.commandList.size() != 3) {
                        cout << "Wrong implementation of the command - go check it in the help menu\n";
                        continue;
                        }
                        else {
                            shellSortContainer(task.getLevel(2));
                            continue;
                        }
                    }

                    else if (task.getLevel(1) == "input") {
                        if (task.commandList.size() != 3) {
                            cout << "Wrong implementation of the command - go check it in the help menu\n";
                            continue;
                        }
                        else {
                            insertSortContainer(task.getLevel(2));
                            continue;
                        }
                    }
                }
                continue;
            }

            if (currentTopLevelCommand == testCom){
                continue;
            }

            if (currentTopLevelCommand != "exit" && currentTopLevelCommand!="q" && currentTopLevelCommand!="quit" && currentTopLevelCommand!="^C") cout << "Unknown Command, please refer to instructions when inputting a command string\n";
        }
    }
};