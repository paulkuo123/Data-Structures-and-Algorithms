#include <iostream>
#include <cmath>

using namespace std;

class HashTable{
    private:
    int size;

    public:
    HashTable();
    int hash1(int key);
    int hash2(int key);
    void set(int key, int value);
    void get(int key);
    void printAll();
};

HashTable::HashTable(){

}

// division method
int HashTable::hash1(int key){
    return key % size;
}

// multiplication method
int HashTable::hash2(int key){
    int A = (sqrt(5) - 1) / 2;
    return floor(size * (key * A) % 1);
}

int main(){
    HashTable hashTable;
    hashTable.hash2(2);
    return 0;
}