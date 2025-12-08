class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    
    void backtrack(string &word, string &beginWord, vector<string> &path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &p : parent[word]) {
            path.push_back(p);
            backtrack(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return {};

        unordered_map<string, int> dist;
        queue<string> q;

        q.push(beginWord);
        dist[beginWord] = 0;

        int L = beginWord.size();

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int d = dist[word];

            for (int i = 0; i < L; i++) {
                string next = word;
                char orig = next[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    next[i] = ch;
                    if (!words.count(next)) continue;

                    if (!dist.count(next)) {
                        dist[next] = d + 1;
                        q.push(next);
                    }

                    if (dist[next] == d + 1) {
                        parent[next].push_back(word);
                    }
                }
                next[i] = orig;
            }
        }

        if (!dist.count(endWord)) return {};

        vector<string> path = { endWord };
        backtrack(endWord, beginWord, path);

        return ans;
    }
};
