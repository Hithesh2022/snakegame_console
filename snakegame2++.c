
// C program to build the complete 
// snake game 
#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

  

int i, j, height = 20, width = 20; 

int gameover, score; 

int x, y, fruitx, fruity, flag; 

  
// Function to generate the fruit 
// within the boundary 

void setup() 
{ 

    gameover = 0; 

  

    // Stores height and width 

    x = height / 2; 

    y = width / 2; 
label1: 

    fruitx = rand() % 20; 

    if (fruitx == 0) 

        goto label1; 
label2: 

    fruity = rand() % 20; 

    if (fruity == 0) 

        goto label2; 

    score = 0; 
} 

  
// Function to draw the boundaries 

void draw() 
{ int k,piece,tailx[100],taily[100],ch;

    system("cls"); 

    for (i = 0; i < height; i++) { 

        for (j = 0; j < width; j++) { 

            if (i == 0 || i == width - 1 

                || j == 0 

                || j == height - 1) { 

                printf("*"); 

            } 

            else { 

                if (i == x && j == y) 

                    printf("0"); 

                else if (i == fruitx 

                         && j == fruity) 

                    printf("O"); 

               // else
	else 
		/*	{ for(k=0;k<piece;k++)
			{
				if(i==tailx[k] && j==taily[k])
				{
					printf("o");
					ch=1;
				}
		}
			 if(ch==0)
				printf("   ");
			     if(ch==0 )
*/
                    printf(" "); 

            } 

        } 

        printf("\n"); 

    } 

  

    // Print the score after the 

    // game ends 

    printf("score = %d", score); 

    printf("\n"); 

    printf("press X to quit the game"); 
} 

  
// Function to take the input 

void input() 
{ 

    if (kbhit()) { 

        switch (getch()) { 

        case 'a': 

            flag = 1; 

            break; 

        case 's': 

            flag = 2; 

            break; 

        case 'd': 

            flag = 3; 

            break; 

        case 'w': 

            flag = 4; 

            break; 

        case 'x': 

            gameover = 1; 

            break; 

        } 

    } 
} 

  
// Function for the logic behind 
// each movement 

void logic() 
{ 

    sleep(0.002); 
   /*int prevx,prevy,prev2x,prev2y,tailx[100],taily[100],x,y,piece;
prevx=tailx[0];
prevy=taily[0];
tailx[0]=x;
taily[0]=y;

for(i=1; i<=piece;i++)//piece is to increase snake length when eats fruit
{
	prev2x=tailx[i];
	prev2y=taily[i];
	tailx[i]=prevx;
	taily[i]=prevy;
	prevx=prev2x;
	prevy=prev2y;
 } */

    switch (flag) { 

    case 1: 

        y--; 

        break; 

    case 2: 

        x++; 

        break; 

    case 3: 

        y++; 

        break; 

    case 4: 

        x--; 

        break; 

    default: 

        break; 

    } 

  

    // If the game is over 

    if (x < 0 || x > height 

        || y < 0 || y > width) 

        gameover = 1; 

  

    // If snake reaches the fruit 

    // then update the score 

    if (x == fruitx && y == fruity) { 

    label3: 

        fruitx = rand() % 20; 

        if (fruitx == 0) 

            goto label3; 

  

    // After eating the above fruit 

    // generate new fruit 

    label4: 

        fruity = rand() % 20; 

        if (fruity == 0) 

            goto label4; 

        score += 5; 
       // piece++;

    } 
} 

  
// Driver Code 

void main() 
{ char i[100];
int j;
printf("Enter your name gentleman:\t");
scanf("%s",i);
/*printf("\n are you sad  enter in 0 or 1");
scanf("%d",j);
if(j==0)
{
printf("you have entered 0 so dont play");
	exit(0);
}
else if(j==1);
{*/


    int m, n; 

  

    // Generate boundary 

    setup(); 

  

    // Until the game is over 

    while (!gameover) { 

  

        // Function Call 

        draw(); 

        input(); 

        logic(); 

   		 } 
 
   			printf("\nYour name is %s and score is %d ",i,score);
	//}
/
}


