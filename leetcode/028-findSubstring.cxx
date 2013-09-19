class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> as;
        int ln = L.size();
        int sn = S.size();
        if (ln<1) return as;
        int lm = L[0].size();

        vector<string> l;
        vector<int> lct;

        sort(L.begin(), L.end());
        l.push_back(L[0]);
        lct.push_back(1);
        int li = 0;
        for (int i=1; i<ln; ++i) {
            if (L[i] != L[i-1]) {
               l.push_back(L[i]);
               lct.push_back(1);
               ++li;
            } else {
               ++lct[li]; 
            }
        }
        ++li;
       
        //cout << "li:" << li << endl;
        for (int i=0; i<lm; ++i) {
            vector<int> tmp;
            for (int j=i+lm; j<=sn; j+=lm) {
                tmp.push_back(find(l.begin(), l.end(), string(S, j-lm, lm))\
                        - l.begin());
            }
            //for (int k=0; k<tmp.size(); ++k) {
            //    cout << tmp[k] << "-";
            //}
            //cout << endl; 
            for (int k=ln; k<=tmp.size(); ++k) {
                vector<int> kct(lct);
                int j;
                for (j=k-ln; j<k; ++j) {
                   if (tmp[j]==li) break; 
                   if (kct[tmp[j]]==0) break;
                   --kct[tmp[j]];
                }
                if (j == k) {
                    as.push_back(i + (k-ln)*lm);
                    //cout << ":::" <<  i + (k-ln)*lm << endl;
                }
            }
        }
        return as;
    }
};

