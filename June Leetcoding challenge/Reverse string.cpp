
class Solution {
public:
void reverseString(vector<char>& s) {

    int low=0;
    int high=s.size()-1;
    while(low<=high)
    {
        swap(s[low],s[high]);
        low++;
        high--;
    }
    
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<" ";
    }
}
};
