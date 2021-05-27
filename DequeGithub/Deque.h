//Deque.h

#pragma once
#include <stdexcept>
using std::runtime_error;


/* class that creates a node object, the node contains two 'Node pointers',
 * one that points to the next node and one that points to the last node.
 * Also contains the template data */
template <class T>
class Node{
public:
    Node* next;
    Node* last;
    T data;


    //node default constructor, sets both Node pointers to nullptr
    Node()
    : next(nullptr), last(nullptr)
    { }


    //node constructor when passed in a value, sets pointers to nullptr
    Node(T value)
    : next(nullptr), last(nullptr), data(value)
    { }


    /* node constructor that takes in parameters for the next and last pointers
     * as well as the data for the newly created node */
    Node(Node* next, Node* last, T value)
    : next(next), last(last), data(value)
    { }

};  //Node class

template <class T>
class Deque{
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;


    //makes a deep copy of the parameter object to the current Deque object
    void deepCopy(const Deque& toCopy);


    //deletes all the nodes in the Deque
    void removeContents();


public:
    //default constructor (creates an empty deque)
    Deque();


    /*copy constructor (creates a deep copy of the contents of the
     * parameter and initializes a new Deque object) */
    Deque(const Deque& toCopy);


    //destructor (calls removeContents private method to deallocate memory)
    ~Deque();


    /* overloads the '=' (assignment) operator allowing a previously
     * created Deque object to equal that of another Deque object */
    Deque& operator=(const Deque& toEqual);


    // creates a new node containing the parameter as it's data and places at front of deque
    void insertFront(T toAddAtFront);


    // creates a new node containing the parameter as it's data and places at back of deque
    void insertBack(T toAddAtBack);


    // removes node at front of deque and returns it's data
    T removeFront();


    // removes node at back of deque and returns it's data
    T removeBack();


    // returns the data at the front of the Deque
    T peekFront() const;


    // returns the data at the back of the Deque
    T peekBack() const;


    // checks if the Deque is empty
    bool empty() const;


    // gets the current size of the Deque
    int size() const;

}; //Deque class



//****************
//PRIVATE METHODS
//****************

//makes a deep copy of the parameter object to the current Deque object
template <class T>
void Deque<T>::deepCopy(const Deque& toCopy) {
    Node<T>* temp = nullptr;
    if(toCopy.head != nullptr && toCopy.tail != nullptr){
        temp = new Node<T>(toCopy.head->next, toCopy.head->last, toCopy.head->data);
        head = temp;
        tail = temp;
        temp = toCopy.head->next;
    }
    while(temp != nullptr){
        insertBack(temp->data);
        temp = temp->next;
    }
}


//deletes all the nodes in the Deque
template <class T>
void Deque<T>::removeContents() {
    Node<T>* temp;
    while(head != nullptr){
        temp = head->next;
        head->next = nullptr;
        head->last = nullptr;
        delete head;
        head = temp;
    }
    head = nullptr;
    tail = nullptr;
}


//***************
//PUBLIC METHODS
//***************

//default constructor (creates an empty deque)
template <class T>
Deque<T>::Deque()
{ }


/*copy constructor (creates a deep copy of the contents of the
* parameter and initializes a new Deque object) */
template <class T>
Deque<T>::Deque(const Deque& toCopy) {
    deepCopy(toCopy);
}


//destructor (calls removeContents private method to deallocate memory)
template <class T>
Deque<T>::~Deque() {
    removeContents();
}


/* overloads the '=' (assignment) operator allowing a previously
* created Deque object to equal that of another Deque object */
template <class T>
Deque<T>& Deque<T>::operator=(const Deque& toEqual) {
    if(this != &toEqual){           //only runs if 'this' object is not the same as the parameter
        removeContents();
        deepCopy(toEqual);
    }
    return *this;
}


// creates a new node containing the parameter as it's data and places at front of deque
template <class T>
void Deque<T>::insertFront(T toAddAtFront) {
    if(head == nullptr && tail == nullptr){                     //empty case
        head = new Node<T>(nullptr, nullptr, toAddAtFront);
        tail = head;
    }else{
        head->last = new Node<T>(head, nullptr, toAddAtFront);  //if not empty
        head = head->last;
    }
}


// creates a new node containing the parameter as it's data and places at back of deque
template <class T>
void Deque<T>::insertBack(T toAddAtBack) {
    if(head == nullptr && tail == nullptr){                     //empty case
        tail = new Node<T>(nullptr, nullptr, toAddAtBack);
        head = tail;
    }else{
        tail->next = new Node<T>(nullptr, tail, toAddAtBack);   //if not empty
        tail = tail->next;
    }
}


// removes node at front of deque and returns it's data
template <class T>
T Deque<T>::removeFront(){
    T valueRemoved;
    if(head == nullptr || tail == nullptr){            //empty case
        throw runtime_error("Deque is empty.");
    }else if(head == tail){                            //contains one item
        valueRemoved = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
    }else {
        valueRemoved = head->data;
        Node<T> *temp = head;
        head = head->next;              //reassigns head to next node in Deque
        head->last = nullptr;           //head's last pointer set to nullptr
        delete temp;                    //deletes node at front of Deque
    }
    return valueRemoved;
}


// removes node at back of deque and returns it's data
template <class T>
T Deque<T>::removeBack() {
    T valueRemoved;
    if(head == nullptr || tail == nullptr){             //empty case
        throw runtime_error("Deque is empty.");
    }else if(head == tail){                             //contains one item
        valueRemoved = tail->data;
        delete tail;
        head = nullptr;
        tail = nullptr;
    }else {
        valueRemoved = tail->data;
        Node<T> *temp = tail;
        tail = tail->last;              //reassigns tail to point to a new last node
        tail->next = nullptr;           //tail's next pointer set to nullptr
        delete temp;                    //deletes node at end of Deque
    }
    return valueRemoved;
}


// returns the data at the front of the Deque
template <class T>
T Deque<T>::peekFront() const {
    if(head == nullptr || tail == nullptr){             //empty case
        throw runtime_error("Deque is empty");
    }else{
        return head->data;
    }
}


// returns the data at the back of the Deque
template <class T>
T Deque<T>::peekBack() const{
    if(head == nullptr || tail == nullptr){             //empty case
        throw runtime_error("Deque is empty");
    }else{
        return tail->data;
    }
}


// checks if the Deque is empty
template <class T>
bool Deque<T>::empty() const{
    return (head == nullptr && tail == nullptr);
}


// gets the current size of the Deque
template <class T>
int Deque<T>::size() const{
    int size = 0;
    if(head != nullptr && tail != nullptr){
        Node<T>* temp = head;
        while(temp != nullptr){
            size++;
            temp = temp->next;
        }
    }
    return size;
}

