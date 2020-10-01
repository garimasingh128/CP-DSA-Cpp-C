class Node {
public:
    Node(): end(false), next(26, NULL) {}
    bool end;
    vector<Node*> next;
};

class Trie {
public:
    Trie() {
        root = new Node();
    }

    void add(string& str) {
        Node* node = root;
        for (auto& c: str) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new Node();
            node = node->next[c - 'a'];
        }
        node->end = true;
    }

    vector<string> dfs(const string& s, int idx, unordered_map<int, vector<string>>& mp) {
        if (idx == s.size()) return vector<string>{""};
        if (mp.count(idx)) return mp[idx];
        Node* node = root;
        vector<string> ret;
        for (int i = idx; i < s.size(); ++i) {
            if (!node->next[s[i] - 'a']) break;
            node = node->next[s[i] - 'a'];
            if (node->end) {
                vector<string> sub_ret = dfs(s, i + 1, mp);
                string cur_str = s.substr(idx, i + 1 - idx);
                for (auto& str: sub_ret) {
                    ret.push_back(cur_str + (str.size() ? " " : "") + str);
                }
            }
        }
        return mp[idx] = ret;
    }

private:
    Node* root;
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) return vector<string>();
        Trie trie;
        for (auto& word: wordDict) {
            trie.add(word);
        }
        unordered_map<int, vector<string>> mp;
        return trie.dfs(s, 0, mp);
    }
};

