#include <gtest/gtest.h>
#include "telepath/operations/numel.h"

#include <vector>

/*
    If a type T defines T.numel(), then it should be used,
    otherwise if T defines Size<T>, then numel should return
    the product of the elements of size( T )
*/

using namespace telepath;

template< std::size_t N >
struct Dims{
    std::size_t dims[ N ];
    inline auto size() const{
        return std::vector<std::size_t>( std::begin(dims), std::end(dims) );
    }
};

template< std::size_t N >
struct Batarang{
    std::size_t dims[ N ];
    inline auto numel() const{
        return this->dims[0];
    }
};

namespace telepath{
template< std::size_t N >
    struct Numel< Batarang<N> >{
        inline auto operator()( const Batarang<N>& x ) const{
            return x.numel();
        }
    };
}

TEST( Operations_NumelTest, IterableSize ){
    Dims<1> d1 = { 5 };
    EXPECT_EQ( 5, numel( d1 ) );
    Dims<4> d4 = { 5, 2, 3, 1 };
    EXPECT_EQ( 30, numel( d4 ) );
    Batarang<4> holy_cow_batman = { 5, 2, 3, 1 };
    EXPECT_EQ( 5, numel( holy_cow_batman ) );
}

