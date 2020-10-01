#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int>person;

    //insert
    person.insert(pair<int,int>(12,56));
    person.insert({2,78});
    person.insert({6,45});
    person.insert({9,77});

    auto it=person.find(9);
    person.erase(it);

    for(auto itr=person.begin();itr!=person.end();++itr){
        cout<<itr->first<<" : "<<itr->second<<endl;
    }
    cout<<"size:"<<person.size()<<endl;
    cout<<"MAX size:"<<person.max_size()<<endl;


}