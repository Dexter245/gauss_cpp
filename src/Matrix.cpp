//
// Created by dexter on 4/27/15.
//

#include "Matrix.h"


Matrix::Matrix(int numRows, int numColumns) {

    this->_numRows = numRows;
    this->_numColumns = numColumns;
    _initArray();

}

Matrix::~Matrix() {

    if(_mat != 0){
        for(int i = 0; i < _numRows; i++)
            delete [] _mat[i];
        delete [] _mat;
        _mat = 0;
    }

}

void Matrix::multiply(Matrix otherMatrix) {

}

bool Matrix::isRowEchelonForm() {
    return false;
}

std::string Matrix::toString() {
    return std::string();
}

void Matrix::toIdentity() {

   for(int i = 0; i < _numRows; i++){

       for(int j = 0; j < _numColumns; j++){

           if(i == j)
               _mat[i][j] = 1;
           else
               _mat[i][j] = 0;

       }

   }

}

void Matrix::toRowScale(int rowToScale, double scaleValue) {

}

void Matrix::toRowSwitch(int row1, int row2) {

}

void Matrix::toScaleAndAdd(int rowToScale, double scaleValue, int rowToAddTo) {

}

void Matrix::_initArray() {

    _mat = new double*[_numRows];
    for(int i = 0; i < _numRows; i++){
        _mat[i] = new double[_numColumns];
        for(int j = 0; j < _numColumns; j++){
            _mat[i][j] = 0;
        }
    }

}

bool Matrix::equals(Matrix &otherMatrix) {
    if(_numRows != otherMatrix._numRows)
        return false;
    if(_numColumns != otherMatrix._numColumns)
        return false;
    for(int i = 0; i < _numRows; i++){
        for(int j = 0; j < _numColumns; j++){
            if(_mat[i][j] != otherMatrix._mat[i][j])
                return false;
        }
    }
    return true;
}

