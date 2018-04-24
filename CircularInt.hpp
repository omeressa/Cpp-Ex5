
#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class CircularInt{
   // private:


    public:
        int max;
        int min;
        int current;
        CircularInt();
        CircularInt(int, int);
        CircularInt(int,int,int);
        ~CircularInt();
        
       // int keepInRange(int  , int  , int  );

/*==========Add==========*/
        friend const CircularInt operator + (int, CircularInt const &);
        friend const CircularInt operator + (CircularInt const &, int);
        friend const CircularInt operator + (CircularInt const &, CircularInt const &);
        CircularInt& operator ++ ();
        const CircularInt operator ++ (int);
        CircularInt& operator += (CircularInt const &);
        CircularInt& operator+=(int num);
        
/*==========Sub==========*/
        friend const CircularInt  operator - (int, CircularInt const &);
        friend const CircularInt  operator - (CircularInt const &,int);
        friend const CircularInt  operator - (CircularInt const &,CircularInt const &);
        CircularInt& operator-();
        CircularInt& operator -- ();
        const CircularInt operator -- (int);
        CircularInt& operator -= (CircularInt const &);
        CircularInt& operator -= (int);
        
/*==========Mult==========*/
        friend const CircularInt  operator * (int, CircularInt const &);
        friend const CircularInt  operator * (CircularInt const &,int);
        friend const CircularInt  operator * (CircularInt const &, CircularInt const &);
        CircularInt& operator *= (CircularInt const &);
        CircularInt& operator *= (int);
        
/*==========Div==========*/
        friend const CircularInt  operator / (int, CircularInt const &);
        friend const CircularInt  operator / (CircularInt const &, int);
        friend const CircularInt  operator / (CircularInt const &, CircularInt const &);
        CircularInt& operator /= (CircularInt const &);
        CircularInt& operator /= (int);

/*==========Comp==========*/
        CircularInt& operator = (CircularInt const &);
        friend bool operator == (CircularInt const &, int const);
        friend bool operator == (int const, CircularInt const &);
        friend bool operator == (CircularInt const &, CircularInt const &);
        friend bool operator != (CircularInt const &, int const);
        friend bool operator != (int const, CircularInt const &);
        friend bool operator != (CircularInt const &, CircularInt const &);
        
        friend bool operator >= (CircularInt const &, int const);
        friend bool operator >= (int const, CircularInt const &);
        friend bool operator >= (CircularInt const &, CircularInt const &);

        friend bool operator <= (CircularInt const &, int const);
        friend bool operator <= (int const, CircularInt const &);
        friend bool operator <= (CircularInt const &, CircularInt const &);

        friend bool operator < (CircularInt const &, int const);
        friend bool operator < (int const, CircularInt const &);
        friend bool operator < (CircularInt const &, CircularInt const &);

        friend bool operator > (CircularInt const &, int const);
        friend bool operator > (int const, CircularInt const &);
        friend bool operator > (CircularInt const &, CircularInt const &);


/*==========Stream==========*/
        friend std::ostream & operator<<(std::ostream& os,const CircularInt& ci);
        friend std::istream &operator>>(std::istream& is, CircularInt& ci);
    
/*==========Modulo==========*/
        int modulo(int min, int max, int current, int num);// helping function for modulo
        friend const CircularInt operator%(const CircularInt& , const int& );
        friend const CircularInt operator%(const int& , const CircularInt& );
        friend const CircularInt operator%(const CircularInt& , const CircularInt& );
        
/*==========logic==========*/
        friend const CircularInt operator^(CircularInt&,int);
        friend const CircularInt operator^(int,CircularInt&);
        friend const CircularInt operator^(CircularInt&,CircularInt&);

        CircularInt& operator|=(const int);
        CircularInt& operator|=(const CircularInt&);

        CircularInt& operator&=(const int);
        CircularInt& operator&=(const CircularInt&);



};


        

        
        
        
        
        
        
        
        
        
        
        
        
        
        

