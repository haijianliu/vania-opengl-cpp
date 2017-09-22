
#include "Engine.hpp"

/*------------------------------------------------------------------------------
< Constructor >
------------------------------------------------------------------------------*/
Scene01::Scene01() {

}


/*------------------------------------------------------------------------------
< Destructor >
------------------------------------------------------------------------------*/
Scene01::~Scene01() {

}


/*------------------------------------------------------------------------------
< load > in Scene start()
------------------------------------------------------------------------------*/
void Scene01::load() {
	/* Scene::loadMapData(const char* name, const char* path);
	..............................................................................*/
	// map
	this->tiledMap->loadMapData("TileObject2", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene01-BackGround2.csv");
	this->tiledMap->loadMapData("TileObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene01-BackGround.csv");
	this->tiledMap->loadMapData("ColliderObject", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene01-Ground.csv");
	this->tiledMap->loadMapData("CameraRange", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene01-Camera.csv");
	this->tiledMap->loadMapData("Range", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene01-Range.csv");
	// enemy
	this->tiledMap->loadMapData("Block", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene01-Block.csv");
	this->tiledMap->loadMapData("Crab", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene01-Crab.csv");
	this->tiledMap->loadMapData("AI", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene01-AI.csv");
	// item
	this->tiledMap->loadMapData("Orb", "/Users/haijian/Documents/OpenGL/vania-OpenGL/vania-OpenGL/Maps/scene_Scene01-Orb.csv");
}


/*------------------------------------------------------------------------------
< set > in Scene start()
------------------------------------------------------------------------------*/
void Scene01::set() {
	// BackGround Object
	this->backGround2nd->sprite->texture = getGame()->resources->getTexture("background_2nd");
	this->backGround4th->sprite->texture = getGame()->resources->getTexture("background_4th");
	this->backGround2nd->sprite->setSlice(0.0f,0.0f,SCREEN_WIDTH,SCREEN_HEIGHT);
	this->backGround4th->sprite->setSlice(0.0f,0.0f,SCREEN_WIDTH,SCREEN_HEIGHT);
	this->backGround2nd->active = true;
	this->backGround4th->active = true;
}


/*------------------------------------------------------------------------------
< end > before Scene update()
------------------------------------------------------------------------------*/
void Scene01::end() {
	// Check Switch Scene
	if (getGame()->player->transform->position.x < this->tiledMap->gameObjects["Range"][0]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene00");
	}
	if (getGame()->player->transform->position.x > this->tiledMap->gameObjects["Range"][1]->transform->position.x) {
		getGame()->sceneManager->setActiveScene("Scene02");
	}
}


/*------------------------------------------------------------------------------
< reset > in SceneManager setActiveScene()
------------------------------------------------------------------------------*/
void Scene01::reset() {
	// frameDelay
	this->frameSkip = true;
}


/*------------------------------------------------------------------------------
< clear >
------------------------------------------------------------------------------*/
void Scene01::clear() {

}