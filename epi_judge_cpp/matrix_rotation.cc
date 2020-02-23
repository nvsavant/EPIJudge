#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
void RotateMatrix(vector<vector<int>>* square_matrix_ptr) {
    vector<vector<int>>& A = *square_matrix_ptr;
    
    //Transpose
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if(i > j) {
                std::swap(A[i][j], A[j][i]);
            }
        }
    }
    
    //Swap colums
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size() / 2; j++) {
            std::swap(A[i][j], A[i][A[i].size() - 1 - j]);
        }
    }
        
    return;
}
vector<vector<int>> RotateMatrixWrapper(vector<vector<int>> square_matrix) {
  RotateMatrix(&square_matrix);
  return square_matrix;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"square_matrix"};
  return GenericTestMain(args, "matrix_rotation.cc", "matrix_rotation.tsv",
                         &RotateMatrixWrapper, DefaultComparator{},
                         param_names);
}
