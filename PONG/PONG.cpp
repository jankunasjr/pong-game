#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <set>
#include <vector>
#include <map>
#include <fstream>
#include <cmath>
#include <time.h>
#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <exception>
using namespace std;

string name1, name2;
static int score1, score2;

HANDLE hOut;

void clearScreen() // Direct implementation of "cls"
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

class Game_Interface
{
protected:
	int select_mode;
	int select;
	int valid_select;
	int coordinates;
public:
	Game_Interface()
	{
		select_mode = 0;
		select = 0;
		valid_select = false;
		coordinates = 5;
	}
	virtual void Draw_Interface() = 0;

	int get_select(){
		return select;
	}
	int get_select_mode(){
		return select_mode;
	}
};
class Start_Screen : public Game_Interface
{
public:
	void Draw_Interface() override
	{
		for (int i = 0; i < 40 + 1; i++) cout << "\xDC";						//ceiling
		
		cout << endl;

		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				if (j == 0) cout << "\xDB";           //left wall
				if (j == 40 - 1) cout << "\xDB";           //right wall
				else cout << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < 40 + 1; i++) cout << "\xDF";						//floor
		
		cout << endl;

		COORD p;

		p.X = int(40 / 2 - 2);
		p.Y = int(8);

		SetConsoleCursorPosition(hOut, p);

		cout << "PONG" << endl;
		p.X = int(40 / 2 - 7);
		p.Y = int(12);

		SetConsoleCursorPosition(hOut, p);

		cout << "1.Start Game" << endl;

		p.X = int(40 / 2 - 7);
		p.Y = int(14);

		SetConsoleCursorPosition(hOut, p);

		cout << "2.Leaderboard" << endl;

		p.X = int(40 / 2 - 7);
		p.Y = int(16);

		SetConsoleCursorPosition(hOut, p);

		cout << "3.Exit Game" << endl;
	}
	void game_start()
	{
		while (!valid_select)
		{
			valid_select = true;
			if (_kbhit())
			{
				select = _getch();
				select = select - '0';
			}
			if (select < 1 || select > 3) valid_select = false;
		}
		system("cls");
		if (select == 1)
		{
			for (int i = 0; i < 40 + 1; i++) cout << "\xDC";						 //ceiling

			cout << endl;

			for (int i = 0; i < 30; i++)
			{
				for (int j = 0; j < 40; j++)
				{
					if (j == 0) cout << "\xDB";           //left wall
					if (j == 40 - 1) cout << "\xDB";           //right wall
					else cout << " ";
				}
				cout << endl;
			}
			for (int i = 0; i < 40 + 1; i++) cout << "\xDF";						//floor
			
			cout << endl;

			COORD p;

			p.X = int(40 / 2 - 4);
			p.Y = int(12);

			SetConsoleCursorPosition(hOut, p);
			cout << "1.PvP" << endl;

			p.X = int(40 / 2 - 4);
			p.Y = int(14);

			SetConsoleCursorPosition(hOut, p);
			cout << "2.PvE" << endl;
			valid_select = false;
			while (!valid_select)
			{
				valid_select = true;
				if (_kbhit())
				{
					select_mode = _getch();
					select_mode = select_mode - '0';
				}
				if (select_mode < 1 || select_mode > 3) valid_select = false;
			}
		}
		system("cls");

		for (int i = 0; i < 40 + 1; i++) cout << "\xDC";						 //ceiling

		cout << endl;

		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				if (j == 0) cout << "\xDB";           //left wall
				if (j == 40 - 1) cout << "\xDB";           //right wall
				else cout << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < 40 + 1; i++) cout << "\xDF";						//floor

		cout << endl;
		if (select_mode == 1 && select == 1)
		{
			COORD p;

			p.X = int(2);
			p.Y = int(3);

			SetConsoleCursorPosition(hOut, p);
			cout << "Player 1 name: ";
			cin >> name1;

			while (1)
			{
				p.X = int(2);
				p.Y = int(coordinates);
				SetConsoleCursorPosition(hOut, p);
				cout << "Player 2 name: ";
				cin >> name2;
				coordinates += 2;
				if (name2 == "Enemy")
				{
					p.X = int(2);
					p.Y = int(coordinates);
					SetConsoleCursorPosition(hOut, p);
					cout << "Invalid name" << endl;
					coordinates += 2;
				}
				else break;
			}
			
		}
		else if (select == 1 && select_mode == 2)
		{
			COORD p;

			p.X = int(2);
			p.Y = int(3);

			SetConsoleCursorPosition(hOut, p);
			cout << "Player 1 name: ";
			cin >> name1;
			name2 = "Enemy";
		}
	}
};
class End_Screen : public Game_Interface
{
public:
	void who_won()
	{
		if (score1 > score2) throw name1;
		else if (score1 < score2) throw name2;
	}
	void Draw_Interface() override
	{
		for (int i = 0; i < 40 + 1; i++) cout << "\xDC";						//ceiling
		
		cout << endl;

		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				if (j == 0) cout << "\xDB";           //left wall
				if (j == 40 - 1) cout << "\xDB";           //right wall
				else cout << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < 40 + 1; i++) cout << "\xDF";						//floor
		
		cout << endl;

		COORD p;

		p.X = int(40 / 2 - 7);
		p.Y = int(12);

		SetConsoleCursorPosition(hOut, p);

		cout << "1.Title Screen" << endl;

		p.X = int(40 / 2 - 7);
		p.Y = int(14);

		SetConsoleCursorPosition(hOut, p);

		cout << "2.Exit Game" << endl;
	}
};

class Gameplay_Objects
{
protected:
	int x, y;
	int og_X, og_Y;
	int direction;
public:
	Gameplay_Objects(int posX, int posY)
	{
		og_X = posX;
		og_Y = posY;
		x = posX;
		y = posY;
		direction = 0;
	}

	int getX(){
		return x;
	}
	int getY(){
		return y;
	}

};
class Ball : public Gameplay_Objects
{
public:
	Ball(int posX, int posY) : Gameplay_Objects(posX, posY) {}

	void change_dir(int d){
		direction = d;
	}
	int get_dir(){
		return direction;
	}
	void Reset()
	{
		x = og_X;
		y = og_Y;
		direction = 0;
	}
	void Move()
	{
		while (1)
		{
			if (direction == 0) //no movement
				break;
			else if (direction == 1)  // move down
			{
				y++;
				break;
			}
			else if (direction == 2) // move downleft        
			{
				x--;
				y++;
				break;
			}
			else if (direction == 3)  //move downright
			{
				x++;
				y++;
				break;
			}
			else if (direction == 4)  // move up
			{
				y--;
				break;
			}
			else if (direction == 5)  // move upleft
			{
				x--;
				y--;
				break;
			}
			else if (direction == 6) // move upright
			{
				x++;
				y--;
				break;
			}
		}
	}
};
class Paddle : public Gameplay_Objects
{
public:
	Paddle(int posX, int posY) : Gameplay_Objects(posX, posY) {}

	void Reset()
	{
		x = og_X;
		y = og_Y;
	}
	void Move_Left(){
		x -= 2;
	}
	void Move_Right(){
		x += 2;
	}
	void Move_Right_AI(){
		x++;
	}
	void Move_Left_AI(){
		x--;
	}
};

class game_manager
{
private:
	int width, height, end_game, win;
	Ball* ball;
	Paddle* player1;
	Paddle* player2;
public:
	game_manager()
	{
		win = 0;
		end_game = 0;
		score1 = 0;
		score2 = 0;
		width = 40;
		height = 30;
		ball = new Ball(40 / 2, 30 / 2);
		player1 = new Paddle(40 / 2 - 3, 30 - 1);
		player2 = new Paddle(40 / 2 - 3, 0);
	}
	~game_manager()
	{
		delete ball, player1, player2;
	}
	int end(){
		return end_game;
	}
	int get_win(){
		return win;
	}
	void Draw()
	{
		clearScreen();
		for (int i = 0; i < width + 2; i++) cout << "\xDC";   //ceiling
		
		cout << endl;

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j == 0) cout << "\xDB";                                         //left wall
				
				if (ball->getX() == j && ball->getY() == i)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "0";											//ball
				}
				else if (player1->getX() == j && player1->getY() == i)
				{
					SetConsoleTextAttribute(hConsole, 11);
					cout << "=";											//player 1
				}
				else if (player1->getX() + 1 == j && player1->getY() == i)
				{
					SetConsoleTextAttribute(hConsole, 11);
					cout << "=";											//player 1
				}
				else if (player1->getX() + 2 == j && player1->getY() == i)
				{
					SetConsoleTextAttribute(hConsole, 11);
					cout << "=";											//player 1
				}
				else if (player1->getX() + 3 == j && player1->getY() == i)
				{
					SetConsoleTextAttribute(hConsole, 11);
					cout << "=";											//player 1
				}
				else if (player1->getX() + 4 == j && player1->getY() == i)
				{
					SetConsoleTextAttribute(hConsole, 11);
					cout << "=";											//player 1
				}
				else if (player1->getX() + 5 == j && player1->getY() == i)
				{
					SetConsoleTextAttribute(hConsole, 11);
					cout << "=";											//player1                         
				}
				else if (player1->getX() + 6 == j && player1->getY() == i)
				{
					SetConsoleTextAttribute(hConsole, 11);
					cout << "=";											//player1
				}
				else if (player2->getX() == j && player2->getY() == i)
				{
					if (name2 != "Enemy") SetConsoleTextAttribute(hConsole, 11);
					else SetConsoleTextAttribute(hConsole, 13);
					
					cout << "=";											//player2
				}
				else if (player2->getX() + 1 == j && player2->getY() == i)
				{
					if (name2 != "Enemy") SetConsoleTextAttribute(hConsole, 11);
					else SetConsoleTextAttribute(hConsole, 13);
					
					cout << "=";											//player2
				}
				else if (player2->getX() + 2 == j && player2->getY() == i)
				{
					if (name2 != "Enemy") SetConsoleTextAttribute(hConsole, 11);
					else SetConsoleTextAttribute(hConsole, 13);

					cout << "=";											//player2
				}
				else if (player2->getX() + 3 == j && player2->getY() == i)
				{
					if (name2 != "Enemy") SetConsoleTextAttribute(hConsole, 11);
					else SetConsoleTextAttribute(hConsole, 13);

					cout << "=";												//player2
				}
				else if (player2->getX() + 4 == j && player2->getY() == i)
				{
					if (name2 != "Enemy") SetConsoleTextAttribute(hConsole, 11);
					else SetConsoleTextAttribute(hConsole, 13);

					cout << "=";												//player2
				}
				else if (player2->getX() + 5 == j && player2->getY() == i)
				{
					if (name2 != "Enemy") SetConsoleTextAttribute(hConsole, 11);
					else SetConsoleTextAttribute(hConsole, 13);
					
					cout << "=";													//player2
				}
				else if (player2->getX() + 6 == j && player2->getY() == i)
				{
					if (name2 != "Enemy") SetConsoleTextAttribute(hConsole, 11);
					else SetConsoleTextAttribute(hConsole, 13);

					cout << "=";													//player2
				}
				else cout << " ";

				SetConsoleTextAttribute(hConsole, 15);
				if (j == width - 1) cout << "\xDB";
			}
			cout << endl;
		}
		for (int i = 0; i < width + 2; i++) cout << "\xDF";										//floor

		cout << endl;

		cout << name1 << ": " << score1 << endl << name2 << ": " << score2 << endl;
	}
	void input()
	{
		ball->Move();

		if (_kbhit())
		{
			char key = _getch();
			if (key == 'a')
			{
				if (player1->getX() > 0) 
					player1->Move_Left();
			}
			if (GetAsyncKeyState(VK_LEFT) && name2 != "Enemy")
			{
				if (player2->getX() > 0)
					player2->Move_Left();
			}
			if (key == 'd')
			{
				if (player1->getX() + 8 < width)     
					player1->Move_Right();
			}
			if (GetAsyncKeyState(VK_RIGHT) && name2 != "Enemy")
			{
				if (player2->getX() + 8 < width)        
					player2->Move_Right();
			}

			if (ball->get_dir() == 0 && score1 >= score2) ball->change_dir(4);
			else if (ball->get_dir() == 0 && score1 < score2) ball->change_dir(1);
			if (key == 'q') end_game = 1;
		}
	}
	void logic()
	{
		for (int i = 0; i < 8; i++) //lower paddle
		{
			if (ball->getY() == player1->getY() - 1)
			{
				if (ball->getX() + 1 == player1->getX() + i)
					ball->change_dir(((rand() % 3) + 4));     //if ball touches paddle it bounces off up, upleft or upright
			}
		}
		for (int i = 0; i < 8; i++) //upper paddle
		{
			if (ball->getY() == player2->getY() + 1)
			{
				if (ball->getX() + 1 == player2->getX() + i)
					ball->change_dir(((rand() % 3) + 1));   //if ball touches paddle it bounces off down,downleft or downright
			}
		}

		if (ball->getX() == width - 1)   //right wall
		{
			if (ball->get_dir() == 6){
				ball->change_dir(5);
			}											//if ball touches right wall and the directions was upright
			else                                          //then direction change to upleft else downleft
				ball->change_dir(2);
		}

		if (ball->getX() == 0) //left wall
		{
			if (ball->get_dir() == 5){  //if ball touches left wall and the directions was upleft                                 
				ball->change_dir(6);                //then direction change to upright else downright
			}
			else 
				ball->change_dir(3);
		}

		if (ball->getY() > height)    // floor 
		{
			score2++;
			ball->Reset();
			player1->Reset();
			player2->Reset();
		}
		if (ball->getY() < -1) // ceiling
		{
			score1++;
			ball->Reset();
			player1->Reset();
			player2->Reset();
		}
	}
	void AI()
	{
		if (ball->getX() != 20 && ball->getY() != 15)
		{
			if (ball->getX() - 1 < player2->getX())
			{
				if (player2->getX() > 0) 
					player2->Move_Left_AI();
			}
			if (ball->getX() - 1 > player2->getX())
			{
				if (player2->getX() + 8 < width)
					player2->Move_Right_AI();
			}
		}
	}
	void operator ++(int){
		win = abs(score1 - score2);
	}
};

class leaderboard
{
private:
	int num, player_scores, name_amount, coordinate;
	string player_names;
	map<string, int> leaderboard_map;
	vector<int> scores;
	set<string>dif_names;
	bool found_player1, found_player2;
	ifstream in1, in2;
	ofstream of1, of2;
public:
	leaderboard()
	{
		num = 0;
		name_amount = 0;
		player_scores = 0;
		found_player1 = false;
		found_player2 = false;
		coordinate = 5;
	}
	~leaderboard()
	{
		scores.clear();
		in1.close();
		in2.close();
		of1.close();
		of2.close();
	}
	void leaderboards()
	{
		in1.open("scores.txt");
		in2.open("players.txt");
		while (!in2.eof())
		{
			in1 >> player_scores;
			in2 >> player_names;                   //input scores and player names from files
			dif_names.insert(player_names);
			leaderboard_map[player_names] = player_scores;
		}

		int name_amount = dif_names.size();
		dif_names.insert(name1);

		if (dif_names.size() > name_amount) leaderboard_map[name1] = score1;
		else found_player1 = true; //check if names are already on the leaderboard

		if (name2 != "Enemy")
		{
			if (found_player1 == false && dif_names.size() > name_amount) leaderboard_map[name2] = score2;
			else if (dif_names.size() - 1 > name_amount) leaderboard_map[name2] = score2;
			else found_player2 = true;
		}

		if (found_player1 == true || found_player2 == true)
		{
			for (map<string, int>::iterator it = leaderboard_map.begin(); it != leaderboard_map.end(); it++)
			{
				if (it->first == name1 && it->second < score1) leaderboard_map[name1] = score1;
				if (it->first == name2 && it->second < score2) leaderboard_map[name2] = score2;
			}
		}

		for (map<string, int>::iterator it = leaderboard_map.begin(); it != leaderboard_map.end(); it++)
			scores.push_back(it->second);

		sort(scores.begin(), scores.end());

		of1.open("scores.txt");
		of2.open("players.txt");

		for (int i = scores.size() - 1; i >= 0; i--)
		{
			for (map<string, int>::iterator it = leaderboard_map.begin(); it != leaderboard_map.end(); it++)
			{
				if (scores[i] == it->second && it->first != "\0" && num < 10)
				{
					of1 << it->second << endl;
					of2 << it->first << endl;
					leaderboard_map.erase(it->first);
					num++;
					break;
				}
			}
		}
	}
	void draw_leaderboard()
	{
		in1.open("scores.txt");
		in2.open("players.txt");
		while (!in2.eof())
		{
			in1 >> player_scores;
			in2 >> player_names;                   //input scores and player names from files
			dif_names.insert(player_names);
			leaderboard_map[player_names] = player_scores;
		}

		for (map<string, int>::iterator it = leaderboard_map.begin(); it != leaderboard_map.end(); it++)
			scores.push_back(it->second);

		sort(scores.begin(), scores.end());

		of1.open("scores.txt");
		of2.open("players.txt");
		COORD p;

		p.X = int(40 / 2 - 6);
		p.Y = int(3);
		SetConsoleCursorPosition(hOut, p);
		cout << "LEADERBOARD" << endl << endl;

		for (int i = scores.size() - 1; i >= 0; i--)
		{
			for (map<string, int>::iterator it = leaderboard_map.begin(); it != leaderboard_map.end(); it++)
			{
				if (scores[i] == it->second && it->first != "\0" && num < 10)
				{
					COORD p;

					p.X = int(40 / 2 - 6);
					p.Y = int(coordinate);

					SetConsoleCursorPosition(hOut, p);
					cout << num + 1 << ". " << it->first << " " << it->second << endl;
					of1 << it->second << endl;
					of2 << it->first << endl;
					leaderboard_map.erase(it->first);
					num++;
					coordinate += 2;
					break;
				}
			}
		}
	}
};

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);                     //changes consoles dimensions
	MoveWindow(console, r.left, r.top, 200, 200, TRUE);

	char key_mode;
	game_manager m;
	leaderboard l;
	Start_Screen s;
	End_Screen e;

	Game_Interface* s1 = new Start_Screen();
	Game_Interface* s2 = new End_Screen();

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);          //hide console cursor
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = false;
	SetConsoleCursorInfo(hOut, &ConCurInf);

	system("cls");
	s1->Draw_Interface();
	s.game_start();

	if (s.get_select() == 1)
	{
		if (s.get_select_mode() == 1)
		{
			while (1)
			{
				m.Draw();
				m.input();          
				m.logic();
				m++;
				Sleep(3);
				if (m.end() == 1 || m.get_win() >= 10) break;
			}
			system("cls");
			s2->Draw_Interface();
			l.leaderboards();
			if (m.end() != 1)
			{
				try{
					e.who_won();
				}
				catch (string x)
				{
					COORD p;

					p.X = int(40 / 2 - 7);
					p.Y = int(8);

					SetConsoleCursorPosition(hOut, p);
					cout << x << " has Won";
				}
			}
			else
			{
				COORD p;

				p.X = int(40 / 2 - 5);
				p.Y = int(8);

				SetConsoleCursorPosition(hOut, p);
				cout << "FORCED END";
			}
			while (1)
			{
				key_mode = _getch();
				key_mode = key_mode - '0';
				if (key_mode == 1) return main();
				else if (key_mode == 2){
					system("cls");
					return 0;
				}
			}
		}
		else if (s.get_select_mode() == 2)
		{
			while (1)
			{
				m.Draw();
				m.input();
				m.logic();
				m.AI();
				m++;
				Sleep(3);
				if (m.end() == 1 || m.get_win() >= 10) break;
			}
			system("cls");
			s2->Draw_Interface();
			l.leaderboards();
			if (m.end() != 1)
			{
				try{
					e.who_won();
				}
				catch (string x)
				{
					COORD p;

					p.X = int(40 / 2 - 7);
					p.Y = int(8);

					SetConsoleCursorPosition(hOut, p);
					cout << x << " has Won";
				}
			}
			else
			{
				COORD p;

				p.X = int(40 / 2 - 5);
				p.Y = int(8);

				SetConsoleCursorPosition(hOut, p);
				cout << "FORCED END";
			}
			while (1)
			{
				key_mode = _getch();
				key_mode = key_mode - '0';
				if (key_mode == 1) return main();
				else if (key_mode == 2)
				{
					system("cls");
					delete s1, s2;
					return 0;
				}
			}
		}
	}
	if (s.get_select() == 2)
	{
		while (1)
		{
			l.draw_leaderboard();
			char key = _getch();
			if (key == 'q') return main();
		}
	}
	if (s.get_select() == 3)
	{
		delete s1, s2;
		system("cls");
		return 0;
	}
}
