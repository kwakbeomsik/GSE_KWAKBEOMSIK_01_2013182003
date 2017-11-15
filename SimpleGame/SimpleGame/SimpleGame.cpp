/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "SceneMgr.h"

DWORD PreviousTime = 0;

SceneMgr* pSceneMgr = NULL;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);




	pSceneMgr->DrawScene();
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{

		if (pSceneMgr->m_Object[i] != NULL && pSceneMgr->m_Building[0] != NULL)
		{

			if (pSceneMgr->CheckCollision(pSceneMgr->m_Object[i], pSceneMgr->m_Building[0]))
			{
				//pSceneMgr->m_Object[i]->Life = pSceneMgr->m_Object[i]->Life - pSceneMgr->m_Building[0]->Life;
				//pSceneMgr->m_Building[0]->Life = pSceneMgr->m_Building[0]->Life - pSceneMgr->m_Object[i]->Life;
				pSceneMgr->m_Building[0]->Life -= 20.0f;
				pSceneMgr->m_Object[i]->Life -= 200.0f;
			}
		}
	}

	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		for (int j = 0; j < MAX_BULLET_COUNT; ++j)
		{
			if (pSceneMgr->m_Object[i] != NULL && pSceneMgr->m_Bullet[j] != NULL)
			{
			
				if (pSceneMgr->CheckCollision(pSceneMgr->m_Object[i], pSceneMgr->m_Bullet[j]))
				{
					pSceneMgr->m_Bullet[j]->Life -= 20.0f;
					pSceneMgr->m_Object[i]->Life -= 20.0f;
				}
			}
		}
	}
	///////////////////
	for (int i = 0; i < MAX_ARROW_COUNT; ++i)
	{
		if (pSceneMgr->m_Arrow[i] != NULL && pSceneMgr->m_Building[0] != NULL)
		{

			if (pSceneMgr->CheckCollision(pSceneMgr->m_Arrow[i], pSceneMgr->m_Building[0]))
			{
				//pSceneMgr->m_Object[i]->Life = pSceneMgr->m_Object[i]->Life - pSceneMgr->m_Building[0]->Life;
				//pSceneMgr->m_Building[0]->Life = pSceneMgr->m_Building[0]->Life - pSceneMgr->m_Object[i]->Life;
				pSceneMgr->m_Building[0]->Life -= 20.0f;
				pSceneMgr->m_Arrow[i]->Life -= 200.0f;
			}
		}
	}

	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		for (int j = 0; j < MAX_ARROW_COUNT; ++j)
		{
			if (pSceneMgr->m_Object[i] != NULL && pSceneMgr->m_Arrow[j] != NULL)
			{

				if (pSceneMgr->CheckCollision(pSceneMgr->m_Object[i], pSceneMgr->m_Arrow[j]))
				{
					//pSceneMgr->m_Arrow[j]->Life -= 10.0f;
					//pSceneMgr->m_Object[i]->Life -= 5.0f;
				}
			}
		}
	}
	


	glutSwapBuffers();
}

void Idle(void)
{

	DWORD CurrentTime = timeGetTime();
	
	DWORD elapsedTime = CurrentTime - PreviousTime;
	PreviousTime = CurrentTime;


	if ((CurrentTime % 800) == 0)
		pSceneMgr->AddActorObject(0, 0, OBJECT_BULLET);

		for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
		{
			if(pSceneMgr->m_Object[i] != NULL)
				if ((CurrentTime % 2000) == 0)
				{
					pSceneMgr->AddActorObject(pSceneMgr->m_Object[i]->GetPosition().x, pSceneMgr->m_Object[i]->GetPosition().y, OBJECT_ARROW);
				}
		}



	
	
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if(pSceneMgr->m_Object[i] != NULL)
			pSceneMgr->m_Object[i]->Update((float)elapsedTime);
		if (pSceneMgr->m_Bullet[i] != NULL)
			pSceneMgr->m_Bullet[i]->Update((float)elapsedTime);
		if (pSceneMgr->m_Arrow[i] != NULL)
			pSceneMgr->m_Arrow[i]->Update((float)elapsedTime);
	}
	if (pSceneMgr->m_Building[0] != NULL)
	{
		pSceneMgr->m_Building[0]->Update((float)elapsedTime);
	}


	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		pSceneMgr->AddActorObject(float(x - 250), float((y - 250)*-1), OBJECT_CHARACTER);
		
	}

	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	pSceneMgr = new SceneMgr(500, 500);

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	PreviousTime = timeGetTime();


	glutMainLoop();


	pSceneMgr = NULL;
	delete pSceneMgr;

    return 0;
}

