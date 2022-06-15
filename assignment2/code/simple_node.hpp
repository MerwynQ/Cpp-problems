#ifndef SIMPLE_NODE_HPP
#define SIMPLE_NODE_HPP

#include <vector>
#include <memory>

class SimpleNode
{
public:
  class Invalid
  {
  };
  explicit SimpleNode(double content); // initialiser

  SimpleNode(const SimpleNode &other_node); // copy operator
  SimpleNode(SimpleNode &&other_node) = default; // move operator

  SimpleNode &operator=(const SimpleNode &other_node) = default; // copy assignment
  SimpleNode &operator=(SimpleNode &&other_node) = default; // move assignment

  void insert(SimpleNode& successor_node); // member function insert
  SimpleNode &next() const; // member function next

  bool is_tail() const; // member function istail
  std::size_t length() const; //member function length

  double &operator()(); //overloaded operator ()
  double operator()() const;

private:
  double content_; // own content
  std::unique_ptr<SimpleNode> successor_; // successor nodes content
};

#endif // SIMPLE_NODE_HPP
