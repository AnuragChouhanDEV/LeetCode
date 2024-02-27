// https://leetcode.com/problems/text-justification/description/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        // index for main loop and internal loop respectively
        int i = 0, j = 0;
        while (i < words.size())
        {
            // add cheracters count and space count initially for each string
            int chars_count = words[i].length();
            int space_count = 0;
            // start loop from next index onwards
            j = i + 1;
            // capture character count and space count for the string
            while (j < words.size() && chars_count + space_count + 1 + words[j].length() <= maxWidth)
            {
                chars_count += words[j].length();
                space_count++;
                j++;
            }
            // get the spaces required in between
            int space_req = maxWidth - chars_count;
            int spaces = (space_count == 0) ? 0 : space_req / space_count;
            int extra_space = (space_count == 0) ? 0 : space_req % space_count;
            // if we reach the end the no extra spaces are required
            if (j == words.size())
            {
                spaces = 1;
                extra_space = 0;
            }
            // take an empty string to populate result
            string str;
            for (int k = i; k < j; ++k)
            {
                // add string as it is
                str += words[k];
                // check if we reached the end
                if (k == j - 1)
                    break;
                // populate spaces
                for (int p = 0; p < spaces; ++p)
                {
                    str.push_back(' ');
                }
                // populate extra space
                if (extra_space > 0)
                {
                    str.push_back(' ');
                    extra_space--;
                }
            }
            // if width is more insert spaces
            while (str.length() < maxWidth) {
                str.push_back(' ');
            }
            // push the string in result
            res.push_back(str);
            // start from j ornwards
            i = j;
        }
        return res;
    
    }
};