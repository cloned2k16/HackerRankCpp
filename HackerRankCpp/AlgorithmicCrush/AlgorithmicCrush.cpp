#include <iostream>
#include <vector>

#include "AlgorithmicCrush.h"

namespace AlgorithmicCrush {
//  ----------------------------------- --------------------------- ------------------------------- --------------------
    Solution::                          Solution                    ()                              {}
    Solution::~                         Solution                    ()                              {}
//  ----------------------------------- --------------------------- ------------------------------- --------------------
//   3 <= N <= 1e7
//   1 <= M <= 1*1e5
//   1 <= a <= b <= N
//   0 <= k <= 1e9
    int
        Solution::                      main                        ()                              {
            int N,M;
            std::cin >> N;
            std::cin >> M;
            long long * mtx    = new long long [N+1];
            for (int n=0; n<=N; n++) mtx[n]=0;

            for (int i = 0; i < M; i++) {
                int     a,b;
                long long  k;
                std::cin >> a;
                std::cin >> b;
                std::cin >> k;
                        
                mtx[a]     += k;
                mtx[b + 1] -= k;
            }

            long long max = mtx[0];
            for (int i = 1; i <= N; i++) {
                long long v = mtx[i - 1] + mtx[i];
                mtx[i] = v;
                if (v>max) max = v;
            }

            std::cout << max << std::endl;

            // using double  was much tooo slow!
            //std::cout.precision(0);
            //std::cout << std::fixed << max << std::endl;
            return 0;
    }
//  ----------------------------------- --------------------------- ------------------------------- --------------------
    Solution::constructor::             constructor                 ()                              {
        SolutionBase::solutionFactory()["AlgorithmicCrush"] = new AlgorithmicCrush::Factory();
        std::cout << "AlgorithmicCrush constructor finished\n";
    }
    //  ----------------------------------- --------------------------- ------------------------------- --------------------
    Solution::constructor               Solution::static_init;
    //  ----------------------------------- --------------------------- ------------------------------- --------------------
};