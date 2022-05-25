#include "Manage.h"
/**************************
*查看往届记录（读文件）
*
***************************/
void Manage::watchRecord() {
	if (fileIsEmpty) {
		cout << "文件不存在或为空" << endl;
	}
	else {
		for (int i = 0; i < m_Record.size(); i++) {
			cout << "第" << i + 1 << "届"
				<< "冠军编号：" << m_Record[i][0] << " 得分：" << m_Record[i][1]
				<< " 亚军编号：" << m_Record[i][2] << " 得分：" << m_Record[i][3]
				<< " 季军编号：" << m_Record[i][4] << " 得分：" << m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}