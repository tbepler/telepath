#ifndef INCLUDED_TELEPATH_MATRIX_H
#define INCLUDED_TELEPATH_MATRIX_H

#include <cblas.h>
#include "telepath/blas/traits.h"

namespace telepath{

    enum ORDER {
        ROW_MAJOR = CblasRowMajor,
        COL_MAJOR = CblasColMajor
    };
    enum TRANSPOSE {
        NONE = CblasNoTrans,
        TRANS = CblasTrans,
        CONJ_TRANS = CblasConjTrans
    };
    enum UPLO{
        UPPER = CblasUpper,
        LOWER = CblasLower,
    };

    /*
    Struct for storing BLAS matrix data
    */
    template< typename T >
    struct matrix{
        ORDER layout;
        TRANSPOSE trans;
        T* array;
        std::size_t rows;
        std::size_t cols;
        std::size_t ld;
    };

    template< typename T >
    struct sym_matrix{
        ORDER layout;
        TRANSPOSE trans;
        UPLO uplo;
        T* array;
        std::size_t rows;
        std::size_t cols;
        std::size_t ld;
    };

} //namespace telepath

namespace blas{

    template< typename T >
    struct MatrixTraits< telepath::matrix<T> >{
        using mat = typename telepath::matrix<T>;
        using scalar_t = T;
        constexpr static CBLAS_ORDER layout( const mat& m ){
            return (CBLAS_ORDER) m.layout;
        }
        constexpr static CBLAS_TRANSPOSE trans( const mat& m ){
            return (CBLAS_TRANSPOSE) m.trans;
        }
        constexpr static auto nrows( const mat& m ){ return m.rows; }
        constexpr static auto ncols( const mat& m ){ return m.cols; }
        constexpr static T* array( mat& m ){ return m.array; }
        constexpr static const T* array( const mat& m ){ return m.array; }
        constexpr static auto ld( const mat& m ){ return m.ld; }
    };
    
    template< typename T >
    struct MatrixTraits< telepath::sym_matrix<T> >{
        using mat = typename telepath::sym_matrix<T>;
        using scalar_t = T;
        constexpr static CBLAS_ORDER layout( const mat& m ){
            return (CBLAS_ORDER) m.layout;
        }
        constexpr static CBLAS_TRANSPOSE trans( const mat& m ){
            return (CBLAS_TRANSPOSE) m.trans;
        }
        constexpr static CBLAS_UPLO uplo( const mat& m ){
            return (CBLAS_UPLO) m.uplo;
        }
        constexpr static auto nrows( const mat& m ){ return m.rows; }
        constexpr static auto ncols( const mat& m ){ return m.cols; }
        constexpr static T* array( mat& m ){ return m.array; }
        constexpr static const T* array( const mat& m ){ return m.array; }
        constexpr static auto ld( const mat& m ){ return m.ld; }
    };

} //namespace blas

#endif
