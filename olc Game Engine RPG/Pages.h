#ifndef PAGES_H
#define PAGES_H

#include "Game.h"

class Game;

class PageState
{
public:
	static MainPage	main_menu;
	static NamePage name_page;

	virtual ~PageState() {};
	virtual void update(Game* engine) {};
	virtual void draw(Game* engine) {};
};

class MainPage : public PageState
{
public:
	virtual void update(Game* engine) override;
	virtual void draw(Game* engine) override;
};

class NamePage : public PageState
{
public:
	virtual void update(Game* engine) override;
	virtual void draw(Game* engine) override;
};

#endif
