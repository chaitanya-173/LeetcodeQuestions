class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        map<int,int> freq;
        for(auto it: hand) freq[it]++;
        sort(hand.begin(), hand.end());

        while(!freq.empty()) {
            int cur = freq.begin()->first;

            for(int i=0; i<groupSize; i++) {
                if(!freq[cur + i]) return false;
                freq[cur + i]--;
                if(freq[cur + i] == 0) freq.erase(cur + i);
            }
        }

        return true;
    }
};