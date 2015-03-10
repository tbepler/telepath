#ifndef INCLUDED_TELEPATH_BLAS_2_GEMV_H
#define INCLUDED_TELEPATH_BLAS_2_GEMV_H

#include <cblas.h>
#include <complex>

namespace telepath{

    template< typename T >
    void gemv( CBLAS_ORDER order, CBLAS_TRANSPOSE trans, std::size_t m,
        std::size_t n, T alpha, const T* a, std::size_t lda, const T* x,
        std::size_t incx, T beta, T* y, std::size_t incy );
    template< typename T >
    void gemv( CBLAS_ORDER order, CBLAS_TRANSPOSE trans, std::size_t m,
        std::size_t n, const T* alpha, const T* a, std::size_t lda, const T* x,
        std::size_t incx, const T* beta, T* y, std::size_t incy );

    template<>
    void gemv<float>( CBLAS_ORDER order, CBLAS_TRANSPOSE trans, std::size_t m,
        std::size_t n, float alpha, const float* a, std::size_t lda,
        const float* x, std::size_t incx, float beta, float* y,
        std::size_t incy ){
        return cblas_sgemv( order, trans, m, n, alpha, a, lda, x, incx, beta,
            y, incy );
    }
    
    template<>
    void gemv<double>( CBLAS_ORDER order, CBLAS_TRANSPOSE trans,
        std::size_t m, std::size_t n, double alpha, const double* a,
        std::size_t lda, const double* x, std::size_t incx, double beta,
        double* y, std::size_t incy ){
        return cblas_dgemv( order, trans, m, n, alpha, a, lda, x, incx, beta,
            y, incy );
    }
    
    template<>
    void gemv<std::complex<float> >( CBLAS_ORDER order, CBLAS_TRANSPOSE trans,
        std::size_t m, std::size_t n, const std::complex<float>* alpha,
        const std::complex<float>* a, std::size_t lda,
        const std::complex<float>* x, std::size_t incx,
        const std::complex<float>* beta, std::complex<float>* y,
        std::size_t incy ){
        return cblas_cgemv( order, trans, m, n, (float*) alpha, (float*) a, lda,
            (float*) x, incx, (float*) beta, (float*) y, incy );
    }
    
    template<>
    void gemv<std::complex<double> >( CBLAS_ORDER order,
        CBLAS_TRANSPOSE trans, std::size_t m, std::size_t n,
        const std::complex<double>* alpha, const std::complex<double>* a,
        std::size_t lda, const std::complex<double>* x, std::size_t incx,
        const std::complex<double>* beta, std::complex<double>* y,
        std::size_t incy ){
        return cblas_zgemv( order, trans, m, n, (double*) alpha, (double*) a,
            lda, (double*) x, incx, (double*) beta, (double*) y, incy );
    }

} //namespace telepath

#endif
