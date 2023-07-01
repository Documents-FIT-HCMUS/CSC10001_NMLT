#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

void input(int[], int&);
void output(int[], int);
void findPrime(int[], int[], int, int&);
void sortAsc(int[], int);
void swap(int&, int&);
bool prime(int);

bool prime(int x)
{
	int i;
	if (x <= 1) return 0;
	for (i = 2; i < x; i++)
	{
		if (x % i == 0) return 0;
	}
	return 1;
}
void input(int a[], int& an)
{
	int i;
	cout << "Nhap n tu ban phim: ";
	cin >> an;
	for (i = 0; i < an; i++)
	{
		cout << "Nhap phan tu a[" << i << "]: ";
		cin >> a[i];
	}
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sortAsc(int a[], int an)
{
	int i, j;
	for (i = 0; i < an - 1; i++)
	{
		for (j = i + 1; j < an; j++)
			if (a[i] > a[j]) swap(a[i], a[j]);
	}
}

void findPrime(int a[], int b[], int an, int& bn)
{
	int i, j, d;
	for (i = 0; i < an; i++)
	{
		if (prime(a[i]))
		{
			d = 0;
			for (j = 0; j < bn; j++)
			{
				if (a[i] == b[j]) d++;
			}
			if (d == 0)
			{
				b[bn] = a[i];
				bn++;
			}
		}
	}
}

void output(int a[], int an)
{
	int i;
	fstream f;
	f.open("output.txt", ios::out);
	if (f.fail()) cout << "KHONG THE MO FILE.";
	else
	{
		f << an << endl;
		for (i = 0; i < an; i++)
		{
			f << a[i] << " ";
		}
		f.close();
	}
}

int main()
{
	int a[100], b[100], an, bn = 0;
	input(a, an);
	findPrime(a, b, an, bn);
	cout << "Bai 1:\nSo luong so nguyen to phan biet trong mang da nhap la " << bn << " (so nay co ghi o trong file).\n";
	sortAsc(b, bn);
	cout << "Bai 2: ket qua luu trong file output.txt o thu muc project.";
	output(b, bn);
}