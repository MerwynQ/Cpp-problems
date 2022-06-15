#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <sstream>

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

int main(int argc, const char* argv[]) {

    vector<string> v, info, landsc, del1, del2;
    string c;
    while(cin) {                                           // populate input into a vector with vector elements being
        getline(cin, c);                             // entire lines from cin
        v.push_back(c);
        if (c.empty())
            break;                                         // breaks only when empty, ie, when enter is hit twice
    }

    split(v[0], info);
    split(v[1], landsc);

    int cit = stoi(info[0]);
    int rbeam = stoi(info[1]);
    int rcat = stoi(info[2]);

    int c1 = 0;
    int c2 = 0;
    for(int i = 0; i < landsc.size(); i++)
    {
        if(del1.size() != cit || i != landsc.size() - 1)
        {
            if(stoi(landsc[i]) == 1)
            {
                if(i >= del1.size())
                {
                    del1.push_back("1");
                }
                for(int j = 0; j < rbeam; j++)
                {
                    if(del1.size() != cit)
                    {
                        del1.push_back("1");
                    }

                }
                if(i != 0)
                {
                    for(int j = i; j >= i - rbeam; j--)
                    {
                        del1[j] = "1";
                    }
                }
                c1++;
                if(del1.size() == cit && find(del1.begin(), del1.end(), "0") == del1.end())
                {
                    break;
                }
            }
            else
            {
                if(i >= del1.size())
                {
                    del1.push_back("0");
                }
            }
        }
    }
    if(find(del1.begin(), del1.end(), "0") != del1.end())
    {
        c1 = -1;
    }

    for(int i = 0; i < landsc.size(); i++)
    {
        if(del2.size() != cit || i != landsc.size() - 1)
        {
            if(stoi(landsc[i]) == 2)
            {
                if(i > del2.size())
                {
                    del2.push_back("1");
                }
                for(int j = 0; j < rcat; j++)
                {
                    if(del2.size() != cit)
                    {
                        del2.push_back("1");
                    }
                }
                if(i != 0)
                {
                    for(int j = i; j >= i - rcat; j--)
                    {
                        del2[j] = "1";
                    }
                }
                c2++;
                if(del2.size() == cit && find(del2.begin(), del2.end(), "0") == del2.end())
                {
                    break;
                }
            }
            else
            {
                if(i >= del2.size())
                {
                    del2.push_back("0");
                }
            }
        }
    }
    if(find(del2.begin(), del2.end(), "0") != del2.end())
    {
        c2 = -1;
    }

    cout << "beamer:" << c1 << endl;
    cout << "cata:" << c2 << endl;

  return 0;
}
