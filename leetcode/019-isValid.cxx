class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack< char > st;
        string::iterator it = s.begin();
        while (it != s.end()) {
            if (*it == '(') {
                st.push(')');
            }else if (*it == '{') {
                st.push('}');
            }else if(*it=='[') {
                st.push(']');
            } else {
                if (st.empty()) return false;
                if (st.top() == *it) st.pop();
                else return false;
            }
            ++it; 
        }
        if (st.empty()) return true;
        return false;
    }
};

