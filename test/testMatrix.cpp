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
    }



}







