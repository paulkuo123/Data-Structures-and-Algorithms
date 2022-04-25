#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n){
    for (int i=0; i<=n-2; i++){
        bool swapping = false;
        for (int j=n-1; j>=i+1; j--){
            if (arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                swapping = true;
            }
        }
        if (swapping == false)
            break;
    }
}

int main() {
    int arr[4]{7, 2, 9, 5};
    int arrLength = *(&arr + 1) - arr;

    bubbleSort(arr, arrLength);

    for (int i=0; i<4; i++)
        cout << arr[i] << " ";
    return 0;
}
