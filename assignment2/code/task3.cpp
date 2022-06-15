#include <string>
#include <utility>
#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

class cluster
{
public:
    cluster(string a, int c, int d, int e) : name(move(a)), assignment("cluster="), start(c), stop(d), mid(e)
    {

    }

void assign(int clu, cluster &other_chrom) {
    int diff = abs(other_chrom.mid - this->mid);
    if (diff <= 2000 && other_chrom.name == this->name) {
        if(assignment == "cluster=")
        {
            assignment.append(to_string(clu));
            other_chrom.assign(clu, *this);
        }
        else if(other_chrom.assignment == "cluster=")
        {
            other_chrom.assignment = assignment;
        }
    }
    if (diff > 2000 || other_chrom.name != this->name && other_chrom.assignment == "cluster=")
    {
        if (this->assignment == "cluster=")
        {
            assignment.append(to_string(clu));
            other_chrom.assignment.append(to_string(clu + 1));
        } else{
            int i;
            for (i = 0; i < this->assignment.length(); i++ )
            {
                if(isdigit(this->assignment[i]))
                    {
                        break;
                    }
            }
            assignment = assignment.substr(i, assignment.length() - i );
            int clu2 = atoi(assignment.c_str());
            other_chrom.assignment.append(to_string(clu2 + 1));
        }
    }
}

string col1() {
    return name;
}

string col2()
{
        return to_string(start);
}

string col3()
{
        return to_string(stop);
}

string col4()
{
        return assignment;
}

string results(ofstream file)

{
    file << name << '\t' << start << '\t' << stop << '\t' << assignment;
}

private:
    string name;
    string assignment;
    int start;
    int stop;
    int mid;
};

void split(string const &vec_element, vector<string> &set) // function to split individual lines to separate sequences
{
    // make a stream
    stringstream ss(vec_element);

    string buffer; // a temporary placeholder
    while (std::getline(ss, buffer,'\t')) {    //getline to split, just like with cin below
        set.push_back(buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        cerr << "Please give correct input" << endl;
        return 1;
    }

    string f = argv[1];
    ifstream file(f);                       // reading from file
    string s;
    vector <string> s1;
    if (file.is_open()) {
        while (getline(file, s)) {
            if(s == "")
            {
                cerr << "File contains empty lines" << endl;
                return 3;
            }
            s1.push_back(s);
        }
    }
    s1.erase(remove(s1.begin(), s1.end(), ""), s1.end());


    vector<int> midpoint;
    vector<vector<string>> s3;
    for(int i = 0; i < s1.size(); i++)
    {
        vector<string> s2;
        split(s1[i], s2);
        string chrom = s2[0];
        int begin = stoi(s2[1]);
        int end = stoi(s2[2]);


        int mid = (begin + end) / 2;
        vector<string> s4 = {s2[0], s2[1], s2[2], to_string(mid)};
        s3.push_back(s4);
    }

    vector<string> chroms;
    for(int i = 0; i < s3.size(); i++)
    {
        chroms.push_back(s3[0][1]);
    }

    if(!is_sorted(chroms.begin(), chroms.end()))
    {
        cerr << "Unsorted chromosomes" << endl;
        return 2;
    }

    vector<cluster> tab;
    for(int i = 0; i < s3.size(); i++)
    {
        cluster clus(s3[i][0], stoi(s3[i][1]), stoi(s3[i][2]), stoi(s3[i][3]));
        tab.push_back(clus);
    }

    int num = 1;
    for(int i = 1; i < tab.size(); i++)
    {
        tab[i-1].assign(num, tab[i]);
        num ++;
    }
    string out = argv[3];
    ofstream myfile;
    myfile.open (out);
    for(int i = 0; i < tab.size(); i++) {
        string a,b,c,d;
        a = tab[i].col1();
        b = tab[i].col2();
        c = tab[i].col3();
        d = tab[i].col4();
        myfile << a << '\t' << b << '\t' << c << '\t' << d;

        if(i != tab.size() - 1)
        {
            myfile << endl;
        }
    }
    myfile.close();
}