#ifndef INCLUDED_TELEPATH_MATRIX_H
#define INCLUDED_TELEPATH_MATRIX_H

namespace telepath{

    enum StorageOrder { ROW_MAJOR, COL_MAJOR };
    
    template< typename M >
    struct matrix_traits{
        /*
        static constexpr bool is_contiguous();
        static constexpr StorageOrder storage_order();
        using scalar_t;
        */
        static constexpr bool is_contiguous(){ return M::is_contiguous(); }
        static constexpr StorageOrder storage_order(){
            return M::storage_order(); }
        using scalar = M::scalar;
    };

    template< typename M >
    constexpr StorageOrder storage_order( const M& m ){
        return matrix_traits<M>::storage_order();
    }

    template< typename M >
    constexpr bool is_contiguous( const M& m ){
        return matrix_traits<M>::is_contiguous();
    }



    template< typename M > auto* c_array( M& m ) -> decltype( m.c_array() ){
        return m.c_array();
    }
    template< typename M > const auto* c_array( const M& m )
        -> decltype( m.c_array() ){
        return m.c_array();
    }

    template< typename M > auto rows( const M& m )
        -> decltype( m.rows() ){
        return m.rows();
    }

    template< typename M > auto cols( const M& m )
        -> decltype( m.cols() ){
        return m.cols();
    }

    template< typename M > auto offset( const M& m )
        -> decltype( m.offset() ){
        return m.offset();
    }

    template< typename M > inline auto numel( const M& m )
        -> decltype( rows( m ) * cols( m ) )
    {
        return rows( m ) * cols( m );
    }

    template< typename M, typename I, typename J >
    inline auto& index( M& m, I&& i, J&& j )
        -> decltype( m( std::forward<I>(i),std::forward<J>(j) ) ) {
        return m( std::forward<I>(i),std::forward<J>(j) );
    }
    
    template< typename M, typename I, typename J >
    inline const auto& index( const M& m, I&& i, J&& j )
        -> decltype( m( std::forward<I>(i),std::forward<J>(j) ) ) {
        return m( std::forward<I>(i),std::forward<J>(j) );
    }

    template< typename Scalar >
    struct matrix{

        static constexpr bool is_contiguous(){ return true; }
        static constexpr StorageOrder storage_order(){ return COL_MAJOR; }
        using scalar = Scalar;

        std::vector<scalar> data_;
        std::size_t m_;
        std::size_t n_;
        std::size_t offset_;

        inline scalar* c_array(){ return &data_[0]; }
        inline const scalar* c_array() const{ return &data_[0]; }
        constexpr std::size_t rows() const{ return m_; }
        constexpr std::size_t cols() const{ return n_; }
        constexpr std::size_t offset() const{ return offset_; }
        inline scalar& operator()( std::size_t i, std::size_t j ){
            return 
        }

    };



} //namespace telepath

#endif
