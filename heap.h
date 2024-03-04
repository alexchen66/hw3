#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
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
  Heap(int m=2, PComparator c = PComparator());

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
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  void heapify(int index);

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
  std::vector<T> heap_vector;
  PComparator Comparator_ ;
  int m_;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  Comparator_ = c;
  m_ = m;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
  
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_vector.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");
  }
  heap_vector[0] = heap_vector.back(); 
  heap_vector.pop_back();
heapify(0);
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int index)
{
  std::size_t left_child_index = index * m_ + 1;
  std::size_t swapper_index = index; // to decide if we want to swap 
  // since m_ is not fixed we need for loop
  for (std::size_t i = 0; i < m_ && left_child_index + i < heap_vector.size(); ++i)
  {
    if (Comparator_(heap_vector[left_child_index + i], heap_vector[swapper_index])) 
    // if i'th child is larger than current smaller child
    {
      swapper_index = left_child_index + i;
    }
  }
  if (index != swapper_index)
  {
    std::swap(heap_vector[index], heap_vector[swapper_index]);
    heapify(swapper_index);
  }
} 


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return heap_vector.empty();
}


template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const 
{
  return heap_vector.size();
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  heap_vector.push_back(item);
  std::size_t item_index = heap_vector.size() - 1;
  std::size_t parent_index = (item_index - 1)/m_;

  while (item_index > 0 && Comparator_(heap_vector[item_index], heap_vector[parent_index]))
  {
    std::swap(heap_vector[item_index], heap_vector[parent_index]);
    item_index = parent_index;
    parent_index = (item_index - 1)/m_;
  }
}
#endif

