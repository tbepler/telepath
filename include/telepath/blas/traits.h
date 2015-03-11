#ifndef INCLUDED_BLAS_TRAITS_H
#define INCLUDED_BLAS_TRAITS_H

#include <type_traits>

namespace blas{

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
