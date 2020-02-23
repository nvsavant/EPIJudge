#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
bool isPrime(int n) {
    if(n <= 1) {
        return false;
    }
    
    if(n == 2 || n == 3) {
        return true;
    }
    
    for (int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    
    return true;
}

// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
  // TODO - you fill in here.
    vector<int> retVec;
    for (int i = 1; i <= n; i++) {
        if(isPrime(i)) {
            retVec.push_back(i);
        }
    }
    
    return retVec;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "prime_sieve.cc", "prime_sieve.tsv",
                         &GeneratePrimes, DefaultComparator{}, param_names);
}
