#include "Manage.h"
/**************************
*清空比赛记录（清空文件，保存）
*
***************************/
void Manage::clearRecord() {
	ofstream ofs;
	ofs.open(speech,ios::trunc);
	ofs.close();
	fileIsEmpty = true;
	//重置比赛
	resetMatch();
	cout << "记录清除成功！" << endl;
	system("pause");
	system("cls");
}