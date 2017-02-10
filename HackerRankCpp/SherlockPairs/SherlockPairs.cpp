#include <iostream>
#include <vector>
#include <algorithm>
#include "SherlockPairs.h"


namespace SherlockPairs{
//	-----------------------------------	---------------------------	-------------------------------	--------------------
	Solution::                          Solution					()                              {}
	Solution::~                         Solution					()                              {}
//	-----------------------------------	---------------------------	-------------------------------	--------------------
//  Costrains
//      1 <= nt   <= 10
//      1 <= N    <= 1e5
//      1 <= A[i] <= 1e6
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    long long                           getPairs                    (std::vector <int> a)           {
        long long sum = 0;
        int  len = a.size();
        for (int i = 1; i < len; i++) {
            long long c = 1;
            long p = a[i - 1], p1;
            while (i < len && (p1 = a[i]) == p) {
                c++;
                p = p1;
                i++;
            }
            sum += (c * (c - 1));
        }
        return sum;
    }
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    int
	Solution::                          main						()                              {
        int nt;
        std::cin >> nt;
        for (int tn = 0; tn < nt; tn++) {
            int N;
            std::vector <int> A;    
            std::cin >> N;
            for (int i = 0; i < N; i++) {
                int n;
                std::cin >> n;
                A.push_back(n);
            }
            
            std::sort(A.begin(),A.end());
            long long r = getPairs(A);
            std::cout << r << std::endl;
        }

		return 0;
	}
//	-----------------------------------	---------------------------	-------------------------------	--------------------
	Solution::constructor::             constructor                 ()                              {
		SolutionBase::solutionFactory()["SherlockPairs"] = new SherlockPairs::Factory();
		std::cout << "SherlockPairs constructor finished\n";
	}
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    Solution::constructor               Solution::static_init;
//	-----------------------------------	---------------------------	-------------------------------	--------------------
};


