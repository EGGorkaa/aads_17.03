#include "top-it-vector.hpp"
#include <iostream>
#include <iomanip>

int testDefaultVector()
{
  topit::Vector< int > v;
  return v.isEmpty();
}

bool testVectorWithValue()
{
    topit::Vector< int > v;
    v.pushBack(1);

}

int main()
{
  using test_t = bool(*)();
  using pair_t = std::pair<const char*, test_t>;
  pair_t tests[] = {
    {"Default vector is empty", testDefaultVector}
  };
  const size_t count = sizeof(tests) / sizeof(pair_t);
  std::cout<<std::boolalpha;
  bool pass = true;
  for(size_t i = 0; i < count; ++i)
  {
    bool res = tests[i].second();
    std::cout<<res<<" :";
    std::cout<< tests[i].first<<"\n";
    pass = pass && res;
  }
  std::cout<<pass<<": RESULT\n";
}
