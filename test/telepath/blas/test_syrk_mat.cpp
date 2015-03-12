#include <gtest/gtest.h>
#include "telepath/blas/level3/syrk_mat.h"
#include "telepath/matrix.h"

#include <vector>

using namespace telepath;

template< typename T >
class Matrix{
    std::vector<T> data_;
    std::size_t rows_;
    std::size_t cols_;
    public:
        constexpr Matrix( std::size_t rows, std::size_t cols )
            : data_( rows*cols ), rows_( rows ), cols_( cols ) { }
};

TEST( BLAS_SyrkMat, Eval ){
    
    double arrayA[] = { 1, 3, 5, 2, 4, 6 };
    /*
    1 2
    3 4
    5 6
    */
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

    blas::syrk( A, C );
    EXPECT_EQ( expect, arrayC );

    /*
    1 3 5
    2 4 6
    */
    matrix<double> Atrans = A;
    Atrans.trans = TRANS;
    std::vector<double> arrayCtrans( 4 );
    sym_matrix<double> Ctrans = {
        COL_MAJOR,
        NONE,
        UPPER,
        &arrayCtrans[0],
        2,
        2,
        2
    };
    std::vector<double> expect_trans = { 35, 0, 44, 56 };

    blas::syrk( Atrans, Ctrans );
    EXPECT_EQ( expect_trans, arrayCtrans );
 
}
