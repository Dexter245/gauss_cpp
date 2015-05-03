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

TEST(Matrix, equals){
    Matrix mat1(2, 3);
    Matrix mat2(2, 3);
    double arr1[2][3] = { {1, 2, 3}, {4, 5, 6} };
    mat1.set(arr1);
    mat2.set(arr1);
    ASSERT_TRUE(mat1.equals(mat2));
    arr1[1][0] = 7;
    mat2.set(arr1);
    ASSERT_FALSE(mat1.equals(mat2));
}

TEST(Matrix, isRowEchelonForm){
    Matrix mat(3, 4);
    double arr1[3][4] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0} };
    mat.set(arr1);
    ASSERT_TRUE(mat.isRowEchelonForm());

    double arr2[3][4] = { {1, 1, 1, 1}, {0, 1, 1, 1}, {0, 0, 1, 1} };
    mat.set(arr2);
    ASSERT_TRUE(mat.isRowEchelonForm());

    double arr3[3][4] = { {1, 1, 1, 1}, {0, 1, 1, 1}, {0, 0, 0, 0} };
    mat.set(arr3);
    ASSERT_TRUE(mat.isRowEchelonForm());

    double arr4[3][4] = { {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0} };
    mat.set(arr4);
    ASSERT_TRUE(mat.isRowEchelonForm());

    double arr5[3][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
    mat.set(arr5);
    ASSERT_TRUE(mat.isRowEchelonForm());


    double arr_1[3][4] = { {1, 1, 1, 1}, {1, 0, 0, 0}, {0, 0, 0, 0} };
    mat.set(arr_1);
    ASSERT_FALSE(mat.isRowEchelonForm());

    double arr_2[3][4] = { {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 1} };
    mat.set(arr_2);
    ASSERT_FALSE(mat.isRowEchelonForm());

    double arr_3[3][4] = { {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1} };
    mat.set(arr_3);
    ASSERT_FALSE(mat.isRowEchelonForm());

    double arr_4[3][4] = { {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1} };
    mat.set(arr_4);
    ASSERT_FALSE(mat.isRowEchelonForm());

    double arr_5[3][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1} };
    mat.set(arr_5);
    ASSERT_FALSE(mat.isRowEchelonForm());



}







