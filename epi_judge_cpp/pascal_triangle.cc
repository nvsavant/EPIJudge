#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<vector<int>> GeneratePascalTriangle(int num_rows) {
    if(num_rows == 0) {
        return {};
    }
    
    vector<vector<int>> retVec;
    for (int line = 1; line <= num_rows; line++) {
        vector<int> vec;
        long c = 1;
        for (int i = 1; i <= line; i++) {
            vec.push_back(c);
            c = c * (line - i) / i;
        }
        retVec.push_back(vec);
    }
    
    return retVec;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_rows"};
  return GenericTestMain(args, "pascal_triangle.cc", "pascal_triangle.tsv",
                         &GeneratePascalTriangle, DefaultComparator{},
                         param_names);
}
