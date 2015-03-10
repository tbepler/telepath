#ifndef INCLUDED_TELEPATH_TRAITS_POD_COMPLIANT_H
#define INCLUDED_TELEPATH_TRAITS_POD_COMPLIANT_H

namespace telepath{

    template< typename T >
    struct pod_compliant_trait{
        constexpr bool value = false;
    };

    template< typename T >
    constexpr bool pod_compliant(){ return pod_compliant_trait<T>::value; }

} //namespace telepath

#endif
