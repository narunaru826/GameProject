#pragma once

#include"../Player/Player.h"
#include"../Enemy/EnemyManager.h"
#include"../Shot/ShotManager.h"

class CollisionManager
{
private:

public:

	//プレイヤーと敵の判定
	static bool CheckHitPlayerToEnemy(Player& player,EnemyManager &enemymanager);

	//プレイヤーと敵の弾の判定
	static bool CheckHitPlayerToEnemy1Shot(Player& player, ShotManager& shotmanager);

	//プレイヤーと敵の弾の判定
	static bool CheckHitPlayerToBoss1Shot(Player& player, ShotManager& shotmanager);

	static bool CheckHitPlayerShotToBoss1(ShotManager &shotmanager,EnemyManager &enemymanager);
};