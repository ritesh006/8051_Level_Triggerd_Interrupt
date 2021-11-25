/*---------------------------------------------------------- 
	Here we are going to program a level triger interrupts 
	
------------------------------------------------------------*/


# include<reg51.h>				/* header file for registers addresses */

void ms_Delay(unsigned int);			/* delay function prototyping */

sbit sq_wave=P1^3;				/* rename port 1.3 as a square wave for square wave generation */

sbit Led = P1^4;							/* rename port 1.4 as led for external led configure */

sbit Switch = P3^2;           /* rename port 3.2 as switch for external switch configuration */



/* ---------------- interrupts subroutine function starts here --------------------*/
void ENT_LED() interrupt 0 

/* define interrupt function of subroutine interrupt. interrupt 0 is only number for showing 
	 difference between normal function and interrupt subroutine */
{
	Led = ~Led;     /* this is for making compliment of led if initially led 1 it will goes 0 or vice versa */
	
	ms_Delay(500);	/* adding some delay */
}

/* ---------------- interrupts subroutine functione ends here --------------------*/




void ms_Delay(unsigned int time)  /* define delay function */
{
	
	unsigned int i,j;
	
	for(i=0; i < time; i++)
	for(j=0; j < 113; j++);
	
}



/*-------------void main start-----------------------------------*/
void main ()
{
	Switch = 1; 							/* switch set 1 for making port 3.2 as a input */
	
	Led = 0; 									/* led port 1.4 set to 0 for initially led will off */
	
	IT0 = 0;									/* setting ITO equal to 0 we are using this hardware for level triggerd
															 if ITO = 1 it will be configure for edge trigger */
	
	IE = 0x81;                /* enable interrupt INT0 External interrupt zero */
	
	
	/*------------ While loop starts --------------------------------*/
	
	while(1)
	{
		/* square wave generation code starts */
		
		sq_wave = 1; 									/* setting port 1.3 to high */

		ms_Delay(500);						/* adding some delay */
	
		sq_wave = 0; 									/* setting port 1.3 to low */
	
		ms_Delay(500);						/* adding some delay */
	
		/* square wave generation code ends here */
	}
		
	/*------------ While loop Ends --------------*/
	
	
}
/*-------------void main ends here-----------------------------------*/

