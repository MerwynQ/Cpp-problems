#include <string>
#include <utility>
#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

void rec(string &s1, string &s2, int* p, int* p2, vector<vector<vector<int>>> &path, vector<vector<int>> &dp, vector<int*> &branch,
vector<vector<int>> &branch_ind, vector<vector<char>> &glob_ali2, vector<int> &hist)
{
    int i = branch_ind[0][0];                                               // index i
    int j = branch_ind[0][1];                                               // index j
    vector<char> glob1;                                                     // to store one string
    vector<char> glob2;                                                     // to store second string
    int dashcount1 = 0;
    int dashcount2 = 0;


    while(p2 != p)
    {
        if(path[i][j][0] == 1 && path[i][j][1] == 0 && path[i][j][2] == 0)  // only diagonal link
        {
            p2 = &dp[i - 1][j - 1];                                         // new pointer to diagonal
            glob1.push_back(s1[j]);                                  // letter of first string
            glob2.push_back(s2[i]);                                    // letter of second string
            i--;                                                            // decrement both i and j
            j--;
        }

        else if(path[i][j][1] == 1 && path[i][j][0] == 0 && path[i][j][2] == 0)  // only top link
        {
            p2 = &dp[i - 1][j];                                             // new pointer to top
            glob1.push_back('-');                                           // dash for first string
            dashcount1++;
            glob2.push_back(s2[i]);                                  // letter of second string
            i--;                                                            // decrement only
        }

        else if(path[i][j][2] == 1 && path[i][j][0] == 0 && path[i][j][1] == 0)  // only left link
        {
            p2 = &dp[i][j - 1];                                             // new pointer to left
            glob1.push_back(s1[j]);                                  // letter of first string
            glob2.push_back('-');                                           // dash for second string
            dashcount2++;
            j--;                                                            // decrement only j
        }

        else if(path[i][j][0] == 1 && path[i][j][1] == 1 && path[i][j][2] == 1)  // all three links
        {
            p2 = &dp[i - 1][j - 1];                                         // new pointer to diagonal
            glob1.push_back(s1[j]);                                  // letter of first string
            glob2.push_back(s2[i]);                                    // letter of second string
            branch.push_back(&dp[i][j - 1]);                                // store top in branch
            hist.push_back(1);
            branch.push_back(&dp[i - 1][j]);                                // store left in branch
            hist.push_back(0);
            vector<int> branch_ind2;                                        // branch index vector
            branch_ind2.push_back(i);                                       // store top indices in branch_ind
            branch_ind2.push_back(j - 1);
            branch_ind.push_back(branch_ind2);
            vector<int> branch_ind3;
            branch_ind3.push_back(i - 1);                                   // store left indices in branch_ind
            branch_ind3.push_back(j);
            branch_ind.push_back(branch_ind3);
            i--;                                                            // decrement both i and j
            j--;
        }

        else if(path[i][j][0] == 1 && path[i][j][1] == 1 && path[i][j][2] == 0)     // diagonal and top link
        {
            p2 = &dp[i - 1][j - 1];                                            // new pointer to diagonal
            branch.push_back(&dp[i - 1][j]);                                   // store top in branch
            vector<int> branch_ind2;
            hist.push_back(1);
            branch_ind2.push_back(i - 1);                                       // store top indices in branch_ind
            branch_ind2.push_back(j);
            branch_ind.push_back(branch_ind2);
            glob1.push_back(s1[j]);                                     // letter of first string
            glob2.push_back(s2[i]);                                        // letter of second string
            i--;                                                                // decrement both i and j
            j--;
        }

        else if(path[i][j][0] == 1 && path[i][j][1] == 0 && path[i][j][2] == 1)      // diagonal and left link
        {
            p2 = &dp[i - 1][j - 1];                                             // new pointer to diagonal
            branch.push_back(&dp[i][j - 1]);                                    // store left in branch
            vector<int> branch_ind2;
            hist.push_back(0);
            branch_ind2.push_back(i);                                           // store left indices in branch_ind
            branch_ind2.push_back(j - 1);
            branch_ind.push_back(branch_ind2);
            glob1.push_back(s1[j]);                                      // letter of first string
            glob2.push_back(s2[i]);                                        // letter of second string
            i--;                                                                // decrement both i and j
            j--;
        }

        else if(path[i][j][0] == 0 && path[i][j][1] == 1 && path[i][j][2] == 1)      // top and left link
        {
            p2 = &dp[i - 1][j];                                                 // new pointer to top
            branch.push_back(&dp[i][j - 1]);                                    // store left in branch
            hist.push_back(0);
            vector<int> branch_ind2;                                            // store left indices in branch_ind
            branch_ind2.push_back(i);
            branch_ind2.push_back(j - 1);
            branch_ind.push_back(branch_ind2);
            glob1.push_back('-');                                               // dash for first string
            dashcount1++;
            glob2.push_back(s2[i]);                                      // letter of second string
            i--;                                                                // decrement only i
        }
    }

    glob1.push_back(s1[j]);
    glob2.push_back(s2[i]);

    vector dash = {dashcount1, dashcount2};

    int sz = glob1.size() - *max_element(dash.begin(), dash.end());
    int sz1 = s1.length();

    reverse(glob1.begin(), glob1.end());
    reverse(glob2.begin(), glob2.end());

    if(sz == sz1)
    {
        glob_ali2.push_back(glob1);                                                 // add string 1 to alignment vector
        glob_ali2.push_back(glob2);
    }
    else
    {
        if(hist[0] == 1)
        {
            glob1.push_back('-');
            glob2.push_back(s2[sz]);
            for(int i = sz + 1; i < sz1; i++)
            {
                glob1.push_back(s1[i]);
                glob2.push_back(s2[i]);
            }
        }
        else if(hist[0] == 0)
        {
            glob1.push_back(s1[sz]);
            glob2.push_back('-');
            for(int i = sz + 1; i < sz1; i++)
            {
                glob1.push_back(s1[i]);
                glob2.push_back(s2[i]);
            }
        }
        glob_ali2.push_back(glob1);                                                 // add string 1 to alignment vector
        glob_ali2.push_back(glob2);
    }

}

int main(int argc, const char *argv[])
{
    string s1 = argv[1];
    string s2 = argv[2];

    vector<vector<char>> dp;                        // table for storing match mismatch values
    vector<vector<int>> dpmain;
    vector<int> dpmain2;
    dpmain2.push_back(0);
    for(int i = 1; i < s1.length() + 1; i++)
    {
        dpmain2.push_back(i*(-1));
    }
    dpmain.push_back(dpmain2);
    vector<char> dpbasic;                           // rows in the table

    dpbasic.push_back('\000');                      // blank values for the early elements
    dpbasic.push_back('\000');
    for(int i = 0; i < s1.length(); ++i)
    {
        dpbasic.push_back(s1[i]);                   // string letters in the first row
    }
    vector<char> dpbasic2(dpbasic.size());

    dp.push_back(dpbasic);                          // insert string name into 2D vector horizontally

    for(int i = 1; i < s1.length() + 2; i++)
    {
        dp.push_back(dpbasic2);                     // insert remaining empty rows into 2D vector
    }

    for(int i = 0; i < s2.length(); i++)
    {
        dp[i + 2][0] = s2[i];                       // insert string name letters vertically into 2D vector
    }

    dp[1][1] = 0;                                   // set first value to zero

    int val = -1;
    for(int i = 2; i < dp.size(); i++)
    {
        dp[1][i] = val;                             // give first numerical row value beginning from -1
        val--;
    }

    int val2 = -1;
    for(int i = 2; i < dp.size(); i++)
    {
        dp[i][1] = val2;                            // give first numerical column value beginning from -1
        val2--;
    }

    vector<vector<vector<int>>> path;               // vector to store the links, between an element and its diagonal, top or left

    for(int i = 2; i < dp.size(); i++)
    {
        vector<vector<int>> store;                 // stores for all three (diag, top, left) whether the value was used or not
        dpmain2.push_back((i - 1) * (-1));
        for(int j = 2; j < dp.size(); j++)
        {

            vector<int> match;                      // stores 1 or zero depending if the derived value came from the element
            int diag = dp[i-1][j - 1];              // diagonal element
            int top = dp[i - 1][j];               // top element
            int left = dp[i][j - 1];              // left element
            vector<int> range = {diag, top, left};  // all three in a vector

            if(dp[i][0] == dp[0][j])                // if string letters match
            {
                int diag2 = diag + 1;                         // increment diagonal
                int top2 = top - 1;
                int left2 = left - 1;
                vector<int> range2 = {diag2, top2, left2};
                int res = *max_element(range2.begin(), range2.end());     // return max element among three
                char res2 = res;
                dp[i][j] = res2;                                         // give the cell new value
                dpmain2.push_back(res);

                for(int k = 0; k < 3; k++)
                {
                    if(range2[k] == res)             // to remember which of the three gave the value
                    {
                        match.push_back(1);
                    }
                    else
                    {
                        match.push_back(0);
                    }
                }

            }
            else
            {
                int diag2 = diag - 1;
                int top2 = top - 1;
                int left2 = left - 1;
                vector<int> range2 = {diag2, top2, left2};
                int res = *max_element(range2.begin(), range2.end());
                char res2 = res;
                dp[i][j] = res2;
                dpmain2.push_back(res);
                for(int k = 0; k < 3; k++)
                {
                    if(range2[k] == res)
                    {
                        match.push_back(1);
                    }
                    else
                    {
                        match.push_back(0);
                    }
                }
            }
            store.push_back(match);
        }
        path.push_back(store);                          // path stores the links for every cell
    }


    int k = 0;
    for(int i = 0; i < dp.size() - 1; i++)
    {
        vector<int> dpmain3;
        for(int j = 0; j < dp.size() - 1; j++)
        {
           dpmain3.push_back(dpmain2[k]);
           k++;
        }
        dpmain.push_back(dpmain3);
    }

    dpmain.erase(dpmain.begin());


    int align = dp[dp.size() - 1][dp.size() - 1];       // score

    cout << align << endl;

    int* p = &dpmain[0][0];                                         // pointer to the beginning, upstream
    int* p2 = &dpmain[dpmain.size() - 1][dpmain.size() - 1];       // pointer to the score
    vector<int*> branch;                                            // vector of pointers to store branches
    vector<vector<int>> branch_ind;                                 // 2D vector of ints to store indices i and j of those branches
    vector<int> branch_ind2;                                        // vector to store i or j separately and pushback to branch_ind
    branch_ind2.push_back(dpmain.size() - 2);
    branch_ind2.push_back(dpmain.size() - 2);
    branch_ind.push_back(branch_ind2);

    vector<vector<vector<char>>> glob_ali;              // to store all alignments
    vector<vector<char>> glob_ali2;                     // to store one alignment

    vector<int> hist;

    rec(s1, s2, p, p2, path, dpmain, branch, branch_ind, glob_ali2, hist);
    glob_ali.push_back(glob_ali2);                      // stores the first alignment
    branch_ind.erase(branch_ind.begin());               // erase the indices after used

    int bs = branch.size();

    while(!branch.empty())                                  // keep running function until there are no more branches
    {
        for(int i = 0; i < bs; i++)
        {
            vector<vector<char>> glob_ali3;                 // to store a new alignment
            int indi = branch_ind[0][0];                    // index i of branch
            int indj = branch_ind[0][1];                    // index j of branch
            int* pb = &dpmain[indi][indj];                     // new pointer to branch
            rec(s1, s2, p, pb, path, dpmain, branch, branch_ind, glob_ali3, hist);
            glob_ali.push_back(glob_ali3);                  // stores subsequent alignments
            branch.erase(branch.begin()); // erase branch after used
            branch_ind.erase(branch_ind.begin());                                       // erase the indices after used
            hist.erase(hist.begin());
        }


    }




    for(int i = 0; i < glob_ali.size(); i++)                                  // output
    {
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k <= glob_ali[i][j].size() - 1; k++)
            {
                char c = glob_ali[i][j][k];
                cout << c;
            }
            cout << endl;
        }
        if(i != glob_ali.size() - 1)
        {
            cout << endl;
        }
    }

    return 0;
}
