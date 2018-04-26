/**created by Omar Essa
* 4/26/2018
*/

#include <iostream>
#include <string>
#include "CircularInt.hpp"
using namespace std;

//Constructors
    CircularInt::CircularInt(){
		max = 12;
		min = 1;
		current = 1;
	}
	
	CircularInt::CircularInt(int min, int max){
		this->max = max;
		this->min = min;
		current = min;
}

CircularInt::CircularInt(int min, int max,int current){
    this->max = max;
    this->min = min;
    this->current = current;
}

	CircularInt::~CircularInt(){}

	
	/**keepInRange is a helping function that keeps the current time in range 
	 * between min and max
	 */
  int keepInRange(int min, int max, int current){
	while(current > max){
		current = current - (max - min + 1);
	}
	while(current < min){
		current = current + (max - min + 1);
	}
	return current;
}

/*====================Equal====================*/


CircularInt& CircularInt::operator = (CircularInt const & obj){
	if(this->max != obj.max || this->min != obj.min)
		throw " ranges are different one from the other !";
	else{
	this->max = obj.max;
	this->min = obj.min;
	this->current = obj.current;
	}
	return *this;
}

CircularInt& CircularInt::operator = (int num){
        this->current = keepInRange(this->min,this->max,num);
	return *this;
}

/*====================Add====================*/

/** since "other" is const we cant change the current in it so we need to make a temp CircularInt 
 * and make changes on it instead.
 */
 
const CircularInt operator + (int num, CircularInt const & other){
	int answer = other.current + num;
	answer = keepInRange(other.min,other.max,answer);
	CircularInt temp(other.min,other.max,answer);
	return temp;
}

/**in this operator we simply use the operator CircularInt operator:
 *    + (int num, CircularInt const & other) that we wrote up 
*/

const CircularInt operator + (CircularInt const & other, int num){
	return num + other ;
}

/** using operators between objects , first we need to check if both objects got the same ranges
 * if not then we throw a messege error! 
 */
 
const CircularInt operator + (CircularInt const & a, CircularInt const & b){
  if (a.min!=b.min || a.max!=b.max)
     throw std::invalid_argument( "different ranges error!! \n" );
     else{
  int answer = a.current+b.current;
  answer = keepInRange(a.min, a.max, answer);
  CircularInt temp(a.min, a.max, answer);
  return temp;
     }
     }

/** here we add ++a directly */

CircularInt& CircularInt::operator++ (){
  current = current + 1 ;
  if (current > max )
  current = min;
  
	return *this;
}

/** here first we make a copy and then add +1 to the copy,
 *  we dont make changes on a himself
 */
 
 const CircularInt CircularInt::operator++(int x) {
		CircularInt temp(*this);
	++(*this);
	return temp;
}

CircularInt& CircularInt::operator+=(const CircularInt& other){
  if (other.min!= min || other.max!= max)
      throw std::invalid_argument( "different ranges error!! \n" );
  else{
  		current += other.current;
		current = keepInRange(min,max,current);
		return *this;
  }
}

CircularInt& CircularInt::operator+=(int num) {
	if(num < 0)//+(-x) = -x
		current -= abs(num);
	else{
		current += num;
		current = keepInRange(min,max,current);
	}
	return *this;
}


/*====================Sub====================*/

/** operator - is the same as operator + , we only change + to - */

const CircularInt operator - (int num, CircularInt const & other){
  CircularInt temp(other);
  int diff = (temp.max-temp.min+1)%other.current;
  if(diff>num)
  diff=num-diff;
  else if(diff<=num)
  diff=num+diff;
  diff=keepInRange(temp.min,temp.max,diff);
  temp.current=diff;

	return temp;
}

const CircularInt operator - (CircularInt const & other, int num){
		int diff = num;
				CircularInt temp(other);
					temp.current+= (-diff)% (other.max - other.min + 1) ;
	if(temp.current > temp.max)
		temp.current -= (temp.max - temp.min + 1);
	if(temp.current < temp.min)
		temp.current += (temp.max - temp.min + 1);
	return temp;;
}

const CircularInt operator - (CircularInt const & a, CircularInt const & b){
  if (a.min!=b.min || a.max!=b.max)
     throw std::invalid_argument( "different ranges error!! \n" );
     else{
  int answer = a.current-b.current;
  answer = keepInRange(a.min, a.max, answer);
  CircularInt temp(a.min, a.max, answer);
  return temp;
     }
}

CircularInt& CircularInt::operator-(){
	current *= -1;
	current = keepInRange(min,max,current);

	return *this;
}

/** here we sub --a directly */

CircularInt& CircularInt::operator--() {
  current = current-1 ;
  if (current < min )
  current = max;
	return *this;
}

/** here first we make a copy and then sub -1 to the copy,
 *  we dont make changes on a himself
 */

const CircularInt CircularInt::operator--(int x) {
	CircularInt temp(*this);
	--(*this);
	return temp;
}

CircularInt& CircularInt::operator-=(const CircularInt& other){
  if (other.min!= min || other.max!= max)
      throw std::invalid_argument( "different ranges error!! \n" );
  else{
  		current -= other.current;
		current = keepInRange(min,max,current);
		return *this;
  }
}

CircularInt& CircularInt::operator -= (int const num){
  current = current - num;
	current = keepInRange(min,max,current);
	return *this;
}

/*====================Mult====================*/


/** to do Mult we use the same code we used at + and - , with a different in sigh * 
*/

const CircularInt  operator * (CircularInt const & other,int num){
	int mult;
	 mult = (other.current) * num;
	mult = keepInRange(other.min,other.max,mult);
	CircularInt temp(other.min,other.max,mult);
	return temp;
}
/** to mult a number with "other" we use the operator we wrote up*/

const CircularInt  operator * (int num, CircularInt const & other){
  return other * num;
}


/** for mult a with b we need to check first if they r in the same range */

const CircularInt  operator * (CircularInt const & a, CircularInt const & b){
  if (a.min!=b.min || a.max!=b.max)
     throw std::invalid_argument( "different ranges error!! \n" );
     else{
  int answer = a.current*b.current;
  answer = keepInRange(a.min, a.max, answer);
  CircularInt temp(a.min, a.max, answer);
  return temp;
     }
}

CircularInt& CircularInt::operator *= (CircularInt const & other){
  if (other.min!= min || other.max!= max)
      throw std::invalid_argument( "different ranges error!! \n" );
  else{
  		current *= other.current;
		current = keepInRange(min,max,current);
		return *this;
  }
}

CircularInt& CircularInt::operator*=(int num) {
	current = current*num;
	current = keepInRange(min,max,current);
	return *this;
}

/*====================Div====================*/


const CircularInt operator / ( CircularInt const & other, int num){
		int temp = (other.current)%num;

	if (temp != 0)
		throw "\"There is no number x in {"+to_string(other.min)+","+to_string(other.max)+"} such that x*"+to_string(num)+"="+to_string(other.current)+"\" ";
	else{
	CircularInt ans(other);
	ans.current /= num;
	return ans;
	}
}

const CircularInt operator / (int num, CircularInt const & other){
	CircularInt temp {other.min, other.max};
	if(other.current <= num && num <= other.max){
		for(int i = other.min; i <= other.max; i++)
			if(num == other.current * i){
				temp.current = i;
				break;
		}
	}
	else
		throw "\"There is no number x in {"+to_string(other.min)+","+to_string(other.max)+"} such that x*"+to_string(num)+"="+to_string(other.current)+"\" ";
	return temp;
}

const CircularInt operator / (CircularInt const & a, CircularInt const & b){
	CircularInt temp {a.min, a.max};
	if(a.min <= b.current && b.current <= a.current){
		for(int i = a.min; i <= a.max; i++)
			if(a.current == b.current * i){
				temp.current = i;
			}
		}
    else
        throw "\"There is no number x in {"+to_string(a.min)+","+to_string(a.max)+"} such that x*"+to_string(a.current)+"="+to_string(b.current)+"\" ";
	return temp;
}

CircularInt& CircularInt::operator /= (CircularInt const & other){
	if(max >= other.current && other.current <= min){
		for(int i = min; i <= max; i++)
			if(current == other.current * i){
				this->current = i;
				break;
		}
	}
	else
		throw "\"There is no number x in {"+to_string(min)+","+to_string(max)+"} such that x*"+to_string(other.current)+"="+to_string(current)+"\" ";
	return *this;
}

CircularInt& CircularInt::operator /= (int const num){
	if(max >= num && num <= min){
		for(int i = min; i <= max; i++)
			if(current == num * i){
				this->current = i;
				break;
		}
	}
	else
		throw "\"There is no number x in {"+to_string(min)+","+to_string(max)+"} such that x*"+to_string(num)+"="+to_string(current)+"\" ";
	return *this;
}

/*====================Compare====================*/



bool operator == (CircularInt const & other, int const num){
    return (other.current == num);
}

bool operator == (int const num, CircularInt const & other){
    return num == other.current;
}

bool operator == (CircularInt const & a, CircularInt const & b){
    return a.current == b.current;
}

bool operator != (CircularInt const & other, int num){
    return !(other.current == num);
}

bool operator != (int num, CircularInt const & other){
    return !(num == other.current);
}

bool operator != (CircularInt const & a, CircularInt const & b){
    return !(a.current == b.current);
}

bool operator >= (CircularInt const & other, int const num){
    return other.current >= num;
}

bool operator >= (int const num, CircularInt const & other){
    return num >= other.current;
}
 bool operator >= (CircularInt const & a, CircularInt const & b){
   return a.current >= b.current;
 }

bool operator <= (CircularInt const & other, int const num){
    return other.current <= num;
}

bool operator <= (int const num, CircularInt const & other){
    return num <= other.current;
}
 bool operator <= (CircularInt const & a, CircularInt const & b){
   return a.current <= b.current;
 }
bool operator < (CircularInt const & other, int const num){
    return other.current < num;
}

bool operator < (int const num, CircularInt const & other){
    return num < other.current;
}
 bool operator < (CircularInt const & a, CircularInt const & b){
   return a.current < b.current;
 }

bool operator > (CircularInt const & other, int const num){
    return other.current > num;
}

bool operator > (int const num, CircularInt const & other){
    return num > other.current;
}
 bool operator > (CircularInt const & a, CircularInt const & b){
   return a.current > b.current;
 }



/*====================Stream====================*/

std::ostream& operator<<(std::ostream & os,const CircularInt &ci){
	return os<<ci.current;
}

std::istream& operator>>(std::istream & is,CircularInt &ci) {
	int ans;
	is>>ans;
	if(ans>ci.max || ans<ci.min)
		throw std::invalid_argument( "value not in range\n" );
	ci.current = ans;
	return is;
}
	
	/*====================Modulo====================*/
	
int CircularInt::modulo(int min, int max, int current, int num){
    current= current%num;
    if(current>=min&&current<=max)return current;
    current=keepInRange(min,max,current);
    return current;
}
	
const CircularInt operator%(const CircularInt& a, const int& num) {
    CircularInt temp{a.min,a.max};
    temp.current=temp.modulo(a.min, a.max, a.current, num);
    return temp;  
}

const CircularInt operator%(const int& num, const CircularInt& a) {
    CircularInt temp{a.min,a.max};
    temp.current=temp.modulo(a.min, a.max, num, a.current);
    return temp;  
}

const CircularInt operator%(const CircularInt& a, const CircularInt& b) {
    CircularInt temp{a.min,a.max};
    temp.current=temp.modulo(a.min, a.max, a.current, b.current);
    return temp;  
}
	
	/*====================logic====================*/
	
	CircularInt& CircularInt::operator|=(const int num){
	current |= num;
	current = keepInRange(min,max,current);
	return *this;
}

CircularInt& CircularInt::operator|=(const CircularInt& other){
	current |= other.current;
	current = keepInRange(min,max,current);
	return *this;
}

CircularInt& CircularInt::operator&=(const int num){
	current &= num;
	current = keepInRange(min,max,current);
	return *this;
}

CircularInt& CircularInt::operator&=(const CircularInt& other){
	current &= other.current;
	current = keepInRange(min,max,current);
	return *this;
}

	
	


























