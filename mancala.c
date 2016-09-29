/*
Project 2
File: mancala.c
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int pos,x,curPos, players, player, player_1, position, cur_position,s;


//============================================================

int main(void)
{ 
//initialize board board values 
int board[14];
  board[0] = 4;
  board[1] = 4;
  board[2] = 4;
  board[3] = 4;
  board[4] = 4;
  board[5] = 4;
  board[6] = 0;
  board[7] = 4;
  board[8] = 4;
  board[9] = 4;
  board[10] = 4;
  board[11] = 4;
  board[12] = 4;
  board[13] = 0;
//welcome users, set again='y' and enter while loop
printf("\nWelcome to Mancala!\n");
//set again equal to 'y' so to enter while loop
char again='y';
int players;
//while again is y
while (again=='y' || again=='Y')
	{  
	//ask if one or two user game
	printf("How many players will be playing?");
	printf("\nOptions:\n1. One Player \n2. Two Players\n");
	scanf("%d", &players);
	//if 1 player, enter function playing with computer
	if (players==1)
		{
		one_player(board);
		}
	//if 2 players enter function for 2 user input
	if (players==2)
		{
		two_player(board);
		}
	//ask if want to play again after completing a game	
	printf("Do you want to play again? Y or N \n");
	scanf("%s", &again);
	}	
//end program
return 0;
} 

//=================================================================

int one_player(int board[])
{  
 //initialize the values of every board and mancala
  board[0] = 4;
  board[1] = 4;
  board[2] = 4;
  board[3] = 4;
  board[4] = 4;
  board[5] = 4;
  board[6] = 0;
  board[7] = 4;
  board[8] = 4;
  board[9] = 4;
  board[10] = 4;
  board[11] = 4;
  board[12] = 4;
  board[13] = 0;
int position, s=1, cur_position, direction;
  int sum = board[6] + board[13];
//enter function to determine who will move first
  int player_1=first_player();

//display the current look of the board  
cur_board(board);
 //while all the marble are not in the mancala
  while (sum != 48)
  {
	//with computer player_1=0, complete computer's move
	if (player_1==0)
	{
		
		printf("Computer Turn\n");
		//select position through random generator and check if it fit parameter
		position=run();
       
		//check to make sure chosen position is on correct side. 
		//If not, allows for resubmission until it is
		while (position!=6 && position!=7 && position!=8 && position!=9 && position!=10 && position!=11)
			{
			position=run();	
			}
		//enter function to determine direction of move
		direction=dir_move();
		if (direction==0)
			{
			printf("Moved position %d in clockwise direction\n", position);	
			//add one to position so to coincide with array
			position +=1;
			//enter function to complete the move
			cur_position=move_clockwise(board, position, player_1);
			//display updated board and position from which the move was made
			cur_board(board);
			//check if there are still marbles in current player's bowls
			s=complete(player_1, board);
			}
			
		if(direction==1)
			{
			printf("Moved position %d in counter-clockwise direction\n", position);
			//add one to position so to coincide with array
			position +=1;
			//enter function to complete the move
			cur_position=move_counter(board, position, player_1);
			//display updated board and position from which the move was made
			cur_board(board);
			//check if there are still marbles in current player's bowls
			s=complete(player_1, board);
			}
			
		//check if the player can go again, if so, allow them another turn
		while(cur_position==13 && s==2)
		{
			printf("\n***************************\n");
			printf("    COMPUTER GOES AGAIN\n");
			printf("***************************\n");
			printf("Computer Turn\n");
       
			position=run();
			
			//check to make sure chosen position is on correct side. 
			//If not, allows for resubmission until it is
			while (position!=6 && position!=7 && position!=8 && position!=9 && position!=10 && position!=11)
				{
				position=run();	
				}
			//enter function to determine direction of computer's move
			direction=dir_move();
			if (direction==0)
				{
				printf("Moved position %d in clockwise direction\n", position);	
				//add one to position so to coincide with array
				position +=1;
				//enter function to complete the move
				cur_position=move_clockwise(board, position, player_1);
				//display updated board and position from which the move was made
				cur_board(board);
				//check if there are still marbles in current player's bowls
				s=complete(player_1, board);
				}
			if(direction==1)
				{
				printf("Moved position %d in counter-clockwise direction\n", position);
				//add one to position so to coincide with array
				position +=1;
				//enter function to complete the move
				cur_position=move_counter(board, position, player_1);
				//display updated board and position from which the move was made
				cur_board(board);
				//check if there are still marbles in current player's bowls
				s=complete(player_1, board);
				}
		}
		//add 1 so next player can go
		player_1 +=1;
	}
	//calculate sum of both mancala
	sum = board[6] + board[13];
	
	//while it is second player and the sum of the mancala is less than 48
	if (player_1==1 && sum !=48)
		{
			//print current player and allow them to pick a position they want to 
			//move marbles from
			printf("Player BLUE\n");
			printf("Pick a position corresponding to the integer: ");
			scanf("%d", &position);
       
			//check to make sure chosen position is on correct side. 
			//If not, allows for resubmission until it is
			while (position!=0 && position!=1 && position!=2 && position!=3 && position!=4 && position!=5)
				{
				printf("\nInvalid input, you have to select a bowl from your side.\nPlease select another position\n");
				scanf("%d",&position);	
				}
			printf("\nPlease choose which direction you want to move in");
			printf("\nOptions:\n0.Clockwise \n1. Counter-Clockwise\n");
			scanf("%d",&direction);
			if (direction==0)
				{
				//enter function to complete the move
				cur_position=move_clockwise(board, position, player_1);
				//display updated board and position from which the move was made
				cur_board(board);
				//check if there are still marbles in current player's bowls
				s=complete(player_1, board);
				}
			if(direction==1)
				{
				//enter function to complete the move
				cur_position=move_counter(board, position, player_1);
				//display updated board and position from which the move was made
				cur_board(board);
				//check if there are still marbles in current player's bowls
				s=complete(player_1, board);
				}
		//check if the player can go again, if so, allow them another turn
		while(cur_position==6 && s==2)
			{
			printf("***************************\n");
			printf("    BLUE GOES AGAIN\n");
			printf("***************************\n");
			printf("Player BLUE\n");
			printf("Pick a position corresponding to the integer: ");
			scanf("%d", &position);
       
			//check to make sure chosen position is on correct side. 
			//If not, allows for resubmission until it is
			while (position!=0 && position!=1 && position!=2 && position!=3 && position!=4 && position!=5)
				{
				printf("\nInvalid input, you have to select a bowl from your side.\nPlease select another position\n");
				scanf("%d",&position);	
				}
			//ask user to choose a direction they want to move in and check to 
			//make sure it is a valid input
			printf("\nPlease choose which direction you want to move in");
			printf("\nOptions:\n0. Clockwise \n1. Counter-Clockwise\n");
			scanf("%d",&direction);
			while(direction!=1 && direction!=0)
				{
				printf("Invalid input. Pick another number\n");
				scanf("%d", &direction);
				}
			if (direction==0)
				{
				//enter function to complete the move
				cur_position=move_clockwise(board, position, player_1);
				//display updated board and position from which the move was made
				cur_board(board);
				//check if there are still marbles in current player's bowls
				s=complete(player_1, board);
				}
			if(direction==1)
				{
				//enter function to complete the move
				cur_position=move_counter(board, position, player_1);
				//display updated board and position from which the move was made
				cur_board(board);
				//check if there are still marbles in current player's bowls
				s=complete(player_1, board);
				}
			}
		//subtract 1 from player so next player can go
		player_1 -=1;
		}
	//calculate the sum of both mancala
	sum = board[6] + board[13];
  }
  //print final score and winner of game
  printf("		Final Board Outcome\n\n");
  printf("SCORE:\n");
  printf("BLUE			RED\n");
  printf("%d			%d", board[6], board[13]);
  cur_board(board);
  winner_one(board);
  return 0;
} 

//=====================================================================

int two_player(int board[])  
{  
 //initialize the values of every board and mancala
  board[0] = 4;
  board[1] = 4;
  board[2] = 4;
  board[3] = 4;
  board[4] = 4;
  board[5] = 4;
  board[6] = 0;
  board[7] = 4;
  board[8] = 4;
  board[9] = 4;
  board[10] = 4;
  board[11] = 4;
  board[12] = 4;
  board[13] = 0;
int position, s=1, cur_position, direction;
  int sum;
  int player_1;
 //enter function and determine initial value of player 1 to determine
 //who will make the first move
  player_1=first_player();
  //calculate current sum of both mancala
  sum = board[6] + board[13];
  //display the board
 cur_board(board);
 //enter while loop and continue playing for as long as the number of 
 //marbles in both mancala is less than 48
  while (sum != 48)
  {
  
	if (player_1==0)
	{
		//print current player and allow them to pick a position they want to 
		//move marbles from
		printf("Player RED\n");
		printf("Pick a position corresponding to the integer: ");
		scanf("%d", &position);
       
		//check to make sure chosen position is on correct side. 
		//If not, allows for resubmission until it is
		while (position!=6 && position!=7 && position!=8 && position!=9 && position!=10 && position!=11)
			{
			printf("\nInvalid input, you have to select a bowl from your side.\nPlease select another position\n");
			scanf("%d",&position);	
			}
		
		printf("\nPlease choose which direction you want to move in");
		printf("\nOptions:\n0.Clockwise \n1. Counter-Clockwise\n");
		scanf("%d",&direction);
		if (direction==0)
			{
			//add one to position so to coincide with array
			position +=1;
			//enter function to complete the move
			cur_position=move_clockwise(board, position, player_1);
			//display updated board and position from which the move was made
			cur_board(board);
			//check if there are still marbles in current player's bowls
			s=complete(player_1, board);
			}
		if(direction==1)
			{
			//add one to position so to coincide with array
			position +=1;
			//enter function to complete the move
			cur_position=move_counter(board, position, player_1);
			//display updated board and position from which the move was made
			cur_board(board);
			//check if there are still marbles in current player's bowls
			s=complete(player_1, board);
			}
		//check if the player can go again, if so, allow them another turn
		while(cur_position==13 && s==2)
		{
			printf("\n***************************\n");
			printf("    RED GOES AGAIN \n");
			printf("***************************\n");
			printf("Player RED\n");
			printf("Pick a position corresponding to the integer: ");
			scanf("%d", &position);
			//check to make sure chosen position is on correct side. 
			//If not, allows for resubmission until it is
			while (position!=6 && position!=7 && position!=8 && position!=9 && position!=10 && position!=11)
			{
			printf("\nInvalid input, you have to select a bowl from your side.\nPlease select another position\n");
			scanf("%d",&position);	
			}
			//ask user to choose a direction they want to move in and check to 
			//make sure it is a valid input
			printf("\nPlease choose which direction you want to move in");
			printf("\nOptions:\n0. Clockwise \n1. Counter-Clockwise\n");
			scanf("%d",&direction);
			while(direction!=1 && direction!=0)
				{
				printf("Invalid input. Pick another number\n");
				scanf("%d", &direction);
				}
			if (direction==0)
				{
				//add one to position so to coincide with array
				position +=1;
				//enter function to complete the move
				cur_position=move_clockwise(board, position, player_1);
				//display updated board and position from which the move was made
				cur_board(board);
				//check if there are still marbles in current player's bowls
				s=complete(player_1, board);
				}
			if(direction==1)
				{
				//add one to position so to coincide with array
				position +=1;
				//enter function to complete the move
				cur_position=move_counter(board, position, player_1);
				//display updated board and position from which the move was made
				cur_board(board);
				//check if there are still marbles in current player's bowls
				s=complete(player_1, board);
				}
			}
		player_1 +=1;
	}
	//calculate the sum of both mancala
	sum = board[6] + board[13];
	
	//if it is second player and sum of mancala is less than 48
	if (player_1==1 && sum != 48)
		{
			//print current player and allow them to pick a position they want to 
			//move marbles from
			printf("Player BLUE\n");
			printf("Pick a position corresponding to the integer: ");
			scanf("%d", &position);
       
			//check to make sure chosen position is on correct side. 
			//If not, allows for resubmission until it is
			while (position!=0 && position!=1 && position!=2 && position!=3 && position!=4 && position!=5)
				{
				printf("\nInvalid input, you have to select a bowl from your side.\nPlease select another position\n");
				scanf("%d",&position);	
				}
			
			printf("\nPlease choose which direction you want to move in");
			printf("\nOptions:\n0. Clockwise \n1. Counter-Clockwise\n");
			scanf("%d",&direction);
			if (direction==0)
				{
				//enter function to complete the move
				cur_position=move_clockwise(board, position, player_1);
				//display updated board and position from which the move was made
				cur_board(board);
				//check if there are still marbles in current player's bowls
				s=complete(player_1, board);
				}
			if(direction==1)
				{
				//enter function to complete the move
				cur_position=move_counter(board, position, player_1);
				//display updated board and position from which the move was made
				cur_board(board);
				//check if there are still marbles in current player's bowls
				s=complete(player_1, board);
				}
		//check if the player can go again, if so, allow them another turn
		while(cur_position==6 && s==2)
			{
			printf("***************************\n");
			printf("    BLUE GOES AGAIN\n");
			printf("***************************\n");
			printf("Player BLUE\n");
			printf("Pick a position corresponding to the integer: ");
			scanf("%d", &position);
			//check to make sure chosen position is on correct side. 
			//If not, allows for resubmission until it is
			while (position!=0 && position!=1 && position!=2 && position!=3 && position!=4 && position!=5)
				{
				printf("\nInvalid input, you have to select a bowl from your side.\nPlease select another position\n");
				scanf("%d",&position);	
				}
			//ask user to choose a direction they want to move in and check to 
			//make sure it is a valid input
			printf("\nPlease choose which direction you want to move in");
			printf("\nOptions:\n0. Clockwise \n1. Counter-Clockwise\n");
			scanf("%d",&direction);
			while(direction!=1 && direction!=0)
				{
				printf("Invalid input. Pick another number\n");
				scanf("%d", &direction);
				}
			if (direction==0)
				{
				//enter function to complete the move
				cur_position=move_clockwise(board, position, player_1);
				//display updated board and position from which the move was made
				cur_board(board);
				//check if there are still marbles in current player's bowls
				s=complete(player_1, board);
				}
			if(direction==1)
				{
				//enter function to complete the move
				cur_position=move_counter(board, position, player_1);
				//display updated board and position from which the move was made
				cur_board(board);
				//check if there are still marbles in current player's bowls
				s=complete(player_1, board);
				}
			}
		//subtracts value of player by one so next turn 
		//can be made for other player
		player_1 -=1;
		}
	//calculates the sum of marbles in both mancala
	sum = board[6] + board[13];
  }
 //print final score and determine the winner
  printf("		Final Board Outcome\n\n");
  printf("SCORE:\n");
  printf("BLUE			RED\n");
  printf("%d			%d", board[6], board[13]);
  winner_two(board);
  //exists back to main function
  return 0;
}
 
//=============================================================
 
//function used to determine the direction computer will move
//in the single player game
int dir_move(void)
{
 int dir;
	//to determine direction of move for computer and returns int
	dir=rand()%2;	
	return (dir);
}
 
//============================================================= 
 
//function used to determine winner in a one player game
int winner_one(int board[])
{
//declare blue the winner if Computer has few marbles in mancala
if(board[13]>board[6])
	{
	printf("Computer is the winner!");
	printf("Too bad, better luck next time!\n\n");
	}
//declare BLUE the winner if RED has fewer marbles in mancala
if(board[13] < board[6])
	{
	printf("The winner:\n");
	printf("***************************\n");
	printf("   	 BLUE  \n");
	printf("***************************\n\n");
	printf("Great game! :-D\n\n");
	}
//declare a tie if marbles are equal in each side
if(board[13]==board[6])
	{
	printf("Looks like you tied");
	printf("Try your luck and play again!\n\n");
	}
return 0; 
}
 
//========================================================== 
 
//function used to determine the winner in a two player game
int winner_two(int board[])
{
//declare RED winner if RED has more marbles in mancala
if(board[13]>board[6])
	{
	printf("The winner:\n");
	printf("***************************\n");
	printf("   	 RED  \n");
	printf("***************************\n\n");
	printf("Great game! :-D\n\n");
	}
//declare blue the winner if RED has few marbles in mancala
if(board[13] < board[6])
	{
	printf("The winner:\n");
	printf("***************************\n");
	printf("   	 BLUE  \n");
	printf("***************************\n\n");
	printf("Great game! :-D\n\n");
	}
//if the value of both boards are equal, then print a tie
if(board[13]==board[6])
	{
	printf("Looks like you tied");
	printf("Try your luck and play again!\n\n");
	}
//exist function	
return 0; 
}
 
//=============================================================
 
//function used to pick a position for the computer
int run(void)
{
int place;
//set upper bound equal to 11 and generate number between 
//0-11 to return
place=rand()%12;
return (place);
}
 
//=============================================================

//function used to determine who will make the first move
int first_player(void)
{	
	int play;
	//to determine who will be player 1 when upper bound is 1 
	//in random generator and number is returned
	play=rand()%2;	
	return (play);
}
 
//=============================================================

//function used to move the marble clockwise
//and return the position of the last marble placed
int move_clockwise(int board[], int position, int player_1)
{
//set initial position equal to the chosen position
int initPos = position;
int i,curPos;
//enter for loop, adding in increments of 1, from 1 until 
//equal to number of marbles +1
  for (  i = 1; i < board[position] + 1; i++)
  {  
	//set the current position equal to the position -i
    int curPos = position -i;
    
	//if the current position becomes equal or more than 14
	//subtract it by 14 to set it back equal to range or array 
	//corresponding to the board
    if (curPos >= 14)
      curPos -= 14;
    //if the current position becomes equal or more than 28
	//subtract it by 28 to set it back equal to range or array 
	//corresponding to the board
    else if (curPos >= 28)
      curPos -= 28;
	
	//check if current position becomes less than 0 so t
	//return it back around the board to position 11 by adding 13
	else if (curPos<(0))
		{
		curPos+=13;
		}
    
	//if current player is player RED/Computer
	if (player_1 == 0)
    {
	//set pointer current1 to the array place of the current position 
	//for every current position gone over, add 1 to the value of the bowl
	//if the current position is in player BLUE's mancala
	//skip to next bowl 
      int * current1 = &(board[curPos]);
      if (current1 == &(board[6]))
	  
        current1 = &(board[5]);
      *current1 += 1;
    }    
     
	//if current player is player BLUE
    else if (player_1 == 1)
    {
	//set pointer current2 to the array place of the current position 
	//for every current position gone over, add 1 to the value of the bowl
	//if the current position is in player RED/Computer's mancala
	//skip to next bowl 
      int * current2 = &(board[curPos]);
      if (current2 == &(board[13]))
	  
        current2 = &(board[12]);
      *current2 += 1;
	  
    }
  }

//to calculate the placement of the last marble to return and 
//determine if the player will be able to get another turn  
//set the curPos equal to the in-putted position minus 1
curPos = position -1;
for (  i = 2; i < board[position] + 1; i++)
	{  
    //check if the current position is less than 0 so to
	//return to other side of board by adding 13
	if (curPos<(0))
		{
		curPos+=13;
		}
	//if current player is player BLUE
	if(curPos==13 && player_1==1)
		{
		curPos=12;
		}	
	//if current player is player RED/Computer
	if (curPos==6 && player_1==0)
		{
		curPos=5;
		}
	//if current player is player RED/Computer
	if (curPos==(-1) && player_1==0)
		{
		curPos=13;
		}
	//subtract 1 from the current position so to keep counting 
	//the placement while going clockwise
	curPos-=1;
	}
//set the value of the bowl in the chosen position 
//equal to zero so to empty it out
board[initPos] = 0;
// return the position of the last marble placed
return(curPos);
 }
 
//==========================================================================
 
//function used to move the marble counter-clockwise and returns the 
//position of the last marble placed
int move_counter(int board[], int position, int player_1)
{
//set initial position equal to the chosen position
int initPos = position;
int i,curPos;
//enter for loop, adding in increments of 1, from 1 until 
//equal to number of marbles +1
  for ( i = 1; i < board[position] + 1; i++)
  {  
	//set the current position equal to the position +i
    int curPos = position + i;
    
	//if the current position becomes equal or more than 14
	//subtract it by 14 to set it back equal to range or array 
	//corresponding to the board
    if (curPos >= 14)
      curPos -= 14;
	  
    //if the current position becomes equal or more than 14
	//subtract it by 14 to set it back equal to range or array 
	//corresponding to the board 
    else if (curPos >= 28)
      curPos -= 28;
 
	//if current player is player RED/Computer
    if (player_1 == 0)
    {
	//set pointer current1 to the array place of the current position 
	//for every current position gone over, add 1 to the value of the bowl
	//if the current position is in player BLUE's mancala
	//skip to next bowl 
      int * current1 = &(board[curPos]);
      if (current1 == &(board[6]))
	  
        current1 = &(board[7]);
      *current1 += 1;
	  
    }    
     
	//if current player is player BLUE
    else if (player_1 == 1)
    {
	//set pointer current1 to the array place of the current position 
	//for every current position gone over, add 1 to the value of the bowl
	//if the current position is in player RED/Computer's mancala
	//skip to next bowl 
      int * current2 = &(board[curPos]);
      if (current2 == &(board[13]))
	  
        current2 = &(board[0]);
      *current2 += 1;
	  
    }
  }
  
//to calculate the placement of the last marble to return and 
//determine if the player will be able to get another turn
  for ( i = 1; i < board[position] + 1; i++)
  {  
    curPos = position + i;
	//if current player is player BLUE
	if(curPos==13 && player_1==1)
		{
		curPos=0;
		}	
	//if current player is player RED/Computer
	if (curPos==6 && player_1==0)
		{
		curPos=7;
		}
	//if current player is player RED/Computer
	if (curPos==14 && player_1==0)
		{
		curPos=0;
		}
	}
	
//set the value of the bowl in the chosen position 
//equal to zero so to empty it out
board[initPos] = 0;
// return the position of the last marble placed
return(curPos);
 }
 
//==========================================================================

//function used to determine if one player emptied their bowls
int complete(int player_1, int board[])
{
//if current player is player RED/Computer
if (player_1==0)
	{
		//check if all of the current player's bowls are empty
		if ((board[12]==0) && (board[7]==0) && board[8]==0 && board[9]==0 && board[10]==0 && board[11]==0 )
			{
			//adds the marble currently in the opponent's side to current player's mancala
			board[13] = board[13]+board[0]+board[1]+board[2]+board[3]+board[4]+board[5];
			//empties out opponent's bowls
			board[0]=0;
			board[1]=0;
			board[2]=0;
			board[3]=0;
			board[4]=0;
			board[5]=0;
			//return 1 so player doesn't go again
			return (1);	
			}
	}
//if current player is player BLUE
if(player_1==1)
	{
	//check if all of the current player's bowls are empty
	if (board[0]==0 && board[1]==0 && board[2]==0 && board[3]==0 && board[4]==0 && board[5]==0 )
		{
		//adds the marbles currently in the opponent's side to current player's mancala
		board[6] = board[6]+board[7]+board[8]+board[9]+board[10]+board[11]+board[12];
		//empties out opponent's bowls
		board[7]=0;
		board[8]=0;
		board[9]=0;
		board[10]=0;
		board[11]=0;
		board[12]=0;
		//return 1 so player doesn't go again
		return (1);	
		}
	
	}
//return 2 if conditions not met so player can get another turn if applicable	
return (2);

}

//==========================================================================
 
 //function used to display most updated board
int cur_board(int board[])
{
	//print current board positions
	printf("\n\n      5   4   3   2   1   0	  \n");
	printf("BLUE\n");
	printf("=====[%d] [%d] [%d] [%d] [%d] [%d]-----\n", board[5], board[4], board[3], board[2], board[1], board[0]);
	printf("|%d|			      |%d|\n", board[6], board[13]);
	printf("-----[%d] [%d] [%d] [%d] [%d] [%d]=====\n", board[7], board[8], board[9], board[10], board[11], board[12]);
	printf("			      RED\n");
	printf("      6   7   8   9  10   11    \n\n");
	//return 0 to exist function
	return 0;
}
