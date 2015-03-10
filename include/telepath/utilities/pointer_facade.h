#ifndef INCLUDED_TELEPATH_UTILITIES_POINTER_FACADE_H
#define INCLUDED_TELEPATH_UTILITIES_POINTER_FACADE_H

namespace utils{

    template< typename T >
    class PointerFacade{
        T val_;
        public:
            PointerFacade( const T& val ) : val_( val ) { }
            PointerFacade( const T* val ) : val_( *val ) { }
            T* operator->() { return &val_; }
            const T* operator->() const { return &val_; }
            T& operator*() { return val_; }
            const T& operator*() const { return val_; }
    };

} //namespace utils

#endif
