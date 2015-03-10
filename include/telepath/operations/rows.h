#ifndef INCLUDED_TELEPATH_MATRIX_OPERATIONS_ROWS_H
#define INCLUDED_TELEPATH_MATRIX_OPERATIONS_ROWS_H

namespace telepath{

    //Specialize to define a function for providing a view of the rows of T
    //Should allow mapping/folding/etc. over the row space of T
    template< typename T >
    struct Rows{ };

    template< typename M >
    inline auto rows( const M& A ) -> decltype( Rows<M>()( A ) ){
        return Rows<M>()( A );
    }

    template< typename M >
    inline auto rows( M& A ) -> decltype( Rows<M>()( A ) ){
        return Rows<M>()( A );
    }

    template< typename T >
    struct NumRows{ };

    template< typename T >
    inline auto numrows( const T& x ) -> decltype( NumRows<T>()( x ) ){
        return NumRows<T>()( x );
    }

} //namespace telepath

#endif
