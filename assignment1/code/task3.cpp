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

int min(vector<int> b, int a)   // function to get minimum
{

    b.erase(b.begin() + a); // removing the element at a specific index to avoid comparing a string's hamming distance with itself
    int result = *min_element(b.begin(), b.end());
    return result;
}

int max(vector<int> b) // function to get maximum
{
    int result = *max_element(b.begin(), b.end());
    return result;
}

double mean(vector<int> b) // function to get mean
{
    double sum = 0;
    for(int i : b)
    {
        sum = sum + i; // total sum
    }

    return sum / (b.size() - 1); // total divided by number of elements
}

double med(vector<int> &b, int a) // function to get median

{
    b.erase(b.begin() + a);  // removed the number at a specific index to avoid having the hamming distance with itself
    sort(b.begin(), b.end());

    double low = b[b.size() / 2 - 1];  // middle left element
    double high = b[b.size() / 2];     // middle right element
    if (b.size() % 2 == 0)              // if even, average of the two
    {
        double result = (low + high) / 2;
        return result;
    }
    else
    {
        double result = high;           // if odd, just the middle element
        return result;
    }
}

int occ(vector<string> b, string a)     // function get occurences
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

    for (int k = 0; k < size; k++) {                       // iterate over each line of stored input
        vector<string> set;                                // initialise a vector per line
        split(v[k], set);                               // split the line into words to form a set
        if(set.size() < index)
        {
            cout << "\n";
        }
        else{
            string sequence = set[index - 1];                      // mark one word in the set as the target from input
            vector<int> dist;                                  // form a new vector to do all computations
            for (int i = 0; i < set.size(); i++) {             // vector iterates over each remaining set element
                int count = 0;
                int seqsize = sequence.size();
                for (int j = 0; j < seqsize; j++) {    // vector iterates over each letter to count the differences
                    if (sequence[j] != set[i][j]) {
                        count++;
                    }
                }
                dist.push_back(count);                         // count between target and each word is stored
            }

            cout << min(dist, index - 1) << ' ' << max(dist) << ' ' << mean(dist) << ' ' << med(dist, index - 1) << ' ' << occ(set, s) << endl;


        }
         }

    return 0;
}