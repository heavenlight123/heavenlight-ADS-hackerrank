#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int minimumNumber(int n, string password) {
    int missing_categories = 0;
    bool has_digit = false;
    bool has_lower = false;
    bool has_upper = false;
    bool has_special = false;
    
    const string special_chars = "!@#$%^&*()-+"; 
    
    for (char c : password) {
        if (isdigit(c)) {
            has_digit = true;
        } else if (islower(c)) {
            has_lower = true;
        } else if (isupper(c)) {
            has_upper = true;
        } else if (special_chars.find(c) != string::npos) {
            has_special = true;
        }
    }
    
    if (!has_digit) missing_categories++;
    if (!has_lower) missing_categories++;
    if (!has_upper) missing_categories++;
    if (!has_special) missing_categories++;
    
    int needed_for_categories = missing_categories;
    int needed_for_length = max(0, n - (int)password.length());
    
    return max(needed_for_categories, needed_for_length);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
