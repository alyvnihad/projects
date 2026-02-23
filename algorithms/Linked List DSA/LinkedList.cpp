#include <iostream>

using namespace std;

/*
    Exercise:

    1. Define a struct called Node that represents a single node in the linked list. 
    The struct should have two members: a data member to store the value of the node 
    and a pointer member to point to the next node in the list.

    2. Define a class called LinkedList that represents the linked list itself. 
    The class should have a private member to store the head node pointer.

    3. Implement a constructor for the LinkedList class that initializes the head pointer to nullptr, 
    indicating an empty list.

    4. Implement a member function in the LinkedList class called insert, 
    which takes a value as a parameter and inserts a new node with that value at the beginning of the list.

    5. Implement a member function in the LinkedList class called display, 
    which traverses the linked list and prints the values of all the nodes.

    6. Implement a member function in the LinkedList class called search, 
    which takes a value as a parameter and searches for a node with that value in the list. 
    If found, it should return true; otherwise, it should return false.

    7. Implement a member function in the LinkedList class called remove, 
    which takes a value as a parameter and removes the first occurrence of a node with that value from the list. 
    If the value is not found, it should do nothing.

    8. Implement a member function in the LinkedList class called append, 
    which takes a value as a parameter and adds a new node with that value to the end of the list.

    9. Implement a destructor for the LinkedList class that deletes all the nodes in the list.

    10. Test your implementation by creating an instance of the LinkedList class, inserting several nodes, 
    and then calling the display function to verify that the nodes are correctly inserted and displayed. 
    Test the search, remove, and append functions as well.

    Remember to use the appropriate access specifiers (private, public) to encapsulate the members of the classes properly. 
    This exercise will help you understand how to implement a linked list using OOP principles in C++.
*/


/* Solution */
struct Node{
    int data;
    Node *next;

    Node(int value = 0){
        data = value;
        next = nullptr;
    }  
};

class LinkedList{
    public:
        Node *head;

        LinkedList(){
            head = nullptr;
        }

        ~LinkedList(){  
            Node *destructor = head;
            while(destructor){
                cout << "delete on " << destructor->data << endl;
                Node *temp = destructor->next;
                delete destructor;
                destructor = temp;
            }
        }

        LinkedList &append(int value){
           Node *node = new Node(value);
           if(head == nullptr){       
                head = node;
           }
           else{
                Node *yeniNode = head;
                while(yeniNode->next != nullptr){
                    yeniNode = yeniNode->next;
                }
                yeniNode->next = node;
           }
           return *this;
        }

        LinkedList &insert(int insert){
            Node *insertNode = new Node(insert);
            insertNode->next = head;
            head = insertNode;
            
            return *this;
        }

        bool search(int search){
            Node *searchNode = head;
            while(searchNode != nullptr){
                if(searchNode->data == search){
                    return true;
                }
                searchNode = searchNode->next;                
            }
            return false;
        }

        LinkedList &remove(int remove){
            if(head->data == remove){
                Node *temp = head;
                head = head->next;
                delete temp;
                return *this;
            }

            Node *removeNode = head;
            while(removeNode->next != nullptr){
                if(removeNode->next->data == remove){
                    Node *temp = removeNode->next;
                    removeNode->next = removeNode->next->next;
                    delete temp;
                    return *this;
                }
                removeNode = removeNode->next;
            }
            return *this;
        }

        LinkedList &display(){
            Node *displayNode = head;
            while(displayNode != nullptr){
                cout << "[" << displayNode->data << " | " << displayNode->next;
                if(displayNode->next != nullptr){
                    cout << " ---> ";
                }
                displayNode = displayNode->next;
            }
            cout <<"]"<< endl;

            return *this;
        }
};


int main() {

    /*      Example usage:     */
    system("cls");

    LinkedList list;

    list.append(1).append(2).append(3).append(4);
    
    list.display();

    list.insert(5).display();

    bool isFound = list.search(4);

    cout << std::boolalpha << endl;
    cout << isFound;
    cout << endl << endl;

    list.remove(3).display().remove(4).display().remove(5).display();

    cout << endl;

    /*  
        Example Output: 
        
        [1 | 0x7f9092f05c80] ---> [2 | 0x7f9092f05c90] ---> [3 | 0x7f9092f05ca0] ---> [4 | 0x0] 
        [5 | 0x7f9092f05c70] ---> [1 | 0x7f9092f05c80] ---> [2 | 0x7f9092f05c90] ---> [3 | 0x7f9092f05ca0] ---> [4 | 0x0] 

        true

        [5 | 0x7f9092f05c70] ---> [1 | 0x7f9092f05c80] ---> [2 | 0x7f9092f05ca0] ---> [4 | 0x0] 
        [5 | 0x7f9092f05c70] ---> [1 | 0x7f9092f05c80] ---> [2 | 0x0] 
        [1 | 0x7f9092f05c80] ---> [2 | 0x0] 

        Destructor: 
            delete on 0
            delete on 1
            delete on 2
    */

    return 0;
}