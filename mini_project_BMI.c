#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//mini project " Health Advisory based of BMI "

struct details
{
	char name[20];
	char gen[2];
	int age;
	float weight;
	float height;
}d1;

float bmi;

void input ();
void bmi_chart();
float calculate();
void category(float);
void analyse(float );
void risk_factor(float ,float );

int main()
{
	int ch;

	printf("\n\t\t***** WELCOME TO HEALTH ADVISORY BASED ON BMI *****\n");

	printf("\nEnter the following Details:\n\n");
    input();
    printf("\n\n=============================================================================\n\n");
	printf("\nPress any key to continue....!\n");
	getch();


	do
	{
	system ("cls");
	printf("\n\t\t***** HEALTH ADVISORY BASED ON BMI *****\n");
	printf("\nEnter your choice:\n");
	printf("\n1.Display of general BMI chart");
	printf("\n2.Calclutation of BMI");
	printf("\n3.Analysis of BMI");
	printf("\n4.Exit\n\n\t");
	scanf("%d",&ch);
	printf("\n\n=============================================================================\n\n");

	switch(ch)
    {
	case 1:
		printf("\n\t\t\tBMI CHART");
		bmi_chart();
		printf("\n\n=============================================================================\n\n");
		printf("\nPress any key to continue....!\n");
		getch();
		break;

	case 2:
		printf("\n\t\t\tCalculation of BMI\n ");
		bmi = calculate();
		printf("\nBMI = %.2f",bmi);
		category(bmi);
		printf("\n\n=============================================================================\n\n");
		printf("\nPress any key to continue....!\n");
		getch();
		break;

	case 3:
	    printf("\n\t\t\tAnalysis of BMI\n");
	    bmi = (d1.weight/(d1.height*d1.height)*10000);
	    analyse(bmi);
	    printf("\n\n=============================================================================\n\n");
	    printf("\nPress any key to continue....!\n");
		getch();
	    break;

	case 4:
		printf("\n\n\t\t\tThank You for using the application...!\n\n");
		printf("\n\n=============================================================================\n\n");
		break;

	default:
	    printf("\nInvalid choice,Choose again...!\n");
	    printf("\n\n=============================================================================\n\n");
	    printf("\nPress ENTER to choose again ....!\n");
		getch();
	}

}while(ch!=4);

	return 0;
}

void input()
{
	printf("Name : ");
	scanf("%[^\n]",d1.name);
	printf("\nAge : ");
	scanf("%d",&d1.age);
	printf(" \nGender - (M) Male \t (F) Female : ");
	scanf("%s",d1.gen);
    printf("\nWeight in Kg : ");
	scanf("%f",&d1.weight);
	printf("\nHeight in cm : ");
	scanf("%f",&d1.height);
}

void bmi_chart()
{
	printf("\n\n\t CATEGORY \t\t\t BMI RANGE kg/m^2\n\n");
	printf("\t Underweight\t\t\t Below 18.5\n");
	printf("\t Normal\t\t\t\t 18.5-24.9\n");
	printf("\t Overweight\t\t\t 25-29.9\n");
	printf("\t Obesity Class I\t\t 30-34.9\n");
	printf("\t Obesity Class II\t\t 35-39.9\n");
	printf("\t Obesity Class III\t\t Above 40\n");
}

float calculate()
{
	float index;
	puts(d1.name);
	printf("\n\nWeigth in kg : %.2f",d1.weight);
	printf("\nHeight in Cm : %.2f",d1.height);
	index = (d1.weight/(d1.height*d1.height)*10000);
	return index;
}

void category(float b)
{
	if(b<18.5)
	{
		printf("\nYou are underweight\n");
	}
	else if(b>=18.5&&b<=24.9)
	{
		printf("\nYour BMI is Normal\n");
	}
	else if(b>24.9&&b<=29.9)
	{
		printf("\nYou are Overweight\n");
	}
	else if(b>29.9&&b<=34.9)
	{
		printf("\nYour BMI is under the category Obesity Class I\n");
	}
	else if(b>34.9&&b<40)
	{
		printf("\nYour BMI is under the category Obesity Class II\n");
	}
	else
	{
		printf("\nYour BMI is under the category Obesity Class III\n");
	}
}

void analyse (float bi)
{
	puts(d1.name);
	printf("\n\nWeigth in kg : %.2f",d1.weight);
	printf("\nHeight in Cm : %.2f",d1.height);
    static float lower,upper;
    lower=(18.5*(d1.height*d1.height))/10000;
    upper=(24.9*(d1.height*d1.height))/10000;
    printf("\nYour Body Mass Index (BMI) is %.2f",bi);
    printf("\nYour ideal weight range based on your BMI is between %.2f kg and %.2f kg ",lower,upper);
    risk_factor(lower,upper);
}

void risk_factor(float low,float up)
{
    if (bmi<18.5)
    {
        printf("\nYour BMI indicates that your are 'UNDERWEIGHT' for your height.");
        printf("\nTo have a normal BMI you have to gain %.2f kg of weight.",low-d1.weight);
        printf("\nYou can gain weight by including energy dense food, which are rich in calories and less in volume like raisins,nuts,fruits,etc.");
    }
    else if(bmi>=18.5&&bmi<=24.9)
    {
        printf("\nYour BMI indicates that your weight is 'NORMAL'. Congratulations for maintaining an healthy weight...!");
    }
    else if(bmi>24.9&&bmi<=29.9)
    {
        printf("\nYour BMI indicates that you are 'OWERWEIGHT' and this may Incresaes the risk of type 2 diabetes, Hypertension, coronary heart diseses, stroke, sleep apena etc.");
        printf("\nTo have a normal BMI you have to lose %.2f kg of weight.",d1.weight-up);
    }
    else if(bmi>29.9&&bmi<=34.9)
    {
        printf("\nYour BMI indicates that you are 'OBESE(CLASS I) ' and this puts you at High Risk of type 2 diabetes, Hypertension, coronary heart diseses, stroke, sleep apena etc.");
        printf("\nTo have a normal BMI you have to lose %.2f kg of weight.",d1.weight-up);
    }
    else if(bmi>34.9&&bmi<40)
    {
        printf("\nYour BMI indicates that you are 'OBESE(CLASS II) ' and this puts you at Very High Risk of type 2 diabetes, Hypertension, coronary heart diseses, stroke, sleep apena etc.");
        printf("\nTo have a normal BMI you have to lose %.2f kg of weight.",d1.weight-up);
    }
    else
    {
        printf("\nYour BMI indicates that you are 'OBESE(CLASS III) ' and this puts you at Extremely High Risk of type 2 diabetes, Hypertension, coronary heart diseses, stroke, sleep apena etc.");
        printf("\nTo have a normal BMI you have to lose %.2f kg of weight.",d1.weight-up);
    }
}


