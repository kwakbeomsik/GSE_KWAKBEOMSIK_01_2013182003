#include "stdafx.h"
#include "SceneMgr.h"


SceneMgr::SceneMgr()
{
	srand(time(NULL));

	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{

		float fRandx = 0.0f;
		float fRandy = 0.0f;
		float fRandz = 0.0f;

		fRandx = rand() % 500 - 250;
		fRandy = rand() % 500 - 250;

		m_Object[i] = new Object;
		m_Object[i]->SetPosition(fRandx, fRandy, fRandz);

		m_Object[i]->v_x = rand() % 5 - 2;
		m_Object[i]->v_y = rand() % 5 - 2;
		
		
		if (m_Object[i]->v_x == 0)
		{
			m_Object[i]->v_x -=	1;
		}
		if (m_Object[i]->v_y == 0)
		{
			m_Object[i]->v_y += 1;
		}
		//////ÃÑ¾Ë
		m_Bullet[i] = new Object;

		m_Bullet[i]->v_x = rand() % 5 - 2;
		m_Bullet[i]->v_y = rand() % 5 - 2;


		if (m_Bullet[i]->v_x == 0)
		{
			m_Bullet[i]->v_x -= 1;
		}
		if (m_Bullet[i]->v_y == 0)
		{
			m_Bullet[i]->v_y += 1;
		}


	}
	

	m_Build = new Object;
	
}
SceneMgr::~SceneMgr()
{
}
bool SceneMgr::CheckCollision(Object* Object1, Object* Object2)
{
		if (sqrt((Object2->GetPosition().x - Object1->GetPosition().x)*(Object2->GetPosition().x - Object1->GetPosition().x) + (Object2->GetPosition().y - Object1->GetPosition().y)*(Object2->GetPosition().y - Object1->GetPosition().y)) <= 30)
			return true;
		else
			return false;	
}
