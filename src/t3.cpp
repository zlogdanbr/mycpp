#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

inline void insertInLine( long long* line, int n, const vector<int>& q )
{
    if ( q[1]-q[0] == 1  )
    {
        line[ q[0] - 1 ] = line[ q[0] -1 ] + q[2];
        line[ q[1] - 1 ] = line[ q[0] - 1 ];
        return;
    }
    else if ( q[1] == q[0])
    {
        line[ q[0] - 1 ] = line[ q[0] -1 ] + q[2];   
        return;    
    }
    else
    {
        for( int i = q[0]-1 ; i < ( q[1] ); i++ )
        {
            line[i] = line[i] + q[2];
        }
        return;
    }
}

inline long long  findMAX( long long* line, int n )
{
    long long* i1; 
    i1 = std::upper_bound( line, line + n, line[0] );  
    return *i1;
}

// Complete the arrayManipulation function below.
inline long long arrayManipulation(int n, const vector<vector<int>>& queries) 
{
    long long max =  0;
    long long* v = new long long [ n ];
    
    for( auto it = queries.cbegin(); it != queries.cend(); it++ )
    {
        insertInLine( v, n,  *it );
    }

    max = findMAX( v , n );

    if ( v != nullptr )
    {
        delete[] v;
        v = nullptr;
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
