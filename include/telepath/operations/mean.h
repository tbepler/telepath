#ifndef INCLUDED_TELEPATH_OPERATIONS_MEAN_H
#define INCLUDED_TELEPATH_OPERATIONS_MEAN_H

#include "telepath/operations/sum.h"
#include "telepath/operations/numel.h"

namespace telepath{

    template< typename T >
    struct Mean{
        inline auto operator()( const T& x ) const{
            return sum( x ) / numel( x );
        }
    };

    template< typename T >
    inline auto mean( const T& x ) -> decltype( Mean<T>()( x ) ){
        return Mean<T>()( x );
    }

} //namespace telepath

#endif
