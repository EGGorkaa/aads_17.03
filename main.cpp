#include <iostream>
#include "top-it-vector.hpp"
#include <iomanip>

bool testDefaultVector()
{
  topit::Vector< int > v;
  return v.isEmpty();
}

bool testVectorWithValue()
{
  topit::Vector< int > v;
  v.pushBack(1);
  return !v.isEmpty();
}

bool testElementAccess()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  return v[0] == 1 && v[1] == 2;
}

bool testCopyConstructor()
{
  topit::Vector< int > v;
  v.pushBack(1);
  topit::Vector< int > yav = v;
  bool isAllEqual = v.getSize() == yav.getSize();
  for (size_t i = 0; isAllEqual && i < v.getSize(); ++i) {
    isAllEqual = isAllEqual && (v[i] == yav[i]);
  }
  return isAllEqual;
}

bool testSwap()
{
  topit::Vector< int > v;
  v.pushBack(1);
  topit::Vector< int > yav;
  yav.pushBack(2);
  v.swap(yav);
  return yav[0] == 1 && v[0] == 2;
}

bool testPushFront()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushFront(2);
  return v[0] == 2 && v[1] == 1;
}

bool testEmptyCapacity()
{
  topit::Vector< int > v;
  return !v.getCapacity();
}

bool testEmptySize()
{
  topit::Vector< int > v;
  return !v.getSize();
}

bool testPopBack()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.popBack();
  return v.getSize() == 1 && v[0] == 1;
}

int main()
{
  using test_t = bool (*)();
  using pair_t = std::pair< const char *, test_t >;
  pair_t tests[] = {{"Default vector is empty", testDefaultVector},
                    {"Vector with any value is not empty", testVectorWithValue},
                    {"Inbound access elenets", testElementAccess},
                    {"Sizes must be equal as elements", testCopyConstructor},
                    {"Correct swap elements", testSwap},
                    {"The element should be added in the beginning", testPushFront},
                    {"Capacity of empty vector should be 0", testEmptyCapacity},
                    {"Size of empty vector should be 0", testEmptySize},
                    {"Last element should be deleted", testPopBack}};
  const size_t count = sizeof(tests) / sizeof(pair_t);
  std::cout << std::boolalpha;
  bool pass = true;
  for (size_t i = 0; i < count; ++i) {
    bool res = tests[i].second();
    std::cout << res << ": ";
    std::cout << tests[i].first << '\n';
    pass = pass && res;
  }
  std::cout << pass;
  std::cout << ": RESULT\n";
}