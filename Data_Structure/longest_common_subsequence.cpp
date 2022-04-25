#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Recursion
int simpleLCS(string str1, string str2){
    if (str1.length() == 0 || str2.length() == 0){
        return 0;
    }
    else if (str1.substr(str1.length()-1, 1) == str2.substr(str2.length()-1, 1)){
        return 1 + simpleLCS(str1.substr(0, str1.length() - 1), str2.substr(0, str2.length() - 1));
    }
    else{
        return max(simpleLCS(str1.substr(0, str1.length() - 1), str2), 
                   simpleLCS(str1, str2.substr(0, str2.length() - 1)));
    }
}

// Dynamic Programming
int** table1;
string** table2;
string x;
string y;
string result = "";

void LCS(string str1, string str2){
    int m = str1.length();
    int n = str2.length();

    table1 = new int*[m+1];
    table2 = new string*[n+1];

    // Table1
    for(int i = 0; i <= m; i++){
        table1[i] = new int[n+1];
        table1[i][0] = 0;
        for(int j = 1; j <= n; j++){
            table1[i][j] = -1;
        }
    }

    for (int i = 0; i <= n; i++){
        table1[0][i] = 0;
    }

    //Table2
    for(int i = 0; i <= m; i++){
        table2[i] = new string[n+1];
        for(int j = 0; j <= n; j++){
            table2[i][j] = " ";
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(str1[i - 1] == str2[j - 1]){
                table1[i][j] = 1 + table1[i - 1][j - 1];
                table2[i][j] = "↖";
            }
            else if(table1[i -1][j] >= table1[i][j - 1]){
                table1[i][j] = table1[i - 1][j];
                table2[i][j] = "↑";
            }
            else{
                table1[i][j] = table1[i][j -1];
                table2[i][j] = "←";
            }
        }
    }
}

void printLCS(int i, int j){
    if (i == 0 || j == 0){
        return;
    }
    if (table2[i][j] == "↖"){
        printLCS(i - 1, j -1);
        result += x[i - 1];
    }
    else if (table2[i][j] == "↑"){
        printLCS(i - 1, j);
    }
    else if(table2[i][j] == "←"){
        printLCS(i, j - 1);
    }
}

int main(){
    // cout << simpleLCS("ATAACGCGCTGCTCGGGT", "TCAATCAGGATCCGCTGA");
    x = "ABB";
    y = "ABC";

    LCS(x, y);

    // for(int i = 0; i <= 3; i++){
    //     for (int j = 0; j <= 3; j++){
    //         cout << table2[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    printLCS(x.length(), y.length());
    cout << result << endl;


    //delete
    for (int i = 0; i <= x.length(); i++){
        delete [] table1[i];
    }
    delete [] table1;

    for (int i = 0; i <= x.length(); i++){
        delete [] table2[i];
    }
    delete [] table2;
}