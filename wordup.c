// Ben Turner
// 4/26/25
// Project 10 

#include <stdio.h>
#define columns 6
#define rows 6
#define max_size 50

void checkguess(char wordtoguess[columns], char userguess[rows][max_size],int numbguess, char arrwos[rows][max_size]);
void uncapitalletters(char userguess[rows][max_size], int attemptnumb);
int lessthancolumns(char userguess[rows][max_size], int attemptnumb);
int win(char userguess[rows][max_size], char wordtoguess[columns], int attemptnumb);
void grabfile(char wordtoguess[]);

int main(){
char wordtoguess[columns], userguess[rows][max_size], arrows[rows][max_size];
int numbguess = 0, wordlength, winner;	
	
	//Grab the word to be guessed from file
	grabfile(wordtoguess);	
	//ask for number and display attempt
	printf("-----Guess the 5 letter word!!-----\n");
	
	for(numbguess = 0 ; numbguess <= rows - 1 ; numbguess++){
		
		// do while word is columns amount long
		do{
		
		if( numbguess == 5){
			printf("Final Guess:");
				}
		
		else if (numbguess < 6 ){
		printf("Guess #%d: ", numbguess + 1 );
					}		
		fgets(userguess[numbguess], max_size, stdin);		
		printf("===================\n");
		wordlength = 0;
		if(lessthancolumns(userguess, numbguess) == 1){
			
			printf("Word must be %d letters long\n", columns -1);
			wordlength = 1;
								}
		}while(wordlength == 1);
		   
	uncapitalletters(userguess, numbguess);
	winner = win(userguess, wordtoguess, numbguess);
	checkguess(wordtoguess, userguess, numbguess, arrows);
	
	//Display win messege
	if(winner == 1){
		printf("You Won!! you guessed the word %s on guess %d !!\n", wordtoguess, numbguess + 1);
		return 0; 
			}
	//printf previous guesses 
	for(int i = 0 ; i <= numbguess ; i++){
		printf("%s", userguess[i]);
		printf("%s\n", arrows[i]);
							}
	
								}	
return 0;
}

// checks user guess for matching characters 
void checkguess(char wordtoguess[], char userguess[][max_size], int attemptnumb, char arrows[][max_size]){
		
	for(int i = 0 ; i < columns ; i++){
		for(int w = 0 ; w < columns ; w++){
			
			if(wordtoguess[i] == userguess[attemptnumb][w]){
					arrows[attemptnumb][w] = '^';
										}
							}
			if(userguess[attemptnumb][i] == wordtoguess[i]){
					userguess[attemptnumb][i] = userguess[attemptnumb][i] - 32;
					arrows[attemptnumb][i] = ' '; 
									}					
					}
	}
// uncapitalize the user inputed letters 
void uncapitalletters(char userguess[][max_size], int attemptnumb){
	
	for(int i = 0 ; i < columns ; i++){
		if(userguess[attemptnumb][i] < 90 && userguess[attemptnumb][i] > 65){
			userguess[attemptnumb][i] = userguess[attemptnumb][i] + 32; 
								}
					}
		}
//makes sure the user types the correct word length							
int lessthancolumns(char userguess[][max_size], int attemptnumb){
	
	for(int i = 0 ; i < max_size - 1 ; i++){
		if(i == columns && userguess[attemptnumb][i] == '\0'){
		return 0;
								}
		
		if(i < columns && userguess[attemptnumb][i] == '\0'){
		return 1;
								}
		else if (i > columns - 1 && userguess[attemptnumb][i] != '\0'){
		return 1;
								}
					}							
	return 0;
	}
// File io 
int win(char userguess[][max_size], char wordtoguess[columns], int attemptnumb){
	
		int win = 0; 
		
		for(int i = 0 ; i < columns - 1 ; i++){
			if(userguess[attemptnumb][i] == wordtoguess[i]){
				win++;
				if(win == 5){				
					return 1; 			
						}
									}	
							}
return 0;
}
void grabfile(char wordtoguess[]){

	FILE *fptr;
		fptr = fopen("word.txt","r");
			if(fptr ==  NULL){
				printf("could not open file correctly");
					}
		fgets(wordtoguess, columns , fptr);
		fclose(fptr);		
	
	}
		
		
