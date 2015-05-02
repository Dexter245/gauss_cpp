//
// Created by dexter on 5/2/15.
//

#ifndef GAUSS_CPP_TESTMATRIX_H
#define GAUSS_CPP_TESTMATRIX_H

const int numIdtTests = 3;
int idtTestParams[numIdtTests][2] = {
        {1, 1}, {2, 2}, {3, 3}
};

double idtMatrices[numIdtTests][5][5]{
        {
                {1}
        },
        {
                {1, 0},
                {0, 1}
        },
        {
                {1, 0, 0},
                {0, 1, 0},
                {0, 0, 1}
        }
};









#endif //GAUSS_CPP_TESTMATRIX_H
