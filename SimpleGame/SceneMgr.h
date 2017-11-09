#pragma once
#include "Object.h"

#define OBJECT_BUILDING 0
#define OBJECT_CHARACTER 1
#define OBJECT_BULLET 2
#define OBJECT_ARROW 3



class SceneMgr
{
public:
	Object* m_Object[MAX_OBJECTS_COUNT];
	Object* m_Build;
	Object* m_Bullet[MAX_BULLET_COUNT];
	Object* m_Arrow[MAX_ARROW_COUNT];

public:
	bool CheckCollision(Object* Object1, Object* Object2);
	void AddObject(int type);
	

public:
	SceneMgr();
	~SceneMgr();
};

