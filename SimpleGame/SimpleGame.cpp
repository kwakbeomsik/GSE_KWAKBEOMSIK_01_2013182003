/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"


#include "Renderer.h"

Renderer *g_Renderer = NULL;
SceneMgr* pSceneMgr = new SceneMgr;
int  iCount = 0;
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		g_Renderer->DrawSolidRect(pSceneMgr->m_Object[i]->GetPosition().x, pSceneMgr->m_Object[i]->GetPosition().y, pSceneMgr->m_Object[i]->GetPosition().z, 5, 1, 1, 1, 1);
		g_Renderer->DrawSolidRect(pSceneMgr->m_Bullet[i]->GetPosition().x, pSceneMgr->m_Bullet[i]->GetPosition().y, pSceneMgr->m_Bullet[i]->GetPosition().z, 2, 1, 0, 0, 1);

	}
	
	g_Renderer->DrawSolidRect(pSceneMgr->m_Build->GetPosition().x, pSceneMgr->m_Build->GetPosition().y, pSceneMgr->m_Build->GetPosition().z, 50, 1, 1, 0, 0);
	
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		if (pSceneMgr->CheckCollision(pSceneMgr->m_Object[i], pSceneMgr->m_Build) == true)
		{
			//delete pSceneMgr->m_Object[i];
			pSceneMgr->m_Object[i]->SetPosition(0, 0, 0);
		}
		for (int j = 0; j < MAX_OBJECTS_COUNT; ++j)
		{
			if (pSceneMgr->CheckCollision(pSceneMgr->m_Object[i], pSceneMgr->m_Bullet[j]) == true)
			{
				pSceneMgr->m_Object[i]->SetPosition(0, 0, 0);
				//delete pSceneMgr->m_Object[i];
			}
		}


	}


	
	glutSwapBuffers();
}

void Idle(void)
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		pSceneMgr->m_Object[i]->Update();
		pSceneMgr->m_Bullet[i]->Update();
	}

	RenderScene();

}

void MouseInput(int button, int state, int x, int y)
{
	
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			pSceneMgr->m_Object[iCount]->SetPosition(x-250, (y-250)*-1, 0);
			++iCount;
			if (iCount == 10)
				iCount = 0;
		}
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

	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);
	
	glutMainLoop();

	delete g_Renderer;
	
    return 0;
}

