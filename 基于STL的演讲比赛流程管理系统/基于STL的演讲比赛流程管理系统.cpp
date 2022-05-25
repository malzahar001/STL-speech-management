#include <iostream>
#include "Manage.h"
#include <ctime>
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    Manage cm;
    int select = -1;
    while (true) {
        cm.show_Menu();
        cout << "请输入您的选择： " << endl;
        cin >> select;
        switch (select) {
        case 1:
            //开始演讲比赛（并且写文件，保存）
            cm.startMatch();
            break;
        case 2:
            //查看往届记录（读文件）
            cm.watchRecord();
            break;
        case 3:
            //清空比赛记录（清空文件，保存）
            cm.clearRecord();
            break;
        case 0:
            //退出比赛程序
            cm.exitMatch();
            break;
        default:
            cout << "输入错误数字，请重新输入" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}
