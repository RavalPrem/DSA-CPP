#include<iostream>
using namespace std;
int main() {
    int size;
    cout << "\nEnter size of an array : ";
    cin >> size;

    cout << "\nEnter elements of array \n" << endl;
    int arr[size];

    for(int i = 0; i < size; i ++) {
        cout << "Enter element [" << i << "] : ";
        cin >> arr[i];
    }

    cout << "\nAn Array down below" << endl;
    for(int i = 0; i < size; i ++) {
        cout << arr[i] << " ";
    }

    //bubble sort

    int temp;
    for(int i = 0; i < size - 1; i ++) {
        for(int j = 0; j < size - i - 1; j ++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\n\nSorted array down below" << endl;
    for(int i = 0; i < size; i ++) {
        cout << arr[i] << " ";
    }

    cout << "\n\n" << endl;
    return 0;
}