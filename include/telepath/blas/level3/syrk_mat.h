#ifndef INCLUDED_TELEPATH_BLAS_3_SYRK_MAT_H
#define INCLUDED_TELEPATH_BLAS_3_SYRK_MAT_H

#include "telepath/blas/level3/syrk.h"
#include <assert.h>

namespace telepath{
    
    template< typename T, typename Mat, typename SymMat >
    void syrk( T alpha, const Mat& A, T beta, SymMat& C ){
        
        assert( layout(A) == layout(C) );
        assert( nrows(C) == ncols(C) );
        assert( uplo(C) == CblasUpper || uplo(C) == CblasLower );
        if( getTrans(A) == CblasNoTrans ){
            assert( nrows(A) == nrows(C) );
        }else{
            assert( ncols(A) == nrows(C) );
        }

        syrk( (CBLAS_ORDER) layout(A), (CBLAS_UPLO) uplo(C),
            (CBLAS_TRANSPOSE) getTrans(A), nrows(A), ncols(A), alpha,
            array(A), ldInc(A), beta, array(C), ldInc(C) );

    }

} //namespace telepath

#endif
