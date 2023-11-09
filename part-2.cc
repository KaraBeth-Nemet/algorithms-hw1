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

long getNumWays(long amt, long coins[], long numCoins){

    long numWays[amt + 1];
    for(int i = 0; i <= amt; i++){
        numWays[i] = 0;
    }
    numWays[0] = 1;

    for(int i = 0; i < numCoins; i++){
        for(int j = coins[i]; j <= amt; j++){
            numWays[j] += numWays[j - coins[i]];
        }
    }

    return numWays[amt];

}

// long getNumWays(long amt, long coins[], long numCoins){

//     long numWays[amt + 1];
//     for(int i = 0; i <= amt; i++){
//         numWays[i] = 0;
//     }
//     numWays[0] = 1;

//     for(int i = 0; i < numCoins; i++){
//         for(int j = coins[i]; j <= amt; j++){
//             numWays[j] += numWays[j - coins[i]];

//         }
//     }

//     return numWays[amt];

// }


int main(){

    clock_t start, end;
    long numWays;
    double time_taken;


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
}