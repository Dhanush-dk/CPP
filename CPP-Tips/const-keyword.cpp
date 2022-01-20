1) When Pointer variable points to constant value:

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int m = 3;
    const int* i = &n;
    *i = 8; //TLE error.Value cannot be changed using the pointer variable.
    n = 8; //Now the value is changed.
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
    *i = &m; // TLE error. The address pointing by the variable cannot be changed.
    cout << "*i == "<< *i << "\n";
    cout << "n == "<< n << "\n";
    cout << "Both values are same.";

    return 0;
}

// 3) When constant pointer pointing to the constant variable:

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n = 2;
// 	const int* const i = &n;
	
// }
