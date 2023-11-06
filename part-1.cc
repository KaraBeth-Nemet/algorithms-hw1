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
using namespace std;


int main (){
    //{length, price}. access with prices[x][1]
    vector<vector<int>> prices = {{1,1}, {2,5}, {4,9}, {6,17}, {8,20}, {10,30}, {12, 36}, {16, 48}};
    //                              0      1      2       3       4        5        6         7
    vector<int> cost, bestCut = {0};

    cout << "did this work?     " << prices[3][1] << endl ;
    int numOfPrices = prices.size() - 1;
    cout << numOfPrices << endl;
    int i, j , localmax = 0;

    for(i; i < numOfPrices; ++i){
        cout << "get here?";
        localmax = INT_MIN;
        for(j; j < i; ++j){
            cout << "localmax < prices[i][0] + cost[i - j]" << localmax << prices[i][0] + cost[i - j] << endl;
            if (localmax < prices[i][0] + cost[i - j]){
                 localmax = prices[i][0] + cost[i - j];
                 bestCut[i] = i;
            }
        }
        cost[i] = localmax;
    }


}