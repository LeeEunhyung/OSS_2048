#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
char e=0;
int main( ){
long int A[5][5],i,j,x,y=0,k,t=0,D[16],a=0,b=0,n=1,O[5][5],rscore,score,highscore,s,end;
srand(time(NULL));

for(i=1;i<=4;i++){
	for(j=1;j<=4;j++){
		A[i][j]=0 ;
	}
}

rscore=0;
score=0 ;
highscore=0;

i=rand()%3+1;
j=rand()%3+1;
x=rand()%2+2;
if(x==3)
	x=2;
A[i][j]=x;
i=rand()%3+1;
j=rand()%3+1;
x=rand()%2+2;
if(x==3)
	x=2;
A[i][j]=x;
s=0;
for(i=1;i<5;i++){
	for(j=1;j<5;j++){
		s+=A[i][j];
    }
}
highscore=s;
score=s ;
for(i=1;i<5;i++){
    printf("\n| %4d    | %4d    | %4d    | %4d    |\n",A[i][1],A[i][2],A[i][3],A[i][4]);
}
printf("\nThe current state\n")	;
printf("Score:%d\nHigh Score=%d",score,highscore);
printf("\nPress w to move up,press a to move left,press s to move down,press d to move right,\npress e to finish the game, press x to refresh,press r to restore \n");

while(e!='e'){
e=getch();
srand(time(NULL));

if(e=='d'){

	rscore=score;
	for(i=1;i<=4;i++){
	    for(j=1;j<=4;j++){
		    O[i][j]=A[i][j] ;
	    }
    }

	for(k=1;k<=3;k++){

	    for(i=1;i<=4;i++){
		    for(j=1;j<4;j++){
		    	if(A[i][j]!=0 && A[i][j+1]==0){
		    	  	A[i][j+1]=A[i][j];
					A[i][j]=0;
    	        }
			}
		}
    }
    for(i=1;i<=4;i++){
		j=1;
		t=0;
		    while(j<=3 && t==0){

			    if(A[i][j]==A[i][j+1]&& A[i][j]!=0){
			      	A[i][j+1]=A[i][j+1]+A[i][j] ;
			    	A[i][j]=0;
				    t=1;
				}
			j=j+1 ;
			}
	}
    for(k=1;k<=3;k++){

	    for(i=1;i<=4;i++){
		    for(j=1;j<4;j++){
		    	if(A[i][j]!=0 && A[i][j+1]==0){
		    	  	A[i][j+1]=A[i][j];
					A[i][j]=0;
    	        }
			}
		}
    }


n=0;
	for(i=1;i<=4;i++){
	    for(j=1;j<=4;j++){
		    if(A[i][j]==0){
			    D[n]=10*i+j;
			    n=n+1;
	        }
		}
    }
	b=rand()%n;
    i=D[b]/10 ;
	j=D[b]%10;
	x=rand()%2+2;
    if(x==3)
	    x=2;

    A[i][j]=x ;
    system("CLS");
	for(i=1;i<5;i++){
    printf("\n| %4d    | %4d    | %4d    | %4d    |\n",O[i][1],O[i][2],O[i][3],O[i][4]);
    }

    printf("\nThe previous state\n")	;
    printf("Score:%d\nHigh Score:%d",rscore,highscore);
	for(i=1;i<5;i++){
    printf("\n| %4d    | %4d    | %4d    | %4d    |\n",A[i][1],A[i][2],A[i][3],A[i][4]);
    }

s=0;
for(i=1;i<5;i++){
	for(j=1;j<5;j++){
		s+=A[i][j];
    }
}

score=s ;
if(score>highscore){
	highscore=score;
}
printf("\nThe current state\n")	;
printf("Score:%d\nHigh Score:%d",score,highscore);

}



if(e=='a'){
	rscore=score;
	for(i=1;i<=4;i++){
	    for(j=1;j<=4;j++){
		    O[i][j]=A[i][j] ;
	    }
    }

	for(k=1;k<=3;k++){

	    for(i=1;i<=4;i++){
		    for(j=4;j>1;j--){
		    	if(A[i][j]!=0 && A[i][j-1]==0){
		    	  	A[i][j-1]=A[i][j];
					A[i][j]=0;
    	        }
			}
		}
    }
    	for(i=1;i<=4;i++){
		j=1;
		t=0;
		    while(j<=3 && t==0){

			    if(A[i][j]==A[i][j+1]&& A[i][j]!=0){
			      	A[i][j]=A[i][j+1]+A[i][j] ;
			    	A[i][j+1]=0;
				    t=1;
				}
			j=j+1 ;
			}
		}
    for(k=1;k<=4;k++){

	    for(i=1;i<=4;i++){
		    for(j=4;j>1;j--){
		    	if(A[i][j]!=0 && A[i][j-1]==0){
		    	  	A[i][j-1]=A[i][j];
					A[i][j]=0;
    	}
			}
		}
    }

    n=0;
	for(i=1;i<=4;i++){
	    for(j=1;j<=4;j++){
		    if(A[i][j]==0){
			    D[n]=10*i+j;
			    n=n+1;
	        }
		}
    }
	b=rand()%n;
    i=D[b]/10 ;
	j=D[b]%10;
	x=rand()%2+2;
    if(x==3)
	    x=2;

    A[i][j]=x ;
    system("CLS");
	for(i=1;i<5;i++){
    printf("\n| %4d    | %4d    | %4d    | %4d    |\n",O[i][1],O[i][2],O[i][3],O[i][4]);
    }

    printf("\nThe previous state\n")	;
    printf("Score:%d\nHigh Score:%d",rscore,highscore);

	for(i=1;i<5;i++){
    printf("\n| %4d    | %4d    | %4d    | %4d    |\n",A[i][1],A[i][2],A[i][3],A[i][4]);
    }
s=0;
for(i=1;i<5;i++){
	for(j=1;j<5;j++){
		s+=A[i][j];
    }
}
score=s ;
if(score>highscore){
	highscore=score ;
}
printf("\nThe current state\n")	;
printf("Score:%d\nHigh Score:%d",score,highscore);
}
if(e=='s'){
	rscore=score;
	for(i=1;i<=4;i++){
	    for(j=1;j<=4;j++){
		    O[i][j]=A[i][j] ;
	    }
    }

	for(k=1;k<=4;k++){

	    for(j=1;j<=4;j++){
		    for(i=4;i>1;i--){
		    	if(A[i][j]==0 && A[i-1][j]!=0){
		    	  	A[i][j]=A[i-1][j];
					A[i-1][j]=0;
		    	}
			}
		}
    }
	for(j=1;j<=4;j++){
		i=4;
		t=0;
		while(i>1 && t==0){
			if(A[i][j]==A[i-1][j]&& A[i][j]!=0){
				A[i][j]=A[i-1][j]+A[i][j] ;
				A[i-1][j]=0;
				t=1;
				}
			i=i-1 ;
			}
	}
for(k=1;k<=4;k++){
	for(j=1;j<=4;j++){
		for(i=4;i>1;i--){
		    if(A[i][j]==0 && A[i-1][j]!=0){
		    	A[i][j]=A[i-1][j];
				A[i-1][j]=0;
		    }
		}
	}
}

n=0;
	for(i=1;i<=4;i++){
	    for(j=1;j<=4;j++){
		    if(A[i][j]==0){
			    D[n]=10*i+j;
			    n=n+1;
	        }
		}
    }
	b=rand()%n;
    i=D[b]/10 ;
	j=D[b]%10;
	x=rand()%2+2;
    if(x==3)
	    x=2;
    A[i][j]=x ;
    system("CLS");
	for(i=1;i<5;i++){
    printf("\n| %4d    | %4d    | %4d    | %4d    |\n",O[i][1],O[i][2],O[i][3],O[i][4]);
    }
    printf("\nThe previous state\n")	;
    printf("Score:%d\nHigh Score:%d",rscore,highscore);
	for(i=1;i<5;i++){
    printf("\n| %4d    | %4d    | %4d    | %4d    |\n",A[i][1],A[i][2],A[i][3],A[i][4]);
    }
s=0;
for(i=1;i<5;i++){
	for(j=1;j<5;j++){
		s+=A[i][j];
    }
}
score=s ;
if(score>highscore){
	highscore=score ;
}
printf("\nThe current state\n")	;
printf("Score:%d\nHigh Score:%d",score,highscore);
}
if(e=='w'){
	rscore=score;
	for(i=1;i<=4;i++){
	    for(j=1;j<=4;j++){
		    O[i][j]=A[i][j] ;
	    }
    }

	for(k=1;k<=3;k++){

	    for(j=1;j<=4;j++){
		    for(i=1;i<4;i++){
		    	if(A[i][j]==0 && A[i+1][j]!=0){
		    		A[i][j]=A[i+1][j];
		    		A[i+1][j]=0 ;
				}
			}
	    }
    }
	for(j=1;j<=4;j++){
		i=1;
		t=0;
		while(i<4 && t==0){

			if(A[i][j]==A[i+1][j]&& A[i][j]!=0){
				A[i][j]=A[i+1][j]+A[i][j] ;
				A[i+1][j]=0;
				t=1;
				}
			i=i+1 ;
			}
	}
		for(k=1;k<=3;k++){
	        for(j=1;j<=4;j++){
		        for(i=1;i<4;i++){
		    	    if(A[i][j]==0 && A[i+1][j]!=0){
		    		    A[i][j]=A[i+1][j];
		    		    A[i+1][j]=0 ;
				    }
			    }
	        }
        }

n=0;
	for(i=1;i<=4;i++){
	    for(j=1;j<=4;j++){
		    if(A[i][j]==0){
			    D[n]=10*i+j;
			    n=n+1;
	        }
		}
    }
	b=rand()%n;
    i=D[b]/10 ;
	j=D[b]%10;
	x=rand()%2+2;
    if(x==3)
	    x=2;
	 A[i][j]=x ;
    system("CLS");
	for(i=1;i<5;i++){
    printf("\n| %4d    | %4d    | %4d    | %4d    |\n",O[i][1],O[i][2],O[i][3],O[i][4]);
    }
    printf("\nThe previous state\n")	;
    printf("Score:%d\nHigh Score:%d",rscore,highscore);
	for(i=1;i<5;i++){
    printf("\n| %4d    | %4d    | %4d    | %4d    |\n",A[i][1],A[i][2],A[i][3],A[i][4]);
    }
s=0;
for(i=1;i<5;i++){
	for(j=1;j<5;j++){
		s+=A[i][j];
    }
}
score=s ;
if(score>highscore){
	highscore=score ;
}
printf("\nThe current state\n")	;
printf("Score:%d\nHigh Score=%d",score,highscore);
}
if(e=='x'){

score=0;
	for(i=1;i<=4;i++){
		for(j=1;j<=4;j++){
			A[i][j]=0 ;
		}
	}
    system("CLS");
	for(i=1;i<5;i++){
    printf("\n| %4d    | %4d    | %4d    | %4d    |\n",O[i][1],O[i][2],O[i][3],O[i][4]);
    }

    printf("\nThe previous state\n")	;
    printf("Score:%d\nHigh Score:%d",rscore,highscore);

	for(i=1;i<5;i++){
    printf("\n| %4d    | %4d    | %4d    | %4d    |\n",A[i][1],A[i][2],A[i][3],A[i][4]);
    }
printf("\nThe current state\n")	;
printf("Score:%d\nHigh Score:%d",score,highscore);
}
if(e=='r'){

	system("CLS");
	for(i=1;i<5;i++){
    printf("\n| %4d    | %4d    | %4d    | %4d    |\n",A[i][1],A[i][2],A[i][3],A[i][4]);
    }
printf("\nThe previous state\n")	;
printf("Score:%d\nHigh Score:%d",score,highscore);
	for(i=1;i<5;i++){
        printf("\n| %4d    | %4d    | %4d    | %4d    |\n",O[i][1],O[i][2],O[i][3],O[i][4]);
    }
printf("\nThe current state\n")	;
printf("Score:%d\nHigh Score:%d",rscore,highscore);
    for(i=1;i<5;i++){
	    for(j=1;j<5;j++){
		    A[i][j]=O[i][j];
	    }
    }
}

a=0;
for(i=1;i<=4;i++){
	    for(j=1;j<=4;j++){
		    if(A[i][j]==0){
		    	a=1;
				}
		}
}
for(i=1;i<=4;i++){
	for(j=1;j<=4;j++){
		if(i==4 && j!=4 && A[i][j]==A[i][j+1]){
			a=1;
		}
		if (j==4 && i!=4 && A[i][j]==A[i+1][j]){
		   a=1 ;
	    }
		if(A[i][j]==A[i+1][j] || A[i][j]==A[i][j+1] ){

		    a=1 ;
	    }
	}
}
if(a!=1){
	e='e';
}
i=1;
j=1;
end=0 ;

while(i<5 && end==0 ){
	while(j<5 && end==0){
		if(A[i][j]==2048){
			end=1;
		}
		j+=1 ;
	}
    i+=1 ;
}
printf("\nPress 8 to move up,press 4 to move left,press move 2 to down,press 6 to move right,\npress e to finish the game,press x to refresh,press r to restore \n");

if(end==1){
	printf("YOU WON!\n");
	e='e';
}
}
system("CLS");
	for(i=1;i<5;i++){
        printf("\n| %4d    | %4d    | %4d    | %4d    |\n",A[i][1],A[i][2],A[i][3],A[i][4]);
    }
printf("\nThe current state\n")	;
if(end!=1){
    printf("\nYOU LOSE!");
}
printf("\n \n GAME OVER!\n Score: %d \n High Score:%d",score,highscore);
getch()	;
return 0 ;
}
