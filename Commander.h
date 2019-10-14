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

    Array<int> createRandomArray(int size){
        Array<int> array = Array<int>();
        for (unsigned int i = 0; i<size;i++){
            array.append(rand()%150+ i*10%rand());
        }
        return array;
    }

    Array<int> createManualArray(int size){
        Array<int> array = Array<int>();
        for (unsigned int i = 0; i<size;i++){
            int def;
            string str;
            getline(cin,str);
            try {
                def = stoi(str);
            }
            catch (std::out_of_range){
                cout << "Number is out of range, using default i = 1235\n";
                def = 1235;
            }
            catch (std::invalid_argument){
                cout << "Invalid input, using default i = 1235\n";
                def = 1235;
            }
            array.append(def);
        }
        return array;
    }

    List<int> createRandomList(int size){
        List<int> list = List<int>();
        for (unsigned int i=0; i<size;i++){
            list.append(rand()%150+ i*10%rand());
        }
        return list;
    }

    List<int> createManualList(int size){
        List<int> list = List<int>();
        for (unsigned int i=0; i<size;i++){
            int def;
            cin >> def;
            list.append(def);
        }
        return list;
    }

    void addContainer(container toAdd){
        containers.push_back(toAdd);
        //cout << "DEBUG_________Added container" << endl;
    }

    void addContainerWithCopy(string withName, string newName){
        int index;
        for (int i = 0; i<containers.size();i++) {
            if (containers[i].name == withName) {
                index = i; break;
            }
        }
        container activeContainer = containers[index];

        if (activeContainer.type == "Array") {
            Array<int> sequence = Array<int>(activeContainer.value);
            container newContainer = container(&sequence,newName,"Array",activeContainer.sorted);
            addContainer(newContainer);
        }

        else if (activeContainer.type == "List") {

        }
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

    void outputContainersAsCompare(string firstName, string secondName){
        int index;
        for (int i = 0; i<containers.size();i++) {
            if (containers[i].name == firstName) {
                index = i; break;
            }
        }
        container activeContainer_1 = containers[index];

        for (int i = 0; i<containers.size();i++) {
            if (containers[i].name == secondName) {
                index = i; break;
            }
        }

        container activeContainer_2 = containers[index];


        cout.width(10);
        cout.left;
        cout << "Original";
        cout.width(10);
        cout.left;
        cout << "Sorted";
        cout << endl;

        if (activeContainer_1.value->getLength() == activeContainer_2.value->getLength()) {
            for (unsigned int i=0;i<activeContainer_1.value->getLength();i++){
            cout.width(10);
            cout.left;
            cout << activeContainer_1.value->get(i);
            cout.width(10);
            cout.left;
            cout << activeContainer_2.value->get(i);
            cout << endl;
            }
        }
    }

    void checkIfContainerIsSorted(string withName){
        int index;
        for (int i = 0; i<containers.size();i++) {
            if (containers[i].name == withName) {
                index = i; break;
            }
        }

        container activeContainer = containers[index];
        bool correct = true;
        
        int counter = 0;

        while (counter < activeContainer.value->getLength()-2){
            if (activeContainer.value->get(counter)>activeContainer.value->get(counter+1)){
                correct = false;
                cout << "Got incorrect result with " <<  activeContainer.value->get(counter) << " and "<<activeContainer.value->get(counter+1) << endl;
                break;
            }
            counter++;
            
        }

        if (correct) {
            cout << "Container was succesfully sorted" << endl;
        }
        else {
            cout << "Container was NOT sorted, something went wrong..." << endl;
        }
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

        std::cout << "\n **Sorting now, this may take a while**\n" << std::endl;

        addContainerWithCopy(withName,withName+"_tempsort");



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


    containers[index].sorted = true;

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsedTime =std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    outputContainersAsCompare(withName+"_tempsort",withName);

    checkIfContainerIsSorted(withName);

    removeContainer(withName+"_tempsort");



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

        addContainerWithCopy(withName,withName+"_tempsort");

        std::cout << "\n **Sorting now, this may take a while**\n" << std::endl;

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

    activeContainer.sorted = true;


    

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsedTime =std::chrono::duration_cast<std::chrono::microseconds>(end - start);


    outputContainersAsCompare(withName+"_tempsort",withName);

    checkIfContainerIsSorted(withName);

    containers[index].sorted = true;

    removeContainer(withName+"_tempsort");


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
    
    //string help = "\nCommand Processor v0.1\n\nList of all available commands:\nhelp - shows this very menu\ncontainer - allows you to control your container, which are needed for the algorithms to work\nsort - allows you to sort containers with the algorithm of your choice\ntest - allows you to run included internal test\n\nAll commands are case-sensitive. Please, don\'t make it harder than it needs to be\n\n";
    const string help = "List of all available commands:\nhelp - shows this help menu\ncontainer create {NAME} {array OR list} - creates a container of given name, type and a size of 10 (elements are random)\ncontainer create {NAME} {array OR list} {size(int)} {\"auto\" or \"manual\"} - creates a container of given name, type and size (elements are random)\ncontainer show {NAME} - show the container with given name\ncontainer list - show list of all existed containers\ncontainer delete {NAME}  - delete the container with given name\nsort {shell OR insert} {NAME} - sort  the container with given name by shell sort or insert sort\ntest size {\"shell\" or \"insert\"} - runs included test on high amount of elements with built-in benchmark and sort check\n\nAll commands are case-sensitive. Please, don't make it harder than it needs to be\n";    

    //help = newHelp;

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
            cout << "  >> ";
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
                            if (task.commandList.size() == 6) {
                                int test;
                                try {
                                    test = stoi(task.getLevel(4));
                                }
                                catch(const std::invalid_argument) {
                                    cout << "Invalid argument: cannot be translated to size\n";
                                    continue;
                                }
                                catch(const std::out_of_range) {
                                    cout << "Invalid argument: size is too big\n";
                                    continue;
                                }

                                if (task.getLevel(3) == "list") {
                                    if (task.getLevel(5) == "auto"){        
                                        Array<int> cont = createRandomArray(test);
                                        container contT = container(&cont,task.getLevel(2),"List",false);
                                        addContainer(contT);
                                        continue;
                                    }
                                    else if (task.getLevel(5) == "manual") {
                                        Array<int> cont = createManualArray(test);
                                        container contT = container(&cont,task.getLevel(2),"List",false);
                                        addContainer(contT);
                                        continue;
                                    }
                                }

                                if (task.getLevel(3) == "array") {
                                    if (task.getLevel(5) == "auto") { 
                                        List<int> cont = createRandomList(test);
                                        container contT = container(&cont,task.getLevel(2),"Array",false);
                                        addContainer(contT);
                                        continue;
                                    }
                                    else if (task.getLevel(5) == "manual") {
                                        List<int> cont = createManualList(test);
                                        container contT = container(&cont,task.getLevel(2),"Array",false);
                                        addContainer(contT);
                                        continue;
                                    }

                                }

                                cout << "Wrong command" << endl;
                                
                            }
                            else {
                                if (task.getLevel(3) == "array") {
                                    Array<int> cont = Array<int>();
                                    if (task.getLevel(4) != "Insufficient amount of arguments for command") {
                                        for (unsigned int i=0;i<stoi(task.getLevel(4));i++) {
                                            cont.append(rand()%150+ i*10%rand());
                                        };
                                    }
                                    else {
                                        for (unsigned int i=0; i<contsize; i++) {
                                            cont.append(rand()%150+ i*10%rand());
                                        }
                                    }
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
                                    container contT = container(&cont,task.getLevel(2),"List",false);
                                    addContainer(contT);
                                }
                                else cout << "Unknown type of sequential container: available type are: array OR list\n";
                            }
                        }

                        if (task.getLevel(1) == "copy") {
                            if (task.commandList.size() != 4) {
                                cout << "Wrong implementatuin of the command – go check it in the help menu\n";
                            }
                            else {
                                addContainerWithCopy(task.getLevel(3),task.getLevel(2));
                                print("Created new container with name \"" + task.getLevel(2) + "\" as a copy of \"" + task.getLevel(3) +"\"\n");
                            }
                        }

                        // if (task.getLevel(1) == "createCustom") {
                        //     if (task.commandList.size() < 5 or task.commandList.size() > 5) {
                        //         cout << "Wrong implementation of the command - go check it in the help menu\n";
                        //     }
                        //     else {
                        //         if (task.getLevel(3) == "array") {
                        //             Array<int> cont;
                        //             if (task.getLevel(4) != "Insufficient amount of arguments for command") {
                                        
                        //                 cont = createRandomArray(stoi(task.getLevel(4)));
                        //             }
                        //             else {
                                        
                        //                 cont = createRandomArray(contsize);
                        //             }

                        //             // for (unsigned int i=0;i<cont.getLength();i++){
                        //             //     cout << cont.get(i) << endl;
                        //             // }
                        //             //print("And here");
                        //             container contT = container(&cont,task.getLevel(2),"Array",false);
                        //             addContainer(contT);
                        //             //print("Succesfully added container");
                        //             print("Succesfully created container with Array type sequence with name:" + task.getLevel(2) + "\n");
                        //             continue;
                        //             }
                                
                        //             else if (task.getLevel(3) == "list") {
                        //                     List<int> cont = createRandomList(contsize);
                                            
                                        
                        //             container contT = container(&cont,task.getLevel(2),"Array",false);
                        //             addContainer(contT);
                        //         }
                        //         else cout << "Unknown type of sequential container: available type are: array OR list\n";
                        //     }
                        // }
                                

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

                    else if (task.getLevel(1) == "insert") {
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

            if (task.getLevel(0) == testCom){
                if (!(task.commandList.size()==3 or task.commandList.size()==2)) {
                    cout << "Wrong implementation of the command - go check it in the help menu\n";
                }
                else {
                    if (task.commandList.size() == 2 and task.getLevel(1)!="string") {
                        cout << "Wrong implementation of the command - go check it in the help menu\n";
                        continue;
                    }
                    else {
                        //TO-DO: create string test
                        print("string test");
                        
                    }

                    if (task.commandList.size() == 3) {
                        print("hey");
                        if (task.getLevel(1) == "size") {
                            if (task.getLevel(2) == "shell") {
                                //TO-DO: create shell sort test with n=10000 
                                Array<int> cont = createRandomArray(10000);
                                container testContainer = container(&cont,"testContainer","Array",false);
                                print("Running test");
                                addContainer(testContainer);
                                shellSortContainer("testContainer");
                                cout << "Tested Shell sort with n=10000\n";
                                removeContainer("testContainer");
                                //continue;
                            }
                            if(task.getLevel(2) == "insert") {
                                //TO-DO: create insert sort test with n=10000
                                Array<int> cont = createRandomArray(10000);
                                container testContainer = container(&cont,"testContainer","Array",false);
                                print("Running test");
                                addContainer(testContainer);
                                insertSortContainer("testContainer");
                                cout << "Tested Insert sort with n=10000\n";
                                removeContainer("testContainer");
                                continue;
                            }
                        }
                        else {
                            cout << "Wrong implementation of the command - go check it in the help menu\n";
                        }
                    }
                }
                continue;
            }

            if (currentTopLevelCommand != "exit" && currentTopLevelCommand!="q" && currentTopLevelCommand!="quit" && currentTopLevelCommand!="^C") cout << "Unknown Command, please refer to instructions when inputting a command string\n";
        }
    }
};