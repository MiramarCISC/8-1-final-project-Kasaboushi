#ifndef PROJECT_HPP
#define PROJECT_HPP
#include <string>

using namespace std;

const double A_MINIMUM = 90.0;
const double B_MINIMUM = 80.0;
const double C_MINIMUM = 70.0;
const double D_MINIMUM = 60.0;
const int GEN_1_NUMBER = 151;

const int FIRST_CHOICE = 0;
const int LAST_CHOICE = 6;

struct Pokemon {
    string name;
    string type1;
    string type2;
    int dexNum;
    int gen;
    bool caught;
};


struct teamMember {
    string name;
    teamMember* next;
};

int createPokemonList(string filename, Pokemon pokes[], int pokeNo);
bool isValidChoice(int choice);
int findPokemon (Pokemon pokes[], string name, int pokeNo);
void sortByGeneration(Pokemon pokes[], int pokeNo, int genNo);
void sortByType(Pokemon pokes[], string type1, string type2, int pokeNo);
void sortByCaught (Pokemon pokes[], int pokeNo);
void changeCaught(Pokemon pokes[], string name, int pokeNo);
double percentCaught (Pokemon pokes[], int pokeNo);
void createTeamMember(string name, teamMember*& head);
int deleteMember(teamMember*& head, string name);
int deleteAllMembers(teamMember*& head);
void printPokemon(Pokemon pokes[], int pokeNo);
int gradeMessage(double percent);
bool writeTeamOut(string filename, teamMember* head);
void writeReport(Pokemon pokes[], int pokeNo, string filename)



#endif