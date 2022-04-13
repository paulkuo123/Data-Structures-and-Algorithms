#include<iostream>

using namespace std;

void selectionSort(int* arr, int size){
    for (int i=0; i<=size-2; i++){
        int minIndex = i;
        for (int j=i; j<=size-1; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        // swap
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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

    selectionSort(arr, 4);
    cout << "sorted:\n";
    printArray(arr, 4);
    return 0;
}
