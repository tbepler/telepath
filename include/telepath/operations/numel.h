#ifndef INCLUDED_TELEPATH_OPERATIONS_NUMEL_H
#define INCLUDED_TELEPATH_OPERATIONS_NUMEL_H

#include "telepath/operations/size.h"
#include "telepath/operations/prod.h"

namespace telepath{

    template< typename T >
    struct Numel{
        inline auto operator()( const T& x ) const{
            return prod( size( x ) );
        }
    };

    template< typename T >
    inline auto numel( const T& x ) -> decltype( Numel<T>()( x ) ){
        return Numel<T>()( x );
    }

} //namespace telepath

#endif
