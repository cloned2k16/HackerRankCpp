// HackerRankCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>

#include "SolutionBase.h"
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    struct                              _INIT                       {
	                                    _INIT                       ()                              {
		    std::cout << "_INIT finished\n";
	    }
    };
    _INIT                               static_init;
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    int                                 test                        (char * name, int cases [])     {
	    IFactory* factory = SolutionBase::solutionFactory()[name];
	    if (factory != NULL) {
		    SolutionBase* sol = factory->create();
		    sol->main();
	    }
	    else {
		    std::cout << "sorry can't find class\n";
	    }
	    return 0;
    }
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    int                                 main                        (char argc, char argv [])       {
	    std::cout << "here we go\n";
        
        int cases[] = { 0,3 };
        test("SherlockPairs"            ,cases);

        //int cases[] = {   7 };
        //test("SherlockPermutations"     ,cases);

        _getch();
    	return 0;
    }   
//	-----------------------------------	---------------------------	-------------------------------	--------------------

