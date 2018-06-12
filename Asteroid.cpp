#include "Asteroid.h"
int Asteroid::seed=2365;
Asteroid::Asteroid(float x,float y,char si,float r): Base(x,y)
{
	xco=x;yco=y;
	srand(seed);
	 size=si;
	rad=r;
	if(size=='s')
		rad=20;
	else
	{
		if(size=='m')		
			rad=40;
		else
			if(size=='l')
			rad=80;
	}
	int rndpoints=0;
	rndpoints=rand()% 9;
	npoints = MAX(5,rndpoints);
	//cout<<"rndpoints before: "<<rndpoints<<endl;
	//cout << npoints << endl;
	dtheta = 360 / npoints;
	// using the formula rcostheta and rsin theta;
	 
	 float stheta=dtheta;
	 for(int i=0;i<9;i++)
	 {
		 theta[i] = 0;
	 }
	 theta[9] = GetRandInRange(0,dtheta);
	 xco=x;yco=y;
	 sx = xco + float(rad) * cos(Deg2Rad(theta[9]));
	 sy = yco + float(rad) * sin(Deg2Rad(theta[9]));
	 for(int i=0;i<9;i++)
	 {
		 theta[i] = 0;
	 }
	 
	 for(int i=0;i<npoints-1;i++)
	 {
		 theta[i] = GetRandInRange(stheta, stheta + dtheta);
		 stheta+=dtheta;
	 }
	 seed+=653;
	 destroy=0;
	 cout<<" xco: "<<xco<<" yco: "<<yco<<endl;
	 //xco=x;
	if(size=='l')
	MidCheck();
	// cout<<" beginnig xco: "<<xco<<" beginnig yco: "<<yco<<endl;
}

void Asteroid::Draw(ColorNames color)
{
	float x1 = sx;
	float y1 = sy;
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
}
void Asteroid::setXCo(const float x)
{
	xco=x;
	sx= xco + float(rad) * cos(Deg2Rad(theta[9]));
}void Asteroid::setYCo(const float y)
{
	yco=y;
	sy = yco + float(rad) * sin(Deg2Rad(theta[9]));
}

void Asteroid::setSX(const float x)
{
	sx=x;
}
void Asteroid ::setSY(const float y)
{
	sy=y;
}
void Asteroid::MidCheck()
{
	 bool v=true;
	 for(int i=0;v;i++)
	 {
		 if(yco>=550 || yco<=250)
		 {
			 v=false;
		 }
		 else
		 {
			 yco=rand()%840;
			 seed+=554;
		 }
	 }
	 v=true;
	 for(int i=0;v;i++)
	 {
		 if(xco>=900 || xco<=300)
		 {
			 v=false;
		 }
		 else
		 {
			 xco=rand()%1024;
			 seed+=554;
		 }
	 }
	  sx = xco + float(rad) * cos(Deg2Rad(theta[9]));
	 sy = yco + float(rad) * sin(Deg2Rad(theta[9]));
}
float Asteroid::getTheta(int i)
{
	return theta[i];
}
