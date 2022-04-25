#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printArray(const vector<int> v, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void swap(int &p1, int &p2){
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

void maxHeapify(vector<int> &arr, int root, int heapSize){
    int largest;
    int l = root * 2 + 1;
    int r = root * 2 + 2;

    if (l <= heapSize && arr[l] > arr[root])
        largest = l;
    else
        largest = root;
    if (r <= heapSize && arr[r] > arr[largest])
        largest = r;
    if (largest != root){
        swap(arr[root], arr[largest]);
        maxHeapify(arr, largest, heapSize);
    }
}

void buildMaxHeap(vector<int> &arr){
    int heapSize = arr.size()-1;
    for (int i = floor(heapSize / 2); i >= 0; i--){
        maxHeapify(arr, i, heapSize);
    }
}

void heapSort(vector<int> &arr)
{
    buildMaxHeap(arr);
    int heapSize = arr.size()-1;
    for (int i = heapSize; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapSize -= 1;
        maxHeapify(arr, 0, heapSize);
    }
}

int main()
{
    vector<int> arr = {5, 1, 8, 10, 2, 17, 7, 3, 20, 11, 21, 6};
    cout << "original:\n";
    printArray(arr, 12);

    heapSort(arr);
    cout << "sorted:\n";
    printArray(arr, 12);
    return 0;
}
