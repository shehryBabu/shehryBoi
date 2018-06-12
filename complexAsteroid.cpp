
#include "complexAsteroid.h"
complexAsteroid::complexAsteroid(float x,float y,char s): Asteroid(x,y,s),Base(x,y)
{
	srand(seed);
	newX=rand()%1024;
	newY=rand()%840;
	Asteroid::seed+=654;
	cout<<" before newX: "<<newX<<" before newY: "<<newY<<endl;
	if(newX>=newY)
	{
		if(newX>=getXCo())
		{
			newX=getXCo()+512;
		}
		else
		{
			newX=getXCo()-512;
		}
	}
	else
	{
		if(newY>=getYCo())
			newY=getYCo()+420;
		else
			newY=getYCo()-420;
	}
	dx=newX-getXCo();
	dy=newY-getYCo();
	if(getSize()=='l')
	{
		speed=1/500.0;
	}
	else
	{
		if(getSize()=='m')
		{
			speed=1/350.0;
		}
		else
			speed=1/200.0;
	}
	sec=0;
}

void complexAsteroid::Move(int x)
{	
	if(getDestroy()==0)
	{
		sec++;
		if(sec%193==0)
		{
			changeDir();
		}
		setXCo(getXCo()+(dx*speed));
	setYCo(getYCo()+(dy*speed));
	//Draw();
	//cout<<"new X: "<<newX<<" newY: "<<newY<<" getXCOO: "<<getXCo()<<" getYCO: "<<getYCo()<<" Dx: "<<Dx<<" Dy: "<<Dy<<endl;
	
	//setSX((Dx*speed));
	//setSY((Dy*speed));
	/*if(getSize()=='l')
	{
		if(getXCo()<=70)
		{
			setXCo(1024);
		}
	}*/
	
	if(getXCo()<=-80 && dx<0)
	{
		setXCo(1152);
	}
		
	if(getYCo()>=910 && dy>=0)
	{
		setYCo(-80);
		
	}
	
	if(getXCo()>=1150 && dx>=0)
	{
		setXCo(-80);
	}
	
	if(getYCo()<=-80 && dy<0)
	{
		setYCo(900);
	}
	}
	else
	{
		setXCo(12021);
		setYCo(25122);
	}
}
/*void complexAsteroid::SPLIT()
{
	split=1;
}*/
void complexAsteroid::changeDir()
{
	srand(seed);
	newX=rand()%1024;
	newY=rand()%840;
	Asteroid::seed+=654;
	//cout<<" before newX: "<<newX<<" before newY: "<<newY<<endl;
	if(newX>=newY)
	{
		if(newX>=getXCo())
		{
			newX=getXCo()+512;
		}
		else
		{
			newX=getXCo()-512;
		}
	}
	else
	{
		if(newY>=getYCo())
			newY=getYCo()+420;
		else
			newY=getYCo()-420;
	}
	dx=newX-getXCo();
	dy=newY-getYCo();
}
