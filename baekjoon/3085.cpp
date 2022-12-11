#include <iostream>
using namespace std;

int n;
int MAX;
char arr[50][50];
char arr_temp[50][50];

void print_arr_temp() {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr_temp[i][j];
        }
        cout << endl;
    }
}

void check () {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp = 1;
            // bottom 
            for (int k = i + 1; k < n; k++) {
                if (arr_temp[i][j] == arr_temp[k][j])
                    temp++;
                else 
                    break;
            }
            if (temp > MAX) {
                MAX = temp;
            }
            // right 
            temp = 1;
            for (int k = j + 1; k < n; k++) {
                if (arr_temp[i][j] == arr_temp[i][k])
                    temp++;
                else 
                    break;
            }
            if (temp > MAX) {
                MAX = temp;
            }
            // diagonal
            /*temp = 1;
            for (int k = 1; k + i < n && k + j < n; k++) {
                if (arr_temp[i][j] == arr_temp[i+k][j+k])
                    temp++;
                else 
                    break;
            }
            if (temp > MAX) {
                MAX = temp;
                //cout << "update" << i << j << "diag" << MAX << endl;
            }
            */
        }
    }
}

void reset_temp_arr() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr_temp[i][j] = arr[i][j];
        }
    }
}

void swap(int i, int j) {
    if (i < n - 1) {
        reset_temp_arr();
        arr_temp[i][j] = arr[i+1][j];
        arr_temp[i+1][j] = arr[i][j];
        check();
    }
    if (j < n - 1) {
        reset_temp_arr();
        arr_temp[i][j] = arr[i][j+1];
        arr_temp[i][j+1] = arr[i][j];
        check();
    }
    /*
    if (i < n - 1 && j < n - 1) {
        reset_temp_arr();
        arr_temp[i][j] = arr[i+1][j+1];
        arr_temp[i+1][j+1] = arr[i][j];
        check();
    }
    */
}

int main () {
    cin >> n;
    MAX = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    reset_temp_arr();
    check();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            swap(i, j); 
        }
    }

    cout << MAX;
    
    return 0;
}
