#include <iostream>


using namespace std;


int main() {

   int t,den,a,ct;

   cin>>t;

   while(t--){

       cin>>den;

       a=1,ct=0;

       while(den>0){

           den-=a;

           a=a+1;

           ct++;

       }

       cout<<ct<<"\n";

   }

   

}
