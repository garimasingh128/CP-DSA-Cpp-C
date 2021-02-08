bool compare(vector<int> a,vector<int> b)
{
    if(a[0]==b[0])
        return b[1]>a[1];
    return a[0]>b[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

       sort(people.begin(),people.end(),compare);
        vector<vector<int> > f;
        for(int i=0;i<people.size();i++)
        {
            f.insert(f.begin()+people[i][1],people[i]);
        }
        return f;

    }
};
