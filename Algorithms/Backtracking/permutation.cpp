#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


vector<vector<string>> result;

void permutation(vector<string> arr){
    // 排列演算法 backtracking
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr.size(); j++){
            if (i == j){
                continue;
            }
            for (int k = 0; k < arr.size(); k++){
                if (i == k || j == k){
                    continue;
                }
                cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
            }
        }
    }
}

void swap(vector<string> &arr, int a, int b){
    string temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void perm(vector<string> &arr, int start){
    // In general
    if (start >= arr.size()){
        result.push_back(arr);
    }
    else{
        for (int i = 0; i < arr.size(); i++){
            swap(arr, i, start);
            perm(arr, start + 1);
            swap(arr, i, start);
        }
    }
}

int main(){
    vector<string> arr {"A", "B", "C"};
    permutation(arr);

    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << endl;
        }
    }
    return 0;
}