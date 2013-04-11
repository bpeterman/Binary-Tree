#include <iostream>
#include <stdexcept>
#include <string>
#include "tree_list_tpt.h"

using namespace std;

int main(void)
{
  cout << "TESTING BINARY SEARCH TREE METHODS" << endl;
	tree<string> t;
	
	// test SMALLEST
	cout << "\nTESTING SMALLEST METHOD" << endl;
	
	try {
		t.smallest();
		cout << "\tSMALLEST for empty tree does NOT throw domain error exception. (INCORRECT)" << endl;
	}
	catch (domain_error &de) {
		cout << "\tSMALLEST for empty tree throws domain error exception. (CORRECT)" << endl;
	}
	cout << "\tBuilding test tree." << endl;
	t.insert("40");
	t.insert("50");
	t.insert("45");
	t.insert("60");
	t.insert("55");
	t.insert("47");
	t.insert("30");
	t.insert("35");
	t.insert("32");
	t.pre_print();
	cout << endl;
	if (t.smallest() == "30")
		cout << "\tSmallest element of tree == \"30\". (CORRECT)" << endl;
	else
		cout << "\tSmallest element of tree != \"30\". (INCORRECT)" << endl;
	
	
	// test LARGEST
	cout << "\nTESTING LARGEST METHOD" << endl;
	t.~tree();
	tree<string> t;
	
	try {
		t.largest();
		cout << "\tLARGEST for empty tree does NOT throw domain error exception. (INCORRECT)" << endl;
	}
	catch (domain_error &de) {
		cout << "\tLARGEST for empty tree throws domain error exception. (CORRECT)" << endl;
	}
	cout << "\tBuilding test tree." << endl;
	t.insert("40");
	t.insert("50");
	t.insert("45");
	t.insert("60");
	t.insert("55");
	t.insert("47");
	t.insert("30");
	t.insert("35");
	t.insert("32");
	t.pre_print();
	cout << endl;
	if (t.largest() == "60")
		cout << "\tLargest element of tree == \"60\". (CORRECT)" << endl;
	else
		cout << "\tLargest element of tree != \"60\". (INCORRECT)" << endl;
		
	// test IN_SUM
	cout << "\nTESTING IN_SUM METHOD" << endl;
	t.~tree();
	tree<string> t;
	
	if (t.sum() == "")
		cout << "\tIn-order Sum of empty tree of strings is empty string. (CORRECT)" << endl;
	else
		cout << "\tIn-order Sum of empty tree of strings is NOT empty string. (INCORRECT)" << endl;
	cout << "\tBuilding test tree." << endl;
	t.insert("40");
	t.insert("50");
	t.insert("45");
	t.insert("60");
	t.insert("55");
	t.insert("47");
	t.insert("30");
	t.insert("35");
	t.insert("32");
	if (t.sum() == "303235404547505560")
		cout << "\tIn-order Sum of tree of strings == \"303235404547505560\". (CORRECT)" << endl;
	else
		cout << "\tIn-order Sum of tree of strings != \"303235404547505560\". (INCORRECT)" << endl;
	
	// test POST_SUM
	cout << "\nTESTING POST_SUM METHOD" << endl;
	t.~tree();
	tree<string> t;
	
	if (t.sum() == "")
		cout << "\tPost-order Sum of empty tree of strings is empty string. (CORRECT)" << endl;
	else
		cout << "\tPost-order Sum of empty tree of strings is NOT empty string. (INCORRECT)" << endl;
	cout << "\tBuilding test tree." << endl;
	t.insert("40");
	t.insert("50");
	t.insert("45");
	t.insert("60");
	t.insert("55");
	t.insert("47");
	t.insert("30");
	t.insert("35");
	t.insert("32");
	if (t.sum() == "323530474555605040")
		cout << "\tPost-order Sum of tree of strings == \"323530474555605040\". (CORRECT)" << endl;
	else
		cout << "\tPost-order Sum of tree of strings != \"323530474555605040\". (INCORRECT)" << endl;
	
	// test copy constructor
	cout << "\nTESTING COPY CONSTRUCTOR" << endl;
	t.~tree();
	tree<string> t;
	t.insert("40");
	t.insert("50");
	t.insert("30");
	
	tree<string> t2 = t;
	t.insert("20");
	t2.insert("60");
	if ((t.smallest() == "20") && t.contains("40") && t.contains("30") && t.contains("50") && !t.contains("60") &&
		(t2.largest() == "60") && t2.contains("40") && t2.contains("30") && t2.contains("50") && !t2.contains("20"))
		cout << "Copy constructor corrrectly made tree t2 from tree t. (CORRECT)" << endl;
	else
		cout << "Copy constructor incorrrectly made tree t2 from tree t. (INCORRECT)" << endl;
	
	// test assignment operator
	cout << "\nTESTING ASSIGNMENT OPERATOR" << endl;
	t.~tree();
	tree<string> t;
	t.insert("40");
	t.insert("50");
	t.insert("30");
	
	tree<string> t3;
	t3 = t;
	t.insert("20");
	t3.insert("60");
	if ((t.smallest() == "20") && t.contains("40") && t.contains("30") && t.contains("50") && !t.contains("60") &&
		(t3.largest() == "60") && t3.contains("40") && t3.contains("30") && t3.contains("50") && !t3.contains("20"))
		cout << "Copy constructor corrrectly made tree t3 from tree t. (CORRECT)" << endl;
	else
		cout << "Copy constructor incorrrectly made tree t3 from tree t. (INCORRECT)" << endl;	
	
	system("pause");
}
