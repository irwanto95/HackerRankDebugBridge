#include "pch.h"
#include "PracticeCPP/AttendingWorkshops.h"

#define main() MAIN_ENTRY(AttendingWorkshops)

#ifndef _WIN32
#include<bits/stdc++.h>
#endif // !_WIN32

#include <algorithm>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops
{
	void Init(int start, int duration)
	{
		mStartTime = start;
		mDuration = duration;
		mEndTime = start + duration;
	}

	int mStartTime;
	int mDuration;
	int mEndTime;
};

struct Available_Workshops
{
	~Available_Workshops()
	{
		delete[] mWorkshops;
	}

	int mNumberOfWorkshops;
	Workshops * mWorkshops;
};

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
	Available_Workshops* worksops = new Available_Workshops();
	worksops->mNumberOfWorkshops = n;
	worksops->mWorkshops = new Workshops[n];

	for (int i = 0; i < n; i++)
	{
		worksops->mWorkshops[i].Init(start_time[i], duration[i]);
	}

	/*	idea: https://www.hackerrank.com/challenges/attending-workshops/forum
		user: christosg8
		url: https://en.wikipedia.org/wiki/Interval_scheduling#Greedy_polynomial_solution
	*/
	std::sort(worksops->mWorkshops
		, worksops->mWorkshops + n
		, [](Workshops & work1, Workshops & work2)
		{
			return (work1.mEndTime < work2.mEndTime)
				|| ((work1.mEndTime == work2.mEndTime) && (work1.mStartTime < work2.mStartTime));
		});

	return worksops;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
	int result = 0;
	int lastEnd = 0;

	for (int i = 0; i < ptr->mNumberOfWorkshops; i++)
	{
		if (i > 0)
		{
			if (ptr->mWorkshops[i].mStartTime < lastEnd)
			{
				continue;
			}
		}
	
		lastEnd = ptr->mWorkshops[i].mEndTime;
		result++;
	}

	return result;
}

int main(int argc, char *argv[]) {
	int n; // number of workshops
	cin >> n;
	// create arrays of unknown size n
	int* start_time = new int[n];
	int* duration = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> start_time[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> duration[i];
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time, duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;
	return 0;
}
