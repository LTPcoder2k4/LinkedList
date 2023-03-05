#pragma once

struct Video {
	char* title;
	char category[5];
	int quantity;
};

//Input video
Video videoInput();

//Data migration
void videoCopy(Video*, Video);

//Display video
void videoDisplay(const Video&);

//Clear data
void videoEmpty(Video*&);