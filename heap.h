#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
//added
#include <vector>
#include <utility>

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
  std::vector<T> data_;
  int m_;
  PComparator comp_;


};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c): m_(m), comp_(c)
{

}

//destructor
template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}

template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return data_.empty();
}

template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return data_.size();
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
    throw std::underflow_error("Heap is empty");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return data_[0];

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  data_.push_back(item); //placing new item at end of vector
  size_t curr = data_.size() - 1; //record new items index

  while (curr > 0) //val has a parent
  {
    size_t parent = (curr-1) / m_; //finds parents index for node at index curr

    if (comp_(data_[curr],data_[parent])){
      std::swap(data_[curr],data_[parent]);
      curr = parent;
    } else {
      break;
    }

  }
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
    throw std::underflow_error("Heap empty");

  }

  //trickle down & check whether higher priority child swaps with curr node
  if (size()==1) {
    data_.pop_back();
    return;
  } else {
    data_[0] = data_.back(); //accessing vectors last element & moving to root
    data_.pop_back(); //remove dupes last item
    size_t curr = 0; //trickle down from root

  //trickle down
  while(true){
    size_t firstKid = m_ * curr + 1;

    if (firstKid >= data_.size()){
      break;
    }
    size_t bestKid = firstKid;


  for (int i =1; i < m_; i++){
    size_t kid = firstKid + i;

    if (kid >= data_.size()){
      break;
    }
    if (comp_(data_[kid],data_[bestKid])){
      bestKid = kid;
    }
  }

  if (comp_(data_[bestKid],data_[curr])){
    std::swap(data_[bestKid],data_[curr]);
    curr = bestKid;
  }
  else {
    break;
  }

}

  }
}


#endif