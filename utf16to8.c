// 16to8
#include<stdio.h>

int main(void)
{
	int a1,a2, b1,b2,b3,b4,codepoint;
	
	//////////////////////////////////////////////////
	///diadikasia eureshs tou codepoint//////////////
	/////////////////////////////////////////////////
	
	while((b1 = getchar()) != EOF )
	{	
		b2= getchar();
	
		a1 = b1 << 8;
		a1 = a1 | b2;
	
		if ((a1>= 0x0000 && a1 <=0xD7FF) || ((a1>= 0xE000) && (a1 <=0xFFFF)))
		{
			codepoint = a1;
		}else
		{
			b3 = getchar();
			b4 = getchar();
	
			a2 = b3 << 8;
			a2 = a2 | b4;
	
			a1 = a1 - 0xD800;
			a2 = a2 - 0xDC00;
	
			a1 = a1 << 10;
			a1 = a1 | a2;
			codepoint = a1 + 0x10000;
	
	
		}
		
	
		/////////////////////////////////////////////////////////////////////////////
		/// diadikasia metatropis tou codepoint apo thn istoselida////////////////////
		/// http://www.herongyang.com/Unicode/UTF-8-UTF-8-Encoding-Algorithm.html/////
		/////////////////////////////////////////////////////////////////////////////
		if (codepoint<0x80) 
		{  
	      	b1 = codepoint >> 0  & 0x7F | 0x00;
	      	putchar(b1);
	 	}else if (codepoint<0x0800)
		{  
	    	b1 = codepoint >> 6  & 0x1F | 0xC0  ;
	      	b2 = codepoint >> 0  & 0x3F | 0x80  ;
	      	putchar(b1);
	      	putchar(b2);
	 	}else if (codepoint < 0x010000)
		{  
	      	b1 = codepoint>>12 & 0x0F | 0xE0 ;
	      	b2 = codepoint>>6  & 0x3F | 0x80 ;
	      	b3 = codepoint>>0  & 0x3F | 0x80 ;
	      	putchar(b1);
	      	putchar(b2);
	      	putchar(b3);
		}else if (codepoint<0x110000)
		{
    	 	b1 = codepoint>>18 & 0x07 | 0xF0 ;
    	  	b2 = codepoint>>12 & 0x3F | 0x80 ;
    	  	b3 = codepoint>>6  & 0x3F | 0x80 ;
    	  	b4 = codepoint>>0  & 0x3F | 0x80 ;
    	  	
    	  	putchar(b1);
	      	putchar(b2);
	      	putchar(b3);
	      	putchar(b4);
 		}
		
    }
		return 0;
}	
