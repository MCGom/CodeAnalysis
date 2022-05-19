///중복 컴파일 방지를 위한 부분
#pragma once
///필요한 헤더 파일 전처리 부분
#include "framework.h"
#include <vector>
#include <map>
///전처리 종료 시점
///std 네임 스페이스 사용 선언
using namespace std;
/**
 * \brief 
 */
class Entity;
class BulletBase;

/**
 * @class GameHandler
 * @brief 
 */
class GameHandler
{
public:
	void OnPaint(HDC hdc);
	void OnKeyDown(WPARAM wParam);

	static GameHandler* GetInstance();
	static void DestroyInstance();
	void InitBitmap(HINSTANCE hInst);

	//
	static DWORD WINAPI test(void* param);
	static DWORD WINAPI attack(LPVOID param);
	static DWORD WINAPI enemy_attack(LPVOID param);
	static DWORD WINAPI enemy_move(LPVOID param);
	static DWORD WINAPI BulletTR(LPVOID param);
	static DWORD WINAPI StageTR(LPVOID param);

	void GameStart();
	void GameOver();
	void GameClear();
	void ResetGame();
	void RestartGame();
	bool EnemyCollisionTest(class EnemyBase* ColEnemy);

	int BulletCollisionTestToEnemy(BulletBase* ColBullet);
	bool BulletCollisionTestToPlayer(BulletBase* ColBullet);

	void DeleteBullet(int KeyCode);
	void DeleteEnemy(int KeyCode);
	void CreateBullet(BulletBase* newBullet);
	void CreateEnemy(EnemyBase* newEnemy);
	int GetPlayerLife();



private:
	GameHandler();
	~GameHandler();
	static GameHandler* Instance;
	HINSTANCE hInst;
	HANDLE Bullet_SemaHnd;
	HANDLE Enemy_SemaHnd;

	map<int, class BulletBase*> Bullets;
	map<int, class EnemyBase*> Enemys;

	bool bGameover;
	bool bGameclear;
	bool bGameend;


	int StageKey;

	HBITMAP BIT_Frame;
	HBITMAP BIT_Heart;
	HBITMAP BIT_NullHeart;

	class PlayerBase* player;
	class PageStart* start;
	class PageEnd* end;
	class PageClear* clear;

};

