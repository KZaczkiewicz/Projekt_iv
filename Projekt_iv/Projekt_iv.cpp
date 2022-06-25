#include <iostream>
#include <fstream>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Nalezy podac dwie nazwy plikow\n";
        return 0;
    }

    int bitCounter = 0, differentCounter = 0;

    auto start = high_resolution_clock::now();

    string firstFile = argv[1];
    string secondFile = argv[2];

    ifstream firstStream(firstFile, ios::binary);
    ifstream secondStream(secondFile, ios::binary);

    ofstream logsFile;
    logsFile.open("logs.txt");

    

    char firstChar, secondChar;
    firstStream >> firstChar;
    secondStream >> secondChar;

    while (!firstStream.eof() && !secondStream.eof()) {

        bitCounter++;
        if (firstChar != secondChar) {
            differentCounter++;
        }
        firstStream >> firstChar;
        secondStream >> secondChar;

    }

    if (!firstStream.eof() || !secondStream.eof()) {
        auto now = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(now.time_since_epoch());
        logsFile << duration.count() << "nie mozna porownac plikow roznej dlugosci\n";
        cout << duration.count() << "nie mozna porownac plikow roznej dlugosci";
    }
    else {
        double a = differentCounter, b = bitCounter;
        
        auto now = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(now.time_since_epoch());
        cout << duration.count() << " ilosc roznych bajtow: " << a << "\n";
        cout << duration.count() << " ilosc porownanych bajtow: " << b << "\n";
        cout << duration.count() << " BER: " << a / b << "\n";
        logsFile << duration.count() << " ilosc roznych bajtow: " << a << "\n";
        logsFile << duration.count() << " ilosc porownanych bajtow: " << b << "\n";
        logsFile << duration.count() << " BER: " << a / b << "\n";
        auto stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "czas: " << duration.count() << "\n";
    }


    firstStream.close();
    secondStream.close();
    logsFile.close();


    return 0;
}

