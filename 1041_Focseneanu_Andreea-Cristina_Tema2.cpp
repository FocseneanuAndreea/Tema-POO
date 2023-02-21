#pragma once
#include<iostream>
#include<stdio.h>
#include<string.h>


using namespace std;

template<class T>
class Stiva
{
	int nrElem;
	T* stiva;

public:
	Stiva();
	Stiva(int nrElem, T* stiva);
	Stiva(const Stiva& s);
	~Stiva();
	void addElem(T x);
	void removeElem(int index);
	template<class T>
	friend ostream& operator<<(ostream& out, Stiva<T> s);

	template<class T>
	friend istream& operator>>(istream& in, Stiva<T>& s);
};

template<class T>Stiva<T>::Stiva()
{
	this->nrElem = 0;
	this->stiva = nullptr;
}

template<class T>Stiva<T>::Stiva(int nrElem, T* stiva)
{
	if (nrElem > 0 && stiva != nullptr) {
		this->nrElem = nrElem;
		this->stiva = new T[this->nrElem];
		for (int i = 0; i < this->nrElem; i++)
			this->stiva[i] = stiva[i];
	}
	else {
		this->nrElem = 0;
		this->stiva = nullptr;
	}
}

template<class T>Stiva<T>::Stiva(const Stiva<T>& s)
{
	this->nrElem = s.nrElem;
	this->stiva = new T[this->nrElem];
	for (int i = 0; i < this->nrElem; i++)
		this->stiva[i] = s.stiva[i];
}

template<class T>
Stiva<T>::~Stiva()
{
	if (this->stiva != nullptr)
		delete[] this->stiva;
}

template<class T>
void Stiva<T>::addElem(T x)
{
	T* tmp = new T[++this->nrElem];
	for (int i = 0; i < this->nrElem - 1; i++)
		tmp[i] = this->stiva[i];
	tmp[this->nrElem - 1] = x;

	delete[] this->stiva;
	this->stiva = tmp;
}

template<class T>
void Stiva<T>::removeElem(int index)
{
	if (this->nrElem > 1) {
		T* tmp = new T[--this->nrElem];
		int j = 0;
		for (int i = 0; i < this->nrElem + 1; i++)
			if (i != index) {
				tmp[j] = this->stiva[i];
				j++;
			}
			else
				continue;

		delete[] this->stiva;
		this->stiva = tmp;
		this->nrElem = j;
	}
	else {
		this->nrElem = 0;
		this->stiva = nullptr;
	}
}

template<class T>
ostream& operator<<(ostream& out, Stiva<T> s)
{
	out << endl << "Stiva are " << s.nrElem << " elemente." << endl;
	out << "Stiva: ";
	for (int i = s.nrElem-1; i >= 0; i--)
		out << s.stiva[i] << " ";
	out << endl;

	return out;
}

template<class T>
istream& operator>>(istream& in, Stiva<T>& s)
{
	s.nrElem = -1;
	while (s.nrElem < 0) {
		cout << "nr elemente = ";
		in >> s.nrElem;
	}

	if (s.nrElem == 0)
		cout << "Stiva este goala!" << endl;
	else {
		if (s.stiva != nullptr)
			delete[] s.stiva;
		s.stiva = new T[s.nrElem];
		cout << "stiva = ";
		for (int i = 0; i < s.nrElem; i++)
			in >> s.stiva[i];
	}

	return in;
}

template<class T>
class Coada
{
	int nrElem;
	T* coada;

public:
	Coada();
	Coada(int nrElem, T* coada);
	Coada(const Coada& c);
	~Coada();
	void addElem(T x);
	void removeElem(int index);
	template<class T>
	friend ostream& operator<<(ostream& out, Coada<T> c);

	template<class T>
	friend istream& operator>>(istream& in, Coada<T>& c);
};

template<class T>Coada<T>::Coada()
{
	this->nrElem = 0;
	this->coada = nullptr;
}

template<class T>Coada<T>::Coada(int nrElem, T* coada)
{
	if (nrElem > 0 && coada != nullptr) {
		this->nrElem = nrElem;
		this->coada = new T[this->nrElem];
		for (int i = 0; i < this->nrElem; i++)
			this->coada[i] = coada[i];
	}
	else {
		this->nrElem = 0;
		this->coada = nullptr;
	}
}

template<class T>Coada<T>::Coada(const Coada<T>& c)
{
	this->nrElem = c.nrElem;
	this->coada = new T[this->nrElem];
	for (int i = 0; i < this->nrElem; i++)
		this->coada[i] = c.coada[i];
}

template<class T>
Coada<T>::~Coada()
{
	if (this->coada != nullptr)
		delete[] this->coada;
}

template<class T>
void Coada<T>::addElem(T x)
{
	T* tmp = new T[++this->nrElem];
	for (int i = 0; i < this->nrElem - 1; i++)
		tmp[i] = this->coada[i];
	tmp[this->nrElem - 1] = x;

	delete[] this->coada;
	this->coada = tmp;
}

template<class T>
void Coada<T>::removeElem(int index)
{
	if (this->nrElem > 1) {
		T* tmp = new T[--this->nrElem];
		int j = 0;
		for (int i = 0; i < this->nrElem + 1; i++)
			if (i != index) {
				tmp[j] = this->coada[i];
				j++;
			}
			else
				continue;

		delete[] this->coada;
		this->coada = tmp;
	}
	else {
		this->nrElem = 0;
		this->coada = nullptr;
	}
}

template<class T>
ostream& operator<<(ostream& out, Coada<T> c)
{
	out << endl << "Coada are " << c.nrElem << " elemente." << endl;
	out << "Coada: ";
	for (int i = 0; i < c.nrElem; i++)
		out << c.coada[i] << " ";
	out << endl;

	return out;
}

template<class T>
istream& operator>>(istream& in, Coada<T>& c)
{
	c.nrElem = -1;
	while (c.nrElem < 0) {
		cout << "nr elemente = ";
		in >> c.nrElem;
	}

	if (c.nrElem == 0)
		cout << "Coada este goala!" << endl;
	else {
		if (c.coada != nullptr)
			delete[] c.coada;
		c.coada = new T[c.nrElem];
		cout << "coada = ";
		for (int i = 0; i < c.nrElem; i++)
			in >> c.coada[i];
	}

	return in;
}

void main() {
	Stiva<int> s1;
	Coada<int> c1;
	int stiva[3] = { 1, 2, 3 };
	Stiva<int> s2(3, stiva);
	int coada[3] = { 1, 2, 3 };
	Coada<int> c2(3, coada);
	Stiva<int> s3(s2);
	Coada<int> c3(c2);

	cout << s3;
	s3.addElem(5);

	cout << c3;
	c3.addElem(5);

	s3.removeElem(1);
	cout << s3;

	c3.removeElem(2);
	cout << c3;
}