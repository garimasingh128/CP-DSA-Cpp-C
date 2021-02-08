#include<iostream>
#include<queue>
using namespace std;
void show(queue<int>Q){
    queue<int>q=Q;
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
        
    }
    

}
int main(){
    queue<int>q;
    q.push(1);
    q.push(8);
    q.push(67);
    q.push(5);
    q.push(6);

    show(q);
    cout<<endl;
    cout<<"size:"<<q.size()<<endl;
     cout<<"front:"<<q.front()<<endl;
      cout<<"back:"<<q.back()<<endl;

}