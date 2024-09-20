#include <iostream>
#include <fstream>
#include <bitset>
#include <ctime>
#include <cmath>
using namespace std;
int main(){
    unsigned int start_time = clock();
    bitset<8*1024*1024>sort(0);
    
    fstream fin("input3a.txt");
    
    int x;
    while (fin>>x)
    sort[x]=1;
    
    fin.close();

    fstream fout("output3a.txt");

    for (int i=0;i<sort.size();i++)
    if (sort[i]==1)
    fout<<i<<" ";

    fout.close();
    unsigned int end_time = clock();
    cout<<"Programm working time: "<<end_time-start_time<<endl;
    cout<<"Array size: "<<sizeof(sort)<<endl;
    
    return 0;
    
}