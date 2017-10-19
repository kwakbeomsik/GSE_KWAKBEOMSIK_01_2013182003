#pragma once
#include "Object.h"


class SceneMgr
{
public:
	Object* m_Object[MAX_OBJECTS_COUNT];

public:
	SceneMgr();
	~SceneMgr();
};

