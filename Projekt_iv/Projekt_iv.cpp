#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Nalezy podac dwie nazwy plikow\n";
        return 0;
    }

    int bitCounter = 0, differentCounter = 0;

    string firstFile = argv[1];
    string secondFile = argv[2];

    ifstream firstStream(firstFile, ios::binary);
    ifstream secondStream(secondFile, ios::binary);

    

    char firstChar, secondChar;
    firstStream >> firstChar;
    secondStream >> secondChar;

    while (firstChar != EOF && secondChar != EOF) {

        bitCounter++;
        if (firstChar != secondChar) {
            differentCounter++;
        }
        firstStream >> firstChar;
        secondStream >> secondChar;

    }

    if (firstChar != EOF || secondChar != EOF) {
        cout << "Pliki powinny byc tej samej dlugosci";
    }
    else {
        double a = differentCounter, b = bitCounter;
        cout << a / b << "\n";
    }


    firstStream.close();
    secondStream.close();


    return 0;
}

