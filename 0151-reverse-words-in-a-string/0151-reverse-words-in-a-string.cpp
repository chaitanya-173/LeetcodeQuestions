class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        stack<string> words;
        string ans;

        while (ss >> word) {
            words.push(word);
        }

        while(!words.empty()) {
            ans += words.top();
            words.pop();
            if(!words.empty()) ans += " ";
        }


        

        return ans;
    }
};