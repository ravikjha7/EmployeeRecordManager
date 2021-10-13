/*
    Hello Everyone, My Name Is Ravi Jha and I have made This Project as My 1st Semester Project
    This Project is Openly Available To Everyone On GitHUb : ravikjha7
    So If you want to use it or Contribute to it , You are Open For it....
    Thanks For Giving Us Your Valuable Time Thank You!!!
*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string.h>

void print();
void load();
void gotoxy(int x, int y);
void setPassword();
void menu();
void add();
void check();
void update();
void delete();
void about();
void myexit();
struct Employee;
int validEmail(char email[]);

int main()
{
    print(); // To Print The Intro Stuff
    return 0;
}

void print()
{   
    int i=0;
    start:
    system("cls");
    gotoxy(70,7);
    printf("WELCOME TO THE REVOLUTION\n");
    gotoxy(74,10);
    printf("USER LOGIN PORTAL\n");
    gotoxy(7,12);
    printf("Enter Password To Unlock:    ");
    char password[20],checkpassword[20];
    scanf("%[^\n]%*c",password);
    gotoxy(7,14);
    FILE *fp;
    fp = fopen("Password.txt","r");
    fscanf(fp,"%s",checkpassword);
    fclose(fp);
    if(strcmp(password,checkpassword)==0) //Comparing Password
    {   
        printf("PassWord Matched SuccessFully!!!\n");
        load();
    }
    else
    {
        printf("Invalid Password !! Please Try Again %c\n",2);
        if(i<2)
        {
            i++;
            gotoxy(7,16);
            printf("You Have %d Chances Left!!!!",3-i);
            getch();
            goto start;
        }
        else
        {   
            gotoxy(7,16);
            printf("Sorry You Have Entered Wrong Password 3 Times....");
            gotoxy(7,18);
            printf("Please Read The Readme File!!!");
            getch();
            exit(1);
        }
    }
}
void load() //For Loading Screen
{
    int row,col,r,c,q;
    gotoxy(78,17);
    printf("Loading...");
    gotoxy(72,18);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //To Print The Character Slowly
        printf("%c",177);
    }
    printf("\n");
    gotoxy(52,20);
    printf("Loading Completed SuccessFully. Press Any Key To Continue");
    getch(); 
    menu();
}

//Menu Card
void menu() 
{
    system("cls");
    gotoxy(15,7); // To Move The Cursor To Desired Location
    printf("MENU SECTION\n");
    gotoxy(15,10);
    printf("1. Add New Employee's Data\n");
    gotoxy(15,12);
    printf("2. Check Employee's Data\n");
    gotoxy(15,14);
    printf("3. Update Existing Employee's Data\n");
    gotoxy(15,16);
    printf("4. Delete Employee's Data\n");
    gotoxy(15,18);
    printf("5. Update Password");
    gotoxy(15,20);
    printf("6. About The Company\n");
    gotoxy(15,22);
    printf("7. Exit");
    gotoxy(15,24);
    fflush(stdin);
    printf("Choose Your Option : ");
    int choice;
    char temp;
    fflush(stdin); 
    // To Clear The Buffer
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 :
            add();
            break;
        case 2:
            check();
            break;
        case 3:
            update();
            break;
        case 4:
            delete();
            break;
        case 5:
            setPassword();
            break;
        case 6:
            about();
            break;
        case 7:
            myexit();
            break;
        default:
            gotoxy(15,27);
            printf("Invalid Option!!!\n");
            gotoxy(55,29);
            printf("Press Any Key to Continue , Press 0 to Exit ");
            temp = getch();
            if(temp!='0')
            {
                menu();
            }
            else
            {
                myexit();
            }
    }
}

// Structure To Manage Employee's Details
struct Employee
{
    char name[20],dob[11],join[11],address[100],salary[20],contact[15],email[20],eno[10];
};

void add()
{   
    struct Employee e;
    // To Clear The System For Opening The Menu
    system("cls");
    gotoxy(7,7);
    printf("Enter Employee's Details:\n\n");
    gotoxy(7,9);
    printf("Name : ");
    fflush(stdin); 
    scanf("%[^\n]%*c",&e.name);
    gotoxy(7,11);
    printf("Enter Employee No. : ");
    scanf("%[^\n]%*c",&e.eno);
    gotoxy(7,13);
    printf("Contact No. : ");
    fflush(stdin);
    scanf("%[^\n]%*c",&e.contact);
    gotoxy(7,15);
    printf("E-mail Id : ");
    scanf("%[^\n]%*c",&e.email);
    gotoxy(7,17);
    printf("Date Of Birth (MM-DD-YYYY) : ");
    scanf("%[^\n]%*c",&e.dob);
    gotoxy(7,19);
    printf("Joining Date : ");
    scanf("%[^\n]%*c",&e.join);
    gotoxy(7,21);
    printf("Address : ");
    scanf("%[^\n]%*c",&e.address);
    gotoxy(7,23);
    printf("Salary : ");
    scanf("%[^\n]%*c",&e.salary);
    gotoxy(64,26);
    printf("Data Added Successfully....\n");
    gotoxy(50,28);
    FILE *fp;
    int i=0;
    char filename[20];
    // The Name Entered By The User will be Ravi Jha Suppose so we need to add .txt to end of it
    while(e.name[i]!='\0')
    {
        filename[i]=e.name[i];
        i++;
    }
    filename[i]='.';
    filename[i+1]='t';
    filename[i+2]='x';
    filename[i+3]='t';
    filename[i+4]='\0';
    fp = fopen(filename,"w");
    time_t t;
    // For Getting The Current Date and Time
    time(&t);
    fprintf(fp,"Employee's Details:\n\nName : %s\n\n",e.name);
    fprintf(fp,"Employee No. : %s\n\n",e.eno);
    fflush(stdout);
    fprintf(fp,"Conact No. : %s\n\n",e.contact);
    fflush(stdout);
    fprintf(fp,"E-mail Id : %s\n\n",e.email);
    fflush(stdout);
    fprintf(fp,"Date Of Birth : %s\n\n",e.dob);
    fflush(stdout);
    fprintf(fp,"Joining Date : %s\n\n",e.join);
    fflush(stdout);
    fprintf(fp,"Address : %s\n\n",e.address);
    fflush(stdout);
    fprintf(fp,"Salary : %s\n\n",e.salary);
    fflush(stdout);
    fprintf(fp,"Data Stored On : %s\n\n",ctime(&t));
    fflush(stdout);
    fclose(fp);
    printf("Press Any Key To Return To Main Menu , Press 0 for Exit ");
    char temp = getch();
    if(temp=='0')
    {
        myexit();
    }
    else
    {
        menu();
    }
}

void check()
{   
    char name[20];
    fflush(stdin);
    system("cls");
    gotoxy(0,6);
    printf("Name Of The Employee : ");
    scanf("%[^\n]%*c",name);
    FILE *fp;
    int i=0;
    char temp;
    char filename[20];
    while(name[i]!='\0')
    {
        filename[i]=name[i];
        i++;
    }
    // The Filename should be name.txt so adding .txt to end of name
    filename[i]='.';
    filename[i+1]='t';
    filename[i+2]='x';
    filename[i+3]='t';
    filename[i+4]='\0';
    //Opening The File
    fp = fopen(filename,"r");
    // fp==NULL means there is no file with current Employee Name 
    if(fp==NULL){
    gotoxy(0,8);
    printf("No Existing Employee Found With Name %s\n",name);
    gotoxy(55,11);
    printf("Press Any Key To Return To Main Menu , Press 0 for Exit ");
    temp = getch();
    if(temp=='0')
    {
        myexit();
    }
    else
    {
        menu();
    }
    }
    else
    {
        char ch;
        gotoxy(0,8);
        //To Print The Details
        while((ch=fgetc(fp))!=EOF) 
        {
            printf("%c",ch);
        }
    }
    fclose(fp);
    gotoxy(55,29);
    printf("Press Any Key To Return To Main Menu , Press 0 for Exit ");
    temp = getch();
    if(temp=='0')
    {
        myexit();
    }
    else
    {
        menu();
    }
}

//To Update The Details Of The Current Employee
void update()
{
    system("cls");
    gotoxy(12,6);
    printf("The Old Data cannot be restored!!!!\n");
    gotoxy(12,8);
    printf("Still Want to Continue?? Press Any Key To Continue , Press 0 For Main Menu ");
    int choice;
    char name[20];
    char temp;
    temp = getch();
    if(temp=='0')
    {
        menu();
    }
    else
    {
    fflush(stdin);
    gotoxy(12,10);
    printf("Enter Employee Name: ");
    scanf("%[^\n]%*c",name);
    FILE *fp;
    int i=0;
    char filename[20];
    while(name[i]!='\0')
    {
        filename[i]=name[i];
        i++;
    }
    filename[i]='.';
    filename[i+1]='t';
    filename[i+2]='x';
    filename[i+3]='t';
    filename[i+4]='\0';
    fp = fopen(filename,"r");
    if(fp==NULL)
    {
    gotoxy(12,12);
    printf("No Existing Employee Found With Name %s\n",name);
    gotoxy(55,14);
    printf("Press Any Key To Return To Main Menu , Press 0 for Exit ");
    temp = getch();
    if(temp=='0')
    {
        myexit();
    }
    else
    {
        menu();
    }
    }
    else
    {
        gotoxy(12,12);
        printf("What You Want to Update??");
        gotoxy(12,13);
        printf("1.Name");
        gotoxy(12,14);
        printf("2.Employee ID");
        gotoxy(12,15);
        printf("3.Contact No");
        gotoxy(12,16);
        printf("4.Email-ID ");
        gotoxy(12,17);
        printf("5.Date Of Birth ");
        gotoxy(12,18);
        printf("6.Joining Date ");
        gotoxy(12,19);
        printf("7.Address");
        gotoxy(12,20);
        printf("8.Salary");
        gotoxy(12,21);
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        FILE *fp1;
        // To Store The Data Temporarily in the Copy File
        fp1=fopen("Copy.txt","w");
        int count=0,count2=0;
        char ch;
        int temp2=1;
        time_t t;
        time(&t);
        fflush(stdin);
        // CLearing The Input Buffer
        switch(choice)
        {
        case 1:
              gotoxy(12,23);
              printf("Enter New Name : ");
              scanf("%[^\n]%*c",name);
              // To Change The Desired Line i.e to Update Particular Information
              while((ch=fgetc(fp))!=EOF)
	          {	
		        if(ch=='\n')
		        temp2++;
                /* I am putting every line from the existing file to a copy file except
                 the line which needs to be changed */
		        if(temp2!=3&&temp2!=21)
		        {
			        fputc(ch,fp1);
		        }
                // That Line Is Added To The Fle By Here
		        else if(count==0)
                {
                fputc(ch,fp1);
			    fprintf(fp1,"Name : %s",name);
			    count++;
		        }
                // This Is Just For Editing The Last Update Date and Time
                if(temp2==21&&count2==0)
                {
                    fprintf(fp1,"\nLast Updated on : %s", ctime(&t));
                    count2++;
                }
		      }
            
	        fclose(fp);
	        fclose(fp1);
            // Now Removing The Original File
	        remove(filename);
            int i=0;
            /* Now Changing The Name of filename as You Have Changed The Name Of The Employee
            So While Accessing The Employee Details You Need to Enter New name of the Employee
            */
            while(name[i]!='\0')
            {
                filename[i]=name[i];
                i++;
            }
            filename[i]='.';
            filename[i+1]='t';
            filename[i+2]='x';
            filename[i+3]='t';
            filename[i+4]='\0';
            // Now Simply Changing The name of copy.txt to Employee's Name File
	        rename("Copy.txt",filename);
            gotoxy(12,25);
            printf("Employee's Name Updated !!!");
            gotoxy(55,27);
            printf("Press Any Key to Continue , Press 0 to Exit ");
            temp = getch();
            if(temp!='0')
            {
                menu();
            }
            else
            {
                myexit();
            }
            break;
        
        case 2:
            gotoxy(12,23);
            printf("Enter New Employee ID : ");
            scanf("%[^\n]%*c",name);
            while((ch=fgetc(fp))!=EOF)
	        {	
		    if(ch=='\n')
		    temp2++;
		    if(temp2!=5&&temp2!=21)
		    {
			    fputc(ch,fp1);
		    }
		    else if(count==0)
            {
            fputc(ch,fp1);
			fprintf(fp1,"Employee No. : %s",name);
			count++;
		    }
            if(temp2==21&&count2==0)
            {
                fprintf(fp1,"\nLast Updated on : %s", ctime(&t));
                count2++;
            }
		    }
	        fclose(fp);
	        fclose(fp1);
	        remove(filename);
            rename("Copy.txt",filename);
            gotoxy(12,25);
            printf("Employee's ID Updated !!!");
            gotoxy(55,27);
            printf("Press Any Key to Continue , Press 0 to Exit ");
            temp = getch();
            if(temp!='0')
            {
                menu();
            }
            else
            {
                myexit();
            }
            break;
        case 3:
            gotoxy(12,23);
            printf("Enter New Contact No. : ");
            scanf("%[^\n]%*c",name);
            while((ch=fgetc(fp))!=EOF)
	        {	
		    if(ch=='\n')
		    temp2++;
		    if(temp2!=7&&temp2!=21)
		    {
			    fputc(ch,fp1);
		    }
		    else if(count==0)
            {
            fputc(ch,fp1);
			fprintf(fp1,"Conact No. : %s",name);
			count++;
		    }
            if(temp2==21&&count2==0)
            {
                fprintf(fp1,"\nLast Updated on : %s", ctime(&t));
                count2++;
            }
		    }
	        fclose(fp);
	        fclose(fp1);
	        remove(filename);
            rename("Copy.txt",filename);
            gotoxy(12,25);
            printf("Employee's Contact Number Updated !!!");
            gotoxy(55,27);
            printf("Press Any Key to Continue , Press 0 to Exit ");
            temp = getch();
            if(temp!='0')
            {
                menu();
            }
            else
            {
                myexit();
            }
            break;
        case 4:
            gotoxy(12,23);
            printf("Enter New Email-ID : ");
            scanf("%[^\n]%*c",name);
            while((ch=fgetc(fp))!=EOF)
	        {	
		    if(ch=='\n')
		    temp2++;
		    if(temp2!=9&&temp2!=21)
		    {
			    fputc(ch,fp1);
		    }
		    else if(count==0)
            {
            fputc(ch,fp1);
			fprintf(fp1,"E-mail ID : %s",name);
			count++;
		    }
            if(temp2==21&&count2==0)
            {
                fprintf(fp1,"\nLast Updated on : %s", ctime(&t));
                count2++;
            }
		    }
	        fclose(fp);
	        fclose(fp1);
	        remove(filename);
            rename("Copy.txt",filename);
            gotoxy(12,25);
            printf("Employee's Email-ID Updated !!!");
            gotoxy(55,27);
            printf("Press Any Key to Continue , Press 0 to Exit ");
            temp = getch();
            if(temp!='0')
            {
                menu();
            }
            else
            {
                myexit();
            }
            break;
        case 5:
            gotoxy(12,23);
            printf("Enter New Date Of Birth : ");
            scanf("%[^\n]%*c",name);
            while((ch=fgetc(fp))!=EOF)
	        {	
		    if(ch=='\n')
		    temp2++;
		    if(temp2!=11&&temp2!=21)
		    {
			    fputc(ch,fp1);
		    }
		    else if(count==0)
            {
            fputc(ch,fp1);
			fprintf(fp1,"Date Of Birth : %s",name);
			count++;
		    }
            if(temp2==21&&count2==0)
            {
                fprintf(fp1,"\nLast Updated on : %s", ctime(&t));
                count2++;
            }
		    }
	        fclose(fp);
	        fclose(fp1);
	        remove(filename);
            rename("Copy.txt",filename);
            gotoxy(12,25);
            printf("Employee's DOB Updated !!!");
            gotoxy(55,27);
            printf("Press Any Key to Continue , Press 0 to Exit ");
            temp = getch();
            if(temp!='0')
            {
                menu();
            }
            else
            {
                myexit();
            }
            break;
        case 6:
            gotoxy(12,23);
            printf("Enter New Joining Date : ");
            scanf("%[^\n]%*c",name);
            while((ch=fgetc(fp))!=EOF)
	        {	
		    if(ch=='\n')
		    temp2++;
		    if(temp2!=13&&temp2!=21)
		    {
			    fputc(ch,fp1);
		    }
		    else if(count==0)
            {
            fputc(ch,fp1);
			fprintf(fp1,"Joining Date : %s",name);
			count++;
		    }
            if(temp2==21&&count2==0)
            {
                fprintf(fp1,"\nLast Updated on : %s", ctime(&t));
                count2++;
            }
		    }
	        fclose(fp);
	        fclose(fp1);
	        remove(filename);
            rename("Copy.txt",filename);
            gotoxy(12,25);
            printf("Employee's Joining Date Updated !!!");
            gotoxy(55,27);
            printf("Press Any Key to Continue , Press 0 to Exit ");
            temp = getch();
            if(temp!='0')
            {
                menu();
            }
            else
            {
                myexit();
            }
            break;
        case 7:
            gotoxy(12,23);
            printf("Enter New Address : ");
            scanf("%[^\n]%*c",name);
            while((ch=fgetc(fp))!=EOF)
	        {	
		    if(ch=='\n')
		    temp2++;
		    if(temp2!=15&&temp2!=21)
		    {
			    fputc(ch,fp1);
		    }
		    else if(count==0)
            {
            fputc(ch,fp1);
			fprintf(fp1,"Address : %s",name);
			count++;
		    }
            if(temp2==21&&count2==0)
            {
                fprintf(fp1,"\nLast Updated on : %s", ctime(&t));
                count2++;
            }
		    }
	        fclose(fp);
	        fclose(fp1);
	        remove(filename);
            rename("Copy.txt",filename);
            gotoxy(12,25);
            printf("Employee's Address Updated !!!");
            gotoxy(55,27);
            printf("Press Any Key to Continue , Press 0 to Exit ");
            temp = getch();
            if(temp!='0')
            {
                menu();
            }
            else
            {
                myexit();
            }
            break;
        case 8:
            gotoxy(12,23);
            printf("Enter New Salary : ");
            scanf("%[^\n]%*c",name);
            while((ch=fgetc(fp))!=EOF)
	        {	
		    if(ch=='\n')
		    temp2++;
		    if(temp2!=17&&temp2!=21)
		    {
			    fputc(ch,fp1);
		    }
		    else if(count==0)
            {
            fputc(ch,fp1);
			fprintf(fp1,"Salary : %s",name);
			count++;
		    }
            if(temp2==21&&count2==0)
            {
                fprintf(fp1,"\nLast Updated on : %s", ctime(&t));
                count2++;
            }
		    }
	        fclose(fp);
	        fclose(fp1);
	        remove(filename);
            rename("Copy.txt",filename);
            gotoxy(12,25);
            printf("Employee's Salary Updated !!!");
            gotoxy(55,27);
            printf("Press ANy Key to Continue , Press 0 to Exit ");
            temp = getch();
            if(temp!='0')
            {
                menu();
            }
            else
            {
                myexit();
            }
            break;
        default:
        // If User Entered Any Other Option Other Than The Given One
            gotoxy(12,23);
            printf("Invalid Option!!!\n");
            gotoxy(55,26);
            printf("Press Any Key to Continue , Press 0 to Exit ");
            temp = getch();
            if(temp!='0')
            {
                menu();
            }
            else
            {
                myexit();
            }
        }
    }
    }

}

//To Delete The Employee's Data
void delete() 
{   
    system("cls");
    gotoxy(54,6);
    printf("WARNING : Deleted Employee's Data cannot be restored!!!!\n");
    gotoxy(12,9);
    printf("Still Want to Continue?? Press Any Key To Continue , Press 0 For Main Menu ");
    char temp = getch();
    if(temp=='0')
    {
        menu();
    }
    else
    {
    char temp,name[20];
    gotoxy(12,11);
    fflush(stdin);
    printf("Enter Employee Name: ");
    scanf("%[^\n]%*c",name);
    FILE *fp;
    int i=0;
    char filename[20];
    while(name[i]!='\0')
    {
        filename[i]=name[i];
        i++;
    }
    filename[i]='.';
    filename[i+1]='t';
    filename[i+2]='x';
    filename[i+3]='t';
    filename[i+4]='\0';
    // Opening The File Just To Check whether Employee with the given name exists or not
    fp = fopen(filename,"r");
    if(fp==NULL)
    {
    gotoxy(12,13);
    printf("No Existing Employee Found With Name %s\n",name);
    gotoxy(55,15);
    printf("Press Any Key To Return To Main Menu , Press 0 for Exit ");
    temp = getch();
    if(temp=='0')
    {
        myexit();
    }
    else
    {
        menu();
    }
    }
    else
    {   
        // If Yes , Just Closing The File
        fclose(fp);
        gotoxy(54,13);
        printf("Are You Sure ??? You Want to Delete %s's Data",name);
        gotoxy(54,15);
        printf("Press Any Key to Continue , Press 0 For Main Menu ");
        temp = getch();
        if(temp=='0')
        {
            menu();
        }
        else
        {
        remove(filename);
        gotoxy(12,17);
        printf("All Data Of %s Deleted!!!",name);
        gotoxy(47,19);
        printf("We wish %s a Very Good Luck And Hope To Have a Great Future %c",name,3);
        // Just Giving Him/Her Good wishes 
        gotoxy(12,22);
        printf("Press Any Key To Return To Main Menu , Press 0 for Exit ");
        temp = getch();
        if(temp=='0')
        {
            myexit();
        }
        else
        {
           menu();
        }
        }
    }
    }
}

void gotoxy(int x, int y) // To Move The Cursor To The Desired Place
{
HANDLE Screen;
Screen = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Position={x, y};
SetConsoleCursorPosition(Screen, Position);
}

// To Set The New Password
void setPassword()
{   
    // If User Enters Wrong Password Then To Bring Her/Him Again Here
    set:
    system("cls");
    gotoxy(7,12);
    printf("Enter Old Password : ");
    char check[20],check2[20];
    fflush(stdin);
    scanf("%s", check);
    FILE *fp = fopen("Password.txt","r");
    //Accsessing The Old Password
    fscanf(fp,"%s",check2);
    fclose(fp);
    fflush(stdin);
    //Comparing Old Password with Entered Password
    if(strcmp(check,check2)==0)
    {   
        gotoxy(7,14);
        fp = fopen("Password.txt","w");
        printf("Enter New Password: ");
        scanf("%[^\n]%*c", &check);
        // To Save The New Password To The File "Password.txt"
        fputs(check,fp);
        gotoxy(7,16);
        printf("PassWord Updated SuccessFully %c %c",2,2);
        fclose(fp);
        gotoxy(55,18);
        printf("Press Any Key to Continue , Press 0 to Exit ");
        char temp = getch();
        if(temp!='0')
        {
            menu();
        }
        else
        {
            myexit();
        }
    }
    else
    {
        gotoxy(7,14);
        printf("Invalid Password !!!");
        gotoxy(55,16);
        printf("Press Any Key to Continue , Press 0 For Main Menu ");
        char temp = getch();
        if(temp!='0')
        {   
            // Use To Move To The Place Where Password Is Asked
            goto set;
        }
        else
        {
            menu();
        }
    }
}

// About The Company!!
void about()
{
    system("cls");
    gotoxy(7,12);
    printf("You , Ya You , Who is Reading this About , Thanks For Checking the About Section");
    gotoxy(7,14);
    printf("Press Any Key To Continue");
    getch();
    // Just to add A feel of Really Reading Something
    gotoxy(7,16);
    printf("We at 'THE REVOLUTION' works for the Welfare Of The Society %c ",3);
    getch();
    gotoxy(7,18);
    printf("We want The Entire Society To be Educated");
    getch();
    gotoxy(7,20);
    printf("If You Want to Contribute To Us You Can Find Us on GitHub : ravikjha7 ");
    // I am also On LinkedIn with the Same ID : ravikjha7
    getch();
    gotoxy(7,22);
    printf("A Very Thanks For Reading This About !! Thank You %c",2);
    gotoxy(7,25);
    printf("Press Any Key For Main Menu , Press 0 to exit ");
    char temp = getch();
    if(temp!='0')
    {
        menu();
    }
    else
    {
        myexit();
    }
}

// To Show The Details Before Exiting
void myexit()
{
    system("cls");
    gotoxy(7,12);
    printf("Are You Sure You Want To Exit Press Any Key To Exit , Press 0 For Main Menu ");
    char temp = getch();
    if(temp==0)
    {
        menu();
    }
    else
    {
        gotoxy(7,15);
        printf("Thanks For Using The Program !!");
        gotoxy(7,17);
        printf("Follow us on GitHub : ravikjha7 ");
        gotoxy(55,20);
        printf("Thank You!!!! %c %c %c ",2,3,2);
        getch();
        system("cls");
        exit(1);

    }
	// int validEmail(char email[])
	// {
		
	// 	for(int i=0;i<)
	// }
}
