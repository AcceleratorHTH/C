/** Make by Pham Quoc Trung, Dang Truong An and Tran Trong Duc. Please do not copy!**/
/** Work best with VSCode **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct contact
{
	char FirstName[20];
	char LastName[20];
	char Company[20];
	char PhoneNumber[12];
	char Email[50];
	char WorkingAddress[100];
	char HomeAddress[100];
	int day, month, year;
}prf;


void print_menu();
void add_contact();
void edit_contact();
void delete_contact();
void display_contact();
void search_contact();
void date_valid();
void phonenum_valid();
int checkPhoneNumber();
int checkEmpty();
void birthday_display();
void selection_date_sort();


int main()
{
	char choice;
	do
	{
		printf("\033[38;5;231m");
        system("title XLR8@IA1701:~$ Contact Keeper");
        system("cls"); 
		print_menu();
		scanf("%c%*c", &choice);

		system("cls"); 


        printf("				   _____            _             _     _                              \n");
		printf("				  / ____|          | |           | |   | |                             \n");
		printf("				 | |     ___  _ __ | |_ __ _  ___| |_  | | _____  ___ _ __   ___ _ __  \n");
		printf("				 | |    / _ \\| '_ \\| __/ _` |/ __| __| | |/ / _ \\/ _ \\ '_ \\ / _ \\ '__| \n");
		printf("				 | |___| (_) | | | | || (_| | (__| |_  |   <  __/  __/ |_) |  __/ |    \n");
		printf("				  \\_____\\___/|_| |_|\\__\\__,_|\\___|\\__| |_|\\_\\___|\\___| .__/ \\___|_|    \n");
		printf("				                                                     | |               \n");
		printf("				        =[ PRF192 ASSIGNMENT ]                       |_|               \n");
		printf("        			+ -- -- =[ IA1701 FPT University ]\n");
		printf("				+ -- -- =[ Pham Quoc Trung, Dang Truong An, Tran Trong Duc ]\n\n");
        printf(" =====================================================================================================================================\n\n");


		switch(choice)
		{
			case '1':
				add_contact();
				break;
			case '2':
				if (checkEmpty() == 0)
					printf("| (?) The contact is emty!\n\n");
				else
					edit_contact();
					break;
			case '3':
				if (checkEmpty() == 0)
					printf("| (?) The contact is emty!\n\n");
				else
					delete_contact();
					break;
			case '4':
				if (checkEmpty() == 0)
					printf("| (?) The contact is emty!\n\n");
				else
					display_contact();
					break;
			case '5':
				if (checkEmpty() == 0)
					printf("| (?) The contact is emty!\n\n");
				else
					search_contact();
					break;
			case '6':
				if (checkEmpty() == 0)
					printf("| (?) The contact is emty!\n\n");
				else
					birthday_display();
					break;
			case 'q':
				system("cls");
				break;
			default:
				printf("| (?) Invalid selection!\n\n");
				break;


		}
		
		if (choice != 'q')
		{
			printf(" -------------------------------------------------------------------------------------------------------------------------------------\n\n");
			printf("Press Enter to back to main menu.");
			getchar();
		}
	}
	while (choice != 'q');

	return 0;
}


void print_menu()
{

    printf("				   _____            _             _     _                              \n");
    printf("				  / ____|          | |           | |   | |                             \n");
    printf("				 | |     ___  _ __ | |_ __ _  ___| |_  | | _____  ___ _ __   ___ _ __  \n");
    printf("				 | |    / _ \\| '_ \\| __/ _` |/ __| __| | |/ / _ \\/ _ \\ '_ \\ / _ \\ '__| \n");
    printf("				 | |___| (_) | | | | || (_| | (__| |_  |   <  __/  __/ |_) |  __/ |    \n");
	printf("				  \\_____\\___/|_| |_|\\__\\__,_|\\___|\\__| |_|\\_\\___|\\___| .__/ \\___|_|    \n");
    printf("				                                                     | |               \n");
    printf("				        =[ PRF192 ASSIGNMENT ]                       |_|               \n");
	printf("        			+ -- -- =[ IA1701 FPT University ]\n");
	printf("				+ -- -- =[ Pham Quoc Trung, Dang Truong An, Tran Trong Duc ]\n\n");
	printf(" =====================================================================================================================================\n");
	printf("|                                                                                                                                     |\n");
	printf("| 1> Add Contact                                                                                                                      |\n");
	printf("| 2> Edit Contact                                                                                                                     |\n");
	printf("| 3> Delete Contact                                                                                                                   |\n");
	printf("| 4> Display Contact                                                                                                                  |\n");
	printf("| 5> Search contact                                                                                                                   |\n");
	printf("| 6> Birthday display by month                                                                                                        |\n");
	printf("| q> Quit                                                                                                                             |\n");
	printf("|                                                                                                                                     |\n");
	printf("| Enter your choice (1/2/3/4/5/6/q):                                                                                                  |");
	printf("\n -------------------------------------------------------------------------------------------------------------------------------------\033[A\r\033[37C");

}


void add_contact()
{
	FILE *ct;
	int check;

    ct = fopen("contact.txt", "a+");
	

	printf("| 1. First Name: ");
	scanf("%[^\n]", &prf.FirstName);
	
	
	printf("| 2. Last Name: ");
	scanf("%*c%[^\n]", &prf.LastName);


    printf("| 3. Company: ");
	scanf("%*c%[^\n]", &prf.Company);
	

    printf("| 4. Phone number: ");
	PN: scanf("%*c%[^\n]", &prf.PhoneNumber);
	check = checkPhoneNumber(prf.PhoneNumber);
	if (check == 1)
	{
		printf("| (?) Phone Number invalid/existed!\n");
		printf("|Re-enter Phone Number: ");
		goto PN;
	}
	phonenum_valid(prf.PhoneNumber);
	
	
    printf("| 5. Email: ");
	scanf("%*c%[^\n]", &prf.Email);
	
	
    printf("| 6. Working Address: ");
	scanf("%*c%[^\n]", &prf.WorkingAddress);
	
	
	printf("| 7. Home Address: ");
	scanf("%*c%[^\n]", &prf.HomeAddress);
	

	printf("| 8. Birthday (dd/mm/yyyy): ");
	scanf("%d/%d/%d", &prf.day, &prf.month, &prf.year);
	date_valid(prf.day, prf.month, prf.year);

	
	fprintf(ct, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
					prf.FirstName,
					prf.LastName,
					prf.Company,
					prf.PhoneNumber,
					prf.Email,
					prf.WorkingAddress,
					prf.HomeAddress,
					prf.day, prf.month, prf.year);
	printf("\n| CONTACT ADDED!\n");
	fclose(ct);
	getchar();
}


void display_contact()
{
	
 	FILE *ct;
 	ct = fopen("contact.txt", "r");
	
	char a[20][20], temp[20];
	int count = 0, i, j;
	
	while (fscanf(ct, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
 					&prf.FirstName,
					&prf.LastName,
					&prf.Company,
					&prf.PhoneNumber,
					&prf.Email,
					&prf.WorkingAddress,
					&prf.HomeAddress,
					&prf.day, &prf.month, &prf.year) == 10)

			{
			strcpy(a[count], prf.FirstName);
  			count++;
			}
		
			for (i = count - 1; i > 0; i--)
        		for (j = 0; j < i; j++)
            		if (strcmp(a[j], a[j+1]) > 0)
            			{
							strcpy(temp, a[j]);
							strcpy(a[j], a[j+1]);
							strcpy(a[j+1], temp);
            			}

			printf(" -------------------------------------------------------------------------------------------------------------------------------------\n"); 
			printf("| First Name   Last Name           Company   Phone Number                         Email   Working Address   Home Address     Birthday |\n");
			printf(" -------------------------------------------------------------------------------------------------------------------------------------\n");
			
			for (i = 0; i<count; i++)
 				{
  				rewind(ct);
  				while (fscanf(ct, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
								&prf.FirstName,
								&prf.LastName,
								&prf.Company,
								&prf.PhoneNumber,
								&prf.Email,
								&prf.WorkingAddress,
								&prf.HomeAddress,
								&prf.day, &prf.month, &prf.year) == 10)
  					{
   						if (strcmp(a[i], prf.FirstName) == 0)
    					printf("|%11s %11s %17s %14s %29s %17s %14s   %02d/%02d/%d |\n", 
									prf.FirstName,
									prf.LastName,
									prf.Company,
									prf.PhoneNumber,
									prf.Email,
									prf.WorkingAddress,
									prf.HomeAddress,
									prf.day, prf.month, prf.year );

  					}
			
				}
 	fclose(ct);
}


void search_contact()
{
	FILE *ct;
	int check;
	char pn[12], pqt[12];
 	printf("\n| Enter the Phone Number you want to search: ");
 	scanf("%[^\n]c", &pn);
 	check = checkPhoneNumber(pn);
 	if (check == 0)
  		printf("| (?) Your Phone Number is not available in the file!\n", pn);
 	else
 	{
  		ct = fopen("contact.txt", "r");
		printf("\n -------------------------------------------------------------------------------------------------------------------------------------\n"); 
		printf("|First Name   Last Name           Company   Phone Number                          Email   Working Address   Home Address     Birthday |\n");
		printf(" -------------------------------------------------------------------------------------------------------------------------------------\n");
  		while (fscanf(ct, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
 					&prf.FirstName,
					&prf.LastName,
					&prf.Company,
					&prf.PhoneNumber,
					&prf.Email,
					&prf.WorkingAddress,
					&prf.HomeAddress,
					&prf.day, &prf.month, &prf.year) == 10)
  			{
  	 			strcpy(pqt, prf.PhoneNumber);
   				if (strcmp(pqt, pn) == 0)
   					{
    				printf("|%10s %11s %17s %14s %30s %17s %14s   %02d/%02d/%d |\n", 
					prf.FirstName,
					prf.LastName,
					prf.Company,
					prf.PhoneNumber,
					prf.Email,
					prf.WorkingAddress,
					prf.HomeAddress,
					prf.day, prf.month, prf.year );
   					}
  			}
  	fclose(ct);
 }
 getchar();
}


void edit_contact()
{
	FILE *cto;
	FILE *ctt;
	int check, choice;
	char pn[12], pqt[12];
	printf("\n| Enter the Phone Number of the contact you want to edit: ");
 	scanf("%[^\n]c", &pn);
 	check = checkPhoneNumber(pn);
 	if (check == 0)
  		printf("| (?) Your Phone Number is not available in the file!\n", pn);
 	else
	{
		cto = fopen("contact.txt", "r");
		ctt = fopen("temp_contact.txt", "w");
		while (fscanf(cto, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
 					&prf.FirstName,
					&prf.LastName,
					&prf.Company,
					&prf.PhoneNumber,
					&prf.Email,
					&prf.WorkingAddress,
					&prf.HomeAddress,
					&prf.day, &prf.month, &prf.year) == 10)
			{
			strcpy(pqt, prf.PhoneNumber);
			if (strcmp(pqt, pn) != 0)
				fprintf(ctt, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
					prf.FirstName,
					prf.LastName,
					prf.Company,
					prf.PhoneNumber,
					prf.Email,
					prf.WorkingAddress,
					prf.HomeAddress,
					prf.day, prf.month, prf.year);
			else
				{
					printf("\n|\t1. Edit First Name");
    				printf("\n|\t2. Edit Last Name");
					printf("\n|\t3. Edit Company");
					printf("\n|\t4. Edit Phone Number");
					printf("\n|\t5. Edit Email");
					printf("\n|\t6. Edit Working Address");
					printf("\n|\t7. Edit Home Address");
					printf("\n|\t8. Edit Birthday\n");
    				printf("\n| Enter your choice: ");
					scanf("%d", &choice);

					switch(choice)
					{
						case 1:
							printf("| Enter First Name: ");
							scanf("%*c%[^\n]", &prf.FirstName);
							break;
						case 2:
							printf("| Enter Last Name: ");
							scanf("%*c%[^\n]", &prf.LastName);
							break;
						case 3:
							printf("| Enter Company: ");
							scanf("%*c%[^\n]", &prf.Company);
							break;
						case 4:
							printf("| Enter Phone Number: ");
							scanf("%*c%[^\n]", &prf.PhoneNumber);
							phonenum_valid(prf.PhoneNumber);
							break;
						case 5:
							printf("| Enter Email: ");
							scanf("%*c%[^\n]", &prf.Email);
							break;
						case 6:
							printf("| Enter Working Address: ");
							scanf("%*c%[^\n]", &prf.WorkingAddress);
							break;
						case 7:
							printf("| Enter Home Address: ");
							scanf("%*c%[^\n]", &prf.HomeAddress);
							break;
						case 8:
							printf("| Enter Birthday: ");
							scanf("%d/%d/%d", &prf.day, &prf.month, &prf.year);
							date_valid(prf.day, prf.month, prf.year);
							break;
						default:
     						printf("| (?) Invalid Selection!");
     						break;
					}
					fprintf(ctt, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
					prf.FirstName,
					prf.LastName,
					prf.Company,
					prf.PhoneNumber,
					prf.Email,
					prf.WorkingAddress,
					prf.HomeAddress,
					prf.day, prf.month, prf.year);

				}

		}
		fclose(cto);
		fclose(ctt);
		cto = fopen("contact.txt", "w");
		ctt = fopen("temp_contact.txt", "r");
		while (fscanf(ctt, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
						&prf.FirstName,
						&prf.LastName,
						&prf.Company,
						&prf.PhoneNumber,
						&prf.Email,
						&prf.WorkingAddress,
						&prf.HomeAddress,
						&prf.day, &prf.month, &prf.year) == 10)
				fprintf(cto, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
						prf.FirstName,
						prf.LastName,
						prf.Company,
						prf.PhoneNumber,
						prf.Email,
						prf.WorkingAddress,
						prf.HomeAddress,
						prf.day, prf.month, prf.year);
		printf("\n| CONTACT UPDATED\n");
		fclose(cto);
		fclose(ctt);

		
	}
	getchar();
	
}


void delete_contact()
{

	FILE *cto;
	FILE *ctt;
	int check, choice;
	char pn[12], pqt[12];
	printf("\n| Enter the Phone Number of the contact you want to delete: ");
 	scanf("%[^\n]c", &pn);
 	check = checkPhoneNumber(pn);
 	if (check == 0)
  		printf("| (?) Your Phone Number is not available in the file!\n\n", pn);
 	else
	{
		cto = fopen("contact.txt", "r");
		ctt = fopen("temp_contact.txt", "w");
		while (fscanf(cto, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
 					&prf.FirstName,
					&prf.LastName,
					&prf.Company,
					&prf.PhoneNumber,
					&prf.Email,
					&prf.WorkingAddress,
					&prf.HomeAddress,
					&prf.day, &prf.month, &prf.year) == 10)
		{
		strcpy(pqt, prf.PhoneNumber);
		if (strcmp(pqt, pn) != 0)
			
				fprintf(ctt, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
					prf.FirstName,
					prf.LastName,
					prf.Company,
					prf.PhoneNumber,
					prf.Email,
					prf.WorkingAddress,
					prf.HomeAddress,
					prf.day, prf.month, prf.year);
		
		}
	
	fclose(cto);
	fclose(ctt);
	cto = fopen("contact.txt", "w");
	ctt = fopen("temp_contact.txt", "r");
	while (fscanf(ctt, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
 					&prf.FirstName,
					&prf.LastName,
					&prf.Company,
					&prf.PhoneNumber,
					&prf.Email,
					&prf.WorkingAddress,
					&prf.HomeAddress,
					&prf.day, &prf.month, &prf.year) == 10)
			fprintf(cto, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
					prf.FirstName,
					prf.LastName,
					prf.Company,
					prf.PhoneNumber,
					prf.Email,
					prf.WorkingAddress,
					prf.HomeAddress,
					prf.day, prf.month, prf.year);
	
	printf("\n| CONTACT DELETED\n\n");
	fclose(cto);
	fclose(ctt);
	}
	getchar();

}


void birthday_display()
{
	FILE *cto;
	FILE *ctt;
	cto = fopen("contact.txt", "r");
	ctt = fopen("temp_contact.txt", "w");
	int x, d[20], m[20], y[20], count = 0, i;
	char c;
	printf("| Enter a month: ");
	scanf("%d", &x);
	
	if (x < 1 || x > 12)
		printf("| (?) Invalid month!\n\n");
	else
	{
		

		while (fscanf(cto, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
									&prf.FirstName,
									&prf.LastName,
									&prf.Company,
									&prf.PhoneNumber,
									&prf.Email,
									&prf.WorkingAddress,
									&prf.HomeAddress,
									&prf.day, &prf.month, &prf.year) == 10)
						{
						if (x == prf.month)
							{
							d[count] = prf.day;
							m[count] = prf.month;
							y[count] = prf.year;
							count++;
							}
						}
		selection_date_sort(d, m, y, count);
		for (i = 0; i<count; i++)
		{
			rewind(cto);
			while (fscanf(cto, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
									&prf.FirstName,
									&prf.LastName,
									&prf.Company,
									&prf.PhoneNumber,
									&prf.Email,
									&prf.WorkingAddress,
									&prf.HomeAddress,
									&prf.day, &prf.month, &prf.year) == 10)
							if (d[i] == prf.day && m[i] == prf.month && y[i] == prf.year)
								fprintf(ctt, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
													prf.FirstName,
													prf.LastName,
													prf.Company,
													prf.PhoneNumber,
													prf.Email,
													prf.WorkingAddress,
													prf.HomeAddress,
													prf.day, prf.month, prf.year);
		}
		fclose(cto);
		fclose(ctt);
		printf(" \n-------------------------------------------------------------------------------------------------------------------------------------\n"); 
		printf("| First Name   Last Name           Company   Phone Number                         Email   Working Address   Home Address     Birthday |\n");
		printf(" -------------------------------------------------------------------------------------------------------------------------------------\n");
		ctt = fopen("temp_contact.txt", "r");
		while (fscanf(ctt, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
									&prf.FirstName,
									&prf.LastName,
									&prf.Company,
									&prf.PhoneNumber,
									&prf.Email,
									&prf.WorkingAddress,
									&prf.HomeAddress,
									&prf.day, &prf.month, &prf.year) == 10)
						{
							
							printf("|%11s %11s %17s %14s %29s %17s %14s   %02d/%02d/%d |\n", 
									prf.FirstName,
									prf.LastName,
									prf.Company,
									prf.PhoneNumber,
									prf.Email,
									prf.WorkingAddress,
									prf.HomeAddress,
									prf.day, prf.month, prf.year );

						}

	}
	getchar();


}


void date_valid(int dd, int mm, int yy)
{
    if(yy>=1900 && yy<=2022)
    {
        if(mm>=1 && mm<=12)
        {
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                goto end;
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                goto end;
            else if((dd>=1 && dd<=28) && (mm==2))
                goto end;
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                goto end;
            else
                printf("| (?) Your birthday is invalid or in wrong format!\n");
				printf("| Re-enter your Birthday: ");
				scanf("%d/%d/%d", &prf.day, &prf.month, &prf.year);
				date_valid(prf.day, prf.month, prf.year);
        }
        else
        {
            printf("| (?) Your birthday is invalid or in wrong format!\n");
			printf("| Re-enter your Birthday: ");
			scanf("%d/%d/%d", &prf.day, &prf.month, &prf.year);
			date_valid(prf.day, prf.month, prf.year);
        }
    }
    else
    {
        printf("| (?) Your birthday is invalid or in wrong format!\n");
		printf("| Re-enter your Birthday: ");
		scanf("%d/%d/%d", &prf.day, &prf.month, &prf.year);
		date_valid(prf.day, prf.month, prf.year);
    }
    end:;

}


void phonenum_valid(char str[])
{
	int i;
	if (strlen(str) < 9 || strlen(str) > 11)
		{
			printf("| (?) Invalid Phone Number!\n");
			printf("| Re-enter your Phone Number: ");
			scanf("%*c%[^\n]", &prf.PhoneNumber);
			phonenum_valid(prf.PhoneNumber);
		}
	else
		{
		for(i = 0; str[i] != '\0'; i++)
			if (isdigit(str[i]) == 0)
			{
				printf("| (?) Invalid Phone Number!\n");
				printf("| Re-enter your Phone Number: ");
				scanf("%*c%[^\n]", &prf.PhoneNumber);
				phonenum_valid(prf.PhoneNumber);
			}
		}
}


int checkPhoneNumber(char pn[])
{
 FILE *ct;
 struct check
 {
	char FirstName[20];
	char LastName[20];
	char Company[20];
	char PhoneNumber[12];
	char Email[50];
	char WorkingAddress[100];
	char HomeAddress[100];
	int day, month, year;
 }prf1;
 ct = fopen("contact.txt", "r");
 while (fscanf(ct, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
 					&prf1.FirstName,
					&prf1.LastName,
					&prf1.Company,
					&prf1.PhoneNumber,
					&prf1.Email,
					&prf1.WorkingAddress,
					&prf1.HomeAddress,
					&prf1.day, &prf1.month, &prf1.year) == 10)
  	{
	  if (strcmp(pn, prf1.PhoneNumber) == 0)
  		{
   		fclose(ct);
   		return 1;
  		}
	}	  
 		fclose(ct);
 		return 0;
    
}


int checkEmpty()
{
	int ch = 0;
	FILE *ct;
	ct = fopen("contact.txt", "r");
	while (fscanf(ct, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
 					&prf.FirstName,
					&prf.LastName,
					&prf.Company,
					&prf.PhoneNumber,
					&prf.Email,
					&prf.WorkingAddress,
					&prf.HomeAddress,
					&prf.day, &prf.month, &prf.year) == 10)
	ch = 1;
	fclose(ct);
	return ch;
}


void selection_date_sort(int d[], int m[], int y[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
        for (j = i+1; j < size; j++)
        {
            if (y[i] < y[j])
                {
                    temp = y[i];
                    y[i] = y[j];
                    y[j] = temp;

                    temp = m[i];
                    m[i] = m[j];
                    m[j] = temp;

                    temp = d[i];
                    d[i] = d[j];
                    d[j] = temp;
        
                }
            else if (y[i] == y[j] && m[i] < m[j])
                {
                    temp = y[i];
                    y[i] = y[j];
                    y[j] = temp;

                    temp = m[i];
                    m[i] = m[j];
                    m[j] = temp;

                    temp = d[i];
                    d[i] = d[j];
                    d[j] = temp;
        
        
                }
            else if (y[i] == y[j] && m[i] == m[j] && d[i] < d[j])
                {
                    temp = y[i];
                    y[i] = y[j];
                    y[j] = temp;

                    temp = m[i];
                    m[i] = m[j];
                    m[j] = temp;

                    temp = d[i];
                    d[i] = d[j];
                    d[j] = temp;
        
                }
        }

}





































/** Make by Pham Quoc Trung, Dang Truong An and Tran Trong Duc. Please do not copy!**/
/** Copyright 2022, Pham Quoc Trung, All rights reserved.**/
