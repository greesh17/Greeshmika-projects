#include <iostream>
#include <exception>
#include <string>

using namespace std;
class LineEditorNode {
	typedef string value_type;
public:
	LineEditorNode *next;
	LineEditorNode *prev;
	value_type elt;

	LineEditorNode() {
		next = nullptr;
		prev = nullptr;
	}

	LineEditorNode(value_type item) {
		next = nullptr;
		prev = nullptr;
		elt = item;
	}

	~LineEditorNode() {};

};
class LineEditor
{

	// The following declarations describe the functions that you must implement.
	// You SHOULD NOT CHANGE any of the following PUBLIC declarations.
public:
	typedef string value_type;							// data type of sequence items
	typedef unsigned int size_type;					// data type of sequence counts and / or sizes

	LineEditor(size_type sz = 0);					// creates a sequence indexed from 0 ... sz

	LineEditor(const LineEditor& s);					// create a sequence from the existing sequence s 
	~LineEditor();									// destroys the sequence

	LineEditor& operator=(const LineEditor& s);		// assign sequence s to the sequence

	value_type& operator[](size_type p);			// return a reference to the item at index position p
	value_type& at(size_type p);					// return a reference to the item at index position p

	void push_back(const value_type& v);			// add v to the end of the sequence
	void pop_back();								// remove item at the end of the sequence

	void insert(size_type p, value_type v);		// insert the item v in the sequence at index position p

	const value_type& front() const;				// returns a reference to the first item in the sequence
	const value_type& back() const;					// returns a reference to the last item in the sequence

	bool empty() const;								// returns true if the sequence is empty
	size_type size() const;

	void clear();									// clears the sequence returning it to the empty state
	void erase(size_type p, size_type n = 1);	// deletes n number items starting a index position p 	

	ostream& print(ostream& = cout);				// prints the items as a comma seperated sequence
	LineEditor readFile(string);
	void writeFile(string);
	LineEditorNode* getHead();
	LineEditorNode* getTail();
	int getNumberOfLines();


private:

	LineEditorNode *head;
	LineEditorNode *tail;
	size_type numElts;   // Number of elements in the sequence
	
};  // End of class Sequence

// You must also implement the << operator.  Do not change this declaration:
ostream& operator<<(ostream&, LineEditor&);

