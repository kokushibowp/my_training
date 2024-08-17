#pragma once
#include <list>
#include <Windows.h>

// ������ ����� � ��������� ������� � https://www.cyberforum.ru/cpp-beginners/thread223822.html

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
	//Menu(const Menu& other);                              ���� ������� ����
	//Menu& operator=(const Menu& other);                   �� � �� ������ ��� ��� ����� �����
	//Menu(const Menu&& other);                             ������ ��� ������� ����� ���� ������ ���� singleton'��
	//Menu& operator=(const Menu&& other);                  ���� ��� ��� ������ ��� �������� ����� � ������� ���� ������ ������ ����?)
	//~Menu();

	void add_item(char* itemName);                   //     �������� ����� � ����, ����� ���������� ���� ������� ���������� ������� draw_menu()
	void del_item(int numItem);                      //     ����� ������� ������ ������� del_item() ���������� �������������� ���� ����������������� �������� clear_screen() � draw_menu()
	void set_cursor(int numItem);
	void draw_menu();
	void clear_screen();
	void move_up();
	void move_down();
	void set_color(WORD dColor, WORD sColor);
	unsigned int get_cursor_pos();
	void menu_processor(bool (*f)(Menu* menu));
};