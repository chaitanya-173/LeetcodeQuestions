class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Move into vector for sorting
        vector<pair<char, int>> freqVec(freq.begin(), freq.end());

        // Step 3: Sort by frequency (high to low)
        sort(freqVec.begin(), freqVec.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        // Step 4: Build result string
        string result;
        for (auto& p : freqVec) {
            result.append(p.second, p.first);  // Append char p.second times
        }

        return result;
    }
};
