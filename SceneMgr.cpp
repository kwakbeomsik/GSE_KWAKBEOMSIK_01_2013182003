#include "stdafx.h"
#include "SceneMgr.h"


SceneMgr::SceneMgr()
{

	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		
		m_Object[i] = new Object;

		srand((unsigned)time(NULL));

		float fRandx = rand() % 200;
		float fRandy = rand() % 200;
		float fRandz = 0;

		m_Object[i]->SetPosition(fRandx, fRandy, fRandz);
	}
}


SceneMgr::~SceneMgr()
{
}
