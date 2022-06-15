#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void split(string const &vec_element, vector<string> &set) // function to split individual lines to separate sequences
{
    // make a stream
    stringstream ss(vec_element);

    string buffer; // a temporary placeholder
    while (std::getline(ss, buffer,' ')) {    //getline to split, just like with cin below
        set.push_back(buffer);
    }
}

int min(vector<int> b, int a)
{
    b.erase(b.begin() + a);
    int result = *min_element(b.begin(), b.end());
    return result;
}

int max(vector<int> b)
{
    int result = *max_element(b.begin(), b.end());
    return result;
}

double mean(vector<int> b)
{
    double sum = 0;
    for(int i : b)
    {
        sum = sum + i;
    }

    return sum / (b.size() - 1);
}

double med(vector<int> b, int a)
{
    b.erase(b.begin() + a);
    sort(b.begin(), b.end());

    double low = b[b.size() / 2 - 1];
    double high = b[b.size() / 2];
    if (b.size() % 2 == 0)
    {
        double result = (low + high) / 2;
        return result;
    }
    else
    {
        double result = high;
        return result;
    }
}

int occ(vector<string> b, string a)
{
    int c = 0;                          // counter
    for(auto & i : b) {
        string s = i;
        int count = 0;
        size_t index = s.find(a, 0); // first occurrence
        while(index != string::npos)
        {
            count++;
            index = s.find(a, index + 1);
        }
        c += count;
    }
    return c;
}

int main(int argc, char *argv[]) {
    if(argc < 3 || argc > 3) {
        cout << "Please give correct input \n";             // error message for inadequate input
        return 1;
    }

    int index = stoi(argv[1]);
    string s = argv[2];
    vector<string> v;
    string c;
    while(cin) {                                           // populate input into a vector with vector elements being
        getline(cin, c);                             // entire lines from cin
        v.push_back(c);
        if (c.empty())
            break;                                         // breaks only when empty, ie, when enter is hit twice
    }
    int size = v.size() - 1;

    vector<vector<string>> mat;
    for (int k = 0; k < size; k++) {                       // iterate over each line of stored input
        vector<string> set;                                // initialise a vector per line
        split(v[k], set);
        mat.push_back(set);
    }


    for(int i; i < mat.size(); i++)
    {
        string sequence = mat[i][index - 1];                      // mark one word in the set as the target from input
        vector<int> dist;                                  // form a new vector to do all computations
        for (int k = 0; k < mat[i].size(); k++) {             // vector iterates over each remaining set element
            int count = 0;
            int seqsize = sequence.size();
            for (int j = 0; j < seqsize; j++) {    // vector iterates over each letter to count the differences
                if (sequence[j] != mat[i][k][j]) {
                    count++;
                }
            }
            dist.push_back(count);                         // count between target and each word is stored
        }
        cout << min(dist, index - 1) << ' ' << max(dist) << ' ' << mean(dist) << ' ' << med(dist, index - 1) << ' ' << occ(mat[i], s) << endl;
    }


    for(int i = 0; i < mat.size(); i++){
        vector<string> cols;
        for(int j = 0; j < mat.size(); j++)
        {
            cols.push_back(mat[j][i]);
        }
        string sequence = cols[index - 1];
        vector<int> dist;
        for(int k = 0; k < cols.size(); k++)
        {
            int count = 0;
            int seqsize = sequence.size();
            for(int l = 0; l < seqsize; l++)
            {
                if(sequence[l] != cols[k][l])
                {
                    count++;
                }
            }
            dist.push_back(count);
        }
        cout << min(dist, index - 1) << ' ' << max(dist) << ' ' << mean(dist) << ' ' << med(dist, index - 1) << ' ' << occ(cols, s) << endl;
    }



    vector<string> diag;
    for(int i = 0; i < mat.size(); i++) {
        diag.push_back(mat[i][i]);
    }


    string sequence = diag[index - 1];
    vector<int> dist;
    for(int i = 0; i < diag.size(); i++) {
        int count = 0;
        int seqsize = sequence.size();
        for (int j = 0; j < seqsize; j++) {    // vector iterates over each letter to count the differences
            if (sequence[j] != diag[i][j]) {
                count++;
            }
        }
        dist.push_back(count);
    }
    cout << min(dist, index - 1) << ' ' << max(dist) << ' ' << mean(dist) << ' ' << med(dist, index - 1) << ' ' << occ(diag, s) << endl;

    vector<string> upp;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++) {
            if (i <= j) {
                string s = mat[i][j];
                upp.push_back(s);
            }

        }
    }

    vector<int> dist2;
    string sequence2 = upp[index - 1];
    for(int i = 0; i < upp.size(); i++){
        int count = 0;
        int seqsize2 = sequence2.size();
        for (int j = 0; j < seqsize2; j++) {    // vector iterates over each letter to count the differences
            if (sequence2[j] != upp[i][j]) {
                count++;
            }
        }
        dist2.push_back(count);
    }

    cout << min(dist2, index - 1) << ' ' << max(dist2) << ' ' << mean(dist2) << ' ' << med(dist2, index - 1) << ' ' << occ(upp, s) << endl;

    return 0;
}
