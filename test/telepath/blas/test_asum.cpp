#include <gtest/gtest.h>
#include "telepath/blas/blas_1.h"

#include <limits>

using namespace std;
using namespace telepath;

template< typename T >
class Blas1Test : public ::testing::Test {};

typedef ::testing::Types< float, double > types;
TYPED_TEST_CASE( Blas1Test, types );

TYPED_TEST( Blas1Test, asum ){

    TypeParam* v_r = new TypeParam[ 10000 ];
    for( size_t i = 0 ; i < 10000 ; ++i ){
        v_r[i] = i;
    }
    TypeParam expect_sum = (10000-1) * 10000 / 2;
    EXPECT_EQ( expect_sum, asum( 10000, v_r ) );

    TypeParam expect_sum_5 = ( 10000/5-1) * 10000 / 2;
    EXPECT_EQ( expect_sum_5, asum( 10000/5, v_r, 5 ) );
    delete v_r;
    
    complex<TypeParam>* v_c = new complex<TypeParam>[ 10000 ];
    for( size_t i = 0 ; i < 10000 ; ++i ){
        v_c[i] = complex<TypeParam>(i,i);
    }
    expect_sum = (10000-1) * 10000;
    EXPECT_EQ( expect_sum, asum( 10000, v_c ) );

    expect_sum_5 = ( 10000/5-1) * 10000;
    EXPECT_EQ( expect_sum_5, asum( 10000/5, v_c, 5 ) );
    delete v_c;

}
