#include <iostream>
#include "game.cpp"
#include <string>
using namespace std;

int status[9][9];
static int size = 3;

//Game Controller

//输入相对坐标，设置值
void set(int x, int y, int value)
{
	if (x <= 0 || x > ::size || y <= 0 || y > ::size) return;
	x--; y--;
	status[x][y] = value;
}

//输入相对坐标，增加值
void add(int x, int y, int amount)
{
	if (x <= 0 || x > ::size || y <= 0 || y > ::size) return;
	x--; y--;
	int origin = status[x][y];
	origin = origin + amount;
	set(x+1, y+1, origin);
}

//输入相对坐标，取得对应值，若相对坐标不存在则输出 -1
int get(int x, int y)
{
	if (x <= 0 || x > ::size || y <= 0 || y > ::size) return -1;
	x--; y--;
	int o = status[x][y];
	return o;
}

//点击相对坐标，为周围增加值（增加一定次数）
void click(int x, int y, int clickTime) {
	add(x, y, clickTime);
	add(x + 1, y, clickTime);
	add(x - 1, y, clickTime);
	add(x, y + 1, clickTime);
	add(x, y - 1, clickTime);
}

//默认化棋盘，尺寸大小为3，所有格子清零。
void goDefault() {
	for (int x = 1; x <= 10; x++) {
		for (int y = 1; y <= 10; y++) {
			int a = x - 1;
			int b = y - 1;
			status[a][b] = 0;
		}
	}
}

//获取棋盘信息，格式化"[S]%表格大小%[O]1#2#3#;2#2#3#;3#2#3#;"
string getStatus()
{
	string out = "[S]" + to_string(::size) + "[O]";
	for (int xPos = 1; xPos <= ::size; xPos++) {
		for (int yPos = 1; yPos <= ::size; yPos++) {
			int amount = get(xPos, yPos);
			out += to_string(amount);
			out += "#";
		}
		out += ";";
	}
	return out;
}



//Utils
//获取输入内容并返回，可选参数为内容输入提示
string getInput(string hint = "请输入内容：")
{
	string input;
	cout << hint;
	cin >> input;
	cout << endl;
	return input;
}

//将 字符串 类型转换为 整数 类型
int stringtoint(string in)
{
	const char* i = in.data();
	int out = atoi(i);
	return out;
}

//上述二函数综合，直接获得整数
int getInt(string hint)
{
	string in = getInput(hint);
	int out = stringtoint(in);
	return out;
}

//未完工
void processRawStatus(string in)
{

}

int main()
{
	goDefault();
	int def = 0;
	int exit = 0;
	int run = 0;
	do {
		cout << "--------------------------------" << endl;
		cout << "|1.点击坐标" << endl;
		cout << "|2.获取状态" << endl;
		cout << "|9.结束程序" << endl;
		cout << "--------------------------------" << endl;
		run = getInt("请输入执行的任务：");
		if (run == 1) {
			cout << endl;
			cout << "请输入坐标：" << endl;
			int x = getInt("请输入 X 坐标：");
			int y = getInt("请输入 Y 坐标：");
			click(x, y, 1);
			exit = 0;
			cout << "点击完毕，现在的状态：" << endl;
			string status = getStatus();
			cout << status << endl;
			exit = 0;
		}
		else if (run == 2) {
			string status = getStatus();
			cout << status << endl;
			exit = 0;
		}
		else if (run == 9) {
			exit = 1;
		}
		else {}
	} while (exit == 0);

	cout << "程序已退出！";
	return 0;
}