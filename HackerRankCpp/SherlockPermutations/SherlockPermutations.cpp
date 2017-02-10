#include <iostream>
#include <vector>
#include "SherlockPermutations.h"


namespace SherlockPermutations {
//	-----------------------------------	---------------------------	-------------------------------	--------------------
	Solution::                          Solution					()                              {}
	Solution::~                         Solution					()                              {}
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    std::vector <int>   cache_data      { 1,1,2 };                                                  //  initialization must contain at least 1 value (0)!
    int                 cache_size      = 1024;                                                     //  no big deal in space terms!
    int                 modulo          = (int)  1e9 + 7;    
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    struct                              _INIT {
        _INIT() {
            int  len    = cache_size;
            for (int i = len; i<cache_size; i++) {
                cache_data.push_back( (int)(((long)cache_data[i - 1] * i) % modulo));
            }
        }
    };
    _INIT                               static_init;
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    int                                 modInverse                  (int a, int n)                  {
       int i = n, v = 0, d = 1;
        while (a>0) {
            int t = i / a, x = a;
            a = i % x;
            i = x;
            x = d;
            d = v - t*x;
            v = x;
        };
        v %= n;
        if (v<0) v = (int)((long)(v + n) % n);
        return v;
    }
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    int                                 fact_mod                    (int n)                         {
        int len = cache_data.size();

        if (n < len) return cache_data[n];
        else {
            int r = cache_data[len - 1];
            for (int i = len; i <= n; i++) {
                r = (int)(((long long)r * i) % modulo);
            }
            return r;
        }
    }
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    int
	Solution::                          main						()                              {
        int nT;
        std::cin >> nT;
        for (int tn = 0; tn < nT; tn++) {
            int n ,m;
            std::cin >> n;
            std::cin >> m;
            int r, A = 0, iB = 0;
            if (m == 1) r = 1;
            else {
                m -= 1;
                A = fact_mod(n + m);
                iB = modInverse((int)(((long long)fact_mod(n) * fact_mod(m)) % modulo), modulo);
                r = (int)(((long long)A * iB) % modulo);
            }
            std::cout << r << std::endl;
        }
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



