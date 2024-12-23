#include "class.h"
#include "rand.h"
#include <string>
#include <sstream>
#include <fstream>
#include <limits>

void getValidNumber(int& number) {
	while (true) {
		cin >> number;
		// 检查输入流状态，判断输入是否有效
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入无效，请输入一个数字：" << endl;
		}
		else break;
	}
}

// 文件输入
void fileinput(queue cq, queue sq) {

}

// 人工输入
void maninput(queue cq, queue sq) {
	// 客户人数
	cout << "请输入客户人数：" << endl;
	int num;
	getValidNumber(num);
	for (int i = 1; i <= num; i++) {
		string name, id;
		int arrtime, reqtime, phone[11];
		bool kind;
		cout << "请输入第" << i << "个客户的信息：" << endl;
		cout << "请输入姓名：" << endl;
		cin >> name;
		cout << "请输入电话号码（11位）：" << endl;
		do {
			string input;
			cin >> input; // 读取整行输入

			if (input.length() != 11 || input[0] != '1') {
				cout << "电话号码输入不合法，请重新输入：" << endl;
				continue;
			}

			bool flag = true;
			for (int j = 0; j < 11; ++j) {
				if (input[j] < '0' || input[j] > '9') {
					cout << "电话号码输入不合法，请重新输入：" << endl;
					flag = false;
					break;
				}
				phone[j] = input[j] - '0'; // 将字符转换为对应的数字并存储
			}

			if (flag) {
				break; // 如果输入合法，则退出循环
			}
		} while (true);
		cout << "请输入身份证号（18位）：" << endl;
		bool flag = true;
		do {
			cin >> id; // 读取整行输入
			if (id[0] < '1' || id[0] > '9') {
				flag = false; // 第一个字符必须是数字1-9
			}

			for (int j = 1; j < 17; ++j) {
				if (id[j] < '0' || id[j] > '9') {
					flag = false; // 第2到第17位必须是数字
					break;
				}
			}

			if (flag) {
				if ((id[17] < '0' || id[17] > '9') && id[17] != 'X') {
					flag = false; // 第18位必须是数字或X
				}
			}

			if (!flag) {
				cout << "身份证号输入不合法，请重新输入：" << endl;
			}
		} while (!flag); // 如果输入合法，则退出循环
		cout << "请输入业务类型：" << endl;
		cout << "0.普通业务" << endl;
		cout << "1.特殊业务" << endl;
		cin >> kind;
		cout << "请输入到达时间（格式：HH:MM）：" << endl;
		string time;
		int hours, minutes;
		getline(cin, time);
		// 使用 stringstream 进行字符串解析
		stringstream ss(time);
		char colon;  // 用来读取冒号
		// 提取小时和分钟
		ss >> hours >> colon >> minutes;
		arrtime = (hours - OpeningHour) * 60 + (minutes - OpeningMintue);
		cout << "请输入所需时长：" << endl;
		getValidNumber(reqtime);
		client newc(name, phone, kind, id, arrtime, reqtime);
		node newnode(newc);
		if (kind == 0)cq.enqueue(newnode);
		else sq.enqueue(newnode);
	}
}

void Time() {
	for (int time = 0; time < MAXTIME; time++) {

	}
}

void PrintMenu() {
	cout << "请选择输入数据的方式（输入选项）：" << endl;
	cout << "1.随机生成" << endl;
	cout << "2.文件输入" << endl;
	cout << "3.人工输入" << endl;
	cout << "4.退出" << endl;
}

int main() {
	queue Cqueue, Squeue;
	char choice;
	do {
		PrintMenu();
		cin >> choice;
		switch (choice) {
		case'1': // 随机生成
			randinput(Cqueue, Squeue);
			break;
		case'2': // 文件输入
			fileinput(Cqueue, Squeue);
			break;
		case'3': // 人工输入
			maninput(Cqueue, Squeue);
			break;
		case'4': // 结束
			return 0;
			break;
		default:cout << "请输入合法的选项" << endl;
		}
	} while (choice != '4');
	
	Time();
	return 0;
}