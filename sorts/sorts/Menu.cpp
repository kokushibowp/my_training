#include "Menu.h"
#include <iostream>

// данный класс Ч переделка примера с https://www.cyberforum.ru/cpp-beginners/thread223822.html

Menu::Menu(COORD coords) : countItems(0), latestCursorPos(0), menuCoords(coords) {
	gout = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Menu::add_item(char* itemName) {
	items.push_back(itemName);
	
	++countItems;
}

void Menu::del_item(int numItem) {
	std::list<char*>::iterator it = items.begin();
	for (int i = 1; i < numItem; ++i) ++it;
	items.erase(it);
	--countItems;
}

void Menu::set_cursor(int numItem) {                                                                                    // вызывать только после draw_menu()
	if (!isDrawed)return;
	if ((numItem > countItems) || (numItem < 1))return;
	COORD cursorCoords;
	DWORD dw;
	std::list<char*>::iterator it;
	
	cursorCoords.X = menuCoords.X-1;
	cursorCoords.Y = menuCoords.Y - 1 + latestCursorPos;
	
	FillConsoleOutputCharacterA(gout, ' ', 1, cursorCoords, &dw);
	it = items.begin();
	for (int i = 1; (i < latestCursorPos) ; ++i) {
		if (it != items.end()) ++it;
	}
	if (it != items.end()) FillConsoleOutputAttribute(gout, defaultColor, strlen(*it) + 1, cursorCoords, &dw);
	
	cursorCoords.Y = menuCoords.Y-1+numItem;
	FillConsoleOutputCharacterA(gout, '>', 1, cursorCoords, &dw);
	it = items.begin();
	for (int i = 1; (i < numItem) ; ++i) {
		if(it != items.end()) ++it;
	}
	if (it != items.end()) FillConsoleOutputAttribute(gout, selectedColor, strlen(*it)+1, cursorCoords, &dw);
	
	latestCursorPos = numItem;
}

void Menu::draw_menu() {
	COORD currentCoords = menuCoords;
	DWORD dw = 0;
	std::list<char*>::iterator it = items.begin();
	for (int i = 0; i < countItems; ++i) {
		WriteConsoleOutputCharacterA(gout, *it, strlen(*it), currentCoords, &dw);
		FillConsoleOutputAttribute(gout, defaultColor, strlen(*it), currentCoords, &dw);
		++it;
		++currentCoords.Y;
	}
	isDrawed = 1;
	set_cursor(1);
}

void Menu::clear_screen() {
	system("CLS");
	/*COORD currentCoords = menuCoords;
	DWORD dw = 0;
	for (int i = 0; i < countItems; ++i) {
		WriteConsoleOutputCharacterA(gout, "                                                                                                   ", 100, currentCoords, &dw);
		++currentCoords.Y;
	}*/
}

void Menu::move_up() {
	if (latestCursorPos != 1) set_cursor(latestCursorPos - 1);
	else set_cursor(countItems);
}

void Menu::move_down() {
	if (latestCursorPos != countItems) set_cursor(latestCursorPos + 1);
	else set_cursor(1);
}

void Menu::set_color(WORD dColor, WORD sColor) {                                                                        // пример: set_color(0x03, 0x2F), вызывать перед draw_menu()
	defaultColor = dColor;
	selectedColor = sColor;
}

unsigned int Menu::get_cursor_pos() {
	return latestCursorPos;
}

void Menu::menu_processor(bool (*f)(Menu* menu)) {
	while (1) {
		if ((GetKeyState(VK_UP) == -127) || (GetKeyState(VK_UP) == -128)) {
			move_up();
			Sleep(150);
		}
		else if ((GetKeyState(VK_DOWN) == -127) || (GetKeyState(VK_DOWN) == -128)) {
			move_down();
			Sleep(150);
		}
		else if ((GetKeyState(VK_RETURN) == -127) || (GetKeyState(VK_RETURN) == -128)) {
			if(!f(this))return;
			Sleep(150);
		}
	}
}