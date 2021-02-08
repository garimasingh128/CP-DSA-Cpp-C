#include<iostream>
#include<list>
using namespace std;
void show(list<int>l){
   list<int>::iterator it;
   for(it=l.begin();it!=l.end();it++){
       cout<<*it<<" ";
   }
    

}
    


int main(){
    list<int>l;
    list<int>::iterator it;
    l.push_back(3);
    l.push_back(4);
    l.push_back(7);
    l.push_back(55);
    l.push_back(9);

  it=l.begin();
  cout<<*it;
  show(l);
  cout<<endl;
  //l.clear();
  cout<<"front :"<<l.front()<<endl;
  cout<<"back:"<<l.back()<<endl;

}