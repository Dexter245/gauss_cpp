//
// Created by dexter on 4/27/15.
//

#include "Matrix.h"
#include <iostream>
#include <string.h>
#include <sstream>


Matrix::Matrix(int numRows, int numColumns) :
    _rows(numRows),
    _columns(numColumns)
{

    _initArray();

}

Matrix::~Matrix() {

    if(_mat != 0){
        for(int i = 0; i < _rows; i++)
            delete [] _mat[i];
        delete [] _mat;
        _mat = 0;
    }

}

void Matrix::multiply(Matrix otherMatrix) {

}

bool Matrix::isRowEchelonForm() {
    int lastPos = -1;

    for(int i = 0; i < _rows; i++){
        int pos = 0;
        for(int j = 0; j < _columns; j++){
            if(_mat[i][j] != 0){
                pos = j;
                if(pos <= lastPos)
                    return false;
                break;
            }
            if(j == _columns-1)
                pos = _columns;
        }
        lastPos = pos;
    }

    return true;
}

std::string Matrix::toString() {

    for(int i = 0; i < _rows; i++){
        for(int j = 0; j < _columns; j++){
            std::cout << _mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return std::string();
}

void Matrix::toIdentity() {

   for(int i = 0; i < _rows; i++){

       for(int j = 0; j < _columns; j++){

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

    _mat = new double*[_rows];
    for(int i = 0; i < _rows; i++){
        _mat[i] = new double[_columns];
        for(int j = 0; j < _columns; j++){
            _mat[i][j] = 0;
        }
    }

}

bool Matrix::equals(Matrix &otherMatrix) {
    if(_rows != otherMatrix._rows)
        return false;
    if(_columns != otherMatrix._columns)
        return false;
    for(int i = 0; i < _rows; i++){
        for(int j = 0; j < _columns; j++){
            if(_mat[i][j] != otherMatrix._mat[i][j])
                return false;
        }
    }
    return true;
}

