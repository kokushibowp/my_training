#pragma once
#include <list>
#include <Windows.h>

// данный класс — переделка примера с https://www.cyberforum.ru/cpp-beginners/thread223822.html

class Menu {
private:
	std::list<char*> items;
	unsigned int countItems;
	unsigned int latestCursorPos;
	HANDLE gout;
	WORD defaultColor = 0x0F;
	WORD selectedColor = 0x1F;                        
	COORD menuCoords = { 0 };
	bool isDrawed = 0;
public:
	Menu(COORD coords); 
	//Menu(const Menu& other);                              типа правило пяти
	//Menu& operator=(const Menu& other);                   но я не уверен что оно здесь нужно
	//Menu(const Menu&& other);                             вообще мне кажется класс меню должен быть singleton'ом
	//Menu& operator=(const Menu&& other);                  ведь как это вообще так возможно чтобы в консоли было больше одного меню?)
	//~Menu();

	void add_item(char* itemName);                   //     добавить пункт в меню, после добавления всех пунктов необходимо вызвать draw_menu()
	void del_item(int numItem);                      //     после каждого вызова функции del_item() необходимо перерисовывать меню последовательными вызовами clear_screen() и draw_menu()
	void set_cursor(int numItem);
	void draw_menu();
	void clear_screen();
	void move_up();
	void move_down();
	void set_color(WORD dColor, WORD sColor);
	unsigned int get_cursor_pos();
	void menu_processor(bool (*f)(Menu* menu));
};