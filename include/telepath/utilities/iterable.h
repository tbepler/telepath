#ifndef INCLUDED_UTILS_ITERABLE_H
#define INCLUDED_UTILS_ITERABLE_H

#include <utility>
#include <iterator>
#include "telepath/utilities/iterator_traits.h"

namespace utils{

    namespace iterable_detail{
        
        using std::begin; using std::end;

        template< typename T >
        auto adl_begin( T&& t ) -> decltype( begin( std::declval<T>() ) ){
            return begin( std::forward<T>( t ) );
        }
        template< typename T >
        auto adl_end( T&& t ) -> decltype( end( std::declval<T>() ) ){
            return end( std::forward<T>( t ) );
        }

        template< typename T >
        using sink_t = void;
/*
        template< typename T, typename = void >
        struct is_iterator : public std::false_type{};

        template< typename T >
        struct is_iterator< T, sink_t<
            typename std::iterator_traits<T>::value_type> >
            : public std::true_type{};
*/
        template< typename T >
        using begin_t = decltype( adl_begin( std::declval<T&>() ) );
        template< typename T >
        using end_t = decltype( adl_end( std::declval<T&>() ) );

        template< typename T, typename = void >
        struct is_iterable : public std::false_type{};

        template< typename T >
        struct is_iterable< T, typename std::enable_if<
            is_iterator< begin_t<T> >::value && is_iterator< end_t<T> >::value,
            void
            >::type > : public std::true_type{};

    } //namespace detail

    using iterable_detail::adl_begin;
    using iterable_detail::adl_end;
    using iterable_detail::begin_t;
    using iterable_detail::end_t;

    template< typename T >
    struct is_iterable : public iterable_detail::is_iterable<T> {};

    template< typename T >
    using iterable = typename std::enable_if< is_iterable<T>::value, T >::type;
     
    template< typename T >
    using uniterable = typename std::enable_if< !is_iterable<T>::value,
        T >::type;

} //namespace utils

#endif
