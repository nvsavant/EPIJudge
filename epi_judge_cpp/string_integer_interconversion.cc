#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;

string IntToString(int x) {
    string str;
    bool negFlag = false;
    int localX = abs(x);
    if(x < 0) {
        negFlag = true;
    }
    
    
    while (x) {
        str.push_back('0' + (localX % 10));
        localX /= 10;
    }
    
    if(negFlag) {
        str.push_back('-');
    }
    
    return {str.rbegin(), str.rend()};
}
int StringToInt(const string& s) {
    int result = 0;
    int end = 0;
    
    if(s[0] == '-') {
        end = 1;
    }
    
    for(int i = s.size() - 1; i > end; i++) {
        int num = s[i] - '0';
        result = (result * 10) + num;
    }
    
    return s[0] == '-' ? (-1 * result) : result;
}
void Wrapper(int x, const string& s) {
  if (stoi(IntToString(x)) != x) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};
  return GenericTestMain(args, "string_integer_interconversion.cc",
                         "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}
