#ifndef INCLUDED_TELEPATH_VECTOR_NUMEL_H
#define INCLUDED_TELEPATH_VECTOR_NUMEL_H

#include "telepath/operations/numel.h"
#include "telepath/vector/vector.h"

namespace telepath{

    template< typename T >
    struct Numel< vector<T> >{
        inline std::size_t operator()( const vector<T>& vec ) const{
            return vec.length;
        }
    };

} //namespace telepath

#endif
