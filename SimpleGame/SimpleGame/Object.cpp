#include "stdafx.h"
#include "Object.h"


Object::Object(float x, float y, int type)
{
	srand((unsigned)time(NULL));

	if (type == OBJECT_CHARACTER)
	{
		tagPos.x = x;
		tagPos.y = y;

		v_x = rand() % 5 - 2;
		if (v_x == 0)
			v_x = 1;
		v_y = rand() % 5 - 2;
		if (v_y == 0)
			v_y = -1;
	
		Size = 10;
		Life = 10;
		LifeTime = 1000.0f;
		R = 1.0f;
		G = 1.0f;
		B = 1.0f;
		A = 1.0f;
	}
	else if (type == OBJECT_BUILDING)
	{
		tagPos.x = x;
		tagPos.y = y;

		v_x = 0;
		v_y = 0;
		Size = 50;
		Life = 200;
		R = 1.0f;
		G = 1.0f;
		B = 0.0f;
		A = 1.0f;
	}
	if (type == OBJECT_BULLET)
	{
		
		tagPos.x = x;
		tagPos.y = y;


		v_x = rand() % 5 - 2;
		if (v_x == 0)
			v_x = 1;
		v_y = rand() % 5 - 2;
		if (v_y == 0)
			v_y = -1;
		Size = 2;
		Life = 20;
		LifeTime = 1000.0f;
		R = 1.0f;
		G = 0.0f;
		B = 0.0f;
		A = 1.0f;
	}
	if (type == OBJECT_ARROW)
	{
		
		tagPos.x = x;
		tagPos.y = y;


		v_x = rand() % 5 - 2;
		if (v_x == 0)
			v_x = 0.5;
		v_y = rand() % 5 - 2;
		if (v_y == 0)
			v_y = -0.5;
		Size = 2;
		Life = 10;
		LifeTime = 1000.0f;
		R = 0.0f;
		G = 1.0f;
		B = 0.0f;
		A = 1.0f;
	}
	
}


Object::~Object()
{
}
void Object::Update(float elapsedTime)
{
	float fTime = elapsedTime / 10.0f;


	tagPos.x = tagPos.x + v_x * fTime;
	tagPos.y = tagPos.y + v_y * fTime;
	tagPos.z = tagPos.z;

	LifeTime -= 0.1f;

	if (tagPos.x > 250)
	{
		v_x = -1 * v_x;
	}
	if (tagPos.x < -250)
	{
		v_x = -1 * v_x;
	}
	if (tagPos.y > 250)
	{
		v_y = -1 * v_y;
	}
	if (tagPos.y < -250)
	{
		v_y = -1 * v_y;
	}

}