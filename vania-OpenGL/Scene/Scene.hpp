
#ifndef Scene_hpp
#define Scene_hpp

class Scene {
private:
	// tiled map Setting
	int tileSize = 16;
	glm::i32vec2 mapSize = glm::i32vec2(225,90);
	glm::i32vec2 tilesetsSize = glm::i32vec2(384/16,320/16);

public:
	// Scene GameObjects and Colliders
	std::vector<GameObject*> gameObjects;
	std::vector<BoxCollider*> colliders;

	// tiled map data
	std::map<const char*, std::vector<glm::i32vec2>> mapDatas;
	std::map<const char*, std::vector<GameObject*>> sceneGameObjects;

	// Camera
	Camera* camera;

	// Frame Delay
	bool frameSkip = true; // skip the first frame

	// Constructors
	Scene();
	virtual ~Scene();

	void start();
	void update();

	virtual void load() = 0;
	virtual void end() = 0;
	virtual void reset() = 0;
	virtual void clear() = 0;

	// Functions
	bool loadMapData(const char* name, const char* path);
	void createGameObject(const char* name);
	void setGameObject(const char* name);

	void setTile(GameObject* gameObject, int mapID, int tileID);
	void setPosition(GameObject* gameObject, int mapID);


	void fixCamera(const char* name);

	bool checkCollision(BoxCollider* a, BoxCollider* b);
	void checkCollider();

};


#endif /* Scene_hpp */
