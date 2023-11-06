/*
 * @file part-1.cc
 * @author Kara Nemet (kn485120@ohio.edu)
 * @brief 
 * @version 0.1
 * @date 2023-11-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <bits/stdc++.h> 
using namespace std;

int cutRod(int length){
        //{length, price}. access with prices[x][1]
                                //  0      1      2       3       4        5        6         7
    vector<vector<int>> prices = {{1,1}, {2,5}, {4,9}, {6,17}, {8,20}, {10,30}, {12, 36}, {16, 48}};

    vector<int> maxProfit(length + 1, 0);

    for(int i = 1; i <= length; i++){
        int localmax = INT_MIN;
        for(int j = 0; j < prices.size(); j++){
            if(prices[j][0] <= i){
                localmax = max(localmax, prices[j][1] + maxProfit[i - prices[j][0]]);
            }
        }
        maxProfit[i] = localmax;
    }
    return maxProfit[length];


}

int main (){


    vector<int> rodLengths = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    int localmax = INT_MIN;
    int maxProfit = 0;

        clock_t start, end;

    for(int i = 0; i < rodLengths.size(); i++){
        start = clock();
        maxProfit = cutRod(rodLengths[i]);
        end = clock();
        cout << "Max profit for " << rodLengths[i] << " = " << maxProfit << endl;
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
        cout << " sec " << endl;
    }
}
