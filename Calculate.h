//
// Created by huangruidong on 2022/12/1.
//

#ifndef ALOGORITHM_CALCULATE_H
#define ALOGORITHM_CALCULATE_H
//�˳��������ļ����������� D �̸�Ŀ¼�£�ʵ�ʵ�������ʱ���ɸ���ʵ��������Ĵ洢·��
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


int N;	//����ȫ�ֱ�������ʾ�������������
Stack<float> numStack;//����ջ
Stack<char> operatorStack;//�����ջ
string scoreFile;
string averageFile;

/**
 * ���������\n
 * ��D��shitiku.txt�ļ�������Ĵ������ʽ\n
 * �������ʽʱ�����������0�Ļ��������һ����Ϊ0������
 * */
int creatQuestion() { //���������
    ofstream outfile;    // ����д�ļ���
    // ���ļ�
    outfile.open("D:\\shitiku.txt", ios::out | ios::app);
    if (!outfile.is_open()) {    // �ж��ļ��Ƿ��ʧ��
        cout << "�޷�����������ļ���" << endl;
        return 0;
    }
    cout << "����Ҫ������������������Ŀ: " << endl;
    cin >> N;
    outfile << N << endl;
    srand(time(nullptr));
    int i;
    for (i = 0; i < N; i++) {
        Question t;
        string s;
        int i = rand() % 5; // ������ʽ�Ľṹ(ģ��)
        char lastChar = ' '; // ��һ������
        s = exStruct[i]; // ���սṹ���й���
        for (i = 0; i < s.size(); i++) {
            if (s[i] == 'O') {
                int j = rand() % 4;
                s[i] = ptr[j]; // �滻ΪO�ַ�Ϊ�����(+-*/)�������
                lastChar = s[i];
            }
            if (s[i] == 'E') {
                int j = rand() % 10; // �滻E�ַ�Ϊ����
                while (lastChar == '/' && j == 0) { // ��ֹ��ĸΪ0
                    j = rand() % 10;
                }
                s[i] = j + '0';
            }
        }
        t.title = s;
        outfile << t.title << endl;    //����������ı��ʽд���ļ�
    }
    outfile.close();
    return 1;
}


/**
 * �ж���������ȼ�
 * @param a ջ�����ַ�
 * @param b �������ĵ�ǰ�ַ�
 * @return  ���ȼ��ķ��� > < =
 *          > ��ʾջ������������ȼ� ���� ��ǰ����������ȼ�
 *          < ��ʾջ������������ȼ� С�� ��ǰ����������ȼ�
 *          = ��ʾջ������������ȼ� ���� ��ǰ����������ȼ�
 */
char getPrecede(char a,char b) {
    int i, j;
    // ���ȼ���� ����ջ������� ���ǵ�ǰ�����
    char Table[8][8] = {{' ', '+', '-', '*', '/', '(', ')', '='},
                        {'+', '>', '>', '<', '<', '<', '>', '>'},
                        {'-', '>', '>', '<', '<', '<', '>', '>'},
                        {'*', '>', '>', '>', '>', '<', '>', '>'},
                        {'/', '>', '>', '>', '>', '<', '>', '>'},
                        {'(', '<', '<', '<', '<', '<', '=', ' '},
                        {')', '>', '>', '>', '>', ' ', '>', '>'},
                        {'=', '<', '<', '<', '<', '<', ' ', '='}};

    for (i = 0; i < 8; i++)//������Ѱ��
        if (Table[i][0] == a)
            break;
    for (j = 0; j < 8; j++)
        if (Table[0][j] == b)//������Ѱ��
            break;
    if (b == '\0' && numStack.size() > 1) return '>';
    return Table[i][j];//���ص���ʵ��><=
}


/**
 * �����Ԫ���ʽ��ֵ
 * @param a ������
 * @param theta �����
 * @param b ������
 * @return �����Ľ��
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
 * ������ʽ�Ľ��\n
 * �������̣�\n
 *  1. ����ջ�����м��㣬��Ϊ����ջ���洢���ʽ��operatorStack ���������numStack ������������֣���\n
 *  2. �������֣�ֱ����ջnumStack��\n
 *  3. �����ַ�������Ҫ��operatorStackջ����Ԫ�رȽ�һ�����ȼ���=��ʾ���ʽ�Ľ�������������=��\n
 *     ���� Precede �Ƚ�ջ��Ԫ�ص��ַ� �� ��ǰ�ַ������ȼ�\n
 *     - �������ֵΪ > ����˵��ջ��Ԫ�ص����ȼ����ڵ�ǰԤ�����������˽�ջ��Ԫ�ص��������ջ���м��㡣\n
 *     - �������ֵΪ < ����˵��ջ��Ԫ�ص����ȼ�С�ڵ�ǰԤ�������������ǰ�������ջ��\n
 *     - �������ֵΪ = ����˵��ջ��Ԫ�ص����ȼ����ڵ�ǰԤ�����������˽�ջ��Ԫ�ص��������ջ������\n
 * @param question ����ı��ʽ
 * @return ���ʽ�Ľ��
 */
float clcResult(string question) {
    int i = 0;// ѭ������
    operatorStack.push('=');    // ����=��ѹ��������ջ��
    while (question[i] != '=' && question[i] != '\0' || operatorStack.top() != '=') { // �Ա��ʽ a ���м���
        int y = 0;
        if (question[i] >= '0' && question[i] <= '9') { // �ַ�������
            while(question[i] >= '0' && question[i] <= '9') {
                y = y * 10 + (question[i] - '0');
                i++;
            }
            numStack.push(y);
        } else { //�ַ��������
            switch (getPrecede(operatorStack.top(), question[i])) { //���������ջ��������������ȼ��Ƚϲ�����ش���
                case '<': // ջ��Ԫ������Ȩ�ͣ���ǰ�������ջ
                    operatorStack.push(question[i++]);
                    break;
                case '=':// ջ��Ԫ�����ȼ��͵�ǰ�ַ���ͬ����ջ������
                    operatorStack.pop();
                    i++;
                    break;
                case '>':// ջ��Ԫ�ص����ȼ����ڵ�ǰԤ�����������˽�ջ��Ԫ�ص��������ջ���м���
                    char theta = operatorStack.top(); // �����ջ��ջ
                    operatorStack.pop();
                    float n = numStack.top(); // ȡ������������
                    numStack.pop();
                    float m = numStack.top();
                    numStack.pop();
                    numStack.push(operQuestion(m, theta, n)); // ��������ѹջ
                    break;
            }
        }
    }
    return numStack.top(); // �������ռ�����
}


/**
 * �����ȡ��Ŀ���\n
 * ���ѡȡ n ����Ŀ������ű��������� a �У�ʹ�� set ȥ��
 * @param n ѡ�����Ŀ����
 * @param a ����õ�����Ŀ���
 */
void selectQuestion(int n,int a[]) {
    srand(time(nullptr));
    set<int>::iterator j;
    set<int> set; // ʹ�� set ȥ��
    while (set.size() <= n) {
        set.insert(rand() % N);
    }
    j = set.begin(); // ��ȡ������
    for (int i = 0; i < n; ++i, ++j) {
        a[i] = *j;
    }
}

/**
 * ��ƽ���ɼ�\n
 * �� sno_score.txt �����ɼ�����Ϣ������ƽ��ֵ��д�� sno_average.txt �ļ���
 */
void getAvgScore() {//
    int sum = 0, count = 0;
    ifstream inFile;
    // ���ļ�
    inFile.open(scoreFile);
    if (!inFile.is_open()) {    // �ж��ļ��Ƿ��ʧ��
        cout << "�޷��򿪳ɼ���Ϣ�ļ�!" << endl;
        exit(-1);
    }

    while (!inFile.eof()) {//�������е���ʷ�ɼ������
        int score;
        inFile >> score;
        sum += score;
        count++;    //��¼�ɼ�����
    }
    inFile.close();
    int avg;
    avg = sum / count; // ����ƽ��ֵ

    // д�� average.txt �ļ���
    ofstream outfile;    // ����д�ļ���
    outfile.open(averageFile, ios::out | ios::app);
    if (!outfile.is_open()) {    // �ж��ļ��Ƿ��ʧ��
        cout << "�޷����������޷���ƽ���ɼ��ļ�" << endl;
        exit(-1);
    }
    outfile << avg << endl;//��ƽ��ֵд���ļ���
    outfile.close();
}

/**
 * ������⹦��\n
 * 1. �û����� n����ʾҪ�� n ���⡣\n
 * 2. �����ȡ���ظ��� n ���⡣���û�������\n
 * 3. �ж��û�����Ľ������\n
 * 4. ����÷֣��ѵ÷�д��sno_score.txt�ļ��С�\n
 * 5. ����ƽ���֣���ƽ����д��sno_average.txt�С�\n
 * 6. �Ƚϱ��ε÷ֺ�֮ǰƽ���ֵĴ�С���ж��ǽ��������˲���\n
 * @param questions ��⣨�������飩
 */
void practice(Question questions[], string sno) {
    scoreFile = "D:\\" + sno + "_score.txt";
    averageFile = "D:\\" + sno + "_average.txt";
    system("cls");
    cout << "******��ӭ******" << endl;
    int score, avg, k = 0;
    int n; // Ҫ������Ŀ����
    cout << "������Ҫ�������⣺" << endl;
    cin >> n;
    int t[n];
    selectQuestion(n, t);    //���� selectQuestion ������������������ȡ n ����Ŀ
    int i;
    for (i = 0; i < n; i++) {
        //���Ⲣ�жϴ��Ƿ���ȷ
        printf("\n ��%d ���⣺\n", i + 1);
        cout << questions[t[i]].title << endl;
        float ans;
        cin >> ans;
        if (abs(questions[t[i]].result - ans) < 0.01) { // �������п�����ѭ��С�������ﵱ���С�� 0.01 ��Ϊ������ȷ
            k++;
            cout << "����ȷ��" << endl;
        } else {
            printf("�𰸴�����ȷ��Ϊ��%f\n", questions[t[i]].result);
        }
    }
    score = 100 * k / n; // �ɼ�����ɰٷ���
    printf("\n ���ε÷֣�%d\n", score);    //��������������õķ�������������
    if (score >= 90)
        cout << "���㣬��������" << endl;
    else if (score >= 80)
        cout << "���ã�����Ŭ����" << endl;
    else if (score >= 70)
        cout << "һ�㣬�������ͣ�" << endl;
    else if (score >= 60)
        cout << "���񣬶��Ŭ����" << endl;
    else
        cout << "��⣬�����񣬸úú�ѧϰ�ˣ�" << endl;

    // �ѳɼ�д�� sno_score.txt
    ofstream outfile;

    outfile.open(scoreFile, ios::out | ios::app);
    if (!outfile.is_open()) {    // �ж��ļ��Ƿ��ʧ��
        cout << "�޷����������޷��򿪳ɼ���Ϣ�ļ���" << endl;
        exit(-1);
    }
    outfile << " " << score;//�����γɼ�д���ļ�
    outfile.close();

    getAvgScore();// ����ƽ���ɼ� ���ʱ����ƽ��������� д��sno_average.txt

    // ��average.txt �ж���֮ǰ��ƽ���ɼ����жԱ�
    ifstream inFile;
    inFile.open(averageFile);
    if (!inFile.is_open()) { // �ж��ļ��Ƿ��ʧ��
        cout << "�޷���ƽ���ɼ���Ϣ�ļ�!" << endl;
        exit(-1);
    }
    inFile >> avg; //����֮ǰ�ɼ���ƽ���ɼ�
    if (score > avg)
        cout << "�ɼ�����ǰ�����������������Ŭ����" << endl;
    else if (score < avg)
        cout << "�ɼ�����ǰ����˲��ˣ�Ҫ�����ϰ����Ҫ���٣���" << endl;
    else
        cout << " �ɼ�����ǰ��ƽ" << endl;
}

/**
 * �����ʷ�ɼ�\n\n
 * �� score.txt �ļ��ж�����ʷ�ɼ� �� �� average.txt �ж���ƽ���ɼ�
 */
void history(string sno) {
    scoreFile = "D:\\" + sno + "_score.txt";
    averageFile = "D:\\" + sno + "_average.txt";
    ifstream inFile;
    // ���ļ�
    inFile.open(scoreFile);
    if (!inFile.is_open()) {
        cout << "�޷��򿪳ɼ���Ϣ�ļ�!" << endl;
        exit(-1);
    }
    cout << " ��ʷ�ɼ���ʾ���£�" << endl;
    int score;
    while (!inFile.eof()) {
        inFile >> score;
        cout << score << endl;
    }
    inFile.close();
    cout << endl;

    inFile.open(averageFile);
    if (!inFile.is_open()) {    // �ж��ļ��Ƿ��ʧ��
        cout << "�޷���ƽ���ɼ��ļ�!" << endl;
        exit(-1);
    }
    int avg;
    inFile >> avg;
    cout << "ƽ��Ϊ��" << avg << endl;
}

#endif //ALOGORITHM_CALCULATE_H
