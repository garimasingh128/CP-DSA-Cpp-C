class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0) return 1;
        string bin="";
        while(N>0){
            int rem=N%2;
            bin+=to_string(rem);
            N/=2;
        }
        int ans=0;
        for(int i=0;i<bin.size();i++){
            if(bin[i]=='0'){
                ans+=pow(2,i);
            }
        }
        return ans;
    }
};
