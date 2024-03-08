/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * 

  Muhammad Saad Mursaleen
  22I-0835
  CS-A
  Project
  
  */




#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include <sstream>
#include <SFML/Audio.hpp>

using namespace sf;
int main(){
    srand(time(0));
    const char menu[]=" Main Menu ";
    RenderWindow window(VideoMode(500, 480), title);
    Texture obj1, obj2, obj3, obj4;
    
    //    Load "frames.png","tiles.png" and "background.png" for Texture objects
    
    obj2.loadFromFile("img/background.png"); 
    obj1.loadFromFile("img/tiles.png");
       
    
    obj4.loadFromFile("img/tiles1.png");     // object for shadow
    obj3.loadFromFile("img/frame.png");   
    
    Sprite sprite(obj1), background(obj2), frame(obj3), shadow(obj4);
    int saad1[4][2], saad2[4][2];
    
    long long int delta_x=0, colorNum=5;
    
    double timer=0, delay=0.25;
    long long int x=0;
    bool rotate=false;
    bool p=false;
    long long int score=0, level=1;
    bool wait=true;
    Clock clock;
    long long int M = 20;  
    long long int N=10; 
   
    
    float btime=0;
    float bdelay=0.3;
    // int gameGrid[20][10] = {0};
    while (window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
       

        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e)){                    //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
		    if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
		        if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
		            rotate = true;                         //Rotation gets on
		        else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
		            delta_x = -1;                         //Change in X-Axis - Negative
		        else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
		            delta_x = 1;    				//Change in X-Axis - Positive
		        else if (e.key.code == Keyboard::Down) {  //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
		        	delay=0.02;      
		        	}          
                
            }
            
            
        }                     


        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
  /*   
        
        
    /]  sf::Music music;
	if (!music.openFromFile("saadmusic.ogg"))    // Trying to add music
    	return -1; // error
	music.play();
     
      sf::SoundBuffer buffer;
	buffer.loadFromFile("saadmusic.ogg");
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
        
        
        
 /     Music tetmus;
        if(tetmus.openFromFile("saadmusic.ogg")){
        	tetmus.play();
        }
   */   shadowhere(delta_x,colorNum,saad1,saad2);   // function to display shadow
        
        destroy73(score,level);             // Funtion to delete lines and calculate score
        if(endgame()){				// Function to end the program when tiles reach the top
      		window.close();
      	}
        if(rotate == true){			// function to rotate the tiles
        	rotation(rotate); 
         	rotate=false;
         	}
        fallingPiece(timer, delay, colorNum);   // falling piece function
       
     	leftright(delta_x);			// left right function
     	
     	delta_x=0;
        
      	
    
        if(e.key.code == Keyboard::Space){    
      		fallguys();	            // function to drop down the tile to bottom 
      	}			
      
      

     
         


        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////
	

        window.clear(Color::Black);
        window.draw(background);
        
       
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);

          }
          
          
         for (int i=0; i<4; i++){
            shadow.setTextureRect(IntRect(colorNum*18,0,18,18));    
            shadow.setPosition(saad1[i][0]*18,saad2[i][1]*18);
            shadow.move(28,31);
            window.draw(shadow);

          }
          
          for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        
        sf::Font scoredesign;
        scoredesign.loadFromFile("Raleway-Black.ttf");
     
        sf::Text head;
        head.setFont(scoredesign);
        head.setString("SCORE: ");
        head.setPosition({330,150});
        window.draw(head);
        
        sf::Text scorenum(std::to_string(score), scoredesign);
        scorenum.setPosition({450,150});
        window.draw(scorenum);
          
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
    }
    
   
    return 0;
}
