#pragma once
#include "Object.h"
#include "Renderer.h"
#include "Sound.h"


class SceneMgr
{
private:
	Object* m_Object[MAX_OBJECT_COUNT];
	Object* m_Building[MAX_BUILDING_COUNT];
	Object* m_Bullet[MAX_BULLET_COUNT];
	Object* m_Arrow[MAX_ARROW_COUNT];
	Sound* m_Sound;
	Renderer* m_pRenderer;

	int SoundBG[5];
	float EnemyRespawnTime = 0.0f;
	int iFrameMove = 0;
	float fBulletFrame = 0;
	int iTexture[5];
	bool isSound = false;

public:
	bool CheckCollision(Object* Object1, Object* Object2);
	void Collision();
	int AddActorObject(float x, float y, int type, int team);
	void UpdateAllObject(float elapsedTime);
	void DrawScene();
	bool PlayerRespawn();
	
public:
	SceneMgr(int width, int height);
	~SceneMgr();
};

