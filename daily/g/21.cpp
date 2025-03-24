// 21 minutes, need syntax help for lambda function
class Solution {
    public:
        string simplifyPath(string path) {
            path.push_back('/');
            vector<string> st;
            int start = 0;
            int pos;
            while ((pos = path.find("/", start)) != string::npos)
            {
                string substring = path.substr(start, pos - start);
                if (substring.size())
                {
                    if (substring == "..")
                    {
                        if (st.size())
                        {
                            st.pop_back();
                        }
                    } else if (substring != ".")
                    {
                        st.push_back(substring);
                        cout << "pushing " << substring << endl;
                    }
                }
                start = pos + 1;
            }
            string base = "";
            string res = accumulate(st.begin(), st.end(), base, [](string a, string b){ return std::move(a) + "/" + b;});
            return res.size() ? res : "/";
        }
    };