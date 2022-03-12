/** Make by Pham Quoc Trung, Dang Truong An and Tran Trong Duc. Please do not copy! **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <stdbool.h>


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
};

void print_menu();
void add_contact();
void edit_contact();
void delete_contact();
void display_contact();
void search_contact();
int date_valid();
int phonenum_valid();
int checkPhoneNumber();
int checkEmpty();
void birthday_display();
void selection_date_sort();
HWND WINAPI GetConsoleWindowNT();
void DisableResizeWindow();


void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1)
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    if (Min == 1)
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    if (Max == 1)
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
}



int main()
{
	char choice;
	do
	{
		// printf("\033[38;5;85m");
		HWND hWnd=GetConsoleWindowNT();
    	MoveWindow(hWnd,0,0,1040,500,TRUE);
		DisableResizeWindow();
		DisableCtrButton(0,0,1);
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
	struct contact prf;

    ct = fopen("contact.txt", "a+");


	printf("| 1. First Name: ");
	scanf("%[^\n]", &prf.FirstName);
	while (strlen(prf.FirstName) == 0)
		{
		printf("| (?) You can not leave it emty! \n");
		printf("| Re-enter First Name: ");
		scanf("%*c%[^\n]", &prf.FirstName);
		}


	printf("| 2. Last Name: ");
	scanf("%*c%[^\n]", &prf.LastName);
	while (strlen(prf.LastName) == 0)
		{
		printf("| (?) You can not leave it emty! \n");
		printf("| Re-enter Last Name: ");
		scanf("%*c%[^\n]", &prf.LastName);
		}

    printf("| 3. Company: ");
	strcpy(prf.Company,"");
	scanf("%*c%[^\n]", &prf.Company);
	while (strlen(prf.Company) == 0)
		{
		printf("| (?) You can not leave it emty! \n");
		printf("| Re-enter Company: ");
		scanf("%*c%[^\n]", &prf.Company);
		}


    printf("| 4. Phone number: ");
	scanf("%*c%[^\n]", &prf.PhoneNumber);
	while (checkPhoneNumber(prf.PhoneNumber) == 1)
	{
		
		printf("| (?) Phone Number existed!\n");
		printf("| Re-enter Phone Number: ");
		scanf("%*c%[^\n]", &prf.PhoneNumber);

	}
	while (phonenum_valid(prf.PhoneNumber) == 0)
	{
		printf("| (?) Invalid Phone Number!\n");
		printf("| Re-enter your Phone Number: ");
		scanf("%*c%[^\n]", &prf.PhoneNumber);
		
	}



    printf("| 5. Email: ");
	strcpy(prf.Email,"");
	scanf("%*c%[^\n]", &prf.Email);
	while (strlen(prf.Email) == 0)
		{
		printf("| (?) You can not leave it emty! \n");
		printf("| Re-enter Email: ");
		scanf("%*c%[^\n]", &prf.Email);
		}


    printf("| 6. Working Address: ");
	scanf("%*c%[^\n]", &prf.WorkingAddress);
	while (strlen(prf.WorkingAddress) == 0)
		{
		printf("| (?) You can not leave it emty! \n");
		printf("| Re-enter Working Address: ");
		scanf("%*c%[^\n]", &prf.WorkingAddress);
		}


	printf("| 7. Home Address: ");
	scanf("%*c%[^\n]", &prf.HomeAddress);
	while (strlen(prf.HomeAddress) == 0)
		{
		printf("| (?) You can not leave it emty! \n");
		printf("| Re-enter Home Address: ");
		scanf("%*c%[^\n]", &prf.HomeAddress);
		}


	printf("| 8. Birthday (dd/mm/yyyy): ");
	BD: scanf("%d/%d/%d", &prf.day, &prf.month, &prf.year);
	if (date_valid(prf.day, prf.month, prf.year) == 0)
    {
        printf("| (?) Your birthday is invalid or in wrong format!\n");
        printf("| Re-enter your Birthday: ");
        goto BD;

    }


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
	struct contact prf1;
 	FILE *ct;
 	ct = fopen("contact.txt", "r");

	char a[50][20], b[50][20], temp[20];
	int count = 0, i, j;

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
			strcpy(a[count], prf1.FirstName);
			strcpy(b[count], prf1.PhoneNumber);
  			count++;
			}

			for (i = count - 1; i > 0; i--)
        		for (j = 0; j < i; j++)
            		if (strcmp(a[j], a[j+1]) > 0)
            			{
							strcpy(temp, a[j]);
							strcpy(a[j], a[j+1]);
							strcpy(a[j+1], temp);

							strcpy(temp, b[j]);
							strcpy(b[j], b[j+1]);
							strcpy(b[j+1], temp);
            			}

			printf(" -------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("| First Name   Last Name           Company   Phone Number                         Email   Working Address   Home Address     Birthday |\n");
			printf(" -------------------------------------------------------------------------------------------------------------------------------------\n");

			for (i = 0; i<count; i++)
 				{
  				rewind(ct);
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
   						if (strcmp(a[i], prf1.FirstName) == 0 && strcmp(b[i], prf1.PhoneNumber) == 0)
    					printf("|%11s %11s %17s %14s %29s %17s %14s   %02d/%02d/%d |\n",
									prf1.FirstName,
									prf1.LastName,
									prf1.Company,
									prf1.PhoneNumber,
									prf1.Email,
									prf1.WorkingAddress,
									prf1.HomeAddress,
									prf1.day, prf1.month, prf1.year );

  					}

				}
 	fclose(ct);
}


void search_contact()
{
	FILE *ct;
	struct contact prf2;
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
 					&prf2.FirstName,
					&prf2.LastName,
					&prf2.Company,
					&prf2.PhoneNumber,
					&prf2.Email,
					&prf2.WorkingAddress,
					&prf2.HomeAddress,
					&prf2.day, &prf2.month, &prf2.year) == 10)
  			{
  	 			strcpy(pqt, prf2.PhoneNumber);
   				if (strcmp(pqt, pn) == 0)
   					{
    				printf("|%10s %11s %17s %14s %30s %17s %14s   %02d/%02d/%d |\n",
					prf2.FirstName,
					prf2.LastName,
					prf2.Company,
					prf2.PhoneNumber,
					prf2.Email,
					prf2.WorkingAddress,
					prf2.HomeAddress,
					prf2.day, prf2.month, prf2.year );
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
	struct contact prf3;
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
 					&prf3.FirstName,
					&prf3.LastName,
					&prf3.Company,
					&prf3.PhoneNumber,
					&prf3.Email,
					&prf3.WorkingAddress,
					&prf3.HomeAddress,
					&prf3.day, &prf3.month, &prf3.year) == 10)
			{
			strcpy(pqt, prf3.PhoneNumber);
			if (strcmp(pqt, pn) != 0)
				fprintf(ctt, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
					prf3.FirstName,
					prf3.LastName,
					prf3.Company,
					prf3.PhoneNumber,
					prf3.Email,
					prf3.WorkingAddress,
					prf3.HomeAddress,
					prf3.day, prf3.month, prf3.year);
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
							scanf("%*c%[^\n]", &prf3.FirstName);
							break;
						case 2:
							printf("| Enter Last Name: ");
							scanf("%*c%[^\n]", &prf3.LastName);
							break;
						case 3:
							printf("| Enter Company: ");
							scanf("%*c%[^\n]", &prf3.Company);
							break;
						case 4:
							printf("| Enter Phone Number: ");
							scanf("%*c%[^\n]", &prf3.PhoneNumber);
							phonenum_valid(prf3.PhoneNumber);
							break;
						case 5:
							printf("| Enter Email: ");
							scanf("%*c%[^\n]", &prf3.Email);
							break;
						case 6:
							printf("| Enter Working Address: ");
							scanf("%*c%[^\n]", &prf3.WorkingAddress);
							break;
						case 7:
							printf("| Enter Home Address: ");
							scanf("%*c%[^\n]", &prf3.HomeAddress);
							break;
						case 8:
							printf("| Enter Birthday: ");
							scanf("%d/%d/%d", &prf3.day, &prf3.month, &prf3.year);
							date_valid(prf3.day, prf3.month, prf3.year);
							break;
						default:
     						printf("| (?) Invalid Selection!");
     						break;
					}
					fprintf(ctt, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
					prf3.FirstName,
					prf3.LastName,
					prf3.Company,
					prf3.PhoneNumber,
					prf3.Email,
					prf3.WorkingAddress,
					prf3.HomeAddress,
					prf3.day, prf3.month, prf3.year);

				}

		}
		fclose(cto);
		fclose(ctt);
		cto = fopen("contact.txt", "w");
		ctt = fopen("temp_contact.txt", "r");
		while (fscanf(ctt, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
						&prf3.FirstName,
						&prf3.LastName,
						&prf3.Company,
						&prf3.PhoneNumber,
						&prf3.Email,
						&prf3.WorkingAddress,
						&prf3.HomeAddress,
						&prf3.day, &prf3.month, &prf3.year) == 10)
				fprintf(cto, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
						prf3.FirstName,
						prf3.LastName,
						prf3.Company,
						prf3.PhoneNumber,
						prf3.Email,
						prf3.WorkingAddress,
						prf3.HomeAddress,
						prf3.day, prf3.month, prf3.year);
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
	struct contact prf4;
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
 					&prf4.FirstName,
					&prf4.LastName,
					&prf4.Company,
					&prf4.PhoneNumber,
					&prf4.Email,
					&prf4.WorkingAddress,
					&prf4.HomeAddress,
					&prf4.day, &prf4.month, &prf4.year) == 10)
		{
		strcpy(pqt, prf4.PhoneNumber);
		if (strcmp(pqt, pn) != 0)

				fprintf(ctt, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
					prf4.FirstName,
					prf4.LastName,
					prf4.Company,
					prf4.PhoneNumber,
					prf4.Email,
					prf4.WorkingAddress,
					prf4.HomeAddress,
					prf4.day, prf4.month, prf4.year);

		}

	fclose(cto);
	fclose(ctt);
	cto = fopen("contact.txt", "w");
	ctt = fopen("temp_contact.txt", "r");
	while (fscanf(ctt, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
 					&prf4.FirstName,
					&prf4.LastName,
					&prf4.Company,
					&prf4.PhoneNumber,
					&prf4.Email,
					&prf4.WorkingAddress,
					&prf4.HomeAddress,
					&prf4.day, &prf4.month, &prf4.year) == 10)
			fprintf(cto, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
					prf4.FirstName,
					prf4.LastName,
					prf4.Company,
					prf4.PhoneNumber,
					prf4.Email,
					prf4.WorkingAddress,
					prf4.HomeAddress,
					prf4.day, prf4.month, prf4.year);

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
	struct contact prf5;
	cto = fopen("contact.txt", "r");
	ctt = fopen("temp_contact.txt", "w");
	int x, d[20], m[20], y[20], count = 0, i;
	char a[20][20];
	printf("| Enter a month: ");
	scanf("%d", &x);

	if (x < 1 || x > 12)
		printf("| (?) Invalid month!\n\n");
	else
	{


		while (fscanf(cto, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
									&prf5.FirstName,
									&prf5.LastName,
									&prf5.Company,
									&prf5.PhoneNumber,
									&prf5.Email,
									&prf5.WorkingAddress,
									&prf5.HomeAddress,
									&prf5.day, &prf5.month, &prf5.year) == 10)
						{
						if (x == prf5.month)
							{
							d[count] = prf5.day;
							m[count] = prf5.month;
							y[count] = prf5.year;
							strcpy(a[count], prf5.PhoneNumber);
							count++;
							}
						}
		selection_date_sort(d, m, y, a, count);
		for (i = 0; i<count; i++)
		{
			rewind(cto);
			while (fscanf(cto, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
									&prf5.FirstName,
									&prf5.LastName,
									&prf5.Company,
									&prf5.PhoneNumber,
									&prf5.Email,
									&prf5.WorkingAddress,
									&prf5.HomeAddress,
									&prf5.day, &prf5.month, &prf5.year) == 10)
							if (d[i] == prf5.day && m[i] == prf5.month && y[i] == prf5.year && strcmp(a[i], prf5.PhoneNumber) == 0 )
								fprintf(ctt, "%s|%s|%s|%s|%s|%s|%s|%02d/%02d/%d\n",
													prf5.FirstName,
													prf5.LastName,
													prf5.Company,
													prf5.PhoneNumber,
													prf5.Email,
													prf5.WorkingAddress,
													prf5.HomeAddress,
													prf5.day, prf5.month, prf5.year);
		}
		fclose(cto);
		fclose(ctt);
		printf(" \n-------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("| First Name   Last Name           Company   Phone Number                         Email   Working Address   Home Address     Birthday |\n");
		printf(" -------------------------------------------------------------------------------------------------------------------------------------\n");
		ctt = fopen("temp_contact.txt", "r");
		while (fscanf(ctt, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
									&prf5.FirstName,
									&prf5.LastName,
									&prf5.Company,
									&prf5.PhoneNumber,
									&prf5.Email,
									&prf5.WorkingAddress,
									&prf5.HomeAddress,
									&prf5.day, &prf5.month, &prf5.year) == 10)
						{

							printf("|%11s %11s %17s %14s %29s %17s %14s   %02d/%02d/%d |\n",
									prf5.FirstName,
									prf5.LastName,
									prf5.Company,
									prf5.PhoneNumber,
									prf5.Email,
									prf5.WorkingAddress,
									prf5.HomeAddress,
									prf5.day, prf5.month, prf5.year );

						}

	}
	getchar();


}


int date_valid(int dd, int mm, int yy)
{
   if(yy>=100 && yy<=9999){
      if(mm>=1 && mm<=12){
         if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12));
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11));
               else if((dd>=1 && dd<=28) && (mm==2));
                  else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)));
            else
               return 0;
            } else{
            return 0;
         }
      } else {
      return 0;
   }
}


int phonenum_valid(char str[])
{
	int i;
	if (strlen(str) < 9 || strlen(str) > 11)
			return 0;
	else if (strlen(str) >= 9 && strlen(str) <= 11)
		for(i = 0; str[i] != '\0'; i++)
			if (isdigit(str[i]) == 0)
				return 0;
	else
		return 1;


}


int checkPhoneNumber(char pn[])
{
 FILE *ct;
 struct contact prf8;
 ct = fopen("contact.txt", "r");
 while (fscanf(ct, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
 					&prf8.FirstName,
					&prf8.LastName,
					&prf8.Company,
					&prf8.PhoneNumber,
					&prf8.Email,
					&prf8.WorkingAddress,
					&prf8.HomeAddress,
					&prf8.day, &prf8.month, &prf8.year) == 10)
  	{
	  if (strcmp(pn, prf8.PhoneNumber) == 0)
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
	struct contact prf9;
	FILE *ct;
	ct = fopen("contact.txt", "r");
	while (fscanf(ct, "%20[^|]|%20[^|]|%20[^|]|%11[^|]|%50[^|]|%100[^|]|%100[^|]|%d/%d/%d%*c",
 					&prf9.FirstName,
					&prf9.LastName,
					&prf9.Company,
					&prf9.PhoneNumber,
					&prf9.Email,
					&prf9.WorkingAddress,
					&prf9.HomeAddress,
					&prf9.day, &prf9.month, &prf9.year) == 10)
	ch = 1;
	fclose(ct);
	return ch;
}


void selection_date_sort(int d[], int m[], int y[], char a[][20], int size)
{
    int i, j, temp;
	char tempc[20];
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

					strcpy(tempc, a[i]);
					strcpy(a[i], a[j]);
					strcpy(a[j], tempc);

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

					strcpy(tempc, a[i]);
					strcpy(a[i], a[j]);
					strcpy(a[j], tempc);


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

					strcpy(tempc, a[i]);
					strcpy(a[i], a[j]);
					strcpy(a[j], tempc);

                }
        }

}


HWND WINAPI GetConsoleWindowNT(void)
{
    //declare function pointer type
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    //declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;
    //get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    //assign procedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib
    ,TEXT("GetConsoleWindow"));
    //check if the function pointer is valid
    //since the function is undocumented
    if(GetConsoleWindow == NULL){
        return NULL;
    }
    //call the undocumented function
    return GetConsoleWindow();
}


void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}































/** Make by Pham Quoc Trung, Dang Truong An and Tran Trong Duc. Please do not copy!**/
/** Copyright 2022, Pham Quoc Trung, All rights reserved.**/
