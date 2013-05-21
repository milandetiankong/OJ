class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows == 1) return s;

        string as;
        int n = s.size();
        int rows = 1, step = 2 * (nRows-1), left=0;
        
        for (int i=0; i<n; i+=step) {
            as.push_back(s[i]);
        }
        step -= 2;
        left += 2;

        while(rows < nRows-1) {
            int i = rows;
            while (i < n) {
                as.push_back(s[i]);
                i += step;
                if (i < n) as.push_back(s[i]);
                i += left;
            }
            step -= 2;
            left += 2;
            ++rows;
        } 

        for (int i=nRows-1; i<n; i+=left) {
           as.push_back(s[i]); 
        }

        return as;
    }
};

