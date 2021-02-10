/*
Created by Timothy Kemmis
student no: c3329386
course: SENG1120
Assignment3
*/

#ifndef ASSIGNMENT3_HTABLE_H
#define ASSIGNMENT3_HTABLE_H

#include <cmath>
#include <sstream>
#include <iostream>
#include <string>
#include "MechPart.h"

template <typename value_type>
class HTable{
public:
    //HTable constructor
    //The value type being used exists
    HTable();
    //An empty HTable is created

    //A destructor for HTable
    //A HTable exists
    ~HTable();
    //The HTable has been removed from memory

    //An adding method for crating a new HTable entry with data value_type p
    //value_type p exists
    void add(const value_type &p);
    //A new HTable entry is created with data of value_type p

    //A removing method for removing a HTable entry with data value_type p
    //a HTable entry  with data value_type p exists
    void remove(const value_type p);
    //A node with data of value_type p is removed

    //A function for getting how many types of parts there are
    //A HTable exists
    int calculateParts() const;
    //The parts member variable is returned which is the total number of all the different parts

    //A function to calculate the amount of parts plus their quantity
    //A HTable exists
    int calculateInventory();
    //An int corresponding to the total quantities of all parts is returned

    //A print helper function which modifies an ostream variable which is used by the overloaded << operator
    //A HTable exists
    void print(std::ostream &out) const;
    //The out variable contains all of the data of the HTable

private:

    //A hashing function which returns an int hash-value using the given hashing algorithm
    //The value_type value exists
    int hashfun(const value_type& value);
    //An int hash-value is returned

    //A member variable for storing the size of the HTable array
    //No preconditions
    const static int TABLE_SIZE = 5000;
    //A static const int variable of 5000 is created

    //An array member variable of type value_type for storing the mechparts in the hash table
    value_type data[TABLE_SIZE];

    //A variable for storing the number of different parts there are
    int parts;

    //A member variable for storing the size of all the quantities of the mechparts
    int inventorySize;


};

//An overloaded << operator for printing HTables
//A HTable exists
template <typename value_type>
std::ostream& operator <<(std::ostream& out, HTable<value_type>& value);
//A formatted string containing the formatted data of the HTable is returned

#endif //ASSIGNMENT3_HTABLE_H

//HTable constructor
template <typename value_type>
HTable<value_type>::HTable() {
    parts = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        data[i] = value_type();
    }

}

//A destructor for HTable
template <typename value_type>
HTable<value_type>::~HTable() {
    parts = NULL;

    for (int i = 0; i < TABLE_SIZE; i++) {
        data[i].set_code("");
        data[i].set_quantity(NULL);
    }
}

//An adding method for crating a new HTable entry with data value_type p
template <typename value_type>
void HTable<value_type>::add(const value_type &p) {
    int hashValue = hashfun(p);
    data[hashValue] = p;
    parts++;
}

//A removing method for removing a HTable entry with data value_type p
template <typename value_type>
void HTable<value_type>::remove(const value_type p) {
    int hashValue = hashfun(p);
    if (data[hashValue]==value_type()){
        return;
    }
    data[hashValue].set_code("");
    data[hashValue].set_quantity(NULL);
    parts--;
}

//A hashing function which returns an int hash-value using the given hashing algorithm
template <typename value_type>
int HTable<value_type>::hashfun(const value_type &value){
    int position = 0;
    string temp = value.get_code();
    for (int i=0; i<(int)temp.length(); i++)
    {
        position += (i+1) * (i+1) * temp.at(i);
    }
    return position % TABLE_SIZE;
}

//A print helper function which modifies an ostream variable which is used by the overloaded << operator
template <typename value_type>
void HTable<value_type>::print(std::ostream &out) const{
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!(data[i]==value_type())){
           out << data[i];
        }
    }
}

//A function for getting how many types of parts there are
template <typename value_type>
int HTable<value_type>::calculateParts() const{
    return parts;
}

//A function to calculate the amount of parts plus their quantity
template <typename value_type>
int HTable<value_type>::calculateInventory(){
    inventorySize = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!(data[i]==value_type())){
            inventorySize += data[i].get_quantity();
        }
    }
    return inventorySize;
}

//An overloaded << operator for printing HTables
template <typename value_type>
std::ostream& operator <<(std::ostream& out, HTable<value_type>& value){

    value.print(out);
    return out;
}