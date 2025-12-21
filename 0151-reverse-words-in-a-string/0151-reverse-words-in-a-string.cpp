class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        stack<string> words;
        string word;
        while(ss >> word) {
            words.push(word);
        }

        string ans;
        while(!words.empty()) {
            ans += words.top();
            words.pop();
            if(!words.empty()) ans += " ";
        }

        return ans;
    }
};