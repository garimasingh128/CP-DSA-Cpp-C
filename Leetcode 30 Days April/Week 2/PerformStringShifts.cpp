class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {

        int i;
        deque<char> d;
        for(i=0;i<s.length();i++)
        {
            d.push_back(s[i]);
        }
        for(i=0;i<shift.size();i++)
        {
            if(shift[i][0]==0)
            {
                while(shift[i][1]--)
                {
                    d.push_back(d.front());
                    d.pop_front();
                }
            }
            else if(shift[i][0]==1)
            {
                while(shift[i][1]--)
                {
                    d.push_front(d.back());
                    d.pop_back();
                }
            }
        }
        s="";
        while(!d.empty())
        {
            s+=d.front();
            d.pop_front();
        }
        return s;
    }
};
