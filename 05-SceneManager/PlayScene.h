#pragma once
#include "Game.h"
#include "Textures.h"
#include "Scene.h"
#include "GameObject.h"
#include "Brick.h"
#include "Mario.h"
#include "Goomba.h"
#include "Koopa.h"
#include "InvisibleBlock.h"
#include "Spawner.h"
//#include "Koopas.h"


class CPlayScene: public CScene
{
protected: 
	// A play scene has to have player, right? 
	LPGAMEOBJECT player;
	LPGAMEOBJECT ScoreBoard;
	CSpawner* curSpawner;
	vector<LPGAMEOBJECT> objects;

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_OBJECTS(string line);

	void LoadAssets(LPCWSTR assetFile);
	
public: 
	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();


	LPGAMEOBJECT GetPlayer() { return player; }

	void AddNewObjectToTail(LPGAMEOBJECT obj) {
		this->objects.push_back(obj);
	}
	void AddNewObjectToHead(LPGAMEOBJECT obj) {
		this->objects.insert(this->objects.begin(), obj);
	}
	void AddAfterObject(LPGAMEOBJECT obj,LPGAMEOBJECT after) {
		auto it = std::find(objects.begin(), objects.end(), after);
		if (it == objects.end()) {
			return;
		}
		objects.insert(it + 1, obj);
	}

	void AddBeforeObject(LPGAMEOBJECT obj, LPGAMEOBJECT before) {
		auto it = std::find(objects.begin(), objects.end(), before);
		if (it == objects.end()) {
			return;
		}
		objects.insert(it, obj);
	}


	void Clear();
	void PurgeDeletedObjects();

	static bool IsGameObjectDeleted(const LPGAMEOBJECT& o);
};

typedef CPlayScene* LPPLAYSCENE;

