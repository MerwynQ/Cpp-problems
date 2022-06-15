#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

void split(string const &vec_element, vector<int> &set) // function to split individual lines to separate sequences
{
    // make a stream
    stringstream ss(vec_element);

    string buffer; // a temporary placeholder
    while (std::getline(ss, buffer,' ')) {    //getline to split, just like with cin below
        set.push_back(stoi(buffer));
    }
}

void bk(vector<int> &R, vector<int> &P, vector<int> &X, vector<vector<int>> matrix, int count)
{
    vector<int> newR, newP, newX;
    newX = X;
    if(P.empty() && X.empty())
    {
        cout << '{';
       for(size_t i = 0; i < R.size(); i++)
       {
           if(i < R.size() - 1)
           {
               cout << R[i] << ',' << ' ';
           }
           else
           {
                cout << R[i];
           }
       }
       cout << '}' << endl;
    }

    else
    {
        while(!P.empty())
        {
            vector<int> temp;
            temp.push_back(P[0]);
            newR.clear();
            set_union(R.begin(), R.end(), temp.begin(), temp.end(), back_inserter(newR));
            vector<int> pos = matrix[P[0]];
            vector<int> neighbour;
            for(size_t j = 0; j < pos.size(); j++)
            {
                if(pos[j] == 1)
                {
                    neighbour.push_back(j);
                }
            }
            newP.clear(); newX.clear();
            set_intersection(P.begin(), P.end(), neighbour.begin(), neighbour.end(), back_inserter(newP));
            set_intersection(X.begin(), X.end(), neighbour.begin(), neighbour.end(), back_inserter(newX));
            count ++;

            bk(newR, newP, newX, matrix, count);
            if(P.size() > 0)
            {
                vector<int> temp2;
                temp2.push_back(P[0]);
                newP.clear(); newX.clear();
                set_difference(P.begin(), P.end(), temp2.begin(), temp2.end(), back_inserter(newP));
                set_union(X.begin(), X.end(), temp2.begin(), temp2.end(), back_inserter(newX));
                X.clear(); P.clear();
                X = newX; P = newP;
                newX.clear(); newP.clear();
            }
        }
    }
}

int main(int argc, const char* argv[]) {

    vector<vector<int>> v2;
    string c;

    while(cin) {                                           // populate input into a vector with vector elements being
        vector<int> v;
        getline(cin, c);                            // entire lines from cin
        split(c, v);
        v2.push_back(v);
        if (c.empty())
            break;                                         // breaks only when empty, ie, when enter is hit twice
    }

    v2.pop_back();
    vector<int> P;
    for(size_t i = 0; i < v2.size(); i++)
    {
        P.push_back(i);
    }

    vector<int> R, X;

    bk(R, P, X, v2, 0);

    return 0;
}
