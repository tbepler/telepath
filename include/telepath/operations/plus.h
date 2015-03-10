#ifndef INCLUDED_TELEPATH_OPERATIONS_PLUS_H
#define INCLUDED_TELEPATH_OPERATIONS_PLUS_H

namespace telepath{

    //assigns V = T + U
    template< typename T, typename U, typename V >
    struct Plus{
        inline V& operator()( const T& t, const U& u, V& v ) const{
            return v = t + u;
        }
    };

} //namespace telepath

#endif
