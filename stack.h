#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T &item);
    void pop();           // throws std::underflow_error if empty
    const T &top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private:
    std::vector<T> vec;
};

template <typename T>
Stack<T>::Stack() {

}

template <typename T>
Stack<T>::~Stack() {

}

// @summary Check if stack is empty
template <typename T>
bool Stack<T>::empty() const
{
    return vec.empty();
}

// @summary Get stack size
template <typename T>
size_t Stack<T>::size() const
{
    return vec.size();
}

// @summary Push new item to stack
template <typename T>
void Stack<T>::push(const T &item)
{
    vec.push_back(item);
}

// @summary Remove item from top
template <typename T>
void Stack<T>::pop()
{
    if (size() == 0)
    {
        // @condition If stack is empty, throw error
        throw std::underflow_error("Stack Underflow Error during pop()");
    }
    else
    {
        // @condition If valid pop, remove item
        vec.pop_back();
    }
}

// @summary Retrieve item at the top
template <typename T>
const T &Stack<T>::top() const
{
    if (size() == 0)
    {
        // @condition If stack is empty, throw error
        throw std::underflow_error("Stack Underflow Error dring top()");
    }
    else
    {
        // @condition If valid, get top item
        return vec.back();
    }
}

#endif