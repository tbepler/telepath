#ifndef INCLUDED_TELEPATH_LAPACK_DRIVERS_LLS_H
#define INCLUDED_TELEPATH_LAPACK_DRIVERS_LLS_H

#include <lapacke.h>

namespace telepath{

    template< typename T >
    auto posv( int matrix_order, char uplo, std::size_t n, std::size_t nrhs,
        T* a, std::size_t lda, T* b, std::size_t ldb );
    template<>
    inline auto posv<float>( int matrix_order, char uplo, std::size_t n,
        std::size_t nrhs, float* a, std::size_t lda, float* b,
        std::size_t ldb ){
        return LAPACKE_sposv( matrix_order, uplo, n, nrhs, a, lda, b, ldb );
    }
    template<>
    inline auto posv<double>( int matrix_order, char uplo, std::size_t n,
        std::size_t nrhs, double* a, std::size_t lda, double* b,
        std::size_t ldb ){
        return LAPACKE_dposv( matrix_order, uplo, n, nrhs, a, lda, b, ldb );
    }
    template<>
    inline auto posv<std::complex<float> >( int matrix_order, char uplo,
        std::size_t n, std::size_t nrhs, std::complex<float>* a,
        std::size_t lda, std::complex<float>* b, std::size_t ldb ){
        return LAPACKE_cposv( matrix_order, uplo, n, nrhs, a, lda, b, ldb );
    }
    template<>
    inline auto posv<std::complex<double> >( int matrix_order, char uplo,
        std::size_t n, std::size_t nrhs, std::complex<double>* a,
        std::size_t lda, std::complex<double>* b, std::size_t ldb ){
        return LAPACKE_zposv( matrix_order, uplo, n, nrhs, a, lda, b, ldb );
    }
    inline auto posv( int matrix_order, char uplo, std::size_t n,
        std::size_t nrhs, double* a, std::size_t lda, double* b,
        std::size_t ldb, double* x, std::size_t ldx, lapack_int* iter ){
        return LAPACKE_dsposv( matrix_order, uplo, n, nrhs, a, lda, b, ldb,
            x, ldx, iter );
    }
    inline auto posv( int matrix_order, char uplo, std::size_t n,
        std::size_t nrhs, std::complex<double>* a, std::size_t lda,
        std::complex<double>* b, std::size_t ldb, std::complex<double>* x,
        std::size_t ldx, lapack_int* iter ){
        return LAPACKE_zcposv( matrix_order, uplo, n, nrhs, a, lda, b, ldb,
            x, ldx, iter );
    }
    

    template< typename T >
    auto gelsd( int matrix_order, std::size_t m, std::size_t n,
        std::size_t nrhs, T* a, std::size_t lda, T* b, std::size_t ldb,
        T* s, T rcond, lapack_int* rank );
    template<>
    inline auto gelsd<double>( int matrix_order, std::size_t m, std::size_t n,
        std::size_t nrhs, double* a, std::size_t lda, double* b,
        std::size_t ldb,double* s, double rcond, lapack_int* rank ){
        return LAPACKE_dgelsd( matrix_order, m, n, nrhs, a, lda, b, ldb,
            s, rcond, rank );
    }
    template<>
    inline auto gelsd<float>( int matrix_order, std::size_t m, std::size_t n,
        std::size_t nrhs, float* a, std::size_t lda, float* b,
        std::size_t ldb,float* s, float rcond, lapack_int* rank ){
        return LAPACKE_sgelsd( matrix_order, m, n, nrhs, a, lda, b, ldb,
            s, rcond, rank );
    }
    template<>
    inline auto gelsd<std::complex<double> >( int matrix_order, std::size_t m,
        std::size_t n, std::size_t nrhs, std::complex<double>* a,
        std::size_t lda, std::complex<double>* b, std::size_t ldb,
        std::complex<double>* s, std::complex<double> rcond, lapack_int* rank ){
        return LAPACKE_zgelsd( matrix_order, m, n, nrhs, a, lda, b, ldb,
            s, rcond, rank );
    }
    template<>
    inline auto gelsd<std::complex<float> >( int matrix_order, std::size_t m,
        std::size_t n, std::size_t nrhs, std::complex<float>* a,
        std::size_t lda, std::complex<float>* b, std::size_t ldb,
        std::complex<float>* s, std::complex<float> rcond, lapack_int* rank ){
        return LAPACKE_cgelsd( matrix_order, m, n, nrhs, a, lda, b, ldb,
            s, rcond, rank );
    }

} //namespace telepath

#endif
