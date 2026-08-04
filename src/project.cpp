#include <iostream>
#include <fstream>
#include <ostream>
#include "project.hpp"

using namespace std;


// function to put everything in the file in an array

// function to sort pokemon by name
// function that sorts/filters by generation
// filter by type
// boolean to alter caught/not
// percentage completion
// filter by caught/uncaught 
// choice validator
// input validator

//returns number loaded and stores
bool isValidChoice (int choice) {
    if ((choice >= FIRST_CHOICE) && (choice <= LAST_CHOICE)) {
        return true;
    }
    return false;
}
int findPokemon (Pokemon pokes[], string name, int pokeNo) { //return index of pokemon
    for (int i = 0; i < pokeNo; i ++) {
        if (pokes[i].name == name) {
            return i;
        }
    }
    return -1;
}
int createPokemonList(string filename, Pokemon pokes[], int pokeNo) {
    if (pokes == nullptr) {
        cout << "File Not Found: nullptr in input\n";
        return 0;
    }

    ifstream in(filename);

    if (!in.is_open()) {
        return 0;
    }

    int count = 0;
    Pokemon poke;

    while (count < pokeNo && in >> poke.name >> poke.type1 >> poke.type2 >> poke.dexNum >> poke.gen) {
            poke.caught = false;
            pokes[count] = poke;
            count++;
    }

    in.close();

    return count;
}

void sortByGeneration(Pokemon pokes[], int pokeNo, int genNo) {
    int index = 0;
    int count = 0;
    while (index <= pokeNo) { //first, order by generation number
        for (int i = 0; i < pokeNo; i ++) { // look through everything
            if (pokes[i].gen == genNo) { // if it matches numbers
                count ++;
                Pokemon temp = pokes[index];
                pokes[index] = pokes[i];
                pokes[i] = temp;
                
            }
        }
        index ++;
    }
    cout << "Generation Sort Complete! Sorting by Dex Number...\n";
    for (int i = 0; i < count; i ++) {
        for (int j = 0; j < count; j ++) {
            if (pokes[j].dexNum < pokes[i].dexNum) {
                Pokemon temp = pokes[j];
                pokes[j] = pokes[i];
                pokes[i] = temp;
            }
        }
    }
    cout << "Sort Complete!\n";

}

void sortByType(Pokemon pokes[], string type1, string type2, int pokeNo) {
    int index = 0;
    int count = 0;
    while (index <= pokeNo) { //first, order by generation number
        for (int i = 0; i < pokeNo; i ++) { // look through everything
            if ((pokes[i].type1 == type1) && (pokes[i].type2 == type2)) { // if it matches numbers
                count ++;
                Pokemon temp = pokes[index];
                pokes[index] = pokes[i];
                pokes[i] = temp;
                
            }
        }
        index ++;   
    }
    cout << "Matches Sorted to Front!\n";
}

void sortByCaught (Pokemon pokes[], int pokeNo) {
    int index = 0;
    int count = 0;
    while (index <= pokeNo) { 
        for (int i = 0; i < pokeNo; i ++) { 
            if (pokes[i].caught) { 
                count ++;
                Pokemon temp = pokes[index];
                pokes[index] = pokes[i];
                pokes[i] = temp;
            }
        }
        
    }
}
void changeCaught(Pokemon pokes[], string name, int pokeNo) {
    for (int i = 0; i < pokeNo; i ++) {
        if (pokes[i].name == name) {
            if (pokes[i].caught == true) {
                pokes[i].caught = false;   
                cout << name << " marked uncaught\n";
                break;
            }
            else
            {
                pokes[i].caught = true;
                cout << name << " marked caught\n";
                break;
            }
        }
    }
    cout << name << " not found\n";
}

double percentCaught (Pokemon pokes[], int pokeNo) {
    double caughtCount = 0;
    for (int i = 0; i < pokeNo; i ++) {
        if (pokes[i].caught) {
            caughtCount ++;
        }
    }
    return (pokeNo/caughtCount) * 100.0;
}

void createTeamMember(string name, teamMember*& head) {
    teamMember* team = new teamMember;
    team->name = name;
    team->next = head;
    head = team;
}
int deleteMember(teamMember*& head, string name) {
     teamMember* previous = nullptr;
     teamMember* current = head;
        int count = 0;
        while (current != nullptr) {
            if (current->name == name) {
                teamMember* temp = current;
                if (previous == nullptr) {
                    head = current->next;
                    current = head;
                }
                else {
                    previous->next = current-> next;
                    current = current->next;
                }
                delete temp;
                count ++;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
    return count;
}
int deleteAllMembers(teamMember*& head) {
    int count = 0;
    while (head != nullptr) {
        teamMember* node = new teamMember;
        node = head->next;
        delete head;
        head = node;
        count ++;
    }
    return count;
}
void printPokemon(Pokemon pokes[], int pokeNo) {
    for (int i = 0; i < pokeNo; i ++) {
        Pokemon poke = pokes[i];
        cout << poke.name << " " << poke.type1 << " " << poke.type2 << " " << poke.dexNum << " " << poke.gen << "\n";
    }
}
void writeReport(Pokemon pokes[], int pokeNo, string filename) {
    double percent = percentCaught(pokes, pokeNo);
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Report Write Failed\n";
    }
    outFile << percent << " percent caught.";
    outFile << "Name Type1 Type2 DexNumber Generation\n";
    for (int i = 0; i < pokeNo; i ++) {
        Pokemon poke = pokes[i];
        outFile << poke.name << " " << poke.type1 << " " << poke.type2 << " " << poke.dexNum << " " << poke.gen << "\n";
    }
    outFile.close();
    cout << "Write Complete";

    
}
int gradeMessage(double percent) {
    if (percent == 100) {
        cout << "You are a true Pokemon Master!\n";
        return 0;
    }
    else if (percent >= A_MINIMUM) {
        cout << "Grade A: So close!\n";
        return 1;
    }
    else if (percent >= B_MINIMUM) {
        cout << "Grade B: Great job so far!\n";
        return 2;
    }
    else if (percent >= C_MINIMUM) {
        cout << "Grade C: Getting close to all of em!\n";
        return 3;
    }
    else if (percent >= D_MINIMUM) {
        cout << "Grade D: Doing better!\n";
        return 4;
    }
    else {
        cout << "Grade F: Try Harder\n";
        return 5;
    }
}
bool writeTeamOut(string filename, teamMember* head) {
    ofstream out(filename);
    if (!out.is_open()) {
        return false;
    }
    if (head == nullptr) {
        cout << "No teams built\n";
        return false;
    }
    if (!out.is_open()) {
        return false;
    }
    while (head != nullptr) {
        out << head->name;
        head = head->next;
    }
    out.close();
    return true;
}

void savePokemonToFile(Pokemon pokes[], int pokeNo) {
    string filename;
    cout << "Enter filename to save to: \n";
    cin >> filename;
    ofstream pokeFile(filename);
    if (!pokeFile.is_open()) {
        cout << "Failed to save\n";
        return;
    }
    pokeFile << "Name Type1 Type2 DexNumber Generation\n";
    for (int i = 0; i < pokeNo; i ++) {
        Pokemon poke = pokes[i];
        pokeFile << poke.name << " " << poke.type1 << " " << poke.type2 << " " << poke.dexNum << " " << poke.gen << "\n";
    }
    cout << "Write Complete\n";
    pokeFile.close();


}

//Unit 1
    // assigns grade/ output based on percent completed
//unit 2
    // validity of choices
//unit 3
    // sets and get specific mons
//unit 4
    // sorts
//unit 5
    // get data from a pokemon structure
//unit 6
    // Teambuilder Test
//unit 7
    // print team to file, print collected to file