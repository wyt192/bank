#include "rand.h"

int randnum(int lower, int upper) {
    // 创建随机数生成器
    mt19937 rng;
    // 使用系统时钟作为种子
    auto seed = chrono::steady_clock::now().time_since_epoch().count();
    rng.seed(static_cast<unsigned long>(seed));
    // 生成随机数
    uniform_int_distribution<int> dist(lower, upper); // 定义分布范围
    return dist(rng);
}

// 随机姓名
string randname() {
    // 打开文件
    ifstream file("names.txt");
    if (!file.is_open()) {
        cerr << "无法打开文件" << endl;
    }
    // 读取文件中的所有名字
    vector<string> names;
    string name;
    while (getline(file, name)) {
        names.push_back(name);
    }
    file.close();
    // 随机选择一个名字
    int index = randnum(0, names.size() - 1);
    string randName = names[index];
    return randName;
}

// 随机电话号码
void randphone(int* phone) {
    // 第一位为1
    phone[0] = 1;
    // 生成剩余的10个数字
    for (int i = 1; i < 11; i++) {
        // 设置随机数种子
        phone[i] = randnum(0, 9);
    }
}

// 随机生成身份证号
string randid() {
    string id;
    id = '0' + randnum(1, 9);
    for (int i = 1; i < 17; i++) {
        id += '0' + randnum(0, 9);
    }
    int x = rand();
    if (x % 11) {
        id += 'X';
    }
    else {
        id += '0' + randnum(0, 9);
    }
    return id;
}

// 随机生成
void randinput(queue cq, queue sq) {
    int pretime = 0; // 上一位客户到达的时间
    for (int i = 0; pretime < MAXTIME; i++) {
        string name = randname();
        int phone[11];
        randphone(phone);
        bool kind = randnum(0, 1);
        string id = randid();
        // 假设30分钟之内必定会有下一位客户
        int arrtime = randnum(0, 30);
        arrtime += pretime;
        pretime = arrtime;
        int reqtime;
        if (kind) {
            reqtime = randnum(1, 15);
        }
        else {
            reqtime = randnum(1, 5);
        }
        client newc(name, phone, kind, id, arrtime, reqtime);
        node newnode(newc);
        if (kind == 0)cq.enqueue(newnode);
        else sq.enqueue(newnode);
    }
}