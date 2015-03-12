#ifndef INCLUDED_BLAS_TRAITS_H
#define INCLUDED_BLAS_TRAITS_H

#include <cblas.h>
#include <type_traits>

namespace blas{
    
    /*
    Specialize to define the blas traits of an object. Should
    be constructed from an instance of T
    */
    template< typename T >
    struct Traits {
        
    };

    template< typename T >
    constexpr auto blas_cast( T&& x ){
        return Traits<T>( std::forward<T>( x ) );
    }
    template< typename T >
    constexpr CBLAS_ORDER layout( T&& traits ){
        return (CBLAS_ORDER) traits.layout(); }
    template< typename T >
    constexpr CBLAS_TRANSPOSE trans( T&& traits ){
        return (CBLAS_TRANSPOSE) traits.trans(); }
    template< typename T >
    constexpr CBLAS_UPLO uplo( T&& traits ){
        return (CBLAS_UPLO) traits.uplo(); }
    template< typename T >
    constexpr auto nrows( T&& traits ){ return traits.nrows(); }
    template< typename T >
    constexpr auto ncols( T&& traits ){ return traits.ncols(); }
    template< typename T >
    constexpr auto array( T&& traits ){ return traits.array(); }
    template< typename T >
    constexpr auto ld( T&& traits ){ return traits.ld(); }

    template< typename T >
    struct MatrixTraits {
        /*
        using scalar_t = ...
        static CBLAS_ORDER layout( const T& );
        static CBLAS_TRANSPOSE trans( const T& );
        static CBLAS_UPLO uplo( const T& ); --if symmetric
        static std::size_t nrows( const T& );
        static std::size_t ncols( const T& );
        static scalar_t* array( T& );
        static const scalar_t* array( const T& );
        static std::size_t ld( const T& );
        */
    };

    template< typename T >
    struct VectorTraits{
        /*
        using scalar_t = ...
        static std::size_t length( const T& );
        static std::size_t inc( const T& );
        static scalar_t* array( T& );
        static const scalar_t* array( const T& );
        */
    };

    template< typename T >
    struct BlasCast : public std::false_type{
        /*
        When implemented - extend std::true_type (define ::value = true)
        static _ blas_cast( T& );
        static _ blas_cast( const T& );
        */
    };



} //namespace blas

#endif
