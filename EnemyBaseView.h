#pragma once
#include "BaseView.h"
#include "GridView.h"

class EnemyBaseView : public BaseView, protected GridView
{
public:
	EnemyBaseView(const Base& base);
	void render(Game& game) override;
};

