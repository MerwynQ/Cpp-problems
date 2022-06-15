#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 4)
    {
        cerr << "Please give correct input" << endl;
        return 1;
    }

    string f = argv[1];
    ifstream file(f);                       // reading from file
    string s;
    vector<string> seq, head;
    string s2;
    if(file.is_open()) {
        while (getline(file, s)) {
            bool check = 1;
            if (s[0] != '>') {

                for(int i = 0; i < s.length(); i++)
                {
                    if(s[i] != 'A' && s[i] != 'T' && s[i] != 'C' && s[i] != 'G' && s[i] != 'a' && s[i] != 't' && s[i] != 'c' && s[i] != 'g')
                    {
                        check = check && 0;
                    }
                    if(check == 0)
                    {
                        seq.push_back("invalid");
                        s2.clear();
                        break;
                    }
                    else
                    {
                        s2.clear();
                        transform(s.begin(), s.end(), s.begin(), ::toupper);
                        s2.append(s, 0, s.length());
                    }
                }
            }
            else
            {
                if(!s.empty() && !s2.empty())
                {
                    seq.push_back(s2);
                }
                head.push_back(s);
            }
        }
    }

    if(seq.size() != head.size())
    {
        seq.push_back(s2);
    }

    int km, n;
    try {
        km = stoi(argv[2]);
    }
    catch (std::invalid_argument)
    {
        cerr << "give integer argument for k" << endl;
    }

    try {
        n = stoi(argv[3]);
    }
    catch (std::invalid_argument)
    {
        cerr << "give integer argument for n" << endl;
    }

    vector<vector<string>> all;

    for(size_t i = 0; i < seq.size(); i++)
    {
        vector<string> kmers;
        for(int j = 0; j < seq[i].size(); j++)
        {

            string kmer;
            kmer.push_back(seq[i][j]);
            for(int k = 0; k < km - 1; k++)
            {
                kmer.push_back(seq[i][j + (k + 1)*n + k + 1]);
            }
            if(!count(kmer.begin(), kmer.end(), '\0'))
            {
                kmers.push_back(kmer);
            }
        }
        all.push_back(kmers);
    }

    for(size_t i = 0; i < all.size(); i++)
    {
        if(seq[i] != "invalid")
        {
            cout << head[i].erase(0,1) << endl;

            vector<string> kmers2 = all[i];
            sort(kmers2.begin(), kmers2.end());

            string w = "dupe";

            for(size_t j = 0; j < kmers2.size(); j++)
            {
                string kmer2 = kmers2[j];
                if(kmer2 != w)
                {
                    int c = count(kmers2.begin(), kmers2.end(), kmer2);
                    cout << kmer2 << ' ' << c << endl;
                    replace(kmers2.begin(), kmers2.end(), kmer2, w);
                }
            }
            cout << endl;
        } else
        {

            cerr << head[i].erase(0,1) << endl;
        }
    }
  return 0;
}
