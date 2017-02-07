#include <iostream>
#include "SherlockPermutations.h"


namespace SherlockPermutations {
//	-----------------------------------	---------------------------	-------------------------------	--------------------
	Solution::                          Solution					()                              {}
	Solution::~                         Solution					()                              {}
//	-----------------------------------	---------------------------	-------------------------------	--------------------
	int 
	Solution::                          main						()                              {
		std::cout << "hi, I'm Sherlok Permutations\n";
		return 0;
	}
//	-----------------------------------	---------------------------	-------------------------------	--------------------
	Solution::constructor::             constructor                 ()                              {
		SolutionBase::solutionFactory()["SherlockPermutations"] = new SherlockPermutations::Factory();
		std::cout << "SherlockPermutations constructor finished\n";
	}
//	-----------------------------------	---------------------------	-------------------------------	--------------------
	Solution::constructor               Solution::static_init;
//	-----------------------------------	---------------------------	-------------------------------	--------------------
};



