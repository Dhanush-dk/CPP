// Correct way of declaring a constant variable:
const int i = 3; // constant varible must be initialized at the time of assignment

//Wrong ways of declaring a constant variable:
1)
const int i; // is not initialized at the time of assigment
i = 3;

2) 
const int i; // is left un-initialized


Constant keyword with pointer variables:

1) When Pointer variable points to constant value:

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int m = 3;
    const int* i = &n;
    *i = 8; //Error. Because the pointer variable points to the constant value Which is like read only.
    n = 8; //Now the value is changed.
	i = &m; // Pointer pointing to the address can be changed.
    cout << "*i == "<< *i << "\n";
    cout << "n == "<< n << "\n";
    cout << "Both values are same.";

    return 0;
}

2) When constant pointer variable points to a value:

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int m = 3;
    int* const i = &n;
    *i = 7; // Value can be changed
    i = &m; // Error. The address pointing by the constant pointer type variable cannot be changed.
    cout << "*i == "<< *i << "\n";
    cout << "n == "<< n << "\n";
    cout << "Both values are same.";

    return 0;
}

3) When constant pointer pointing to the constant variable:

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 2;
	int m = 4;
	const int* const i = &n;
	*i = 5; // CTE.
	i = &m; // CTE.
	// The address and the value in the address cannot be changed.
	cout << *i;
	return 0;
}


4) Passing const argument value to non const parameter of a function causes error:

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int func(const int *n){ // Here mentioning const is mandatory Otherwise throws CTE.
    return *n + 2;
}
int main(){
	const int n = 2;
	cout << func(&n); // Output is 4;
	return 0;
}

Const Methods/Functions can be declared in two ways:

1. For const functions in class:
	class{
		void foo() const{
			//statement;
		}
	};

2. For non class const functions:

	const void foo(){ // Not void foo() const
		//statement;
	}


// An example program for First type:
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class car{
    int price;
    public:
        car(int val){
            price = val;
        }
        void addPrice(int val){
            price += val;
        }
        int getPrice() const{
            return price;
        }
        void setPrice(int val){
            price = val;
        }
};
int main()
{
    car obj(34000);
    obj.addPrice(4000);
    cout << obj.getPrice() << endl;
    
    const car constantObj(1000);
    // constantObj.addPrice(1000);  // This is not possible. Because the constant price cannot be changed since it's a constant object.
    cout << constantObj.getPrice() << endl;
    // constantObj.setPrice(3000); // This is not possible. Because the constant price cannot be changed since it's a constant object.
    cout << constantObj.getPrice() << endl;
    
    return 0;
}

Output:
38000
1000
1000
	
	
// An example program for second type
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int update(const int n){
	n--; // CTE since the variable passed in the parameter is const type.
    return n * n;
}
int main()
{
    const int n = 4;
    int m = 5;
    cout << update(n) << endl;
	// n = update(n); // CTE since it's const variable. We cannot change the constant variable.
    m = update(m);
    cout << m;
    return 0;
}

Without n-- line the output is 
16
25
