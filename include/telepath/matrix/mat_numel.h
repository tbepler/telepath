#ifndef INCLUDED_TELEPATH_MATRIX_NUMEL_H
#define INCLUDED_TELEPATH_MATRIX_NUMEL_H

#include "telepath/operations/numel.h"
#include "telepath/matrix/matrix.h"

namespace telepath{

    template< typename T >
    struct Numel< matrix<T> >{
        inline std::size_t operator()( const matrix<T>& mat ) const{
            return mat.rows * mat.cols;
        }
    };

} //namespace telepath

#endif
