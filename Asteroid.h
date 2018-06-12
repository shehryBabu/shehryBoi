

#ifndef _ASTEROID_H_
#define _ASTEROID_H_
#include "Base.h"
#include<string>
#include<cmath>
#include<time.h>
#include<stdio.h>
#include<cstdlib>
#include<ctime>

using namespace std;

class Asteroid : virtual public Base
{
private:
		char size;
		float theta[10],sx,sy,rad,npoints,dtheta;
		int destroy;
		
public:
		static int seed;
		Asteroid(float x,float y,char si,float r=50);
		void behind(const int corners=5,ColorNames color=WHITE);
		virtual void Draw(ColorNames color=WHITE);
		virtual void setXCo(const float x);
		virtual void setYCo(const float y);
		virtual float getXCo()const{return xco;}
		virtual float getYCo()const{return yco;}
		float getSX()const{return sx;}
		float getSY()const{return sy;}
		void setSX(const float x);
		void setSY(const float y);
		char getSize()const{return size;}
		virtual void Move(int i=0)=0;
		float getRad()const{return rad;}
		float getTheta(int i);
		virtual void Thrust(){}
		void Destroy(){destroy=1;}
		int getDestroy(){return destroy;}
		//virtual void SPLIT(){cout<<"hekllo"<<endl;}
		void MidCheck();
		virtual ~Asteroid(){}
};
#endif 
