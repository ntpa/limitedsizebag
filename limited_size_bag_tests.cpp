#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Empty Test", "[LimitedSizeBag]"){
  REQUIRE(true);
}

TEST_CASE("Tests", "[LimitedSizeBag]"){
   LimitedSizeBag<int> bag;
  REQUIRE(bag.add(4)); 
  REQUIRE(bag.add(5)); 
  REQUIRE(bag.add(1)); 
  REQUIRE(bag.contains(2) == false);
  REQUIRE(bag.contains(5) == true);
  // Current bag contents: 1 5 4 
  REQUIRE(bag.getCurrentSize() == 3);
  REQUIRE(bag.remove(1));
  REQUIRE(!bag.remove(7));
  REQUIRE(bag.getCurrentSize() == 2);
  LimitedSizeBag<int> bag2; 
  bag2.add(2); bag2.remove(2); 
  REQUIRE(bag2.isEmpty());
}
