#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
    /**
     * @brief Construct a new Heap object
     *
     * @param m ary-ness of heap tree (default to 2)
     * @param c binary predicate function/functor that takes two items
     *          as an argument and returns a bool if the first argument has
     *          priority over the second.
     */
    Heap(int m = 2, PComparator c = PComparator());

    /**
     * @brief Destroy the Heap object
     *
     */
    ~Heap();

    /**
     * @brief Push an item to the heap
     *
     * @param item item to heap
     */
    void push(const T &item);

    /**
     * @brief Returns the top (priority) item
     *
     * @return T const& top priority item
     * @throw std::underflow_error if the heap is empty
     */
    T const &top() const;

    /**
     * @brief Remove the top priority item
     *
     * @throw std::underflow_error if the heap is empty
     */
    void pop();

    /// returns true if the heap is empty

    /**
     * @brief Returns true if the heap is empty
     *
     */
    bool empty() const;

    /**
     * @brief Returns size of the heap
     *
     */
    size_t size() const;

private:
    /// Add whatever helper functions and data members you need below
    std::vector<T> vec;
    void make_heap();
    void compare_with_children(size_t index);
    int find_better_child(size_t starting_index);
    int max_children;
    PComparator comparator;
};

// rebuild heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::make_heap()
{
    // if size is one or less, heap is sorted
    if (size() <= 1)
        return;

    // get first non-child node
    int cursor = size() - 1;
    int starting_node = 0;
    while (cursor > 0)
    {
        int children = 0;
        for (int x = 1; x <= max_children; x++)
        {
            size_t child_index = (max_children * cursor) + x;
            if (child_index <= size())
            {
                children++;
            }
        }
        if (children == 0)
        {
            starting_node = cursor;
            break;
        }
        cursor--;
    }

    // compare nodes
    compare_with_children(starting_node);
}

// helper function to navigate through nodes during remake
template <typename T, typename PComparator>
void Heap<T, PComparator>::compare_with_children(size_t index)
{
    

    // loop through each child and check if the child or any of its descendants are better
    T this_value = vec[index];
    int priority_descendant_index = find_better_child(index);
    if(priority_descendant_index != -1) {

        // if priority descendant found, swap values
        vec[index] = vec[priority_descendant_index];
        vec[priority_descendant_index] = this_value;

    }

    // if this index is the root node, comparisions are finished
    if (index == 0) return;

    // otherwise, move to next node (n-1) and repeat process
    compare_with_children(index - 1);
}

// helper function to look for a child node with higher priority
// @return Index of the better child or -1 if it doesn't exist
template <typename T, typename PComparator>
int Heap<T, PComparator>::find_better_child(size_t starting_index)
{

    // if child is out of bounds, return -1
    if (starting_index >= size())
        return -1;

    // check if children are "better"
    T this_value = vec[starting_index];
    T child_value;

    int priority_child_index = -1;
    T priority_child;

    // loop through possible children
    for (int x = 1; x <= max_children; x++)
    {
        size_t child_index = (max_children * starting_index) + x;

        // make sure child exists
        if (child_index < size())
        {
            child_value = vec[child_index];

            // if child is better than the parent and is the current highest priority child, set as new highest priority child
            if (comparator(child_value, this_value) && (priority_child_index == -1 || comparator(child_value, priority_child)))
            {
                priority_child_index = child_index;
                priority_child = vec[priority_child_index];
            }
        }
    }

    // if no priority child, return starting index
    if (priority_child_index == -1)
        return starting_index;

    // otherwise, check highest priority child's children
    return find_better_child(priority_child_index);
}

// construct heap instance
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
    max_children = m;
    comparator = c;
}

// destroy the heap
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
    vec.clear();
}

// Push a new item onto the heap and remake heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item)
{
    vec.push_back(item);
    make_heap();
}

// Check if the heap is empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
    if (size() == 0)
        return true;
    return false;
}

// Return the size of the heap
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
    return vec.size();
}

// Return the top of the heap
template <typename T, typename PComparator>
T const &Heap<T, PComparator>::top() const
{
    // @condition If empty, throw underflow exception
    if (empty())
    {
        throw std::underflow_error("Heap Underflow during top()");
    }
    else
    {

        // @condition Otherwise, show front element
        return vec.front();
    }
}

// Pop the top of the heap and call make_heap to maintain the heap property
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
    // @condition If empty, throw underflow exception
    if (empty())
    {
        throw std::underflow_error("Heap Underflow during pop()");
    }
    else
    {

        // @condition Otherwise, pop front element and call make_heap to maintain heap property
        vec.erase(vec.begin());
        make_heap();
    }
}

#endif
