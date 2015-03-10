#ifndef INCLUDED_TELEPATH_REGRESSION_RIDGE_H
#define INCLUDED_TELEPATH_REGRESSION_RIDGE_H

namespace telepath{

    template< typename T >
    T ridge( const Matrix<T>& X, const Vector<T>& y, T lambda,
        bool centered = false ){
        
        if( !centered ){
            //center X and Y and store their column means
            //call ridge with centered X and Y
            //find bias by y_h - w*x_h
            //restore X and Y by adding back column means
            //return
        }
        //A = X'X + lambdaI
        //b = X'y
        //w = solve( A, b )

    }

} //namespace telepath

#endif
