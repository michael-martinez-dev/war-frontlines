#pragma once
#include "BaseView.h"
#include "GridView.h"

class FriendlyBaseView : public BaseView, protected GridView {
public:
	FriendlyBaseView(const Base& base);
	void render(Game& game) override;
};
