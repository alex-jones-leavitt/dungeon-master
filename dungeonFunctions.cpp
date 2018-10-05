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

void up(){
	y--;
	map[y][x] = '*';
	map[y+1][x] = '-';
	obs[y+1][x] = 0;
}

void down(){
	y++;
	map[y][x] = '*';
	map[y-1][x] = '-';
	obs[y-1][x] = 0;
}

void left(){
	x--;
	map[y][x] = '*';
	map[y][x+1] = '-';
	obs[y][x+1] = 0;
}

void right(){
	x++;
	map[y][x] = '*';
	map[y][x-1] = '-';
	obs[y][x-1] = 0;
}

void dungeon(){
	cout<<R"(                                    |~
                                   /\//
                                  /  \\
                                  :~~@|        
                                  :__]|.
                                 :=====|
                                  :~~@|
                                  :  ]|
                       |~         :  ]|
                      / \   |~    :  ]|
                     /   \ / \    :__]|_.
                     :   :/ / \_  :=====|
                    :=========/ \ :~~~@|
                     :~~~~@~~/\  \:   ]|
                     :  |   /  \ .]/\ ]|_
                     :  /\_/[][]\./..\ ]|_
                     :  [= |_MM_| [==]# ]|
                 /\  :  [-H- -- -{__i]#_]|__.
                /\ \-:  [    H   ][#][#] ] ~|.
       \  \ \  /  \ \:  [ H  H  H; I#I |]] I |.
     \   \  \ : II \ |__[        ;     |]]   #]    /   /
   \   \  wet : mm  I|++  H  H  H;     |]/\  #] wet  /  /
 \   \water   :  n  i|++   ,     ; NHN |/_-\ #]  water  /  /
  \ wetter |##      i|   _HHH__ _;_HNH |[ ##-#]_  wetter /    /
 \waterwet |##  ~~~~==== HHHHH     :HN  [ ###-#]   waterwet  /
 waterwet  |##__****___HHH___HHH~~~L_H_J[ ###\#]   waterwater  /
 waterwet  |############# ### ####T##T##[\##]###]   wetterwet
 wetter    |####T###T####[www# ]########[ ##] /    waterwater /
wetwet     |#############[www# ]##T##T##[ ##]/    wetterwater
waterwet   ###////////////====\##\\\\\\\\####   wetterwater
 wetwater                 |  |                 wetwaterwet
   waterwaterwaterwaterwet|  |wetterwaterwetterwaterwet
      waterwaterwaterwater|  |waterwaterwaterwaterwet
                          |  |)"<<endl;
}

void dead(){
	cout<<"You spontaneously combusted. You dead."<<endl;
	cout<<R"(                            (
                .            )        )
                         (  (|              .
                     )   )\/ ( ( (
             *  (   ((  /     ))\))  (  )    )
           (     \   )\(          |  ))( )  (|
           >)     ))/   |          )/  \((  ) \
           (     (      .        -.     V )/   )(    (
            \   /     .   \            .       \))   ))
              )(      (  | |   )            .    (  /
             )(    ,'))     \ /          \( `.    )
             (\>  ,'/__      ))            __`.  /
            ( \   | /  ___   ( \/     ___   \ | ( (
             \.)  |/  /   \__      __/   \   \|  ))
            .  \. |>  \      | __ |      /   <|  /
                 )/    \____/ :..: \____/     \ <
          )   \ (|__  .      / ;: \          __| )  (
         ((    )\)  ~--_     --  --      _--~    /  ))
          \    (    |  ||               ||  |   (  /
                \.  |  ||_             _||  |  /
                  > :  |  ~V+-I_I_I-+V~  |  : (.
                 (  \:  T\   _     _   /T  : ./
                  \  :    T^T T-+-T T^T    ;<
                   \..`_       -+-       _'  )
         )            . `--=.._____..=--'. ./         (
        ((     ) (          )             (     ) (   )> 
         > \/^/) )) (   ( /(.      ))     ))._/(__))./ (_.
        (  _../ ( \))    )   \ (  / \.  ./ ||  ..__:|  _. \
        |  \__.  ) |   (/  /: :)) |   \/   |(  <.._  )|  ) )
       ))  _./   |  )  ))  __  <  | :(     :))   .//( :  : |
       (: <     ):  --:   ^  \  )(   )\/:   /   /_/ ) :._) :
        \..)   (_..  ..  :    :  : .(   \..:..    ./__.  ./
                   ^    ^      \^ ^           ^\/^     ^)"<<endl;
}

void teleport(){
	cout<<"OOOH, you are being teleported through time and space."<<endl<<"Good luck!"<<endl;
	map[y][x] = '-';
	obs[y][x] = 0;
	srand(time(NULL));
	x = (rand()%10)+1;
	y = (rand()%10)+1;
	map[y][x] = '*';
	cout<<R"(                      .   *        .       .
       *      -0-
          .                .  *       - )-
       .      *       o       .       *
 o                |
           .     -O-
.                 |        *      .     -0-
       *  o     .    '       *      .        o
              .         .        |      *
   *             *              -O-          .
         .             *         |     ,
                .           o
        .---.
  =   _/__~0_\_     .  *            o       '
 = = (_________)             .
                 .                        *
       *               - ) -       *)"<<endl;
}

void alien(){
	cout<<"You have been abducted by aliens."<<endl;
	cout<<"Is that good?"<<endl;
	cout<<"Is that bad?"<<endl;
	cout<<"I dunno."<<endl;
	cout<<"Either way,"<<endl;
	cout<<"you lost."<<endl;
	cout<<R"(             ,-"     "-.
            / o       o \
           /   \     /   \
          /     )-"-(     \
         /     ( 6 6 )     \
        /       \ " /       \
       /         )=(         \
      /   o   .--"-"--.   o   \
     /    I  /  -   -  \  I    \
 .--(    (_}y/\       /\y{_)    )--.
(    ".___l\/__\_____/__\/l___,"    )
 \                                 /
  "-._      o O o O o O o      _,-"
      `--Y--.___________.--Y--'
         |==.___________.==| 
         `==.___________.==' )"<<endl;
}

void invalid(){
	cout<<"You just couldn't follow the rules, could you?"<<endl;
	cout<<R"(                                           .""--.._
                                           []      `'--.._
                                           ||__           `'-,
                                         `)||_ ```'--..       \
                     _                    /|//}        ``--._  |
                  .'` `'.                /////}              `\/
                 /  .""".\              //{///    
                /  /_  _`\\            // `||
                | |(_)(_)||          _//   ||
                | |  /\  )|        _///\   ||
                | |L====J |       / |/ |   ||
               /  /'-..-' /    .'`  \  |   ||
              /   |  :: | |_.-`      |  \  ||
             /|   `\-::.| |          \   | ||
           /` `|   /    | |          |   / ||
         |`    \   |    / /          \  |  ||
        |       `\_|    |/      ,.__. \ |  ||
        /                     /`    `\ ||  ||
       |           .         /        \||  ||
       |                     |         |/  ||
       /         /           |         (   ||
      /          .           /          )  ||
     |            \          |             ||
    /             |          /             ||
   |\            /          |              ||
   \ `-._       |           /              ||
    \ ,//`\    /`           |              ||
     ///\  \  |             \              ||
    |||| ) |__/             |              ||
    |||| `.(                |              ||
    `\\` /`                 /              ||
       /`                   /              ||
      /                     |              ||
     |                      \              ||
    /                        |             ||
  /`                          \            ||
/`                            |            ||
`-.___,-.      .-.        ___,'            ||
         `---'`   `'----'`)"<<endl;
}

void lost(){
	char lost;
	cout<<"Dang, you lost. Bummer. Wanna try again?! (y/n)"<<endl;
	cin>>lost;
	lost = tolower(lost);
	while(lost!='y' && lost!='n'){
		cout<<"That is not valid input. Please only enter a y for yes or n for no."<<endl;
		cin>>lost;
		lost = tolower(lost);
	}
	if(lost=='y'){
		cout<<"SAHWEET!"<<endl;
		main();
	}
	else{
		cout<<"OKEY BAI."<<endl;
	}
}

void won(){
	char won;
	cout<<"LOOKIE HERE, you won! Wanna go again?! (y/n)"<<endl;
	cin>>won;
	won = tolower(won);
	while(won!='y' && won!='n'){
		cout<<"That is not valid input. Please only enter a y for yes or n for no."<<endl;
		cin>>won;
		won = tolower(won);
	}
	if(won=='y'){
		cout<<"SAHWEET!"<<endl;
		main();
	}
	else{
		cout<<"OKEY BAI."<<endl;
	}
}
