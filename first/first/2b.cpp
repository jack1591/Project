#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
int n;
int main(){
    unsigned long long x = 0;
    int cnt;
    cin>>cnt;
    for (int i=0;i<cnt;i++){
        cin>>n;
        unsigned long long a = 1;
        x = x | (a<<(63-n));
        //cout<<bitset<64>(x)<<endl;
    }
    cout<<bitset<64>(x)<<endl;
    
    bitset<64> sort = x;
    for (int i=63;i>=0;i--){
        if (sort[i]==1)
        cout<<63-i<<" ";
    }

    return 0;
}

/*
    n = 63;
    while (n>=0){
        long long tek = x/pow(2,n);
        tek%=2;
        
        if (tek==1)
        cout<<63-n<<" ";

        n--;
    }
    */