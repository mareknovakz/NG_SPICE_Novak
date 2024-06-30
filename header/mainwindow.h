//Class for creating main window. Window will openning if is program running

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ncsurses.h>
#include <string>

class MainWindow{
public:
	MainWindow (int height, int width, int startY, int startX);
	~MainWindow();

	void printText(const std::string& text);
	void refreshWindow();
	void clearWindow();
	void getUserInput(std::string& input);

private:
	WINDOW* window;
	int height; //Sets height window
	int width;  //Sets height width
	int StartY; //Initialization location window on a monitor
	int StartX; //Initialization location window on a monitor
};

#endif 