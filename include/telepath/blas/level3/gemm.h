#ifndef INCLUDED_TELEPATH_BLAS_3_GEMM_H
#define INCLUDED_TELEPATH_BLAS_3_GEMM_H

#include <cblas.h>

namespace telepath{

    template< typename T >
    void gemm( CBLAS_ORDER order, CBLAS_TRANSPOSE transA,
        CBLAS_TRANSPOSE transB, std::size_t m std::size_t n, std::size_t k,
        T alpha, const T* A, std::size_t lda, const T* B, std::size_t ldb,
        T beta, T* C, std::size_t ldc );
    template<>
    void gemm<float>( CBLAS_ORDER order, CBLAS_TRANSPOSE transA,
        CBLAS_TRANSPOSE transB, std::size_t m, std::size_t n, std::size_t k,
        float alpha, const float* A, std::size_t lda, const float* B,
        std::size_t ldb, float beta, float* C, std::size_t ldc ){
        return cblas_sgemm( order, transA, transB, m, n, k, alpha, A, lda, B,
            ldb, beta, C, ldc );
    }
    template<>
    void gemm<double>( CBLAS_ORDER order, CBLAS_TRANSPOSE transA,
        CBLAS_TRANSPOSE transB, std::size_t m, std::size_t n, std::size_t k,
        double alpha, const double* A, std::size_t lda, const double* B,
        std::size_t ldb, double beta, double* C, std::size_t ldc ){
        return cblas_dgemm( order, transA, transB, m, n, k, alpha, A, lda, B,
            ldb, beta, C, ldc );
    }
    template<>
    void gemm<std::complex<float>>( CBLAS_ORDER order, CBLAS_TRANSPOSE transA,
        CBLAS_TRANSPOSE transB, std::size_t m, std::size_t n, std::size_t k,
        const std::complex<float>* alpha, const std::complex<float>* A,
        std::size_t lda, std::const complex<float>* B, std::size_t ldb,
        const std::complex<float>* beta, std::complex<float>* C,
        std::size_t ldc ){
        return cblas_cgemm( order, transA, transB, m, n, k, (float*) alpha,
            (float*) A, lda, (float*) B, ldb, (float*) beta, (float*) C, ldc );
    }
    template<>
    void gemm<std::complex<double>>( CBLAS_ORDER order, CBLAS_TRANSPOSE transA,
        CBLAS_TRANSPOSE transB, std::size_t m, std::size_t n, std::size_t k,
        const std::complex<double>* alpha, const std::complex<double>* A,
        std::size_t lda, const std::complex<double>* B, std::size_t ldb,
        const std::complex<double>* beta, std::complex<double>* C,
        std::size_t ldc ){
        return cblas_zgemm( order, transA, transB, m, n, k, (double*) alpha,
            (double*) A, lda, (double*) B, ldb, (double*) beta, (double*) C,
            ldc );
    }

} //namespace telepath

#endif

