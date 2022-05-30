#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int perfect = 0;

void NQueens(int n){
    string** arr = new string*[n];
    for (int i = 0; i < n; i++){
        arr[i] = new string[n];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            arr[i][j] = "X";
        }
    }

    int i = 0;
    int j = 0;
    bool loop = true;
    while (loop){
        cout << i << " " << j << endl;

        arr[i][j] = "Q";

        // check if Q can stay there
        bool violation = false;
        // 往上查
        int k = 0;
        while (k < i)
        {
            if (arr[k][j] == "Q"){
                violation = true;
            }
            k++;
        }
        
        // 往左查
        k = 0;
        while (k < j)
        {
            if (arr[i][k] == "Q"){
                violation = true;
            }
            k++;
        }

        // 往左下
        k = 1;
        int l = -1;
        while (i + k < n && j + l >= 0){
            if (arr[i + k][j + l] == "Q"){
                violation = true;
            }
            k++;
            l--;
        }

        // 往左上
        k = -1;
        while (i + k >= 0 && j + k >= 0){
            if (arr[i + k][j + k] == "Q"){
                violation = true;
            }
            k--;
        }

        if (!violation){
            cout << "OK" << endl;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }

            if (j == n - 1){
                perfect++;
                cout << "Perfect" << endl;
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        cout << arr[i][j] << " ";
                    }
                    cout << endl;
                }

                arr[i][j] = "X";
                i++;
            }
            else{
                i = 0;
                j++;
            }
        }

        if (violation){
            cout << "Not OK" << endl;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }

            arr[i][j] = "X";
            i++;
        }

        while (i >= n)
        {
            // check
            // go back to previous column
            j--;
            for (int b = 0; b < n; b++){
                if (arr[b][j] == "Q"){
                    arr[b][j] = "X";
                    cout << "b and j is " << endl;
                    cout << b << j << endl;
                    i = b + 1;
                    break; 
                }
            }

            if (j < 0){
                cout << "dead end" << endl;
                loop = false;
                break;
            }
        }
        
    }
}

int main(){
    NQueens(4);

    cout << "Number of Perfect Solution is " << perfect << endl;
    return 0;
}