//
// Created by huangruidong on 2022/12/1.
//

#ifndef ALOGORITHM_CONTANTS_H
#define ALOGORITHM_CONTANTS_H
#include <string>
using namespace std;

//����
char ptr[10] = {'+', '-', '*', '/', '(', ')', '='};
// ���ʽ������ģ�� E�������� O���������(+,-,*,/)
string exStruct[] = {
        "(EOE)=",
        "(EO(EOE))=",
        "(EO(EOE))=",
        "((EOE)O(EOE))=",
        "((EOE)O(EOE))="
};
#endif //ALOGORITHM_CONTANTS_H
