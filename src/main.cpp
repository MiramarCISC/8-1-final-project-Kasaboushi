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
        cout << "3. Toggle Caught";
        cout << "4. Open Teambuilder";
        cout << "5. Write to file";
        cout << "6. Show Completion";
        cout << "0. Quit";
        cout << "Input Choice: ";
        cin >> choice;
        if (isValidChoice(choice))
            if (choice == 1) {
                cout << "Name Type1 Type2 DexNumber Generation";
                printPokemon(pokes, lineCounter);
            }
            if (choice == 2) {
                cout << "Pick Parameter";
                cout << "1. Caught";
                cout << "2. Generation";
                cout << "3. Type";
                int sortChoice = 0;
                if (choice == 1) {
                    sortByCaught(pokes,lineCounter);
                    cout << "Sort Complete!";
                }
                else if (sortChoice == 2) {
                    cout << "Enter Generation Number: ";
                    int genNo;
                    cin >> genNo;
                    if ((choice >= 1) && (choice <= 9)) {
                        sortByGeneration(pokes,lineCounter,genNo);
                        cout << "Sorting for Generation " << genNo << " Pokemon...";
                    }
                    else {
                        cout << "Invalid Number";
                    }
                }
                else if (sortChoice == 3) {
                    string type1;
                    string type2;
                    cout << "Enter Type 1";
                    cin >> type1;
                    cout << "Enter Type 2";
                    cin >> type2;
                    sortByType(pokes, type1, type2, lineCounter);
                }
                else {
                    cout << "Invalid Choice";
                }
            }
            if (choice == 3) {
                cout << "Enter Name:";
                string name;
                cin >> name;
                changeCaught(pokes, name, lineCounter);
            }
            if (choice == 4) {
                cout << "Welcome to the Teambuilder!";
                cout << "1. Add Pokemon";
                cout << "2. Clear Team";
                cout << "3. Save Team";
                cout << "0. Exit";
                int teamChoice = -1;
                do {
                    if ((teamChoice <= 0)||(teamChoice <= 3)) {
                        if (teamChoice == 1) {
                            
                        }
                        if (teamChoice == 2) {
                            //deleteAllMembers();
                        }
                        if (teamChoice == 3) {
                            bool success = true;//writeTeamOut("team.txt", );
                            if (success){
                                cout << "Write Complete under team.txt";
                            }
                            else {
                                cout << "Error";
                            }
                        }
                        if (teamChoice == 0) {
                            cout << "Exiting...";
                        }
                    }
                } while (choice != 0);
            }
            if (choice == 5) {
                
            }
            if (choice == 6) {
                cout << percentCaught(pokes, lineCounter) << " Percent Caught!";
                gradeMessage(percentCaught(pokes, lineCounter));
            }
            if (choice == 0) {
                cout << "Exiting...";
            }
        else {
            cout << "Invalid Choice";
        }

    } while (choice != 0);
    return 0;
}
