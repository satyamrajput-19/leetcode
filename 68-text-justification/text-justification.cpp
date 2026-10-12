class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }

            int numWords = j - i;
            int totalSpaces = maxWidth - lineLength;
            string currentLine = "";

            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    currentLine += words[k];
                    if (k < j - 1) {
                        currentLine += " ";
                    }
                }
                currentLine.append(maxWidth - currentLine.length(), ' ');
            } else {
                int spacesBetweenWords = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int k = i; k < j; k++) {
                    currentLine += words[k];
                    if (k < j - 1) {
                        int spacesToApply = spacesBetweenWords + (extraSpaces > 0 ? 1 : 0);
                        currentLine.append(spacesToApply, ' ');
                        extraSpaces--;
                    }
                }
            }

            result.push_back(currentLine);
            i = j;
        }

        return result;
    }
};