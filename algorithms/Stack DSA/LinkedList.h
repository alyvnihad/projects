#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;
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

        LinkedList &insert(int insert){
            Node *insertNode = new Node(insert);
            insertNode->next = head;
            head = insertNode;
            
            return *this;
        }

        LinkedList &remove(int remove){
            if(head->data == remove){
                Node *temp = head;
                head = head->next;
                delete temp;
                return *this;
            }
            return *this;
        }

        LinkedList &display(){
            cout << "Display Stack: ";
            Node *displayNode = head;
            while(displayNode != nullptr){
                cout << "[" << displayNode->data << " | " << displayNode->next << "]";
                if(displayNode->next != nullptr){
                    cout << " ---> ";
                }
                displayNode = displayNode->next;
            }
            cout << endl;

            return *this;
        }
};


#endif