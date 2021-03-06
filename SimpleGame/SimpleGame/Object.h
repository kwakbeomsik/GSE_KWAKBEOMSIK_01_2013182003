#pragma once

struct Pos
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};
class Object
{
private:
	Pos tagPos;
public:
	float v_x = 1.0f;
	float v_y = 1.0f;
	float v_z = 0.0f;

	float Life;
	float LifeTime;
	float Size;
	float R;
	float G;
	float B;
	float A;
	int Type;
	int Team;
	float LastBullet;
	float LastArrow;
	float EnemyRespawnTime = 5.0f;
	float PlayerRespawnTime = 7.0f;
	float Gauge;
	float Particletime;

public:
	Pos GetPosition() { return tagPos; };
	void SetPosition(float x, float y, float z) { tagPos.x = x, tagPos.y = y, tagPos.z = z; }
	void Update(float elapsedTime);
	
public:
	Object(float x, float y, int type, int team);
	~Object();
};

