/*
Created by Timothy Kemmis
student no: c3329386
course: SENG1120
Assignment3
*/

#ifndef ASSIGNMENT3_BTNODE_H
#define ASSIGNMENT3_BTNODE_H

#include <cmath>
#include <iostream>
#include <string>

template <typename value_type>
class BTNode{

public:
    //The student class is added to value_type
    //typedef std::string value_type;

    //Constructors
    //No precondition
    BTNode();
    //A blank node is created

    //The value_type data exists
    BTNode(const value_type data);
    //A node with data is created


    //Destructor
    //A BTNode exists
    ~BTNode();
    //BTNode is removed from memory

    //Setters
    //Sets the setLeftChild pointer of a BTNode
    //BTNode exists
    void setLeftChild(BTNode<value_type>* n);
    //BTNode n is set to leftChild

    //Sets the setRightChild pointer of a BTNode
    //BTNode exists
    void setRightChild(BTNode<value_type>* n);
    //BTNode n is set to rightChild

    //Sets the setParent pointer of a BTNode
    //BTNode exists
    void setParent(BTNode<value_type>* n);
    //BTNode n is set to setParent

    //Sets the data of the BTNode
    //Value_type data exists
    void setData(const value_type s);
    //The value_type data is added to BTNode

    //Getters
    //Gets the leftChild pointer of a BTNode
    //leftChild exists
    BTNode<value_type>* getLeftChild() const;
    //leftChild pointer is returned

    //Gets the rightChild pointer of a BTNode
    //rightChild exists
    BTNode<value_type>* getRightChild() const;
    //rightChild pointer is returned

    //Gets the parent pointer of a BTNode
    //parent exists
    BTNode<value_type>* getParent() const;
    //parent pointer is returned

    //Gets the data of the BTNode
    //BTNode with data exists
    value_type getData();
    //Data of BTNode returned

    //Gets the quantity of mechpart
    int getQuantity();



private:



    //A pointer for the leftchild of BTNode
    BTNode<value_type>* leftChild;

    //A pointer for the the rightchild BTNode
    BTNode<value_type>* rightChild;

    //A pointer for the parent of BTNode
    BTNode<value_type>* parent;

    //A value_type data type
    value_type data;



};

//overloads the << operator for outputting BTNode's
template <typename value_type>
std::ostream& operator <<(std::ostream& out, const BTNode<value_type>& value);



#endif //ASSIGNMENT3_BTNODE_H


//BTNode constructor creates an empty BTNode
template <typename value_type>
BTNode<value_type>::BTNode(){
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
}

//A BTNode constructor that creates a BTNode with d data
template <typename value_type>
BTNode<value_type>::BTNode(const value_type d){
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
    data = d;
}

//BTNode destructor
template <typename value_type>
BTNode<value_type>::~BTNode(){
    //destructor code
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
}

//Set the leftChild pointer of BTNode to BTNode n
template <typename value_type>
void BTNode<value_type>::setLeftChild(BTNode<value_type> *n){
    leftChild = n;
}

//Set the rightChild pointer of BTNode to BTNode n
template <typename value_type>
void BTNode<value_type>::setRightChild(BTNode<value_type> *n){
    rightChild = n;
}

//Set the parent pointer of BTNode to BTNode n
template <typename value_type>
void BTNode<value_type>::setParent(BTNode<value_type> *n){
    parent = n;
}

//Returns the leftChild pointer of a BTNode
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getLeftChild() const {
    return leftChild;
}

//Returns the rightChild pointer of a BTNode
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getRightChild() const {
    return rightChild;
}

//Returns the leftChild pointer of a BTNode
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::getParent() const {
    return parent;
}

//Set the data to s
template <typename value_type>
void BTNode<value_type>::setData(const value_type s){
    data = s;
}

//Get the data of BTNode
template <typename value_type>
value_type BTNode<value_type>::getData(){
    return data;
}

//Gets the quantity of the mechpart
template <typename value_type>
int BTNode<value_type>::getQuantity() {
    return data.get_quantity();
}

//overloads the << operator for outputting BTNode's
template <typename value_type>
std::ostream& operator <<(std::ostream& out, const BTNode<value_type>& value){
    return out << "BTNode:::" << value.getData() ;
}