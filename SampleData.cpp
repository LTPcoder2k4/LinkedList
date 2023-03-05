#include "SampleData.h"
#include <iostream>
#include <cstring>

using namespace std;

Video videoInput() {
	//Decalre the temporary variable to store data
	Video video{};

	//Input the title of video
	cout << "Title: ";
	
	//Declare a dummy variable to store the title before assign it to title of video
	char temp[100];
	cin.getline(temp, 100, '\n');

	//Allocate the title of video
	video.title = new char[strlen(temp) + 1];

	//Copy the data from dummy to the official one
	strcpy_s(video.title, strlen(temp) + 1, temp);

	//Input the category
	cout << "Category: ";
	cin.getline(video.category, 5, '\n');

	//Input the quantity
	cout << "Quantity: "; cin >> video.quantity;

	//Return the new video
	return video;
}

void videoCopy(Video* dst, Video src) {
	//Allocate new title
	dst->title = new char[strlen(src.title) + 1];

	//Copy the title
	strcpy_s(dst->title, strlen(src.title) + 1, src.title);

	//Copy the category
	strcpy_s(dst->category, strlen(src.category) + 1, src.category);

	//Copy the quantity
	dst->quantity = src.quantity;
}

void videoDisplay(const Video& video) {
	//Print the title
	cout << "Title: " << video.title << '\n';

	//Print the category
	cout << "Category: " << video.category << '\n';

	//Print the quantity
	cout << "Quantity: " << video.quantity << '\n';
}

void videoEmpty(Video* &video) {
	//Delete the allocated memory of title
	delete video->title;
}