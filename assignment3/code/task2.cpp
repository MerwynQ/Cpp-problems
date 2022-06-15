#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>
#include <iomanip>
#include <numeric>

using namespace std;

double mean(vector<double> &vec)
{
    double sum = 0;
    for(double i : vec)
    {
        sum = sum + i; // total sum
    }

    return sum / (vec.size()); // total divided by number of elements
}

double sd(vector<double> &vec, double &num)
{
    vector<double> v;
    for(int i = 0; i < vec.size(); i++)
    {
        v.push_back((vec[i] - num) * (vec[i] - num));
    }

    double sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        sum = sum + v[i];
    }

    double var = sum / (v.size() - 1);
    return sqrt(var);
}


int main(int argc, const char* argv[]) {
    if(argc != 6)
    {
        cerr << "incorrect arguments" << endl;
    }

    unsigned int n = stoul(argv[1]);
    unsigned int m = stoul(argv[2]);
    unsigned int s = stoul(argv[3]);
    unsigned int k = stoul(argv[5]);
    double p = stod(argv[4]);

    mt19937_64 mt(s);

    negative_binomial_distribution<> nbd(k, p);

    vector<double> v1, v2, v3, v4, v5;

    for(int i = 0; i < n; i++)
    {
        v1.push_back(nbd(mt));
    }

    double av = mean(v1);

    cout << "V1 Mean: " << setprecision(3) << av << endl << "V1 Sample standard deviation: " << setprecision(3) << sd(v1, av) << endl;


    for(size_t i = 0; i < v1.size(); i++)
    {
        double l = log2(abs(v1[i]) + 1);
        v3.push_back(l);
    }

    v5 = v3;

    sort(v3.begin(), v3.end());
    reverse(v3.begin(), v3.end());

    size_t size = v1.size();

    if(size < 10)
    {
        cout << "V1 Top " << size << " elements: ";
        for(size_t i = 0; i < size; i++)
        {
            if(i < size - 1)
            {
                cout << v3[i] << ',' << ' ';
            }
            else
            {
                cout << v3[i];
            }

        }
        cout << endl;
    }
    else
    {
        cout << "V1 Top 10 elements: ";
        for(size_t i = 0; i < 10; i++)
        {
            if(i < 9)
            {
                cout << v3[i] << ',' << ' ';
            }
            else
            {
                cout << v3[i];
            }
        }
        cout << endl;
    }

    unsigned int s2 = s*2;

    mt19937_64 mt2(s2);

    negative_binomial_distribution<> nbd2(k, p);

    for(int i = 0; i < m; i++)
    {
        v2.push_back(nbd2(mt2));
    }

    size_t size2 = v2.size();
    double av2 = mean(v2);

    cout << "V2 Mean: " << setprecision(3) << av2 << endl << "V2 Sample standard deviation: " << setprecision(3) << sd(v2, av2) << endl;

    for(size_t i = 0; i < v2.size(); i++)
    {
        double l2 = log2(abs(v2[i]) + 1);
        v4.push_back(l2);
    }

    sort(v4.begin(), v4.end());
    reverse(v4.begin(), v4.end());

    if(size2 < 10)
    {
        cout << "V2 Top " << size2 << " elements: ";
        for(size_t i = 0; i < size2; i++)
        {
            if(i < size2 - 1)
            {
                cout << v4[i] << ',' << ' ';
            }
            else
            {
                cout << v4[i];
            }

        }
        cout << endl;
    }
    else
    {
        cout << "V2 Top 10 elements: ";
        for(size_t i = 0; i < 10; i++)
        {
            if(i < 9)
            {
                cout << v4[i] << ',' << ' ';
            }
            else
            {
                cout << v4[i];
            }

        }
        cout << endl;
    }

    cout << endl << "Comparing V1 and V2..." << endl;

    double av3 = mean(v3);
    double av4 = mean(v4);

    double sd1 = pow(sd(v1, av),2);
    double sd2 = pow(sd(v2, av2),2);
    double sd3 = pow(sd(v3, av3), 2);
    double sd4 = pow(sd(v4, av4), 2);

    double sp = sqrt((((n - 1)*sd1) + (m - 1)* sd2) / (n + m - 2));
    double splog = sqrt((((n - 1)*sd3) + (m - 1)* sd4) / (n + m - 2));

    double sq = sqrt(double((1 / double(n)) + (1 / double(m))));
    double denom1, denom2;
    denom1 = sp * sq;
    denom2 = splog * sq;
    double t1, t2;

    t1 = ((av - av2) / (denom1));

    t2 = ((av3 - av4) / (denom2));

    cout << "Unscaled t-statistic: " << setprecision(3) <<  t1 << endl;

    cout << endl << "Comparing log2scaled V1 and V2..." << endl << "Scaled t-statistic: " << setprecision(3) << t2 << endl << "Total degrees of freedom: " << n + m - 2 << endl;

    vector<double> io(n);

    iota(io.begin(), io.end(), 1);

    unsigned int s3 = s*7;

    mt19937_64 mt3(s3);

    shuffle(io.begin(), io.end(), mt3);

    for(size_t i = 0; i < io.size(); i++)
    {
        io[i] = io[i] * v5[i];
    }

    vector<double> even, odd;

    for(size_t i = 0; i < io.size(); i++)
    {
        int r = round(io[i]);
        if(r % 2 != 0)
        {
            odd.push_back(io[i]);
        }
        else
        {
            even.push_back(io[i]);
        }
    }

    sort(even.begin(), even.end());
    reverse(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    cout << endl << "Sorted vector: ";

    for(size_t i = 0; i < even.size(); i++)
    {
        cout << even[i] << ',' << ' ';
    }
    for(size_t i = 0; i < odd.size(); i++)
    {
        if(i < odd.size() - 1)
        {
            cout << odd[i] << ',' << ' ';
        }
        else
        {
            cout << odd[i];
        }
    }

    return 0;
}
