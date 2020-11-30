#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "List.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc!=2) {
        cout << " file number not match. Sorry!" << endl;
        return 1;
    }

    ifstream inFile;
  //  ofstream outFile;
    inFile.open(argv[1], ios::in);
    if (inFile.fail()) {
       cout << "File " << argv[1] << " open error. Sorry!" << endl;
       return 1;
    }
/*
    outFile.open("RESULT", ios::out);
    if (outFile.fail()) {
       cout << "Output file RESULT open error. Sorry!" << endl;
       return 1;
    }
*/
/*
Instantiate one double Lists and two string Lists. Use data in the
double file to construct the double List. And use the data in the
string file to construct the first string List.
5. Use copy constructor to copy the already constructed List to create a
second double List.
6. Use assignment operator to assign the first string List to the second.
7. Use operator== to check if the two double List and string List
are indeed the same. Use cout to report the comparison result.
8. Use setElement() to assign values to all Array objects.
9. Modify the makefile from the Assignment 3 to compile your program
*/
    unsigned int dataLength;
    inFile >> dataLength;
    cout << "Given data length is " << dataLength << endl;
    List<double> double_list(dataLength);

    double_list.setLength(dataLength);
	/*
    inFile >>double_list;
    cout<< "First, the alist\n";
    cout<< "alist size is " << double_list.getLength() << endl;
    cout<< double_list;
	*/
    inFile.close();

    // blist not empty, setLength(20) should fail.
	/*
    blist.setLength(20);
    blist.resetLength(30);
    outFile << "\nSecond, the Original blist\n";
    outFile << "blist size is " << blist.getLength() << endl;
    for (unsigned int i = 0; i < blist.getLength(); i++)
        blist.setElement(i, i-14);
    outFile << blist;

    if (alist == blist) {
       outFile << "\nalist == blist\n";
    } else {
       outFile << "\nalist != blist\n";
    }

    clist = alist + blist;
    outFile << "\nThen, add alist and blist into clist\n";
    outFile << "clist size is " << clist.getLength() << endl;
    outFile << clist;

    blist = alist;
    outFile << "\nNow, the blist assigned by alist\n";
    outFile << "blist size is " << blist.getLength() << endl;
    outFile << blist;

    if (alist != blist) {
       outFile << "\nalist != blist\n";
    } else {
       outFile << "\nalist == blist\n";
    }

    clist.clear();
    outFile << "\nReset clist: clist size is " << clist.getLength() << endl;
    outFile << "\nCopy alist to the clist, with a for loop\n";
    clist.setLength(alist.getLength());
    for (unsigned int i = 0; i < clist.getLength(); i++) {
        clist.setElement(i, alist.getElement(i));
    }
    outFile << "clist size is " << clist.getLength() << endl;
    outFile << clist;

    List dlist(alist);
    outFile << "\nalist is copied to dlist using copy constructor\n";
    outFile << "dlist size is " << dlist.getLength() << endl;
    outFile << dlist;

    dlist += alist;
    outFile << "\nAdd alist to dlist\n";
    outFile << "dlist size is " << dlist.getLength() << endl;
    outFile << dlist;

    outFile << "\ndlist prefix adds 1\n";
    outFile << ++dlist;

    outFile << "\ndlist postfix adds 1 more : before\n";
    outFile << dlist++;
    outFile << "\ndlist postfix adds 1 more : after\n";
    outFile << dlist;

    outFile << "\nclist prefix substracts 1\n";
    outFile << --clist;

    outFile << "\nclist postfix substracts 1 more : before\n";
    outFile << clist--;
    outFile << "\nclist postfix substracts 1 more : after\n";
    outFile << clist;

    outFile.close();
*/
    return 0;
}
