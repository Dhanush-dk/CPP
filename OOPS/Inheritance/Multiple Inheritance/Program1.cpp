Practice Qn from codesdope.com

Create two classes named Mammals and MarineAnimals. 
Create another class named BlueWhale which inherits both the above classes.
Now, create a function in each of these classes which prints "I am mammal",
                                                             "I am a marine animal" and
                                                             "I belong to both the categories: Mammals as well as Marine Animals" respectively. 
Now, create an object for each of the above class and try calling
1 - function of Mammals by the object of Mammal
2 - function of MarineAnimal by the object of MarineAnimal
3 - function of BlueWhale by the object of BlueWhale
4 - function of each of its parent by the object of BlueWhale



#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Mammals{
    public:
    void print1(){
        cout << "I am Mammal." << endl;
    }
};
class MarineAnimals{
    public:
    void print2(){
        cout << "I am Marine Animal." << endl;
    }
};
class BlueWhale : public Mammals, public MarineAnimals{
    public:
    void print3(){
        cout << "I belong to both categories: Mammals as well as MarineAnimals" << endl;
    }
};
int main()
{
    Mammals mammal;
    mammal.print1();
    
    MarineAnimals marine;
    marine.print2();
    
    BlueWhale whale;
    whale.print3();
    whale.print2();
    whale.print1();

    return 0;
}
