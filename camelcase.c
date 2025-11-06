#include <bits/stdc++.h>

using namespace std;

int camelcase(string s) {
    if (s.empty()) {
        return 0;
    }

    int word_count = 1;
    
    for (char c : s) {
        if (isupper(c)) {
            word_count++;
        }
    }
    
    return word_count;
}

int main() {
    
    return 0;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
