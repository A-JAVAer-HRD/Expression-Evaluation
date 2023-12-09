//
// Created by huangruidong on 2022/12/1.
//

#ifndef ALOGORITHM_CALCULATE_H
#define ALOGORITHM_CALCULATE_H
//此程序所有文件均保存在了 D 盘根目录下，实际调试运行时，可根据实际情况更改存储路径
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include "Stack.h"
#include "Question.h"
#include "Contants.h"
using namespace std;


int N;	//定义全局变量，表示试题库试题数量
Stack<float> numStack;//数字栈
Stack<char> operatorStack;//运算符栈
string scoreFile;
string averageFile;

/**
 * 建立试题库\n
 * 在D盘shitiku.txt文件中随机的创建表达式\n
 * 创建表达式时，如果分子是0的话重新随机一个不为0的数字
 * */
int creatQuestion() { //建立试题库
    ofstream outfile;    // 定义写文件流
    // 打开文件
    outfile.open("D:\\shitiku.txt", ios::out | ios::app);
    if (!outfile.is_open()) {    // 判断文件是否打开失败
        cout << "无法建立试题库文件！" << endl;
        return 0;
    }
    cout << "输入要建立的试题库的试题数目: " << endl;
    cin >> N;
    outfile << N << endl;
    srand(time(nullptr));
    int i;
    for (i = 0; i < N; i++) {
        Question t;
        string s;
        int i = rand() % 5; // 随机表达式的结构(模板)
        char lastChar = ' '; // 上一个符号
        s = exStruct[i]; // 按照结构进行构造
        for (i = 0; i < s.size(); i++) {
            if (s[i] == 'O') {
                int j = rand() % 4;
                s[i] = ptr[j]; // 替换为O字符为运算符(+-*/)任意符号
                lastChar = s[i];
            }
            if (s[i] == 'E') {
                int j = rand() % 10; // 替换E字符为数字
                while (lastChar == '/' && j == 0) { // 防止分母为0
                    j = rand() % 10;
                }
                s[i] = j + '0';
            }
        }
        t.title = s;
        outfile << t.title << endl;    //将键盘输入的表达式写进文件
    }
    outfile.close();
    return 1;
}


/**
 * 判断运算符优先级
 * @param a 栈顶的字符
 * @param b 遍历到的当前字符
 * @return  优先级的符号 > < =
 *          > 表示栈顶运算符的优先级 大于 当前运算符的优先级
 *          < 表示栈顶运算符的优先级 小于 当前运算符的优先级
 *          = 表示栈顶运算符的优先级 等于 当前运算符的优先级
 */
char getPrecede(char a,char b) {
    int i, j;
    // 优先级表格 行是栈顶运算符 列是当前运算符
    char Table[8][8] = {{' ', '+', '-', '*', '/', '(', ')', '='},
                        {'+', '>', '>', '<', '<', '<', '>', '>'},
                        {'-', '>', '>', '<', '<', '<', '>', '>'},
                        {'*', '>', '>', '>', '>', '<', '>', '>'},
                        {'/', '>', '>', '>', '>', '<', '>', '>'},
                        {'(', '<', '<', '<', '<', '<', '=', ' '},
                        {')', '>', '>', '>', '>', ' ', '>', '>'},
                        {'=', '<', '<', '<', '<', '<', ' ', '='}};

    for (i = 0; i < 8; i++)//横坐标寻找
        if (Table[i][0] == a)
            break;
    for (j = 0; j < 8; j++)
        if (Table[0][j] == b)//纵坐标寻找
            break;
    if (b == '\0' && numStack.size() > 1) return '>';
    return Table[i][j];//返回的其实是><=
}


/**
 * 计算二元表达式的值
 * @param a 操作数
 * @param theta 运算符
 * @param b 操作数
 * @return 计算后的结果
 */
float operQuestion(float a, char theta, float b) {
    float c;
    if (theta == '+')
        c = a + b;
    else if (theta == '-')
        c = a - b;
    else if (theta == '*')
        c = a * b;
    else
        c = a / b;
    return c;
}

/**
 * 计算表达式的结果\n
 * 计算流程：\n
 *  1. 借用栈来进行计算，分为两个栈来存储表达式，operatorStack 存操作符，numStack 存操作数（数字）。\n
 *  2. 遇到数字，直接入栈numStack。\n
 *  3. 遇到字符串则需要和operatorStack栈顶的元素比较一下优先级。=表示表达式的结束，所以先入=。\n
 *     调用 Precede 比较栈顶元素的字符 和 当前字符的优先级\n
 *     - 如果返回值为 > ，则说明栈顶元素的优先级大于当前预算运算符，因此将栈顶元素的运算符出栈进行计算。\n
 *     - 如果返回值为 < ，则说明栈顶元素的优先级小于当前预算运算符，将当前运算符入栈。\n
 *     - 如果返回值为 = ，则说明栈顶元素的优先级等于当前预算运算符，因此将栈顶元素的运算符出栈，化简。\n
 * @param question 传入的表达式
 * @return 表达式的结果
 */
float clcResult(string question) {
    int i = 0;// 循环变量
    operatorStack.push('=');    // 将“=”压到操作符栈底
    while (question[i] != '=' && question[i] != '\0' || operatorStack.top() != '=') { // 对表达式 a 进行计算
        int y = 0;
        if (question[i] >= '0' && question[i] <= '9') { // 字符是数字
            while(question[i] >= '0' && question[i] <= '9') {
                y = y * 10 + (question[i] - '0');
                i++;
            }
            numStack.push(y);
        } else { //字符是运算符
            switch (getPrecede(operatorStack.top(), question[i])) { //该运算符和栈顶运算符进行优先级比较并做相关处理
                case '<': // 栈顶元素优先权低，当前运算符入栈
                    operatorStack.push(question[i++]);
                    break;
                case '=':// 栈顶元素优先级和当前字符相同，出栈，化简
                    operatorStack.pop();
                    i++;
                    break;
                case '>':// 栈顶元素的优先级大于当前预算运算符，因此将栈顶元素的运算符出栈进行计算
                    char theta = operatorStack.top(); // 运算符栈弹栈
                    operatorStack.pop();
                    float n = numStack.top(); // 取出两个操作数
                    numStack.pop();
                    float m = numStack.top();
                    numStack.pop();
                    numStack.push(operQuestion(m, theta, n)); // 计算结果并压栈
                    break;
            }
        }
    }
    return numStack.top(); // 返回最终计算结果
}


/**
 * 随机获取题目序号\n
 * 随机选取 n 个题目，将题号保存在数组 a 中，使用 set 去重
 * @param n 选择的题目数量
 * @param a 随机得到的题目序号
 */
void selectQuestion(int n,int a[]) {
    srand(time(nullptr));
    set<int>::iterator j;
    set<int> set; // 使用 set 去重
    while (set.size() <= n) {
        set.insert(rand() % N);
    }
    j = set.begin(); // 获取迭代器
    for (int i = 0; i < n; ++i, ++j) {
        a[i] = *j;
    }
}

/**
 * 求平均成绩\n
 * 从 sno_score.txt 读出成绩的信息，计算平均值，写入 sno_average.txt 文件中
 */
void getAvgScore() {//
    int sum = 0, count = 0;
    ifstream inFile;
    // 打开文件
    inFile.open(scoreFile);
    if (!inFile.is_open()) {    // 判断文件是否打开失败
        cout << "无法打开成绩信息文件!" << endl;
        exit(-1);
    }

    while (!inFile.eof()) {//读出所有的历史成绩并求和
        int score;
        inFile >> score;
        sum += score;
        count++;    //记录成绩个数
    }
    inFile.close();
    int avg;
    avg = sum / count; // 计算平均值

    // 写入 average.txt 文件中
    ofstream outfile;    // 定义写文件流
    outfile.open(averageFile, ios::out | ios::app);
    if (!outfile.is_open()) {    // 判断文件是否打开失败
        cout << "无法创建或者无法打开平均成绩文件" << endl;
        exit(-1);
    }
    outfile << avg << endl;//将平均值写入文件中
    outfile.close();
}

/**
 * 完成做题功能\n
 * 1. 用户输入 n，表示要做 n 道题。\n
 * 2. 随机抽取不重复的 n 道题。让用户来做。\n
 * 3. 判断用户输入的结果正误。\n
 * 4. 计算得分，把得分写入sno_score.txt文件中。\n
 * 5. 计算平均分，把平均分写入sno_average.txt中。\n
 * 6. 比较本次得分和之前平均分的大小，判断是进步还是退步。\n
 * @param questions 题库（问题数组）
 */
void practice(Question questions[], string sno) {
    scoreFile = "D:\\" + sno + "_score.txt";
    averageFile = "D:\\" + sno + "_average.txt";
    system("cls");
    cout << "******欢迎******" << endl;
    int score, avg, k = 0;
    int n; // 要做的题目数量
    cout << "请输入要做几道题：" << endl;
    cin >> n;
    int t[n];
    selectQuestion(n, t);    //调用 selectQuestion 函数从试题库中随机抽取 n 道题目
    int i;
    for (i = 0; i < n; i++) {
        //做题并判断答案是否正确
        printf("\n 第%d 道题：\n", i + 1);
        cout << questions[t[i]].title << endl;
        float ans;
        cin >> ans;
        if (abs(questions[t[i]].result - ans) < 0.01) { // 浮点数有可能是循环小数，这里当差距小于 0.01 认为输入正确
            k++;
            cout << "答案正确！" << endl;
        } else {
            printf("答案错误！正确答案为：%f\n", questions[t[i]].result);
        }
    }
    score = 100 * k / n; // 成绩换算成百分制
    printf("\n 本次得分：%d\n", score);    //输出本次做题所得的分数并进行评价
    if (score >= 90)
        cout << "优秀，继续保持" << endl;
    else if (score >= 80)
        cout << "良好，还需努力！" << endl;
    else if (score >= 70)
        cout << "一般，继续加油！" << endl;
    else if (score >= 60)
        cout << "及格，多多努力！" << endl;
    else
        cout << "糟糕，不及格，该好好学习了！" << endl;

    // 把成绩写入 sno_score.txt
    ofstream outfile;

    outfile.open(scoreFile, ios::out | ios::app);
    if (!outfile.is_open()) {    // 判断文件是否打开失败
        cout << "无法建立或者无法打开成绩信息文件！" << endl;
        exit(-1);
    }
    outfile << " " << score;//将本次成绩写入文件
    outfile.close();

    getAvgScore();// 计算平均成绩 这个时候会把平均分算出来 写入sno_average.txt

    // 从average.txt 中读出之前的平均成绩进行对比
    ifstream inFile;
    inFile.open(averageFile);
    if (!inFile.is_open()) { // 判断文件是否打开失败
        cout << "无法打开平均成绩信息文件!" << endl;
        exit(-1);
    }
    inFile >> avg; //读出之前成绩的平均成绩
    if (score > avg)
        cout << "成绩较以前相比有所进步，继续努力！" << endl;
    else if (score < avg)
        cout << "成绩较以前相比退步了，要多多练习，不要气馁！！" << endl;
    else
        cout << " 成绩与以前持平" << endl;
}

/**
 * 输出历史成绩\n\n
 * 从 score.txt 文件中读出历史成绩 和 从 average.txt 中读出平均成绩
 */
void history(string sno) {
    scoreFile = "D:\\" + sno + "_score.txt";
    averageFile = "D:\\" + sno + "_average.txt";
    ifstream inFile;
    // 打开文件
    inFile.open(scoreFile);
    if (!inFile.is_open()) {
        cout << "无法打开成绩信息文件!" << endl;
        exit(-1);
    }
    cout << " 历史成绩显示如下：" << endl;
    int score;
    while (!inFile.eof()) {
        inFile >> score;
        cout << score << endl;
    }
    inFile.close();
    cout << endl;

    inFile.open(averageFile);
    if (!inFile.is_open()) {    // 判断文件是否打开失败
        cout << "无法打开平均成绩文件!" << endl;
        exit(-1);
    }
    int avg;
    inFile >> avg;
    cout << "平均为：" << avg << endl;
}

#endif //ALOGORITHM_CALCULATE_H
