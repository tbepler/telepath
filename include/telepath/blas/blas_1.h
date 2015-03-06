#ifndef INCLUDED_TELEPATH_BLAS_1_H
#define INCLUDED_TELEPATH_BLAS_1_H

#include <complex>
#include <cblas.h>

namespace telepath{

    template< typename T >
    inline auto asum( std::size_t n, const T* x, std::size_t incX = 1 );

    template<> inline auto asum<double>( std::size_t n, const double* x,
        std::size_t incX ){ return cblas_dasum( n, x, incX ); }
    template<> inline auto asum<float>( std::size_t n, const float* x,
        std::size_t incX ){ return cblas_sasum( n, x, incX ); }
    template<> inline auto asum<std::complex<double> >( std::size_t n,
        const std::complex<double>* x, std::size_t incX ){
        return cblas_dzasum( n, (const double*) x, incX ); }
    template<> inline auto asum<std::complex<float> >( std::size_t n,
        const std::complex<float>* x, std::size_t incX ){
        return cblas_scasum( n, (const float*) x, incX ); }

} //namespace tblas

#endif
