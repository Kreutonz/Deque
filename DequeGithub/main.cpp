#include "Deque.h"
#include <cassert>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

//copy print methods into the Deque.h file to print Deques

//prints the Deque
//template <class T>
//void Deque<T>::printDequeStats() const {
//    Node<T>* traverse = head;                          //temp pointer to traverse through linked list
//    if(head == nullptr && tail == nullptr){         //empty case
//        cout << "Deque is empty" << endl;
//    }
//    while(traverse != nullptr){
//        cout << endl << "Current Node: " << traverse;
//        cout << endl << "Last: " << traverse->last;
//        if(traverse->last != nullptr){
//            cout << " (" << traverse->last->data << ")";
//        }
//        cout << endl << "Data: " << traverse->data;
//        cout << endl << "Next: " << traverse->next;
//        if(traverse->next != nullptr){
//            cout << " (" << traverse->next->data << ")";
//        }
//        traverse = traverse->next;
//        cout << endl;
//    }
//    cout << endl;
//    cout << "Head: " << head << endl;
//    cout << "Tail: " << tail << endl;
//}//printDequeStats()
//

//template <class T>
//void Deque<T>::printDeque() const {
//    Node<T>* temp = head;
//    if(head == nullptr && tail == nullptr){         //empty case
//        cout << "Deque is empty" << endl;
//    }else{
//        cout << "nullptr <- ";
//        while(temp != nullptr){
//            cout << "|" << temp->data << "|";
//            temp = temp->next;
//            if(temp != nullptr){
//                cout << " <-> ";
//            }
//        }
//        cout << " -> nullptr" << endl;
//    }
//}

void nodeTest(){
    Node<int>* defaultNode = new Node<int>();
    Node<int>* initialNode = new Node<int>(5);
    Node<int>* definedNode = new Node<int>(8);

    assert(defaultNode->next == nullptr);
    assert(defaultNode->last == nullptr);

    assert(initialNode->next == nullptr);
    assert(initialNode->last == nullptr);
    assert(initialNode->data == 5);

    assert(definedNode->next == nullptr);
    assert(definedNode->last == nullptr);
    assert(definedNode->data == 8);

    initialNode->next = definedNode;        //initialNode <-> definedNode
    definedNode->last = initialNode;

    defaultNode->next = initialNode;        //defaultNode <-> initialNode
    initialNode->last = defaultNode;

    assert(initialNode->next == definedNode);
    assert(definedNode->last == initialNode);
    assert(defaultNode->next == initialNode);
    assert(initialNode->last == defaultNode);

    Node<int>* insertNode = new Node<int>(nullptr, definedNode, 20);
    definedNode->next  = insertNode;

    assert(definedNode->next == insertNode);
    assert(insertNode->last == definedNode);
    assert(insertNode->next == nullptr);
    assert(insertNode->data == 20);

    delete defaultNode;
    delete initialNode;
    delete definedNode;
    delete insertNode;

    cout << "...All Node tests passed" << endl;
}//nodeTest()

void copyConstructorTest(){
    Deque<int> dequeToCopy;
    assert(dequeToCopy.size() == 0);
    Deque<int> dequeTest(dequeToCopy);           //copies empty Deque
    assert(dequeTest.size() == 0);
//    dequeTest.printDequeStats();
    assert(dequeTest.size() == 0);


    dequeToCopy.insertBack(1);
    dequeToCopy.insertBack(3);
    dequeToCopy.insertBack(5);
    dequeToCopy.insertBack(7);
    dequeToCopy.insertBack(9);
    assert(dequeToCopy.size() == 5);
//    dequeToCopy.printDequeStats();

    Deque<int> dequeTest2(dequeToCopy);
    assert(dequeTest2.size() == dequeToCopy.size());
//    dequeTest2.printDequeStats();

    cout << "...All copy constructor tests passed" << endl;
}//copyConstructorTest()

void testOperatorOverload(){
    Deque<int> deq1;
    deq1.insertBack(10);
    deq1.insertBack(9);
    deq1.insertBack(8);
    deq1.insertBack(7);
    deq1.insertBack(6);
    assert(deq1.size() == 5);

    Deque<int> deq2;
    deq2.insertBack(1);
    deq2.insertBack(2);
    deq2.insertBack(3);
    assert(deq2.size() == 3);

    Deque<int> deq3;
    assert(deq3.size() == 0);

//    deq1.printDequeStats();
//    deq2.printDequeStats();
//    deq3.printDequeStats();

    deq3 = deq2;
    assert(deq2.size() == deq3.size());
//    cout << "TEST: Deq3 = Deq2" << endl << endl;
//    cout << "Deq2: " << endl;
//    deq2.printDequeStats();
//    cout << "Deq3: " << endl;
//    deq3.printDequeStats();

    deq3 = deq1;
    assert(deq1.size() == deq3.size());
//    cout << "TEST: Deq3 = Deq1" << endl<< endl;
//    cout << "Deq1: " << endl;
//    deq1.printDequeStats();
//    cout << "Deq3: " << endl;
//    deq3.printDequeStats();

    cout << "...All operator overload tests passed" << endl;
}

void insertTest(){
    Deque<int> testDeque;
    assert(testDeque.size() == 0);
//    testDeque.printDequeStats();        //empty

    testDeque.insertFront(5);
    testDeque.insertFront(4);
    testDeque.insertFront(3);
    testDeque.insertFront(2);
    testDeque.insertFront(1);
//    testDeque.printDequeStats();
    assert(testDeque.size() == 5);


    Deque<int> testDeque2;
//    testDeque2.printDequeStats();       //empty
    assert(testDeque2.size() == 0);

    testDeque2.insertBack(6);
    testDeque2.insertBack(7);
    testDeque2.insertBack(8);
    testDeque2.insertBack(9);
    testDeque2.insertBack(10);
//    testDeque2.printDequeStats();
    assert(testDeque2.size() == 5);

    cout << "...All insert tests passed" << endl;
}

void removeTest(){
    Deque<int> deq1;
    deq1.insertBack(1);
    deq1.insertBack(2);
    deq1.insertBack(3);
    deq1.insertBack(4);
    deq1.insertBack(5);
    assert(deq1.size() == 5);
//    deq1.printDequeStats();
//    deq1.printDeque();

    //test for remove back
    int back1 = deq1.removeBack();
    assert(back1 == 5);
//    deq1.printDequeStats();
//    deq1.printDeque();

    //test for remove front
    int front1 = deq1.removeFront();
    assert(front1 == 1);
//    deq1.printDequeStats();
//    deq1.printDeque();

    //test for remove back and remove front
    int back2 = deq1.removeBack();
    int front2 = deq1.removeFront();
    assert(back2 == 4);
    assert(front2 == 2);
//    deq1.printDequeStats();
//    deq1.printDeque();

    //test to remove front if there is only one item
    int front3 = deq1.removeFront();
    assert(front3 == 3);
//    deq1.printDeque();
//    deq1.printDequeStats();


    //test to try and remove an item when none in deque
    try {
        deq1.removeFront();
    }catch(runtime_error)
    { }
//    deq1.printDeque();

    cout << "...All remove tests passed." << endl;
}

void testPeeks(){
    Deque<int> deq1;

    //test to peek a value at front and back should return runtime error
    try{
        int valFront = deq1.peekFront();
    }catch(runtime_error)
    { }

    try{
        int valBack = deq1.peekBack();
    }catch(runtime_error)
    { }


    deq1.insertFront(1);
    int valFront = deq1.peekFront();
    int valBack = deq1.peekBack();
    assert(valFront == 1);
    assert(valBack == 1);
//    deq1.printDeque();

    deq1.insertBack(2);
    deq1.insertBack(3);
    valFront = deq1.peekFront();
    valBack = deq1.peekBack();
    assert(valFront == 1);
    assert(valBack == 3);
//    deq1.printDeque();

    deq1.insertFront(0);
    valFront = deq1.peekFront();
    valBack = deq1.peekBack();
    assert(valFront == 0);
    assert(valBack == 3);
//    deq1.printDeque();

    cout << "...All peek tests passed" << endl;
}

void testEmpty(){
    Deque<int> deq1;

    //empty deque
    bool isEmpty = deq1.empty();
    assert(isEmpty == true);
//    deq1.printDeque();

    //deque contains one item (item is added)
    deq1.insertFront(1);
    isEmpty = deq1.empty();
    assert(isEmpty == false);
//    deq1.printDeque();

    //deque contains two items (item is added)
    deq1.insertFront(2);
    isEmpty = deq1.empty();
    assert(isEmpty == false);
//    deq1.printDeque();

    //deque contains 1 item (item is removed)
    deq1.removeFront();
    isEmpty = deq1.empty();
    assert(isEmpty == false);
//    deq1.printDeque();

    //deque contains 0 items (item is removed)
    deq1.removeBack();
    isEmpty = deq1.empty();
    assert(isEmpty == true);
//    deq1.printDeque();

    cout << "...All tests passed for empty method" << endl;
}

void testSize(){
    Deque<int> deq1;

    //empty deque
    int size = deq1.size();
    assert(size == 0);
//    deq1.printDeque();

    //deque with 1 item
    deq1.insertFront(1);
    size = deq1.size();
    assert(size == 1);
//    deq1.printDeque();

    //deque with 5 items (4 added)
    deq1.insertFront(2);
    deq1.insertFront(3);
    deq1.insertFront(4);
    deq1.insertFront(5);
    size = deq1.size();
    assert(size == 5);
//    deq1.printDeque();

    //deque with 2 items (3 removed)
    deq1.removeFront();
    deq1.removeBack();
    deq1.removeFront();
    size = deq1.size();
    assert(size == 2);
//    deq1.printDeque();

    //deque with 1 item (1 removed)
    deq1.removeFront();
    size = deq1.size();
    assert(size == 1);
//    deq1.printDeque();

    //empty deque (1 item removed)
    deq1.removeFront();
    size = deq1.size();
    assert(size == 0);
//    deq1.printDeque();

    cout << "...All tests passed for size method" << endl;
}

void profsInsertRemoveTest(){
    Deque<int> deq1;

    deq1.insertBack(16);
    deq1.insertBack(76);
    deq1.insertBack(21);
    deq1.insertBack(53);
    assert(deq1.peekFront() == 16);
    assert(deq1.peekBack() == 53);

    Deque<int> deq2(deq1);
    Deque<int> deq3(deq1);
    Deque<int> deq4(deq1);

    deq1.insertFront(13);
    assert(deq1.empty() == false);
    assert(deq1.size() == 5);
    assert(deq1.peekFront() == 13);
    assert(deq1.peekBack() == 53);

    deq2.insertBack(42);
    assert(deq2.empty() == false);
    assert(deq2.size() == 5);
    assert(deq2.peekFront() == 16);
    assert(deq2.peekBack() == 42);

    deq3.removeFront();
    assert(deq3.empty() == false);
    assert(deq3.size() == 3);
    assert(deq3.peekFront() == 76);
    assert(deq3.peekBack() == 53);

    deq4.removeBack();
    assert(deq4.empty() == false);
    assert(deq4.size() == 3);
    assert(deq4.peekFront() == 16);
    assert(deq4.peekBack() == 21);

    cout << "...profsInsertRemoveTest passed" << endl;
}

void profCompilationTest(){
    Deque<int> dq1;
//    cout << dq1.empty() << " - 1" << endl;
    assert(dq1.empty() == true);
    dq1.insertFront(42);
    dq1.insertBack(216);
//    cout << dq1.peekFront() << " - 42" << endl;
//    cout << dq1.peekBack() << " - 216" << endl;
//    cout << dq1.size() << " - 2" << endl;
    assert(dq1.peekFront() == 42);
    assert(dq1.peekBack() == 216);
    assert(dq1.size() == 2);


    Deque<int> dq2(dq1);
    Deque<int> dq3;
    dq3 = dq1;

//    cout << dq1.removeFront() << " - 42" << endl;
//    cout << dq1.removeBack() << " - 216" << endl;
    assert(dq1.removeFront() == 42);
    assert(dq1.removeBack() == 216);

//    cout << dq2.removeFront() << " - 42" << endl;
//    cout << dq2.removeBack() << " - 216" << endl;
//    cout << dq3.removeFront() << " - 42" << endl;
//    cout << dq3.removeBack() << " - 216" << endl;
    assert(dq2.removeFront() == 42);
    assert(dq2.removeBack() == 216);
    assert(dq3.removeFront() == 42);
    assert(dq3.removeBack() == 216);

    cout << "...profCompilationTest passed" << endl;
}

void variousTypesTest(){
    // Test string type
    Deque<string> deqString;
    assert(deqString.empty() == true);
    assert(deqString.size() == 0);

    deqString.insertFront("Dogs");      //adding "Dogs" to front
    assert(deqString.size() == 1);
    assert(deqString.peekFront() == "Dogs");
    assert(deqString.peekBack() == "Dogs");
    assert(deqString.empty() == false);

    deqString.insertFront("Cats");      //adding "Cats" to front
    assert(deqString.peekFront() == "Cats");
    assert(deqString.peekBack() == "Dogs");
    assert(deqString.size() == 2);

    deqString.insertBack("Wolves");     //adding "Wolves to back
    assert(deqString.peekBack() == "Wolves");
    assert(deqString.peekFront() == "Cats");
    assert(deqString.size() == 3);

    deqString.insertFront("Eagle");     //adding "Eagle" to front
    deqString.insertFront("Hippo");     //adding "Hippo" to front
    deqString.insertBack("rat");        //adding "Rat" to back
    assert(deqString.peekFront() == "Hippo");
    assert(deqString.peekBack() == "rat");
    assert(deqString.size() == 6);

    assert(deqString.removeBack() == "rat");        //removing items from Deque
    assert(deqString.removeFront() == "Hippo");
    assert(deqString.removeBack() == "Wolves");
    assert(deqString.removeFront() == "Eagle");
    assert(deqString.removeBack() == "Dogs");
    assert(deqString.removeFront() == "Cats");
    assert(deqString.size() == 0);
    assert(deqString.empty() == true);


    // Test char type
    Deque<char> deqChars;
    assert(deqChars.empty() == true);
    assert(deqChars.size() == 0);

    deqChars.insertFront('c');      //adding 'c' to front
    assert(deqChars.size() == 1);
    assert(deqChars.peekFront() == 'c');
    assert(deqChars.peekBack() == 'c');
    assert(deqChars.empty() == false);

    deqChars.insertFront('b');      //adding 'b' to front
    assert(deqChars.peekFront() == 'b');
    assert(deqChars.peekBack() == 'c');
    assert(deqChars.size() == 2);

    deqChars.insertBack('d');     //adding 'd' to back
    assert(deqChars.peekBack() == 'd');
    assert(deqChars.peekFront() == 'b');
    assert(deqChars.size() == 3);

    deqChars.insertFront('a');     //adding 'a' to front
    deqChars.insertFront('z');     //adding 'z' to front
    deqChars.insertBack('e');        //adding 'e' to back
    assert(deqChars.peekFront() == 'z');
    assert(deqChars.peekBack() == 'e');
    assert(deqChars.size() == 6);

    assert(deqChars.removeBack() == 'e');        //removing items from Deque
    assert(deqChars.removeFront() == 'z');
    assert(deqChars.removeBack() == 'd');
    assert(deqChars.removeFront() == 'a');
    assert(deqChars.removeBack() == 'c');
    assert(deqChars.removeFront() == 'b');
    assert(deqChars.size() == 0);
    assert(deqChars.empty() == true);

    // Test int type
    Deque<int> deqIntegers;
    assert(deqIntegers.empty() == true);
    assert(deqIntegers.size() == 0);

    deqIntegers.insertFront(55);      //adding '55' to front
    assert(deqIntegers.size() == 1);
    assert(deqIntegers.peekFront() == 55);
    assert(deqIntegers.peekBack() == 55);
    assert(deqIntegers.empty() == false);

    deqIntegers.insertFront(102);      //adding '102' to front
    assert(deqIntegers.peekFront() == 102);
    assert(deqIntegers.peekBack() == 55);
    assert(deqIntegers.size() == 2);

    deqIntegers.insertBack(67);     //adding '67' to back
    assert(deqIntegers.peekBack() == 67);
    assert(deqIntegers.peekFront() == 102);
    assert(deqIntegers.size() == 3);

    deqIntegers.insertFront(-2);     //adding '2' to front
    deqIntegers.insertFront(-69);     //adding '69' to front
    deqIntegers.insertBack(1008);        //adding '1008' to back
    assert(deqIntegers.peekFront() == -69);
    assert(deqIntegers.peekBack() == 1008);
    assert(deqIntegers.size() == 6);

    assert(deqIntegers.removeBack() == 1008);        //removing items from Deque
    assert(deqIntegers.removeFront() == -69);
    assert(deqIntegers.removeBack() == 67);
    assert(deqIntegers.removeFront() == -2);
    assert(deqIntegers.removeBack() == 55);
    assert(deqIntegers.removeFront() == 102);
    assert(deqIntegers.size() == 0);
    assert(deqIntegers.empty() == true);


    // Test double type
    Deque<double> deqDoubles;
    assert(deqDoubles.empty() == true);
    assert(deqDoubles.size() == 0);

    deqDoubles.insertFront(55.07);      //adding '55.07' to front
    assert(deqDoubles.size() == 1);
    assert(deqDoubles.peekFront() == 55.07);
    assert(deqDoubles.peekBack() == 55.07);
    assert(deqDoubles.empty() == false);

    deqDoubles.insertFront(-102.76);      //adding '-102.76' to front
    assert(deqDoubles.peekFront() == -102.76);
    assert(deqDoubles.peekBack() == 55.07);
    assert(deqDoubles.size() == 2);

    deqDoubles.insertBack(-67.12567);     //adding '-67.12567' to back
    assert(deqDoubles.peekBack() == -67.12567);
    assert(deqDoubles.peekFront() == -102.76);
    assert(deqDoubles.size() == 3);

    deqDoubles.insertFront(2.0432);     //adding '2.0432' to front
    deqDoubles.insertFront(-69.000);     //adding '-69.000' to front
    deqDoubles.insertBack(1008.23);        //adding '1008.23' to back
    assert(deqDoubles.peekFront() == -69.000);
    assert(deqDoubles.peekBack() == 1008.23);
    assert(deqDoubles.size() == 6);

    assert(deqDoubles.removeBack() == 1008.23);        //removing items from Deque
    assert(deqDoubles.removeFront() == -69.000);
    assert(deqDoubles.removeBack() == -67.12567);
    assert(deqDoubles.removeFront() == 2.0432);
    assert(deqDoubles.removeBack() == 55.07);
    assert(deqDoubles.removeFront() == -102.76);
    assert(deqDoubles.size() == 0);
    assert(deqDoubles.empty() == true);


    // Test bool type
    Deque<bool> deqBools;
    assert(deqBools.empty() == true);
    assert(deqBools.size() == 0);

    deqBools.insertFront(true);      //adding 'true' to front
    assert(deqBools.size() == 1);
    assert(deqBools.peekFront() == true);
    assert(deqBools.peekBack() == true);
    assert(deqBools.empty() == false);

    deqBools.insertFront(false);      //adding 'false' to front
    assert(deqBools.peekFront() == false);
    assert(deqBools.peekBack() == true);
    assert(deqBools.size() == 2);

    deqBools.insertBack(false);     //adding 'false' to back
    assert(deqBools.peekBack() == false);
    assert(deqBools.peekFront() == false);
    assert(deqBools.size() == 3);

    deqBools.insertFront(true);     //adding 'true' to front
    deqBools.insertFront(false);     //adding 'false' to front
    deqBools.insertBack(true);        //adding 'true' to back
    assert(deqBools.peekFront() == false);
    assert(deqBools.peekBack() == true);
    assert(deqBools.size() == 6);

    assert(deqBools.removeBack() == true);        //removing items from Deque
    assert(deqBools.removeFront() == false);
    assert(deqBools.removeBack() == false);
    assert(deqBools.removeFront() == true);
    assert(deqBools.removeBack() == true);
    assert(deqBools.removeFront() == false);
    assert(deqBools.size() == 0);
    assert(deqBools.empty() == true);

    cout << "...All types test passed" << endl;
}

int main() {
    nodeTest();
    copyConstructorTest();
    testOperatorOverload();
    insertTest();
    removeTest();
    testPeeks();
    testEmpty();
    testSize();
    profsInsertRemoveTest();
    profCompilationTest();
    variousTypesTest();
    cout << endl << "...ALL PROGRAM TESTS PASSED" << endl;
    return 0;
}





