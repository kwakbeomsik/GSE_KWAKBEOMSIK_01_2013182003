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
		
		m_Object[i]->Life = 10;

		if (m_Object[i]->v_x == 0)
		{
			m_Object[i]->v_x -=	1;
		}
		if (m_Object[i]->v_y == 0)
		{
			m_Object[i]->v_y += 1;
		}
	}


	m_Build = new Object;
	m_Build->Life = 500;
}
SceneMgr::~SceneMgr()
{
}
bool SceneMgr::CheckCollision(Object* Object)
{
		if (sqrt((m_Build->GetPosition().x - Object->GetPosition().x)*(m_Build->GetPosition().x - Object->GetPosition().x) + (m_Build->GetPosition().y - Object->GetPosition().y)*(m_Build->GetPosition().y - Object->GetPosition().y)) <= 30)
			return true;
		else
			return false;	
}
