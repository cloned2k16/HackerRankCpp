#pragma once

#include "../SolutionBase.h"

namespace AlgorithmicCrush {
    //  ----------------------------------- --------------------------- ------------------------------- --------------------
    class                               Solution
        : public                        SolutionBase {
    public:
                                        Solution                        ();
        ~                               Solution                        ();

        int                             main                            ();


        struct                          constructor {
                                        constructor();
        };
        static constructor              static_init;

    };
    //  ----------------------------------- --------------------------- ------------------------------- --------------------
    class                               Factory
        : public                        IFactory {
    public:
        SolutionBase*               create() { return new Solution(); }
    };
    //  ----------------------------------- --------------------------- ------------------------------- --------------------
};


