#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> merge(vector<int> &v1, vector<int> &v2)
{
    vector<int> merged;
    int i = 0;
    int j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            merged.push_back(v1[i]);
            i++;
        }
        else
        {
            merged.push_back(v2[i]);
            j++;
        }
    }

    while (i < v1.size())
    {
        merged.push_back(v1[i]);
        i++;
    }

    while (j < v2.size())
    {
        merged.push_back(v2[i]);
        j++;
    }
    return merged;
}

void mergeSort(const vector<int> &v)
{
    if (v.size() == 1)
    {
        return;
    }
    else
    {
        int middle = floor(v.size() / 2);
        vector<int> v1 = vector<int>(v.begin(), v.begin() + middle);
        vector<int> v2 = vector<int>(v.begin() + middle + 1, v.end());
        mergeSort(merge(v1, v2));
    }
}

void printArray(const vector<int> &v, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v1 = {8, 1, 3, 5};
    vector<int> v2 = {2, 4, 7, 9};
    vector<int> v3 = merge(v1, v2);
    printArray(v3, 8);

    // vector<int> v = {8, 1, 3, 5};
    // cout << "original:\n";
    // printArray(v, 4);

    // vector<int> result= mergeSort(v);
    // cout << "sorted:\n";
    // printArray(v, 4);
    // return 0;
}
