#include <bits/stdc++.h>

using namespace std;

//#define _DEBUG 0

vector<string> split_string(string);

void pr( const vector<long long>& v, long long& max )
{
    for( const auto& it: v)
    {
        cout << it <<  " ";
    }
    cout << " max value: "<< max << "\n";
}

long long arrayManipulation(int n, vector<vector<int>>& queries)
{
    vector<long long> m;
    m.assign(n,0);
    long long max  = 0;
    for( const auto& q: queries )
    {
        priority_queue<long long, vector<long long>> maxq;
        for(  long long i = q[0]-1; i < q[1]; i++)
        {
            m[i] = m[i] + q[2];
            maxq.emplace( m[i] );
        }
        if ( maxq.top() > max )
            max = maxq.top();
#ifdef _DEBUG            
        pr( m, max );
#endif
    }

    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
