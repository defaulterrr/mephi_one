#include "deepsrc.h"
using namespace std;

enum TimeMode{sec,millisec,microsec};


class UI{
private:
    //const 
    bool benchmark;
    bool testing;
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;
public:
    void print(string message){
        cout << message << endl;
    }

    void startTimer(){
        begin = chrono::high_resolution_clock::now();
    }
    void stopTimer(){
        end = chrono::high_resolution_clock::now();
    }
    void getTimeResult(TimeMode mode){
        switch (mode)
        {
        case sec:{
            auto time = std::chrono::duration_cast<chrono::seconds>(end-begin);
            cout << "Time estimated: " << time.count() << " seconds" << endl;} 
            break;

        case millisec:{
            auto time = std::chrono::duration_cast<chrono::milliseconds>(end-begin);
            cout << "Time estimated: " << time.count() << " seconds" << endl;} 
            break;

        case microsec:{
            auto time = std::chrono::duration_cast<chrono::microseconds>(end-begin);
            cout << "Time estimated: " << time.count() << " seconds" << endl;} 
            break;
        
        default:
            break;
        }
    }

    UI(){
        benchmark = false;
        testing = false;
    }

    UI(bool benchmark, bool testing){
        this->benchmark = benchmark;
        this->testing = testing;
    }

    void execute(){
        Array<int> containterOne;
        for (unsigned int i = 0; i < 100; i++) {
            containterOne.append(rand()%150);
        }

        Array<int> containerTwo = Array<int>(containterOne);

        ShellSort<int> shellSorter;

        shellSorter.sort(&containerTwo,[](int i,int j){
            return 1;
        });
    }
};