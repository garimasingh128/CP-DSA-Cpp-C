class Solution {
   public:
    string getPermutation(int n, int k) {
        int fact_n = 1;
        string s = "";

        for (int i = 1; i <= n; i++)
        {
            fact_n *= i;
            s += (char)(i + 48);
        }

        int k_index = k - 1;
        string ans = "";

        while (k_index)
        {
            int n = s.size();
            fact_n /= n;
            int index = (k_index / fact_n);
            ans += s[index];

            k_index -= (index * fact_n);

            s = s.substr(0, index) + s.substr(index + 1);
        }

        ans += s;
        return ans;
    }
};
