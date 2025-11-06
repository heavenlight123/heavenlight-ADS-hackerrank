#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> cutTheSticks(vector<int> arr) {
    vector<int> result;
    
    sort(arr.begin(), arr.end());
    
    int num_sticks = arr.size();
    
    if (num_sticks == 0) {
        return result;
    }
    
    int remaining_sticks = num_sticks;
    int current_cut_length = arr[0]; 
    int stick_index = 0; 

    while (remaining_sticks > 0) {
        result.push_back(remaining_sticks);
        
        int sticks_cut_to_zero = 0;
        
        while (stick_index < num_sticks && arr[stick_index] == current_cut_length) {
            sticks_cut_to_zero++;
            stick_index++;
        }

        remaining_sticks -= sticks_cut_to_zero;
        
        if (remaining_sticks > 0) {
            current_cut_length = arr[stick_index]; 
        }
    }
    
    return result;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = cutTheSticks(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
