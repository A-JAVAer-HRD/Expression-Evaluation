//
// Created by huangruidong on 2022/12/1.
//

#ifndef ALOGORITHM_QUESTION_H
#define ALOGORITHM_QUESTION_H

#include <string>

using namespace std;
/**
 * ������������
 */
class Question {
public:
    string  title;
    float result;

    Question(string title, float result){ //�вι���
        this->title = title;
        this->result = result;
    }

    Question(){ //�޲ι���
    }
};
#endif //ALOGORITHM_QUESTION_H
