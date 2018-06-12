/*
 * Board.h
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */
#ifndef _BOARD_H_
#define _BOARD_H_

#include <GL/glut.h>
#include <iostream>
#include "util.h"
#include "Base.h"
#include "Shooter.h"
#include "NormalAsteroid.h"
#include "Bullet.h"
#include "complexAsteroid.h"
#include "Saucer.h"
//#define WITH_TEXTURES
using namespace std;

class Board {
private:

	int xcellsize, ycellsize;
	int width, height;
	ColorNames pcolor, bcolor, gcolor;
	static int level,transition,immune,enough,saucerEntry;
	int destroy,SDestroy,num,score,lives,saucers;
	static bool dead;
	static int menu;
	int startOver;

public:
	Base **base;
	static const int BOARD_X = 17;
	static const int BOARD_Y = 14;
	/*
	 static const int BOARD_X=17;
	 static const int BOARD_Y=14;
	 */

	int board_array[BOARD_Y][BOARD_X];
	Board(int xsize = 8, int ysize = 8);

	~Board(void);
	void InitalizeBoard(int, int);
	//draw the board
	void Draw();

	static int GetBoardX() {
		return BOARD_X;
	}
	static int GetBoardY() {
		return BOARD_Y;
	}
	int GetMidX() {
		return BOARD_X * xcellsize / 2.0;
	}
	int GetMidY() {
		return BOARD_Y * ycellsize / 2.0;
	}
	int GetCellSize() {
		return xcellsize;
	}

	void GetInitRandomPosition(int &x, int &y) {
		// leave 10 units from all sides
		x = GetRandInRange(50, width - 50);
		y = GetRandInRange(50, height - 50);
	}
	int GetWidth() {
		return width;
	}
	int GetHeight() {
		return height;
	}
	void Stars();
	void GetInitTextPosition(int &x, int &y);
	void nextLevel();
	int getLevel();
	int getDestroy(){return destroy;}
	void Destroy(){destroy++;}
	void smallDestroy(){SDestroy++;}
	int getNum(){return num;}
	void DrawScore();
	void Score(const int s);
	void Hit();
	void MoveAsteroid();
	void DrawLives();
	void BulletAsteCheck();
	void BulletShoot();
	void DrawShooter();
	void Split(float xx,float yy);
	void SmallSplit(float xx,float yy);
	void DrawSaucer();
	void ShooterAsteCheck();
	void ShooterMedAsteCheck();
	void SaucerEntry();
	void SaucerBullet();
	void SaucerAsteCheck();
	void SaucerMedAsteCheck();
	void SaucerHit();
	void SaucerShooterCheck();
	int getMenu(){return menu;}
	void StartScreen();
	void setMenu(const int i){menu=i;}
	void EndScreen();
	void TryAgain(int i){startOver=i;}
	void Choice();
	
};

#endif
