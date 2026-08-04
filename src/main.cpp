#include <iostream>
#include <fstream>
#include <ostream>
#include "project.hpp"


using namespace std;

int main () {
    int choice = -1;
    // begin a do while loop that stops when choice = last num of list
        // output list of choices and introduction
        // check validity
        // output requested info: cout all pokemon in the array
        // two arrays; one with sorted, one with original values
    // 
    cout << "Pokedex Tracker " << "\n";
    cout << "Enter file name: ";
    string filename;
    cin >> filename;
    int lineCounter = 0;
    string line;
    ifstream pokefile(filename);

    if (!pokefile.is_open()) {
        cout << "Failed to Open\n";
        return 0;
    }
    while (getline(pokefile, line)) {
        lineCounter ++;
    }
    pokefile.close();
    Pokemon* pokes = new Pokemon[lineCounter]; // now automatically create the list
    int loaded = createPokemonList(filename, pokes, lineCounter);
    cout << loaded << " Pokemon successfully found!\n";

    do {
        cout << "1. Print List\n";
        cout << "2. Sort/Filter\n";
        cout << "3. Toggle Caught\n";
        cout << "4. Open Teambuilder\n";
        cout << "5. Write to file\n";
        cout << "6. Show Completion\n";
        cout << "0. Quit\n";
        cout << "Input Choice: ";
        cin >> choice;
        if (isValidChoice(choice)) {
            if (choice == 1) {
                cout << "Name Type1 Type2 DexNumber Generation\n";
                printPokemon(pokes, lineCounter);
            }
            if (choice == 2) {
                cout << "Pick Parameter\n";
                cout << "1. Caught\n";
                cout << "2. Generation\n";
                cout << "3. Type\n";
                int sortChoice = 0;
                if (choice == 1) {
                    sortByCaught(pokes,lineCounter);
                    cout << "Sort Complete!\n";
                }
                else if (sortChoice == 2) {
                    cout << "Enter Generation Number: \n";
                    int genNo;
                    cin >> genNo;
                    if ((choice >= 1) && (choice <= 9)) {
                        sortByGeneration(pokes,lineCounter,genNo);
                        cout << "Sorting for Generation " << genNo << " Pokemon...\n";
                    }
                    else {
                        cout << "Invalid Number\n";
                    }
                }
                else if (sortChoice == 3) {
                    string type1;
                    string type2;
                    cout << "Enter Type 1\n";
                    cin >> type1;
                    cout << "Enter Type 2\n";
                    cin >> type2;
                    sortByType(pokes, type1, type2, lineCounter);
                }
                else {
                    cout << "Invalid Choice\n";
                }
            }
            if (choice == 3) {
                cout << "Enter Name:\n";
                string name;
                cin >> name;
                changeCaught(pokes, name, lineCounter);
            }
            if (choice == 4) {
                cout << "Welcome to the Teambuilder!\n";
                cout << "1. Add Pokemon\n";
                cout << "2. Clear Team\n";
                cout << "3. Save Team\n";
                cout << "4. Print Team\n"
                cout << "0. Exit\n";
                int teamChoice = -1;
                do {
                    if ((teamChoice <= 0)||(teamChoice <= 4)) {
                        if (teamChoice == 1) {
                            //make two functions to handle if no nodes vs some nodes
                        }
                        if (teamChoice == 2) {
                            //deleteAllMembers();
                        }
                        if (teamChoice == 3) {
                            bool success = true;//writeTeamOut("team.txt", );
                            if (success){
                                cout << "Write Complete under team.txt\n";
                            }
                            else {
                                cout << "Error\n";
                            }
                        }
                        if (teamChoice == 0) {
                            cout << "Exiting...\n";
                        }
                    }
                } while (choice != 0);
            }
            if (choice == 5) {
                
            }
            if (choice == 6) {
                cout << percentCaught(pokes, lineCounter) << " Percent Caught!\n";
                gradeMessage(percentCaught(pokes, lineCounter));
            }
            if (choice == 0) {
                cout << "Exiting...\n";
            }
        }
        else {
            cout << "Invalid Choice\n";
        }

    } while (choice != 0);
    delete[] pokes; // delete allocated memory
    pokes = nullptr; // reset the pointer to nothing
    return 0;
}
