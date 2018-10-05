//Alex Jones
//CS 3150
//09-28-2018

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include "dungeonFunctions.h"

using namespace std;

int x;
int y;
char map[12][12];
int obs[12][12];

int main(){
	x=1;
	y=1;
	char move;
	bool alive = true;
	
	srand(time(NULL));
	//this for loop sets the strings in the map array to be (#), which represents an unvisited space
	for(int i=0; i<12; i++){
		for(int j=0; j<12; j++){
			if(i==0 || i==11 || j==0 || j==11){
				map[i][j] = ' ';
			}
			else{
				map[i][j] = '#';
			}
		}
	}
	//these next two are just to represent entrance and exit doors
	map[1][0] = '[';
	map[10][11] = ']';
	//The asterisk is to mark current location, player starts at 1,1
	map[1][1] = '*';
	//this for loop fills obs with potential obstacles, randomly with numbers 1-10
	for(int x=0; x<12; x++){
		for(int y=0; y<12; y++){
			//this surrounds the map with 0's so that players will die if they try to go off of the edge of the map.
			if(x==0 || x==11 || y==0 || y==11){
				obs[y][x] = 0;
			}
			else{
				obs[y][x] = (rand()%20)+1;
			}
		}
	}
	//one is a safe number, to guarantee they don't die right as the game begins
	obs[1][1] = 1;
	//eleven will signify a game won
	obs[10][10] = 21;
	
	cout<< "WELCOME TO MY EVIL LAIR! ESCAPE IF YOU DARE!"<<endl;
	dungeon();
	while(alive){
		for(int a=0; a<12; a++){
			for(int b=0; b<12; b++){
				cout<<map[a][b];
				
			}
			cout<<endl;
		}
		/* for(int c=0; c<12; c++){
			for(int d=0; d<12; d++){
				cout<<obs[c][d];
				
			}
			cout<<endl;
		} */
		cout<<"Make your choice; W, A, S, D.  Remember, don't run into the walls or re-visit a space!"<<endl;
		cin>>move;
		move = tolower(move);
		//this while loop checks for valid input
		while(move!='w' && move!='a' && move!='s' && move!='d'){
			cout<<"That was not valid input, try again."<<endl;
			cin>>move;
			move = tolower(move);
		}
		//switch statement runs the selected function
		switch(tolower(move)){
			case 'w': up(); break;
			case 's': down(); break;
			case 'a': left(); break;
			case 'd': right(); break;
		}
		//when a player hits a specific obstacle, the corresponding function is ran
		switch(obs[y][x]){
			case 8: dead();lost();alive=false;break;
			case 2: teleport();break;
			case 13: alien();lost();alive=false;break;
			case 0: invalid();lost();alive=false;break;
			case 21: won();alive=false;
		}
		/*if(obs[x][y]==7){
			dead();
			end();
			alive = false;
		}
		else if(obs[x][y]==2){
			teleport();
			continue;
		}
		else if(obs[x][y]==4){
			alien();
			end();
			alive = false;
		}
		else if(obs[x][y]==11){
			won();
			alive = false;
		}
		else{
			continue;
		}*/
	}
	
	
}