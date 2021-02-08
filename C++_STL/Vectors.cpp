#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec;
    vec.push_back(3);
    vec.push_back(10);
    vec.push_back(67);
    vec.pop_back();
    auto a=vec.begin();
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }

}