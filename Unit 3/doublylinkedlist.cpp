#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node *next;
        node *prev;
};

node *start = NULL;
node *rear = NULL;

node *create_node(node *start) {
    int num;
    
    cout << "\nEnter -1 to end" << endl;
    cout << "\nEnter num : ";
    cin >> num;
    
    while(num != -1) {
        node *new_node = new node();
        new_node -> data = num;

        if(start == NULL) {
            new_node -> next = NULL;
            new_node -> prev = NULL;
            start = new_node;
            rear = new_node;
        } else {
            new_node -> next = NULL;
            new_node -> prev = rear;
            rear -> next = new_node;
            rear = new_node;
        }

        cout << "\nEnter num : ";
        cin >> num;
    }

    return start;
}

void display_node(node *start) {
    if(start == NULL) cout << "\nEmpty" << endl;
    else {
        node *ptr = start;

        cout << "---------------------------------------" << endl;
        while(ptr -> next != NULL) {
            cout << ptr -> data << " ";
            ptr = ptr -> next;
        }
        cout << ptr -> data << endl;
    }
    cout << "---------------------------------------" << endl;
}

node *create_start(node *start) {
    node *new_node = new node();
    int num;
    cout << "\nEnter num : ";
    cin >> num;
    new_node -> data = num;

    new_node -> prev = NULL;
    new_node -> next = start;
    start = new_node;       
    
    return start;
}

node *create_middle(node *start) {
    node *new_node = new node();
    int num,data;
    cout << "\nEnter num : ";
    cin >> num;

    cout << "\nEnter the value after which the data has to be inserted : ";
    cin >> data;

    new_node -> data = num;

    node *preptr = start, *ptr = start;

    while(preptr -> data != data) {
        preptr = ptr;
        ptr = ptr -> next;
    }

    new_node -> prev = preptr;
    new_node -> next = ptr;
    preptr -> next = new_node;
    ptr -> prev = new_node;

    return start;
}

node *create_end(node *start) {
    node *new_node = new node();

    int num;
    cout << "\nEnter num : ";
    cin >> num;

    new_node -> data = num;
    new_node -> next = NULL;
    new_node -> prev = rear;

    rear -> next = new_node;
    rear = new_node;
    return start;
}

node *delete_beg(node *start) {
    if(start == NULL) {
        cout << "\nLinked list underflow" << endl;
    }
    else {
        node *ptr;

        if(start -> next == NULL) {
            ptr = start;
            start = NULL;
            rear = NULL;
            free(ptr);
        }
        else {
            ptr = start;
            start = start -> next;
            free(ptr);
        }
    }
    return start;
}

node *delete_mid(node *start) {
    if(start == NULL) {
        cout << "\nLinked list Undeflow" << endl;
    }
    else {
        
        if(start -> next == NULL) {
            node *ptr = start;
            start = NULL;
            rear = NULL;
            free(ptr);
        }
        else {
            node *preptr = start, *ptr = start;
            int data;
            cout << "\nEnter node you want to delete : ";
            cin >> data;

            while(ptr -> data != data) {
                preptr = ptr;
                ptr = ptr -> next;
            }

            preptr -> next = ptr -> next;
            ptr -> next -> prev = preptr;
            free(ptr);
        }
    }
    return start;
}

node *delete_end(node *start) {
    if(start == NULL) {
        cout << "\nLinked list undeflow" << endl;
    }
    else {
        if(start -> next == NULL) {
            node *ptr = start;
            start = NULL;
            rear = NULL;
            free(ptr);
        }
        else {
            node *ptr = rear;
            rear = rear -> prev;
            rear -> next = NULL;
            free(ptr);
        }
    }

    return start;
}

void reverse_node(node *start) {
    if(start == NULL) {
        cout << "\nLinked list Undeflow" << endl;
    }
    else {
        node *ptr = rear;

        cout << "---------------------------------------" << endl;
        while(ptr -> prev != NULL) {
            cout << ptr -> data << " ";
            ptr = ptr -> prev;
        }
        cout << ptr -> data << " " << endl;
        cout << "---------------------------------------" << endl;
    }
}
int main() {
    int choice;

    do {
        cout << "\n1) create node" << endl;
        cout << "2) display node" << endl;
        cout << "3) create node at start" << endl;
        cout << "4) create node at middle" << endl;
        cout << "5) create node at end" << endl;
        cout << "6) delete first node" << endl;
        cout << "7) delete chosen node" << endl;
        cout << "8) delete end node" << endl;
        cout << "9) reverse node print" << endl;
        cout << "10) exit" << endl;

        cout << "\nEnter choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
            start = create_node(start);
            break;

            case 2:
            display_node(start);
            break;

            case 3:
            start = create_start(start);
            break;

            case 4:
            start = create_middle(start);
            break;
            
            case 5:
            start = create_end(start);
            break;

            case 6:
            start = delete_beg(start);
            break;

            case 7:
            start = delete_mid(start);
            break;

            case 8:
            start = delete_end(start);
            break;

            case 9:
            reverse_node(start);
            break;

            case 10:
            cout << "\nExit bye" << endl;
            break;

            default:
            cout << "\nWrong choice reEnter the choice" << endl;
            break;
        }
    } while(choice != 10);
}