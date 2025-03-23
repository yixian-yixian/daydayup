// 20 m, review accumulate syntax 
// stack implementation was quick
class Solution {
public:
    string simplifyPath(string path) {
      // . -> ignore 
      // .. -> remove last directory 
      vector<string> stack; 
      stringstream parser(path);
      string temp;
      while (getline(parser, temp, '/')) {
        if (temp == "..") {
          if (!stack.empty()) { stack.pop_back(); }

        } else if (temp != "." && !temp.empty()) {
          stack.push_back(temp);
        }
      }
      return (stack.empty()) ? "/" : accumulate(next(stack.begin()), stack.end(), '/' + stack[0], 
            [](std::string accumulated, const std::string& element) {
              return accumulated + '/' + element;  // concatenate with '/' separator
            });
    }
};
