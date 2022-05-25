#pragma once
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;
#define speech "sppech.csv"
class Manage
{
public:

	Manage();

	void initSpeech();//��ʼ������������
	void show_Menu();//չʾ�˵�
	void createPlayer();//����ѡ�ֲ�������Ϣ
	void setPlayer(vector<Player>& p);//��ѡ���ݽ�˳����г�ǩ
	void showGroup(vector<Player>&p);//��ʾС����Ϣ
	void getScore(vector<Player>& p);//��С�������Ա���

	void loadRecord();//���������¼
	void startMatch();
	void watchRecord();
	void clearRecord();
	void exitMatch();

	void resetMatch();//���ñ������͹��캯������һ�������ÿ�β������պ����ã���ᷢ��vectorԽ��
	void saveDoc(vector<Player>& p);//���������¼���ļ�
private:
	vector<Player> p, p1, p2, p3;
	int nowTimes;//��ǰ�����Ľ���
	bool fileIsEmpty;//�ж��ļ��Ƿ�Ϊ��
	map<int, vector<string> >m_Record;//key����ڼ��죬value���������Ϣ
};