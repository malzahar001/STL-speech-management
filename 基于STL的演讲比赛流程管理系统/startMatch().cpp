#include "Manage.h"
//展示菜单
void Manage::show_Menu() {
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

/**************************
*开始比赛
* 
***************************/
//搬运函数
Player s_transform(Player& p) {
	return p;
}
//比较分数函数
bool cmp(Player& p1, Player& p2) {
	if (p1.m_grade != p2.m_grade)
		return p1.m_grade > p2.m_grade;
	else return p1.m_number < p2.m_number;
}
//打印选手编号信息
void printPlayer1(Player player) {
	cout << player.m_number << ' ';
}
//打印选手完整信息
void printPlayer2(Player player) {
	cout << "选手编号：" << player.m_number << " 选手名称： " << player.m_name
		<< " 选手分数： " << player.m_grade << endl;
}

Manage::Manage() {
	initSpeech();//初始化所有选手组

	createPlayer();//创建所有选手到未分配的组里

	loadRecord();//加载往届记录
}

//初始化管理类数据
void Manage::initSpeech() {
	p.clear();
	p1.clear();
	p2.clear();
	p3.clear();
	m_Record.clear();//重置往届记录容器
	nowTimes = 0;//当前比赛届数初始化为0届
}

//创建12个选手并设置信息
void Manage::createPlayer() {
	string str_name = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++) {
		Player temp;
		temp.m_number = "100";
		if (i < 9)
			temp.m_number += '0';
		temp.m_number += to_string(i+1);
		temp.m_name = "选手";
		temp.m_name += str_name[i];
		temp.m_grade = 0;
		p.push_back(temp);
	}
}

//对选手演讲顺序进行抽签
void Manage::setPlayer(vector<Player>& p) {
	//对所有选手洗牌
	random_shuffle(p.begin(), p.end());
	cout << "-------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	for_each(p.begin(), p.end(), printPlayer1);
	cout <<endl<< "-------------------" << endl;
	system("pause");
}

//显示小组信息
void Manage::showGroup(vector<Player>& p) {
	cout << "小组信息: " << endl;
	for_each(p.begin(), p.end(), printPlayer2);
}
//给小组各个成员打分
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
//开始演讲比赛（并且写文件，保存）
void Manage::startMatch() {
	//1.输出届数
	cout << "第"<<nowTimes<<"届比赛开始！" << endl;
	//2.第一轮抽签
	cout << "第一轮比赛选手正在抽签" << endl;
	setPlayer(p);
	//3.第一轮分组
	//先扩展空间
	p1.resize(p.size() / 2);
	p2.resize(p.size() / 2);
	//搬运容器
	transform(p.begin(), p.begin() + 6, p1.begin(), s_transform);
	transform(p.begin() + 6, p.end(), p2.begin(), s_transform);
	//4.第一轮比赛
	cout << "---------------第一轮正式比赛开始---------------" << endl;
	cout << "第一小组比赛名次：" << endl;
	//第一小组打分，然后排序，并展示信息
	getScore(p1);
	sort(p1.begin(), p1.end(), cmp);
	showGroup(p1);

	cout << "第二小组比赛名次：" << endl;
	//第二小组打分，然后排序，并展示信息
	getScore(p2);
	sort(p2.begin(), p2.end(), cmp);
	showGroup(p2);
	cout << "---------------第一轮正式比赛完毕---------------" << endl;
	system("pause");

	//5.晋级
	//一二组前三名晋级到第三组
	//先扩展空间
	p3.resize(p1.size());
	//搬运容器
	transform(p1.begin(), p1.begin() + 3, p3.begin(), s_transform);
	transform(p2.begin(), p2.begin() + 3, p3.begin()+3, s_transform);
	cout << "---------------第一轮晋级选手信息如下---------------" << endl;
	showGroup(p3);
	system("pause");
	system("cls");
	show_Menu();

	//6.抽签
	cout << "第二轮比赛选手正在抽签" << endl;
	setPlayer(p3);
	//7.第二轮比赛
	cout << "---------------第二轮正式比赛开始---------------" << endl;
	cout << "第一小组比赛名次：" << endl;
	//小组打分，然后排序，并展示信息
	getScore(p3);
	sort(p3.begin(), p3.end(), cmp);
	showGroup(p3);
	cout << "---------------第二轮正式比赛完毕---------------" << endl;
	system("pause");

	//8.显示第二轮晋级选手
	cout << "---------------第二轮晋级选手信息如下---------------" << endl;
	for_each(p3.begin(), p3.begin() + 3, printPlayer2);
	cout << "第" << nowTimes << "届比赛结束！" << endl;
	system("pause");
	system("cls");

	//9.将最终晋级选手录入文件
	show_Menu();
	saveDoc(p3);

	//10.重置比赛
	resetMatch();

	system("pause");
	system("cls");
}

//保存文件
void Manage::saveDoc(vector<Player>& p) {
	ofstream ofs;
	ofs.open(speech, ios::out|ios::app);
	ofs << p[0].m_number <<',' << p[0].m_grade << ','
		<< p[1].m_number << ',' << p[1].m_grade << ','
		<< p[2].m_number << ',' << p[2].m_grade;
	ofs << endl;
	ofs.close();
	cout << "记录已经保存" << endl;
	fileIsEmpty = false;//有新纪录，则文件不为空
}
void Manage::resetMatch() {
	initSpeech();//初始化所有选手组
	createPlayer();//创建所有选手到未分配的组里
	loadRecord();//加载往届记录
}