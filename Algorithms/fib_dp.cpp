#include <iostream>
using namespace std;

int fib(int n){
    if (n == 0 || n == 1){
        return 1;
    }

    int state0 = 1;
    int state1 = 1;
    for (int i = 2; i < n; i++){
        int temp = state1;
        state1 += state0;
        state0 = temp;
    }
    return state1;
}

int main(){
    int n = 5;
    cout << fib(n) << endl;
    return 0;
}