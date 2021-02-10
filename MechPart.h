//Course: SENG1120
//Coded by: Alex Mendes

#ifndef MECHPART_H
#define MECHPART_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class MechPart
{
public:

    // Constructors
    MechPart();
    MechPart(const string, const int);

    // Destructor
    ~MechPart();

    // Setters
    void set_code(const string);
    void set_quantity(const int);

    // Getters
    string get_code() const;
    int get_quantity() const;

//Private member variables
private:
    string code; // mechanical part name
    int quantity; // amount in inventory
};
ostream& operator <<(ostream&, const MechPart&);

bool operator == (const MechPart& s1, const MechPart& s2);
bool operator < (const MechPart& s1, const MechPart& s2);
bool operator >(const MechPart& s1, const MechPart& s2);

#endif