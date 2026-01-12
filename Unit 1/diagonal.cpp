#include<iostream>
using namespace std;
bool isDiagonalMatrix(int mat[4][4]) {
    for(int i = 0; i < 4; i ++) {
        for(int j = 0; j < 4; j ++) {
            if(i != j && mat[i][j] != 0) { 
                /* meaing of --> i != j points the non-diagonal position in matrix that's values
                should be zero, if not return false */ 
                return false;
            }
        }
    }
    return true;
}

int main() {
    int mat[4][4] = {
        {1,0,0,0},
        {0,5,0,0},
        {0,0,3,0},
        {0,0,0,7},
    };

    if(isDiagonalMatrix(mat)) {
        cout << "\nThis matrix is diognal matrix\n" << endl;
    } else {
        cout << "\nThis matrix is not Diognal Matrix\n" << endl;
    }
    return 0;

}