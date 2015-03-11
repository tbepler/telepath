#ifndef INCLUDED_BLAS_L3_SYRK_H
#define INCLUDED_BLAS_L3_SYRK_H

#include <complex>
#include <cblas.h>

namespace blas{
    
    void syrk( CBLAS_ORDER order, CBLAS_UPLO uplo, CBLAS_TRANSPOSE trans,
        std::size_t n, std::size_t k, float alpha, const float* A,
        std::size_t lda, float beta, float* C, std::size_t ldc ){
        return cblas_ssyrk( order, uplo, trans, n, k, alpha, A, lda, beta, C,
            ldc );
    }
    void syrk( CBLAS_ORDER order, CBLAS_UPLO uplo,
        CBLAS_TRANSPOSE trans, std::size_t n, std::size_t k, double alpha,
        const double* A, std::size_t lda, double beta, double* C,
        std::size_t ldc ){
        return cblas_dsyrk( order, uplo, trans, n, k, alpha, A, lda, beta, C,
            ldc );
    }
    void syrk( CBLAS_ORDER order, CBLAS_UPLO uplo, CBLAS_TRANSPOSE trans,
        std::size_t n, std::size_t k, const std::complex<float>* alpha,
        const std::complex<float>* A, std::size_t lda,
        const std::complex<float>* beta, std::complex<float>* C,
        std::size_t ldc ){
        return cblas_csyrk( order, uplo, trans, n, k, (float*) alpha,
            (float*) A, lda, (float*) beta, (float*) C, ldc );
    }
    void syrk( CBLAS_ORDER order, CBLAS_UPLO uplo, CBLAS_TRANSPOSE trans,
        std::size_t n, std::size_t k, const std::complex<double>* alpha,
        const std::complex<double>* A, std::size_t lda,
        const std::complex<double>* beta, std::complex<double>* C,
        std::size_t ldc ){
        return cblas_zsyrk( order, uplo, trans, n, k, (double*) alpha,
            (double*) A, lda, (double*) beta, (double*) C, ldc );
    }

} //namespace blas

#endif
