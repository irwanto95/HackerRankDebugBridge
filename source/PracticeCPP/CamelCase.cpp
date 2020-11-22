#include "pch.h"

#include "PracticeCPP/CamelCase.h"
#define main() MAIN_ENTRY(CamelCase)

#include <string>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {
	int res = 1;

	for (auto c : s)
	{
		if (isupper(c))
		{
			res++;
		}
	}

	return res;
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	string s;
	getline(cin, s);

	int result = camelcase(s);

	cout << result << "\n";

	//fout.close();

	return EXIT_SUCCESS;
}