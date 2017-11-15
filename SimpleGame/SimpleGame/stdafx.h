#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <ctime>
#include <windows.h>
#pragma comment(lib, "winmm.lib") 

using namespace std;



#define MAX_OBJECT_COUNT 30
#define MAX_BUILDING_COUNT 1
#define MAX_BULLET_COUNT 20
#define MAX_ARROW_COUNT 30


#define OBJECT_CHARACTER 0
#define OBJECT_BUILDING 1
#define OBJECT_BULLET 2
#define OBJECT_ARROW 3