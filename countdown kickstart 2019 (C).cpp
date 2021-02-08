#include<iostream>
using namespace std;
#define ll long long
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll int t;
    cin>>t;
    ll int x=1;
    
    while(t>0){
        
       ll int count=0;
        
        ll int n;
        cin>>n;
        ll int k;
        cin>>k;
        
        ll int arr[n];
        for(ll int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        for(ll int i=0;i<n-k+1;i++){
            if(arr[i]==k){
               ll int p=k;
                ll int h=1;
                for(ll int j=i+1;j<i+k;j++){
                    p--;
                    if(arr[j]==p){
                        h++;
                    }
                }
                
                if(h==k){
                    count++;
                }
            }
        }
        
        cout<<"Case #"<<x<<": "<<count<<endl;
        
        x++;
        t--;
    }
    
    return 0;
}