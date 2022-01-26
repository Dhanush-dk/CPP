// Make a class named Fruit with a data member to calculate the number of fruits in a basket.
// Create two other class named Apples and Mangoes to calculate the number of apples and mangoes in the basket. 
// Print the number of fruits of each type and the total number of fruits in the basket.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Fruits{
    public:
    static int totalFruits;
    void update(int);
    // void update(int val){
    //     totalFruits += val;
    // }
    void print(){
        cout << "Total Fruits = " << totalFruits << endl;
    }
};

class Apples : public Fruits{
    public:
    static int totalApples;
    void add(int val){
        totalApples += val;
        update(val);
    }
    void print(){
        cout << "Total Apples = " << totalApples << endl;
    }
};

class Mangoes : public Fruits{
    public:
    static int totalMangoes;
    void add(int val){
        totalMangoes += val;
        Fruits::update(val);
    }
    void print(){
        cout << "Total Mangoes = " << totalMangoes << endl;
    }
};

int Fruits:: totalFruits = 0;
int Mangoes :: totalMangoes = 0;
int Apples :: totalApples = 0;

void Fruits::update(int val){
    totalFruits += val;
}

int main()
{
    Fruits fruit;
    Apples apple;
    Mangoes mango;
    
    apple.add(4);
    apple.add(4);
    mango.add(5);
    apple.add(8);
    
    apple.print();
    mango.print();
    fruit.print();
    return 0;
}

OUTPUT:
Total Apples = 16
Total Mangoes = 5
Total Fruits = 21
