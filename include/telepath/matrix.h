#ifndef INCLUDED_TELEPATH_MATRIX_H
#define INCLUDED_TELEPATH_MATRIX_H

#include <cblas.h>

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
        LOWER = CblasLower
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
    inline ORDER layout( const matrix<T>& mat ){ return mat.layout; }
    template< typename T >
    inline TRANSPOSE getTrans( const matrix<T>& mat ){ return mat.trans; }
    template< typename T >
    inline T* array( matrix<T>& mat ){ return mat.array; }
    template< typename T >
    inline const T* array( const matrix<T>& mat ){ return mat.array; }
    template< typename T >
    inline auto nrows( const matrix<T>& mat ){ return mat.rows; }
    template< typename T >
    inline auto ncols( const matrix<T>& mat ){ return mat.cols; }
    template< typename T >
    inline auto ldInc( const matrix<T>& mat ){ return mat.ld; }

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

    template< typename T >
    inline ORDER layout( const sym_matrix<T>& mat ){ return mat.layout; }
    template< typename T >
    inline TRANSPOSE getTrans( const sym_matrix<T>& mat ){ return mat.trans; }
    template< typename T >
    inline UPLO uplo( const sym_matrix<T>& mat ){ return mat.uplo; }
    template< typename T >
    inline T* array( sym_matrix<T>& mat ){ return mat.array; }
    template< typename T >
    inline const T* array( const sym_matrix<T>& mat ){ return mat.array; }
    template< typename T >
    inline auto nrows( const sym_matrix<T>& mat ){ return mat.rows; }
    template< typename T >
    inline auto ncols( const sym_matrix<T>& mat ){ return mat.cols; }
    template< typename T >
    inline auto ldInc( const sym_matrix<T>& mat ){ return mat.ld; }

} //namespace telepath

#endif
