#include "test_framework/generic_test.h"
int Fibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "fibonacci.cc", "fibonacci.tsv", &Fibonacci,
                         DefaultComparator{}, param_names);
}
