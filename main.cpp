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
// * �˵�
// * @return ѡ��Ĺ���ģ��
// */
// int menu() {
//    int a;
//    do {
//        system("cls");
//        cout << "******��ӭ******" << endl;
//        cout << "������ѧ�ţ�" << endl;
//        cin >> sno;
//        cout << "******�ú�ѧϰ ��������******" << endl;
//        cout << "1.����" << endl;
//        cout << "2.�鿴��ʷ�ɼ�" << endl;
//        cout << "3.�˳�ϵͳ" << endl;
//        cout << "������....." << endl;
//        cin >> a;
//    } while (a < 1 || a > 3);
//    return a;
//}
//
///**
// * ������
// */
// int main() {
//    char c;
//    ifstream inFile;
//    inFile.open("D:\\shitiku.txt"); // ���ļ�
//    if (!inFile.is_open()) { //���������ļ������ڣ���������⣬��һ��ʹ��Ҫ��������
//        cout << "*****��ӭʹ��******" << endl;
//        cout << "�����һ�����У���������⣬���Ƚ�������⣡" << endl;
//        system("pause");
//        if (creatQuestion())
//            cout << "�ɹ���������⣡" << endl;
//        system("pause");
//        inFile.open("D:\\shitiku.txt");
//    }
//    //��������ļ��е���Ϣ�����ڴ���
//    inFile >> N;
//    Question questions[N]; // ��������
//    for (int i = 0; i < N; i++) {
//        string tmp;
//        inFile >> tmp;
//        questions[i].title = tmp;
//        questions[i].result = clcResult(questions[i].title);
//    }
//    inFile.close();
//
//    // �����Ĺ���ģ�飬�����û������ѡ�ִ����ع���
//    while (1) {
//        switch (menu()) {
//            case 1:
//                do {
//                    practice(questions, sno);
//                    cout << " �Ƿ�������⣿y-�ǣ�n-��" << endl;
//                    cin >> c;
//                } while (c != 'n' && c != 'N');
//                break;
//            case 2:
//                history(sno);    //����ɼ�
//                system("pause");
//                break;
//            case 3:
//                cout << " ��ӭʹ�ã��ټ���" << endl;
//                system("pause");
//                exit(0);    //�˳�ϵͳ
//        }
//    }
//    return 0;
//}