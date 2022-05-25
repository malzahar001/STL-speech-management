#include "Manage.h"
//չʾ�˵�
void Manage::show_Menu() {
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

/**************************
*��ʼ����
* 
***************************/
//���˺���
Player s_transform(Player& p) {
	return p;
}
//�ȽϷ�������
bool cmp(Player& p1, Player& p2) {
	if (p1.m_grade != p2.m_grade)
		return p1.m_grade > p2.m_grade;
	else return p1.m_number < p2.m_number;
}
//��ӡѡ�ֱ����Ϣ
void printPlayer1(Player player) {
	cout << player.m_number << ' ';
}
//��ӡѡ��������Ϣ
void printPlayer2(Player player) {
	cout << "ѡ�ֱ�ţ�" << player.m_number << " ѡ�����ƣ� " << player.m_name
		<< " ѡ�ַ����� " << player.m_grade << endl;
}

Manage::Manage() {
	initSpeech();//��ʼ������ѡ����

	createPlayer();//��������ѡ�ֵ�δ���������

	loadRecord();//���������¼
}

//��ʼ������������
void Manage::initSpeech() {
	p.clear();
	p1.clear();
	p2.clear();
	p3.clear();
	m_Record.clear();//���������¼����
	nowTimes = 0;//��ǰ����������ʼ��Ϊ0��
}

//����12��ѡ�ֲ�������Ϣ
void Manage::createPlayer() {
	string str_name = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++) {
		Player temp;
		temp.m_number = "100";
		if (i < 9)
			temp.m_number += '0';
		temp.m_number += to_string(i+1);
		temp.m_name = "ѡ��";
		temp.m_name += str_name[i];
		temp.m_grade = 0;
		p.push_back(temp);
	}
}

//��ѡ���ݽ�˳����г�ǩ
void Manage::setPlayer(vector<Player>& p) {
	//������ѡ��ϴ��
	random_shuffle(p.begin(), p.end());
	cout << "-------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	for_each(p.begin(), p.end(), printPlayer1);
	cout <<endl<< "-------------------" << endl;
	system("pause");
}

//��ʾС����Ϣ
void Manage::showGroup(vector<Player>& p) {
	cout << "С����Ϣ: " << endl;
	for_each(p.begin(), p.end(), printPlayer2);
}
//��С�������Ա���
void Manage::getScore(vector<Player>& p) {
	double score[10];
	for (vector<Player>::iterator it = p.begin(); it != p.end(); it++) {
		double sum = 0;
		for (int i = 0; i < 10; i++) {
			score[i] = rand() % 11;
		}
		sort(score, score + 10);
		for (int i = 1; i < 9; i++) {
			sum += score[i];
		}
		it->m_grade = sum / 8;
	}
}
//��ʼ�ݽ�����������д�ļ������棩
void Manage::startMatch() {
	//1.�������
	cout << "��"<<nowTimes<<"�������ʼ��" << endl;
	//2.��һ�ֳ�ǩ
	cout << "��һ�ֱ���ѡ�����ڳ�ǩ" << endl;
	setPlayer(p);
	//3.��һ�ַ���
	//����չ�ռ�
	p1.resize(p.size() / 2);
	p2.resize(p.size() / 2);
	//��������
	transform(p.begin(), p.begin() + 6, p1.begin(), s_transform);
	transform(p.begin() + 6, p.end(), p2.begin(), s_transform);
	//4.��һ�ֱ���
	cout << "---------------��һ����ʽ������ʼ---------------" << endl;
	cout << "��һС��������Σ�" << endl;
	//��һС���֣�Ȼ�����򣬲�չʾ��Ϣ
	getScore(p1);
	sort(p1.begin(), p1.end(), cmp);
	showGroup(p1);

	cout << "�ڶ�С��������Σ�" << endl;
	//�ڶ�С���֣�Ȼ�����򣬲�չʾ��Ϣ
	getScore(p2);
	sort(p2.begin(), p2.end(), cmp);
	showGroup(p2);
	cout << "---------------��һ����ʽ�������---------------" << endl;
	system("pause");

	//5.����
	//һ����ǰ����������������
	//����չ�ռ�
	p3.resize(p1.size());
	//��������
	transform(p1.begin(), p1.begin() + 3, p3.begin(), s_transform);
	transform(p2.begin(), p2.begin() + 3, p3.begin()+3, s_transform);
	cout << "---------------��һ�ֽ���ѡ����Ϣ����---------------" << endl;
	showGroup(p3);
	system("pause");
	system("cls");
	show_Menu();

	//6.��ǩ
	cout << "�ڶ��ֱ���ѡ�����ڳ�ǩ" << endl;
	setPlayer(p3);
	//7.�ڶ��ֱ���
	cout << "---------------�ڶ�����ʽ������ʼ---------------" << endl;
	cout << "��һС��������Σ�" << endl;
	//С���֣�Ȼ�����򣬲�չʾ��Ϣ
	getScore(p3);
	sort(p3.begin(), p3.end(), cmp);
	showGroup(p3);
	cout << "---------------�ڶ�����ʽ�������---------------" << endl;
	system("pause");

	//8.��ʾ�ڶ��ֽ���ѡ��
	cout << "---------------�ڶ��ֽ���ѡ����Ϣ����---------------" << endl;
	for_each(p3.begin(), p3.begin() + 3, printPlayer2);
	cout << "��" << nowTimes << "�����������" << endl;
	system("pause");
	system("cls");

	//9.�����ս���ѡ��¼���ļ�
	show_Menu();
	saveDoc(p3);

	//10.���ñ���
	resetMatch();

	system("pause");
	system("cls");
}

//�����ļ�
void Manage::saveDoc(vector<Player>& p) {
	ofstream ofs;
	ofs.open(speech, ios::out|ios::app);
	ofs << p[0].m_number <<',' << p[0].m_grade << ','
		<< p[1].m_number << ',' << p[1].m_grade << ','
		<< p[2].m_number << ',' << p[2].m_grade;
	ofs << endl;
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
	fileIsEmpty = false;//���¼�¼�����ļ���Ϊ��
}
void Manage::resetMatch() {
	initSpeech();//��ʼ������ѡ����
	createPlayer();//��������ѡ�ֵ�δ���������
	loadRecord();//���������¼
}