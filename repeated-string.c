#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

long repeatedString(string s, long n) {
    if (s.empty()) {
        return 0;
    }
    
    long count_a_in_s = 0;
    for (char c : s) {
        if (c == 'a') {
            count_a_in_s++;
        }
    }
    
    long len_s = s.length();
    
    long full_repetitions = n / len_s;
    long total_a = full_repetitions * count_a_in_s;
    
    long remainder_length = n % len_s;
    
    for (int i = 0; i < remainder_length; ++i) {
        if (s[i] == 'a') {
            total_a++;
        }
    }
    
    return total_a;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
