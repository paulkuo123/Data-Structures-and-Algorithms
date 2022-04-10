#include<iostream>

using namespace std;

void insertionSort(int* arr, int size){
    for (int j=1; j<size; j++){
        int key = arr[j];
        int i = j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}

int smallValue(int* arr, int size){
    int smallest = arr[0];
    for (int i=1; i<size; i++){
        if (arr[i] < smallest)
            smallest = arr[i];
    }
}

void printArray(const int *arr, int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[4] = {8, 1, 3, 5};
    cout << "original:\n";
    printArray(arr, 4);

    insertionSort(arr, 4);
    cout << "sorted:\n";
    printArray(arr, 4);
    return 0;
}
