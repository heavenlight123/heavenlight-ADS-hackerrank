#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int alternate(string s) {
    set<char> unique_chars;
    for (char c : s) {
        unique_chars.insert(c);
    }
    
    vector<char> distinct_chars(unique_chars.begin(), unique_chars.end());
    
    int max_length = 0;
    
    for (size_t i = 0; i < distinct_chars.size(); ++i) {
        for (size_t j = i + 1; j < distinct_chars.size(); ++j) {
            char c1 = distinct_chars[i];
            char c2 = distinct_chars[j];
            
            string t = "";
            for (char c : s) {
                if (c == c1 || c == c2) {
                    t += c;
                }
            }
            
            bool is_alternating = true;
            if (t.length() > 1) {
                for (size_t k = 0; k < t.length() - 1; ++k) {
                    if (t[k] == t[k+1]) {
                        is_alternating = false;
                        break;
                    }
                }
            } 

            if (is_alternating) {
                if (t.length() > max_length) {
                    max_length = t.length();
                }
            }
        }
    }
    
    return max_length;
}
