#ifndef INCLUDED_TELEPATH_OPERATIONS_FOLD_H
#define INCLUDED_TELEPATH_OPERATIONS_FOLD_H

#include "telepath/utilities/iterable.h"

namespace telepath{

    namespace fold_detail{

        template< typename T, typename = void >
        struct FoldImpl { 
            template< typename U, typename F >
            inline auto operator()( F&& f, const T& x, U init ) const{
                return f( init, x );
            }
        };

        template< typename T >
        struct FoldImpl< T, std::enable_if_t< utils::is_iterable<T>::value > >{
            template< typename U, typename F >
            inline auto operator()( F&& f, const T& xs, U init ) const{
                for( auto&& x : xs ){
                    init = f( init, x );
                }
                return init;
            }
        };
        
    } //namespace fold_detail

    template< typename T >
    struct Fold : public fold_detail::FoldImpl<T> {};

    template< typename F, typename T, typename U >
    inline auto fold( F&& f, const T& xs, U init )
        -> decltype( Fold<T>()( std::forward<F>( f ), xs, init ) ){
        return Fold<T>()( std::forward<F>( f ), xs, init );
    }
    
    template< typename F, typename T >
    inline auto fold( F&& f, const T& xs )
        -> decltype( Fold<T>()( std::forward<F>( f ), xs ) ){
        return Fold<T>()( std::forward<F>( f ), xs );
    }

} //namespace telepath

#endif
