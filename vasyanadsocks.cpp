#include <bits/stdc++.h>

using namespace std;

int main(){

    int a,b,ans = 0;
    cin >> a >> b;
    while(a > 0){
        ans++;
        a--;
        if(ans%b == 0)a++;
    }
    cout << ans << endl;
    return 0;
}
