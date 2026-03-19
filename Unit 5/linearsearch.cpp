#include<iostream>
using namespace std;
int main() {
    int arr[5] = {4,5,1,3,2};

    int data;
    cout << "\nEnter data you want to search : ";
    cin >> data;


    bool status;
    for(int i = 0; i < 5    ; i ++) {
        if(arr[i] == data) {
            status = true;
            break;
        }
    }

    status ? cout << "\ndata found in array \n" << endl : cout << "\ndata not found in array \n" << endl;

    cout << endl;
    return 0;
}