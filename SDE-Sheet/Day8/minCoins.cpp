#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int> v,int rupees){
    int i = v.size()-1;
    int coinsCount = 0;
    while(rupees > 0){
        if(v[i] > rupees) i--;
        else{
            rupees -= v[i];
            coinsCount++;
        }
    }
    return coinsCount;
}
int main(){
    vector<int> v{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n;
    cout<< "Enter rupees:";
    cin >> n;
    cout << "Coins needed = " << findMin(v,n) << "\n";
    return 0;
}