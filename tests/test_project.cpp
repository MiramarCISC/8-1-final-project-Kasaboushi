#include "project.hpp"
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool nearlyEqual(double actual, double expected, double tolerance = 0.0001) {
    return fabs(actual - expected) <= tolerance;
}

Pokemon* setupPokes() {
    string filename = "pokemon.txt";
    int lineCounter = 0;
    string line;
    ifstream pokefile(filename);

    if (!pokefile.is_open()) {
        cout << "Failed to Open\n";
    }
    while (getline(pokefile, line)) {
        lineCounter ++;
    }
    pokefile.close();
    Pokemon* pokes = new Pokemon[lineCounter]; // now automatically create the list
    teamMember* head = nullptr;
    int loaded = createPokemonList(filename, pokes, lineCounter);
    return pokes;
}

// Week 1: Program Basics
void testWeek1ProgramBasics() {
    assert(gradeMessage(100) == 0);
    assert(gradeMessage(90) == 1);
    assert(gradeMessage(80) == 2);
    assert(gradeMessage(70) == 3);
    assert(gradeMessage(60) == 4);
    assert(gradeMessage(20) == 5);
}

// Week 2: Decisions and Loops
void testWeek2DecisionsAndLoops() {
    assert(isValidChoice(0) == true);
    assert(isValidChoice(-1) == false);
    assert(isValidChoice(15) == false);
    assert(isValidChoice(5) == true);
    assert(isValidChoice(2) == true);
}

// Week 3: Functions and Program Design
void testWeek3FunctionsAndProgramDesign() {
    Pokemon *pokes = setupPokes();
    assert(nearlyEqual(percentCaught(pokes,4),0.0));
    changeCaught(pokes, "Charmander", 4);
    assert(nearlyEqual(percentCaught(pokes,4),25));
    
}

// Week 4: Arrays, Searching, and Sorting
void testWeek4ArraysSearchingSorting() {
    Pokemon *pokes = setupPokes();
    assert(findPokemon(pokes, "Cyndaquil", 4) == 3);
    assert(findPokemon(pokes, "Charmander", 4) == 0);

}

// Week 5: Strings and Structures
void testWeek5StringsAndStructures() {
    Pokemon test = {"Sunflora", "Grass", "none", 192, 2, false};
    assert(test.name == "Sunflora");
    assert(test.type1 == "Grass");
    assert(test.type2 == "none");
    assert(test.dexNum == 192);
    assert(test.gen == 2);
    assert(test.caught == false);
}

// Week 6: Simple Linked Task List
void testWeek6SimpleLinkedTaskList() {

    teamMember* start = nullptr;
    createTeamMember("Excadrill",start);
    createTeamMember("Chandelure",start);
    createTeamMember("Beartic",start);
    assert(deleteAllMembers(start) == 3);
}

// Week 7: File-Based Inventory Report
void testWeek7FileBasedInventoryReport() {
    ifstream pokeFile("pokemon.txt");
    assert(pokeFile.is_open());
    Pokemon pokes[4];
    assert(createPokemonList("pokemon.txt",pokes,4) == 4);


}

int main() {
    testWeek1ProgramBasics();
    testWeek2DecisionsAndLoops();
    testWeek3FunctionsAndProgramDesign();
    testWeek4ArraysSearchingSorting();
    testWeek5StringsAndStructures();
    testWeek6SimpleLinkedTaskList();
    testWeek7FileBasedInventoryReport();

    cout << "All corrected final project template tests passed!" << endl;
    return 0;
}
