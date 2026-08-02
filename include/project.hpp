#ifndef PROJECT_HPP
#define PROJECT_HPP
#include <string>;

const double A_MINIMUM = 90.0;
const double B_MINIMUM = 80.0;
const double C_MINIMUM = 70.0;
const double D_MINIMUM = 60.0;
const int GEN_1_NUMBER = 151;

struct Pokemon {
    string type1;
    string type2;
    int dexNum;
    int gen;
    bool caught;
};


struct teamMember {
    Pokemon poke;
    teamMember* next;
};

#endif