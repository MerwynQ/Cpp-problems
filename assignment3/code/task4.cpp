#include "matrix.hpp"
#include <ostream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  // show here that your iterators perform correctly

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  Matrix<int> M1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}} ;



  Matrix<int>::col_reverse_iterator it = M1.col_rbegin(1);
  Matrix<int>::col_reverse_iterator it2 = M1.col_rend(1);
  Matrix<int>::diag_iterator it3 = M1.diag_begin();
  Matrix<int>::diag_iterator it4 = M1.diag_end();

  int b = *it;

  ++it;

  int g = *it;

  int c = *it2;

  int d = *it3;

  ++it3;
  ++it3;

  int f = *it3;

  int e = *it4;

  bool check = 1;
  if(it3 == it4)
  {
      check = 1;
  }

  bool check2 = 1;
  Matrix<int>::diag_iterator it5 = M1.diag_begin();

  if(it4 != it5)
  {
      check2 = 0;
  }

    for (auto it= M1.col_rbegin(1); it != M1.col_rend(1); ++it){
        std::cout << *it << std::endl;
    }

    for (auto it= M1.diag_begin(); it != M1.diag_end(); ++it){
        int v = *it;
        std::cout << v << std::endl;
    }


    const Matrix<int> M2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    const Matrix<int>::const_col_reverse_iterator it7 = M2.col_rbegin(2);
    const Matrix<int>::const_col_reverse_iterator it8 = M2.col_rend(2);
    const Matrix<int>::const_diag_iterator it9 = M2.diag_begin();
    const Matrix<int>::const_diag_iterator it10 = M2.diag_end();

    int m = *it7;

    ++it7;
    ++it7;

    int n = *it7;

    int o = *it8;

    int p = *it9;

    ++it9;
    ++it9;

    int q = *it9;

    int r = *it10;

    for (auto it= M2.col_rbegin(1); it != M2.col_rend(1); ++it){
        std::cout << *it << std::endl;
    }

    for (auto it= M2.diag_begin(); it != M2.diag_end(); ++it){
        int v = *it;
        std::cout << v << std::endl;
    }

    //test

  return 0;
}
