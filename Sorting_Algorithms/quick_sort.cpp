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

void swap(int &p1, int &p2)
{
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

int partition(vector<int> &arr, int p, int r)
{
    int pivot = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i + 1;
}

void quickSort(vector<int> &arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main()
{
    vector<int> arr = {5, 1, 8, 10, 2, 17, 7, 3, 20, 11, 21, 6};
    cout << "original:\n";
    printArray(arr, arr.size());

    quickSort(arr, 0, arr.size() - 1);
    cout << "sorted:\n";
    printArray(arr, arr.size());
    return 0;
}
