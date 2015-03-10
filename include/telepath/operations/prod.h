#ifndef INCLUDED_TELEPATH_OPERATIONS_PROD_H
#define INCLUDED_TELEPATH_OPERATIONS_PROD_H

#include "telepath/operations/fold.h"

namespace telepath{

    template< typename T >
    struct Product{
        template< typename U >
        inline auto operator()( const T& x, U init ) const{
            return fold( []( auto&& a, auto&& b ){ return a*b; },
                x, init );
        }
        inline auto operator()( const T& x ) const{
            return fold( []( auto&& a, auto&& b ){ return a*b; },
                x, 1 );
        }
    };

    template< typename T, typename U >
    inline auto prod( const T& x, U init ) -> decltype( Product<T>()( x, init ) ){
        return Product<T>()( x, init );
    }
    
    template< typename T >
    inline auto prod( const T& x ) -> decltype( Product<T>()( x ) ){
        return Product<T>()( x );
    }

} //namespace telepath

#endif
