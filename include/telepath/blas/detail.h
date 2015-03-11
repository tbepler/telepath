#ifndef INCLUDED_BLAS_DETAIL_H
#define INCLUDED_BLAS_DETAIL_H

#include <cblas.h>
#include "telepath/blas/traits.h"

namespace blas{

    namespace matrix{

        namespace matrix_detail{

            template< typename T, bool = BlasCast<T>::value >
            struct BlasMatImpl { };

            template< typename T >
            struct BlasMatImpl< T, true >{
                using mat_t = decltype( BlasCast<T>::blas_cast(
                    std::declval<T>() ) );
                mat_t mat;
                constexpr BlasMatImpl( const T& m )
                    : mat( BlasCast<T>::blas_cast( m ) ) { }
                operator mat_t&() { return mat; }
                operator const mat_t&() const{ return mat; }
            };

            template< typename T >
            struct BlasMatImpl< T, false >{
                using mat_t = T;
                mat_t& mat;
                constexpr BlasMatImpl( T& m ) : mat( m ) { }
                operator mat_t&() { return mat; }
                operator const mat_t&() const{ return mat; }
            };
            
            template< typename T, bool = BlasCast<T>::value >
            struct ConstBlasMatImpl { };

            template< typename T >
            struct ConstBlasMatImpl< T, true >{
                using mat_t = decltype( BlasCast<T>::blas_cast(
                    std::declval<T>() ) );
                mat_t mat;
                constexpr ConstBlasMatImpl( const T& m )
                    : mat( BlasCast<T>::blas_cast( m ) ) { }
                operator const mat_t&() const{ return mat; }
            };

            template< typename T >
            struct ConstBlasMatImpl< T, false >{
                using mat_t = T;
                const mat_t& mat;
                constexpr ConstBlasMatImpl( const T& m ) : mat( m ) { }
                operator const mat_t&() const{ return mat; }
            };

        } //namespace matrix_detail

        template< typename T >
        struct Mat : public matrix_detail::BlasMatImpl<T> {
            using impl = typename matrix_detail::BlasMatImpl<T>; 
            using impl::impl;
        };

        template< typename T >
        struct ConstMat : public matrix_detail::ConstBlasMatImpl<T>{
            using impl = typename matrix_detail::ConstBlasMatImpl<T>; 
            using impl::impl;
        };

        template< typename T >
        using scalar_t = typename MatrixTraits<T>::scalar_t;

        template< typename T >
        constexpr CBLAS_ORDER layout( const T& x ){
            return MatrixTraits<T>::layout( x );
        }
        
        template< typename T >
        constexpr CBLAS_TRANSPOSE trans( const T& x ){
            return MatrixTraits<T>::trans( x );
        }
        
        template< typename T >
        constexpr CBLAS_UPLO uplo( const T& x ){
            return MatrixTraits<T>::uplo( x );
        }
        
        template< typename T >
        constexpr std::size_t nrows( const T& x ){
            return MatrixTraits<T>::nrows( x );
        }
        
        template< typename T >
        constexpr std::size_t ncols( const T& x ){
            return MatrixTraits<T>::ncols( x );
        }
        
        template< typename T >
        constexpr std::size_t ld( const T& x ){
            return MatrixTraits<T>::ld( x );
        }
        
        template< typename T >
        constexpr auto array( T& x ){
            return MatrixTraits<T>::array( x );
        }
        
        template< typename T >
        constexpr auto array( const T& x ){
            return MatrixTraits<T>::array( x );
        }

    } //namespace matrix

    template< typename T >
    struct MatrixTraits< matrix::Mat<T> >
        : public MatrixTraits< typename matrix::Mat<T>::mat_t > { };
    
    template< typename T >
    struct MatrixTraits< matrix::ConstMat<T> >
        : public MatrixTraits< typename matrix::ConstMat<T>::mat_t > { };

    namespace vector{

        namespace vector_detail{

            template< typename T, bool = BlasCast<T>::value >
            struct BlasVecImpl { };

            template< typename T >
            struct BlasVecImpl< T, true >{
                using vec_t = decltype( BlasCast<T>::blas_cast(
                    std::declval<T>() ) );
                vec_t vec;
                constexpr BlasVecImpl( const T& v )
                    : vec( BlasCast<T>::blas_cast( v ) ) { }
                operator vec_t&() { return vec; }
                operator const vec_t&() const{ return vec; }
            };

            template< typename T >
            struct BlasVecImpl< T, false >{
                using vec_t = T;
                vec_t& vec;
                BlasVecImpl( const T& v ) : vec( v ) { }
                operator vec_t&() { return vec; }
                operator const vec_t&() const{ return vec; }
            };

        } //namespace vector_detail

        template< typename T >
        struct Vec : public vector_detail::BlasVecImpl<T> {
            using impl = typename vector_detail::BlasVecImpl<T>; 
            using impl::impl;
        };

        template< typename T >
        using scalar_t = typename VectorTraits<T>::scalar_t;

        template< typename T >
        constexpr auto length( const T& x ){
            return VectorTraits<T>::length( x );
        }

        template< typename T >
        constexpr auto inc( const T& x ){
            return VectorTraits<T>::inc( x );
        }

        template< typename T >
        constexpr auto array( T& x ){
            return VectorTraits<T>::array( x );
        }
        
        template< typename T >
        constexpr auto array( const T& x ){
            return VectorTraits<T>::array( x );
        }

    } //namespace vector

    template< typename T >
    struct VectorTraits< vector::Vec<T> >
        : public VectorTraits< typename vector::Vec<T>::vec_t > { };

} //namespace blas

#endif
