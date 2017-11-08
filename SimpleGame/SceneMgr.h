#pragma once
#include "Object.h"

#define OBJECT_BUILDING
#define OBJECT_CHARACTER
#define OBJECT_BULLET
#define OBJECT_ARROW

class SceneMgr
{
public:
	Object* m_Object[MAX_OBJECTS_COUNT];
	Object* m_Build;

public:
	bool CheckCollision(Object* Object);

public:
	SceneMgr();
	~SceneMgr();
};

