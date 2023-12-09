//
// Created by huangruidong on 2022/12/1.
//

#ifndef ALOGORITHM_QUESTION_H
#define ALOGORITHM_QUESTION_H

#include <string>

using namespace std;
/**
 * 试题数据类型
 */
class Question {
public:
    string  title;
    float result;

    Question(string title, float result){ //有参构造
        this->title = title;
        this->result = result;
    }

    Question(){ //无参构造
    }
};
#endif //ALOGORITHM_QUESTION_H
