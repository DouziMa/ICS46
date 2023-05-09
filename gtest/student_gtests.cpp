#include <gtest/gtest.h>
#include <ostream>
#include <iostream>
#include <vector>
#include "Timer.h"
#include "hasher.h"
#include "hashtable.h"
#include "stats.h"

TEST(Replace, Me) {
  EXPECT_TRUE(true);
}

TEST(HashTable_MultHaher, Number_Of_Entries){
  MultHasher h;
  HashTable ht1(h,4);
  ht1.insert("aaaa");
  std::ostringstream output1;
  ht1.print(output1);
  std::cout << "Result after inserting aaaa:\n" << output1.str() << std::endl;
  int actual_num_entries1 = ht1.number_of_entries();
  EXPECT_EQ(1, actual_num_entries1);
  std::cout << "Number of entries after inserting aaaa: " << actual_num_entries1 << std::endl;
  std::vector<int> v1;
  ht1.get_chain_lengths(v1);
  std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  ht1.insert("bbbb");
  std::ostringstream output2;
  ht1.print(output2);
  std::cout << "Result after inserting bbbb:\n" << output2.str() << std::endl;
  int expected_num_entries2 = 2;
  int actual_num_entries2 = ht1.number_of_entries();
  EXPECT_EQ(expected_num_entries2, actual_num_entries2);
  std::cout << "Number of entries after inserting bbbb: " << actual_num_entries2 << std::endl;
  std::vector<int> v2;
  ht1.get_chain_lengths(v2);
  std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  ht1.insert("cccc");
  std::ostringstream output3;
  ht1.print(output3); 
  std::cout << "Result after inserting cccc:\n" << output3.str() << std::endl;
  int actual_num_entries3 = ht1.number_of_entries();
  EXPECT_EQ(3, actual_num_entries3);
  std::cout << "Number of entries after inserting cccc:: " << actual_num_entries3 << std::endl;
  std::vector<int> v3;
  ht1.get_chain_lengths(v3);
  std::copy(v3.begin(), v3.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
