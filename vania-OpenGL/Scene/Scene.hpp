
#ifndef Scene_hpp
#define Scene_hpp

class Scene {
private:
	// global GameObjects and Colliders parameter
	std::vector<GameObject*>* gpGameObjects;
	std::vector<BoxCollider*>* gpColliders;
	unsigned int startGameObjectsSize;
	unsigned int startCollidersSize;

	// tiled map Setting
	int tileSize = 16;
	glm::vec2 mapSize = glm::vec2(225,90);
	glm::vec2 tilesetsSize = glm::vec2(384/16,320/16);

	// tiled map data
	std::map<const char*, std::vector<glm::i32vec2>> mapDatas;
	std::map<const char*, std::vector<GameObject*>> sceneGameObjects;

public:
	// Scene GameObjects and Colliders
	std::vector<GameObject*> gameObjects;
	std::vector<BoxCollider*> colliders;
	// SceneManager
	Resources* resources;
	// Camera
	Camera* camera;
	// Timer
	Timer* timer;
	// Audio

	// Frame Delay
	bool frameSkip = true; // skip the first frame


	Scene();
	virtual ~Scene();

	virtual void start();
	void setScene();
	virtual void update();
	void draw();

	// Functions
	bool checkCollision(BoxCollider* a, BoxCollider* b);
	void checkCollider();
	bool loadMapData(const char* name, const char* path);
	void setTile(GameObject* gameObject, int mapID, int tileID);
	void setPosition(GameObject* gameObject, int mapID);
	void reset();
};


#endif /* Scene_hpp */
