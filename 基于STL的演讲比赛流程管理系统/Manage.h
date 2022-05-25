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

	void initSpeech();//初始化管理类数据
	void show_Menu();//展示菜单
	void createPlayer();//创建选手并设置信息
	void setPlayer(vector<Player>& p);//对选手演讲顺序进行抽签
	void showGroup(vector<Player>&p);//显示小组信息
	void getScore(vector<Player>& p);//给小组各个成员打分

	void loadRecord();//加载往届记录
	void startMatch();
	void watchRecord();
	void clearRecord();
	void exitMatch();

	void resetMatch();//重置比赛，和构造函数功能一样，如果每次插入或清空后不重置，则会发生vector越界
	void saveDoc(vector<Player>& p);//将比赛结果录入文件
private:
	vector<Player> p, p1, p2, p3;
	int nowTimes;//当前比赛的届数
	bool fileIsEmpty;//判断文件是否为空
	map<int, vector<string> >m_Record;//key代表第几届，value代表具体信息
};