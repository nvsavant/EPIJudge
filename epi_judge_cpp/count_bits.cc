#include "test_framework/generic_test.h"

short CountBits(unsigned int x) {
    short numOfSetBits = 0;
    while (x) {
        if(x % 2) {
            numOfSetBits++;
        }
        x /= 2;
    }
    
    return numOfSetBits;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "count_bits.cc", "count_bits.tsv", &CountBits,
                         DefaultComparator{}, param_names);
}
