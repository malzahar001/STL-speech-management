#include "Manage.h"
/**************************
*��ձ�����¼������ļ������棩
*
***************************/
void Manage::clearRecord() {
	ofstream ofs;
	ofs.open(speech,ios::trunc);
	ofs.close();
	fileIsEmpty = true;
	//���ñ���
	resetMatch();
	cout << "��¼����ɹ���" << endl;
	system("pause");
	system("cls");
}