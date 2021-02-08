class Solution {
public:
    int countElements(vector<int>& arr) {

        int i,c=0;
        unordered_map<int,int> m;
        for(i=0;i<arr.size();i++)
        {
            m[arr[i]]=1;
        }
        for(i=0;i<arr.size();i++)
        {
            if(m[arr[i]+1]==1)
                c++;
        }
        return c;

    }
};
