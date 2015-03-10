#ifndef INCLUDED_TELEPATH_VECTOR_FOLD_H
#define INCLUDED_TELEPATH_VECTOR_FOLD_H

#include "telepath/vector/vector.h"
#include "telepath/operations/fold.h"

namespace telepath{
    
    template< typename F, typename T >
    inline auto fold( F&& f, const vector<T>& vec, T init = T() ){
        T* pos = vec.array;
        T* end = vec.array + vec.length*vec.inc;
        for( ; pos < end ; pos += vec.inc ){
            x = f( x, *pos );
        }
        return x;
    }

} //namespace telepath

#endif
