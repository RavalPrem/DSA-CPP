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

    int temp, minValue, position;

    for(int i = 0; i < size - 1; i ++) {
        minValue = arr[i];
        position = i;

        for(int j = i + 1; j < size; j ++) {
            if(arr[j] < minValue) {
                minValue = arr[j];
                position = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[position];
        arr[position] = temp;
    }

    cout << "\n\nSorted array down below" << endl;
    for(int i = 0; i < size; i ++) {
        cout << arr[i] << " ";
    }

    cout << "\n\n" << endl;
    return 0;
}