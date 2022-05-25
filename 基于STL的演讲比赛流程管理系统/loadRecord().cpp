#include "Manage.h"
/**************************
*�鿴�����¼�����ļ���
*
***************************/
void Manage::loadRecord() {
	ifstream ifs;
	ifs.open(speech,ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		fileIsEmpty = true;
		system("pause");
		system("cls");
		ifs.close();
		return;
	}
	else {
		if (ifs.eof()) 
		{
			cout << "�ļ�Ϊ�գ�" << endl;
			fileIsEmpty = true;
			system("pause");
			system("cls");
			ifs.close();
			return;
		}
		//�ļ��м�¼��Ϣ,�����м�¼��Ϣ��һ��һ�в���ÿ�еĶ���֮������ݽ������ŵ������¼��
		fileIsEmpty = false;
		int num = 0;//�������������ǰ������Ϊ0
		string temp;
		while (ifs >> temp) //����һ����
		{

			vector<string>v;//���һ����ÿ������֮�������������
			int pos = -1;//׷��ÿ�����ŵ�λ��
			int start = 0;//׷�ٿ�ʼ���Ҷ��ŵ�λ��
			
			while (true) {
				pos = temp.find(",", start);//׷��ÿ�����ŵ�λ��
				if (pos == -1) {				//˵���Ѿ�û�ж��ţ���ֻʣ���һ��������Ҫ��ȡ
					v.push_back(temp.substr(start, pos - start));  //��ȡ���ݣ�pos-start��������ݳ���
					break;
				}
				v.push_back(temp.substr(start, pos - start));  //��ȡ���ݣ�pos-start��������ݳ���
				start = pos + 1;//��ʼλ�ø��µ�����֮��һ��λ��
			}
			m_Record.insert(pair<int, vector<string> >(num,v));//�������һ�죨һ�У��������¼
			num++;//���±�������
			nowTimes = num+1;//���µ�ǰ��������
		}

		ifs.close();
	}

}