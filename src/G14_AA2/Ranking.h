#pragma once
#include "Scene.h"
class Ranking : public Scene
{
public:
	Ranking();
	~Ranking();
	void Update() override;
	void Draw() override;
	void HandleEvents() override;
};

