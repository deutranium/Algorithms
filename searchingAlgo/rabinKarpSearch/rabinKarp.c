#include<stdio.h>
#include<string.h>
 

int rabinKarp(char txt[], char pat[], int q) 
{ 
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
    int d = 256;
	int p=0,t=0,h=1;
	
	for(int i=0;i<pat_len-1;i++)
	    h = (h*d)%q;
	
	for(int i=0;i<pat_len;i++)
	{
	    p = (d*p + pat[i])%q;
	    t = (d*t + txt[i])%q;
	}
	for(int i=0;i<=txt_len-pat_len;i++)
	{
	    if(p == t)
	    {
	        int j;
	        for(j=0;j<pat_len;j++)
	        {
	            if(txt[i+j] != pat[j])
	                break;
	        }
	        if(j == pat_len)
	            return i;
	    }
	    if(i < txt_len-pat_len)
	    {
	        t = ((t - txt[i]*h)*d + txt[pat_len+i])%q;
	        if(t < 0)
	            t = t + q;
	    }
	}
	return -1;
} 

int main()
{
    char text[] = "AABBACHADA";
    char pat[] = "BBAC";
    int index =  rabinKarp(text,pat,101);
    if(index != -1)
        printf("Pattern found at: %d\n", index+1);
    else
        printf("Pattern not found\n");
    
}
