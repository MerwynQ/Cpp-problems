#include "dataframe.hpp"
#include "utils.hpp"
//Also consider the code in utils.hpp may come in handy (does not have to be used)

using namespace std;

Dataframe::Dataframe() = default;

size_t Dataframe::nrows() const
{

    std::list<std::vector<ColType>> data2 = data;
    list<vector<ColType>>::iterator it = data2.begin();

    vector<ColType> v2 = *it;
    return v2.size();
}

size_t Dataframe::ncols() const
{
    return data.size();
}

void Dataframe::add_column(const std::vector<T>& col_values)
{
    vector<ColType> v;
    for(int i = 0; i < col_values.size(); i++)
    {

        v.push_back(col_values[i]);
    }
    data.push_back(v);
}

void Dataframe::remove_column(const size_t i)
{

    list<vector<ColType>>::iterator it = data.begin();
    advance(it, i);
    data.erase(it);
}

void Dataframe::remove_column(const std::string& c)
{
    vector<string>::iterator it = find(colnames.begin(), colnames.end(), c);
    int i = distance(colnames.begin(), it);
    list<vector<ColType>>::iterator it2 = data.begin();
    advance(it2, i);
    data.erase(it2);
}



bool Dataframe::has_rownames() const
{
    if(rownames.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Dataframe::has_colnames() const
{
    if(colnames.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Dataframe::set_colnames(const std::vector<std::string>& cnames)
{
    for(int i = 0; i < cnames.size(); i++)
    {
        colnames[i] = cnames[i];
    }
}

void Dataframe::set_rownames(const std::vector<std::string>& rnames)
{
    for(int i = 0; i < rnames.size(); i++)
    {
        rownames[i] = rnames[i];
    }
}

void Dataframe::clear_rownames()
{
    rownames.clear();
}

void Dataframe::clear_colnames()
{
    colnames.clear();
}

void Dataframe::swap_columns(const size_t i, const size_t j)
{
    list<vector<ColType>>::iterator it = data.begin();


    advance(it, i);
    vector<ColType> v2 = *it;

    list<vector<ColType>>::iterator it1 = data.begin();


    advance(it1, j);
    vector<ColType> v3 = *it;

    data.erase(it);
    data.insert(it, v3);
    data.erase(it1);
    data.insert(it1, v2);
}

void Dataframe::swap_columns(const std::string& i, const std::string& j)
{

}



