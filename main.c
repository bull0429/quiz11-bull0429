
#include <stdio.h>
#include <string.h>
#define MAX 50
char Password[10]="qwer1234";
int size=5;
char pw[10];
char searchName[10];
int trial=0;
char temp_name[10];
char temp_phone[20];

struct phone{
		char name[10];
		char phone[20];
};

int main()
{
		struct phone book[MAX];
		strcpy(book[0].name,"나태희");
		strcpy(book[0].phone,"010-1111-1111");
		strcpy(book[1].name,"유현빈");
		strcpy(book[1].phone,"010-2222-2222");
		strcpy(book[2].name,"나원빈");
		strcpy(book[2].phone,"010-3333-3333");
		strcpy(book[3].name,"문건영");
		strcpy(book[3].phone,"010-4444-4444");
		strcpy(book[4].name,"소지법");
		strcpy(book[4].phone,"010-5555-5555");

		int service =0;

		do
			{
					printf("전화번호관리\n\n");
					printf("1.등록 2.전체검색 3.특정인물검색 4.삭제 5.종료 \n\n");
					printf("메뉴선택 : ");
					scanf("%d",&service);

					switch(service)
					{
							case 1:
							while(1)
							{
							printf("비밀번호:");
							scanf("%s",pw);
							if(!strcmp(pw,Password)){
                                trial=0;
                                printf("등록할 이름:");
                                scanf("%s",temp_name);
                                printf("전화번호:");
                                scanf("%s",temp_phone);
                                strcpy(book[size].name, temp_name);
                                strcpy(book[size].phone, temp_phone);
                                printf("%s 정보 등록 완료\n",book[size].name);
                                size++;
                            break;
				}
				trial ++;

				if(trial>=3){
						printf("비밀번호 3회 실패");
						return 0;
						}
				printf("비밀번호 %d회 실패: %s\n",trial,pw);
		}
					break;

							case 2:
							printf("전화번호목록\n");
							for(int i=0;i<size;i++)
							printf("%s\t%s\n",book[i].name,book[i].phone);
							printf("\n");
							break;

							case 3:
							printf("검색할 이름:");
							scanf("%s",searchName);
							for(int i=0;i<10;i++){
								if(!strcmp(searchName,book[i].name)){
									printf("%s\t%s\n",book[i].name,book[i].phone);
                                                                    }
                                                }
                            break;
							case 4:
							printf("삭제할 이름:");
							scanf("%s",temp_name);
							for(int i=0;i<size;i++){
									if(!strcmp(temp_name,book[i].name)){
											for(i;i<size-1;i++){
													strcpy(book[i].name,book[i+1].name);
													strcpy(book[i].phone,book[i+1].phone);
											}
							size--;
							printf("정보 삭제 완료\n");
									}
			}
			}
			}while(service!=5);
		return 0;}
