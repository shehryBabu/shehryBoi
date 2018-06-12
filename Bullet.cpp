#include "Bullet.h"
Bullet::Bullet(int s): Base(11199,11199)
{
	sswitch=s;
	Travelx=0;Travely=0;
	bulletAttack=false;
	attack=0;
}
void Bullet::Shoot(float x,float y,float ddx,float ddy)
{
	if(xco==11199 && yco==11199)
	{
		xco=x;
		yco=y;
		dx=ddx;dy=ddy;
	}
	float speed=1/5.0;
	Draw();
	xco+=dx*speed;yco+=dy*speed;
	Travelx+=ABS(dx*speed);Travely+=ABS(dy*speed);
	//cout<<" working: "<<endl;
		if(xco<=-40 && dx<0)
	{
		xco=1040;
	}
		
	if(yco>=843 && dy>=0)
	{
		yco=-20;
		
	}
	
	if(xco>=1150 && dx>=0)
	{
		xco=-40;
	}
	
	if(yco<=-40 && dy<0)
	{
		yco=850;
	}
	if(Travelx>=650 || Travely>=650 || Travelx+Travely>=1700 )
	{
		Travelx=0;Travely=0;
		//sswitch=0;
		xco=11199;yco=11199;
		bulletAttack=false;
	}
	
}
int Bullet::good()
{
	return sswitch;
}
void Bullet::Destroy()
{
	Travelx=0;Travely=0;
		sswitch=0;
		//cout<<" not working"<<endl;
		xco=11199;yco=11199;
		bulletAttack=false;
}
void Bullet::Draw(ColorNames color)
{
	//float col=colors[5][2];
	DrawRectangle(xco,yco,5,5,colors[WHITE]);
	
	//cout<<" SHOTTGU"<<endl;
	//cout<<" xco: "<<xco<<" yco: "<<yco<<endl;
}
/*void Bullet::Update(float x,float y)
{
	xco=x;yco=y;
}*/
int Bullet:: getAttack()
{
	attack++;
	if (attack >=10)
	{
		attack=0;
	}
	return attack;
}
bool Bullet:: BulletAttack()
{
	return bulletAttack;
}
void Bullet:: Attack()
{
	bulletAttack=true;
}
bool Bullet::collision(float xx,float yy,float rad)
{
	float d=0;
	d=sqrt((((xx-xco)*(xx-xco))+((yy-yco)*(yy-yco))));
	if(d<=rad)
	{
		cout<<" shootot"<<endl;
		return true;
	}
	return false;
}
