/*
#include <fstream>
#include <iostream>
*/
#include <string>
#include <stdlib.h>
#include "List.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc!=3) {
        cout << " file number not match. Sorry!" << endl;
        return 1;
    }

    ifstream inFile;
	ifstream inFile2;
  //  ofstream outFile;
    inFile.open(argv[1], ios::in);
    if (inFile.fail()) {
       cout << "File " << argv[1] << " open error. Sorry!" << endl;
       return 1;
    }
	inFile2.open(argv[2], ios::in);
    if (inFile.fail()) {
       cout << "File " << argv[2] << " open error. Sorry!" << endl;
       return 1;
    }
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
    inFile>>dataLength;
    cout<<"Given data length is "<<dataLength<<endl;
    List<double> double_list;
	double_list.setLength(dataLength);
	cout<<"double file content read in class should be "<<endl;
	inFile>>double_list;
	inFile.close();
	cout<<double_list;
	List<double> double_list_copy(double_list);
	cout<<"Copy constructor on double type content should be same "<<endl;
	cout<<double_list_copy;
	
	
	
	unsigned int dataLength2;
	inFile2>>dataLength2;
	List<string> string_list(dataLength2);
	inFile2>>string_list;
	inFile2.close();
	cout<<"string file content read in class should be "<<endl;
	cout<<string_list;
	List<string> string_list_copy;
	string_list_copy=string_list;
	cout<<"assignment operator on string type content should be same "<<endl;
	cout<<string_list_copy;
	
	cout<<"operator==test should be 1"<<endl;
	cout<<(string_list_copy==string_list)<<endl;
	
	cout<<"operator!=test should be 0"<<endl;
	cout<<(double_list!=double_list_copy)<<endl;
	
	cout<<"operator +test "<<endl;
	cout<<double_list+double_list_copy<<endl;
	
	cout<<"operator ++ postfix test "<<endl;
	cout<<double_list++;
	cout<<double_list;
	cout<<"operator ++ pretfix test "<<endl;
	cout<<++double_list;
	
	cout<<"operator -- postfix test "<<endl;
	cout<<double_list--;
	cout<<double_list;
	cout<<"operator -- pretfix test "<<endl;
	cout<<--double_list;
	
	cout<<"clear test return should be 1"<<endl;
	cout<<double_list.clear()<<endl;
	cout<<double_list_copy<<endl;
	cout<<"resetlength test return should be 1"<<endl;
	cout<<double_list_copy.resetLength(4)<<endl;
	
	cout<<"resetlength test length should be 4"<<endl;
	cout<<double_list_copy.getLength()<<endl;
	cout<<"setelement test"<<endl;
	double_list_copy.setElement(0,1.2);
	double_list_copy.setElement(1,2.1);
	double_list_copy.setElement(2,3.2);
	double_list_copy.setElement(3,5.8);
	cout<<double_list_copy<<endl;
    return 0;
}
