#ifndef INCLUDED_TELEPATH_OPERATIONS_SIZE_H
#define INCLUDED_TELEPATH_OPERATIONS_SIZE_H

namespace telepath{

    template< typename T >
    struct Size{
        inline auto operator()( const T& x ) const{ return x.size(); }
    };

    template< typename T >
    inline auto size( const T& x ) -> decltype( Size<T>()( x ) ){
        return Size<T>()( x );
    }

} //namespace telepath

#endif
