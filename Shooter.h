
#ifndef _SHOOTER_H_
#define _SHOOTER_H_

#include "util.h"
#include <iostream>
#include "Bullet.h"
#include "Saucer.h"
#include<string>
#include<cmath>
 // for basic math functions such as cos, sin, sqrt
using namespace std;

class Shooter :public Base
{
	private:
			float x1,y1,x2,y2,x3,y3,x5,y5,x6,y6,angle,factor;
			static float boost;
			int shoot;
			//Bullet bullet;
			int const num;
			bool alive;
			//Split **ss;
			static int menu,ind;
			static int sec,saucerEntry;
			static int Score;
			//int lives;
			static int immune,enough;
	public:
			
			Shooter(float x,float y);
			void Draw(ColorNames color=WHITE);
			virtual void Move(int i=0);
			float getXco()const;
			float getYco()const;
			void setXco(const float x);
			void setYco(const float y);
			void Thrust();
			float CosA(float x,float y);
			float SinA(float x,float y);
			//void Shoot();
			void Rect();
			bool collision(float xx,float yy,float rad);
			void Destroy();
		//	int getLives()const{return lives;}
			//bool Alive(float x,float y,float r,int t,int k);
			//void bulletCollision(float x,float y,float xx,float yy,float rad,int k,int t);
			void Menu();
			int getMenu();
			
			//void Salive(float xx,float yy,float x,float y, float rad,int i,int k);
			void setSEntry(const int i);
			int getSEntry()const;
			virtual float getXCo()const{return x1;}
			virtual float getYCo()const{return y1;}
			virtual void setXCo(const float x){xco=x;}
			virtual void setYCo(const float y){yco=y;}
		//	void DrawLives();
			//void setLives(const int l){lives=l;}
			virtual ~Shooter(){}
};

#endif
