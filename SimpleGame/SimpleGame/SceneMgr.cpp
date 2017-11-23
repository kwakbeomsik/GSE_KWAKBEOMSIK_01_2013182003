#include "stdafx.h"
#include "SceneMgr.h"


SceneMgr::SceneMgr(int width, int height)
{
	m_pRenderer = new Renderer(width, height);
	if (!m_pRenderer->IsInitialized())
		{
			std::cout << "Renderer could not be initialized.. \n";
		}

	m_Building[0] = new Object(0, -300, OBJECT_BUILDING, PLAYER);
	m_Building[1] = new Object(-200, -300, OBJECT_BUILDING, PLAYER);
	m_Building[2] = new Object(200, -300, OBJECT_BUILDING, PLAYER);
	m_Building[3] = new Object(0, 300, OBJECT_BUILDING, ENEMY);
	m_Building[4] = new Object(-200, 300, OBJECT_BUILDING, ENEMY);
	m_Building[5] = new Object(200, 300, OBJECT_BUILDING, ENEMY);

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
int SceneMgr::AddActorObject(float x, float y, int type, int team)
{
	switch (type)
	{
	case OBJECT_CHARACTER:
		for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
		{
			if (m_Object[i] == NULL)
			{
				m_Object[i] = new Object(x, y, type , team);
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
				m_Bullet[i] = new Object(x, y, type, team);
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
				m_Arrow[i] = new Object(x, y, type, team);
				return i;
			}
		}
		return -1;
		break;
	
	}
}
void SceneMgr::DrawScene()
{
	//오브젝트 그려주기
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (m_Object[i] != NULL)
		{
			m_pRenderer->DrawSolidRect(m_Object[i]->GetPosition().x, m_Object[i]->GetPosition().y, m_Object[i]->GetPosition().z, m_Object[i]->Size, m_Object[i]->R, m_Object[i]->G, m_Object[i]->B, m_Object[i]->A, LEVEL_GROUND);
			m_pRenderer->DrawSolidRectGauge(m_Object[i]->GetPosition().x, m_Object[i]->GetPosition().y + 20.0f, m_Object[i]->GetPosition().z, 30.0f, 3.0f, m_Object[i]->R, m_Object[i]->G, m_Object[i]->B, m_Object[i]->A, m_Object[i]->Gauge, LEVEL_GROUND);
		
		}
	}
	//빌딩 그려주기

	//플레이어
	for (int i = 0; i < MAX_BUILDING_COUNT - 3; ++i)
	{
		if (m_Building[i] != NULL)
		{
			m_pRenderer->DrawTexturedRect(m_Building[i]->GetPosition().x, m_Building[i]->GetPosition().y, m_Building[i]->GetPosition().z, m_Building[i]->Size, m_Building[i]->R, m_Building[i]->G, m_Building[i]->B, m_Building[i]->A, m_pRenderer->CreatePngTexture("texture.png"), LEVEL_SKY);
			m_pRenderer->DrawSolidRectGauge(m_Building[i]->GetPosition().x, m_Building[i]->GetPosition().y + 60.0f, m_Building[i]->GetPosition().z, 100.0f, 3.0f, m_Building[i]->R, m_Building[i]->G, m_Building[i]->B, m_Building[i]->A, m_Building[i]->Gauge, LEVEL_GROUND);
			
		}

	}
	//적
	for (int i = MAX_BUILDING_COUNT - 3; i < MAX_BUILDING_COUNT; ++i)
	{
		if (m_Building[i] != NULL)
		{
			m_pRenderer->DrawTexturedRect(m_Building[i]->GetPosition().x, m_Building[i]->GetPosition().y, m_Building[i]->GetPosition().z, m_Building[i]->Size, m_Building[i]->R, m_Building[i]->G, m_Building[i]->B, m_Building[i]->A, m_pRenderer->CreatePngTexture("texture2.png"), LEVEL_SKY);
			m_pRenderer->DrawSolidRectGauge(m_Building[i]->GetPosition().x, m_Building[i]->GetPosition().y + 60.0f, m_Building[i]->GetPosition().z, 100.0f, 3.0f, m_Building[i]->R, m_Building[i]->G, m_Building[i]->B, m_Building[i]->A, m_Building[i]->Gauge, LEVEL_GROUND);
		}
	
	}

	//총알 그려주기
	for (int i = 0; i < MAX_BULLET_COUNT; ++i)
	{
		if (m_Bullet[i] != NULL)
		{
			m_pRenderer->DrawSolidRect(m_Bullet[i]->GetPosition().x, m_Bullet[i]->GetPosition().y, m_Bullet[i]->GetPosition().z, m_Bullet[i]->Size, m_Bullet[i]->R, m_Bullet[i]->G, m_Bullet[i]->B, m_Bullet[i]->A, LEVEL_UNDERGROUND);
		}
	}

	//화살 그려주기
	for (int i = 0; i < MAX_ARROW_COUNT; ++i)
	{
		if (m_Arrow[i] != NULL)
		{
			m_pRenderer->DrawSolidRect(m_Arrow[i]->GetPosition().x, m_Arrow[i]->GetPosition().y, m_Arrow[i]->GetPosition().z, m_Arrow[i]->Size, m_Arrow[i]->R, m_Arrow[i]->G, m_Arrow[i]->B, m_Arrow[i]->A, LEVEL_UNDERGROUND);
		}
	}

	// 빌딩 삭제
	for (int i = 0; i < MAX_BUILDING_COUNT; ++i)
	{
		if (m_Building[i]->Life <= 0)
		{
			m_Building[i]->SetPosition(500, 500, 350);
		/*	m_Building[0] = NULL;
			delete m_Building[0];*/
		}
	}
	// 오브젝트 삭제
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (m_Object[i] != NULL)
		{
			if (m_Object[i]->Life <= 0 || m_Object[i]->LifeTime < 0)
			{
				m_Object[i] = NULL;
				delete m_Object[i];
			}
		}
	}
	// 총알 삭제
	for (int i = 0; i < MAX_BULLET_COUNT; ++i)
	{
		if (m_Bullet[i] != NULL)
		{
			if (m_Bullet[i]->Life <= 0 || m_Bullet[i]->LifeTime < 0)
			{
				m_Bullet[i] = NULL;
				delete m_Bullet[i];

			}
		}
	}
	// 화살 삭제
	for (int i = 0; i < MAX_ARROW_COUNT; ++i)
	{
		if (m_Arrow[i] != NULL)
		{
			if (m_Arrow[i]->Life <= 0 || m_Arrow[i]->LifeTime < 0)
			{
				m_Arrow[i] = NULL;
				delete m_Arrow[i];

			}
		}
	}
}
// 충돌 처리
void SceneMgr::Collision()
{
	// 오브젝와 빌딩 충돌처리
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		for (int j = 0; j < MAX_BUILDING_COUNT; ++j)
		{
			if (m_Object[i] != NULL && m_Building[j] != NULL)
			{
				if (CheckCollision(m_Object[i], m_Building[j]) && m_Object[i]->Team != m_Building[j]->Team)
				{
					//m_Object[i]->Life = m_Object[i]->Life - m_Building[j]->Life;
					//m_Building[j]->Life = m_Building[j]->Life - m_Object[i]->Life;
				    m_Building[j]->Life -= 100.0f;
					m_Object[i]->Life -= 500.0f;
				}
			}
		}
	}
	//오브젝트와 총알 충돌처리
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		for (int j = 0; j < MAX_BULLET_COUNT; ++j)
		{
			if (m_Object[i] != NULL && m_Bullet[j] != NULL)
			{

				if (CheckCollision(m_Object[i], m_Bullet[j]) && m_Object[i]->Team != m_Bullet[j]->Team)
				{
					m_Bullet[j]->Life -= 100.0f;
					m_Object[i]->Life -= 15.0f;
				}
			}
		}
	}
	//화살과 빌딩 충돌처리
	for (int i = 0; i < MAX_ARROW_COUNT; ++i)
	{
		for (int j = 0; j < MAX_BUILDING_COUNT; ++j)
		{
			if (m_Arrow[i] != NULL && m_Building[j] != NULL)
			{

				if (CheckCollision(m_Arrow[i], m_Building[j]) && m_Arrow[i]->Team != m_Building[j]->Team)
				{
					//pSceneMgr->m_Object[i]->Life = pSceneMgr->m_Object[i]->Life - pSceneMgr->m_Building[0]->Life;
					//pSceneMgr->m_Building[0]->Life = pSceneMgr->m_Building[0]->Life - pSceneMgr->m_Object[i]->Life;
					m_Building[j]->Life -= 10.0f;
					m_Arrow[i]->Life -= 500.0f;
				}
			}
		}
	}
	//총알과 빌딩 충돌처리
	for (int i = 0; i < MAX_BULLET_COUNT; ++i)
	{
		for (int j = 0; j < MAX_BUILDING_COUNT; ++j)
		{
			if (m_Bullet[i] != NULL && m_Building[j] != NULL)
			{

				if (CheckCollision(m_Bullet[i], m_Building[j]) && m_Bullet[i]->Team != m_Building[j]->Team)
				{
					//pSceneMgr->m_Object[i]->Life = pSceneMgr->m_Object[i]->Life - pSceneMgr->m_Building[0]->Life;
					//pSceneMgr->m_Building[0]->Life = pSceneMgr->m_Building[0]->Life - pSceneMgr->m_Object[i]->Life;
					m_Building[j]->Life -= 15.0f;
					m_Bullet[i]->Life -= 500.0f;
				}
			}
		}
	}
	//화살과 오브젝트 충돌처리
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		for (int j = 0; j < MAX_ARROW_COUNT; ++j)
		{
			if (m_Object[i] != NULL && m_Arrow[j] != NULL)
			{

				if (CheckCollision(m_Object[i], m_Arrow[j]) && m_Object[i]->Team != m_Arrow[j]->Team)
				{
					m_Arrow[j]->Life -= 100.0f;
					m_Object[i]->Life -= 10.0f;
				}
			}
		}
	}
	////오브젝트와 오브젝트 충돌처리
	//for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	//{
	//	for (int j = 0; j < MAX_OBJECT_COUNT; ++j)
	//	{
	//		if (m_Object[i] != NULL && m_Object[j] != NULL)
	//		{

	//			if (CheckCollision(m_Object[i], m_Object[j]) && m_Object[i]->Team != m_Object[j]->Team)
	//			{
	//				m_Object[j]->Life -= 10.0f;
	//				m_Object[i]->Life -= 10.0f;
	//			}
	//		}
	//	}
	//}


}
void SceneMgr::UpdateAllObject(float elapsedTime)
{
	
	
	// 총알 생성
	for (int i = 0; i < MAX_BUILDING_COUNT; ++i)
	{
		if (m_Building[i]->Team == PLAYER)
		{
			if (m_Building[i]->LastBullet > 5.0f)
			{
				AddActorObject(m_Building[i]->GetPosition().x, m_Building[i]->GetPosition().y, OBJECT_BULLET, PLAYER);
				m_Building[i]->LastBullet = 0.0f;
			}
		}
		else if (m_Building[i]->Team == ENEMY)
		{
			if (m_Building[i]->LastBullet > 10.0f)
			{
				AddActorObject(m_Building[i]->GetPosition().x, m_Building[i]->GetPosition().y, OBJECT_BULLET, ENEMY);
				m_Building[i]->LastBullet = 0.0f;
			}

		}
	}
	// 화살 생성
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (m_Object[i] != NULL)
		{
			if (m_Object[i]->Team == PLAYER)
			{
				if (m_Object[i]->LastArrow > 3.0f)
				{
					AddActorObject(m_Object[i]->GetPosition().x, m_Object[i]->GetPosition().y, OBJECT_ARROW, PLAYER);
					m_Object[i]->LastArrow = 0.0f;
				}
			}
			else if (m_Object[i]->Team == ENEMY)
			{
				if (m_Object[i]->LastArrow > 3.0f)
				{
					AddActorObject(m_Object[i]->GetPosition().x, m_Object[i]->GetPosition().y, OBJECT_ARROW, ENEMY);
					m_Object[i]->LastArrow = 0.0f;
				}
			}
		}
	}
	//적 오브젝트 생성
	float EnemyObjectX = float(rand() % 501 - 250);
	float EnemyObjectY = float(rand() % 400);


	if (m_Building[0]->EnemyRespawnTime > 3.0f)
	{
		AddActorObject(EnemyObjectX, EnemyObjectY, OBJECT_CHARACTER, ENEMY);
		m_Building[0]->EnemyRespawnTime = 0.0f;
	}
	
	
	EnemyRespawnTime += elapsedTime;
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (m_Object[i] != NULL)
			m_Object[i]->Update((float)elapsedTime);
	}
	for (int i = 0; i < MAX_BULLET_COUNT; ++i)
	{
		if (m_Bullet[i] != NULL)
			m_Bullet[i]->Update((float)elapsedTime);
	}
	for (int i = 0; i < MAX_ARROW_COUNT; ++i)
	{
		if (m_Arrow[i] != NULL)
			m_Arrow[i]->Update((float)elapsedTime);
	}
	for (int i = 0; i < MAX_BUILDING_COUNT; ++i)
	{
		if (m_Building[i] != NULL)
			m_Building[i]->Update((float)elapsedTime);
	}

}
bool SceneMgr::PlayerRespawn()
{
	if (m_Building[0]->PlayerRespawnTime > 3.0f)
	{
		m_Building[0]->PlayerRespawnTime = 0.0f;
		return true;
	}
	else
		return false;
}