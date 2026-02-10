#include<iostream>
using namespace std;
class node {
    public:
        int data;
        node *next;
};
node *start = NULL;
node *rear = NULL;

node *create_node(node *start) {
    int num;
    cout << "Enter -1 to end \n" << endl;
    cout << "Enter number : ";
    cin >> num;
    
    while(num != -1) {
        node *new_node = new node();
        new_node -> data = num;

        if(start == NULL) {
            new_node -> next = NULL;
            start = new_node;
            rear = new_node;
        } else {
            new_node -> next = NULL;
            rear -> next = new_node;
            rear = new_node;
        }

        cout << "Enter number : ";
        cin >> num;
    }
    return start;
}

void display(node *start) {
    if(start == NULL) cout << "\nLinked list underflow" << endl;
    else {
        node *ptr = start;

        cout << "-----------------------------------------------" << endl;
        while(ptr -> next != NULL) {
            cout << ptr -> data << " ";
            ptr = ptr -> next;
        }
        cout << ptr -> data << endl;
        cout << "-----------------------------------------------" << endl;
    }
}

node *create_beg(node *start) {
    int num;
    cout << "\nEnter num : ";
    cin >> num;

    node *new_node = new node();
    new_node -> data = num;

    if(start == NULL) {
        new_node -> next = NULL;
        start = new_node;
        rear = new_node;
    } else {
        new_node -> next = start;
        start = new_node;
    }
    return start;
}

node *create_after(node *start) {
    if(start == NULL) cout << "\nLinked list underflow" << endl;
    else {
        int data,num;
        cout << "\nEnter num : ";
        cin >> num;

        cout << "\nEnter data after it, new node shoud create : ";
        cin >> data;

        node *ptr = start, *preptr = start;

        node *new_node = new node();
        new_node -> data = num;

        while(preptr -> data != data) {
            preptr = ptr;
            ptr = ptr -> next;
        }

        preptr -> next = new_node;
        new_node -> next = ptr;
    }
    return start;
}

node *create_end(node *start) {
    if(start == NULL) cout << "\nLinked list underflow" << endl;
    else {
        node *new_node = new node();
        int num;
        cout << "\nEnter num : ";
        cin >> num;

        new_node -> data = num;
        new_node -> next = NULL;
        rear -> next = new_node;
        rear = new_node;
    }

    return start;
}

node *delete_first(node *start) {
    if(start == NULL) cout << "\nLinked list underflow" << endl;
    else {
        node *ptr = start;
        start = start -> next;
        free(ptr);
    }
    return start;
}

node *delete_selected(node *start) {
    if(start == NULL) cout << "\nLinked list underflow" << endl;
    else {
        node *ptr = start,*preptr = start;
        int num;

        cout << "\nEnter number to delete that node : ";
        cin >> num;

        while(ptr -> data != num) {
            preptr = ptr;
            ptr = ptr -> next;
        }

        preptr -> next = ptr -> next;
        free(ptr);
    }
    return start;
}

node *delete_last(node *start) {
    if(start == NULL) cout << "\nLinked list underflow" << endl;
    else {
        node *preptr = start, *ptr = start;

        while(ptr -> next != NULL) {
            preptr = ptr;
            ptr = ptr -> next;
        }
        rear = preptr;
        rear -> next = NULL;
        free(ptr);
    }
    return start;
}


int main() {
    int choice = 0;

    do {
        cout << "\n1) Create node" << endl;
        cout << "2) Display node" << endl;
        cout << "3) create node at beginning" << endl;
        cout << "4) create node after data" << endl;
        cout << "5) create node at end" << endl;
        cout << "6) delete first node" << endl;
        cout << "7) delete selected node" << endl;
        cout << "8) delete end node" << endl;
        cout << "9) End" << endl;

        cout << "\nEnter choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
            start = create_node(start);
            break;

            case 2:
            display(start);
            break;

            case 3:
            start = create_beg(start);
            break;

            case 4:
            start = create_after(start);
            break;

            case 5:
            start = create_end(start);
            break;

            case 6:
            start = delete_first(start);
            break;
            
            case 7:
            start = delete_selected(start);
            break;

            case 8:
            start = delete_last(start);
            break;

            case 9:
            cout << "\nGood Bye" << endl;
            break;

            default:
            cout << "\nInvalid Choice" << endl;
            break;
        }
    } while(choice != 9);
    return 0;
}