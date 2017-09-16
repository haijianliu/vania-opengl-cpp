
#ifndef GameObject_hpp
#define GameObject_hpp

class GameObject {
private:
	// List of GameObjects
	std::vector<GameObject*>* gameObjects;

public:
	// Global classes
	Timer* timer;
	Camera* camera;
	Resources* resources;

	// GameObject members
	Transform* transform;
	Sprite* sprite;

	// status
	float birthTime = 0;
	bool active = true;
	bool visible = true;

	GameObject();
	virtual ~GameObject();

	void defaultStart();
	void draw();

	virtual void start() = 0;
	virtual void update() = 0;
	virtual void fixedUpdate() = 0;
	virtual void onTriggerEnter(BoxCollider* other) = 0;
};

#endif /* GameObject_hpp */
