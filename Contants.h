//
// Created by huangruidong on 2022/12/1.
//

#ifndef ALOGORITHM_CONTANTS_H
#define ALOGORITHM_CONTANTS_H
#include <string>
using namespace std;

//符号
char ptr[10] = {'+', '-', '*', '/', '(', ')', '='};
// 表达式的生成模板 E换成数字 O换成运算符(+,-,*,/)
string exStruct[] = {
        "(EOE)=",
        "(EO(EOE))=",
        "(EO(EOE))=",
        "((EOE)O(EOE))=",
        "((EOE)O(EOE))="
};
#endif //ALOGORITHM_CONTANTS_H
