
#include "MyList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void testCopyConstructor(LineEditor);

int main()
{
	/*
	//tested
	// Create a sequence of length four, store some values, and print
	try {
		cout << "Testing sequence creation and printing" << endl;
		cout << "--------------------------------------" << endl;
		LineEditor data(4);
		data[0] = "100";
		data[1] = "200";
		data[2] = "300";
		cout << "Sequence:  " << data << endl;
		cout << "Should be: <100, 200, 300, ???>" << endl << endl;
	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}


	LineEditor lineEditor;
	LineEditor lineEditor2 = lineEditor.readFile("input.txt");
	cout << lineEditor;

cout << lineEditor;
lineEditor2.insert(3, "HELLOWORD");
lineEditor2.insert(0, "BEGINING");
lineEditor2.writeFile("output.txt");*/


	LineEditor e;
char command = ' ';
int n, n2;
string fname, input;
cin >> command; //getting command from user
while (command != 'Q')
{
	if (command == 'r')
	{
		cin >> fname;
		e= e.readFile(fname);
	}
	else if (command == 'w')
	{
		cin >> fname;
		e.writeFile(fname);
	}
	else if (command == 'b')
	{
		cin >> input;
		e.insert(0,input);
	}

	else if (command == 'a')
	{
		cin >> input;
		e.push_back(input);
	}
	else if (command == 'd')
	{
		cin >> n >> n2;
		if(n!=1)
		n2 = n2 - n;
		n = n - 1;
		//there is bug if we delete everything
			e.erase(n, n2);
		
	}
	else if (command == 'l')
	{
		cin >> n >> n2;
		e.getNumberOfLines();
		if (n > 0 && n <= e.getNumberOfLines() && n2 > 0 && n2 <= e.getNumberOfLines())
		{
			for (int i = n - 1; i < n2; i++) {
				cout << e[i]<<endl;
			}
		}
		else
		{
			cout << "Not in range" << endl;
			
		}
	}
	else if (command == 'i')
	{
		input = "";
		
		cin >> n>> input;
		// cout << "number " << n << endl;
		
		if (n > 1 && n < e.getNumberOfLines())
		{
			e.insert(n, input);
		}
		if (n > 1 && n == e.getNumberOfLines()) {
			e.push_back(input);
		}
		if (n == 1) {
			e.insert(0, input);

		}
		else
		{
			cout << "Not in range" << endl;
			cin.ignore(255, '\n');
		}
	}

	else if (command == 'F')
	{
		input = "";
		cin >> input;
		
		for (int i = 0; i <= e.getNumberOfLines(); i++) {
			size_t found = e[i].find(input);
			if (found >0) {
				cout << e[i]<<endl;
			}
		}
	}

	/*
	

	else if (command == 'j')
	{
		cin >> n;
		if (e.testlines(n) && n != e.count_NumberofLines()) {

			e.to_join(n);
		}
		else
		{
			cout << "Not in range" << endl;
			cin.ignore(255, '\n');
		}

	}
	else if (command == 'p')
	{
		cin >> n;
		if (e.testlines(n)) {
			e.to_paste(n);
		}
		else
		{
			cout << "Not in range" << endl;
			cin.ignore(255, '\n');
		}

	}
	
	else if (command == 'y')
	{
		cin >> n >> n2;
		if (e.testlines(n) && e.testlines(n2)) {
			e.to_InsertBuffer(n, n2);
		}
		else
		{
			cout << "Not in range" << endl;
			cin.ignore(255, '\n');
		}
	}
	
	
	
	 */
	else if (command == 'N')
	{
	cout << e.getNumberOfLines() << endl;
	}
	 else if (command =='Q')
	  {
		  cout << "Thank you!! Terminating the Program.."<<endl;
		  break;
	  }
	else
	{
		cout << "Invalid command" << endl;
	}
	cin >> command;
}

return 0;
/*
ifstream ifs2("input.txt");

		
		ifs2.open("input.txt");
	for (int j = 0; j < numberOfLines; j++) {
		getline(ifs2, lineData);
		lineEditor[j] = lineData;
	}
	cout << lineEditor;*/
	/*//tested
	// Test for independent sequences
	try {
		cout << "Testing multiple sequences" << endl;
		cout << "--------------------------" << endl;
		LineEditor s1(3);
		LineEditor s2(3);

		for (int i = 0; i < 3; i++) {
			s1[i] = i;
			s2[i] = 100 + i;
		}
		cout << "Sequence1: " << s1 << endl;
		cout << "Sequence2: " << s2 << endl;
		cout << "Should be: <0, 1, 2>" << endl << "           <100, 101, 102>" << endl << endl;
	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}

	//test failed
	// Test push_back

	try {
		cout << "Testing push_back()" << endl;
		cout << "-------------------" << endl;
		LineEditor data(3);
		data[0] = 100;
		data[1] = 200;
		data[2] = 300;
		data.push_back(400);
		data.push_back(500);
		cout << "Sequence:  " << data << endl;
		cout << "Should be: <100, 200, 300, 400, 500>" << endl << endl;
	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}

	// Test push_back to an empty sequence
	//tail failed
	try {
		cout << "Testing push_back() on an empty sequence" << endl;
		cout << "-------------------" << endl;
		LineEditor data(0);
		data.push_back(100);
		data.push_back(200);
		data.push_back(300);
		data.push_back(400);
		data.push_back(500);
		cout << "Sequence:  " << data << endl;
		cout << "Should be: <100, 200, 300, 400, 500>" << endl << endl;
	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}
	//tested
	// Test pop_back
	try {
		cout << "Testing pop_back()" << endl;
		cout << "------------------" << endl;
		LineEditor data(5);
		for (int i = 0; i < 5; i++) {
			data[i] = (i + 1) * 100;
		}
		data.pop_back();
		data.pop_back();
		cout << "Sequence:   " << data << endl;
		cout << "Should be:  <100, 200, 300>" << endl << endl;

	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}
	//tested
	// Test pop_back on empty sequence
	try {
		cout << "Testing pop_back() on an empty sequence" << endl;
		cout << "------------------" << endl;
		LineEditor data(3);
		for (int i = 0; i < 3; i++) {
			data[i] = (i + 1) * 100;
		}
		data.pop_back();
		data.pop_back();
		data.pop_back();
		data.pop_back();
		cout << "ERROR: Pop_back() DID NOT throw an exception" << endl << endl;

	}

	catch (exception& e)
	{
		cout << "CORRECT: Threw exception: " << e.what() << endl << endl;
	}

	// Test insert()
	//test failed tail has problem
	try {
		cout << "Testing insert()" << endl;
		cout << "------------------" << endl;

		LineEditor data(5);

		for (int i = 0; i < 5; i++) {
			data[i] = (i + 1) * 100;
		}

		data.insert(3, 999);
		cout << "Sequence:   " << data << endl;
		cout << "Should be:  <100, 200, 300, 999, 400, 500>" << endl << endl;

		data.insert(0, 888);
		cout << "Sequence:   " << data << endl;
		cout << "Should be:  <888, 100, 200, 300, 999, 400, 500>" << endl << endl;

		data.insert(6, 777);
		cout << "Sequence:   " << data << endl;
		cout << "Should be:  <888, 100, 200, 300, 999, 400, 777, 500>" << endl << endl;

	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}

	// Test insert on invalid index
	try {
		cout << "Testing insert() on an invalid index" << endl;
		cout << "------------------" << endl;
		LineEditor data(3);
		for (int i = 0; i < 3; i++) {
			data[i] = (i + 1) * 100;
		}
		data.insert(5, 555);
		cout << "ERROR: Pop_back() DID NOT throw an exception" << endl << endl;

	}

	catch (exception& e)
	{
		cout << "CORRECT: Threw exception: " << e.what() << endl << endl;
	}

	// Test front()
	//tested
	try {
		cout << "Testing front()" << endl;
		cout << "---------------" << endl;

		LineEditor data(3);

		for (int i = 0; i < 3; i++) {
			data[i] = (i + 1) * 100;
		}

		cout << "Front:     " << data.front() << endl;
		cout << "Sequence:  " << data << endl;
		cout << "Should be: 100" << endl;
		cout << "           <100, 200, 300>" << endl << endl;

	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}

	// Test front() on empty sequence
	//tested
	try {
		cout << "Testing front() on an empty sequence" << endl;
		cout << "------------------------------------" << endl;
		LineEditor data(0);
		int result = data.front();
		cout << "ERROR: front() DID NOT throw an exception" << endl << endl;

	}

	catch (exception& e)
	{
		cout << "CORRECT: Threw exception: " << e.what() << endl << endl;
	}

	// Test back()
	//tested
	try {
		cout << "Testing back()" << endl;
		cout << "---------------" << endl;

		LineEditor data(3);

		for (int i = 0; i < 3; i++) {
			data[i] = (i + 1) * 100;
		}

		cout << "Back:      " << data.back() << endl;
		cout << "Sequence:  " << data << endl;
		cout << "Should be: 300" << endl;
		cout << "           <100, 200, 300>" << endl << endl;

	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}

	// Test back() on empty sequence
	try {
		cout << "Testing back() on an empty sequence" << endl;
		cout << "------------------------------------" << endl;
		LineEditor data(0);
		int result = data.back();
		cout << "ERROR: back() DID NOT throw an exception" << endl << endl;

	}

	catch (exception& e)
	{
		cout << "CORRECT: Threw exception: " << e.what() << endl << endl;
	}

	// Test empty()
	try {
		cout << "Testing empty()" << endl;
		cout << "---------------" << endl;

		LineEditor empty_sequence(0);
		LineEditor nonempty_sequence(1);

		cout << "Empty sequence, empty returns: " << empty_sequence.empty() << endl;
		cout << "Non-empty sequence, empty returns: " << nonempty_sequence.empty() << endl << endl;

	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}

	// Test size()
	try {
		cout << "Testing size()" << endl;
		cout << "---------------" << endl;

		LineEditor data(7);
		LineEditor empty_sequence(0);

		cout << "Sequence length 7, size returned: " << data.size() << endl;
		cout << "Empty sequence, size returned: " << empty_sequence.size() << endl << endl;

	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}

	// Test clear()
	try {
		cout << "Testing clear()" << endl;
		cout << "---------------" << endl;

		LineEditor data(5);

		for (int i = 0; i < 5; i++) {
			data[i] = (i + 1) * 100;
		}

		data.clear();
		cout << "Sequence cleared, empty returned: " << data.empty() << endl;
		cout << "Size returned:  " << data.size() << endl << endl;
	}



	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}

	// Test erase
	try {
		cout << "Testing erase()" << endl;
		cout << "------------------" << endl;
		LineEditor data(10);
		for (int i = 0; i < 10; i++) {
			data[i] = (i + 1) * 100;
		}
		data.erase(3, 4);
		cout << "Sequence:   " << data << endl;
		cout << "Should be:  <100, 200, 300, 800, 900, 1000>" << endl << endl;

		data.erase(4, 2);
		cout << "Sequence:   " << data << endl;
		cout << "Should be:  <100, 200, 300, 800>" << endl << endl;

		data.erase(0, 2);
		cout << "Sequence:   " << data << endl;
		cout << "Should be:  <300, 800>" << endl << endl;

	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}

	// Test erase with invalid parameters
	try {
		cout << "Testing erase() on invalid parameters" << endl;
		cout << "------------------" << endl;
		LineEditor data(5);
		for (int i = 0; i < 5; i++) {
			data[i] = (i + 1) * 100;
		}
		data.erase(3, 5);
		cout << "ERROR: erase() DID NOT throw an exception" << endl << endl;

	}

	catch (exception& e)
	{
		cout << "CORRECT: Threw exception: " << e.what() << endl << endl;
	}

	// Test assignment (=) operator
	try {
		cout << "Testing assignment (=) operator" << endl;
		cout << "------------------" << endl;
		LineEditor data1(5);
		LineEditor data2(0);

		for (int i = 0; i < 5; i++) {
			data1[i] = (i + 1) * 100;
		}

		data2 = data1;

		data2[0] = 1;
		data2[1] = 2;

		cout << "Data1:      " << data1 << endl;
		cout << "Data2:      " << data2 << endl;
		cout << "Should be:  <100, 200, 300, 400, 500>" << endl;
		cout << "            <1, 2, 300, 400, 500>" << endl << endl;

	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}

	// Test copy constructor
	try {
		cout << "Testing copy constructor" << endl;
		cout << "------------------" << endl;
		LineEditor data(5);

		for (int i = 0; i < 5; i++) {
			data[i] = (i + 1) * 100;
		}

		testCopyConstructor(data);

		cout << "Original Sequence:      " << data << endl;
		cout << "Should be:              <1, 200, 300, 400, 500>" << endl;
		cout << "                        <100, 200, 300, 400, 500>" << endl << endl;

	}

	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl << endl;
	}

} // END OF MAIN


void testCopyConstructor(LineEditor s)
{
	s[0] = 1;
	cout << "Copied Sequence:        " << s << endl;*/
}