#include "test_framework/generic_test.h"
long long Reverse(int x) {
  
    bool flag = false;
    long long rev = 0;
    
    if(x < 0) {
        flag = true;
    }
    
    x = abs(x);
    while (x) {
        rev = (rev * 10) + (x % 10);
        x /= 10;
    }
    
    return flag ? (-1 * rev) : rev;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_digits.cc", "reverse_digits.tsv",
                         &Reverse, DefaultComparator{}, param_names);
}
