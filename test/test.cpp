#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter the file name\n";
    string s;
    cin>>s;
    fstream f;
    f.open(s,ios::out);
    string l;
    while(f){
        getline(cin,l);
        cout<<l<<endl;
        if(l!="0")
        f<<l<<endl;
    }
    f.close();
    return 0;
}