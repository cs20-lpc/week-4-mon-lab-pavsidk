#include "LinkedList.hpp"
#include <string>
#include <iostream>
using namespace std;

int main() {

    //creating the first linked list, for integer type
    LinkedList<int> myNumbers;
    
    cout << "Length of empty linked list: " << myNumbers.getLength() << endl;
    //appending to an empty list
    myNumbers.append(10);
    cout << "Length of after appending once to an empty linked list: " << myNumbers.getLength() << endl;

    myNumbers.append(43);
    myNumbers.append(62);

    //getting element and printing it
    int number1 = myNumbers.getElement(1);
    cout << "Element 1: " << number1 << endl;

    //trying getElement as an invalid operation
    try {
        myNumbers.getElement(3);
    }
    catch (const string& e) {
        cout << e << endl;
    }

    //printing an element before and after replacing it
    cout << "Element 2, original: " << myNumbers.getElement(2) << endl;
    myNumbers.replace(2, 100);
    cout << "Element 2, replaced: " << myNumbers.getElement(2) << endl;

    //trying replace as an invalid operation (negative position)
    try {
        myNumbers.replace(-3, 99);
    }
    catch (const string& e) {
        cout << e << endl;
    }

    //trying replace as an invalid operation (position greater than length)
    try {
        myNumbers.replace(10, 99);
    }
    catch (const string& e) {
        cout << e << endl;
    }

    //appending another number, and checking the length
    cout << "Length before new append: " << myNumbers.getLength() << endl;
    myNumbers.append(130);
    cout << "Length after new append: " << myNumbers.getLength() << endl;

    //clearing the linked list and checking
    myNumbers.clear();
    cout << "After clearing: ";
    if (myNumbers.isEmpty()) {
        cout << "The list is empty." << endl;
    }
    else {
        cout << "The list is not empty." << endl;
    }

    //creating the second linked list, for string type
    LinkedList<string> myWords;
    myWords.append("World");
    myWords.append("Hello there!");
    myWords.append("This is another string.");

    //getting element 1
    cout << "Element 1 from the 2nd linked list: " << myWords.getElement(1) << endl;

    //printing the second linked list
    cout << "2nd linked list, printed using overloaded operator: " << myWords << endl;
}

