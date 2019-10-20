
#include "Commander.h"

int main(){
    std::cout << "Initialized" << std::endl;Commander bash = Commander();
    bash.eventLoop();
    return 0;
}