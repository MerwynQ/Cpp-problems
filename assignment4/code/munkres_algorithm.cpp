#include "munkres_algorithm.hpp"
#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

Matrix<int> run_munkres_algorithm(Matrix<int> c) {
    size_t nr = c.nrows();
    size_t nc = c.ncols();

    vector<vector<int>> v1, v2;

    int rx, ry;
    for(size_t j = 0; j < nr; j++)
    {
        rx = c(j, 0);
        for(size_t i = 0; i < nc; i++)
        {
            ry = c(j, i);

            if(rx >= ry)
            {
                rx = ry;
            }
        }

        for(size_t i = 0; i < nc; i++)
        {
            c(j, i) = c(j, i) - rx;

        }
    }

    int x, y;
    for(size_t j = 0; j < nr; j++)
    {
        x = c(0, j);
        for(size_t i = 0; i < nc; i++)
        {
            y = c(i, j);

            if(x >= y)
            {
                x = y;
            }
        }

        for(size_t i = 0; i < nc; i++)
        {

            c(i, j) = c(i,j) - x;

        }
    }

    vector<vector<int>> sets;

    for(size_t i = 0; i < nr; i++)
    {
        vector<int> s;
        for(size_t j = 0; j < nc; j++)
        {
            int num = c(i,j);
            s.push_back(num);
        }
        sets.push_back(s);
    }

    for(size_t i = 0; i < nr; i++)
    {
        vector<int> s;
        for(size_t j = 0; j < nc; j++)
        {
            int num = c(j,i);
            s.push_back(num);
        }
        sets.push_back(s);
    }

    vector<int> occ;

    for(size_t i = 0; i < sets.size(); i++)
    {
        vector<int> temp = sets[i];
        int num = count(temp.begin(), temp.end(), 0);
        occ.push_back(num);
    }

    



    vector<int> row = {0, 0, 0};
    vector<int> col = {0, 0, 0};

    int counts = 0;

    int znum = 3;

}
