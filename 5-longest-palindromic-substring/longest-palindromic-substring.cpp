class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Odd length palindromes (center is s[i])
            expandAroundCenter(s, i, i, start, maxLen);
            // Even length palindromes (center is between s[i] and s[i+1])
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        int currentLen = right - left - 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
            start = left + 1;
        }
    }
};