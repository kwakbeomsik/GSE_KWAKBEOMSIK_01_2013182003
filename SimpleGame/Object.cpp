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
	float Time = 0.3;

	tagPos.x = tagPos.x + v_x * Time;
	tagPos.y = tagPos.y;
	tagPos.z = tagPos.z;


	if (tagPos.x > 250)
	{
		v_x = -1 * v_x;
	}
	if (tagPos.x < -250)
	{
		v_x = -1 * v_x;
	}
	

}