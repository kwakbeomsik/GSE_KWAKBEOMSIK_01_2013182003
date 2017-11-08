#include "stdafx.h"
#include "Object.h"


Object::Object()
{
}
Object::~Object()
{
}
void Object::Update()
{
	float Time = 0.03f;


	tagPos.x = tagPos.x + v_x * Time;
	tagPos.y = tagPos.y + v_y * Time;
	tagPos.z = tagPos.z;


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
