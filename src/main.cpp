#include <iostream>
#include <fstream>
#include <ostream>
#include "project.hpp"
#include "project.cpp"

using namespace std;

int main () {
    int choice = -1;
    // begin a do while loop that stops when choice = last num of list
        // output list of choices and introduction
        // check validity
        // output requested info: cout all pokemon in the array
        // two arrays; one with sorted, one with original values
    // 
    cout << "Pokedex Tracker";
    cout << "Enter file name: ";
    string filename;
    cin >> filename;
    int lineCounter = 0;
    string line;
    ifstream pokefile(filename);

    if (!pokefile.is_open()) {
        return 0;
    }
    while (getline(pokefile, line)) {
        lineCounter ++;
    }
    pokefile.close();
    Pokemon pokes[lineCounter]; // now automatically create the list
    int loaded = createPokemonList(filename, pokes, lineCounter);
    cout << loaded << " Pokemon successfully found!";

    do {
        cout << "1. Print List";
        cout << "2. Sort/Filter";
        cout << "3. Mark as Caught";
        cout << "4. Open Teambuilder";
        cout << "5. Write to file";
        cout << "0. Quit";
        if (choice == 1) {

        }
        if (choice == 2) {
            cout << "Enter Generation Number: ";
            cin >> genNo;
        }
        if (choice == 3) {

        }
        if (choice == 4) {

        }
        if (choice == 5) {

        }

    } while (choice != 0);
    return 0;
}
