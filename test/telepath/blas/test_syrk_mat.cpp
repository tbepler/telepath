#include <gtest/gtest.h>
#include "telepath/blas/level3/syrk_mat.h"
#include "telepath/matrix.h"

#include <vector>

using namespace telepath;

TEST( BLAS_SyrkMat, Eval ){
    
    double arrayA[] = { 1, 3, 5, 2, 4, 6 };
    matrix<double> A = {
        COL_MAJOR,
        NONE,
        arrayA,
        3,
        2,
        3
    };
    std::vector<double> arrayC( 9 );
    sym_matrix<double> C = {
        COL_MAJOR,
        NONE,
        UPPER,
        &arrayC[0],
        3,
        3,
        3
    };
    std::vector<double> expect = { 5, 0, 0, 11, 25, 0, 17, 39, 61 };

    syrk( 1, A, 1, C );
    EXPECT_EQ( expect, arrayC );

 
}
