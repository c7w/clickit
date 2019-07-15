#include <iostream>
#include "game.cpp"
#include <string>
using namespace std;

int status[9][9];
static int size = 3;

//Game Controller

//����������꣬����ֵ
void set(int x, int y, int value)
{
	if (x <= 0 || x > ::size || y <= 0 || y > ::size) return;
	x--; y--;
	status[x][y] = value;
}

//����������꣬����ֵ
void add(int x, int y, int amount)
{
	if (x <= 0 || x > ::size || y <= 0 || y > ::size) return;
	x--; y--;
	int origin = status[x][y];
	origin = origin + amount;
	set(x+1, y+1, origin);
}

//����������꣬ȡ�ö�Ӧֵ����������겻��������� -1
int get(int x, int y)
{
	if (x <= 0 || x > ::size || y <= 0 || y > ::size) return -1;
	x--; y--;
	int o = status[x][y];
	return o;
}

//���������꣬Ϊ��Χ����ֵ������һ��������
void click(int x, int y, int clickTime) {
	add(x, y, clickTime);
	add(x + 1, y, clickTime);
	add(x - 1, y, clickTime);
	add(x, y + 1, clickTime);
	add(x, y - 1, clickTime);
}

//Ĭ�ϻ����̣��ߴ��СΪ3�����и������㡣
void goDefault() {
	for (int x = 1; x <= 10; x++) {
		for (int y = 1; y <= 10; y++) {
			int a = x - 1;
			int b = y - 1;
			status[a][b] = 0;
		}
	}
}

//��ȡ������Ϣ����ʽ��"[S]%����С%[O]1#2#3#;2#2#3#;3#2#3#;"
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
//��ȡ�������ݲ����أ���ѡ����Ϊ����������ʾ
string getInput(string hint = "���������ݣ�")
{
	string input;
	cout << hint;
	cin >> input;
	cout << endl;
	return input;
}

//�� �ַ��� ����ת��Ϊ ���� ����
int stringtoint(string in)
{
	const char* i = in.data();
	int out = atoi(i);
	return out;
}

//�����������ۺϣ�ֱ�ӻ������
int getInt(string hint)
{
	string in = getInput(hint);
	int out = stringtoint(in);
	return out;
}

//δ�깤
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
		cout << "|1.�������" << endl;
		cout << "|2.��ȡ״̬" << endl;
		cout << "|9.��������" << endl;
		cout << "--------------------------------" << endl;
		run = getInt("������ִ�е�����");
		if (run == 1) {
			cout << endl;
			cout << "���������꣺" << endl;
			int x = getInt("������ X ���꣺");
			int y = getInt("������ Y ���꣺");
			click(x, y, 1);
			exit = 0;
			cout << "�����ϣ����ڵ�״̬��" << endl;
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

	cout << "�������˳���";
	return 0;
}