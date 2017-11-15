#pragma once
#include "Object.h"
#include "Renderer.h"


class SceneMgr
{
public:
	Object* m_Object[MAX_OBJECT_COUNT];
	Object* m_Building[MAX_BUILDING_COUNT];
	Object* m_Bullet[MAX_BULLET_COUNT];
	Object* m_Arrow[MAX_ARROW_COUNT];

	Renderer* m_pRenderer;
	Renderer* m_texCharacter;

public:
	bool CheckCollision(Object* Object1, Object* Object2);
	int AddActorObject(float x, float y, int type);
	void DrawScene();
	
public:
	SceneMgr(int width, int height);
	~SceneMgr();
};

