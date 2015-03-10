#ifndef INCLUDED_TELEPATH_OPERATIONS_COLS_H
#define INCLUDED_TELEPATH_OPERATIONS_COLS_H

namespace telepath{

    //Object to define a view of the cols of T
    //Should allow mapping/folding/etc. over the col space of T
    template< typename T >
    struct Cols{ };

    //const view of the cols
    template< typename T >
    struct ConstCols{ };
    
    template< typename M >
    inline auto cols( const M& A ) -> decltype( ConstCols<M>( A ) ){
        return ConstCols<M>( A );
    }

    template< typename M >
    inline auto cols( M& A ) -> decltype( Cols<M>( A ) ){
        return Cols<M>( A );
    }

} //namespace telepath

#endif
