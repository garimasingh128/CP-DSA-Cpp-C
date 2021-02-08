
class Solution {
public:
    string reverseWords(string s) {
        string res, tmp;
        int i = 0, j, len = s.size();
        while (true) {

            while (i < len && s[i] == ' ')
                i++;

            if (i >= len)
                break;

            j = i + 1;

            while (j < len && s[j] != ' ')
                j++;
            tmp = s.substr(i, j - i);

            res = tmp + (res.size() ? " " : "") + res;

            i = j + 1;
        }
        return res;
    }
};
