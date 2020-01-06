// ЗАДЪЛЖИТЕЛНО ПРОЧЕТИ КОДА, РАЗБЕРИ ГО и ГО ПРЕНАПИШИ, защото сега е много подобен на авторския

#include <iostream>
using namespace std;

void turn_on_line (int n);
void turn_off_line (int n);

void turn_on_only (int pos)
{
	if (pos == 1)
		cout << "+1\n";
	else {
		turn_on_only (pos-1);
		cout << "+" << pos << "\n";
		turn_off_line (pos-1);
	}
}
void turn_on_line(int n)
{
	switch (n) {
		case 1:
			cout << "+1\n";
			break;
		case 2:
			cout << "+1\n+2\n";
			break;
		default:
			turn_on_only(n-1);
			cout << "+" << n << "\n";
			turn_on_line(n-2);
	}
}
void turn_off_line (int n)
{
	if (n == 1)
		cout << "-1\n";
	else 
	{
		turn_on_only (n-1);
		cout << "-" << n << "\n";
		turn_off_line (n-1);
	}
}

int main ()
{
	int n;
	cin >> n;
	turn_on_line (n);
	return 0;
}
