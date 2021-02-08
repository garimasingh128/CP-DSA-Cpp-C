struct TrieNode{
    int v;
    TrieNode* next[26];
    TrieNode(): v(0){
        memset(next, NULL, sizeof(next));
    }
};
class Solution {
public:


    void backtrack(int x, int y, vector<vector<char> > &board, TrieNode *node, vector<string> &ans, string &cur){
        char tmp = board[x][y];
        board[x][y] = '#';
        node = node->next[tmp-'a'];
        if(node->v > 0){
            ans.push_back(cur);
            node->v--;
        }

        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int i=0; i<4; ++i){
            int x_ = x+dir[i][0], y_ = y+dir[i][1];
            if(x_ >= 0 && x_ < board.size() && y_ >= 0 && y_ < board[0].size() && board[x_][y_] != '#' && node->next[board[x_][y_]-'a']){
                cur.push_back(board[x_][y_]);
                backtrack(x_, y_, board, node, ans, cur);
                cur.pop_back();
            }
        }
        board[x][y] = tmp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || words.empty()) return vector<string>();
        TrieNode *root = new TrieNode();
        for(auto &word: words){
            TrieNode *ptr = root;
            for(auto &c: word){
                if(!ptr->next[c-'a'])
                    ptr->next[c-'a'] = new TrieNode();
                ptr = ptr->next[c-'a'];
            }
            ptr->v++;
        }

        vector<string> ans;
        ans.reserve(words.size());
        int N = board.size(), M = board[0].size();
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(root->next[board[i][j]-'a']){
                    string cur = "";
                    cur.push_back(board[i][j]);
                    backtrack(i, j, board, root, ans, cur);
                }
            }
        }
        return ans;
    }
};
