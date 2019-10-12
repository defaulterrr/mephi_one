#include "UI.h"

int compare(int i, int j){
        if (i > j) {
            return 1; //You can change it to -1
        } else if (i < j) {
            return -1; //You can change it to 1
        } else if (i == j) {
            return 0;
        }
        throw std::logic_error("Unexpected error!");
    }

int main(){
    std::cout << "Initialized" << std::endl;
    //Array<int> arr;
    List<int> arr;
    for (int i = 100; i>0; i--){
        arr.append(i);
    }
    
    for (int i = 0; i<100; i++){
        std::cout << arr.get(i) << std::endl;   
    }

       

    //int compare = [](int j, int i){};

    ShellSort<int> mergeSorter;

    std::cout << "\n\n SORTING NOW \n\n" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    mergeSorter.sort(&arr,[](int i, int j){
        if (i > j) {
            return -1; //You can change it to -1
        } else if (i < j) {
            return 1; //You can change it to 1
        } else if (i == j) {
            return 0;
        }
        throw std::logic_error("Unexpected error!");
    });

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsedTime =std::chrono::duration_cast<std::chrono::microseconds>(end - start);

     for (int i = 0; i<100; i++){
        std::cout << arr.get(i) << std::endl;
    }

    std::cout << "Elapsed time is: "<< elapsedTime.count() << " microseconds"<< std::endl;

    UI Interface = UI();
    

}