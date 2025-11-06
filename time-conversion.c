#include <bits/stdc++.h>

using namespace std;


string timeConversion(string s) {
    string ampm = s.substr(8, 2);
    string hour_str = s.substr(0, 2);
    int hour = stoi(hour_str);

    if (ampm == "PM") {
        if (hour != 12) {
            hour += 12;
        }
    } else {
        if (hour == 12) {
            hour = 0;
        }
    }

    stringstream ss;
    ss << setfill('0') << setw(2) << hour << s.substr(2, 6);

    return ss.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
