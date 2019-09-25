//---------------------------------------------------------------
//
//  4190.308 Computer Architecture (Fall 2019)
//
//  Project #1: 64-bit Integer Arithmetic using 32-bit Operations
//
//  September 9, 2019
//
//  Jin-Soo Kim (jinsoo.kim@snu.ac.kr)
//  Systems Software & Architecture Laboratory
//  Dept. of Computer Science and Engineering
//  Seoul National University
//
//---------------------------------------------------------------

#include <stdio.h>
#include "pa1.h"


// NOTE!!!!!
// You should use only 32-bit integer operations inside Uadd64(), Usub64(),
// Umul64(), and Udiv64() functions.


// Uadd64() implements the addition of two 64-bit unsigned integers.
// Assume that A and B are the 64-bit unsigned integer represented by
// a and b, respectively. Uadd64() should return x, where x.hi and x.lo
// contain the upper and lower 32 bits of (A + B), respectively.

HL64 Uadd64 (HL64 a, HL64 b)
{
	HL64 	x;

    if( a.lo > (a.lo+b.lo) || b.lo > (a.lo+b.lo) )
    {
        x.lo = a.lo+b.lo;
        x.hi = a.hi+b.hi+1;
    }
    else
    {
        x.lo = a.lo+b.lo;
        x.hi = a.hi+b.hi;
    }



	return x;
}

// Usub64() implements the subtraction between two 64-bit unsigned integers.
// Assume that A and B are the 64-bit unsigned integer represented by
// a and b, respectively. Usub64() should return x, where x.hi and x.lo
// contain the upper and lower 32 bits of (A - B), respectively.


HL64 Usub64 (HL64 a, HL64 b)
{
	HL64 	x;
    if(b.lo>a.lo)
    {
        x.lo = 4294967295-b.lo+1+a.lo;
        a.hi--;
    }
    else x.lo = a.lo-b.lo;
    if(b.hi>a.hi)
    {
        x.hi = 4294967295-b.hi+1+a.hi;
    }
    else x.hi = a.hi-b.hi;




	return x;
}


// Umul64() implements the multiplication of two 64-bit unsigned integers.
// Assume that A and B are the 64-bit unsigned integer represented by
// a and b, respectively.  Umul64() should return x, where x.hi and x.lo
// contain the upper and lower 32 bits of (A * B), respectively.

HL64 Umul64 (HL64 a, HL64 b)
{
	HL64 	x;
    x.lo = a.lo*b.lo;
    x.hi = ((a.hi*4294967296+a.lo)*(b.hi*4294967296+b.lo))>>96;
	return x;
}


// Udiv64() implements the division of two 64-bit unsigned integers.
// Assume that A and B are the 64-bit unsigned integer represented by
// a and b, respectively.  Udiv64() should return x, where x.hi and x.lo
// contain the upper and lower 32 bits of the quotient of (A / B),
// respectively.

HL64 Udiv64 (HL64 a, HL64 b)
{
	HL64 	x;
    if( (b.hi==0 && b.lo==0) || (b.hi>a.hi) || (b.hi==a.hi && b.lo>a.lo))
    {
        x.hi=0;
        x.lo=0;
    }
    else if(a.hi==0 && b.hi==0)
    {
        x.hi=0;
        x.lo=a.lo/b.lo;
    }
    else if(b.hi==0)
    {
        unsigned int u1=a.hi, ans=0, ans2=0, j=31;
        while(u1>>=1)
        {
            j++;
        }
        j++;
        HL64 temp;
        temp.hi=0,temp.lo=0;
        for(int i=j; i>=0; i--)
        {
            if( temp.lo >= 2147483648 ) temp.hi = temp.hi+temp.hi+1;
            else temp.hi = temp.hi+temp.hi;
            temp.lo=temp.lo+temp.lo;
            unsigned int u2=a.hi;
            if(i<32) u2=a.lo;
            u2>>=i;
            if( (u2&1)==1 )
            {
                temp.lo++;
                if(temp.lo==0) temp.hi++;
            }
            if(temp.hi>b.hi || (temp.hi==b.hi && temp.lo>=b.lo))
            {
                if(temp.lo<b.lo)
                {
                    temp.lo=temp.lo+(1<<31)-b.lo+(1<<31);
                    temp.hi--;
                }
                else temp.lo = temp.lo-b.lo;
                temp.hi=temp.hi-b.hi;
                if(i>=32)
                {
                    ans2+=(1<<(i-32));
                }
                else
                {
                    ans+=(1<<i);
                }
            }
        }
            x.hi=ans2;
            x.lo=ans;
    }
    else
    {
        unsigned int u1=a.hi, ans=0;
        HL64 temp;
        temp.hi=0,temp.lo=a.hi;
        for(int i=31; i>=0; i--)
        {
            if( temp.lo > (temp.lo+temp.lo) ) temp.hi = temp.hi+temp.hi+1;
            else temp.hi = temp.hi+temp.hi;
            temp.lo=temp.lo+temp.lo;
            unsigned int u2=a.lo;
            u2>>=i;
            if( (u2&1)==1 )
            {
                temp.lo++;
                if(temp.lo==0) temp.hi++;
            }
            if(temp.hi>b.hi || (temp.hi==b.hi && temp.lo>=b.lo))
            {
                if(temp.lo<b.lo)
                {
                    temp.lo=temp.lo+(1<<31)-b.lo+(1<<31);
                    temp.hi--;
                }
                else temp.lo = temp.lo-b.lo;
                temp.hi=temp.hi-b.hi;
                ans+=(1<<i);
            }
        }
        x.hi=0;
        x.lo=ans;
    }
	return x;
}


