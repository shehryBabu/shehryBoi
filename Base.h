
#ifndef _BASE_H_
#define _BASE_H_

#include<iostream>
#include "util.h"

class Base
{
	protected:
			float xco,yco,dx,dy;
	public:
		Base(float x=512,float y=420);
		virtual void setXCo(const float x)=0;
		virtual void setYCo(const float y)=0;
		virtual float getXCo()const=0;
		virtual float getYCo()const=0;
		virtual float getRad()const{};
		virtual void Draw(ColorNames colors=WHITE)=0;
		virtual void Move(int i=0)=0;
		virtual void Thrust(){};
		virtual void Shoot(float x,float y,float ddx,float ddy){};
		virtual bool collision(float xx,float yy,float rad){};
		virtual float getDx(){return dx;}
		virtual float getDy(){return dy;}
		virtual int getAttack(){};
		virtual bool BulletAttack(){};
		virtual void Attack(){};
		virtual void Destroy(){};
		virtual char getSize()const{};
		virtual bool Shoot(){};
		//virtual void setLives(const int l){}
		//virtual int getLives()const{}
		virtual ~Base(){}
			
	
};
#endif
