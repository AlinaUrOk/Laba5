// Laba5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Laba5.h"
#include <iostream>
#include <cstring>
using namespace std;

struct Stack {
	char c;
	Stack* next;
} *top;
int Prior(char a) {
	switch (a) {
	case'*':case'/':return 3;
	case'%':return 2;
	case'(':return 1;
	}
	return 0;
}
Stack* In(Stack* b, char o) {
	Stack* r = new Stack;
	r->c = o;
	r->next = b;
	return r;
}
Stack* Out(Stack* b, char& i) {
	Stack* r = b;
	i = b->c;
	b = b->next;
	delete r;
	return b;
}
int main()
{
	Stack* w, * p = NULL;
	char a;
	char I[200], Ou[200];
	int k = 0, l = 0;
	cout << "Enter your mathematical example: ";
	cin >> I; '\n';
	while (I[k] != '\0') {
		if (I[k] >= 'a' && I[k] <= 'z') {
			Ou[l] = I[k];
			l++;
		}
		if (I[k] == '(') {
			p = In(p, I[k]);
		}
		if (I[k] == ')') {
			while ((p->c) != '(') {
				p = Out(p, a);
				if (!p) {
					Ou[l] = a;
					l++;
				}
			}
			w = p;
			p = p->next;
			delete w;
		}
		if (I[k] == '%' || I[k] == '/' || I[k] == '*' ) {
			while (p != NULL && Prior(p->c) >= Prior(I[k])) {
				p = Out(p, a);
				Ou[l] = a;
				l++;
			}
			p = In(p, I[k]);
		}
		k++;
	}
	while (p != NULL) {
		p = Out(p, a);
		Ou[l] = a;
		l++;
	}
	Ou[l] = '\0';
	cout << Ou << endl;
	cout << "Results: ";
	cout << NewRES(Ou) << endl;
	
}

 double NewRES(char* str)
{
	double Res;
	char q, e, t, y = 'z' + 1;
	int u, x, res = 0;
	int mas[200];
	cout << "Dannie: ";
	for (int i = 0; str[i] != '\0'; i++) {
		q = str[i];
		if (q >= 'a' && q <= 'z') {
			cout << q << ':';
			cin >> mas[int(q)];
		}
	}
	for (int i = 0; str[i] != '\0'; i++) {
		q = str[i];
		if (!(q == '/') || (q == '*') || (q == '%') ) {
			top = In(top, q);
		}
		else {
			top = Out(top, e);
			top = Out(top, q);
			u = mas[int(e)];
			x = mas[int(q)];
			switch (q) {
			case'*':res = u * x; break;
			case'/':res = u / x; break;
			case'%':res = u % x; break;
			}
			mas[int(y)] = res;
			top = In(top, y);
			y++;
		}
	}
	return res;
}

