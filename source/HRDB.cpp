#include "pch.h"

#define HR_TaskFile CollosatronBuggy
#include TaskHeader(GLDC/round_2, HR_TaskFile)

#include <iomanip>

int main() {
	INPUT_OPEN;

	int result = LaunchTaskF(HR_TaskFile);

	INPUT_CLOSE;

	//system("pause");
	return result;
}