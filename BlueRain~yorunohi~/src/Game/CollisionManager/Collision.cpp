#include"Collision.h"
#include"../../Lib/collision/col.h"
bool CollisionManager::CheckHitPlayerToEnemy(Player& player, EnemyManager& enemymanager)
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		Boss1& Boss1 = enemymanager.GetBoss1(i);
		if (!Boss1.IsActive())
		{
			continue;
		}

		VECTOR PlayerPos, Boss1Pos;
		VECTOR PlayerSize, Boss1Size;
		PlayerPos = player.GetPosition();
		Boss1.GetPos(Boss1Pos);

		PlayerSize = VGet(30.0f, 30.0f, 0.0f);
		Boss1Size = VGet(50.0f, 50.0f, 0.0f);

		if (Collision::CheckHitBoxToBox(PlayerPos, PlayerSize, Boss1Pos, Boss1Size))
		{
			if (!player.Hit())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

bool CollisionManager::CheckHitPlayerToEnemy1Shot(Player& player, ShotManager& shotmanager)
{
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		ShotEnemy& EnemyShot = shotmanager.GetEnemyShot(i);

		if (!EnemyShot.IsActive())
		{
			continue;
		}
		VECTOR PlayerPos, EnemyShotPos;
		float PlayerRadi, EnemyShotRadi;

		PlayerPos = player.GetPosition();
		EnemyShot.GetPosition(EnemyShotPos);

		PlayerRadi = 5.0f;
		EnemyShotRadi = 6.0f;
		if (player.GetInviCount() < 0) {
			if (Collision::CheckHitSphereToSphere(PlayerPos, PlayerRadi, EnemyShotPos, EnemyShotRadi))
			{
				if (!player.Hit())
				{
					return true;
				}
				else
				{

					return false;
				}
			}
		}
	}
	return false;
}

bool CollisionManager::CheckHitPlayerToBoss1Shot(Player& player, ShotManager& shotmanager)
{
	bool isactive = player.GetIsActive();
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		BossShot& Boss1Shot = shotmanager.GetBoss1Shot(i);

		if (!Boss1Shot.IsActive())
		{
			continue;
		}
		VECTOR PlayerPos, Boss1ShotPos;
		float PlayerRadi, Boss1ShotRadi;

		PlayerPos = player.GetPosition();
		Boss1Shot.GetPosition(Boss1ShotPos);

		PlayerRadi = 5.0f;
		Boss1ShotRadi = 10.0f;
		
		if (player.GetInviCount() <= 0) {
			if (Collision::CheckHitSphereToSphere(PlayerPos, PlayerRadi, Boss1ShotPos, Boss1ShotRadi))
			{
				
				if (!player.Hit())
				{
					
					return true;
				}
				else
				{

					return false;
				}
			}
		}
	}
	return false;
}

bool CollisionManager::CheckHitPlayerShotToBoss1(ShotManager& shotmanager, EnemyManager& enemymanager)
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		ShotPL &Plshot = shotmanager.GetPlayerShot(i);
		if (!Plshot.IsActive())
		{
			continue;
		}
		for (int j = 0; j < ENEMY_NUM; j++)
		{
			Boss1 &boss1 = enemymanager.GetBoss1(j);
			if (!boss1.IsActive())
			{
				continue;
			}

			VECTOR PlayerShotPos, Boss1Pos;
			float PlayerShotRadi, Boss1Radi;
			int DMG = 1;
			Plshot.GetPosition(PlayerShotPos);
			boss1.GetPos(Boss1Pos);

			PlayerShotRadi = 6.0f;
			Boss1Radi = 40.0f;
			
			if (Collision::CheckHitSphereToSphere(PlayerShotPos, PlayerShotRadi, Boss1Pos, Boss1Radi))
			{
				Plshot.Hit();
				if (!boss1.Hit(DMG))
				{
					return false;
				}
				else
				{
					return true;
				}
				
			}
		}
		
	}
	return false;
}