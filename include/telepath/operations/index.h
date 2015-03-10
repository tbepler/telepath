#ifndef INCLUDED_TELEPATH_MATRIX_INDEX_H
#define INCLUDED_TELEPATH_MATRIX_INDEX_H

namespace telepath{

    struct all{ };
    struct range{
        std::size_t begin;
        std::size_t end;
    };

    template< typename T >
    struct Index{ };

    template< typename T, typename... Params >
    inline auto index( T& x, Params&&... args )
        -> decltype( Index<T>()( x, std::forward<Params>( args )... ) )
    {
        return Index<T>()( x, std::forward<Params>( args )... );
    }

    template< typename T, typename... Params >
    inline auto index( const T& x, Params&&... args )
        -> decltype( Index<T>()( x, std::forward<Params>( args )... ) )
    {
        return Index<T>()( x, std::forward<Params>( args )... );
    }


} //namespace telepath

#endif
