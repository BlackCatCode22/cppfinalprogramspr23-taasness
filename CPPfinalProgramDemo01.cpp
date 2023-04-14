// CPPfinalProgramDemo01.cpp
// dH 4/10/23
// Animal class definition by chatGPT
// modified by dH 4/13/23

// Understand pointers and linked lists.
// Create a linked list of animals

// This program will give you a start on your final program. Lots of repetitive code here - reduce that to functions.
// Use pencil and paper when writing a program with lists and pointers (it's very easy to get lost and pointer errors
//    are arcade) 

#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string m_id;
    string m_name;
    int m_age;
    
public:
    // Default constructor
    Animal() {}

    // Constructor with parameters
    Animal(string _id, string _name, int _age) {
        m_id = _id;
        m_name = _name;
        m_age = _age;
    }

    // Getter functions
    string get_id() const { return m_id; }
    string get_name() const { return m_name; }
    int get_age() const { return m_age; }
    
    // Setter functions
    void set_id(string _id) { m_id = _id; }
    void set_name(string _name) { m_name = _name; }
    void set_age(int _age) { m_age = _age; }
    
};

class Node {
public:
    int value;
    Node* next;
};

class AnimalNode {
public:
    int anInt;
    Animal* animalObj;
    AnimalNode* next;
};

void printList(Node* n) {
    while (n != NULL) {
        cout << n->value << endl;
        n = n->next;
    }
}

void printAnimalList(AnimalNode* n) {
    cout << "\n\n";
    while (n->next != NULL) {
        cout << "\n " << n->anInt << " " << n->animalObj->get_name() << " " << n->animalObj->get_age() << " " << n->animalObj->get_id() << endl;
        n = n->next;
    }
    cout << "\n " << n->anInt << " " << n->animalObj->get_name() << " " << n->animalObj->get_age() << " " << n->animalObj->get_id() << endl;
    cout << "\n\n";
}

int main(){
    
    Node* head = new Node();
    Node* current = new Node();
    Node* temp = new Node();
    Node* priorNode = new Node();
    Node* nextNode = new Node();


    // 1) Create a new node
    // 2) Fill the data fields
    // 3) Attach to list
    // 4) Reposition navigation pointers to reflect the new list.

    head = new Node();
    head->value = 1;
    head->next = NULL;

    // Create a second node to the bottom of the list and make its next field NULL
    head->next = new Node();
    head->next->next = NULL;
    head->next->value = 2;
    // Set current to the end of the list
    current = head->next;

    // Test to see if this is how you want your list looking 
    cout << "/n testing for a 2 here..." << current->value << "  \n";

    // Add a third node to our list and make its next field NULL
    current->next = new Node();
    // Fill the data fields.
    current->next->next = NULL;
    current->next->value = 3;
    // Set current to the end of the list
    current = current->next;
   
    // Test to see if this is how you want your list looking 
    cout << "/n testing for a 3 here..." << current->value << "  \n";

    printList(head);

    // Add ten more nodes.
    for (int i = 4; i < 14; i++) {
        // Add a node to our list and make its next field NULL
        current->next = new Node();
        // Fill the data fields.
        current->next->next = NULL;
        current->next->value = i;
        // Set current to the end of the list
        current = current->next;
    }
    
    printList(head);

    // Create an Animal
    Animal* myAnimal = new Animal();
    myAnimal->set_name("First Animal");
    myAnimal->set_age(12);
    myAnimal->set_id("RE2301");

    // Output the animal.
    cout << myAnimal->get_name() << "  " << myAnimal->get_age() << "  " << myAnimal->get_id() << "\n";

    // Create animal list pointers.
    AnimalNode* anHead = new AnimalNode();
    AnimalNode* anCurrent = new AnimalNode();
    AnimalNode* anTemp = new AnimalNode();
    AnimalNode* anPriorNode = new AnimalNode();
    AnimalNode* anNextNode = new AnimalNode();

    // Create three animals
    Animal* myAnimal01 = new Animal();
    Animal* myAnimal02 = new Animal();
    Animal* myAnimal03 = new Animal();

    myAnimal01->set_id("Hy01");
    myAnimal01->set_age(5);
    myAnimal01->set_name("Shenzi");

    myAnimal02->set_id("Hy02");
    myAnimal02->set_age(2);
    myAnimal02->set_name("Banzai");

    myAnimal03->set_id("Hy03");
    myAnimal03->set_age(7);
    myAnimal03->set_name("Ed");

    anHead = new AnimalNode();
   
    anHead->anInt = 1;
    anHead->animalObj = myAnimal01;
    anHead->next = new AnimalNode();
    anCurrent = anHead->next;

    anCurrent->anInt = 2;
    anCurrent->animalObj = myAnimal02;
    anCurrent->next = new AnimalNode();
    anCurrent = anCurrent->next;

    anCurrent->anInt = 3;
    anCurrent->animalObj = myAnimal03;
    anCurrent->next = NULL;

    // Print the list of animals.
    printAnimalList(anHead);

    // Create a list of 10 animals
    anHead = new AnimalNode();

    anHead->anInt = 1;
    anHead->animalObj = myAnimal01;
    anHead->next = new AnimalNode();
    anCurrent = anHead->next;
    anCurrent->anInt = 88;
    cout << "\n  " << anCurrent->anInt << " \n";

    AnimalNode* pAnimalNodeHead = new AnimalNode();
    pAnimalNodeHead->anInt = 999;
    cout << "\n anInt is: " << pAnimalNodeHead->anInt << " \n";

    AnimalNode* pAnimalNodeCurrent = pAnimalNodeHead;

    // At this point, we have two AnimalNode pointers, pAnimalNodeHead and pAnimalNodeCurrent.
    // Both these pointers point to the same node. We will leave the head pointer where it is and use
    // the current pointer to build our list of AnimalNodes.
    
    for (int i = 0; i < 10; i++) {
        // Create a new AnimalNode
        pAnimalNodeCurrent->next = new AnimalNode();
        // Move current pointer to the newly created node.
        pAnimalNodeCurrent = pAnimalNodeCurrent->next;
        // Fill the new node's data fields, just one field and then test...
        pAnimalNodeCurrent->anInt = i;
    }
    // pCurrent points to the last node, so let's make the next field NULL to help us recognize the list's end.
    pAnimalNodeCurrent->next = NULL;

    // Print the list of 11 animal nodes. The first int should be 999 and the last int should be 10.
    cout << "\n This is the animal node list \n";
    // Set current to head to start the list. Use current to step through the list.
    pAnimalNodeCurrent = pAnimalNodeHead;
    while (pAnimalNodeCurrent->next != NULL) {
        cout << "\n AnimalNode's anInt: " << pAnimalNodeCurrent->anInt << "\n";
        // Advance pCurrent and move through the list
        pAnimalNodeCurrent = pAnimalNodeCurrent->next;  
    }
    // print the last node
    cout << "\n AnimalNode's anInt: " << pAnimalNodeCurrent->anInt << "\n";

    // Now that you have a list of animal nodes, you can attach animals to each node.
    // When rewriting this program you may want to do this in the step above, but this
    // should give you a good feel for how a linked list works.
    
    // Set current to head to start the list. Use current to step through the list.
    pAnimalNodeCurrent = pAnimalNodeHead;
    int loopCounter = 0;
    while (pAnimalNodeCurrent->next != NULL) {
        cout << "\n Adding an animal to this node: " << pAnimalNodeCurrent->anInt << "\n";
        pAnimalNodeCurrent->animalObj = new Animal();
        pAnimalNodeCurrent->animalObj->set_age(loopCounter);
        pAnimalNodeCurrent->animalObj->set_id("An" + to_string(loopCounter));
        pAnimalNodeCurrent->animalObj->set_name("name" + to_string(loopCounter));

        // Advance pCurrent and move through the list
        pAnimalNodeCurrent = pAnimalNodeCurrent->next;
        loopCounter++;
    }
    // handle the last node
    cout << "\n Adding an animal to this node: " << pAnimalNodeCurrent->anInt << "\n";
    pAnimalNodeCurrent->animalObj = new Animal();

    // Print the list of 11 animal nodes. The first int should be 999 and the last int should be 10.
    cout << "\n This is the animal node list with animal objects! \n";
    // Set current to head to start the list. Use current to step through the list.
    pAnimalNodeCurrent = pAnimalNodeHead;
    while (pAnimalNodeCurrent->next != NULL) {
        cout << "\n AnimalNode's anInt: " << pAnimalNodeCurrent->anInt << "\n";
        cout << "\n Animal's data fields (age, id, name) : " << pAnimalNodeCurrent->animalObj->get_age() << "  "
                                                   << pAnimalNodeCurrent->animalObj->get_id() << "  "
                                                   << pAnimalNodeCurrent->animalObj->get_name() << "  " << "\n";
        // Advance pCurrent and move through the list
        pAnimalNodeCurrent = pAnimalNodeCurrent->next;
    }
    // print the last node
    cout << "\n AnimalNode's anInt: " << pAnimalNodeCurrent->anInt << "\n";
   
    cout << "\n ************* this is the end of the program ******** \n\n";



    return 0;
}