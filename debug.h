#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define ARRAY_SIZE 100

// TODO: auto change size based on params
inline void dumpGraph(int graph[][ARRAY_SIZE], int r, int c) {
#ifdef XDebug    
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif
}

template<typename T>
inline void dumpArray(T *dp, int r) {
#ifdef XDebug   
    for(int i = 0; i < r; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
#endif
}

#endif