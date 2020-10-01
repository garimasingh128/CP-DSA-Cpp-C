#include<iostream>
using namespace std;
int main(){
    int a,b,i;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;
    for(i=(a>b?b:a);i>1;i--){
        if(a%i==0 && b%i==0){
            cout<<"HCF is "<<i<<endl;
            break;
        }
    }
}