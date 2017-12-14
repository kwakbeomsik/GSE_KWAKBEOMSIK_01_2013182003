#include "stdafx.h"
#include "Object.h"


Object::Object(float x, float y, int type, int team)
{
	
	if (type == OBJECT_CHARACTER)
	{
		Type = OBJECT_CHARACTER;
		tagPos.x = x;
		tagPos.y = y;

		v_x = 300 * (rand() % 21 - 10) * 0.1f;
		v_y = 300 * (rand() % 21 - 10) * 0.1f;
		
	//	v_x = 300 * (rand() % 3 - 1) * 0.1f;
	//	v_y = 300 * (rand() % 3 - 1) * 0.1f;



		if (v_y == 0 && v_x == 0)
			v_y = 300 * 0.1f;
	
		Size = 60;
		Life = 100.0f;
		LifeTime = 1000.0f;
		Gauge = Life / 100.0f;
		if (team == PLAYER)
		{
			R = 0.0f;
			G = 0.0f;
			B = 1.0f;
			A = 1.0f;
			Team = PLAYER;
		}
		else if (team == ENEMY)
		{
			R = 1.0f;
			G = 0.0f;
			B = 0.0f;
			A = 1.0f;
			Team = ENEMY;
		}
	}
	else if (type == OBJECT_BUILDING)
	{
		Type = OBJECT_BUILDING;
		tagPos.x = x;
		tagPos.y = y;

		v_x = 0;
		v_y = 0;
		Size = 100;
		Life = 500.0f;
		LastBullet = 0.0f;
		LastArrow = 0.0f;
		Gauge = Life / 500.0f;
		if (team == PLAYER)
		{
			R = 0.0f;
			G = 0.0f;
			B = 1.0f;
			A = 1.0f;
			Team = PLAYER;
		}
		else if (team == ENEMY)
		{
			R = 1.0f;
			G = 0.0f;
			B = 0.0f;
			A = 1.0f;
			Team = ENEMY;
		}
	}
	if (type == OBJECT_BULLET)
	{
		Type = OBJECT_BULLET;
		tagPos.x = x;
		tagPos.y = y;

		Size = 6;
		Life = 15;
		LifeTime = 1000.0f;
		if (team == PLAYER)
		{
			R = 0.0f;
			G = 0.0f;
			B = 1.0f;
			A = 1.0f;
			Team = PLAYER;
			Particletime = 0.0f;
			/*v_x = 600 * (rand() % 3 - 1) * 0.1f;
			v_y = 600 * (rand() % 2) * 0.1f;*/
			v_x = 600 * (rand() % 21 - 10) * 0.1f;
			v_y = 600 * (rand() % 10) * 0.1f;
			
			if (v_y == 0 && v_x == 0)
				v_y = 600 * 0.1f;
			if (v_y == 0)
				v_y = 600 * 0.1f;
		}
		else if (team == ENEMY)
		{
			R = 1.0f;
			G = 0.0f;
			B = 0.0f;
			A = 1.0f;
			Team = ENEMY;
		//	v_x = 600 * (rand() % 3 - 1) * 0.1f;
		//	v_y = -600 * ((rand() % 2) * 0.1f);
			v_x = 600 * (rand() % 21 - 10) * 0.1f;
			v_y = -600 * (rand() % 10) * 0.1f;

			if (v_y == 0 && v_x == 0)
				v_y = -600 * 0.1f;
			if (v_y == 0)
				v_y = -600 * 0.1;
		}
	}
	if (type == OBJECT_ARROW)
	{
		Type = OBJECT_ARROW;
		tagPos.x = x;
		tagPos.y = y;


		//v_x = 100 * (rand() % 3 - 1) * 0.1f;
		//v_y = 100 * (rand() % 3 - 1) * 0.1f;
		v_x = 100 * (rand() % 21 - 10) * 0.1f;
		v_y = 100 * (rand() % 21 - 10) * 0.1f;

		if (v_y == 0 && v_x == 0)
			v_y = 100 * 0.1f;
		Size = 6;
		Life = 10;
		LifeTime = 1000.0f;
		if (team == PLAYER)
		{
			R = 0.5f;
			G = 0.2f;
			B = 0.7f;
			A = 1.0f;
			Team = PLAYER;
		}
		else if (team == ENEMY)
		{
			R = 1.0f;
			G = 1.0f;
			B = 0.0f;
			A = 1.0f;
			Team = ENEMY;
		}
	}
	
}

Object::~Object()
{
}
void Object::Update(float elapsedTime)
{
	float fTime = elapsedTime / 1000.0f;


	tagPos.x = tagPos.x + v_x * fTime;
	tagPos.y = tagPos.y + v_y * fTime;
	tagPos.z = tagPos.z;

	LastBullet += fTime;
	LastArrow += fTime;
	PlayerRespawnTime += fTime;
	EnemyRespawnTime += fTime;

	LifeTime -= fTime;
	if(Type == OBJECT_CHARACTER)
	{
		if (tagPos.x > 250)
		{
			v_x = -1 * v_x;
		}
		if (tagPos.x < -250)
		{
			v_x = -1 * v_x;
		}
		if (tagPos.y > 400)
		{
			v_y = -1 * v_y;
		}
		if (tagPos.y < -400)
		{
			v_y = -1 * v_y;
		}
	}
	else if (Type == OBJECT_BULLET || Type == OBJECT_ARROW)
	{
		if (tagPos.x > 250)
		{
			Life = 0;
		}
		if (tagPos.x < -250)
		{
			Life = 0;
		}
		if (tagPos.y > 400)
		{
			Life = 0;
		}
		if (tagPos.y < -400)
		{
			Life = 0;
		}
	}

}