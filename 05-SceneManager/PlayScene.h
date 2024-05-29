#pragma once
#include "Game.h"
#include "Textures.h"
#include "Scene.h"
#include "GameObject.h"
#include "Brick.h"
#include "Mario.h"
#include "Goomba.h"
#include "Koopa.h"
//#include "Koopas.h"


class CPlayScene: public CScene
{
protected: 
	// A play scene has to have player, right? 
	LPGAMEOBJECT player;					

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
		// Tìm vị trí của đối tượng 'after' trong danh sách
		auto it = std::find(objects.begin(), objects.end(), after);
		// Nếu không tìm thấy đối tượng 'after', không làm gì
		if (it == objects.end()) {
			return;
		}
		// Chèn đối tượng mới vào ngay sau vị trí của 'after'
		objects.insert(it + 1, obj);
	}

	void AddBeforeObject(LPGAMEOBJECT obj, LPGAMEOBJECT before) {
		// Tìm vị trí của đối tượng 'before' trong danh sách
		auto it = std::find(objects.begin(), objects.end(), before);
		// Nếu không tìm thấy đối tượng 'before', không làm gì
		if (it == objects.end()) {
			return;
		}
		// Chèn đối tượng mới vào ngay trước vị trí của 'before'
		objects.insert(it, obj);
	}


	void Clear();
	void PurgeDeletedObjects();

	static bool IsGameObjectDeleted(const LPGAMEOBJECT& o);
};

typedef CPlayScene* LPPLAYSCENE;

