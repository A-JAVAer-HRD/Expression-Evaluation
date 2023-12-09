//
// Created by huangruidong on 2023/1/12.
//
#include "Calculate.h"

void testRand() {
    N = 100;
    int n = 10;
    int a[n];
    selectQuestion(10, a);
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << endl;
    }
}
int main() {
    testRand();
    return 0;
}