
#ifndef _COMPLEXASTEROID_H_
#define _COMPLEXASTEROID_H_

#include "Asteroid.h"
#include<string>
#include<cmath>
#include<time.h>
#include<stdio.h>

class complexAsteroid: public Asteroid
{
private:
		float newX,newY,speed;
		int sec;
public:
	complexAsteroid(float x,float y,char s='m');
	virtual void Move(int i=0);
	//virtual void SPLIT(); 
	void changeDir();
	void setSec(const int i){sec=i;}
	int getSec()const{return sec;}
};


#endif
