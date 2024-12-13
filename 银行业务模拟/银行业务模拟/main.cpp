#include "class.h"

void Time() {
	for (int time = 0; time < 480; time++) {

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
	char choice;
	do {
		PrintMenu();
		cin >> choice;
		switch (choice) {
		case'1': // 随机生成
			break;
		case'2': // 文件输入
			break;
		case'3': // 人工输入
			break;
		case'4': // 结束
			return 0;
			break;
		default:cout << "请输入合法的选项" << endl;
		}
	} while (choice != '4');

	return 0;
}