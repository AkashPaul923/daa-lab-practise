#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int data[n];
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    int k=0,l=0,m=data[0];
    for(int i=0;i<n;i++){
        if(m<data[k]){
            l=k;
            m=data[k];
        }
        k=k+1;
    }
    cout<<"LOCATION :"<<l<<endl<<"LARGEST ELEMENT :"<<m;
return 0;
}
