#include "class.h"
#include "rand.h"
#include <string>
#include <sstream>
#include <fstream>
#include <limits>

void getValidNumber(int& number) {
	while (true) {
		cin >> number;
		// ���������״̬���ж������Ƿ���Ч
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������Ч��������һ�����֣�" << endl;
		}
		else break;
	}
}

// �ļ�����
void fileinput(queue cq, queue sq) {

}

// �˹�����
void maninput(queue cq, queue sq) {
	// �ͻ�����
	cout << "������ͻ�������" << endl;
	int num;
	getValidNumber(num);
	for (int i = 1; i <= num; i++) {
		string name, id;
		int arrtime, reqtime, phone[11];
		bool kind;
		cout << "�������" << i << "���ͻ�����Ϣ��" << endl;
		cout << "������������" << endl;
		cin >> name;
		cout << "������绰���루11λ����" << endl;
		do {
			string input;
			cin >> input; // ��ȡ��������

			if (input.length() != 11 || input[0] != '1') {
				cout << "�绰�������벻�Ϸ������������룺" << endl;
				continue;
			}

			bool flag = true;
			for (int j = 0; j < 11; ++j) {
				if (input[j] < '0' || input[j] > '9') {
					cout << "�绰�������벻�Ϸ������������룺" << endl;
					flag = false;
					break;
				}
				phone[j] = input[j] - '0'; // ���ַ�ת��Ϊ��Ӧ�����ֲ��洢
			}

			if (flag) {
				break; // �������Ϸ������˳�ѭ��
			}
		} while (true);
		cout << "���������֤�ţ�18λ����" << endl;
		bool flag = true;
		do {
			cin >> id; // ��ȡ��������
			if (id[0] < '1' || id[0] > '9') {
				flag = false; // ��һ���ַ�����������1-9
			}

			for (int j = 1; j < 17; ++j) {
				if (id[j] < '0' || id[j] > '9') {
					flag = false; // ��2����17λ����������
					break;
				}
			}

			if (flag) {
				if ((id[17] < '0' || id[17] > '9') && id[17] != 'X') {
					flag = false; // ��18λ���������ֻ�X
				}
			}

			if (!flag) {
				cout << "���֤�����벻�Ϸ������������룺" << endl;
			}
		} while (!flag); // �������Ϸ������˳�ѭ��
		cout << "������ҵ�����ͣ�" << endl;
		cout << "0.��ͨҵ��" << endl;
		cout << "1.����ҵ��" << endl;
		cin >> kind;
		cout << "�����뵽��ʱ�䣨��ʽ��HH:MM����" << endl;
		string time;
		int hours, minutes;
		getline(cin, time);
		// ʹ�� stringstream �����ַ�������
		stringstream ss(time);
		char colon;  // ������ȡð��
		// ��ȡСʱ�ͷ���
		ss >> hours >> colon >> minutes;
		arrtime = (hours - OpeningHour) * 60 + (minutes - OpeningMintue);
		cout << "����������ʱ����" << endl;
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
	cout << "��ѡ���������ݵķ�ʽ������ѡ���" << endl;
	cout << "1.�������" << endl;
	cout << "2.�ļ�����" << endl;
	cout << "3.�˹�����" << endl;
	cout << "4.�˳�" << endl;
}

int main() {
	queue Cqueue, Squeue;
	char choice;
	do {
		PrintMenu();
		cin >> choice;
		switch (choice) {
		case'1': // �������
			randinput(Cqueue, Squeue);
			break;
		case'2': // �ļ�����
			fileinput(Cqueue, Squeue);
			break;
		case'3': // �˹�����
			maninput(Cqueue, Squeue);
			break;
		case'4': // ����
			return 0;
			break;
		default:cout << "������Ϸ���ѡ��" << endl;
		}
	} while (choice != '4');
	
	Time();
	return 0;
}