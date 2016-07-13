#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define  IDLENGTH 8
#define BUFFLENGTH 4
struct problems
{
	int firNum, secNum, trueAns, urAns;
	char symbol;
};

char stuId[IDLENGTH];
char buff[BUFFLENGTH];

int main(){
	void getId(void), checkScore(void), startTest(void);
	int choice(void);

	getId();

	switch(choice()){
		case 1:
		startTest();
		break;
		case 2:
		checkScore();
		break;
		case 3:
		return 0;
	}
}

void getId(void){
	int idCheck, idCount;
	printf("%s\n","Please input your student ID, e.g.AB1234: " );
	gets(stuId);
	while (1){
		while (stuId[6] != '\0'){
			printf("%s\n","ID too long or too short!\nPlease check your ID!\n
			Please input your student ID, e.g.AB1234: " );
			gets(stuId);
		}
		idCheck = 0
		for (idCount = 0; idCount < 2; idCount++)idCheck += !(isalpha(stuId[i]));
		for (idCount = 2; idCount < 6; idCount++)idCheck += !(isdigit(stuId[i]));
		if (idCheck != 0){
			printf("%s\n","ID input error!\nPlease check your ID!\n
			Please input your student ID, e.g.AB1234:" );
			gets(stuId);
		}
		else return;
	}
}

int choice(void){
	while(1){
		printf("%s\n","1) Start a Test\n2) Check Scores\n3) Exit\nPlease input your choice " );
		gets(buff);
		if (buff[0]<4 && buff[0]>0)return int(buff[0]);
		printf("%s\n","Wrong input!\n\n" );
	}
}

void startTest(void){
	struct problems problem[10];
	int divBuff, probCount, useTime, score = 0;
	srand(time(NULL));
	long timeStart, timeEnd;
	clock(timeStart);
	for(probCount = 0; probCount < 10; probCount++){
		problem[probCount].firNum = rand()%98 + 1;
		switch(rand()%4){
			case 1:
			problem[probCount].symbol = '+';
			problem[probCount].secNum = rand()%(99 - problem[probCount].firNum) + 1;
			problem[probCount].trueAns = problem[probCount].firNum + problem[probCount].secNum;
			break;
			case 2:
			problem[probCount].symbol = '-';
			problem[probCount].secNum = rand()%(problem[probCount].firNum) + 1;
			problem[probCount].trueAns = problem[probCount].firNum - problem[probCount].secNum;
			break;
			case 3:
			problem[probCount].symbol = '*';
			problem[probCount].secNum = rand()%(99 / problem[probCount].firNum) + 1;
			problem[probCount].trueAns = problem[probCount].firNum * problem[probCount].secNum;
			break;
			case 4:
			problem[probCount].symbol = '/';
			problem[probCount].secNum = rand()%(problem[probCount].firNum) + 1;
			divBuff = problem[probCount].firNum % problem[probCount].secNum;
			if (!(divBuff))problem[probCount].secNum -=divBuff; 
			problem[probCount].trueAns = problem[probCount].firNum / problem[probCount].secNum;
			break;
		}
		printf("%2d: %2d%c%2d = ", probCount + 1, problem[probCount].firNum, problem[probCount].symbol, problem[probCount].secNum);
		gets(buff);
		problem[probCount].urAns = int(*buff);
		if(problem[probCount].urAns == problem[probCount].trueAns) score += 10;
	}
	clock(timeEnd);
	useTime = (timeEnd -timeStart)/CLK_TCK;
	printf("%s  %3d %3d s\n", stuId, score, useTime);
	printf("\n\n", );// to do

	File* outFile;
	outFile = fopen("record.txt","a");
	fprintf(outFile, "%s  %3d %3d s\n", stuId, score, useTime);
	fclose(outFile);
}

void checkScore(void){
	int timeCheck, scoreCheck, readScore, readTime;
	char readId[7], readBuff[14];
	File* inFile;
	inFile = fopen("record.txt","r");
	for(fgets(readId, 7, inFile) != EOF){
		if(!strcmp(readId, stuId)){
			fgets(readBuff, 14, inFile);
			printf("%s%s\n", readId, readBuff);
		}
	}
	return;
}
