#include <iostream>
#include "SolutionBase.h"

//	-----------------------------------	---------------------------	-------------------------------	--------------------
    SolutionBase::						SolutionBase				()                              {}
    SolutionBase::~						SolutionBase				()                              {}

    int
    SolutionBase::						main					    ()                              { return -1;  }

    SolutionBase::static_constructor::  static_constructor          ()                              {
        int sz = SolutionBase::solutionFactory().size();
        std::cout << "we got " << sz << " classes in dictionary\n";
        std::cout << "SolutionBase constructor finished\n";
    }

    SolutionBase::static_constructor    SolutionBase::static_init;
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    SolutionBase*
    IFactory::							create						() { 
        std::cout << "sorry I'm an abstract class\n";  
        return NULL; 
    }
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    SolutionFactory&
    SolutionBase::      	            solutionFactory             ()                              {
        static SolutionFactory solutionFactory;
        return  solutionFactory;
    }
//	-----------------------------------	---------------------------	-------------------------------	--------------------


