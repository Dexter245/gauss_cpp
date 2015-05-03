#include "testMatrix.h"
#include <gtest/gtest.h>
#include "../src/Matrix.h"

TEST(Matrix, createAndDelete){
    auto a = [] (int a, int b) {
        Matrix *mat = new Matrix(a, b);
        delete mat;
        exit(0);
    };

    ASSERT_EXIT(a(4, 4), ::testing::ExitedWithCode(0), "");
    ASSERT_EXIT(a(5, 7), ::testing::ExitedWithCode(0), "");
    ASSERT_EXIT(a(7, 5), ::testing::ExitedWithCode(0), "");
}

TEST(Matrix, toIdentity){

    for(int t = 0; t < numIdtTests; t++){
        int numRows = idtTestParams[t][0];
        int numColumns = idtTestParams[t][1];
        Matrix *mat = new Matrix(numRows, numColumns);
        mat->toIdentity();
        double **matData = mat->getMatrixData();
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numColumns; j++){
                ASSERT_EQ(idtMatrices[t][i][j], matData[i][j]);
            }
        }
        delete mat;
    }

}

TEST(Matrix, set){
    Matrix mat(1, 1);
    double a[1][1] = {1};
    mat.set(a);

    for(int t = 0; t < numSetTests; t++){
        int rows = setTestParams[t][0];
        int columns = setTestParams[t][1];
        Matrix mat(rows, columns);
        mat.set(setMatrices[t]);
        double **matData = mat.getMatrixData();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                ASSERT_EQ(setMatrices[t][i][j], matData[i][j]);
            }
        }
    }
}

//TEST(Matrix, equals){
//    Matrix mat(2, 2);
//    mat.set({1, 1, 1});
//    double a[2][2] = {{1, 2}, {1, 2}};
//    double b[] = {1, 2};
//    std::vector<double> c(b);
//    c.
//    mat.set(b);
//}







