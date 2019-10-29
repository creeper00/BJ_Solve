//---------------------------------------------------------------
//
//  4190.308 Computer Architecture (Fall 2019)
//
//  Project #2: Half-precision Floating Points
//
//  October 1, 2019
//
//  Jin-Soo Kim (jinsoo.kim@snu.ac.kr)
//  Systems Software & Architecture Laboratory
//  Dept. of Computer Science and Engineering
//  Seoul National University
//
//---------------------------------------------------------------

#include <stdio.h>
#include "pa2.h"
typedef union {
  float ff;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;

// Convert 32-bit signed integer to 16-bit half-precision floating point
hfp int2hfp (int n)
{
    if(n==0) return 0;
    if(n>65519) return 31<<10;
    else if(n<(-65519)) return (31<<10)+32768;

    int num=0,ans=0,neg=0;
    if(n<0)
    {
        neg=1<<15;
        n=-n;
    }
    int temp=n,save=n;

    while(temp>1)
    {
        temp=temp/2;
        num++;
    }
    n=n-(1<<num);
    if(n!=0)
    {
        if(num>10) n=n>>(num-10);
        else n=n<<(10-num);
    }
    int check = save- ( ( (n+(1<<10))*(1<<num) )>>10 );
    if(num>10)
    {
        if(check > 1<<(num-11) )
        {
            n=n+1;
        }
        else if ( check == (1<<(num-11)) && (n&1)==1 )
        {
            n=n+1;
        }
    }
    num=num+15;
    return ans=(num<<10)+n+neg;

}


// Convert 16-bit half-precision floating point to 32-bit signed integer
int hfp2int (hfp h)
{
    int neg=0;
    if(h>=(1<<15))
    {
        neg=1;
        h=h-(1<<15);
    }
    int a=h>>10;
    if( a>= 31) return 0x80000000;
    else if( a<15 ) return 0;
    h=h-(a<<10);
    a=a-15;
    int ans = ( (h+(1<<10))*(1<<a) ) >>10;
    if(neg==1) ans=-ans;
    return ans;
}


// Convert 32-bit single-precision floating point to
// 16-bit half-precision floating point
hfp float2hfp (float f)
{
    float_cast d1 = { .ff = f };
    int fs = d1.parts.sign;
    int fe = d1.parts.exponent;
    int fm = d1.parts.mantisa;
    if(f>65519) return 31<<10; // over
    else if(f<(-65519)) return(31<<10)+(1<<15); //under
    else if(f<65519 && f>(-65519)) // in range
    {
        if(fs==1) fs=(1<<15);
        fe=fe-127+15;
        if(fe<1)//denormalize && normalize(when rounded)
        {
            if(f<0) f=-f;
            float check=0,save=f*(1<<14);
            int adder=0,num=-14;
            check = f-( ( (float)((int)(save*1024))/1024 ) / (1<<(-num)) ) - ( 1/ ((1<<(-num))*2048.0) );
            if( check>0 ) adder++;
            else if( !check && ((int)(save*(1<<10))&1)==1 ) adder++;
            if(save>=1) save--;
            else num--;
            return fs+((num+15)<<10)+(int)(save*(1<<10))+adder;
        }
        if( (fm%(1<<13)) > (1<<12)) fm= (fm>>13)+1;
        else if( (fm%(1<<13))==(1<<12) && ((fm>>13)&1)==1 ) fm=(fm>>13)+1;
        else fm=fm>>13;

        return fs+(fe<<10)+fm;
    }
    else if(fs==0) return (31<<10)+12; // NaN (+)
    else return (31<<10)+1+(1<<15); // NaN (-)
}


// Convert 16-bit half-precision floating point to
// 32-bit single-precision floating point
float hfp2float (hfp h)
{
    if( ((1<<15)+(31*(1<<10)))==h ) return 1.0/-0.0;
    else if(h==(31*(1<<10))) return 1.0/0.0;
    else if( (h>(31*(1<<10)) && h<(1<<15))) return -(0.0/0.0);
    else if(((1<<15)+(31*(1<<10)))<h ) return (0.0/0.0);
    int neg=0;
    float a = 0;
    if(h>=(1<<15))
    {
        neg=1;
        h=h-(1<<15);
    }
    int num=(h>>10);
    h=h-(num<<10);
    num=num-15;
    for(int i=10; i>0; i--)
    {
        if( (h&1)==1 ) a+=1.0/(1<<i);
        h=h>>1;
    }
    if(num>=0) a=(a+1)*(1<<num);
    else
    {
        num=-num;
        if(num!=15) a++;
        if(num==15) num--;
        num=1<<num;
        a=a*(1.0/num);
    }
    if(neg==1) a=-a;
	return a;
}


