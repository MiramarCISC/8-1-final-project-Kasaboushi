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
        cout << "File Not Found: nullptr in input";
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
    cout << "Generation Sort Complete! Sorting by Dex Number...";
    for (int i = 0; i < count; i ++) {
        for (int j = 0; j < count; j ++) {
            if (pokes[j].dexNum < pokes[i].dexNum) {
                Pokemon temp = pokes[j];
                pokes[j] = pokes[i];
                pokes[i] = temp;
            }
        }
    }
    cout << "Sort Complete!";

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
    cout << "Matches Sorted to Front!";
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
            }
            else
            {
                pokes[i].caught == true;
            }
        }
        
    }
}

double percentCaught (Pokemon pokes[], int pokeNo) {
    double caughtCount = 0;
    for (int i = 0; i < pokeNo; i ++) {
        if (pokes[i].caught) {
            caughtCount ++;
        }
    }
    return (pokeNo/caughtCount) * 100;
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
        // if (poke.type2 == "none") {
        //     cout << poke.name << poke.type1 << poke.dexNum << poke.gen;
        // }
        // else {
            cout << poke.name << poke.type1 << poke.type2 << poke.dexNum << poke.gen;
        // }
        
    }
}
int gradeMessage(double percent) {
    if (percent == 100) {
        cout << "You are a true Pokemon Master!";
        return 0;
    }
    else if (percent >= A_MINIMUM) {
        cout << "Grade A: So close!";
        return 1;
    }
    else if (percent >= B_MINIMUM) {
        cout << "Grade B: Great job so far!";
        return 2;
    }
    else if (percent >= C_MINIMUM) {
        cout << "Grade C: Getting close to all of em!";
        return 3;
    }
    else if (percent >= D_MINIMUM) {
        cout << "Grade D: Doing better!";
        return 4;
    }
    else {
        cout << "Grade F: Try Harder";
        return 5;
    }
}
bool writeTeamOut(string filename, teamMember* head) {
    ofstream out(filename);
    if (head == nullptr) {
        cout << "No teams built";
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