#pragma once
#include<stdio.h>

struct Point
{
	int xpos;
	int ypos;
};

void SetPointPos(Point* ppos, int xpos, int ypos);
void ShowPointPos(Point* ppos);

int PointComp(Point* pos1, Point* pos2);

