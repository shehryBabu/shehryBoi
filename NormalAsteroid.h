
#ifndef _NORMALASTEROID_H_
#define _NORMALASTEROID_H_

#include "Asteroid.h"
#include<string>
#include<cmath>
#include<time.h>
#include<stdio.h>
class NormalAsteroid: public Asteroid
{
private:
		float newX,newY,speed;
		int destroy;
public:
	NormalAsteroid(float x,float y,char s);
	void Move(int i=0);
	//void Destroy();
	//virtual void Draw(ColorNames color=WHITE);
		virtual void setXCo(const float x){xco=x; setSX(xco + float(getRad()) * cos(Deg2Rad(getTheta(9))));}
		virtual void setYCo(const float y){yco=y; setSY(yco + float(getRad()) * sin(Deg2Rad(getTheta(9))));}
		virtual float getXCo()const{return xco;}
		virtual float getYCo()const{return yco;}
		//virtual char getSize(){return size;}
	 virtual ~NormalAsteroid(){cout<<"destructor";}
};


#endif
