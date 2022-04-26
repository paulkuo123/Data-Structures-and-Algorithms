#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> ps(string str){
    vector<int> psArray(str.length(), 0);
    int n = 0;
    for (int i = 1; i < str.length(); i++){
        if (str[i] != str[n]){
            psArray[i] = 0;
            n = 0;
        }
        else if (str[i] == str[n]){
            psArray[i] = n + 1;
            n++;
        }
    }
    psArray.insert(psArray.begin(), -1);
    psArray.pop_back();
    return psArray;
}

int KMP(string str1, string str2){
    vector<int> psArray = ps(str2);
    int i = 0;
    int j = 0;
    int counter = 0;
    while (i < str1.length())
    {
        if (str1[i] == str2[j] && j < str2.length()){
            if (j == str2.length() -1){
                counter++;
                j = 0;
            }
            else{
                j++;
            }
            i++;
        }
        else if (str1[i] != str2[j]){
            i = i - psArray[j];
            j = 0;
        }
    }
    return counter;
}

int main(){
    int counter = KMP("ACEFBABC BDIJCABC", "ABC");
    cout << counter << endl;
    return 0;
}