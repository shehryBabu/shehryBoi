
#include "NormalAsteroid.h"
NormalAsteroid::NormalAsteroid(float x,float y,char s): Asteroid(x,y,s),Base(x,y)
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
//	if(getSize()=='l')
//	MidCheck();
}

void NormalAsteroid::Move(int x)
{	
	if(getDestroy()==0)
	{
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

/*void NormalAsteroid::SPLIT()
{
	split=1;
}
*/
/*void Asteroid::Draw(ColorNames color)
{
	float x1 = getSX();
	float y1 = getSY();
	for (int i = 0; i < npoints - 1; ++i) {
		
		float x2 = xco + (rad) * cos(Deg2Rad(theta[i])), y2 = yco
				+ (rad) * sin(Deg2Rad(theta[i]));
		DrawLine(x1, y1, x2, y2, 1, colors[color]);
		x1 = x2;
		y1 = y2;
	}
	DrawLine(x1, y1, sx, sy, 1, colors[color]);
	//float *col=&colors[5][1];
	//DrawCircle(xco,yco,rad,col);
}*/
