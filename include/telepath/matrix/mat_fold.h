#ifndef INCLUDED_TELEPATH_MATRIX_FOLD_H
#define INCLUDED_TELEPATH_MATRIX_FOLD_H

#include "telepath/matrix/matrix.h"
#include "telepath/operations/fold.h"
#include "telepath/vector/vector.h"

namespace telepath{

    namespace detail{

        template< typename F, typename T >
        inline auto fold_cols( F&& f, const matrix<T>& mat, 
    
    } //namespace detail

    template< typename T, ORDER o, dim_t dim >
    struct Fold< matrix<T,o>, dim >{
        //by default, call with the whole matrix
        template< typename F, typename U >
        inline auto operator()( F&& f, const matrix<T,o>& mat,
            U init = U() ) const{
            return f( init, mat );
        }
    };

    template< typename T >
    struct Fold< matrix<T,ROW_MAJOR>, ELEM_SPACE >{
        //fold over the elements with the major ordering in the inner loop
        template< typename F, typename U >
        inline auto operator()( F&& f, const matrix<T,ROW_MAJOR>& mat,
            U x = U() ) const{
            
            T* pos = mat.array;
            T* end = pos + (mat.cols+mat.ld)*mat.rows;
            for( ; pos < end ; pos += mat.ld ){
                T* rows_end = pos + mat.cols;
                for( ; pos < row_end ; ++pos ){
                    x = f( x, *pos );
                }
            }
            return x;
        }
    };

    template< typename T >
    struct Fold< matrix<T,ROW_MAJOR>, ROW_SPACE >{
        template< typename F, typename U >
        inline auto operator()( F&& f, const matrix<T,ROW_MAJOR>& mat,
            U x = U() ) const{

            
        }
    };
    
    template< typename T >
    struct Fold< matrix<T,COL_MAJOR>, ELEM_SPACE >{
        //fold over the elements with the major ordering in the inner loop
        template< typename F, typename U >
        inline auto operator()( F&& f, const matrix<T,COL_MAJOR>& mat,
            U x = U() ) const{
            
            T* pos = mat.array;
            T* end = pos + (mat.rows+mat.ld)*mat.cols;
            for( ; pos < end ; pos += mat.ld ){
                T* col_end = pos + mat.rows;
                for( ; pos < col_end ; ++pos ){
                    x = f( x, *pos );
                }
            }
            return x;
        }
    };

    template< typename F, typename T >
    inline auto fold( std::size_t dim, F&& f, const matrix<T>& mat,
        T init = T() ){

    }

} //namespace telepath

#endif
