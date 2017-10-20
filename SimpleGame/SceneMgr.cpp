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

		fRandx = rand() % 250;
		fRandy = rand() % 250;

		m_Object[i] = new Object;
		m_Object[i]->SetPosition(fRandx, fRandy, fRandz);
	}
}


SceneMgr::~SceneMgr()
{
}
