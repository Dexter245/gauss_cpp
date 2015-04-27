//
// Created by dexter on 4/27/15.
//

#ifndef GAUSS_CPP_MATRIX_H
#define GAUSS_CPP_MATRIX_H

#include <string>

class Matrix {

private:
    double **_mat = 0;
    int _numRows = 0;
    int _numColumns = 0;

    void _initArray();

public:
    Matrix(int numRows, int numColumns);
    ~Matrix();

    void multiply(Matrix otherMatrix);
    bool isRowEchelonForm();//ZeilenStufenForm
    std::string toString();

    void toIdentity();
    void toRowScale(int rowToScale, double scaleValue);
    void toRowSwitch(int row1, int row2);
    void toScaleAndAdd(int rowToScale, double scaleValue,
                         int rowToAddTo);






};


#endif //GAUSS_CPP_MATRIX_H
