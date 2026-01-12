#include<iostream>
#define MAX 5
using namespace std;

/*
This code work like you have to enter all the values in queue and then you have to dequeu all elements, after that you can reEnter values in the queue, the display and peek function works fine.

But in this code you have to enque all elements and then you have to deque all elements, after that you can ReEnque elements in the queue and then deque all elements
*/

int queue[MAX];
int front = -1,rear = -1;

void enque(int num) {
    if(front == MAX && rear == 4 ) {
        front = rear = 0;
        queue[rear] = num;
        cout << "\nAn element : " << queue[rear] << " is pushed to queue" << endl;

    } else if(rear == MAX-1) {
        cout << "\nQueue Overflow" << endl;
    } else {
        if(front == -1 && rear == -1 || front > MAX - 1 && rear == MAX || front == 5 && rear == MAX - 1) {
            front = rear = 0;
        } else {
            rear++;
        }
        queue[rear] = num;
        cout << "\nAn element : " << queue[rear] << " is pushed to queue" << endl;
    }
}

void dequeue() {
    if(front < 0 || front > MAX - 1) {
        cout << "\nQueue underflow" << endl;
    } else {
        cout << "\nAn element : " << queue[front] << " is dequeue" << endl;
        front++;

        if(front == 4 && rear == 5) {
            front = rear = 0;
        }
    }
}

void peek() {
    if(front < 0 || front > MAX - 1) {
        cout << "\nQueue underflow" << endl;
    } else {
        cout << "\nPeek element : " << queue[front] << endl;
    }
}

void display() {
    if(front < 0 || front > MAX - 1) {
        cout << "\nQueue underflow\n" << endl;
    } else {
        for(int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        } 
        cout << endl;
    }
}

int main() {
    int num, choice = 0;
    do {
        cout << "\n1)Enque an element" << endl;
        cout << "2)Deque an element" << endl;
        cout << "3)peek an element" << endl;
        cout << "4)Display Queue" << endl;
        cout << "5)Exit" << endl;

        cout << "\nEnter choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
            cout << "\nEnter element to enque : ";
            cin >> num;
            enque(num);
            cout << endl;
            break;

            case 2:
            dequeue();
            cout << endl;
            break;

            case 3:
            peek();
            cout << endl;
            break;

            case 4:
            display();
            // cout << endl;
            break;

            case 5:
            cout << "\nGood bye\n" << endl;
            break;

            case 6:
            cout << "\nThe rear : " << rear << "\nThe front : " << front << endl;
            break;

            default:
            cout << "\nSome problem reEnter choice";
            break;
        }
    } while(choice != 5);
}