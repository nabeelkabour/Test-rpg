#include "Pages.h"

void MainPage::update(Game* engine)
{
	if (engine->GetKey(olc::Key::ENTER).bPressed)
	{
		engine->_page_state = &PageState::name_page;
	}
}

void MainPage::draw(Game* engine)
{

}

void NamePage::update(Game* engine)
{

}

void NamePage::draw(Game* engine)
{

}
