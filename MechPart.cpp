//Course: SENG1120
//Coded by: Alex Mendes

#include "MechPart.h"
#include <cstdlib>

// Constructors
MechPart::MechPart()
{
    code = "";
    quantity = 0;
}

MechPart::MechPart(string code_, int quantity_)
{
    code = code_;
    quantity = quantity_;
}

// empty destructor
MechPart::~MechPart(){}

// Mutator methods (setters)
void MechPart::set_code(const string code_) {code = code_;}
void MechPart::set_quantity(const int quantity_){ quantity = quantity_;}

// Accessor methods (getters)
string MechPart::get_code() const {return code;}
int MechPart::get_quantity() const {return quantity;}

// overloaded ostream operator
ostream& operator <<(ostream& out, const MechPart& value)
{
    out << "(" << value.get_code() << "," << value.get_quantity() << ") ";
    return out;
}

// overloaded == operator
bool operator == (const MechPart& s1, const MechPart& s2)
{
    if (s1.get_code() == s2.get_code())
        return true;
    else
        return false;
}

// overloaded < operator
bool operator < (const MechPart& s1, const MechPart& s2)
{
    if (s1.get_code() < s2.get_code())
        return true;
    else
        return false;
}

// overloaded > operator
bool operator > (const MechPart& s1, const MechPart& s2)
{
    if (s1.get_code() > s2.get_code())
        return true;
    else
        return false;
}
