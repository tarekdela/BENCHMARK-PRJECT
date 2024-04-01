#include <chrono>
#include <cmath>
#include <iostream>
using namespace std;
using namespace std::chrono;

void RunCalculations(){
    int result;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < pow(10,9); j++){
            result = 1.0 + 1.0;
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < pow(10,9); j++){
            result = 1.0 * 1.0;
        }

    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < pow(10,9); j++){
            result = 1.0 / 1.0;
        }
    }  
}

int main(){

     auto start = high_resolution_clock::now();

    RunCalculations();

    auto stop = high_resolution_clock::now();

    auto runTime = duration_cast<milliseconds>(stop-start);

     double seconds = runTime.count() / 1000.0;
    int minutes = seconds / 60;

    cout << minutes << " m " << std::fmod(seconds, 60) << " s\n";

}