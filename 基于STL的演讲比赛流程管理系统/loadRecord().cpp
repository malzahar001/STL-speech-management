#include "Manage.h"
/**************************
*查看往届记录（读文件）
*
***************************/
void Manage::loadRecord() {
	ifstream ifs;
	ifs.open(speech,ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		fileIsEmpty = true;
		system("pause");
		system("cls");
		ifs.close();
		return;
	}
	else {
		if (ifs.eof()) 
		{
			cout << "文件为空！" << endl;
			fileIsEmpty = true;
			system("pause");
			system("cls");
			ifs.close();
			return;
		}
		//文件有记录信息,将所有记录信息按一行一行并把每行的逗号之间的数据截下来放到往届记录中
		fileIsEmpty = false;
		int num = 0;//代表届数，加载前，届数为0
		string temp;
		while (ifs >> temp) //读入一整行
		{

			vector<string>v;//存放一行中每个逗号之间截下来的数据
			int pos = -1;//追踪每个逗号的位置
			int start = 0;//追踪开始查找逗号的位置
			
			while (true) {
				pos = temp.find(",", start);//追踪每个逗号的位置
				if (pos == -1) {				//说明已经没有逗号，则只剩最后一个数据需要截取
					v.push_back(temp.substr(start, pos - start));  //截取数据，pos-start代表该数据长度
					break;
				}
				v.push_back(temp.substr(start, pos - start));  //截取数据，pos-start代表该数据长度
				start = pos + 1;//起始位置更新到逗号之后一个位置
			}
			m_Record.insert(pair<int, vector<string> >(num,v));//插入这个一届（一行）的往届记录
			num++;//更新比赛届数
			nowTimes = num+1;//更新当前比赛届数
		}

		ifs.close();
	}

}