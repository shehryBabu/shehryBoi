#include "Shooter.h"
float Shooter::boost=0;
int Shooter::ind=0;
int Shooter::Score=0;
int Shooter::menu=0;
int Shooter::sec=0;
int Shooter::saucerEntry=0;
int Shooter::immune=0;
int Shooter::enough=1;
Shooter::Shooter(float x,float y): num(4),Base(x,y)
{
	
	srand(time(NULL));
	int seeed=rand();
	x1=xco;y1=yco+20;x2=xco+15,y2=yco-20;x3=xco-15;y3=yco-20;angle=0;shoot=0;factor=0.1;
	float x4,y4;
	x4=(x2+x3)/2;
	y4=(y2+y3)/2;
	dx=x1-x4;
	dy=y1-y4;
	x5=dx+x3;y5=dy+y3;x6=dx+x2;y6=dy+y2;
	//lives=3;
	/*as=new NormalAsteroid *[num];
	for(int i=0;i<num;i++)
	{
		srand(seeed);
		as[i]=new NormalAsteroid(rand()%1024,rand()%840,'l');
		seeed+=2510;
	}*/
	/*ss=new Split*[(num*2)+num];
	alive=true;
	saucer=new Saucer(600,200);*/
	alive=true;
}
void Shooter::setXco(const float x)
{
	xco=x;
}
void Shooter::setYco(const float y)
{
	yco=y;
}
float Shooter::getXco()const
{
	return xco;
}
float Shooter::getYco()const
{
	return yco;
}

void Shooter::Draw(ColorNames color)
{
	if(immune>0)
	{
		enough++;
	}
	if(enough%100==0)
	{
		immune=0;
	}
		//Stars();
		//if(saucerEntry>=5)
		//saucer->DrawSaucer();
		//DrawLives();
		xco=(x1+x2+x3)/3.0;
		yco=(y1+y2+y3)/3.0;

			float x4,y4;
			x4=(x2+x3)/2;
			y4=(y2+y3)/2;
			dx=x1-x4;
			dy=y1-y4;
			DrawLine(x1,y1,x2,y2,1,colors[WHITE]);
			DrawLine(x2,y2,x3,y3,1,colors[WHITE]);
			DrawLine(x3,y3,x1,y1,1,colors[WHITE]);
			//DrawCircle(xco,yco,3,colors[WHITE]);
		
	
		//DrawLine(x4,y4,x1,y1);
		x5=dx+x3;y5=dy+y3;x6=dx+x2;y6=dy+y2;
		
		
		//Rect();
		
		//cout<<" collision: "<<(collision(x2,y2))<<endl;
		//cout<<" collision: "<<(collision(x3,y3))<<endl;
		//cout<<" collision: "<<(collision(x5,y5))<<endl;
		//cout<<" collision: "<<(collision(x6,y6))<<endl;
		/*if(alive)
			Destroy(collision(x2,y2));
		if(alive)
			Destroy(collision(x3,y3));
		if(alive)
			Destroy(collision(x5,y5));
		if(alive)
			Destroy(collision(x6,y6));*/
		//cout<<" dx: "<<dx<<" dty: "<<dy<<endl;
		for(int i=0;i<num;i++)
		{
			/*Alive(as[i]->getXCo(),as[i]->getYCo(),as[i]->getRad(),i,0);/*
			/*Salive(as[i]->getXCo(),as[i]->getYCo(),saucer->Colx1(),saucer->Coly1(),as[i]->getRad(),i,0);
				Salive(as[i]->getXCo(),as[i]->getYCo(),saucer->Colx2(),saucer->Coly2(),as[i]->getRad(),i,0);
				Salive(as[i]->getXCo(),as[i]->getYCo(),saucer->Colx3(),saucer->Coly3(),as[i]->getRad(),i,0);
				Salive(as[i]->getXCo(),as[i]->getYCo(),saucer->Colx4(),saucer->Coly4(),as[i]->getRad(),i,0);*/
		}
		for(int i=0;i<ind;i++)
		{
			/*Alive(ss[i]->getX1(),ss[i]->getY1(),ss[i]->getRAD1(),i,1);
			Alive(ss[i]->getX2(),ss[i]->getY2(),ss[i]->getRAD2(),i,2);*/
				/*Salive(ss[i]->getX1(),ss[i]->getY1(),saucer->Colx1(),saucer->Coly1(),ss[i]->getRAD1(),i,1);
				Salive(ss[i]->getX1(),ss[i]->getY1(),saucer->Colx2(),saucer->Coly2(),ss[i]->getRAD1(),i,1);
				Salive(ss[i]->getX1(),ss[i]->getY1(),saucer->Colx3(),saucer->Coly3(),ss[i]->getRAD1(),i,1);
				Salive(ss[i]->getX1(),ss[i]->getY1(),saucer->Colx4(),saucer->Coly4(),ss[i]->getRAD1(),i,1);
				Salive(ss[i]->getX2(),ss[i]->getY2(),saucer->Colx1(),saucer->Coly1(),ss[i]->getRAD1(),i,2);
				Salive(ss[i]->getX2(),ss[i]->getY2(),saucer->Colx2(),saucer->Coly2(),ss[i]->getRAD1(),i,2);
				Salive(ss[i]->getX2(),ss[i]->getY2(),saucer->Colx3(),saucer->Coly3(),ss[i]->getRAD1(),i,2);
				Salive(ss[i]->getX2(),ss[i]->getY2(),saucer->Colx4(),saucer->Coly4(),ss[i]->getRAD1(),i,2);*/
		}
		if(boost>0)
		{
			yco+=dy*boost;
			xco+=dx*boost;
			x1+=dx*boost;
			x2+=dx*boost;
			x3+=dx*boost;
			y1+=dy*boost;
			y2+=dy*boost;
			y3+=dy*boost;
			xco=(x1+x2+x3)/3.0;
			yco=(y1+y2+y3)/3.0;
			boost-=(0.001);
			//Rect();
			//cout<<" collision: "<<(collision(x2,y2))<<endl;
			//cout<<" collision: "<<(collision(x3,y3))<<endl;
			//cout<<" collision: "<<(collision(x5,y5))<<endl;
			//cout<<" collision: "<<(collision(x6,y6))<<endl;
			for(int i=0;i<num;i++)
			{
				//Alive(as[i]->getXCo(),as[i]->getYCo(),as[i]->getRad(),i,0);
				/*Salive(as[i]->getXCo(),as[i]->getYCo(),saucer->Colx1(),saucer->Coly1(),as[i]->getRad(),i,0);
				Salive(as[i]->getXCo(),as[i]->getYCo(),saucer->Colx2(),saucer->Coly2(),as[i]->getRad(),i,0);
				Salive(as[i]->getXCo(),as[i]->getYCo(),saucer->Colx3(),saucer->Coly3(),as[i]->getRad(),i,0);
				Salive(as[i]->getXCo(),as[i]->getYCo(),saucer->Colx4(),saucer->Coly4(),as[i]->getRad(),i,0);*/
				
			}
			for(int i=0;i<ind;i++)
			{
				/*Alive(ss[i]->getX1(),ss[i]->getY1(),ss[i]->getRAD1(),i,1);
				Alive(ss[i]->getX2(),ss[i]->getY2(),ss[i]->getRAD2(),i,2);
				/*Salive(ss[i]->getX1(),ss[i]->getY1(),saucer->Colx1(),saucer->Coly1(),ss[i]->getRAD1(),i,1);
				Salive(ss[i]->getX1(),ss[i]->getY1(),saucer->Colx2(),saucer->Coly2(),ss[i]->getRAD1(),i,1);
				Salive(ss[i]->getX1(),ss[i]->getY1(),saucer->Colx3(),saucer->Coly3(),ss[i]->getRAD1(),i,1);
				Salive(ss[i]->getX1(),ss[i]->getY1(),saucer->Colx4(),saucer->Coly4(),ss[i]->getRAD1(),i,1);
				Salive(ss[i]->getX2(),ss[i]->getY2(),saucer->Colx1(),saucer->Coly1(),ss[i]->getRAD1(),i,2);
				Salive(ss[i]->getX2(),ss[i]->getY2(),saucer->Colx2(),saucer->Coly2(),ss[i]->getRAD1(),i,2);
				Salive(ss[i]->getX2(),ss[i]->getY2(),saucer->Colx3(),saucer->Coly3(),ss[i]->getRAD1(),i,2);
				Salive(ss[i]->getX2(),ss[i]->getY2(),saucer->Colx4(),saucer->Coly4(),ss[i]->getRAD1(),i,2);*/
			}
			
			
			if(boost<=0.0009)
			{
				factor=0.1;
			}
			if(boost<=0)
			{
				boost=0;
				factor=0.1;
			}
		}
		if(x1<-40 && x2<=-40 && x3<=-40)
		{
			xco=1040;
			x1+=xco;x2+=xco;x3+=xco;
			xco=(x1+x2+x3)/3.0;
			yco=(y1+y2+y3)/3.0;
		}
			
		if(y1>=890 && y2>=890 && y3>=890 )
		{
			yco=-30;
			float y11=yco-910;
			float y22=yco-910;
			float y33=yco-910;
			y1+=y11;y2+=y22;y3+=y33;
			xco=(x1+x2+x3)/3.0;
			yco=(y1+y2+y3)/3.0;
		}
		
		if(x1>=1080 && x2>=1080  && x3>=1080)
		{
			xco=-20;
			float x11=xco-1080;
			float x22=xco-1080;
			float x33=xco-1080;
			
			x1+=x11;x2+=x22;x3+=x33;
			xco=(x1+x2+x3)/3.0;
			yco=(y1+y2+y3)/3.0;
			
		}
	
		if(y1<=-40 && y2<=-40 && y3<=-40)
		{
			yco=900;
			y1+=yco;y2+=yco;y3+=yco;
			xco=(x1+x2+x3)/3.0;
			yco=(y1+y2+y3)/3.0;
		}
		//bullet.Update(x1,y1);
		if(shoot)
		{
			
			//bullet.Shoot(shoot);
			for(int i=0;i<num;i++)
			{
				//bulletCollision(bullet.getXCo(),bullet.getYCo(),as[i]->getXCo(),as[i]->getYCo(),as[i]->getRad(),0,i);
			}
			for(int i=0;i<ind;i++)
			{
				//bulletCollision(bullet.getXCo(),bullet.getYCo(),ss[i]->getX1(),ss[i]->getY1(),ss[i]->getRAD1(),1,i);
				//bulletCollision(bullet.getXCo(),bullet.getYCo(),ss[i]->getX2(),ss[i]->getY2(),ss[i]->getRAD2(),2,i);
			}
			//shoot=bullet.good();
			//cout<<" shootx1: "<<x1<<" shooty1: "<<y1<<endl;
		}
		for(int i=0;i<ind;i++)
		{
			//ss[i]->Move();
		}
		//cout<<" meny WORKING" <<endl;
		//DrawString(450,500,"ASTEROIDS",colors[WHITE]);
		//DrawString(450,300,"PRESS START",colors[WHITE]);
		
		
		
}
void Shooter::Move(int x)
{
	
		
	switch(x)
	{
		case 1:
			angle+=15;
			break;
		case 2:
			angle-=15;
			break;
	}
	float x11,y11,x22,y22,x33,y33;
	x11=CosA(x1,y1);
	x22=CosA(x2,y2);
	x33=CosA(x3,y3);
	y11=SinA(x1,y1);
	y22=SinA(x2,y2);
	y33=SinA(x3,y3);
	//cout<<" x11: "<<x1<<" y11: "<<y1<<endl;
	/*if(shoot)
	{
		//cout<<" working"<<endl;
		bullet.Shoot(x11,y11,dx,dy,shoot);
		shoot=bullet.good();
		//cout<<" shootx1: "<<x1<<" shooty1: "<<y1<<endl;
	}*/
	x1=x11;x2=x22;x3=x33;y1=y11;y2=y22;y3=y33;
	for(int i=0;i<num;i++)
	{
		//Alive(as[i]->getXCo(),as[i]->getYCo(),as[i]->getRad(),0,i);
	}
	for(int i=0;i<ind;i++)
	{
		//Alive(ss[i]->getX1(),ss[i]->getY1(),ss[i]->getRAD1(),i,1);
		//Alive(ss[i]->getX2(),ss[i]->getY2(),ss[i]->getRAD2(),i,2);
	}
	if(boost>0)
	{
		boost-=0.02;
		if(boost<=0)
			boost=0;
		if(boost>=0.8)
			boost=0.8;
	}

	factor=0.1;
	angle=0;
	
}
void Shooter::Thrust()
{

		
	boost+=(0.02+factor);
	factor-=0.05;
	if(boost>=1)
	{
		boost=1;
	}
	if(factor<=0)
		factor=0;
	angle=0;

}
float Shooter::CosA(float x,float y)
{
	return (((cos(Deg2Rad(angle)))*(x-xco))-((sin(Deg2Rad(angle)))*(y-yco)))+xco;
}
float Shooter::SinA(float x,float y)
{
	return (((sin(Deg2Rad(angle)))*(x-xco))+((cos(Deg2Rad(angle)))*(y-yco)))+yco;
}
/*void Shooter::Shoot()
{

		
	shoot=1;
	bullet.setXY(x1,y1,dx,dy);
}*/
void Shooter::Rect()
{
	float *colo=&colors[6][2];
	DrawLine(x2,y2,x3,y3,4,colo);
	DrawLine(x5,y5,x6,y6,4,colo);
	DrawLine(x6,y6,x2,y2,4,colo);
	DrawLine(x5,y5,x3,y3,4,colo);
}
bool Shooter::collision(float xx,float yy,float rad)
{
	
	/*float d[num];
	for(int i=0;i<num;i++)
	{
		d[i]=(((as[i]->getXCo()-x)*(as[i]->getXCo()-x))+((as[i]->getYCo()-y)*(as[i]->getYCo()-y)));
		//cout<<" d: "<<d[i]<<endl;
		if((d[i]*d[i])<=(80*80))
			cout<<"hitknkn"<<endl;
	}
	float d=0;
		d=sqrt((((xx-x)*(xx-x))+((yy-y)*(yy-y))));
		if((d)<=(rad))
		{
				if(rad>=80)
			{
				ss[ind]=new Split (xx,yy,as[t]->getSize());
				as[t]->SPLIT();
				ind++;
			}
			else
			{
				if(rad>=40)
				{
					ss[ind]=new Split(xx,yy,'m');
					ss[t]->SPLIIT(k);
					ind++;
				}
				else
				{
					ss[t]->SPLIIT(k);
				}
				
			}
			return true;
		}
	
	return false;*/
	float d=0;
	d=sqrt((((xx-x2)*(xx-x2))+((yy-y2)*(yy-y2))));
	if(d<=rad)
	{
		
		//cout<<" HITTOOTO"<<endl;
		return true;
	}
	d=sqrt((((xx-x3)*(xx-x3))+((yy-y3)*(yy-y3))));
	if(d<=rad)
	{
		//cout<<" HITTOOTO"<<endl;
		return true;
	}
	d=sqrt((((xx-x5)*(xx-x5))+((yy-y5)*(yy-y5))));
	if(d<=rad)
	{
		//cout<<" HITTOOTO"<<endl;
		return true;
	}
	d=sqrt((((xx-x6)*(xx-x6))+((yy-y6)*(yy-y6))));
	if(d<=rad)
	{
		//cout<<" HITTOOTO"<<endl;
		return true;
	}
	return false;
	
}
/*void Shooter::Destroy(bool v)
{
	if(v)
		alive=false;
	else
		alive=true;
}*/
/*void Shooter::Alive(float x,float y,float r,int t,int k)
{
	if(alive)
		Destroy(collision(x2,y2,x,y,r,t,k));
	if(alive)
		Destroy(collision(x3,y3,x,y,r,t,k));
	if(alive)
		Destroy(collision(x5,y5,x,y,r,t,k));
	if(alive)
		Destroy(collision(x6,y6,x,y,r,t,k));
}*/
/*void Shooter::bulletCollision(float x,float y,float xx,float yy,float rad,int k,int t)
{
	float d=0;
		d=sqrt((((xx-x)*(xx-x))+((yy-y)*(yy-y))));
		if((d)<=(rad))
		{
			bullet.Stop();
			if(rad>=80)
			{
				ss[ind]=new Split (xx,yy,as[t]->getSize());
				as[t]->SPLIT();
				Score+=10;
				cout<<" xx: "<<xx<<" yy: "<<yy<<endl;
				cout<<" WORKING1111"<<endl;
				ind++;
			}
			else
			{
				if(rad>=40)
				{
					Score+=20;
					ss[ind]=new Split(xx,yy,'m');
					ss[t]->SPLIIT(k);
					cout<<" xx: "<<xx<<" yy: "<<yy<<endl;
					cout<<" WORKING222"<<endl;
					ind++;
				}
				else
				{
					//ss[ind]=new Split(xx,yy,'s');
					Score+=40;
					ss[t]->SPLIIT(k);
					cout<<" xx: "<<xx<<" yy: "<<yy<<endl;
					cout<<" WORKING3333"<<endl;
				}
				
			}

			
			//return true;
		}
	//return false;
}*/
void Shooter::Menu()
{
	menu=1;
}
int Shooter::getMenu()
{
	return menu;
}

/*void Shooter::Salive(float xx,float yy,float x,float y, float rad,int t,int k)
{
	float d=0;
		d=sqrt((((xx-x)*(xx-x))+((yy-y)*(yy-y))));
		if((d)<=(rad))
			{
				if(rad>=80)
			{
				ss[ind]=new Split (xx,yy,as[t]->getSize());
				as[t]->SPLIT();
				ind++;
			}
			else
			{
				if(rad>=40)
				{
					ss[ind]=new Split(xx,yy,'m');
					ss[t]->SPLIIT(k);
					ind++;
				}
				else
				{
					ss[t]->SPLIIT(k);
				}
				
			}
			saucer->Dead();
		}
}
*/
void Shooter::Destroy()
{
	if(immune>0)
	{
		return;
	}
	xco=512;yco=420;
	x1=xco;y1=yco+20;x2=xco+15,y2=yco-20;x3=xco-15;y3=yco-20;
	x5=dx+x3;y5=dy+y3;x6=dx+x2;y6=dy+y2;
	boost=0;
	/*lives-=1;
	if(lives<=0)
	{
		lives=0;
	}*/
	immune++;
}
/*void Shooter::DrawLives()
{
	string str="LIVES: ";
	string s=Num2Str(lives);
	str+=s;
	DrawString(100,800,str,NULL);
}
*/
