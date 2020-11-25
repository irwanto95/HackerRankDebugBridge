#include "pch.h"

#define HR_TaskFile MagicSpells
#include TaskHeader(PracticeCPP, HR_TaskFile)

#include <iomanip>

int main()
{
	int result;

	INPUT_OPEN;

	result = LaunchTaskF(HR_TaskFile);

	INPUT_CLOSE;

	//system("pause");
	return result;
}