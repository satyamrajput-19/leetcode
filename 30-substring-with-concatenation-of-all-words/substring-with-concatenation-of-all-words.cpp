class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int sLen = s.length();

        if (sLen < totalLen) return result;

        unordered_map<string, int> counts;
        for (const string& word : words) {
            counts[word]++;
        }

        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            unordered_map<string, int> seen;
            int count = 0;

            for (int j = i; j <= sLen - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);

                if (counts.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > counts[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};