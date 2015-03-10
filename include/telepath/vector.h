#ifndef INCLUDED_TELEPATH_VECTOR_H
#define INCLUDED_TELEPATH_VECTOR_H

namespace telepath{

    /*
    POD struct for storing BLAS vector data
    */
    template< typename T >
    struct vector{

        T* array;
        std::size_t length;
        std::size_t inc;

        constexpr bool operator==( const vector& rhs ){
            return array == rhs.array && length == rhs.length && inc == rhs.inc;
        }
        constexpr bool operator!=( const vector& rhs ){
            return !this->operator==( rhs );
        }

    };
    
} //namespace telepath

#endif
