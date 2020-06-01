 #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    int main(){
        ll t;
        std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        cin>>t;
        while(t--){
            ll x1=INT_MAX,y1=INT_MAX,x2=INT_MIN,y2=INT_MIN;
            ll x,y;
            ll n;
            cin>>n;
            while(n--){
                cin>>x>>y;
                if(x<x1)
                {
                    x1=x;
                }
                if(y<y1)y1=y;
                if(x>x2){
                    x2=x;
                }
                if(y>y2)y2=y;
            }
            if(abs(x1-x2)>=abs(y1-y2))cout<<abs(x1-x2)*abs(x1-x2)<<"\n";
            else cout<<abs(y1-y2)*abs(y1-y2)<<"\n";
        }
    }
    
//    A painter accidentally spilled a few drops of red paint on a sidewalk which he was painting blue. He now needs to repaint the area over which the drops fell. However, he does not want to paint each drop seperately because that would mean a lot of paint wasted, as he does not have a small brush. So he wants to calculate the smallest area that covers all of the dots. Also, he wants this area to be a square patch. Will you help him find the area of this patch?
//
//Input:
//
//The first line of input contains , the number of test cases.
//
//Each test case consists of a single positive integer N, denoting the number of points of spillage, and the next  lines contain  and , denoting the coordinates of the  drop.
//
//Output:
//
//For each test-case, output a single non-negative integer denoting the minimum area of the square patch that encloses all drops inside or on its boundary.
//
//Constraints:
//
//



