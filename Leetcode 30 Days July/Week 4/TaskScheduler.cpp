class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        if(n==0)
            return (int)tasks.size();

        map<char,int> freq;

        int max_freq = 0,inc=0;

        for(int x : tasks)
        {
            freq[x]++;
            max_freq = max(max_freq, freq[x]);
        }
        int idle_time = (max_freq-1)*(n+1)+1;
        for(auto it: freq)
        {
            if(it.second==max_freq)
                inc++;
        }

        int ans = idle_time+(inc-1);

        return max(ans, (int)tasks.size());
    }
};
