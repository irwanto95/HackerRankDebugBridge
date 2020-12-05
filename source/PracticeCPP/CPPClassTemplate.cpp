#include "pch.h"
#include "PracticeCPP/CPPClassTemplate.h"

#define main() MAIN_ENTRY(CPPClassTemplate)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/

/*	got from:
	discussion: https://www.hackerrank.com/challenges/c-class-templates/forum
	comment from: flypixel
	url: https://www.hackerrank.com/flypixel?hr_r=1
*/
#ifndef _WIN32
int start_up()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}

int static r = start_up();

#define endl "\n";
#endif // !_WIN32

template <typename _Type>
class AddElements
{
public:
	AddElements(const _Type & element);
	~AddElements() = default;

	_Type & add(const _Type& element);

private:
	_Type m_element;
};

template<typename _Type>
AddElements<_Type>::AddElements(const _Type & element)
	: m_element(element)
{
}

template<typename _Type>
_Type & AddElements<_Type>::add(const _Type & element)
{
	m_element += element;
	return m_element;
}

/////////////////////////////////////////////////////////

template <>
class AddElements<string>
{
public:
	AddElements(const string & element);
	~AddElements() = default;

	string & concatenate(const string& element);

private:
	string m_element;
};

AddElements<string>::AddElements(const string & element)
	: m_element(element)
{
}

string & AddElements<string>::concatenate(const string & element)
{
	m_element += element;
	return m_element;
}

int main()
{
	CHRONO_START();

	int n, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		string type;
		cin >> type;
		if (type == "float") {
			double element1, element2;
			cin >> element1 >> element2;
			AddElements<double> myfloat(element1);
			cout << myfloat.add(element2) << endl;
		}
		else if (type == "int") {
			int element1, element2;
			cin >> element1 >> element2;
			AddElements<int> myint(element1);
			cout << myint.add(element2) << endl;
		}
		else if (type == "string") {
			string element1, element2;
			cin >> element1 >> element2;
			AddElements<string> mystring(element1);
			cout << mystring.concatenate(element2) << endl;
		}
	}

	CHRONO_FINISH();

	return 0;
}
