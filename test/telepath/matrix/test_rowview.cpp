#include <gtest/gtest.h>

/*

#include "telepath/matrix/mat_rows.h"

double array[] = {
1,
2,
3,
4,
5,
6,
7,
8,
9
};

using namespace telepath;
    
using matrixD = matrix<double>;
using matrixD_t = matrix<double,TRANS>;

1 4 7
2 5 8
3 6 9

const static matrixD mat = { array, 3, 3, 0 };
const static matrixD_t mat_t = { array, 3, 3, 0 };

TEST( Matrix_RowViewTest, Indexing ){
    vector<double> row0 = { array, 3, 3 };
    vector<double> row1 = { array+1, 3, 3 };
    vector<double> row2 = { array+2, 3, 3 };

    EXPECT_EQ( numrows( rows( mat ) ), 3 );
    EXPECT_EQ( index( rows( mat ), 0 ), row0 );
    EXPECT_EQ( index( rows( mat ), 1 ), row1 );
    EXPECT_EQ( index( rows( mat ), 2 ), row2 );

    vector<double> col0 = { array, 3, 1 };
    vector<double> col1 = { array+3, 3, 1 };
    vector<double> col2 = { array+6, 3, 1 };
    
    EXPECT_EQ( numrows( rows( mat_t ) ), 3 );
    EXPECT_EQ( index( rows( mat_t ), 0 ), col0 );
    EXPECT_EQ( index( rows( mat_t ), 1 ), col1 );
    EXPECT_EQ( index( rows( mat_t ), 2 ), col2 );

    auto subview = index( rows( mat_t ), range{1,3} );
    EXPECT_EQ( numrows( subview ), 2 );
    EXPECT_EQ( index( subview, 0 ), col1 );
    EXPECT_EQ( index( subview, 1 ), col2 );

}

TEST( Matrix_RowViewTest, Fold ){

    double sum_array[3] = {0};
    vector<double> row_sum = { sum_array, 3, 1 };

}

*/
