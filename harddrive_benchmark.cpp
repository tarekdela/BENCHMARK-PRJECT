#include <chrono>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;
using namespace std::chrono;

void HardDriveBenchmark1(char * txt){
    fstream file;

    file.open("file.txt", ios::out | ios::app | ios::binary);

    int loop = pow(10, 7);

    for(int i = 0; i < loop; i++){
        file.write(txt, 100);
    }

    file.seekg(0);

    for(int i = 0; i < loop; i++){
        file.read(txt, 100);
    }

    file.close();
}

int main(){

    char text[100];
    for(int i = 0; i < 100; i++){
        text[i] = 'a';
    }

    auto start = high_resolution_clock::now();

    HardDriveBenchmark1(text);

    auto stop = high_resolution_clock::now();

    auto runTime = duration_cast<milliseconds>(stop-start);

    double seconds = runTime.count() / 1000.0;
    int minutes = seconds / 60;

    cout << minutes << " m " << std::fmod(seconds, 60) << " s\n";

}