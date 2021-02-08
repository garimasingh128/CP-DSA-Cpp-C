class FirstUnique {
public:
    queue<int> q;
    unordered_map<int,int> m;
    FirstUnique(vector<int>& nums) {

        int i;
        for(i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(i=0;i<nums.size();i++)
        {
            if(m[nums[i]]==1)
                q.push(nums[i]);
        }
    }

    int showFirstUnique()
    {

        return q.size()? q.front() : -1;
    }

    void add(int value) {

        int i=++m[value];
        if(i==1)
            q.push(value);
        else
        {
            while(!q.empty() && m[q.front()]>1)
                q.pop();
        }

    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
