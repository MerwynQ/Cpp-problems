#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>

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

double sum(vector<double> b)                // function to get sum
{
    double add = 0;
    for(int i = 0; i < b.size(); i++)
    {
        add += b[i];
    }

    return add;
}

double digsum(double add)                   // function to get sum of digits
{

    string s = to_string(add);
    int add2 = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if ((s[i])!= '.')                   // to avoid zeroes after decimal
            add2 += s[i] - '0';             // conversion of char to int
    }
    return add2;
}

double thirdq(vector<double> b)             // function to get third quartile
{
    if(b.size() == 1)
    {
        return -100000;                     // to output Iq, since that is a string and can't be returned from here
    }
    sort(b.begin(), b.end());
    double med = 0;
    if(b.size() % 2 == 0)
    {

        vector<double> up(b.begin() + b.size() / 2, b.end());
        if(up.size() % 2 == 0)
        {
            double med2 = (up[up.size() / 2] + up[(up.size() / 2) - 1]) / 2;
            return med2;
        }
        else
        {
            double med2 = (up[up.size() / 2]);
            return med2;
        }

    }
    else
    {
        med = b.size() / 2;
        vector<double> up(b.begin() + med, b.end());
        up.erase(up.begin());                               // erase the median of the original vector
        if(up.size() % 2 == 0)
        {

            double med2 = (up[up.size() / 2] + up[(up.size() / 2) - 1]) / 2;
            return med2;
        }
        else
        {
            double med2 = up[up.size() / 2];
            return med2;
        }

    }

}

double nsmall(vector<double> b, double a)           // function to get nsmallest
{
    if(a > b.size())
    {
        return -100000;                             // to output In
    }
    else
    {
        sort(b.begin(), b.end());
        return b[a - 1];
    }

}

double mlarge(vector<double> b, double a)
{
    if(a > b.size())
    {
        return -100000;                             // to output Im
    }
    else
    {
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        return b[a - 1];
    }

}

void kap(vector<double> b, vector<unsigned int> &kap) // function to get kaprekar number
{
    for(int i = 0; i < b.size(); i++)
    {
        unsigned int sq = pow(b[i], 2);             // square
        string sq2 = to_string(sq);
        int l = sq2.length();
        if(sq == b[i])
        {
            kap.push_back(b[i]);                        // for the number 1
        }
        else
        {
            for(int j = 0; j < l; j++) {            // loop to consider all sets of substring combination
                string sub1 = sq2.substr(0, j);
                string sub2 = sq2.substr(j, string::npos);
                if(sub2 == "")
                {
                    sub2 = "0";
                }
                if(sub1 == "")
                {
                    sub1 = "0";
                }
                unsigned int a, c;
                a = stoul(sub1);
                c = stoul(sub2);
                unsigned int add = a + c;
                if(add == b[i])
                {
                    if(a != 0 && c != 0)
                    {
                        kap.push_back(b[i]);
                        break;
                    }

                }
            }
        }
    }
}

void lyc(unsigned int b, int reclimit, unsigned int &a)         // function to get lychrel
{
    string s = to_string(b);
    string sr = s;
    reverse(sr.begin(), sr.end());
    unsigned int add = stoul(s) + stoul(sr);                    // add number plus reverse
    string add2 = to_string(add);
    string add3 =  add2;
    reverse(add3.begin(), add3.end());
    if(add2 == add3)                                            // compare if number and reverse are same
    {
        a = 0;
    }
    else
    {
        if(reclimit == 65)                                      // integer overflow beyond 65
        {
            a = 1;
        }
        else{
            unsigned int add4 = stoul(add2);
            reclimit ++;                                        // recursion increased
            lyc(add4, reclimit, a);
        }

    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Please give correct input \n";             // error message for inadequate input
    }
    double m, n;
    n = stod(argv[1]);
    m = stod(argv[2]);
    vector<string> v;
    string c;
    while (cin) {                                           // populate input into a vector with vector elements being
        getline(cin, c);                             // entire lines from cin
        v.push_back(c);
        if (c.empty())
            break;                                         // breaks only when empty, ie, when enter is hit twice
    }
    v.erase(v.end());

    vector<double> set3;
    for (int k = 0; k < v.size(); k++) {                       // iterate over each line of stored input
        vector<string> set;                                // initialise a vector per line
        split(v[k], set);                               // split the line into words to form a set
        vector<double> set2;

        for (int i = 0; i < set.size(); i++) {                                 // to convert a set of strings, to a set of ints
            set2.push_back(stod(set[i]));
        }
        set3.insert(set3.end(), set2.begin(), set2.end());
        double summ = sum(set2);
        double digsumm = digsum(summ);

        cout << summ << ' ' << digsumm << ' ' ;
        if (thirdq(set2) !=  -100000){
            cout << thirdq(set2) << ' ' ;}
        else {
            cout << "Iq"<< ' ' ;}
        if (nsmall(set2, n) != -100000){
            cout << nsmall(set2, n) << ' ';}
        else {
            cout <<"In"<< ' ' ;}
        if (mlarge(set2, m) != -100000){
            cout << mlarge(set2, m) << endl;}
        else {
            cout << "Im" << endl;}
    }

    vector<unsigned int> kapr;
    kap(set3, kapr);

    for(int i = 0; i < kapr.size(); i++)
    {
        if(i != kapr.size() - 1)
        {
            cout << kapr[i] << ' ';                         // avoid unnecessary whitespace at the end of line
        }
        else
        {
            cout << kapr[i];
        }
    }

    cout << endl;

    for(int i = 0; i < set3.size(); i++) {
        if (i <= set3.size() - 1) {
            if (floor(set3[i]) == set3[i]) {
                unsigned int ret2 = 0;
                lyc(set3[i], 1, ret2);
                if (ret2 != 0) {
                    cout << set3[i] << ' ';                     // avoid unnecessary whitespace at end of line
                }
            }
        } else {
            if (floor(set3[i]) == set3[i])                       // check if int
            {
                unsigned int ret2;
                lyc(set3[i], 1, ret2);
                if (ret2 != 0) {
                    cout << set3[i];
                }
            }
        }

    }

    return 0;
}