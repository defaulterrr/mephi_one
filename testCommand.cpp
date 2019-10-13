#include "Command.h"

int main(int argc, char* argv[]){
    string message;
    getline(cin,message);
    cout << "Captured message" << endl;
    Command com = Command(message);
    cout << "Initialized command" << endl;
    for (unsigned int i = 0; i < com.commandList.size(); i++) {
        cout << com.commandList[i] << endl;
    }

    return 0;
}