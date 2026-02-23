#include <iostream>

using namespace std;


/*
    Exercise: Implement a Queue using a Linked List

    Implement the queue data structure using your previous linked list solution.
    The linked list should have nodes that store an integer value and a reference to the next node. 
    The queue should support the following operations:

    1. Enqueue: Add an element to the rear of the queue.
    2. Dequeue: Remove and return the front element of the queue.
    3. Peek/Front: Returns the front element of the queue without removing it.
    4. IsEmpty: Check if the queue is empty.
    5. Size: Return the number of elements currently in the queue.
*/


/*  Solution  */

struct Node{
    int data;
    Node* next;

    Node(int value = 0){
        data = value;
        next = nullptr;
    }
};

class Queue{
    public:

    Node *head;
    int Size;

    Queue(){
        head = nullptr;
        Size = 0;
    }
    int size(){
        return Size;
    }
    Queue &enqueue(int value){
        Node *node = new Node(value);
        ++Size;
        if(head == nullptr){
            head = node; 
            return *this;
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

    int peek(){
        return head->data;
    }

    int dequeue(){
        --Size;
        Node *dequeueNode = head;
        int temp = head->data;
        head = head->next; 
        delete dequeueNode;
        return temp;
    }

    bool isEmpty(){
        return(Size==0) ? 1 : 0;
    }
};


int main() {

    /*      Example usage:     */

    Queue queue;
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Size: " << queue.size() << endl;   // Output: Size: 3
    cout << "Front: " << queue.peek() << endl;  // Output: Front: 10
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: Dequeued: 10
    cout << "Is Empty? " << queue.isEmpty() << endl;  // Output: Is Empty? 0 (false)
    cout << "Front: " << queue.peek() << endl;  // Output: Front: 20
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: Dequeued: 20
    cout << "Is Empty? " << queue.isEmpty() << endl;  // Output: Is Empty? 0 (false)
    cout << "Front: " << queue.peek() << endl;  // Output: Front: 30
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: Dequeued: 30
    cout << "Is Empty? " << queue.isEmpty() << endl;  // Output: Is Empty? 1 (true)

    return 0;
}