/*
 * Board.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */

#include "Board.h"
#include <cstdio>
int Board::level=1;
int Board::transition=0;
int Board::immune=0;
int Board::enough=1;
int Board::saucerEntry=0;
int Board::menu=0;
bool Board::dead=false;
// Asteroids board

// Note that all these enum constants from NILL onwards
// have been given numbers in increasing order
// e.g. NILL=0, and so on
// and these numbers are represented in the board array...
enum BoardParts {
	NILL, S_BRICK, G_BRICK, R_BRICK
};
// defining some utility functions...

/* board_array[Board::BOARD_Y][Board::BOARD_X] = { { 0 } };*/

// Destructor
Board::~Board(void) {
}
void Board::InitalizeBoard(int w, int h) {
	cout << "Initialize board" << endl;
	width = w;
	height = h;
	for (int i = 0; i < BOARD_Y - 1; ++i) {
		for (int j = 0; j < BOARD_X; ++j) {
			// can use G_BRICK, R_BRICK, or S_BRICK here
			board_array[i][j] = NILL;
		}
	}
	//sh=new Shooter(512,420);
}
//Constructor
Board::Board(int xsize, int ysize) {
	cout << "Constructor board" << endl;
	xcellsize = xsize;
	ycellsize = ysize;
	pcolor = CHOCOLATE;
	bcolor = ORANGE_RED;
	gcolor = PINK;
	for (int i = 0; i < BOARD_Y; ++i)
		for (int j = 0; j < BOARD_X; ++j)
			board_array[i][j] = 0;
			
	srand(time(NULL));
	int seeed=rand();
	destroy=0;
	SDestroy=0;
	score=0;
	saucers=0;
	startOver=1;
	lives=3;
	srand(seeed);
	seeed+=34343;
	num=2+(level*2);
	num+=(2+(level*2))*2;
	num+=(2+(level*2))*4;
	cout<<" num "<<num<<endl;
	base=new Base*[11+(level*2)+num];
	for(int i=11+(level*2);i<11+(level*2)+(2+(level*2));i++)
	{
		srand(seeed);
		base[i]=new NormalAsteroid(rand()%1024,rand()%840,'l');
		seeed+=34343;
	}
	for(int i=11+1;i<11+(level*2);i+=2)
	{
		base[i]=new Bullet();
	}
	base[10]=new Shooter(512,420);
	for(int i=0;i<10;i++)
		base[i]=new Bullet();
	
	
	
//set up board
}

void Board::Draw() {
	glColor3f(0, 0, 1);
	glPushMatrix();

	for (int i = BOARD_Y - 2, y = 0; i >= 0; --i, y += xcellsize) {
		for (int j = 0, x = 0; j < BOARD_X; j++, x += (ycellsize)) {
			//			cout <<      " " << board_array[i][j] << " " << flush;
			switch (board_array[i][j]) {
			case NILL:
				// Empty space
				break;
			case S_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize,
						colors[SLATE_GRAY]);
				//DrawLine(x - 10, y, x - 10 + ycellsize, y, 4, colors[BLACK]);
				break;
			case G_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize,
						colors[LIGHT_GREEN]);
				break;
			case R_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize, colors[RED]);
				break;
			}
		}
	}
	if(menu==1)
	{
		saucerEntry++;
		DrawScore();
		DrawLives();
	}
	Stars();
	if(immune>0)
	{
		enough++;
		if(dead==false)
		DrawString(512,650,"Immune",colors[WHITE]);
	}
	if(enough%100==0)
	{
		immune=0;
	}
	glPopMatrix();
}

void Board::GetInitTextPosition(int &x, int &y) {
	x = xcellsize;
	y = (BOARD_Y - 1) * ycellsize + ycellsize / 2;
}
int Board::getLevel()
{
	return level;
}
void Board::nextLevel()
{
	srand(time(NULL));
	int seeed=rand();
	if(destroy+SDestroy==num)
	{
		transition++;
		if(transition%200==0)
		{
		//cout<<" level 2"<<endl;
		level++;
		//float lives=base[10]->getLives();
	for(int i=0;i<11+num;i++)
	{
		delete  base[i];
	}
	delete [] base;
	num=2+(level*2);
	num+=(2+(level*2))*2;
	num+=(2+(level*2))*4;
	//cout<<" num "<<num<<endl;
	base=new Base*[11+(level*2)+num];
	for(int i=11+(level*2);i<11+(level*2)+(2+(level*2));i++)
	{
		srand(seeed);
		base[i]=new NormalAsteroid(rand()%1024,rand()%840,'l');
		seeed+=4654;
	}
		for(int i=11+1;i<11+level*2;i+=2)
	{
		base[i]=new Bullet();
	}
	base[10]=new Shooter(512,420);
	for(int i=0;i<10;i++)
		base[i]=new Bullet();
		base[10]->setXCo(512);
		base[10]->setYCo(420);
		//base[10]->setLives(lives);
		destroy=0;
		SDestroy=0;
		transition=0;
		saucers=0;
		saucerEntry=0;
	}
	else
	{
		string str="LEVEL ";
		string st=Num2Str(level+1);
		str+=st;
		DrawString(512,700,str,colors[WHITE]);
	}
	}
}
void Board::DrawScore()
{
	string str="Score: ";
	str+=Num2Str(score);
	DrawString(50,800,str,colors[WHITE]);
}
void Board::Score(const int s)
{
	score=s;
	if(score%4000==0)
	{
		lives++;
	}
}
void Board::DrawLives()
{
	string str="LIVES: ";
	string s=Num2Str(lives);
	str+=s;
	DrawString(200,800,str,NULL);
}
void Board::Hit()
{
	//cout<<"imune: "<<immune<<endl;
	if(immune>0)
	{
		return;
	}
	//cout<<" lives dedutjnj"<<endl;
	lives-=1;
	if(lives<=0)
	{
		lives=0;
		dead=true;
	}
	immune++;
}
void Board::BulletAsteCheck()
{
	if(dead==false)
	{
	for(int i=0;i<10;i++)
	{
		for(int j=11+(level*2);j<11+(level*2)+(2+(2*getLevel()));j++)
		{
			if(base[i]->BulletAttack())
			{
			if(base[i]->collision(base[j]->getXCo(),base[j]->getYCo(),base[j]->getRad()))
			{
				float xx,yy;
				score+=10;
				xx=base[j]->getXCo();
				yy=base[j]->getYCo();
				base[i]->Destroy();
				base[j]->Destroy();
				/*base[(11+(level*2)+(2+(getLevel()*2)))+(getDestroy()*2)]=new complexAsteroid(xx,yy);
				base[(11+(level*2)+(2+(getLevel()*2)))+(getDestroy()*2)+1]=new complexAsteroid(xx,yy);*/
				Split(xx,yy);
				Destroy();
				//b->base[j]=new complexAsteroid (xx,yy);
			}
		}
		}
		for(int j=11+(level*2)+(2+(getLevel()*2));j<(11+(level*2)+(2+(getLevel()*2)))+(getDestroy()*2);j++)
		{
			if(base[i]->BulletAttack())
			{
			if(base[i]->collision(base[j]->getXCo(),base[j]->getYCo(),base[j]->getRad()))
			{
				float xx,yy;
				xx=base[j]->getXCo();
				yy=base[j]->getYCo();
				base[j]->Destroy();
				base[i]->Destroy();
				//cout<<" xx: "<<xx<<" yy: "<<yy<<endl;
				//cout<<" workdd 1111"<<endl;
			
				if(base[j]->getSize()=='m')
				{
					score+=20;
					//cout<<" workedk"<<endl;
					/*base[(11+(level*2)+(2+(getLevel()*2)))+(getDestroy()*2)]=new NormalAsteroid(xx,yy,'s');
					base[(11+(level*2)+(2+(getLevel()*2)))+(getDestroy()*2)+1]=new NormalAsteroid(xx,yy,'s');*/
					SmallSplit(xx,yy);
					Destroy();
				}
				else
				{
					score+=40;
					smallDestroy();
				}
			}
		}
		}
	}
}
}
void Board::BulletShoot()
{
	if(dead==false)
	{
		for(int i=0;i<10;i++)
	{
		if(base[i]->BulletAttack())
		{
			base[i]->Shoot(base[10]->getXCo(),base[10]->getYCo(),base[10]->getDx(),base[10]->getDy());
		}
	}
}
}
void Board::DrawShooter()
{
	if(lives>0)
	{
		base[10]->Draw();
	}
		else
	{
		base[10]->setXCo(0);
		base[10]->setYCo(0);
		menu=2;
	}
}
void Board::Stars()
{
	srand(5421);
	ColorNames cname=WHITE;
	for(int i=0;i<50;i++)
	{
		DrawCircle(rand()%1020,rand()%840,1,colors[cname]);
	}
}
void Board::Split(float xx,float yy)
{
	base[(11+(level*2)+(2+(getLevel()*2)))+(getDestroy()*2)]=new complexAsteroid(xx,yy);
	base[(11+(level*2)+(2+(getLevel()*2)))+(getDestroy()*2)+1]=new complexAsteroid(xx,yy);
}
void Board::SmallSplit(float xx,float yy)
{
	base[(11+(level*2)+(2+(getLevel()*2)))+(getDestroy()*2)]=new NormalAsteroid(xx,yy,'s');
	base[(11+(level*2)+(2+(getLevel()*2)))+(getDestroy()*2)+1]=new NormalAsteroid(xx,yy,'s');
}
void Board::DrawSaucer()
{
	for(int i=11;i<11+(saucers*2);i+=2)
	{
		base[i]->Draw();
		base[i]->Move();
	}
}
void Board::ShooterAsteCheck()
{
	if(dead==false & immune==0)
	{
		for(int i=11+(getLevel()*2);i<11+(getLevel()*2)+(2+(2*getLevel()));i++)
	{
		if(base[10]->collision(base[i]->getXCo(),base[i]->getYCo(),base[i]->getRad()))
		{
			float xx,yy;
			xx=base[i]->getXCo();
			yy=base[i]->getYCo();
			Hit();
			base[10]->Destroy();
			base[i]->Destroy();
			Split(xx,yy);
			Destroy();
			break;
		}
	}
}
}
void Board::ShooterMedAsteCheck()
{	
		for(int i=11+(getLevel()*2)+(2+(getLevel()*2));i<(11+(getLevel()*2)+(2+(getLevel()*2)))+(getDestroy()*2);i++)
	{
		base[i]->Draw();
		base[i]->Move();
		if(dead==false && immune==0)
	{
		if(base[10]->collision(base[i]->getXCo(),base[i]->getYCo(),base[i]->getRad()))
		{
			
			float xx,yy;
			xx=base[i]->getXCo();
			yy=base[i]->getYCo();
			Hit();
			base[10]->Destroy();
			if(base[i]->getSize()=='m')
			{
				SmallSplit(xx,yy);
				Destroy();
				base[i]->Destroy();
			}
			else
			{
				base[i]->Destroy();
				smallDestroy();
			}
		}
		
	}
}
}
void Board::SaucerEntry()
{
	if(saucers<level)
	{
	if(saucerEntry%400==0)
	{
		for(int i=11+(saucers*2);i<11+(level+(saucers+1));i+=2)
		{
			base[i]=new Saucer(512,840);
			
		}
		saucers++;
		saucerEntry=0;
	}
}
}
void Board::SaucerBullet()
{
	for(int i=11;i<11+(saucers*2);i+=2)
	{
		if(base[i]->Shoot())
		{
			base[i+1]->Attack();
		}
		if(base[i+1]->BulletAttack())
		{
			base[i+1]->Shoot(base[i]->getXCo(),base[i]->getYCo(),base[i]->getDx(),base[i]->getDy());
			if(base[i+1]->collision(base[10]->getXCo(),base[10]->getYCo(),20))
			{
				Hit();
				base[10]->Destroy();
			}
		}
	}
}
void Board::SaucerAsteCheck()
{
	for(int i=11;i<11+(saucers*2);i+=2)
	{
		for(int j=11+(level*2);j<(11+(getLevel()*2)+(2+(getLevel()*2)));j++)
		{
			if(base[i]->collision(base[j]->getXCo(),base[j]->getYCo(),base[j]->getRad()))
			{
				float xx,yy;
				xx=base[j]->getXCo();
				yy=base[j]->getYCo();
				base[j]->Destroy();
				Split(xx,yy);
				Destroy();
				base[i]->Destroy();
			}
		}
	}
}
void Board::SaucerMedAsteCheck()
{
	for(int i=11;i<11+(saucers*2);i+=2)
	{
		for(int j=11+(getLevel()*2)+(2+(getLevel()*2));j<(11+(getLevel()*2)+(2+(getLevel()*2)))+(getDestroy()*2);j++)
		{
			if(base[i]->collision(base[j]->getXCo(),base[j]->getYCo(),base[j]->getRad()))
			{
				float xx,yy;
			xx=base[j]->getXCo();
			yy=base[j]->getYCo();
			base[i]->Destroy();
			if(base[j]->getSize()=='m')
			{
				SmallSplit(xx,yy);
				Destroy();
				base[j]->Destroy();
			}
			else
			{
				base[j]->Destroy();
				smallDestroy();
			}
			}
		}
	}
}
void Board::SaucerHit()
{
	if(dead==false)
	{
		for(int i=0;i<10;i++)
		{
			for(int j=11;j<11+(saucers*2);j+=2)
			{
				if(base[i]->BulletAttack())
				{
					if(base[i]->collision(base[j]->getXCo(),base[j]->getYCo()+20,30))
					{
						score+=300;
						base[i]->Destroy();
						base[j]->Destroy();
					}
				}
			}	
		}
	}
}
void Board::SaucerShooterCheck()
{
		if(dead==false & immune==0)
	{
		for(int i=11;i<11+(saucers*2);i+=2)
		{
		if(base[10]->collision(base[i]->getXCo(),base[i]->getYCo()+20,30))
		{
			Hit();
			base[10]->Destroy();
			break;
		}
	}
}
}
void Board::StartScreen()
{
	DrawString(450,500,"ASTEROIDS",colors[WHITE]);
	DrawString(450,300,"PRESS START",colors[WHITE]);
}
void Board::MoveAsteroid()
{
		for(int i=11+(getLevel()*2);i<11+(getLevel()*2)+(2+(2*getLevel()));i++)
	{
		base[i]->Draw();
		base[i]->Move();

	}
}
void Board::EndScreen()
{
	DrawString(450,500,"GAME OVER",NULL);
	DrawString(450,300,"TRY AGIN",colors[WHITE]);
	DrawString(450,280,"EXIT",colors[WHITE]);
	if(startOver==1)
	{
		DrawCircle(435,308,8,colors[WHITE]);
	}
	else
	{
		DrawCircle(435,289,8,colors[WHITE]);
	}

}
void Board::Choice()
{
	if(startOver==1)
	{
	/*for(int i=0;i<11+num;i++)
	{
		delete  base[i];
	}*/
	delete [] base;
	srand(time(NULL));
	int seeed=rand();
	destroy=0;
	SDestroy=0;
	score=0;
	saucers=0;
	saucerEntry=0;
	immune=0;
	enough=0;
	startOver=0;
	level=1;
	startOver=1;
	lives=3;
	srand(seeed);
	seeed+=34343;
	num=2+(level*2);
	num+=(2+(level*2))*2;
	num+=(2+(level*2))*4;
	cout<<" num "<<num<<endl;
	menu=1;
	dead=false;
	base=new Base*[11+(level*2)+num];
	for(int i=11+(level*2);i<11+(level*2)+(2+(level*2));i++)
	{
		srand(seeed);
		base[i]=new NormalAsteroid(rand()%1024,rand()%840,'l');
		seeed+=34343;
	}
	for(int i=11+1;i<11+(level*2);i+=2)
	{
		cout<<" bullet index>"<<i<<endl;
		base[i]=new Bullet();
	}
	base[10]=new Shooter(512,420);
	for(int i=0;i<10;i++)
		base[i]=new Bullet();
	}
	if(startOver==2)
	{
		exit(1);
	}
}
