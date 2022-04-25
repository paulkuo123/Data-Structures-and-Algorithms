#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printArray(const vector<int> &v, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> merge(const vector<int> &v1, const vector<int> &v2)
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
            merged.push_back(v2[j]);
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
        merged.push_back(v2[j]);
        j++;
    }
    return merged;
}

vector<int> mergeSort(const vector<int> &v)
{
    if (v.size() == 1)
    {
        return v;
    }
    else
    {
        int middle = floor(v.size() / 2);
        vector<int> v1 = vector<int>(v.begin(), v.begin() + middle);
        vector<int> v2 = vector<int>(v.begin() + middle, v.end());
        return merge(mergeSort(v1), mergeSort(v2));
    }
}

int main()
{
    vector<int> v = {8, 1, 3, 5};
    cout << "original:\n";
    printArray(v, 4);

    vector<int> result= mergeSort(v);
    cout << "sorted:\n";
    printArray(result, 4);
    return 0;
}
