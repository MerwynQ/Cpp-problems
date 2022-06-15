#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cassert>

#include <initializer_list>
#include <memory>
#include <ostream>
#include <iterator>
#include <cstddef>

template <class T>
class Matrix {
 public:
  class Invalid {};

  Matrix(std::size_t nrows, std::size_t ncols) : Matrix(nrows, ncols, T()) {}

  Matrix(std::size_t nrows, std::size_t ncols, T init)
      : nrows_(nrows),
        ncols_(ncols),
        data_(std::make_unique<T[]>(nrows * ncols)) {
    if (nrows == 0 || ncols == 0) {
      throw Invalid{};
    }
    for (std::size_t i = 0, end = nrows * ncols; i < end; ++i) {
      data_[i] = init;
    }
  }

  Matrix(std::initializer_list<std::initializer_list<T>> elements)
      : nrows_(elements.size()), ncols_(0), data_() {
    if (elements.size() == 0 || elements.begin()->size() == 0) {
      throw Invalid{};
    }
    ncols_ = elements.begin()->size();
    data_ = std::make_unique<T[]>(nrows_ * ncols_);

    std::size_t i = 0;
    for (auto row : elements) {
      // the number of columns must be the same for each row
      if (row.size() != ncols_) {
        throw Invalid{};
      }
      for (auto e : row) {
        data_[i] = e;
        ++i;
      }
    }
  }

  Matrix(const Matrix& m) : nrows_(m.nrows()), ncols_(m.ncols()), data_() {
    data_ = std::make_unique<T[]>(nrows_ * ncols_);
    std::copy(m.data_.get(), m.data_.get() + (nrows_ * ncols_),
              data_.get());
  }

  Matrix& operator=(const Matrix& m) {
    // self-assignment, don't do anything
    if (this == &m) {
      return *this;
    }
    // there is not enough space in our current matrix, get enough
    if (nrows_ * ncols_ < m.nrows() * m.ncols()) {
      data_ = std::make_unique<T[]>(m.nrows() * m.ncols());
    }
    nrows_ = m.nrows();
    ncols_ = m.ncols();
    std::copy(m.data_.get(), m.data_.get() + (nrows_ * ncols_),
              data_.get());
    return *this;
  }

  T& operator()(std::size_t i, std::size_t j) {
    assert(i * ncols_ + j < nrows_ * ncols_);
    return data_[i * ncols_ + j];
  }

  T operator()(std::size_t i, std::size_t j) const {
    assert(i * ncols_ + j < nrows_ * ncols_);
    return data_[i * ncols_ + j];
  }

  std::size_t nrows() const { return nrows_; }

  std::size_t ncols() const { return ncols_; }

  class col_reverse_iterator
  {
  public:
      class Invalid {};
      col_reverse_iterator(T* pointer, T* pointer2, Matrix & M) : pointer(pointer), pointer2(pointer2), ncols_(M.ncols_), nrows_(M.nrows_), M(M)
      {

      }

      col_reverse_iterator operator++()
      {
          for(size_t i = 0; i < ncols_; i++)
          {
              pointer--;
              if(pointer == pointer2)
              {
                  return col_reverse_iterator(pointer, pointer2, M);
              }
          }
          return col_reverse_iterator(pointer, pointer2, M);
      }

      T& operator *()
      {
          return *pointer;
      }

      bool operator==(const col_reverse_iterator& other)
      {
            if(pointer == other.pointer)
            {
                return true;
            }
            else
            {
                return false;
            }
      }

      bool operator!=(const col_reverse_iterator& other)
      {
          if(pointer != other.pointer)
          {
              return true;
          }
          else
          {
              return false;
          }
      }

  private:
      T* pointer;
      T* pointer2;
      std::size_t nrows_;
      std::size_t ncols_;
      Matrix M;
  };

  class const_col_reverse_iterator
  {
  public:
      class Invalid {};
      const_col_reverse_iterator(T* pointer, T* pointer2, const Matrix & M) : pointer(pointer), pointer2(pointer2), ncols_(M.ncols_), nrows_(M.nrows_), M(M)
              {

              }

      const_col_reverse_iterator operator++() const
      {
          for(size_t i = 0; i < ncols_; i++)
          {
              pointer--;
              if(pointer == pointer2)
              {
                  return const_col_reverse_iterator(pointer, pointer2, M);
              }
          }
          return const_col_reverse_iterator(pointer, pointer2, M);
      }

      const T& operator *() const
      {
          return *pointer;
      }

      bool operator==(const const_col_reverse_iterator& other) const
      {
          if(pointer == other.pointer)
          {
              return true;
          }
          else
          {
              return false;
          }
      }

      bool operator!=(const const_col_reverse_iterator& other) const
      {
          if(pointer != other.pointer)
          {
              return true;
          }
          else
          {
              return false;
          }
      }

  private:
      mutable T* pointer;
      size_t nrows_;
      size_t ncols_;
      Matrix M;
      T* pointer2;
  };

    col_reverse_iterator col_rbegin(std::size_t col_num)
    {
        T* pointer = &data_[nrows_ * ncols_];

        if(col_num < ncols_)
        {
            for(size_t i = 0; i < ncols_ - col_num; i++)
            {
                pointer--;
                T& val = *pointer;
                T& val2 = val;
            }
        }
        else
        {
            throw Invalid{};
        }
        T* pointer2 = &data_[0];
        pointer2--;

        return col_reverse_iterator(pointer, pointer2, *this);
    }

    col_reverse_iterator col_rend(std::size_t col_num)
    {
        T* pointer =  &data_[col_num - 1];
        for(size_t i = 0; i < col_num; i++)
        {
            pointer --;
        }
        T* pointer2 = &data_[0];
        pointer2--;
        return col_reverse_iterator(pointer, pointer2, *this);
    }

    const_col_reverse_iterator col_rend(std::size_t col_num) const
    {
        T* pointer =  &data_[col_num - 1];
        for(size_t i = 0; i < col_num; i++)
        {
            pointer--;
        }
        T* pointer2 = &data_[0];
        pointer2--;

        return const_col_reverse_iterator(pointer, pointer2, *this);
    }

    const_col_reverse_iterator col_rbegin(std::size_t col_num) const
    {
        T* pointer = &data_[nrows_ * ncols_];
        T* pointer2 = &data_[0];
        pointer2--;

        if(col_num < ncols_)
        {
            for(size_t i = 0; i < ncols_ - col_num; i++)
            {
                pointer--;
                T& val = *pointer;
                T& val2 = val;
            }
        }
        else
        {
            throw Invalid{};
        }
        return const_col_reverse_iterator(pointer, pointer2, *this);
    }

  class diag_iterator
  {
  public:
      class Invalid {};
      diag_iterator(T* pointer, T* pointer2, Matrix & M) : pointer(pointer), pointer2(pointer2), nrows_(M.nrows_), ncols_(M.ncols_), M(M)
      {
            if(nrows_ != ncols_)
            {
                throw Invalid {};
            }
      }

      diag_iterator operator++()
      {
          for(int i = 0; i < ncols_ + 1; i++)
          {
              pointer++;
              if(pointer == pointer2)
              {
                  return diag_iterator(pointer, pointer2, M);
              }
          }
          return diag_iterator(pointer, pointer2, M);
      }

      const T& operator *()
      {
          return *pointer;
      }

      bool operator==(const diag_iterator& other)
      {
          if(pointer == other.pointer)
          {
              return true;
          }
          else
          {
              return false;
          }
      }

      bool operator!=(const diag_iterator& other)
      {
          if(pointer != other.pointer)
          {
              return true;
          }
          else
          {
              return false;
          }
      }

  private:
      T* pointer;
      T* pointer2;
      size_t nrows_;
      size_t ncols_;
      Matrix M;
  };

    diag_iterator diag_begin()
    {
        T* pointer = &data_[0];
        T* pointer2 = &data_[nrows_ * ncols_];
        return diag_iterator(pointer, pointer2, *this);
    }

    diag_iterator diag_end()
    {
        T* pointer = &data_[nrows_ * ncols_];
        T* pointer2 = &data_[nrows_ * ncols_];
        return diag_iterator(pointer, pointer2, *this);
    }

  class const_diag_iterator
  {
  public:
      class Invalid {};
      const_diag_iterator(T* pointer, T* pointer2, const Matrix & M) : pointer(pointer), pointer2(pointer2), nrows_(M.nrows_), ncols_(M.ncols_), M(M)
              {
                  if(nrows_ != ncols_)
                  {
                      throw Invalid {};
                  }
              }

      const_diag_iterator operator++() const
      {
          for(int i = 0; i < ncols_ + 1; i++)
          {
              pointer++;
              if(pointer == pointer2)
              {
                  return const_diag_iterator(pointer, pointer2, M);
              }
          }
          return const_diag_iterator(pointer, pointer2, M);
      }

      const T& operator *() const
      {
          return *pointer;
      }

      bool operator==(const const_diag_iterator& other) const
      {
          if(pointer == other.pointer)
          {
              return true;
          }
          else
          {
              return false;
          }
      }

      bool operator!=(const const_diag_iterator& other) const
      {
          if(pointer != other.pointer)
          {
              return true;
          }
          else
          {
              return false;
          }
      }

  private:
      mutable T* pointer;
      T* pointer2;
      size_t nrows_;
      size_t ncols_;
      Matrix M;
  };

    const_diag_iterator diag_begin() const
    {
        T* pointer = &data_[0];
        T* pointer2 = &data_[nrows_ * ncols_];
        return const_diag_iterator(pointer, pointer2, *this);
    }

    const_diag_iterator diag_end() const
    {
        T* pointer = &data_[nrows_ * ncols_];
        T* pointer2 = &data_[nrows_ * ncols_];
        return const_diag_iterator(pointer, pointer2, *this);
    }


  class col_iterator
  {
  public:


  };

  class const_col_iterator
  {
  public:


  };

  class row_iterator
  {
  public:


  };

  class const_row_iterator
  {
  public:


  };

  col_iterator col_begin(std::size_t col_num);
  const_col_iterator col_begin(std::size_t col_num) const;
  col_iterator col_end(std::size_t col_num);
  const_col_iterator col_end(std::size_t col_num) const;

  row_iterator row_begin(std::size_t row_num);
  const_row_iterator row_begin(std::size_t row_num) const;
  row_iterator row_end(std::size_t row_num);
  const_row_iterator row_end(std::size_t row_num) const;

 private:
  std::size_t nrows_;
  std::size_t ncols_;
  std::unique_ptr<T[]> data_;
};

/*
 * Row-wise space separated output of the matrix
 *
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& m) {
  for (std::size_t i = 0; i < m.nrows(); ++i) {
    for (std::size_t j = 0; j < m.ncols() - 1; ++j) {
      os << m(i, j) << ' ';
    }
    os << m(i, m.ncols() - 1) << '\n';
  }
  return os;
}

// test
#endif  // MATRIX_HPP
