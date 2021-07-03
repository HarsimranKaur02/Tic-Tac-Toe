
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


char board[3][3]={'1','2','3','4','5','6','7','8','9'};
char player1[25], player2[25];
int turn=0;
char pos;

void drawboard();
void get_input();
void get_input2();
char checkwin();
void win();
void block();
void random();
void compturn();

int main()
{   char board[3][3]={'1','2','3','4','5','6','7','8','9'};
    int turn=0; 
    fflush(stdin);
    menu:
	system("cls");
	int ch;
	int c;
	printf("\n\n");
	printf("                                                 W E L C O M E \n\n\n\n") ;
	printf("    ********   ****      ****       *********      ***         ****         ********      ****      ******* \n");
	sleep (1);
	printf("       **       **    **               **        **   **     **                **       **    **    **      \n");
	printf("       **       **   **                **       ** *** **   **                 **       **    **    *****   \n");
	sleep (1);
	printf("       **       **    **               **      **       **   **                **       **    **    **      \n");
	printf("       **      ****      ****          **     **         **    ****            **         ****      ******* \n\n\n ");
	sleep (1);
    
	printf("\n\t MENU");
	printf("\n\n\t 1. Start the game");
	printf("\n\n\t 2. Quit the game");
	printf("\n\n\t 3. How to play");
    printf("\n\n\t Enter your choice(1/2/3) : ");
    scanf("%d", &ch);
	
	switch(ch)
	{
		case 1 : {
		menu1:
		system("cls");
		printf("\n\n\t PLAY WITH: ");
		printf("\n\n\t 1.Two players  \n\n\t 2.Computer");
		printf("\n\n\t Your choice(1/2): ");
		scanf("%d", &c);
		if(c==1){
		printf("\n\n\t Enter player1's name : ");
		fflush(stdin);
		gets(player1);
		printf("\n\t Welcome %s. Your sign is X\n", player1);
		
		printf("\n\t Enter player2's name : ");
		fflush(stdin);
		gets(player2);
		printf("\n\t Welcome %s. Your sign is O\n", player2);
		printf("\t ");
		system("pause");
		
		system("cls");
		drawboard();
		get_input();
		
		printf("\n GAME OVER");
		exit (0);
		}
		
		if(c==2)
		{printf("\n\n\t Enter your name : ");
		fflush(stdin);
		gets(player1);
		printf("\n\t Welcome %s. Your sign is O\n", player1);
		printf("\n\t ");
		system("pause");
		system("cls");
		drawboard();
		get_input2();
		printf("\n GAME OVER");
		exit(0);
		goto menu;
		break;
		}
    else
	{printf("\t Please enter valid option\n");
	getch();
	goto menu1;
	break;
		}	}
		
     case 2 : {
     	char d;
     	system("cls");
     	 printf("\n\t Are you sure you want to exit?y/n: ");
             scanf("%s",&d);
             if(d=='y')
                exit(0);
             else
                goto menu;
     	break;
       }
	   
	  case 3: { system("cls");
	  printf("\n\t INSTRUCTIONS\n\n\t");
	  printf(" Tic tac toe is played between two players\n\t");
	  printf(" The objective of this game is to get three same symbols in a row, or a column or a diagonal.\n\t");
	  printf(" You play on a 3 by 3 game board. Players alternating placing Xs and Os on the game board \n\t");
	  printf(" until either opponent has three in a row, column or diagonal or all nine squares are filled.\n\n\t");
	  printf(" ALL THE BEST :) \n\n\t ");
	  system("pause");
	  goto menu;
		break;
	  }	
	  
	  
	  default:
	  	{ printf("\n\t Please enter valid choice\n");
	  	getch();
	  	goto menu;
	  	break;
		  }
}
		
	getch();
	return 0;	
	}
	
void drawboard()
{
	int i,j;
	printf("\n\n\n\t\t\t\t\t  _________ _________ _________\n");
		for(i=0;i<3;i++)
	{
	printf("\t\t\t\t\t |         |         |         |\n");
	printf("\t\t\t\t\t |");
    for(j=0;j<3;j++)
    {
	printf("    %c    |", board[i][j]);
	}
	printf("\n\t\t\t\t\t |_________|_________|_________|\n");
    }
}

char checkwin()
{
// if 'X' wins
 if (board[0][0]=='X'&& board[1][1]=='X'&& board[2][2]=='X') // diagonal1
    return 'X';
 if (board[0][2]=='X'&& board[1][1]=='X'&& board[2][0]=='X') // diagonal2
    return 'X';
 if (board[0][0]=='X'&& board[0][1]=='X'&& board[0][2]=='X') // row1
    return 'X';
 if (board[1][0]=='X'&& board[1][1]=='X'&& board[1][2]=='X') // row2
    return 'X';
 if (board[2][0]=='X'&& board[2][1]=='X'&& board[2][2]=='X') // row3
    return 'X';
 if (board[0][0]=='X'&& board[1][0]=='X'&& board[2][0]=='X') // column1
    return 'X';
 if (board[0][1]=='X'&& board[1][1]=='X'&& board[2][1]=='X') // column2
    return 'X';   
 if (board[0][2]=='X'&& board[1][2]=='X'&& board[2][2]=='X') // column3
    return 'X';
    
 // if 'O' wins   
 else if (board[0][0]=='O'&& board[1][1]=='O'&& board[2][2]=='O') // diagonal1
    return 'O';
 else if (board[0][2]=='O'&& board[1][1]=='O'&& board[2][0]=='O') // diagonal2
    return 'O';
 else if (board[0][0]=='O'&& board[0][1]=='O'&& board[0][2]=='O') // row1
    return 'O';
 else if (board[1][0]=='O'&& board[1][1]=='O'&& board[1][2]=='O') // row2
    return 'O';
 else if (board[2][0]=='O'&& board[2][1]=='O'&& board[2][2]=='O') // row3
    return 'O';
 else if (board[0][0]=='O'&& board[1][0]=='O'&& board[2][0]=='O') // column1
    return 'O';
 else if (board[0][1]=='O'&& board[1][1]=='O'&& board[2][1]=='O') // column2
    return 'O';
 else if (board[0][2]=='O'&& board[1][2]=='O'&& board[2][2]=='O') // column3
    return 'O';
 
 // if there is a draw   
else 
    return 'd';	 
}
	
void get_input()
{
	int i,j;
	char a;
	printf("\n Enter a number between 1 to 9");
	while(1)
	{   label1:
		printf("\n\n Turn for %s: ",player1);
		turn++;
		scanf("%c", &pos);
		fflush(stdin);
		if(pos>='1'&&pos<='9')
		{
			
		for(i=0;i<3;i++)
		  {for(j=0;j<3;j++)
		     {   
		      if(pos==board[i][j])
		       { if(turn%2==0)
		         board[i][j]='O';
		         else
		         board[i][j]='X';
			   }
			     
			}
		 }
	}
	else
	{printf("please enter numbers between 1 to 9.");
	turn--;
	getch();
	goto label1;
	}
	system("cls");
	drawboard();
	a=checkwin();
	if (a=='X')
	{
	  printf("\n\n Congratulations!!\n %s won!!", player1);
	  turn=0;
	  break;
	}
	
	else if (a=='d' && turn==9)
	{printf("\n Match draw");
	turn=0;
	break;
	}
	
	
	label2:
	printf("\n\n Turn for %s: ",player2);
		turn++;
		scanf("%c", &pos);
		fflush(stdin);
		if(pos>='1'&&pos<='9')
      {
      	for(i=0;i<3;i++)
		  {for(j=0;j<3;j++)
		     {   
		      if(pos==board[i][j])
		       { if(turn%2==0)
		         board[i][j]='O';
		         else
		         board[i][j]='X';
			   }
			}
		 }
	}
	else
	{printf("please enter numbers between 1 to 9.");
	turn--;
	getch();
	goto label2;
	}
	system("cls");
	drawboard();
	a=checkwin();
	if (a=='O')
	{
	  printf("\n\n Congratulations!!\n%s won!!", player2);
	  turn=0;
	  break;
	}
  }
}


	void win()
	{
	//FOR WINNING
	
	if((board[1][0]=='X'&&board[2][0]=='X'||board[0][1]=='X'&&board[0][2]=='X'||board[1][1]=='X'&&board[2][2]=='X')&&board[0][0]=='1')
	{
		 board[0][0]='X' ;//pos 1
		
	}
	else if((board[0][0]=='X'&&board[0][2]=='X'||board[1][1]=='X'&&board[2][1]=='X')&&board[0][1]=='2')
	{
		 board[0][1]='X' ;//pos 2
			
	}
	else if((board[0][0]=='X'&&board[0][1]=='X'||board[1][2]=='X'&&board[2][2]=='X'||board[1][1]=='X'&&board[2][0]=='X')&&board[0][2]=='3')
	{
	 board[0][2]='X'; //pos 3
			
	}
	else if((board[0][0]=='X'&&board[2][0]=='X'||board[1][1]=='X'&&board[2][0]=='X')&&board[1][0]=='4')
	{
		 board[1][0]='X'; //pos 4
		
	}
	else if((board[0][1]=='X'&&board[2][1]=='X'||board[1][0]=='X'&&board[1][2]=='X'||board[0][2]=='X'&&board[2][0]=='X'||board[0][0]=='X'&&board[2][2]=='X')&&board[1][1]=='5')
	{
		 board[1][1]='X'; //pos 5
	
	}
	else if((board[1][0]=='X'&&board[1][1]=='X'||board[0][2]=='X'&&board[2][2]=='X')&&board[1][2]=='6')
	{
	 board[1][2]='X'; //pos 6
	
	}
	else if((board[0][0]=='X'&&board[1][0]=='X'||board[2][1]=='X'&&board[2][2]=='X'||board[1][1]=='X'&&board[0][2]=='X')&&board[2][0]=='7')
	{
	 board[2][0]='X'; //pos 7
		
	}
	else if((board[0][1]=='X'&&board[1][1]=='X'||board[2][0]=='X'&&board[2][2]=='X')&&board[2][1]=='8')
	{
	 board[2][1]='X'; //pos 8
			
	}
	else if((board[2][0]=='X'&&board[2][2]=='X'||board[0][2]=='X'&&board[1][2]=='X'||board[0][0]=='X'&&board[1][1]=='X')&&board[2][2]=='9')
	{
	 board[2][2]='X'; //pos 9
		
	}
	}
	
	
	void block()
	{ 
	
	//FOR BLOCKING
    if((board[1][0]=='O'&&board[2][0]=='O'||board[0][1]=='O'&&board[0][2]=='O'||board[1][1]=='O'&&board[2][2]=='O')&&board[0][0]=='1')
    {board[0][0]='X';
	} //pos 1
	
    else if((board[0][0]=='O'&&board[0][2]=='O'||board[1][1]=='O'&&board[2][1]=='O')&&board[0][1]=='2')
    {board[0][1]='X';
	 }//pos 2
	
    else if((board[0][0]=='O'&&board[0][1]=='O'||board[1][2]=='O'&&board[2][2]=='O'||board[1][1]=='O'&&board[2][0]=='O')&&board[0][2]=='3')
	{board[0][2]='X';
	
	} //pos 3
	
	else if((board[0][0]=='O'&&board[2][0]=='O'||board[1][1]=='O'&&board[1][2]=='O')&&board[1][0]=='4')
    {
     board[1][0]='X';}  //pos 4
     
	else if((board[0][1]=='O'&&board[2][1]=='O'||board[1][0]=='O'&&board[1][2]=='O'||board[0][2]=='O'&&board[2][0]=='O'||board[0][0]=='O'&&board[2][2]=='O')&&board[1][1]=='5')
	{board[1][1]='X';}  // pos 5
	
	else if((board[1][0]=='O'&&board[1][1]=='O'||board[0][2]=='O'&&board[2][2]=='O')&&board[1][2]=='6')
    {board[1][2]='X'; } //pos 6
    
	else if((board[0][0]=='O'&&board[1][0]=='O'||board[2][1]=='O'&&board[2][2]=='O'||board[1][1]=='O'&&board[0][2]=='O')&&board[2][0]=='7')
	{board[2][0]='X';}  //pos 7
	
	else if((board[0][1]=='O'&&board[1][1]=='O'||board[2][0]=='O'&&board[2][2]=='O')&&board[2][1]=='8')
	{board[2][1]='X';   //pos 8
	}
	
	else if((board[2][0]=='O'&&board[2][2]=='O'||board[0][2]=='O'&&board[1][2]=='O'||board[0][0]=='O'&&board[1][1]=='O')&&board[2][2]=='9')
	{board[2][2]='X';}   //pos 9
	else
	{
    random();}
	} 
	
	void random()
	{    int i,j,x,y;
	
	{	
	if(board[1][1]=='5')
	{
	x=1;
	y=1;
	}
	else 
	{for(i=2;i>=0;i--)
    {for(j=0;j<3;j++) 
    {if(board[i][j]!='X' && board[i][j]!='O')
        	{
				x=i;
				y=j;
               goto end;
        	}
            
  	}}}
    end:   
    board[x][y]='X';
    
    }} 
	
	void compturn()
{   win();
    block();
 }

void get_input2() //game with computer
{   
//PLAYER'S TURN
	int i,j;
	char a;
	printf("\n Enter a number between 1 to 9");
	while(1)
	{   label3:
		printf("\n\n Turn for %s : ",player1);
		turn++;
		scanf("%c", &pos);
		fflush(stdin);
		if(pos>='1'&&pos<='9')
      {
     	for(i=0;i<3;i++)
		  {for(j=0;j<3;j++)
		     {   
		      if(pos==board[i][j])
		      {if(turn%2!=0)
		        board[i][j]='O';
		        else
		        board[i][j]='X';
					}
		   }
	 }
}
else
	{printf("please enter numbers between 1 to 9.");
	turn--;
	getch();
	goto label3;
	}
	system("cls");
	drawboard();
	
	a=checkwin();
	if (a=='O')
	{
	  printf("\n\n Congratulations!!\n%s won!!", player1);
	  turn=0;
	  break;
	}
	
	else if (a=='d' && turn==9)
	{printf(" Match draw");
	getch();
	turn=0;
	break;} 
	
	//computer's turn
    printf("\n\n Computer's turn \n");
    sleep(1);
    
    turn++;
    system("cls");
    compturn();
    drawboard();
    a=checkwin();
    
    if(a=='X')
    {printf(" Computer won..");
    turn=0;
     break;
	}
}
}


