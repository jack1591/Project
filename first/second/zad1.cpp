#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

struct adress{
    int num_apartment;
    int house;
    string street;
    string town;
    void out(){
        cout<<"Town: "<<town<<endl;
        cout<<"Street: "<<street<<endl;
        cout<<"House: "<<to_string(house)<<endl;
        cout<<"Apartment: "<<to_string(num_apartment)<<endl;
    }
};

struct elem{
    string phone;
    adress tek_addr;
};

vector <pair<string,int>> tabl;
elem test;
int sz = 100;

bool comp(const pair<string,int>& left,const pair<string,int>& right){
    return left.first<right.first;
}

int find_key(string key){
    int mid = 0,delta=ceil(double (tabl.size()-1)/2);
    while (delta!=0){
        mid+=delta;
        //cout<<mid<<"|||"<<delta<<"|||"<<tabl[mid].first<<endl;
        if (tabl[mid].first==key)
        break;
        if ((tabl[mid].first>key))
        delta = -ceil(double (abs(delta))/2);
        else delta = ceil(double (abs(delta))/2);
    }
    if (delta!=0)
    return tabl[mid].second;
    return -1;
}

void key_out(int url){
    ifstream fil("out.bin",ios::binary | ios::in);
    fil.seekg(sizeof(elem)*url,ios_base::beg    );
    fil.read((char*)&test,sizeof(elem)); 
    cout<<"String number: "<<url<<endl;
    cout<<"Phone number: "<<test.phone<<endl;
    test.tek_addr.out(); 
    fil.close();
}

void rand_in(){
    ofstream fout("out.bin",ios::binary | ios::out);
    for (int i=0;i<sz-1;i++){
        string s = "";
        for (int j=0;j<10;j++)
        s+=to_string(rand()%10);
        test.phone = s;
        test.tek_addr.num_apartment = rand()%200+1;
        test.tek_addr.house = rand()%5+1;
        
        test.tek_addr.street+=char (rand()%26 + 'A');
        for (int j=0;j<9;j++)
        test.tek_addr.street+=char (rand()%26 + 'a');

        test.tek_addr.town+=char (rand()%26 + 'A');
        for (int j=0;j<6;j++)
        test.tek_addr.town+=char (rand()%26 + 'a');
    
        //cout<<test.phone<<" "<<test.tek_addr.out()<<" "<<endl;
         
        fout.write((char*)&test,sizeof(elem));
        
        test.tek_addr.street="";
        test.tek_addr.town="";
    }
    test.phone = "89011763269";
    fout.write((char*)&test,sizeof(elem));
        
    fout.close();
}

void lin_poisk(string key){
    ifstream fin("out.bin",ios::binary | ios::out);
    int num = 0;
    while (fin.read((char*)&test,sizeof(elem))){
        num++;
        if (test.phone==key){
            cout<<"Answer: "<<num-1<<endl;
            num=-1;
            break;
        }
    }
    fin.close();
    if (num!=-1)
    cout<<"Not found!\n";
}

int main(){
    srand(time(0));
    cout<<"The number of objects is "<<sz<<endl;
    rand_in();
    
    

    //линейный поиск
    
    unsigned int start_time = clock();
    
    string key;
    cout<<"Enter the key: ";
    cin>>key;
    lin_poisk(key);
    
    unsigned int end_time = clock();
    cout<<"Time: "<<end_time-start_time<<endl;
    
    /*
    ifstream fix("out.bin",ios::binary | ios::in);
    cout<<"Size of information about one person: ";
    cout<<sizeof(elem)<<endl;
    fix.close();
    */

    

    //бинарный однородный поиск
    
    /*
    ifstream fin("out.bin",ios::binary | ios::in);
    for (int i=0;i<sz;i++){
    fin.read((char*)&test,sizeof(elem));
    tabl.push_back(make_pair(test.phone,i));
    }
    
    fin.close();

    sort(tabl.begin(),tabl.end(),comp);
    
    
    for (auto c:tabl)
    cout<<c.first<<" ";
    cout<<endl;
    

    string last;
    last = tabl[tabl.size()-1].first+"9";
    tabl.push_back(make_pair(last,tabl.size()));
    
    
    string num;
    cout<<"Enter the key: ";
    //cin>>num;
    num=tabl[tabl.size()-2].first;
    cout<<num<<endl;
    int x = find_key(num);
    if (x>=0)
    key_out(x);
    else cout<<"Not found!\n";
    
    unsigned int end_time = clock();
    cout<<"Time: "<<end_time-start_time<<endl;
    */   
    return 0;
}