#include "stdafx.h"
#include "SceneMgr.h"


SceneMgr::SceneMgr(int width, int height)
{
	m_pRenderer = new Renderer(width, height);
	if (!m_pRenderer->IsInitialized())
		{
			std::cout << "Renderer could not be initialized.. \n";
		}
	m_Building[0] = new Object(0, 0, OBJECT_BUILDING);
}

SceneMgr::~SceneMgr()
{
}
bool SceneMgr::CheckCollision(Object* Object1, Object* Object2)
{
	if (Object1->GetPosition().x - Object1->Size/2 <= Object2->GetPosition().x + Object2->Size / 2 && Object1->GetPosition().x + Object1->Size / 2 >= Object2->GetPosition().x - Object2->Size / 2 && Object1->GetPosition().y + Object1->Size / 2 >= Object2->GetPosition().y - Object2->Size / 2 && Object1->GetPosition().y - Object1->Size / 2 <= Object2->GetPosition().y + Object2->Size / 2)
		return true;
	else
		return false;
}
int SceneMgr::AddActorObject(float x, float y, int type)
{
	
	switch (type)
	{
	case OBJECT_CHARACTER:
		for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
		{
			if (m_Object[i] == NULL)
			{
				m_Object[i] = new Object(x, y, type);
				return i;
			}
		}
		return -1;
		break;

	case OBJECT_BULLET:
		for (int i = 0; i < MAX_BULLET_COUNT; ++i)
		{

			if (m_Bullet[i] == NULL)
			{
				m_Bullet[i] = new Object(x, y, type);
				return i;
			}
		}
		return -1;
		break;

	case OBJECT_ARROW:
		for (int i = 0; i < MAX_ARROW_COUNT; ++i)
		{

			if (m_Arrow[i] == NULL)
			{
				m_Arrow[i] = new Object(x, y, type);
				return i;
			}
		}
		return -1;
		break;
	
	}
}
void SceneMgr::DrawScene()
{

	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (m_Object[i] != NULL)
		{
			m_pRenderer->DrawSolidRect(m_Object[i]->GetPosition().x, m_Object[i]->GetPosition().y, m_Object[i]->GetPosition().z, m_Object[i]->Size, m_Object[i]->R, m_Object[i]->G, m_Object[i]->B, m_Object[i]->A);
		}
	}
	
	if(m_Building[0] != NULL)
		m_pRenderer->DrawTexturedRect(m_Building[0]->GetPosition().x, m_Building[0]->GetPosition().y, m_Building[0]->GetPosition().z, m_Building[0]->Size, m_Building[0]->R, m_Building[0]->G, m_Building[0]->B, m_Building[0]->A, m_pRenderer->CreatePngTexture("texture.png"));

	for (int i = 0; i < MAX_BULLET_COUNT; ++i)
	{
		if (m_Bullet[i] != NULL)
		{
			m_pRenderer->DrawSolidRect(m_Bullet[i]->GetPosition().x, m_Bullet[i]->GetPosition().y, m_Bullet[i]->GetPosition().z, m_Bullet[i]->Size, m_Bullet[i]->R, m_Bullet[i]->G, m_Bullet[i]->B, m_Bullet[i]->A);
		}
	}

	for (int i = 0; i < MAX_ARROW_COUNT; ++i)
	{
		if (m_Arrow[i] != NULL)
		{
			m_pRenderer->DrawSolidRect(m_Arrow[i]->GetPosition().x, m_Arrow[i]->GetPosition().y, m_Arrow[i]->GetPosition().z, m_Arrow[i]->Size, m_Arrow[i]->R, m_Arrow[i]->G, m_Arrow[i]->B, m_Arrow[i]->A);
		}
	}

	
	if (m_Building[0]->Life < 0)
	{
		m_Building[0]->SetPosition(350, 350, 350);
	/*	m_Building[0] = NULL;
		delete m_Building[0];*/
	}
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (m_Object[i] != NULL)
		{
			if (m_Object[i]->Life < 0 || m_Object[i]->LifeTime < 0)
			{
				m_Object[i] = NULL;
				delete m_Object[i];

			}
		}
	}
	for (int i = 0; i < MAX_BULLET_COUNT; ++i)
	{
		if (m_Bullet[i] != NULL)
		{
			if (m_Bullet[i]->Life < 0 || m_Bullet[i]->LifeTime < 0)
			{
				m_Bullet[i] = NULL;
				delete m_Bullet[i];

			}
		}
	}
	for (int i = 0; i < MAX_ARROW_COUNT; ++i)
	{
		if (m_Arrow[i] != NULL)
		{
			if (m_Arrow[i]->Life < 0 || m_Arrow[i]->LifeTime < 0)
			{
				m_Arrow[i] = NULL;
				delete m_Arrow[i];

			}
		}
	}

}