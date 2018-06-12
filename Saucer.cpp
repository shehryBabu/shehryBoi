#include "Saucer.h"
int Saucer::seed=4654;
Saucer::Saucer(float x,float y): Base(x,y)
{
	
		float x1,y1,x2,y2,x3,y3,x4,y4/*,x5,y5,x6,y6,x7,y7,x8,y8*/;
	x1=xco-30;y1=yco;x2=xco+30;y2=yco;x3=x2;y3=yco-20;x4=x1;y4=y3;
	//x5=sx-15;y5=sy;x6=sx+15;y6=sy;x7=x6;y7=sy+15;x8=x5;y8=y7;
	colx1=x3;colx2=x4;colx3=x4;colx4=x3;coly1=y3;coly2=y4;coly3=y4+35;coly4=y3+35;
	srand(seed);
	seed+=546;
	newX=rand()%1024;
	newY=rand()%840;
	bulletShoot=0;
	dead=false;
}
void Saucer::Draw(ColorNames color)
{
	if(dead==false)
	{
		float x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8;
		x1=xco-30;y1=yco;x2=xco+30;y2=yco;x3=x2;y3=yco-20;x4=x1;y4=y3;
		x5=xco-15;y5=yco;x6=xco+15;y6=yco;x7=x6;y7=yco+15;x8=x5;y8=y7;
		colx1=x3;colx2=x4;colx3=x4;colx4=x3;coly1=y3;coly2=y4;coly3=y4+35;coly4=y3+35;
		DrawLine(x1,y1,x2,y2,1,colors[WHITE]);
		DrawLine(x2,y2,x3,y3,1,colors[WHITE]);
		DrawLine(x3,y3,x4,y4,1,colors[WHITE]);
		DrawLine(x4,y4,x1,y1,1,colors[WHITE]);
		DrawLine(x5,y5,x6,y6,1,colors[WHITE]);
		DrawLine(x6,y6,x7,y7,1,colors[WHITE]);
		DrawLine(x7,y7,x8,y8,1,colors[WHITE]);
		DrawLine(x8,y8,x5,y5,1,colors[WHITE]);
		bulletShoot++;
		//DrawRect();
	}
	else
	{
		colx1=colx2=colx3=colx4=coly1=coly2=coly3=coly4=-80;
	}
	if(xco<=-40 && dx<0)
	{
		xco=1040;
	}
		
	if(yco>=870 && dy>=0)
	{
		yco=-40;
		
	}
	
	if(xco>=1040 && dx>=0)
	{
		xco=-40;
	}
	
	if(yco<=-40 && dy<0)
	{
		yco=870;
	}
}
void Saucer::DrawRect()
{
	DrawLine(Colx1(),Coly1(),Colx2(),Coly2(),3,colors[RED]);
	DrawLine(Colx2(),Coly2(),Colx3(),Coly3(),3,colors[RED]);
	DrawLine(Colx3(),Coly3(),Colx4(),Coly4(),3,colors[RED]);
	DrawLine(Colx4(),Coly4(),Colx1(),Coly1(),3,colors[RED]);
}

void Saucer::Move(int i)
{
	
	if(newX>=newY)
	{
		if(newX>=xco)
		{
			newX=xco+512;
		}
		else
		{
			newX=xco-512;
		}
	}
	else
	{
		if(newY>=yco)
			newY=yco+420;
		else
			newY=yco-420;
	}
	dx=newX-xco;
	dy=newY-yco;
	xco+=dx/500.0;
	yco+=dy/500.0;
}

void Saucer::Destroy()
{
	dead=true;
}
bool Saucer::collision(float xx,float yy,float rad)
{
	float d=0;
	d=sqrt((((xx-colx1)*(xx-colx1))+((yy-coly1)*(yy-coly1))));
	if(d<=rad)
	{
		return true;
	}
	d=sqrt((((xx-colx2)*(xx-colx2))+((yy-coly2)*(yy-coly2))));
	if(d<=rad)
	{
		return true;
	}
	d=sqrt((((xx-colx3)*(xx-colx3))+((yy-coly3)*(yy-coly3))));
	if(d<=rad)
	{
		return true;
	}
	d=sqrt((((xx-colx4)*(xx-colx4))+((yy-coly4)*(yy-coly4))));
	if(d<=rad)
	{
		return true;
	}
	return false;
}
bool Saucer::Shoot()
{
	if(bulletShoot%500==0)
	{
		bulletShoot=0;
		return true;
	}
	return false;
}
float Saucer::getDx()
{
	srand(seed);
	float Dx=rand()%-25+25;
	seed++;
	return Dx;
}
float Saucer::getDy()
{
	srand(seed);
	float Dx=rand()%-25+25;
	seed++;
	return Dx;
}
