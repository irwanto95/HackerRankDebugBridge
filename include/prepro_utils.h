#ifndef PREPRO_UTILS_H
#define PREPRO_UTILS_H

/* open file input to parse
*/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

#ifdef _WIN32
#define USE_FILE_INPUT
#endif // _WIN32

#ifdef USE_FILE_INPUT
#define INPUT_OPEN								\
const char * path = "../data/input.txt";		\
ifstream file(path);							\
if (!file.is_open())							\
{												\
	return -1;									\
};												\

#define INPUT_CLOSE				file.close()
#define cin						file
#define MAIN_ENTRY(FileName)	main_##FileName##(ifstream & file)
#else
#define INPUT_OPEN				ifstream file
#define INPUT_CLOSE				file.close()
#define cin						std::cin
#define MAIN_ENTRY(FileName)	main_##FileName##()
#endif // USE_FILE_INPUT

using namespace std;

/* including file
*/
#define TaskHeader(path, file)		TaskHeader1(path, file)
#define TaskHeader1(path, file)		TaskHeader2(path##/##file##.h)
#define TaskHeader2(file)			#file

// 'file' is 'ifstream file'
#define LaunchTask(task, stream)		LaunchTask1(task, stream)
#define LaunchTask1(task, stream)		main_##task(stream)
#ifdef USE_FILE_INPUT
#define LaunchTaskF(task)				LaunchTask(task, file)
#else
#define LaunchTaskF(task)				LaunchTask(task)
#endif // USE_FILE_INPUT

#define CHRONO_START()	auto start = chrono::high_resolution_clock::now()
#define CHRONO_FINISH()\
auto stop = chrono::high_resolution_clock::now();\
auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);\
cout << endl << "Time taken by function: " << duration.count() << " milliseconds" << endl;\


#endif // PREPRO_UTILS_H