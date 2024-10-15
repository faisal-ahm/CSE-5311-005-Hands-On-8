#include <bits/stdc++.h>
#define MAX_SIZE 100

using namespace std;

// Stack implementation
class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
        } else {
            arr[++top] = value;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return -1; // Indicating error
        } else {
            return arr[top--];
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1; // Indicating error
        } else {
            return arr[top];
        }
    }
};

// Queue implementation
class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow\n";
        } else {
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = value;
            size++;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return -1; // Indicating error
        } else {
            int value = arr[front];
            front = (front + 1) % MAX_SIZE;
            size--;
            return value;
        }
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1; // Indicating error
        } else {
            return arr[front];
        }
    }
};

// Singly Linked List implementation
struct Node {
    int data;
    int next;
};

class SinglyLinkedList {
private:
    Node nodes[MAX_SIZE];
    int head;
    int freeIndex;

public:
    SinglyLinkedList() {
        head = -1;
        freeIndex = 0;
        for (int i = 0; i < MAX_SIZE - 1; i++) {
            nodes[i].next = i + 1;
        }
        nodes[MAX_SIZE - 1].next = -1;
    }

    int insertAtHead(int value) {
        if (freeIndex == -1) {
            cout << "List overflow\n";
            return -1;
        }

        int newIndex = freeIndex;
        freeIndex = nodes[newIndex].next;
        nodes[newIndex].data = value;
        nodes[newIndex].next = head;
        head = newIndex;
        return newIndex;
    }

    int deleteValue(int value) {
        int current = head;
        int previous = -1;

        while (current != -1) {
            if (nodes[current].data == value) {
                if (previous == -1) {
                    head = nodes[current].next;
                } else {
                    nodes[previous].next = nodes[current].next;
                }
                nodes[current].next = freeIndex;
                freeIndex = current;
                return 1; // Success
            }
            previous = current;
            current = nodes[current].next;
        }
        cout << "Value not found\n";
        return 0; // Value not found
    }

    int search(int value) {
        int current = head;
        while (current != -1) {
            if (nodes[current].data == value) {
                return current;
            }
            current = nodes[current].next;
        }
        return -1; // Not found
    }

    void display() {
        int current = head;
        while (current != -1) {
            cout << nodes[current].data << " -> ";
            current = nodes[current].next;
        }
        cout << "NULL\n";
    }
};

int main() {
    // Testing Stack
    Stack stack;
    stack.push(10);
    stack.push(20);
    cout << "Top of stack: " << stack.peek() << endl;
    stack.pop();
    cout << "Top of stack after pop: " << stack.peek() << endl;

    // Testing Queue
    Queue queue;
    queue.enqueue(30);
    queue.enqueue(40);
    cout << "Front of queue: " << queue.frontElement() << endl;
    queue.dequeue();
    cout << "Front of queue after dequeue: " << queue.frontElement() << endl;

    // Testing Linked List
    SinglyLinkedList list;
    list.insertAtHead(50);
    list.insertAtHead(60);
    list.insertAtHead(70);
    cout << "Linked list after insertions: ";
    list.display();

    list.deleteValue(60);
    cout << "Linked list after deleting 60: ";
    list.display();

    int searchResult = list.search(50);
    cout << "Search for 50: " << (searchResult != -1 ? "Found" : "Not found") << endl;

    return 0;
}


/*
OUTPUT:
Top of stack: 20
Top of stack after pop: 10
Front of queue: 30
Front of queue after dequeue: 40
Linked list after insertions: 70 -> 60 -> 50 -> NULL
Linked list after deleting 60: 70 -> 50 -> NULL
Search for 50: Found
*/