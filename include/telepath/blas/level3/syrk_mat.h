#ifndef INCLUDED_BLAS_L3_SYRK_MAT_H
#define INCLUDED_BLAS_L3_SYRK_MAT_H

#include "telepath/blas/level3/syrk.h"
#include "telepath/blas/detail.h"
#include <assert.h>

namespace blas{

    namespace syrk_detail{

        template< typename T, typename U, typename V >
        inline void syrk_impl( T alpha, U&& A, T beta,
            V&& C ){
            
            //using namespace matrix;
            assert( layout( A ) == layout( C ) );
            assert( nrows(C) == ncols(C) );
            assert( ld(C) >= nrows(C) );
            assert( uplo(C) == CblasUpper || uplo(C) == CblasLower );
            if( trans(A) == CblasNoTrans ){
                assert( nrows(A) == nrows(C) );
                assert( ld(A) >= nrows(A) );
            }else{
                assert( ncols(A) == nrows(C) );
                assert( ld(A) >= ncols(A) );
            }

            syrk( 
                (CBLAS_ORDER) layout( A ),
                (CBLAS_UPLO) uplo( C ),
                (CBLAS_TRANSPOSE) trans( A ),
                nrows( C ),
                trans( A ) == CblasNoTrans ? ncols( A ) : nrows( A ),
                alpha,
                array( A ),
                ld( A ),
                beta,
                array( C ),
                ld( C )
            );
        }

    } //namespace syrk_detail
    
    template< typename T, typename U, typename V >
    inline void syrk( T alpha, const U& A, T beta, V& C ){
        syrk_detail::syrk_impl( alpha, blas_cast(A), beta, blas_cast(C) );
    }

    template< typename T, typename U, typename V >
    inline void syrk( T alpha, const U& A, V& C ){
        return syrk( alpha, A, T(1), C );
    }
    
    template< typename T, typename U, typename V >
    inline void syrk( const U& A, T beta, V& C ){
        return syrk( T(1), A, beta, C );
    }
    
    template< typename U, typename V >
    inline void syrk( const U& A, V& C ){
        return syrk( 1.0, A, 1.0, C );
    }

} //namespace blas

#endif
