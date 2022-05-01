#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

double generateRandomNumber(int min, int max) {
    return rand() % max + min;
}

string generateRandomHash() {
    int index;
    char character;
    string hash = "";

    for (index = 0; index < 35; index++) {
        int randomNumber = rand() % 2 + 1;
        int randomCharacterNumber = rand() % 26;
        character = 'a' + randomCharacterNumber;

        if (randomNumber == 1) {
            character = toupper(character);
            hash.push_back(character);
        } else {
            hash.push_back(character);
        }
    }

    return hash;
}

int main() {
    while (true) {
        HANDLE iostreamHandle = GetStdHandle( STD_OUTPUT_HANDLE );
        int randomNumber = generateRandomNumber(1, 1000);

        if (randomNumber == 1) {
            SetConsoleTextAttribute(iostreamHandle, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout << "[-] ";

            SetConsoleTextAttribute(iostreamHandle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY );
            cout << generateRandomHash() << " ";

            SetConsoleTextAttribute(iostreamHandle, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
            cout << "0.000" << generateRandomNumber(1000, 9000) << " BTC" << endl;

            Sleep(10000);
        } else {
            SetConsoleTextAttribute(iostreamHandle, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout << "[-] ";

            SetConsoleTextAttribute(iostreamHandle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY );
            cout << generateRandomHash() << " ";

            SetConsoleTextAttribute(iostreamHandle, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout << "0.0000000 BTC" << endl;

            Sleep(10);
        }

        
    }

    return 0;
}