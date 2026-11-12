#include <stdio.h>
#include <string.h>

int main()
{
   int choice=0;
   char seats[5][4];
   char name[50];
   int age,row,seat;

   char names[20][50];
   int ages[20];
   int rows[20];
   int seats_no[20];
   int passenger_count=0;
   for(int i=0;i<5;i++)
   {
       for(int j=0;j<4;j++)
       {
           seats[i][j]='O';
       }
   }
   while(choice!=7)
    {
    printf("\n=====================================\n");
    printf("     RAILWAY RESERVATION SYSTEM\n");
    printf("=====================================\n");
    printf("1. Display Seat Availability\n");
    printf("2. Book a Ticket\n");
    printf("3. Cancel a Ticket\n");
    printf("4. Search Passenger\n");
    printf("5. Display Reservation Details\n");
    printf("6. Display Available Seats\n");
    printf("7. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Display Seat Availability\n");
            printf(" 1 2 3 4\n");
            for(int i=0;i<5;i++)
              {
                 printf("%d ",i+1);
                 for(int j=0;j<4;j++)
              {
                 printf("%c ",seats[i][j]);
            }
                  printf("\n");
             }
            break;

        case 2:
            printf("Book a Ticket\n");
            printf("\npassenger name:");
            scanf("%s",name);
            printf("Age:");
            scanf("%d",&age);
            printf("row number:");
            scanf("%d",&row);
            printf("seat number:");
            scanf("%d",&seat);
            if(row<1 || row>5)
            {
                printf("invalid row number\n");
            }
            else if(seat<1 || seat>4)
            {
                printf("invalid seat number\n");
            }
            else if(seats[row - 1][seat - 1] == 'X')
           {
                printf("Sorry! This seat is already booked.\n");
           }
           else
           {
                seats[row - 1][seat - 1] = 'X';
                strcpy(names[passenger_count], name);
                ages[passenger_count] = age;
                rows[passenger_count] = row;
                seats_no[passenger_count] = seat;

                passenger_count++;

                printf("\n===============================\n");
                printf("       TICKET BOOKED\n");
                printf("===============================\n");
                printf("Passenger : %s\n", name);
                printf("Age       : %d\n", age);
                printf("Seat      : %d-%d\n", row, seat);
                printf("Booking successful!\n");
           }
            break;

        case 3:
            printf("Cancel a Ticket\n");

            printf("enter row number:");
            scanf("%d",&row);

            printf("enter seat number:");
            scanf("%d",&seat);

            if(row < 1 || row > 5)
            {
                printf("Invalid row number\n");
            }
            else if(seat < 1 || seat > 4)
            {
                printf("Invalid seat number\n");
            }
            else if(seats[row - 1][seat - 1] == 'O')
            {
                printf("No booking found for this seat.\n");
            }
            else
            {
                seats[row - 1][seat - 1] = 'O';

                for(int i=0; i<passenger_count; i++)
                {
                   if(rows[i] == row && seats_no[i] == seat)
                   {
                       names[i][0] = '\0';
                       ages[i] = 0;
                       rows[i] = 0;
                       seats_no[i] = 0;
                       break;
                   }
                }

                printf("Ticket cancelled successfully.\n");
            }
            break;

        case 4:
            printf("Search Passenger\n");

            printf("\nenter passenger name:");
            scanf("%s",name);
            int found=0;
            for(int i=0; i<passenger_count; i++)
             {
                if(strcmp(names[i],name)==0)
                 {
                      found=1;
                      printf("=====================\n");
                      printf("   PASSENGER FOUND\n");
                      printf("=====================\n");
                      printf("\nNAME :%s\n",names[i]);
                      printf("AGE  :%d\n",ages[i]);
                      printf("SEAT :%d-%d\n",rows[i],seats_no[i]);
                 }
             }
             if(found==0)
             {
                 printf("passenger not found");
             }
            break;

        case 5:
            printf("Display Reservation Details\n");

              printf("========================================\n");
              printf("          RESERVATION DETAILS\n");
              printf("========================================\n");

            printf("Passenger        Age       Seat\n");
            printf("----------------------------------------\n");

            for(int i=0; i<passenger_count; i++)
            {
                if(rows[i] != 0)
                {
                    printf("%s\t\t%d\t\t%d-%d\n",
                    names[i], ages[i], rows[i], seats_no[i]);
                }
            }

            break;

        case 6:
            printf("Display Available Seats\n");

            int count=0;
             printf("AVAILABLE SEATS\n");

             for(int i=0;i<5;i++)
             {
                 for(int j=0;j<4;j++)
                 {
                     if(seats[i][j]=='O')
                     {
                         count++;
                     }
                 }
             }
             printf("Total available seats:%d\n",count);

             for(int i=0;i<5;i++)
             {
                 for(int j=0;j<4;j++)
                 {
                     if(seats[i][j]=='O')
                     {
                         printf("%d-%d   ",i+1,j+1);
                     }
                 }
                 printf("\n");
             }
            break;

        case 7:
            printf("Exit\n");
            break;

        default:
            printf("Invalid choice\n");
    }
}
    return 0;
}
