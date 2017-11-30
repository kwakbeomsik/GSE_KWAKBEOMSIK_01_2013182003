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


SceneMgr* pSceneMgr = NULL;
DWORD PreviousTime = 0;
bool PlayerRespawn = true;
float PlayerRespawnTime = 0.0f;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	DWORD CurrentTime = timeGetTime();

	DWORD elapsedTime = CurrentTime - PreviousTime;
	PreviousTime = CurrentTime;
	
	pSceneMgr->UpdateAllObject(float(elapsedTime));
	pSceneMgr->DrawScene();
	pSceneMgr->Collision();
	
	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if ((float((y - 400)*-1) <= 0) && pSceneMgr->PlayerRespawn())
		{
				pSceneMgr->AddActorObject(float(x - 250), float((y - 400)*-1), OBJECT_CHARACTER, PLAYER);
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
	glutInitWindowSize(500, 800);
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

	pSceneMgr = new SceneMgr(500, 800);

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
