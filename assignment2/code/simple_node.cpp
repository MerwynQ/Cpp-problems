#include "simple_node.hpp"
#include<iostream>

using namespace std;

SimpleNode::SimpleNode(double content)
    : content_(content){};   // initialised default constructor to the content double

SimpleNode::SimpleNode(const SimpleNode &other_node)
        : content_(other_node.content_), successor_() {
    if (other_node.successor_ != nullptr) {
        this->successor_ = make_unique<SimpleNode>(*other_node.successor_);
    }
    else  {
        this->successor_ = nullptr;
    }
}

/* SimpleNode & SimpleNode::operator=(const SimpleNode &other_node) // copy assignment
{
    unique_ptr<SimpleNode> successor_{new SimpleNode{*this}};
    return *this;
} */

void SimpleNode::insert(SimpleNode& successor_node) {
    if (this->successor_ != nullptr) {

        SimpleNode node = SimpleNode(*this->successor_);
        while (node.successor_ != nullptr) {
            SimpleNode node = SimpleNode(*node.successor_);
        }

        node.successor_ = make_unique<SimpleNode>(successor_node);

    } else {
        this->successor_ = make_unique<SimpleNode>(successor_node);
    }
}

SimpleNode &SimpleNode::next() const
{
    if(this->successor_ != nullptr)
    {
        return *this->successor_;
    }
    else
    {
        cout << "NULL" << endl;
    }
}

bool SimpleNode::is_tail() const
{
    if(this->successor_ == nullptr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

size_t SimpleNode::length() const
{
    size_t count = 1;
    if(this->successor_ != nullptr)
    {
        count++;
        SimpleNode node = *this->successor_;
        while (node.successor_ != nullptr)
        {
            node = SimpleNode(*node.successor_);
            count++;
        }
        return count;
    }
    else
    {
        return 1;
    }
}
double & SimpleNode::operator()()
{
    return content_;
}

double SimpleNode::operator()() const
{
    return content_;
}
