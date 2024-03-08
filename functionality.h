/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 
 Muhammad Saad Mursaleen
  22I-0835
  CS-A
  project
 
 
 
 * */

//---Piece Starts to Fall When Game Starts---//



void fallingPiece(double& timer, double& delay,long long int& colorNum){
	
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }

        if (!anamoly()){
        	for(int i=0;i<4;i++)
        		gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
        	colorNum=1+rand()%7;
           long int n=rand()%7;
            
            //--- Un-Comment this Part When You Make BLOCKS array---//
                for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 2;
                    point_1[i][1] = BLOCKS[n][i] / 2;
                }
            
        }
        timer=0;
        
    }
    delay=0.4;

}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///


bool shadowcheck(int saad1[4][2],int saad2[4][2])        
{

	for(int i=0;i<4;i++){
		if(saad1[i][0]>=N||saad1[i][1]>=M||saad1[i][0]<0)     // anamoly of shadow similar to anamoly given
		return false;
		}
	for(int i=0;i<4;i++){	
		if(gameGrid[saad1[i][1]][saad1[i][0]])
		return 0;
		}
		
		
  return true;
		
}

void shadowmove( long long int& dx, int saad1[4][2], int saad2[4][2])
{
	int i=0;										// movement of shadow

	while(i<4)
	{
		saad1[i][0]=saad2[i][0];
		saad1[i][0]=saad1[i][0]+dx;   				// movement of shadow on x axis
		
		i=i+1;	
	}
	if(shadowcheck(saad1,saad2)==0)
	{
		i=0;
		while(i<4)
		{
		
			saad1[i][0]=saad2[i][0];
			i=i+1;
		}
	
	}
}

void shadowhere(long long int dx,long long int colorNum, int saad1[4][2], int saad2[4][2] )     // 
{
	
	int i=0;

	while(i<4)
	{
	
		for(int j=0; j<2; j++)
		{
			saad1[i][j]=point_1[i][j];
			saad2[i][j]=point_1[i][j];     // storing points of bllock in another array
			
			
		}
		i=i+1;
	}
	
	do
	{
		
		for(int i=0;i<4;i++)
		{
		
			saad2[i][0]=saad1[i][0];
			saad2[i][1]=saad1[i][1];           //down function till anamoly
			saad1[i][1]=saad1[i][1]+1;
		
		}
		
		
	
	}while(shadowcheck(saad1,saad2));
	
	if(dx)
	{
	
		shadowmove(dx,saad1,saad2);
	}




}








void fallguys(){
	
	do{
	int sa=0;
        while (sa<4){
            point_2[sa][0]=point_1[sa][0];
            point_2[sa][1]=point_1[sa][1];
            point_1[sa][1]+=1;   
            
            sa=sa+1;            // using the same function as the down one but repetitively    
        }
        	}while(anamoly());			// This runs the loop until the bottom boundary or another tile is reached 
    for(int sa=0;sa<4;sa++){
		point_1[sa][1]-=1;
	}
    
	
}


void leftright(long long int a){
	int sa=0;
	while(sa<4){
		point_2[sa][0]=point_1[sa][0];
           	point_2[sa][1]=point_1[sa][1];
	   	point_1[sa][0]+=a;   // 0 used instead of 1 to move horizontally
	   	sa=sa+1;
           }
         if(!anamoly()){
         	for(int sa=0;sa<4;sa++){
         		point_1[sa][0]=point_2[sa][0];
           		point_1[sa][1]=point_2[sa][1];
         	}
         }
           
	
        
	
}







int destroy73(long long int& score ,long long  int& level){

	long int z=0;
	long int x=M-1;
	long int y;
	long int c=0;
	for(int i=M-1;i>0;i--){  
		y=0;
		c=0;
		for(int j=0;j<N;j++){
			if(gameGrid[i][j]){
				y=y+1;         		// Checking all the columns  
			}
			gameGrid[x][j]=gameGrid[i][j];
		}
		if(y>=N){				//y<n
							
			c=c+1;
		}
		else{					// This is done for calculating score
			x=x-1;
		}
		
		/*if(c==4){
			score=score+(level*100);
		}
		else if(c==2){
			score=score+(level*30);
		} */
		if(c==1){
			score=score+(level*10);
		}
		
	/*	
		else if(c==3){
			score=score+(level*60);
		}
		*/
	}
	return score;
}

bool endgame(){
	for (int s=N;s>=0;s--){
		if(gameGrid[1][s]){      //checkiing top line if grid position is on
			return 1;
		}
	}
	return false;
}


void rotation(bool& rotate){
	if(rotate=true){
		int s=0;
		while(s<4){
			
			long long int pointoRx =point_1[s][1] - point_1[1][1];   // finding x coordinate of point of rotation
			long long int pointoRy=point_1[s][0] - point_1[1][0];    // finding y coordinate of point of rotation
			point_1[s][0]=point_1[1][0]-pointoRx;
			point_1[s][1]=point_1[1][1]+pointoRy;
			s=s+1;		
		}
		if(!anamoly()){
			s=0;
			while(s<4){
				point_1[s][0]=point_2[s][0];
				point_1[s][1]=point_2[s][1];
				s=s+1;
			}
		}	
	}
	
}












	


///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
