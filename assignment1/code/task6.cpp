#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <fstream>


using namespace std;

int main(int argc, char *argv[]){
    if(argc < 2)
    {
        cerr << "Please give correct input" << endl;
        return 1;
    }

    string f = argv[1];
    ifstream file(f);                       // reading from file
    string s;
    vector<string> s1;
    if(file.is_open())
    {
        while(getline(file, s))
        {
            if(s[0] != '>')
            {
                s1.push_back(s);            // store lines that are sequences and not sequence names
            }
        }
    }

    vector<string> s2;
    for(int i = 0; i < s1.size(); i++)
    {
        for(int j = 0; j < s1[i].size(); j++)
        {
            if (s1[i][j] == 'A' || s1[i][j] == 'T' || s1[i][j] == 'C' || s1[i][j] == 'G' || s1[i][j] == 'U')
            {
                if (s1[i][j] == 'U')
                {
                    s1[i][j] = 'T';                     // change to DNA from RNA
                }
            }
            else{
                s1[i] = "not DNA or RNA";               // to catch corner cases
            }

        }


        if(s1[i] != "not DNA or RNA") {                 // corner cases discarded
            s2.push_back(s1[i]);
        }
    }


    vector<string> perm;
    for(int i = 0; i < s2.size(); i++)
    {

        string seq = s2[i];
        bool per = next_permutation(seq.begin(), seq.end());        // check if a larger permutation possible
        if(per == false)
        {
            perm.push_back("");                                     // if not, empty the position
        }

        else{
            perm.push_back(seq);                                    // if yes, permutate
        }

    }
    perm.erase(remove(perm.begin(), perm.end(), ""), perm.end()); // remove empty positions

    sort(perm.begin(),perm.end());                  // get lexicographical ordering

    vector<int> perm2;
    for(int i = 0; i < perm.size(); i++)
    {
        int s = perm[i].size();
        perm2.push_back(s);                         // get vector of string sizes
    }

    vector<string> perm3;
    int lim = perm2.size();
    for(int i = 0; i < lim; i++)
    {
        vector<int>::iterator ind = min_element(perm2.begin(), perm2.end());    // smallest position selected
        int ind2 = distance(perm2.begin(), ind);                                // get a index position
        perm3.push_back(perm[ind2]);                                            // put that in new vector
        perm2.erase(perm2.begin() + ind2);                                      // remove from string size vector
        perm.erase(perm.begin() + ind2);                                        // remove from original vector
    }


    for(int i = 0; i < perm3.size(); i++)
    {
            cout << perm3[i] << endl;

    }

    return 0;
}
