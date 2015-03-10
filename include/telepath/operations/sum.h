#ifndef INCLUDED_TELEPATH_OPERATIONS_SUM_H
#define INCLUDED_TELEPATH_OPERATIONS_SUM_H

#include "telepath/matrix/operations/fold.h"

namespace telepath{

    template< typename T >
    struct Sum{
        template< typename U >
        inline auto operator()( const T& x, U init ) const{
            return fold( []( auto&& a, auto&& b ){ return a + b; },
                x, init );
        }
        inline auto operator()( const T& x ) const{
            return fold( []( auto&& a, auto&& b ){ return a + b; },
                x, 0 );
        }
    };

    template< typename T, typename U >
    inline auto sum( const T& A, U init ) -> decltype( Sum<T>()( A, init ) ){
        return Sum<T>()( A, init );
    }
    
    template< typename T >
    inline auto sum( const T& A ) -> decltype( Sum<T>()( A ) ){
        return Sum<T>()( A );
    }

} //namespace telepath

#endif
