
#ifndef LIMITED_SIZE_BAG_HPP
#define LIMITED_SIZE_BAG_HPP

#include "abstract_bag.hpp"
#include <array>
// fixed size bag 
#define SIZE_OF_BAG 50

template<typename T>
class LimitedSizeBag: public AbstractBag<T>  {
  public: 
 
    
    // add an item to the bag
    bool add(const T & item);
    
    // remove an item
    bool remove(const T & item);

    // check is the bag is empty
    bool isEmpty() const;

    // get number of items in the bag
    std::size_t getCurrentSize() const;

    // clear the bag contents
    void clear();

    // count how many time item occurs in bag
    std::size_t getFrequencyOf(const T & item) const;

    // check if item is in the bag
    bool contains(const T& item) const;

    private: 
    // fixed size bag 
    std::size_t index = 0; 
    std::array<T,SIZE_OF_BAG> contents;

    // helper functions
    bool bagSpaceAvailable();
    void updateBag(LimitedSizeBag new_bag);

};

#include "limited_size_bag.cpp"

#endif
