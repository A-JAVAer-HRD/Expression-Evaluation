////
//// Created by huangruidong on 2022/11/24.
////
//#include <iostream>
//#include "Calculate.h"
//using namespace std;
//
//string sno;
//
///**
// * 菜单
// * @return 选择的功能模块
// */
// int menu() {
//    int a;
//    do {
//        system("cls");
//        cout << "******欢迎******" << endl;
//        cout << "请输入学号：" << endl;
//        cin >> sno;
//        cout << "******好好学习 天天向上******" << endl;
//        cout << "1.做题" << endl;
//        cout << "2.查看历史成绩" << endl;
//        cout << "3.退出系统" << endl;
//        cout << "请输入....." << endl;
//        cin >> a;
//    } while (a < 1 || a > 3);
//    return a;
//}
//
///**
// * 主函数
// */
// int main() {
//    char c;
//    ifstream inFile;
//    inFile.open("D:\\shitiku.txt"); // 打开文件
//    if (!inFile.is_open()) { //如果试题库文件不存在，则建立试题库，第一次使用要随机化题库
//        cout << "*****欢迎使用******" << endl;
//        cout << "程序第一次运行，尚无试题库，请先建立试题库！" << endl;
//        system("pause");
//        if (creatQuestion())
//            cout << "成功建立试题库！" << endl;
//        system("pause");
//        inFile.open("D:\\shitiku.txt");
//    }
//    //将试题库文件中的信息读到内存中
//    inFile >> N;
//    Question questions[N]; // 问题数组
//    for (int i = 0; i < N; i++) {
//        string tmp;
//        inFile >> tmp;
//        questions[i].title = tmp;
//        questions[i].result = clcResult(questions[i].title);
//    }
//    inFile.close();
//
//    // 正常的功能模块，根据用户输入的选项，执行相关功能
//    while (1) {
//        switch (menu()) {
//            case 1:
//                do {
//                    practice(questions, sno);
//                    cout << " 是否继续做题？y-是，n-否：" << endl;
//                    cin >> c;
//                } while (c != 'n' && c != 'N');
//                break;
//            case 2:
//                history(sno);    //输出成绩
//                system("pause");
//                break;
//            case 3:
//                cout << " 欢迎使用，再见！" << endl;
//                system("pause");
//                exit(0);    //退出系统
//        }
//    }
//    return 0;
//}