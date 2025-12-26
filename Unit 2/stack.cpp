#include<iostream>
using namespace std;

int arr[4],top = -1;

void push(int num) {
    if(top >= 4) {
        cout << "\nStack Overflow \n" << endl;
    } else {
        top++;
        arr[top] = num;
        cout << "\nElement : " <<arr[top] << " is pushed to stack\n" << endl;
    }
}

void pull() {
    if(top < 0) {
        cout << "\nStack Undersflow \n" << endl;
    } else {
        cout << "\nThe element : " << arr[top] << " is pulled \n" << endl;
        top--;
    }
}

void display() {
    if(top < 0) {
        cout << "\nStack Underflow \n" << endl;
    } else {
        for(int i = top; i >= 0; i --) {
            cout << arr[i] << " ";
        }
        cout << "\n\n";
    }
}

void peek() {
    if(top < 0) {
        cout << "\nStack Underflow \n" << endl; 
    } else {
        cout << "\nElement Peek : " << arr[top] << "\n\n";
    }
}

int main() {
    int number=0,choice;

    do {
        cout << "\n1) push the element" << endl;
        cout << "2) pull the element" << endl;
        cout << "3) display stack" << endl;
        cout << "4) peek element" << endl;
        cout << "5) Exit From Loop" << endl;
        cout << "\n\nEnter number : ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                cout << "\nEnter number for push : ";
                cin >> number;
                push(number);
                break;
            }
            
            case 2: {
                pull();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                peek();
                break;
            }
            case 5:{
                cout << "\nGood Bye ! \n" << endl;
                break;
            }
            default: {
                cout << "\nError caused" << endl;
                break;
            }
            // case 5:exit;

        }
    } while(choice != 5);
}