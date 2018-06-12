
#ifndef _BULLET_H_
#define _BULLET_H_

#include "util.h"
#include "Base.h"
#include<iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

class Bullet : public Base
{
	private:
			float dx,dy;
			float Travelx,Travely;
			int sswitch;
			int attack;
			bool bulletAttack;
	public:
			Bullet( int s=1);
			void Shoot(float x,float y,float ddx,float ddy);
			int good();
			void Move(int i=0){}
			virtual void Draw(ColorNames colors=WHITE);
			void setXY(const float x,const float y,const float dd,const float de){xco=x;yco=y;this->dx=dd;this->dy=de;}
			virtual float getXCo()const{return xco;}
			virtual float getYCo()const{return yco;}
			virtual void setXCo(const float x){xco=x;}
			virtual void setYCo(const float y){yco=y;}
			virtual void Thrust(){}
			virtual int getAttack();
			virtual void Attack();
			bool BulletAttack();
			bool collision(float xx,float yy,float rad);
			void Destroy();
			virtual ~Bullet(){}
			//void Update(float x,float y);
};
#endif
