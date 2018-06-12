#ifndef _SAUCER_H_
#define _SAUCER_H_

#include<iostream>
#include<string>
#include<cmath>
#include "util.h"
#include "Base.h"

class Saucer: public Base
{
	private:
		float colx1,colx2,colx3,colx4,coly1,coly2,coly3,coly4,newX,newY;
		int bulletShoot;
		static int seed;
		bool dead;
	public:
		Saucer(float x,float y);
		void Draw(ColorNames colors=WHITE);
		float Colx1()const{return colx1;}
		float Coly1()const{return coly1;}
		float Colx2()const{return colx2;}
		float Coly2()const{return coly2;}
		float Colx3()const{return colx3;}
		float Coly3()const{return coly3;}
		float Colx4()const{return colx4;}
		float Coly4()const{return coly4;}
		virtual void setXCo(const float x){xco=x;}
		virtual void setYCo(const float y){yco=y;}
		virtual float getXCo()const{return (colx1+colx2)/2;};
		virtual float getYCo()const{return (coly1+coly2)/2;}
		virtual bool collision(float xx,float yy,float rad);
		void DrawRect();
		void Move(int i=0);
		void Destroy();
		bool Shoot();
		float getDx();
		float getDy();
};
#endif
