// 8to16
#include<stdio.h>

int main (void)
{
	int codepoint, a1,a2,a3,a4,b,b1,b2, first,second,third,forth;
	
	
	/////////////////////////////////////////
	////diadikasia eureshs tou codepoint////
	////////////////////////////////////////
	
	
	while(	(  first  = getchar() ) != EOF )			// diavazw 1o byte
	{
					
		if((first>= 0x0000) && (first <=0x007F))		//an briskomai sto diasthma [0x0000,0x007F]
		{												//tote exw kwdikopoihsh me 1 byte
			codepoint = first;
		}
		else if( (first >> 4) == 0x000C)				//alliws an ta 4 prwta psifia einai ta 1100
		{												//tote exw kwdikopoihsh me 2 bytes
			second  = getchar();						//diavazw to 2o byte
	
			a1 = (first & 0x001F);						//apomononw ta 5 teleutaia bits tou 1ou byte		
			a2 = (second & 0x003F);						//apomononw ta 6 teleutaia bits tou 2ou byte
											
			a1 = (a1 << 6);								//sunthetw sto a1 ta 5+6 = 11 bits			
			a1 = (a1 | a2);								//gia na ftiaxw ton codepoint twn 2 bytes
			codepoint  = a1;		
								
		}else if((first >> 4) == 0x000E)				//alliws an ta 4 prwta psifia einai ta 1110
		{												//tote exw kwdikopoihsh me 3 bytes
			second = getchar();							//diavazw 2o byte
			third = getchar();							//diavazw 3o byte
	
			a1 = (first & 0x000F);						//apomononw ta 4 teleutaia bits tou 1ou byte
			a2 = (second & 0x003F);						//apomononw ta 6 teleutaia bits tou 2ou byte
			a3 = (third & 0x003F);						//apomononw ta 6 teleutaia bits tou 3ou byte
	
			a1 = (a1 << 6);								//sunthetw ta 4+6+6=16 bits
			a1 = (a1 | a2);								//gia na ftiaxw ton codepoint twn 3 byte
			a1 = (a1 << 6);
			a1 = (a1 |a3);
			codepoint = a1;
		
	
		}else if ((first >> 4) == 0x000F)				//alliws an ta 4 prwta psifia einai ta 1111
		{												//tote exw kwdikopoihsh me 4 bytes
			second = getchar();							//diavazw 2o byte
			third = getchar();							//diavazw 3o byte
			forth = getchar();							//diavazw 4o byte
	
			a1 = (first & 0x0007);						//apomononw ta 3 teleutaia bits tou 1ou byte
			a2 = (second & 0x003F);						//apomononw ta 6 teleutaia bits tou 2ou byte
			a3 = (third & 0x003F);						//apomononw ta 6 teleutaia bits tou 3ou byte
			a4 = (forth & 0x003F);						//apomononw ta 6 teleutaia bits tou 4ou byte
		
			a1 = (a1 << 6);								//idia diadikasia gia na sunthesw ta 3+6+6+6 = 21 bits
			a1 = (a1 | a2);								//kai na ftiaxw ton codepoint twn 4 bytes
			a1 = (a1 << 6);
			a1 = (a1 |a3);
			a1 = (a1 << 6);
			a1 = (a1 | a4);
			codepoint = a1;
		
		}
	
	
	
		////////////////////////////////////////////
		////diadikasia metatrophs tou codepoint////
		///////////////////////////////////////////
		
		if((codepoint>= 0x0000 && codepoint <=0xD7FF) || ((codepoint>= 0xE000) && (codepoint <= 0xFFFF))) //an exw kwdikopoihsh me 2 bytes
		{
			first = codepoint >> 8; 									//ta 8 prwta bits tou codepoint
			second = (0x00FF & codepoint); 								//ta 8 teleutaia bits tou codepoint
			putchar(first);
			putchar(second); 
		}else if ((codepoint >= 0x010000) && (codepoint <= 0x10FFFF)) 	//an exw kwdikopoihsh me 4 bytes
		{ 
			b = (codepoint - 0x010000);									// b = arithmos twn 20 bits
			b1 = b >> 10;												//b1 = ta 10 prwta bits tou b				
			b2= 0x03FF &  b;											//b2 = ta 10 teleutaia bits tou b
	
			b1 = b1 + 0xD800;											//o b1 twra einai o a1 ths ekfwnhshs
			b2 = b2 + 0xDC00;											//o b2 twra einai o a2 ths ekfwnhshs
	
			first = (b1 >> 8);
			second = b1 & 0x00FF;
			third = b2 >> 8;
			forth  = b2 & 0x00FF;
	
			putchar(first);
			putchar(second); 
			putchar(third); 
			putchar(forth); 
		}
		
	}
	return 0;
}
