#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
unsigned char x[8];
int n;
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        int cnt;
        cin>>cnt;
        x[cnt/8] |= (1<<(7-cnt%8));   
    }
    
   
    for (int i=0;i<8;i++){
        
        bitset<8> sort = x[i];
        for (int j=7;j>=0;j--)
        if (sort[j]==1)
        cout<<i*8+7-j<<" ";
        
    }
    return 0;
}

/*
        n=7;
        while (n>=0){
            unsigned char tek = x[i] / pow(2,n);
            if (tek%2==1)
            cout<<i*8+7-n<<" ";
            n--;
        }
        */