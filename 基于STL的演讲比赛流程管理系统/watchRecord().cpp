#include "Manage.h"
/**************************
*�鿴�����¼�����ļ���
*
***************************/
void Manage::watchRecord() {
	if (fileIsEmpty) {
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < m_Record.size(); i++) {
			cout << "��" << i + 1 << "��"
				<< "�ھ���ţ�" << m_Record[i][0] << " �÷֣�" << m_Record[i][1]
				<< " �Ǿ���ţ�" << m_Record[i][2] << " �÷֣�" << m_Record[i][3]
				<< " ������ţ�" << m_Record[i][4] << " �÷֣�" << m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}