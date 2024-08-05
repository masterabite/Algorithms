#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

//для решения отлично подойдет стек, в котором будем хранить оперируемые числа
stack<int> st;

//функция переводит строку в целое неотрицательное число
int to_int(string str) {
	int n = 0;
	for (char c : str) {
		n *= 10;
		n += c-'0';
	}
	return n;
}

//функция которая возвращает результат выражения a op b, где op - символ, обозначающий знак операцию
int f(int a, int b, char op) {
	if (op == '-') return a - b;
	if (op == '+') return a + b;
	if (op == '*') return a * b;
	if (op == '/') return a / b;
}

int main() {
	string temp; //промежуточная переменная для считывания строк
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		if (!isdigit(temp[0])) { //если очередной элемент не является числом
			int b = st.top(); st.pop(); //сначала достаем из стека второе число
			int a = st.top(); st.pop(); //далее достаем из стека первое число
			st.push(f(a, b, temp[0])); //кладем в стек новое число - результат выражения
		}
		else {
			st.push(to_int(temp)); //если считали число, просто добавляем его в стек
		}
	}
	cout << st.top(); //в результате, в стеке при правильной записи останется единственное число- результат выражения

	return 0;

}
