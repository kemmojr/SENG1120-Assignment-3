/*
Created by Timothy Kemmis
student no: c3329386
course: SENG1120
Assignment3
*/

#ifndef ASSIGNMENT3_BSTREE_H
#define ASSIGNMENT3_BSTREE_H

#include <cmath>
#include <sstream>
#include <iostream>
#include <string>
#include "BTNode.h"

template <typename value_type>
class BSTree{

public:
    //BSTree constructor
    //The value type being used exists
    BSTree();
    //An empty BSTree is created

    //BSTree destructor
    //A BSTree exists
    ~BSTree();
    //The BSTree is removed from memory

    //An adding method for crating a new node with data value_type p
    //value_type p exists
    void add(value_type p);
    //A new node is created with data of value_type p

    //A removing method for removing a node with data value_type p
    //a Node  with data value_type p exists
    void remove(value_type p);
    //A node with data of value_type p is removed

    //A function for getting how many types of parts there are
    //A BSTree exists
    int calculateParts() const;
    //An int is returned corresponding to the amount of different parts there are which is stored in the size variable

    //A helper function which calls a recursive function to calculate the amount of parts plus their quantity
    //A BSTree exists
    int calculateInventory();
    //An int value is returned corresponding to the total quantities of all parts


    //A print helper function which calls a private print function
    //A BSTree exists
    void print(std::ostream &out);
    //returns a string containing the data of the BSTree


private:

    //Remove tree recursively
    //A BSTree exists
    void removeBSTree(BTNode<value_type>* node);
    //All the data of a BSTree is recursively removed

    //A function for finding a node with a given value_type
    //A BSTree exists
    BTNode<value_type>* find(BTNode<value_type>* crnt, value_type target);
    //The node containing the given valuetype is returned if it exists. Otherwise NULL is returned

    //A recursive function that traverses the tree and adds the quantity of each part to the inventory size
    //A BSTree exists
    void getInventory(BTNode<value_type>* node);
    //An int corresponding to the total quantities of all parts is returned

    //A print helper function which creates a string containing the data of the BSTree
    //A BSTree exists
    void print1(BTNode<value_type>* node, std::ostream& out);
    //a string containing the data of the BSTree has been created

    //A method for setting current to the root BTNode
    //A root node exists
    void setCurrentToRoot();
    //The current is the root

    //A method for getting the current BTNode
    //A BSTree exists exists
    BTNode<value_type>* getCurrent() const;
    //The root node is returned

    //A member variable for storing the root of the tree
    BTNode<value_type>* root;

    //A member variable for storing the root of the tree
    BTNode<value_type>* current;

    //A member for storing the last move that was made in the tree traversal
    std::string lastMove;

    //A member variable for measuring the size of the BSTree
    int size;

    //A member variable for storing the size of all the quantities of the mechparts
    int inventorySize;

};

//An overloaded << operator for printing BSTrees
//A BSTree exists
template <typename value_type>
std::ostream& operator <<(std::ostream& out, BSTree<value_type>& value);
//A formatted string containing the contents of the BSTree is returned

#endif //ASSIGNMENT3_BSTREE_H

//Template implementation for the BSTree class
//Constructor
template <typename value_type>
BSTree<value_type>::BSTree() {
    root = NULL;
    size = 0;
}

//A descructor which calls a recursive function to remove the BSTree from memory
template <typename value_type>
BSTree<value_type>::~BSTree() {
    removeBSTree(root);
}

//A private recursive helper function to remove the BSTree from memory
template <typename value_type>
void BSTree<value_type>::removeBSTree(BTNode<value_type> *node) {
    if (node == NULL){
        return;
    }
    removeBSTree(node->getLeftChild());
    removeBSTree(node->getRightChild());
	delete node;
}

//A private find function which returns a BTNode with the value_type or NULL if the node doesn't exist
template <typename value_type>
BTNode<value_type>* BSTree<value_type>::find(BTNode<value_type>* crnt, value_type target) {
    if (crnt==NULL){
        return NULL;
    } else if (crnt->getData()==target){
        current = crnt;
        return crnt;
    } else if (crnt->getLeftChild()==NULL && crnt->getRightChild()==NULL){
        return NULL;
    } else if (target<crnt->getData()){
        current = crnt;
        return find(crnt->getLeftChild(), target);
    } else if (target>crnt->getData()){
        current = crnt;
        return find(crnt->getRightChild(), target);
    }
}

//An adding function which finds the position where the new node needs to be added and adds it there, reassigning the pointers as necessary
template <typename value_type>
void BSTree<value_type>::add(value_type p) {
    //int qnty;

    if (size == 0) {
        BTNode<value_type> *node = new BTNode<value_type>(p);
        node->setLeftChild(NULL);
        node->setRightChild(NULL);
        node->setRightChild(NULL);
        root = node;
        size++;
    } else {
        BTNode<value_type> *adding = new BTNode<value_type>(p);
        BTNode<value_type> *temp = root;
        while (true) {
            if ((p < temp->getData() && temp->getLeftChild() == NULL) || (p > temp->getData() && temp->getRightChild() == NULL)) {//If the inseting data is less than the node and there is no leftchild or the same for being larger and no rightchild
                //temp->getLeftChild()->getData()==NULL&&temp->getRightChild()==NULL
                if (p < temp->getData() && temp->getLeftChild() == NULL) { //Insert as leftchild if avaliable
                    temp->setLeftChild(adding);
                    adding->setParent(temp);
                    adding->setLeftChild(NULL);
                    adding->setRightChild(NULL);
                } else { //Insert as rightchild if avaliable
                    temp->setRightChild(adding);
                    adding->setParent(temp);
                    adding->setLeftChild(NULL);
                    adding->setRightChild(NULL);
                }
                size++;
                break;
            } else if (p < temp->getData()) {
                temp = temp->getLeftChild();
            } else if (p > temp->getData()) {
                temp = temp->getRightChild();
            }
        }
    }
}

//A removing method for removing a node with data value_type p
template <typename value_type>
void BSTree<value_type>::remove(value_type p) {
    setCurrentToRoot();
    BTNode<value_type> *removing = find(getCurrent(), p);//, lChld, rChld, temp;
    BTNode<value_type> *rChld;
    BTNode<value_type> *lChld;
    BTNode<value_type> *temp;
    BTNode<value_type> *tempChld;
    bool tempHasChld = false;
    //BTNode<value_type>* prnt, lChld, rChld, temp;
    bool smallestFound = false;

    if (removing == NULL) {//The function returns and doesn't remove anything if the node does not exist
        return;
    }
    if (removing->getLeftChild() == NULL && removing->getRightChild() == NULL) {//Check to confirm if the node is a leaf
        if (removing == root) {
            root = NULL;
        } else if (removing->getParent()->getLeftChild() ==
                   removing) {//reassign the leftchild or rightchild values of the parent that the node is being removed from to NULL
            removing->getParent()->setLeftChild(NULL);
        } else if (removing->getParent()->getRightChild() == removing) {
            removing->getParent()->setRightChild(NULL);
        }

    } else if (removing->getRightChild() != NULL && removing->getLeftChild() != NULL) {//If the node being removed has a rightchild and a leftchild find the smallest child of the rightchild to replace the removed node
        rChld = removing->getRightChild();
        if (removing->getLeftChild() != NULL) {
            lChld = removing->getLeftChild();
        }
        temp = rChld;

        while (!smallestFound) {
            if (temp->getLeftChild() != NULL) {
                temp = temp->getLeftChild();
            } else {
                smallestFound = true;
            }
        }
        if (temp->getRightChild() != NULL) {
            tempChld = temp->getRightChild();
            tempChld->setParent(temp->getParent());
            temp->getParent()->setLeftChild(tempChld);
        } else if (temp!=rChld){
            temp->getParent()->setLeftChild(NULL);
        }

        //A check to determine if the node being removed is the root and reassign it's parent value
            if (removing == root) {
                temp->setParent(NULL);
                root = temp;
                temp->setLeftChild(removing->getLeftChild());
                temp->getLeftChild()->setParent(temp);

                if (temp!=rChld){
                temp->setRightChild(removing->getRightChild());
                temp->getRightChild()->setParent(temp);
                } else {
                    temp->setRightChild(NULL);
                }
            } else {
                temp->setParent(removing->getParent());
                temp->setLeftChild(removing->getLeftChild());
                temp->getLeftChild()->setParent(temp);

                if (temp != rChld) {
                temp->setRightChild(removing->getRightChild());
                temp->getRightChild()->setParent(temp);
            } else {
                    temp->setRightChild(NULL);
                }
                if (removing->getParent()->getLeftChild()->getData()==removing->getData()){
                    removing->getParent()->setLeftChild(temp);
                } else {
                    removing->getParent()->setRightChild(temp);
                }


            }

    } else {//The final case where the node being removed has only one child
        if(removing->getLeftChild() == NULL) {
            temp = removing->getRightChild();
        } else {
            temp = removing->getLeftChild();
        }

        if (removing == root) {
            temp->setParent(NULL);
            root = temp;
        } else {
            temp->setParent(removing->getParent());
            if (removing->getParent()->getLeftChild()==removing){
                removing->getParent()->setLeftChild(temp);
            } else {
                removing->getParent()->setRightChild(temp);
            }
        }
    }
    delete removing; //Run the destructor on the node after reassigning all the pointers of the nodes that have been moved
    size--;
}

//A function which calculates the total quantities of the parts by calling a recursive helper function
template <typename value_type>
int BSTree<value_type>::calculateInventory() {
    setCurrentToRoot();
    inventorySize = 0;
    getInventory(getCurrent());
    return inventorySize;
}

//A recursive helper function for calculating the total quantities of all the parts
template <typename value_type>
void BSTree<value_type>::getInventory(BTNode<value_type> *node){
    if (node == NULL){
        return;
    }
    getInventory(node->getLeftChild());
    inventorySize += node->getQuantity();
    getInventory(node->getRightChild());
}

//A function for returning the number of parts stored in the size variable
template <typename value_type>
int BSTree<value_type>::calculateParts() const{
    return size;
}

//a private recursive print function
template <typename value_type>
 void BSTree<value_type>::print1(BTNode<value_type> *node, std::ostream &out){
    if (node == NULL){
        return;
    }
    print1(node->getLeftChild(), out);
    out << node->getData();
    print1(node->getRightChild(),out);
}

//A helper print function that calls a private recursive print function
template <typename value_type>
void BSTree<value_type>::print(std::ostream &out){
    setCurrentToRoot();
    print1(getCurrent(),out);

}

//A method for setting current to the root BTNode
template <typename value_type>
void BSTree<value_type>::setCurrentToRoot() {
    current = root;
}

//A method for getting the current BTNode
template <typename value_type>
BTNode<value_type>* BSTree<value_type>::getCurrent() const{
    return current;
}

//An overloaded << operator for printing BSTrees
template <typename value_type>
std::ostream& operator <<(std::ostream& out, BSTree<value_type>& value){
    std::cout << "Before printing" << std::endl;
    value.print(out);
    return out;
}