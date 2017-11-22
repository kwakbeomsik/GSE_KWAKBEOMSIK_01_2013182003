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
#define MAX_BUILDING_COUNT 6
#define MAX_BULLET_COUNT 100
#define MAX_ARROW_COUNT 20


#define OBJECT_CHARACTER 0
#define OBJECT_BUILDING 1
#define OBJECT_BULLET 2
#define OBJECT_ARROW 3

#define PLAYER 0
#define ENEMY 1