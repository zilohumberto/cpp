//============================================================================
// Name        : 10281.cpp
// Author      : UDONE
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<stdio.h>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	char buffer[1000];
	int n, time = 0, now;
	int hour, min, sec, speed=0, newSpeed;
	double distance=0;
	//esto no lo iba ni a adivinar
	while (cin.getline(buffer, sizeof(buffer))){
		n = sscanf(buffer, "%d:%d:%d %d", &hour, &min, &sec, &newSpeed);
		now = hour * 3600 + min * 60 + sec;

		distance += (now - time) * speed;
		time = now;

		if (n == 3)
			printf("%02d:%02d:%02d %.2lf km\n", hour, min, sec, distance/3600);
		else if (n == 4)
			speed = newSpeed;
	}

	return 0;
}
