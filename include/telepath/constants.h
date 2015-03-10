#ifndef INCLUDED_TELEPATH_CONSTANTS_H
#define INCLUDED_TELEPATH_CONSTANTS_H

#include <cstdlib>

namespace telepath{

    using dim_t = std::size_t;

    enum DIM {
        ELEM_SPACE = 0,
        ROW_SPACE = 1,
        COL_SPACE = 2,
        DYNAMIC = -1
    };

} //namespace telepath

#endif
