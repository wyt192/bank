#include "class.h"

void Time() {
	for (int time = 0; time < 480; time++) {

	}
}

void PrintMenu() {
	cout << "��ѡ���������ݵķ�ʽ������ѡ���" << endl;
	cout << "1.�������" << endl;
	cout << "2.�ļ�����" << endl;
	cout << "3.�˹�����" << endl;
	cout << "4.�˳�" << endl;
}

int main() {
	char choice;
	do {
		PrintMenu();
		cin >> choice;
		switch (choice) {
		case'1': // �������
			break;
		case'2': // �ļ�����
			break;
		case'3': // �˹�����
			break;
		case'4': // ����
			return 0;
			break;
		default:cout << "������Ϸ���ѡ��" << endl;
		}
	} while (choice != '4');

	return 0;
}