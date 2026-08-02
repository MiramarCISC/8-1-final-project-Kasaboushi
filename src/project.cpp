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

// choice validator
// input validator
//returns number loaded and stores
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

    while (count < pokeNo)
           in >> poke.name >> poke.type1 >> poke.type2 >> poke.dexNum >> poke.gen >> poke.caught) {
        if (isValidQuantity(item.quantity) && isValidPrice(item.price)) {
            items[count] = item;
            count++;
        }
    }

    in.close();

    return count;
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