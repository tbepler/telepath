#ifndef INCLUDED_TELEPATH_OPERATIONS_DIMS_H
#define INCLUDED_TELEPATH_OPERATIONS_DIMS_H

namespace telepath{

    template< typename T >
    struct Dims{ };

    template< typename T >
    inline auto dims( const T& x ) -> decltype( Dims<T>()( x ) ){
        return Dims<T>()( x );
    }

}

#endif
