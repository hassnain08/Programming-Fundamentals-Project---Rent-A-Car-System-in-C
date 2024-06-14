#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void SignUp();
void Login();
void display(char carLISTinfo[24][3][20], char carCTGinfo[4][1][20]);
void RentACar(char carLISTinfo[24][3][20], char carCTGinfo[4][1][20], char carDETAILinfo[24][4][50], int Days, char CompareCar[50]);
void Compare(char CompareCar[50], char carLISTinfo[24][3][20], char carCTGinfo[4][1][20], char CarName[50], char carDETAILinfo[24][4][50], int ChosenCategory);
int Availability(char CarName[50]);
int Car_Issue(int Days, char CarName[50]);
void UserDetails();

int main()
{
    int Days; char CompareCar[50];

    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t Simple Car Rental System Login");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t   WELCOME DEAR CUSTOMER!!!\n");

    char carCTGinfo[4][1][20] = {
    {"Mini"}, {"Commercial"}, {"Comfort"}, {"Luxury"}};
    char carLISTinfo[24][3][20] = {
        {"1.       Alto", "  Suzuki", "      2019"},
        {"2.      Cultus", "     Suzuki", "      2020"},
        {"3.     Wagon R", "     Suzuki", "      2022"},
        {"4.       Moco", "      Nissan", "      2011"},
        {"5.     Picanto", "      KIA", "        2021"},
        {"6.      Swift", "      Suzuki", "      2023"},

        {"1.  Corolla Yaris", "  Toyota", "      2022"},
        {"2.      Civic", "       Honda", "      2021"},
        {"3.  Karvaan Plus", "   Changan", "     2018"},
        {"4.  Civic Rebirth", "   Honda", "      2015"},
        {"5.   Corolla Gli", "   Toyota", "      2016"},
        {"6.      Camry", "      Toyota", "      2019"},

        {"1.     Sonata", "      Hyundai", "     2022"},
        {"2.       HS", "          MG", "        2021"},
        {"3.      Prius", "      Toyota", "      2023"},
        {"4.    Sportage", "      KIA", "        2022"},
        {"5.       HRV", "        Honda", "      2022"},
        {"6.     Elantra", "     Hyundai", "     2023"},

        {"1.     Bmw I4", "       BMW", "        2022"},
        {"2.   Mercedes S", "Mercedes", "    2013"},
        {"3.    Audi A4", "       Audi", "       2017"},
        {"4.    Audi A8", "       Audi", "       2020"},
        {"5.    Fortuner", "     Toyota", "      2021"},
        {"6.   Ford Edge", "      Ford", "       2019"}
        };
        char carDETAILinfo[24][4][50] = {
        {"Alto", "1. Engine: 660 CC", "2. Milege(km): 18 to 22", "3. Transmission: Automatic"},
        {"Cultus", "1. Engine: 1000 CC", "2. Milege(km): 16 to 18", "3. Transmission: Automatic"},
        {"Wagon R", "1. Engine: 1000 CC", "2. Milege(km): 14 to 18", "3. Transmission: Automatic"},
        {"Moco", "1. Engine: 660 CC", "2. Milege(km): 24 to 30", "3. Transmission: Automatic/Manual"},
        {"Picanto", "1. Engine: 1000 CC", "2. Milege(km): 12 to 15", "3. Transmission: Automatic/Manual"},
        {"Swift", "1. Engine: 1000 CC", "2. Milege(km): 18 to 24", "3. Transmission: Automatic"},

        {"Corolla Yaris", "1. Engine: 1500 CC", "2. Milege(km): 12 to 16", "3. Transmission: Automatic"},
        {"Civic", "1. Engine: 1800 CC", "2. Milege(km): 12 to 16", "3. Transmission: Automatic"},
        {"Karvaan Plus", "1. Engine: 1000 CC", "2. Milege(km): 10 to 12", "3. Transmission: Automatic"},
        {"Civic Rebirth", "1. Engine: 1800 CC", "2. Milege(km): 16 to 18", "3. Transmission: Automatic"},
        {"Corolla Gli", "1. Engine: 1800 CC", "2. Milege(km): 10 to 16", "3. Transmission: Automatic"},
        {"Camry", "1. Engine: 2450 CC", "2. Milege(km): 14 to 19", "3. Transmission: Automatic"},

        {"Sonata", "1. Engine: 1800 CC", "2. Milege(km): 12 to 15", "3. Transmission: Automatic"},
        {"HS", "1. Engine: 1500 CC", "2. Milege(km): 10 to 18", "3. Transmission: Automatic"},
        {"Prius", "1. Engine: 1800 CC", "2. Milege(km): 20 to 23", "3. Transmission: Automatic"},
        {"Sportage", "1. Engine: 2000 CC", "2. Milege(km): 10 to 12", "3. Transmission: Automatic"},
        {"HRV", "1. Engine: 1500 CC", "2. Milege(km): 13 to 15", "3. Transmission: Automatic"},
        {"Elantra", "1. Engine: 1600 CC", "2. Milege(km): 14 to 16", "3. Transmission: Automatic"},

        {"Bmw I4", "1. Battery: 66 kWh", "2. Milege(miles): 250 to 280", "3. Transmission: Automatic"},
        {"Mercedes S ", "1. Engine: 2925 CC", "2. Milege(km/l): 13 to 15", "3. Transmission: Automatic"},
        {"Audi A4", "1. Engine: 2000 CC", "2. Milege(km/l): 17 to 18", "3. Transmission: Automatic"},
        {"Audi A8", "1. Engine: 2995 CC", "2. Milege(km/l): 12 ro 13", "3. Transmission: Automatic"},
        {"Fortuner", "1. Engine: 2694 CC", "2. Milege(km): 9 to 11", "3. Transmission: Automatic"},
        {"Ford Edge", "1. Engine: 2000 CC", "2. Milege(km/l): 12 to 14", "3. Transmission: Automatic"},
        };

	char choice[10];

	printf("Dear Customer! Do you want to SignUp or Login?\n");
	fgets(choice, sizeof(choice), stdin);

	int length = strlen(choice);

	    if (choice[length - 1] == '\n')
	    {
	        choice[length - 1] = '\0';
	    }

	    if (strcmp(choice, "login") == 0 || strcmp(choice, "Login") == 0 || strcmp(choice, "LOGIN") == 0)
	    {
	        	int isLoggedIn = 0;  //initialize to 0 (not logged in)
    			Login(&isLoggedIn);
	    }
	    else if (strcmp(choice, "SIGNUP") == 0 || strcmp(choice, "Sign up") == 0 || strcmp(choice, "signup") == 0 || strcmp(choice, "sign up") == 0)
	    {
	        	SignUp();

	        	//Asking for login after signup

	        	printf("Do you want to Login now? (yes/no): ");
	        	fgets(choice, sizeof(choice), stdin);

	        	length = strlen(choice);

	        		if (choice[length - 1] == '\n')
	        		{
	        		    choice[length - 1] = '\0';
	        		}

	        	if (strcmp(choice, "Yes") == 0 || strcmp(choice, "YES") == 0 || strcmp(choice, "yes") == 0)
	        	{
		        	 int isLoggedIn = 0;  // Initialize to 0 (not logged in)
    				 Login(&isLoggedIn);
	        	}
	        	else
	        	{
	        	    printf("Thank You!\n");
	        	}
	    	}
	   	else
	   	{
	   	     printf("Invalid choice.\n");
	   	}
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t CAR SELECTION\n");

    	display(carLISTinfo, carCTGinfo);

	RentACar(carLISTinfo, carCTGinfo, carDETAILinfo, Days, CompareCar);

    //function for if u want to rent
    //function for choosing car
    //function for asking if compare then comparing cars details
    // function for final selection + details.
    // add time function
    //rent per day + total rent

    return 0;
}

void SignUp()
{
    char USERpass[17];

    printf("Set Your Desired Password (It Should be between 8 to 15 characters long): ");
    fgets(USERpass, sizeof(USERpass), stdin);

    int len = strlen(USERpass);
    if (USERpass[len - 1] == '\n')
    {
        USERpass[len - 1] = '\0';
    }

    if (strlen(USERpass) < 8 || strlen(USERpass) > 15)
    {
        printf("Please set the password according to appropriate limits.\n");
        return;
    }

    FILE *file = fopen("passwords.txt", "a");
    if (file != NULL)
    {
        fprintf(file, "%s\n", USERpass);
        fclose(file);
        printf("Signup successful! Password saved.\n");
    }
    else
    {
        printf("Error opening file for writing.\n");
    }
}

void Login(int *isLoggedIn) {
    char USERpass[17];

    printf("Enter Login password: ");
    fgets(USERpass, sizeof(USERpass), stdin);

    int len = strlen(USERpass);
    if (USERpass[len - 1] == '\n') {
        USERpass[len - 1] = '\0';
    }

    FILE *file = fopen("passwords.txt", "r");
    if (file != NULL)
    {
        char storedPassword[17];

        while (fgets(storedPassword, sizeof(storedPassword), file))
        {
            storedPassword[strcspn(storedPassword, "\n")] = '\0'; // Remove newline if present

            if (strcmp(storedPassword, USERpass) == 0)
            {
                fclose(file);
                printf("Login successful!\n");
                *isLoggedIn = 1; // Set the value pointed to by isLoggedIn to indicate successful login
                return;
            }
        }
        fclose(file);
    }

    printf("Incorrect password.\n");
    exit(0);
}

int Car_Issue(int Days, char CarName[50])
{
    int Day_Issue, Month_Issue, Year_Issue;
    int Day_Return, Month_Return, Year_Return;

    printf("Enter Date On Which Car Is To Be Issued (dd mm yyyy): \n");
    scanf("%d %d %d", & Day_Issue, & Month_Issue, & Year_Issue);
    printf("\a");

    printf("Enter Date On Which Car Is To Be Returned (dd mm yyyy): \n");
    scanf("%d %d %d", & Day_Return, & Month_Return ,& Year_Return);
    printf("\a");

    Days=(Year_Return-Year_Issue)*365+(Month_Return-Month_Issue)*30+(Day_Return-Day_Issue); // this logic is used to calucate the total amount of days that the user is renting the car for.

    printf("Total Amount of days are: %d",Days);

    int rentPerDay = 0;

   	 if (strcmp(CarName, "Alto") == 0) {
        	rentPerDay = 2800; }
         else if (strcmp(CarName, "Cultus") == 0) {
        	rentPerDay = 3000;
    } else if (strcmp(CarName, "Wagon R") == 0) {
        	rentPerDay = 3000;
    } else if (strcmp(CarName, "Moco") == 0) {
        	rentPerDay = 1500;
    } else if (strcmp(CarName, "Picanto") == 0) {
        	rentPerDay = 4000;
    } else if (strcmp(CarName, "Swift") == 0) {
        	rentPerDay = 1500;
    } else if (strcmp(CarName, "Corolla Yaris") == 0) {
        	rentPerDay = 2500;
    } else if (strcmp(CarName, "Civic") == 0) {
        	rentPerDay = 6000;
    } else if (strcmp(CarName, "Karvaan") == 0) {
        	rentPerDay = 4000;
    } else if (strcmp(CarName, "Civic Rebirth") == 0) {
        	rentPerDay = 3000;
    } else if (strcmp(CarName, "Corolla Gli") == 0) {
        	rentPerDay = 4000;
    } else if (strcmp(CarName, "Camry") == 0) {
        	rentPerDay = 6000;
    } else if (strcmp(CarName, "Sonata") == 0) {
        	rentPerDay = 8000; }
        else if (strcmp(CarName, "HS") == 0) {
        	rentPerDay = 8000; }
        else if (strcmp(CarName, "Prius") == 0) {
        	rentPerDay = 7000; }
        else if (strcmp(CarName, "SportAge") == 0) {
        	rentPerDay = 8000; }
        else if (strcmp(CarName, "HRV") == 0) {
        	rentPerDay = 8000; }
        else if (strcmp(CarName, "Elantra") == 0) {
        	rentPerDay = 9000; }
        else if (strcmp(CarName, "Bmw I4") == 0) {
        	rentPerDay = 20000; }
        else if (strcmp(CarName, "Mercedes S Class") == 0) {
        	rentPerDay = 23000; }
        else if (strcmp(CarName, "Audi A4") == 0) {
        	rentPerDay = 24000; }
        else if (strcmp(CarName, "Audi A8") == 0) {
        	rentPerDay = 25000; }
        else if (strcmp(CarName, "Fortuner") == 0) {
        	rentPerDay = 18000; }
        else if (strcmp(CarName, "Ford Edge") == 0) {
        	rentPerDay = 24000;
    }

    if (rentPerDay > 0)
    {
        printf("The rent per day for %s is %d\n", CarName, rentPerDay);
        printf("The rent for %d amount of days is: %d\n", Days, rentPerDay * Days);
        printf("\a");
        return rentPerDay * Days;
    } else
    {
        printf("Incorrect Input, Dear Customer Please Try Again!\n");
        return -1;
    }
}

void RentACar(char carLISTinfo[24][3][20], char carCTGinfo[4][1][20], char carDETAILinfo[24][4][50], int Days, char CompareCar[50])
{
    char CarCategory[50], CarName[50], Answer1[10], Answer2[10], Answer3[10], Answer4[10], Answer5[10];
    int ChosenCategory, CarAvailable;

do{
    printf("\nEnter the Car Category: ");
    fgets(CarCategory, sizeof(CarCategory), stdin);

    CarCategory[strcspn(CarCategory, "\n")] = '\0'; // Remove the newline character

    // Find the selected category
    ChosenCategory = -1;
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(CarCategory, carCTGinfo[i][0]) == 0)
        {
            ChosenCategory = i;
            break;
        }
    }

    if (ChosenCategory == -1)
    {
        printf("\nInvalid Car Category.\n");
        return;
    }

    printf("\nEnter the Car Name: ");
    fgets(CarName, sizeof(CarName), stdin);

    CarName[strcspn(CarName, "\n")] = '\0'; // Remove the newline character

    CarAvailable = Availability(CarName);

    if(!CarAvailable)
        {
            printf("\nSorry, the selected car \'%s\' is not available. Please choose another.\n", CarName);
        }
    } while (!CarAvailable);  //loop ends here

    printf("\nYour Car \'%s\' is Available.\n", CarName);

    printf("\nDo You Want To Compare It With Other Cars From %s Category?\n", CarCategory);
    fgets(Answer1, sizeof(Answer1), stdin);

     Answer1[strcspn(Answer1, "\n")] = '\0'; // Remove the newline character

    if (strcmp(Answer1, "Yes") == 0 || strcmp(Answer1, "yes") == 0)
    {
        	Compare(CompareCar, carLISTinfo, carCTGinfo, CarName, carDETAILinfo, ChosenCategory);

    		printf("\nDo You Want To Go With The Same Car?");
    		fgets(Answer2, sizeof(Answer2), stdin);

		Answer2[strcspn(Answer2, "\n")] = '\0';

    		if (strcmp(Answer2, "Yes")==0 || strcmp(Answer2, "Yes")==0)
    		{
    			printf("\nDear User you have Succesfully Chosen \'\'%s\'\' For Rent", CarName);

    			UserDetails();
    			Car_Issue(Days, CarName);
    		}
    		else if(strcmp(Answer2, "No")==0 || strcmp(Answer2, "no")==0)
    		{
    				printf("\nThen Would You Like The Car You Asked For Comparison?\n");
    				fgets(Answer3, sizeof(Answer3), stdin);

       			 	Answer3[strcspn(Answer3, "\n")] = '\0';

       	  			if (strcmp(Answer3, "Yes")==0 || strcmp(Answer3, "yes")==0)
    				{
    					UserDetails();
    					Car_Issue(Days, CarName);

    				}
    				else if(strcmp(Answer3, "No")==0 || strcmp(Answer3, "no")==0)
    				{
    					RentACar(carLISTinfo, carCTGinfo, carDETAILinfo, Days, CompareCar);
    				}
    		}
    		else{
    				printf("Would You Like To Choose Another Car?\n");
    				fgets(Answer4, sizeof(Answer4), stdin);

        			Answer4[strcspn(Answer4, "\n")] = '\0';

        			if (strcmp(Answer4, "Yes")==0 || strcmp(Answer4, "Yes")==0)
    				{
    					RentACar(carLISTinfo, carCTGinfo, carDETAILinfo, Days, CompareCar);  //RECURSION
    				}
    				else if(strcmp(Answer4, "No")==0 || strcmp(Answer4, "no")==0)
    				{
    				printf("Thankyou For Using Our Services\n");
    				exit(0);
    				}
   		 }
    }

    else if(strcmp(Answer1, "No") == 0 || strcmp(Answer1, "no") == 0)
    {
    		printf("Are You Sure You Want To Go With The Same Car?\n");
    		fgets(Answer5, sizeof(Answer5), stdin);

		 Answer5[strcspn(Answer5, "\n")] = '\0';

		if (strcmp(Answer5, "Yes")==0 || strcmp(Answer5, "yes")==0)
       		{
    			UserDetails();
    			Car_Issue(Days, CarName);
    		}
    		else
		{
			printf("Thank You Dear User For Using Our Services.\n");
			exit(0);
		}
    }
    //call availibility function //if available, then congrats your car is available (then ask do you want to confirm? if yes? then car selected, if no then function recalled), if no, then call function again,
}

int Availability(char CarName[50])
{
    int AvaCheck;
    srand(time(NULL));
    AvaCheck=rand()%2;

	if(AvaCheck==1)
	{ return 1; }
	else{ return 0; }
}

void Compare(char CompareCar[50], char carLISTinfo[24][3][20], char carCTGinfo[4][1][20], char CarName[50], char carDETAILinfo[24][4][50], int ChosenCategory)
{

    printf("%s\n", carCTGinfo[ChosenCategory][0]);

    for (int i = 0; i < 6; i++)
    {
        printf("-%8s- %7s - %4s - \n", carLISTinfo[ChosenCategory * 6 + i][0], carLISTinfo[ChosenCategory * 6 + i][1], carLISTinfo[ChosenCategory * 6 + i][2]);
    }

    printf("Select The Car You Want To Compare With: ");
    fgets(CompareCar, 20, stdin);

    CompareCar[strcspn(CompareCar, "\n")] = '\0'; // Remove the newline character

    for (int i = 0; i < 6; i++)
    {
        if (strcmp(CompareCar, carDETAILinfo[ChosenCategory * 6 + i][0]) == 0)
        {
            printf("\nDetails of Compared Car: %8s \n%12s \n%20s \n%20s \n", carDETAILinfo[ChosenCategory * 6 + i][0], carDETAILinfo[ChosenCategory * 6 + i][1], carDETAILinfo[ChosenCategory * 6 + i][2], carDETAILinfo[ChosenCategory * 6 + i][3]);
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(CarName, carDETAILinfo[ChosenCategory * 6 + i][0]) == 0)
        {
            printf("\nDetails of Selected Car: %8s \n%12s \n%20s \n%20s \n", carDETAILinfo[ChosenCategory * 6 + i][0], carDETAILinfo[ChosenCategory * 6 + i][1], carDETAILinfo[ChosenCategory * 6 + i][2], carDETAILinfo[ChosenCategory * 6 + i][3]);
        }
    }
}

void display(char carLISTinfo[24][3][20], char carCTGinfo[4][1][20])
{
    printf("------------------------------------------------ \n");
    printf("-                 CATEGORIES                      - \n");

    for (int i = 0; i < 4; i++)
    {
        printf("------------------------------------------------------ \n");
        printf("-    %10s-\n", carCTGinfo[i][0]);
        printf("------------------------------------------------ \n");
        printf("-    CAR BRAND   - MODEL - MODEL YEAR - \n");
        printf("------------------------------------------------------ \n");

        for (int j = 0; j < 24; j++)
        {
            if (i == 0) //mini
            {
                if (j < 6)
                {
                    printf("-%8s- %7s - %4s - \n", carLISTinfo[j][0], carLISTinfo[j][1], carLISTinfo[j][2]);
                }
            }
            else if (i == 1) //commercial
            {
                if (j >= 6 && j < 12)
                {
                    printf("-%8s- %7s - %4s - \n", carLISTinfo[j][0], carLISTinfo[j][1], carLISTinfo[j][2]);
                }
            }
            else if (i == 2) //comfort
            {
                if (j >= 12 && j < 18)
                {
                    printf("-%8s- %7s - %4s - \n", carLISTinfo[j][0], carLISTinfo[j][1], carLISTinfo[j][2]);
                }
            }
            else
            {
                if (j >= 18 && j < 24) //luxury
                {
                    printf("-%8s- %7s - %4s - \n", carLISTinfo[j][0], carLISTinfo[j][1], carLISTinfo[j][2]);
                }
            }
        }
    }
}

void UserDetails() {
    char Name[50], CityName[50];
    int IdNum, Age, GuardianNum;
    char PhoneNum[20];

    printf("\nEnter Your Name (as per CNIC): ");
    fgets(Name, sizeof(Name), stdin);
    while (getchar() != '\n');

    printf("\nEnter your ID card number: ");
    scanf("%d", &IdNum);
    while (getchar() != '\n');

    printf("\nEnter your Age: ");
    scanf("%d", &Age);
    while (getchar() != '\n');

    if (Age > 17 || Age < 81)
    {
        printf("\nEnter Phone Number: ");
        fgets(PhoneNum, sizeof(PhoneNum), stdin);
    }
    else
    {
    	printf("\a");
        printf("\nSorry Dear User, You Are Not Eligible To Rent A Car!\n");

        printf("\nPlease Enter Your Guardian's Number.\n");
        scanf("%d",&GuardianNum);
         while (getchar() != '\n');
    }

  /*  printf("\nEnter City Name You Want To Use The Car For: ");
    fgets(CityName, sizeof(CityName), stdin);
    while (getchar() != '\n');
   CityName[strcspn(CityName, "\n")] = 0; //removes newline character if present

    if (strcmp(CityName, "Lahore") == 0 || strcmp(CityName, "lahore") == 0 || strcmp(CityName, "LAHORE") == 0)
    {
        printf("Dear Customer! Our Services For \"Lahore\" Are Available\n");
    }
    else if (strcmp(CityName, "Islamabad") == 0 || strcmp(CityName, "islamabad") == 0 || strcmp(CityName, "ISLAMABAD") == 0 || strcmp(CityName, "isb") == 0 || strcmp(CityName, "Isb") == 0)
    {
        printf("Dear Customer! Our Services For \"Islamabad\" CityName Are Available\n");
    }
    else if (strcmp(CityName, "Peshawar") == 0 || strcmp(CityName, "PESHAWAR") == 0 || strcmp(CityName, "peshawar") == 0) {
        printf("Dear Customer! Our Services For \"Peshawar\" Are Available\n");
    }
    else if (strcmp(CityName, "Taxila") == 0 || strcmp(CityName, "TAXILA") == 0 || strcmp(CityName, "taxila") == 0) {
        printf("Dear Customer! Our Services For \"Taxila\" Are Available\n");
    }
    else if (strcmp(CityName, "Rawalpindi") == 0 || strcmp(CityName, "RAWALPINDI") == 0 || strcmp(CityName, "rawalpindi") == 0 || strcmp(CityName, "pindi") == 0 || strcmp(CityName, "PINDI") == 0) {
        printf("Dear Customer! Our Services For \"Rawalpindi\" Are Available\n");
    }
    else if (strcmp(CityName, "Attock") == 0 || strcmp(CityName, "attock") == 0 || strcmp(CityName, "ATTOCK") == 0) {
        printf("Dear Customer! Our Services For \"Attock\" Are Available\n");
    }

    else
    {
        printf("Dear Customer! This CityName Is Out Of Our Geofencing Scope Of Services.\n");
        printf("Please Choose The CityName In Our Geofencing:\n");
        printf("\tIslamabad\n\tPeshawar\n\tLahore\n\tTaxila\n\tAttock\n\tRawalpindi\n");

        UserDetails();
    }*/
}
