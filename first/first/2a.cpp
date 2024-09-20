#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
int n,kol;
int main(){
    cout<<"Enter the amount of numbers (<9): ";
    cin>>kol;
    cout<<endl;

    unsigned char x = 0;
    for (int i=0;i<kol;i++){
        cin>>n;
        x = x | (1<<(7-n));
    }
    cout<<bitset<8>(x)<<endl;

    bitset<8> sort = x;
    for (int i=7;i>=0;i--){
        if (sort[i]==1)
        cout<<7-i<<" ";
    }
   
    return 0;
}

/*
    n = 7;
    while (n>=0){
        int tek = int(x)/pow(2,n);
        tek%=2;
        
        if (tek==1)
        cout<<7-n<<" ";
        
        n--;
    }
    */