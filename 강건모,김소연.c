/*
	작성자 : 강건모(1260001),김소연(1260007)
	제작일 : 2013.5.15

	프로그램 설명 : 도서관 좌석을 입실, 퇴실, 변경 할수 있는 프로그램입니다.

*/

#include<stdio.h>	//표준 입출력(printf(),scanf()쓰려고)
#include<stdlib.h>	//표준 라이브러리( system("cls"),exit()쓰려고)
#include <ctype.h>	//문자 검사,변환 함수를 포함

void f_first();         //첫화면 함수
int menu();		//메뉴선택 함수
void f_cheak_in();	//좌석입실 함수
void f_cheak_out();	//좌석퇴실 함수
void change();		//좌석변경 함수
void condition();	//좌석현황 함수

int seat[11][11];	//좌석 가로 11 세로 11
int seat_count=0;	//입실한 좌석 수
int rseat_count=121;    //남은 좌석 수

void main()            //메인함수
{
	int m=0;		//메뉴를 위한 변수 선언
	f_first();              //첫화면 함수 실행
	while(1)		//메뉴반복을 위한 무한반복문
	{
		m=menu();	//변수 m에 메뉴번호를 저장

		switch(m)       //변수를 입력받고받는숫자로 switch case()문으로 실행
		{
			case 1:  //m = 1 일일때
				f_cheak_in();	//좌석입실함수 실행
				break;          //case 1 종료
			case 2:
				f_cheak_out();	//좌석퇴실함수 실행
				break;
			case 3:
				change();		//좌석변경함수 실행
				break;
			case 4:
				condition();	//좌석현황함수 실행
				getchar();     //getchar() 하나의 문자만 입력, 화이트스페이스 문제를 해결
				break;
			case 5:
				system("cls");          //전에화면에 표시되어있던화면을 지울때
				exit(0);		//프로그램 종료
		}
	
	}

}

void f_first()	//프로그램 소개를 위한 함수
{
	
	printf("┌──────────────────────────┐\n");
	printf("│                                                    │\n");
	printf("│  도 서 관    좌 석     배 정     프 로 그 램       │\n");
	printf("│                                                    │\n");
	printf("│                                                    │\n");
	printf("│                                                    │\n");
	printf("│                                                    │\n");
	printf("│                      목원대학교 정보통신공학과     │\n");
	printf("│                           7조                      │\n");
	printf("│                              1260001 강건모        │\n");
	printf("│                              1260007 김소연        │\n");
	printf("│                                                v1.0│\n");
	printf("└──────────────────────────┘\n");
	printf("\n\n");
	printf("       <<<<<계속 하려면 아무 키나 입력하세요>>>>>         ");
	getchar();    //getchar() 하나의 문자만 입력, 화이트스페이스 문제를 해결
}

int menu()
{
	int n=0;	//입력받을 메뉴번호 저장

	system("cls");   //전에화면에 표시되어있던화면을 지울때
	while(1)	//메뉴 선택을 반복할 수 있게 만듬
	{
	
		printf("┌─────────────┐\n");
		printf("│도서관 좌석 배정 프로그램 │\n");
		printf("│1.좌석입실                │\n");
		printf("│2.좌석퇴실                │\n");
		printf("│3.좌석변경                │\n");
		printf("│4.좌석현황                │\n");	
		printf("│5.나가기                  │\n");
		printf("└─────────────┘\n");

		printf("원하시는 메뉴의 번호를 선택하세요 > > > > >");
		scanf("%d",&n);
		getchar();    //getchar() 하나의 문자만 입력, 화이트스페이스 문제를 해결

		if(1<=n && n<=5)
		{
				break;	//1~5사이의 숫자일때 무한반복문 종료
		}
		else			//잘못 입력하였을시 문장 출력
		{
			system("cls");
			printf("━━━━━━━━━━━━━━━━━━━━\n");
			printf("        잘못 입력하셨습니다.\n");
			printf("━━━━━━━━━━━━━━━━━━━━\n");
		}
	}
	return n;
}

void f_cheak_in()		//좌석 입력함수
{
	int x=0,y=0;		//x가 알파벳열,y가 숫자열

	system("cls");
	printf("┌─────┐\n");
	printf("│*좌석 입실│\n");
	printf("└─────┘\n");
	
	condition();		//좌석 현황을 먼저 보여줌
	printf("\n");
	printf("배정받을 좌석을 입력하십시요.\n");
	printf("(A~K)열>");
	scanf("%s",&x);
	x=toupper(x);		//입력받은 문자가 소문자일 경우 대문자로 변환후 저장
	x-=65;				//A는 정수형으로 65를 의미해서 65만큼 빼주어 0으로시작하게
	printf("(1~11)번>");
	scanf("%d",&y);
	y-=1;				//배열은 0부터 시작, 따라서 1만큼 빼줌
	if(y>=0 && y<11 && x>=0 && x<11){  
	if(seat[x][y]==0)	//선택한 자리에 아무도 없을 경우
	{
	seat[x][y]=1;		//선택한 자리에 들어온 표시를 함
	seat_count+=1;		//입실한 좌석수 1추가
	rseat_count-=1;		//남은 좌석수 1감소
	condition();		//선택 후 좌석을 보여줌
	getchar();              //getchar() 하나의 문자만 입력
	}
	
  else					//선택한 좌석이 차 있을 경우
	printf("이미 사용중인 자리입니다.\n");
	getchar();             //getchar() 하나의 문자만 입력, 화이트스페이스 문제를 해결
	}
		else
		{
			printf("잘못입력하셨습니다!!");
			getchar();
			getchar();
		}
}

void f_cheak_out()		//좌석 퇴실 함수
{
	int x=0,y=0;

	system("cls");
	printf("┌─────┐\n");
	printf("│*좌석 퇴실│\n");
	printf("└─────┘\n");

 if(seat_count>0)		//입실된 좌석이 있을 경우
 {
   condition();			//좌석현황 출력
   printf("퇴실할 좌석을 입력하십이요.\n");
   printf("(A~K)열>");
   scanf("%s",&x);
   x=toupper(x);		//입력받은 문자가 소문자일 경우 대문자로 변환
   x-=65;				//A는 정수형으로 65를 의미해서 65만큼 빼주어 0으로시작하게
   printf("(1~11)번>");
   scanf("%d",&y);
   y-=1;					//배열은 0부터 시작, 따라서 1만큼 빼줌
   if(y>=0 && y<11 && x>=0 && x<11){  
   if(seat[x][y]==1)	//자리에 사람이 있을경우
   {
    seat[x][y]=0;		//원하는 자리를 퇴실처리
    seat_count-=1;		//입실한 인원 1감소
    rseat_count+=1;		//남은 자리 1증가
	condition();		//선택 후 좌석을 보여줌
	getchar();              //getchar() 하나의 문자만 입력
	getchar();              //getchar() 하나의 문자만 입력
   }
   else
   {
	printf("원래 입실하지 않은 좌석입니다.\n");
	getchar();
   }
   }
   else
		{
			printf("잘못입력하셨습니다!!");
			getchar();
			getchar();
		}
 }
 else					//자리에 사람이 없을 경우
 {
	 printf("입실한 좌석이 없습니다.\n");
	 getchar();
   }
 

}

void change()			//좌석변경
{			
	int x=0,y=0;
	
	system("cls");
	printf("┌─────┐\n");
	printf("│*좌석 변경│\n");
	printf("└─────┘\n");

	if(seat_count>0)	//입실한 사람이 있을 경우
   {
		condition();		//좌석 현황
   
		printf("\n");
		printf("변경할 좌석을 입력하십이요.\n");
		printf("(A~K)열>");
		scanf("%s",&x);
		
		x=toupper(x);		//소문자를 대문자로 변환하여 저장
		x-=65;				//A는 정수형으로 65를 의미해서 65만큼 빼주어 0으로시작하게 
		printf("(1~11)번>");
		scanf("%d",&y);
		y-=1;				//배열이므로 -1을 함
		if(y>=0 && y<11 && x>=0 && x<11){				
		if(seat_count>0)	//모든 좌석에 사람이 1명이라도 있는경우
		 {
			if(seat[x][y]==1)//변경하고자하는 좌석에 사람이 있는경우
			{
				seat[x][y]=0;//퇴실처리

			printf("변경하실 좌석을 입력해주세요.\n");
			printf("(A~K)열>");
			scanf("%s",&x);
			x=toupper(x);
			x-=65;
			printf("(1~11)번>");
			scanf("%d",&y);
			y-=1;

			if(seat[x][y]==1)	//이미 좌석이 차 있는 경우
			{
				printf("이미 사용중인 좌석입니다.\n");
				getchar();
			}
			else
			seat[x][y]=1;
			}
		else
			{
			printf("원래 사용되지 않은 좌석입니다.\n");
			getchar();
			}
		}
		}
		else
		{
			printf("잘못입력하셨습니다!!");
			getchar();
			getchar();
		}
	}
	else
		printf("변경할수 있는 좌석이 없습니다.\n");
		getchar();
	
}


void condition()
{
 int i,j;				//for문을 위한 변수
 

 system("cls");
 printf("                 ◇◇◇◆◆   좌석현황   ◆◆◇◇◇                    \n");
 printf("-----------------------------------------------------------------------\n");
 printf("    ");

 //좌석 현황을 보여준다
 //배열을 이용하여 순차적으로 접근

 for(i=0;i<11;i++)
 {
  printf("    %d ",i+1);	//가로의 숫자열
 }
 printf("\n");
 
 for(i=0;i<11;i++)
 {
  printf("%c열  ",'A'+i);	//세로의 알파벳열
  for(j=0;j<11;j++)
  {
   if(seat[i][j]==1)
    printf("[ ★ ]");	//자리에 사람이 있을 경우
   else
    printf("[    ]");	//자리에 사람이 없을 경우
  }
  printf("\n");
 }

 printf("현재 사용 좌석 수: %d\n",seat_count);
 printf("현재 사용가능한 좌석 수: %d\n",rseat_count);
 printf("-----------------------------------------------------------------------\n");
}