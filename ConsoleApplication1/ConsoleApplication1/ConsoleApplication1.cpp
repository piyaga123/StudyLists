// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "memory.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Song {

public:

	Song(const std::wstring& artist, const std::wstring& title) :m_artist(artist), m_title(title) {};
	Song() {};
	
public:
	std::wstring m_artist;
	std::wstring m_title;
};

unique_ptr<Song> SongFactory(const std::wstring& artist, const std::wstring& title)
{
	// Implicit move operation into the variable that stores the result.
	return make_unique<Song>(artist, title);
}

void MakeSongs()
{
	// Create a new unique_ptr with a new object.
	auto song = make_unique<Song>(L"Mr. Children", L"Namonaki Uta");

	// Use the unique_ptr.
	vector<wstring> titles = { song->m_title };

	// Move raw pointer from one unique_ptr to another.
	unique_ptr<Song> song2 = std::move(song);
	//unique_ptr<Song> song2_5 = song2; //Should not compile as song2 is a unique_ptr

	// Obtain unique_ptr from function that returns by value.
	auto song3 = SongFactory(L"Michael Jackson", L"Beat It");
}

void SongVector() {

	vector<unique_ptr<Song>> songs;

	songs.push_back(make_unique<Song>(L"Mr. Children", L"Namonaki Uta"));
	songs.push_back(make_unique<Song>(L"B'z", L"Juice"));
	songs.push_back(make_unique<Song>(L"Namie Amuro", L"Funky Town"));
	songs.push_back(make_unique<Song>(L"Kome Kome Club", L"Kimi ga Iru Dake de"));
	songs.push_back(make_unique<Song>(L"Ayumi Hamasaki", L"Poker Face"));

	for (const auto& song : songs)
	{
		wcout << L"Artist: " << song->m_artist << L"   Title: " << song->m_title << endl;
		song = nullptr;

	}
	int ii = 0;
	remove this line 
}

int main()
{
	MakeSongs();
	SongVector();
    return 0;
}

