#ifndef INCLUDED_TELEPATH_MATRIX_ROWS_H
#define INCLUDED_TELEPATH_MATRIX_ROWS_H

#include "telepath/operations/rows.h"
#include "telepath/operations/index.h"
#include "telepath/operations/fold.h"
#include "telepath/matrix.h"
#include "telepath/vector.h"

namespace telepath{

    //define row view of matrix
    //need to specialize index, map, fold
    template< typename T, TRANSPOSE t >
    struct row_view{
        matrix<T,t> mat;
    };

    template< typename T, TRANSPOSE t >
    struct Rows< matrix<T,t> >{
        using mat = matrix<T,t>;
        constexpr auto operator()( const mat& m ){
            return row_view<T,t>{ m.array, m.rows, m.cols, m.ld };
        }
    };

    template< typename T >
    struct NumRows< row_view<T,NONE> >{
        inline auto operator()( const row_view<T,NONE>& rv ) const{
            return rv.mat.rows;
        }
    };

    template< typename T >
    struct NumRows< row_view<T,TRANS> >{
        inline auto operator()( const row_view<T,TRANS>& rv ) const{
            return rv.mat.cols;
        }
    };

    template< typename T >
    struct Index< row_view<T,NONE> >{
        using rview = row_view<T,NONE>;
        inline auto operator()( const rview& rv, std::size_t i ) const{
            return vector<T>{ rv.mat.array + i, rv.mat.cols,
                rv.mat.rows + rv.mat.ld };
        }
        inline auto operator()( const rview& rv, const range& r ) const{
            return rview{ { 
                rv.mat.array + r.begin,
                r.end - r.begin,
                rv.mat.cols,
                rv.mat.ld + rv.mat.rows - r.end + r.begin
            } };
        }
        inline auto operator()( const rview& rv, all a ) const{
            return rv;
        }
    };

    template< typename T >
    struct Index< row_view<T,TRANS> >{
        using rview = row_view<T,TRANS>;
        inline auto operator()( const rview& rv, std::size_t i ) const{
            return vector<T>{ rv.mat.array + i*( rv.mat.rows + rv.mat.ld ),
                rv.mat.rows, 1 };
        }
        inline auto operator()( const rview& rv, const range& r ) const{
            return rview{ {
                rv.mat.array + r.begin*( rv.mat.rows + rv.mat.ld ),
                rv.mat.rows,
                r.end - r.begin,
                rv.mat.ld
            } };
        }
        inline auto operator()( const rview& rv, all a ) const{
            return rv;
        }
    };

    template< typename T, TRANSPOSE t >
    struct Fold< row_view<T,t> >{
        using rview = row_view<T,t>;
        template< typename F, typename U >
        inline auto operator()( F&& f, const rview& rv, U init ){
            for( std::size_t i = 0 ; i < numrows( rv ) ; ++i ){
                init = f( init, index( rv, i ) );
            }
            return init;
        }
    };

} //namespace telepath

#endif
