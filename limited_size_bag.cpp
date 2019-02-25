


// ----------- Helper Functions ---------------- // 

template<typename T> 
bool LimitedSizeBag<T>::bagSpaceAvailable() 
{
   bool foundSpaceInBag = false; 
   if (index < SIZE_OF_BAG) {
     foundSpaceInBag = true; 
   }
   return foundSpaceInBag;
}

// ---------------------------------------------- // 

template<typename T>
bool LimitedSizeBag<T>::add(const T & item) 
{
    bool itemAdded = false; 
     
    if (bagSpaceAvailable()) { 
        // add item to bag
        contents[index] = item;
        itemAdded = true; 
        index++;   
    } 
    
  return itemAdded; 
}

template<typename T>
void LimitedSizeBag<T>::clear()
{
   contents.fill(0); 
   index = 0; 
}

template<typename T> 
void LimitedSizeBag<T>::updateBag(const LimitedSizeBag new_bag) {
   this->clear();

   // assign items in bag 
   for (int i=0; i < index; i++) {
     this->add(new_bag.contents[i]);
   }
   // assign new size 
   index = new_bag.getCurrentSize(); 
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return index; 
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T & item)
{
    bool itemRemoved = false; 
    LimitedSizeBag updated_bag;

    // Look for item in Bag 
    for (int i=0; i < index; i++) {
        if (this->contains(item) && !itemRemoved) { // item to be removed found 
           // remove item
           itemRemoved = true; 
        }
        else {
          // add all other items
          T itemToAdd = contents.at(i); 
          updated_bag.add(itemToAdd);
        }

    }
   
     // update contents 
     this->updateBag(updated_bag);

    return itemRemoved;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const 
{
  return (this->getCurrentSize() == 0); 
}


template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
   std::size_t numFound = 0; 
   // iterate through bag
   for (int i=0; i < index; i++) {
	   // increment frequency, if item found 
     if (contents.at(i)==item) {
       // item found 
       numFound++; 
     }
   }
   return numFound; 
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{    

   return (this->getFrequencyOf(item) > 0); 
}
           

