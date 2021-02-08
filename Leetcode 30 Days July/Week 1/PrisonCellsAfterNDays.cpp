class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N)
    {
        vector<int> Ans(8, 0);
        vector<vector<int> > lookup;

        while(N--)
        {
            for(int j=1; j<7; ++j)
            {
                if(cells[j-1] ^ cells[j+1]) Ans[j] = 0;
                else Ans[j] = 1;
            }

            if(lookup.size() && lookup.front() == Ans)
            {
                return lookup[N % lookup.size()];
            }
            else lookup.push_back(Ans);

            cells = Ans;
        }

        return cells;
    }
};
