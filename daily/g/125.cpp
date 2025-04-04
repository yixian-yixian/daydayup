class Solution {
    public:
        bool isPalindrome(string s) {
            int l = 0;
            int r = s.size() - 1;
            while (l < r)
            {
                if (!isalnum(s.at(l)))
                {
                    l++;
                    continue;
                }
    
                if (!isalnum(s.at(r)))
                {
                    r--;
                    continue;
                }
    
                if (tolower(s.at(l++)) != tolower(s.at(r--)))
                {
                    return false;
                }
            }
            return true;
        }
    };