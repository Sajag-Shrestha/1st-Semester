/*
			|-----------------------------------|
			|COVID-19 DONATION MANAGEMENT SYSTEM|  
			|-----------------------------------|
                            
			|Note: This Program is best suited with window screen of 138 width and 30 height.|

*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
struct record
{
	int shipment;
	char name[50], supplycode[10], donator[10];
	float quantity; 	
}; 
int authentic (char[],char[]);
void mainmenu();
void recorddonation(); 
void updatedonation();
void searchdonation(); 
void alldonation();
void deletedonation();
void bubblesort();
void distributionlist();

void donationlist();
void distorder();
void donorder();
void main()
{
	int res, c = -1; logg: ;
	char username[30], password[30];
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t |------------------------------------|\n");
	printf("\t\t\t\t\t\t |            LOGIN SCREEN            |\n");
	printf("\t\t\t\t\t\t |------------------------------------|\n");
 	printf("\n\t\t\t\t\t\t         Enter username: "); 
	gets(username);fflush(stdin);
	printf("\n\t\t\t\t\t\t         Enter password: ");
	gets(password); fflush(stdin);
	res = authentic(username,password);
	c++;
	if(c >= 5)
		{
			system("cls");
			system("color 4");
			printf("\n\n\n\n\n");
			printf("\n\t\t\t\t\t\t       Too many attempts at login!!\a\n\n\n\n\n");		
			getch();
			return;
		}	
	if (res == 0)
		{
			goto logg;
		}
getch();
}
	int authentic(char user[],char pw[])
	{
		if(strcmp(user, "Admin") == 0)
			{
				if(strcmp(pw,"Pass") == 0)			
					{
						printf("\n\n\n\t\t\t\t\t\t           Login Successful!!");
						printf("\n\t\t\t\t\t\t       Press any key to continue...");
						getch();
						mainmenu();
					}
				else
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Login failed - Incorrect Password!");
						printf("\n\t\t\t\t\t\t  Press any key to continue");
						getch();
						return 0;	
					}				
			}
		else
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Login failed - Incorrect Username!");
				printf("\n\t\t\t\t\t\t  Press any key to continue");
				getch();
				return 0;
			}	
	return 0;				
	}

void mainmenu()
{
		int choice;
	do
	{
		system("cls");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t\t |-----------------------------------|\n");
		printf("\t\t\t\t\t\t |   Malaysia Red Crescent Society   |\n");
		printf("\t\t\t\t\t\t |-----------------------------------|\n");
		printf("\t\t\t\t\t\t |                                   |\n");
		printf("\t\t\t\t\t\t |\t1. Enter Inventory           |");
		printf("\n\t\t\t\t\t\t |\t2. Update Record             |");
		printf("\n\t\t\t\t\t\t |\t3. Search Donation           |");
		printf("\n\t\t\t\t\t\t |\t4. Display all Records       |");
		printf("\n\t\t\t\t\t\t |\t5. Delete Donation           |");
		printf("\n\t\t\t\t\t\t |\t6. Exit                      |");
		printf("\n\t\t\t\t\t\t |                                   |");
		printf("\n\t\t\t\t\t\t\tMake a choice? ");
		scanf("%d",&choice); fflush(stdin);
		switch(choice)
		{
			case 1: recorddonation(); break;
			case 2: updatedonation(); break;
			case 3: searchdonation(); break;
			case 4: alldonation(); break;
			case 5: deletedonation(); break;
			case 6: printf("\n\t\t\t\t\t\t\tExiting....Goodbye ~(0v0)/\n\n\n\n"); getch(); exit(0); break;
			default: printf("\n\t\t\t\t\t\t    Invalid Input, Enter value (0-6)");
			getch();
		}
	}while(1);
	getch();	
}



void recorddonation()
{
	int i, shipment, ship, c=0; 
	float quantity, qt;
	char name[50], supplycode[10], donator[10], choice, exit[3], code[10];
	for(;;)
	{
	FILE *fp;
	FILE *tmp;
	fp = fopen("donation.txt","a+");
	tmp = fopen("tmp.txt","a");
	
	if(fp == NULL)
	{
		system("cls");
		printf("\n\n\tFile could not be opened!!\n");  getch(); return;
	}
		system("cls");
		printf("\n\n\tEnter donation record:\n\n");
		printf("\n\tSupply Code: "); gets(supplycode); fflush(stdin);
		for(i=0;i<=3;i++)
			{
				exit[i] = tolower(supplycode[i]);
			}
			if (strcmp(exit,"exit") == 0)
			{
				mainmenu();	
			}
		while(fscanf(fp,"%s %s %s %d %f\n", name, code, donator, &shipment, &quantity) == 5)
		{
			if(strcmp(code, supplycode) ==0)
			{
				c = 1;
				system("cls");
				printf("\n\n\tSuch Supply Code already exists:\n\n");
				printf("\n\tName of Supply\t\t  Supply Code\t\t   Donator\t\tNo. of Shipment\t\tQuantity Received (millions)\n");
				printf("\n\t---------------\t\t --------------\t\t--------------\t\t---------------\t\t---------------\t\t\n");
				printf("\n\t%s                    \t\%s       \t\t%s \t\t       %d  \t\t%.2f million  \t\t\n", name, code, donator, shipment, quantity);				
				printf("\n\n\n\tDo you want to add values into this record?(Y/N)? ");
				scanf("%c",&choice); fflush(stdin);
				choice = tolower(choice);
				if (choice == 'y') 
				{
					printf("\n\tAdd No. of Shipment: "); scanf("%d",&ship); fflush(stdin); 	
					printf("\n\tAdd Quantity Received (millions): "); scanf("%f",&qt); fflush(stdin);
					fprintf(tmp, "%s %s %s %d %f\n",name, code, donator, shipment + ship, quantity + qt);
					system("cls");
					printf("\n\n\tNewly added record: \n\n");
					printf("\n\tName of Supply\t\t  Supply Code\t\t   Donator\t\tNo. of Shipment\t\tQuantity Received (millions)\n");
					printf("\n\t---------------\t\t --------------\t\t--------------\t\t---------------\t\t---------------\t\t\n");
					printf("\n\t%s                    \t\%s       \t\t%s \t\t       %d  \t\t%.2f million  \t\t\n", name, supplycode, donator, shipment+ship, quantity+qt);				
				}
				else mainmenu();
			}
			else 
			{
				fprintf(tmp, "%s %s %s %d %f\n",name, code, donator, shipment, quantity);
			}	
		}
		if(c == 1)
		{
			goto add;
		}
		printf("\n\tName of Supply: "); gets(name); fflush(stdin);
		printf("\n\tDonator: "); gets(donator); fflush(stdin);
		printf("\n\tNo. of Shipment: "); scanf("%d",&shipment); fflush(stdin); 	
		printf("\n\tQuantity Received (millions): "); scanf("%f",&quantity); fflush(stdin);
		fprintf(tmp, "%s %s %s %d %f\n",name, supplycode, donator, shipment, quantity);
		printf("\n\n\tData written successfully!\n");
		add:	
		fclose(fp); fclose(tmp);
		remove("donation.txt");
		rename("tmp.txt","donation.txt");
		printf("\n\n\tDo you wish to continue?(Y/N): ");
		scanf("%c",&choice); fflush(stdin);
		choice = tolower(choice);
		if (choice == 'y') continue;
		else mainmenu();
	}
	getch();
}



void updatedonation()
{
	int shipment, i, option; 
	float quantity;
	char name[50], supplycode[10], donator[10], choice;
	int ship, count = 0, lines = 0;
	float qt, dist;
	char nos[50], code[10], exi[4], donate[10], c;
	del:
	do
	{
		system("cls");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t\t |------------------------------------|\n");
		printf("\t\t\t\t\t\t |           UPDATE RECORDS           |\n");
		printf("\t\t\t\t\t\t |------------------------------------|\n");
		printf("\t\t\t\t\t\t |                                    |\n");
		printf("\t\t\t\t\t\t |\t1. Edit Donation Record       |");
		printf("\n\t\t\t\t\t\t |\t2. Add Donation               |");
		printf("\n\t\t\t\t\t\t |\t3. Add Distribution           |");
		printf("\n\t\t\t\t\t\t |\t4. Main Menu                  |");
		printf("\n\t\t\t\t\t\t |                                    |");
		printf("\n\t\t\t\t\t\t\tMake a choice? ");
		scanf("%d",&choice); fflush(stdin);
		switch(choice)
		{
			case 1: 
					system("cls");
					FILE *fp = fopen("donation.txt","r+");
					FILE *tmp = fopen("tmp.txt","a");
					if(fp == NULL)
					{
						system("cls");
						printf("\n\n File could not be opened!!\n");  getch(); return;
					}
					printf("\n\tEnter Supply Code of the Record you want to update: ");
					gets(code); fflush(stdin);
					for(i=0;i<=3;i++)
					{
						exi[i] = tolower(code[i]);
					}
					if (strcmp(exi,"exit") == 0)
					{
						mainmenu();	
					}	
					while(fscanf(fp,"%s %s %s %d %f\n", name, supplycode, donator, &shipment, &quantity) == 5)
						{
							
							if (strcmp(code, supplycode) == 0)
							{ 
								printf("\n\tCurrent Value: \n");
								printf("\n\tName of Supply\t\t  Supply Code\t\t   Donator\t\tNo. of Shipment\t\tQuantity Received (millions)\n");
								printf("\n\t---------------\t\t --------------\t\t--------------\t\t---------------\t\t---------------\t\t\n");
								printf("\n\t%s                    \t\%s       \t\t%s \t\t       %d  \t\t%.2f million  \t\t\n", name, supplycode, donator, shipment, quantity);
								printf("\n\n\tEnter all the new values to be updated: \n");		
								printf("\t-----------------------------------------\n");
								printf("\n\tSupply Code: "); gets(code); fflush(stdin);
								printf("\n\tName of Supply: "); gets(nos); fflush(stdin);
								printf("\n\tDonator: "); gets(donate); fflush(stdin);
								printf("\n\tNo. of Shipment: "); scanf("%d",&ship); fflush(stdin); 	
								printf("\n\tQuantity Received (millions): "); scanf("%f",&qt); fflush(stdin);
								
								fprintf(tmp,"%s %s %s %d %f\n", nos, code, donate, ship, qt);
								printf("\n\n\tData updated successfully!\n");
								fflush(stdin);
							} 
							else
							{
								fprintf(tmp,"%s %s %s %d %f\n", name, supplycode, donator, shipment, quantity);
								count = count + 1;
							}
							lines++;
						} 	
						fclose(fp); fclose(tmp);
						remove("donation.txt");
						rename("tmp.txt","donation.txt");	
							if(lines == count)
						{
							printf("\n\n\tSuch Supply code doesn't exist, Try Again\n");	
							printf("\tPress any key to continue...");
							getch();
							goto del;	
						}	
				getch();
				break;	
			case 2: 
					system("cls");
					FILE *fp2;
					FILE *tmp2;
					fp2 = fopen("donation.txt","a+");
					tmp2 = fopen("tmp.txt","a");
					if (fp2 == NULL)
					{
						system("cls");
						printf("\n\n File could not be opened!!\n");  getch(); return;
					}
					printf("\n\tEnter Supply Code of the record you want to add: "); gets(supplycode); fflush(stdin);
					for(i=0;i<=3;i++)
					{
						exi[i] = tolower(supplycode[i]);
					}
					if (strcmp(exi,"exit") == 0)
					{
						mainmenu();	
					}	
					while(fscanf(fp2,"%s %s %s %d %f\n", name, code, donator, &shipment, &quantity) == 5)
					{
						if(strcmp(code, supplycode) ==0)
						{
							printf("\n\tCurrent Value: \n");
							printf("\n\tName of Supply\t\t  Supply Code\t\t   Donator\t\tNo. of Shipment\t\tQuantity Received (millions)\n");
							printf("\n\t---------------\t\t --------------\t\t--------------\t\t---------------\t\t---------------\t\t\n");
							printf("\n\t%s                    \t\%s       \t\t%s \t\t       %d  \t\t%.2f million  \t\t\n", name, code, donator, shipment, quantity);				
							printf("\n\n\n\tDo you want to add values into this record?(Y/N)? ");
							scanf("%c",&choice); fflush(stdin);
							choice = tolower(choice);
							if (choice == 'y') 
							{
								printf("\n\tAdd No. of Shipment: "); scanf("%d",&ship); fflush(stdin); 	
								printf("\n\tAdd Quantity Received (millions): "); scanf("%f",&qt); fflush(stdin);
								fprintf(tmp2, "%s %s %s %d %f\n",name, code, donator, shipment + ship, quantity + qt);
								system("cls");
								printf("\n\n\tNewly added record: \n\n");
								printf("\n\tName of Supply\t\t  Supply Code\t\t   Donator\t\tNo. of Shipment\t\tQuantity Received (millions)\n");
								printf("\n\t---------------\t\t --------------\t\t--------------\t\t---------------\t\t---------------\t\t\n");
								printf("\n\t%s                    \t\%s       \t\t%s \t\t       %d  \t\t%.2f million  \t\t\n", name, supplycode, donator, shipment+ship, quantity+qt);				
							}
							else mainmenu();
						}
						else 
						{
							fprintf(tmp2, "%s %s %s %d %f\n",name, code, donator, shipment, quantity);
							count++;
						}	
						lines++;
					}
					fclose(fp2); fclose(tmp2);
					remove("donation.txt");
					rename("tmp.txt","donation.txt");
					if(lines == count)
						{
							printf("\n\n\tSuch Supply code doesn't exist, Try Again\n");	
							printf("\tPress any key to continue...");
							getch();
							goto del;	
						}	
					break;
			case 3:
					system("cls");
					FILE *fp1;
					FILE *tmp1;
					FILE *dis;
					struct record dist;
					fp1 = fopen("donation.txt","r");
					tmp1 = fopen("tmp.txt","a");
					dis = fopen("dist.txt","a+");
					if (fp1 == NULL || dis == NULL)
					{
						system("cls");
						printf("\n\n File could not be opened!!\n");  getch(); return;
					}
					printf("\n\tEnter Supply Code of the record you want to distribute: "); gets(supplycode); fflush(stdin);
					for(i=0;i<=3;i++)
					{
						exi[i] = tolower(supplycode[i]);
					}
					if (strcmp(exi,"exit") == 0)
					{
						mainmenu();	
					}	
					while(fscanf(fp1,"%s %s %s %d %f\n", name, code, donator, &shipment, &quantity) == 5)
					{
						if(strcmp(code, supplycode) ==0)
						{
							printf("\n\tCurrent Value: \n");
							printf("\n\tName of Supply\t\t  Supply Code\t\t   Donator\t\tNo. of Shipment\t\tQuantity Received (millions)\n");
							printf("\n\t---------------\t\t --------------\t\t--------------\t\t---------------\t\t---------------\t\t\n");
							printf("\n\t%s                    \t\%s       \t\t%s \t\t       %d  \t\t%.2f million  \t\t\n", name, code, donator, shipment, quantity);				
							printf("\n\n\n\tDo you want to distribute from this record?(Y/N)? ");
							scanf("%c",&choice); fflush(stdin);
							choice = tolower(choice);
							if (choice == 'y') 
							{ 	
								printf("\n\tSubtract Quantity for Distribution (in millions): "); scanf("%f",&dist.quantity); fflush(stdin);
								printf("%f", dist.quantity);
								fprintf(dis, "%s %s %f\n",name, code, dist.quantity);
								fprintf(tmp1, "%s %s %s %d %f\n",name, code, donator, shipment, quantity - dist.quantity);
								system("cls");
								printf("\n\n\tNewly added record: \n\n");
								printf("\n\tName of Supply  \t\t\t\t  Supply Code \t\t\t\tQuantity Distributed (millions)\n");
								printf("\n\t---------------  \t\t\t\t  --------------  \t\t\t--------------\n");
								printf("\n\t%s                                            \t\%s            \t\t\t%.2f million  \t\t\n", name, supplycode, dist.quantity);				
							}
							else mainmenu();
						}
						else 
						{
							fprintf(tmp1, "%s %s %s %d %f\n",name, code, donator, shipment, quantity);
							count++;
						}	
						lines++;
					}	
					fclose(dis);
					fclose(fp1); fclose(tmp1);
					remove("donation.txt");
					rename("tmp.txt","donation.txt");
					if(lines == count)
						{
							printf("\n\n\tSuch Supply code doesn't exist, Try Again\n");	
							printf("\tPress any key to continue...");
							getch();
							goto del;	
						}	
					break;
			case 4: printf("\n\t\t\t\t\t\tReturning to main menu...\n\n\n\n"); getch(); mainmenu(); break;
			default: printf("\n\t\t\t\t\t\tInvalid Input, Enter value (0-4)");
			getch();
		}		
		printf("\n\n\tDo you want to update another record?(Y/N): ");
		scanf("%c",&choice); fflush(stdin);
		choice = tolower(choice);
		if (choice == 'y') continue;
		else mainmenu();
	}while(1);
	getch();	
}



void searchdonation()
{
	int shipment, i; 
	float quantity;
	char name[50], supplycode[10], donator[10], code[10], exit[4], choice;  
	do
	  {
		FILE *fp = fopen("donation.txt","r");
		system("cls");
		printf("\n\tEnter Supply Code of the Record you want to search: ");
		gets(code); fflush(stdin);
		for(i=0;i<=3;i++)
		{
			exit[i] = tolower(code[i]);
		}
		if (strcmp(exit,"exit") == 0)
		{
			mainmenu();	
		}
		while(fscanf(fp,"%s %s %s %d %f\n", name, supplycode, donator, &shipment, &quantity) == 5)
			{
				if (strcmp(code, supplycode) == 0)
				{ 
					printf("\n\tName of Supply\t\t  Supply Code\t\t   Donator\t\tNo. of Shipment\t\tQuantity Received (millions)\n");
					printf("\n\t---------------\t\t --------------\t\t--------------\t\t---------------\t\t---------------\t\t\n");
					printf("\n\t%s                    \t\%s       \t\t%s \t\t       %d  \t\t%.2f million  \t\t\n", name, supplycode, donator, shipment, quantity);
				}		
			}
			fclose(fp);
			printf("\n\n\n\n\n\tDo you want to search another record?(Y/N): ");
			scanf("%c",&choice); fflush(stdin);
			choice = tolower(choice);
			if (choice == 'y') continue;
			else mainmenu();
		}while(1);
	getch();		
}



void alldonation()
{
	struct record don;
	struct record dist;
	int i = 0, j, shipment, rec; 
	float quantity;
	char name[50], supplycode[10], donator[10], choice, no;
	do
	{
		system("cls");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t\t |-------------------------------------|\n");
		printf("\t\t\t\t\t\t |           DISPLAY RECORDS           |\n");
		printf("\t\t\t\t\t\t |-------------------------------------|\n");
		printf("\t\t\t\t\t\t |                                     |\n");
		printf("\t\t\t\t\t\t |\t1. Display Donation Record     |");
		printf("\n\t\t\t\t\t\t |\t2. Display Distribution Record |");
		printf("\n\t\t\t\t\t\t |\t3. Main Menu                   |");
		printf("\n\t\t\t\t\t\t |                                     |");
		printf("\n\t\t\t\t\t\t\tMake a choice? ");
		scanf("%d",&choice); fflush(stdin);
		switch(choice)
		{
			case 1:
					donorder(); break;
			case 2:
					distorder(); break;
			case 3: printf("\n\t\t\t\t\t\tReturning to main menu...\n\n\n\n"); getch(); mainmenu(); break;
			default: printf("\n\t\t\t\t\t\tInvalid Input, Enter value (0-3)");
			getch();
				
		}
	}while(1);
	getch();
}




void deletedonation()
{
	int i, shipment, count = 0;
	float quantity;
	char exit[4], name[50], supplycode[10], donator[10], code[10], confirm, choice, c;
	del:
	do
	  {
		FILE *fp = fopen("donation.txt","r+");
		FILE *tmp = fopen("tmp.txt","a");
		system("cls");
		printf("\n\tEnter Supply Code of the Record you want to delete: ");
		gets(code); fflush(stdin);
		for(i=0;i<=3;i++)
		{
			exit[i] = tolower(code[i]);
		}
		if (strcmp(exit,"exit") == 0)
		{
			mainmenu();	
		}
		while(fscanf(fp,"%s %s %s %d %f\n", name, supplycode, donator, &shipment, &quantity) == 5)
			{
				
				if (strcmp(code, supplycode) == 0)
				{ 
					count++;
					printf("\n\tName of Supply\t\t  Supply Code\t\t   Donator\t\tNo. of Shipment\t\tQuantity Received (millions)\n");
					printf("\n\t---------------\t\t --------------\t\t--------------\t\t---------------\t\t---------------\t\t\n");
					printf("\n\t%s                    \t\%s       \t\t%s \t\t       %d  \t\t%.2f million  \t\t\n", name, supplycode, donator, shipment, quantity);
					printf("\n\n\n\tAre you sure you want to delete this record?(Y/N): ");
					scanf("%c",&confirm); fflush(stdin);
					choice = tolower(confirm);
					if (confirm == 'y')
					{
						printf("\n\n\n\tThe record has been deleted"); continue;	
					} 
					else mainmenu();
				} 
				else
				{
					fprintf(tmp,"%s %s %s %d %f\n", name, supplycode, donator, shipment, quantity);
				}
			} 	
			fclose(fp); fclose(tmp);
			remove("donation.txt");
			rename("tmp.txt","donation.txt");	
			if(count == 0)
			{
				printf("\n\n\tSuch Supply code doesn't exist, Try Again\n");	
				printf("\tPress any key to continue...");
				getch();
				goto del;	
			}	
			printf("\n\n\tDo you want to delete another record?(Y/N): ");
			scanf("%c",&choice); fflush(stdin);
			choice = tolower(choice);
			if (choice == 'y') continue;
			else mainmenu;
	   }while(1);
	getch();	
}



void bubblesort (struct record dist[], int N)
{
	int i, j; struct record tmp;
	for (i=0; i<N-1; i++)
	{
		for(j=0; j<N-i-1; j++)
		{
			if(dist[j].quantity < dist[j+1].quantity)
			{
				tmp = dist[j];
				dist[j] =  dist[j+1];
				dist[j+1] = tmp;
			}
		}
	}
}



void distributionlist( struct record dist[], int N)
{
	int i;
	printf("\n\tName of Supply  \t\t\t\t  Supply Code \t\t\t\tQuantity Distributed (millions)\n");
	printf("\n\t---------------  \t\t\t\t  --------------  \t\t\t-------------------------\n");
	for(i=0; i<N; i++)
	{
		printf("\n\t%s                                            \t\%s            \t\t\t%.2f million  \t\t\n", dist[i].name, dist[i].supplycode, dist[i].quantity);				
	}
	getch();
}



void donationlist( struct record don[], int N)
{
	int i;
		printf("\n\n\tAll Donation Records:\n");
		printf("\n\tName of Supply\t\t  Supply Code\t\t   Donator\t\tNo. of Shipment\t\tQuantity Received (millions)\n");
		printf("\n\t---------------\t\t --------------\t\t--------------\t\t---------------\t\t---------------\t\t\n");
					
	for(i=0; i<N; i++)
	{
			printf("\n\t%s                    \t\%s       \t\t%s \t\t       %d  \t\t%.2f million  \t\t\n", don[i].name, don[i].supplycode, don[i].donator, don[i].shipment, don[i].quantity);
					
	}
	getch();
}



void donorder()
{
	system("cls");
	int shipment;
	float quantity;
	char name[50], supplycode[10], donator[10]; 
	int i = 0;
	struct record don[10];
	struct record tmp;
	FILE *fp = fopen("donation.txt","r");
	while(fscanf(fp,"%s %s %s %d %f\n", name, supplycode, donator, &shipment, &quantity) == 5)
	{
		tmp.shipment = shipment;
		tmp.quantity = quantity;
		strcpy(tmp.supplycode, supplycode);
		strcpy(tmp.donator,donator);
		strcpy(tmp.name, name);
		don[i] = tmp;
		i++;
	}
	fclose(fp);
	bubblesort(don, i);
	donationlist(don, i);
}



void distorder()
{
	system("cls");
	float quantity;
	char name[50], supplycode[15]; 
	int i = 0;
	struct record dist[10];
	struct record tmp;
	FILE *fp = fopen("dist.txt","r");
	while(fscanf(fp, "%s %s %f\n", name, supplycode, &quantity)== 3)
	{
		tmp.quantity = quantity;
		strcpy(tmp.supplycode, supplycode);
		strcpy(tmp.name, name);
		dist[i] = tmp;
		i++;
	}
	fclose(fp);
	bubblesort(dist, i);
	distributionlist(dist, i);
}

