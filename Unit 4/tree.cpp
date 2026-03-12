#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;
};

node *tree = NULL;

node *create_node(node *tree,int val) {
    node *ptr,*nodeptr,*parentptr;
    ptr = new node();
    ptr -> data = val;
    ptr -> left = NULL;
    ptr -> right = NULL;

    if(tree == NULL) {
        tree = ptr;
        tree -> left = NULL;
        tree -> right = NULL;
    } else {
        parentptr = NULL;
        nodeptr = tree;

        while(nodeptr != NULL) {
            parentptr = nodeptr;

            if(val < nodeptr -> data) nodeptr = nodeptr -> left;
            else nodeptr = nodeptr -> right;
        }

        if(val < parentptr -> data) parentptr -> left = ptr;
        else parentptr -> right = ptr;
    }

    return tree;
}

node *preorder(node *tree) {
    if(tree != NULL) {
        cout << tree -> data << " ";
        preorder(tree -> left);
        preorder(tree -> right);
    }
    return tree;
}

node *inorder(node *tree) {
    if(tree != NULL) {
        inorder(tree -> left);
        cout << tree -> data << " ";
        inorder(tree -> right);
    }
    return tree;
}

node *postorder(node *tree) {
    if(tree != NULL) {
        postorder(tree -> left);
        postorder(tree -> right);
        cout << tree -> data << " ";
    }
    return tree;
}

bool search_element(node *tree,int val) {
    if(tree == NULL) return false;
    if(tree -> data == val) return true;
    if(val < tree -> data) return search_element(tree -> left,val);
    else return search_element(tree -> right,val);
}

int main() {
    int choice,value,search_value;
    bool ok;

    do {
        cout << "\n";
        cout << "1) create node " << endl;
        cout << "2) preorder " << endl;
        cout << "3) inorder " << endl;
        cout << "4) postorder " << endl;
        cout << "5) search node " << endl;
        cout << "6) exit " << endl;

        cout << "\nEnter choice : ";
        cin >> choice;
        
        switch(choice) {
            case 1:
            cout << "\nEnter value : ";
            cin >> value;
            tree = create_node(tree,value);
            break;

            case 2:
            tree = preorder(tree);
            break;

            case 3:
            tree = inorder(tree);
            break;

            case 4:
            tree = postorder(tree);
            break;

            case 5:
            cout << "\nSearch element : ";
            cin >> search_value;
            if(search_element(tree,search_value)) cout << "\nElement found \n" << endl;
            else cout << "\nElement Not Found \n" << endl;
            break;

            case 6:
            cout << "\nExit \n" << endl;
            break;
            
            default:
            cout << "\nError\n" << endl;
            break;
        }
    } while(choice != 6);
}