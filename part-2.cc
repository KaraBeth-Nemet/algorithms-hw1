/**
 * @file part-2.cc
 * @author Kara Nemet (kn485120@ohio.edu)
 * @brief 
 * @version 0.1
 * @date 2023-11-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <bits/stdc++.h> 
#include <iomanip> 



using namespace std;

/**
 * @brief Get the number of ways an amount can be made with a given set of coins
 * 
 * @param amt 
 * @param coins 
 * @param numCoins 
 * @return long 
 */
long getNumWays(long amt, long coins[], long numCoins){

    long numWays[amt + 1];
    // set all values in numWays to 0
    for(int i = 0; i <= amt; i++){
        numWays[i] = 0;
    }
    // set the first value to 1
    numWays[0] = 1;

    // loop through the coins
    for(int i = 0; i < numCoins; i++){
        // loop through the numWays array
        for(int j = coins[i]; j <= amt; j++){
            // add the number of ways to get to the current amount - the current coin to the current amount
            numWays[j] += numWays[j - coins[i]];
        }
    }

    return numWays[amt];

}

/**
 * @brief print the combinations of the different ways to make an amount with a given set of coins
 * 
 * @param coins 
 * @param n 
 * @param amount 
 */
void getCoinCombinations(long coins[], int n, int amount) {
    
    vector<vector<vector<vector<int>>>> ways(amount + 1, vector<vector<vector<int>>>(n + 1));

    // Initialize the first column of the 2D array
    for (int i = 0; i <= n; ++i) {
        ways[0][i].push_back({});
    }

    for (int i = 1; i <= amount; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i - coins[j - 1] >= 0) {
                for (int k = 0; k < ways[i - coins[j - 1]][j].size(); ++k) {
                    vector<int> combination = ways[i - coins[j - 1]][j][k];
                    combination.push_back(coins[j - 1]);
                    ways[i][j].push_back(combination);
                }
            }

            if (j > 1) {
                for (int k = 0; k < ways[i][j - 1].size(); ++k) {
                    ways[i][j].push_back(ways[i][j - 1][k]);
                }
            }
        }
    }

     // Print the combinations
    for(int i = 0; i < ways[amount][n].size(); i++){
        for(int j = 0; j < ways[amount][n][i].size(); j++){
            std::cout << ways[amount][n][i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){

    clock_t start, end;
    long numWays;
    double time_taken;

    cout << endl << "Coin Change Problem : " << endl << endl;


    long coins[10] = {1, 5, 10, 25, 50, 100, 200, 500, 1000, 2000};
    long wizardCoins [3] = {1, 29, 493};
    long amounts[9] = {10, 50, 100, 500, 1000, 1500, 2000, 3000, 5000};

    cout << "Normal Coins : " << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << setw(10) << "Amount" << setw(20) << "Number of ways" << setw(30) << "Time taken by program" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for(int i = 0; i < 9; i++){
        start = clock();
        numWays = getNumWays(amounts[i], coins, 10);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << setw(10) << amounts[i] << setw(20) << numWays << setw(30) << fixed << setprecision(5) << time_taken << " sec" << endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
    cout << endl;

    cout << "Wizarding Coins : " << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << setw(10) << "Amount" << setw(20) << "Number of ways" << setw(30) << "Time taken by program" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for(int i = 0; i < 9; i++){
        start = clock();
        numWays = getNumWays(amounts[i], wizardCoins, 3);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << setw(10) << amounts[i] << setw(20) << numWays << setw(30) << fixed << setprecision(5) << time_taken << " sec" << endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
    cout << endl;

    long amtsToPrint[4] = {10, 25, 50, 100};
    
    for(int i = 0; i < 4; ++i){
        cout << "Amount: " << amtsToPrint[i] << endl;
        start = clock();
        getCoinCombinations(coins, 4, amtsToPrint[i]);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time take to run: " << setprecision(5) << time_taken << " sec" << endl;
    }
        cout << "-----------------------------------------------------------------------------------" << endl;

    for(int i = 0; i < 4; ++i){
        cout << "Amount: " << amtsToPrint[i] << endl;
        start = clock();
        getCoinCombinations(wizardCoins, 3, amtsToPrint[i]);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time take to run: " << setprecision(5) << time_taken << " sec" << endl;
    }
        cout << "-----------------------------------------------------------------------------------" << endl;

}