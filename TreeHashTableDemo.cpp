//TreeHashTableDemo - Main Program
/******************************/
//Author: Alex Mendes
//Course: SENG1120
//Program Description: This program demonstrates the basic functionality of binary seach trees and hash tables. 

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <sstream> 
#include "BSTree.h"
#include "HTable.h"
#include "MechPart.h"
using namespace std;

int main()
{
	clock_t t;

	// if you are using class templates
	BSTree<MechPart> treeValues;
	HTable<MechPart> tableValues;
    MechPart part;

	// Reads data from input file and populates tree
	string line;
    ifstream myfileA ("inventory.txt");
    if (myfileA.is_open())
    {
		while ( getline (myfileA,line) )
		{
			stringstream tempSS, tempSS2;
			int tempInt;
			tempSS << line;
			string token;
			getline(tempSS, token, ' '); // get code
			part.set_code(token);
			getline(tempSS, token, ' '); // get quantity
			tempSS2 << token;  
			tempSS2 >> tempInt;
			part.set_quantity(tempInt);
			treeValues.add(part); // adds element to the tree
			tableValues.add(part); // adds element to the table
		}
	}
	cout << "Finished" << endl;

	string vectorCodes[] = {"VKTN-PE4M-74QL-JFQR", "NBPW-68T3-K6BB-GFUG", "MDN7-AJRJ-CKGD-AQKR", "57Q5-KRVS-SXMX-TCG9", "STX9-DX83-Y4E6-Y7QW", "JLP7-7SDH-JWU9-ZYDD", "9RYN-VW77-TQ53-RPVU", "AS8V-FW82-DA8C-UH62", "CENU-BRGU-ZGXN-9WP9", "J5JZ-WFMR-62YJ-XW7G", "HJ2W-M76T-P8EX-HNK3"};
	int vectorQuantities[] = {3, 63, 95, 25, 37, 11, 77, 5, 54, 53, 68};
			
	cout << "==================" << endl << "BINARY SEARCH TREE" << endl << "==================" << endl << endl;
	t = clock(); // gets current time
	cout << "Initial tree: " << treeValues << endl; // prints the contents of the tree.

	cout << endl << "Adding and removing..." << endl;
	for (int j=0; j<100000; j++)
	{
		for (int i=0; i<11; i++)
		{ // removes the 11 elements in the list. The first one is not present.
			part.set_code(vectorCodes[i]); part.set_quantity(vectorQuantities[i]);
			treeValues.remove(part);
		}

		for (int i=1; i<11; i++)
		{ // adds all elements removed back into the data structure.
			part.set_code(vectorCodes[i]); part.set_quantity(vectorQuantities[i]);
			treeValues.add(part);
		}
	}
	cout << endl << endl;
	//cout << "Final tree  : " << treeValues << endl << endl; // prints the contents of the tree.
	cout << "Time elapsed: " << (clock() - t)/1000.0 << " seconds" << endl; // prints elapsed time.
	cout << "Time per ins/del operation: " << 1000.0*(double)(clock() - t)/(double)(100000*21) << " milliseconds." << endl;
	cout << "There are " << treeValues.calculateParts() << " types of parts and " << treeValues.calculateInventory() << " parts in total." << endl << endl;

	cout << "==================" << endl << "HASH TABLE" << endl << "==================" << endl << endl;
	t = clock(); // gets current time
    cout << "Initial hash table: " << tableValues << endl; // prints the contents of the hash table.

	cout << endl << "Adding and removing..." << endl;
	for (int j=0; j<100000; j++)
	{

		for (int i=0; i<11; i++)
		{ // removes the 11 elements in the list. The first one is not present.
			part.set_code(vectorCodes[i]); part.set_quantity(vectorQuantities[i]);
			tableValues.remove(part);
		}

		for (int i=1; i<11; i++)
		{ // adds all elements removed back into the data structure.
			part.set_code(vectorCodes[i]); part.set_quantity(vectorQuantities[i]);
			tableValues.add(part);
		}
	}
	cout << endl << endl;
	//cout << "Final hash table  : " << tableValues << endl << endl; // prints the contents of the hash table.
    cout << "Time elapsed: " << (clock() - t)/1000.0 << " seconds" << endl; // prints elapsed time.
	cout << "Time per ins/del operation: " << 1000.0*(double)(clock() - t)/(double)(100000*21) << " milliseconds." << endl << endl;
	cout << "There are " << tableValues.calculateParts() << " types of parts and " << tableValues.calculateInventory() << " parts in total." << endl << endl;
	cout << "The program has finished." << endl;
	return 0;
}
