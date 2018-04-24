
 #include <iostream>
 using namespace std;

 #include "CircularInt.hpp"
 
    /**testing all operators of Add**/
 void test1(){
     cout<<"Testing the adding operator on CircularInt hour0 : "<<endl;
     CircularInt hour0 {1, 12}; 
     cout << hour0 << endl;                     // 1
     hour0= hour0 +1; cout << hour0 << endl;     // obj +num =2
     hour0= 5 + hour0; cout << hour0 << endl;   //  num +obj =7
     hour0= hour0 +hour0;cout << hour0 << endl; //   obj +obj =2
     ++hour0;cout << hour0 << endl;          //    ++obj =3
     hour0++;cout << hour0 << endl;         //     obj++ =4
     hour0+=3;cout << hour0 << endl;       //      obj +=num  =7 
     hour0+=hour0;cout << hour0 << endl;   //       obj +=obj  =2
 }
 
    /**testing all operators of Sub**/
 void test2(){
     cout<<"Testing the Sub operator on CircularInt hour1 : "<<endl;
     CircularInt hour1 {1, 12}; 
     cout << hour1 << endl;                       // 1
     hour1= hour1 -1; cout << hour1 << endl;     // obj -num =12
     hour1= 5 - hour1; cout << hour1 << endl;   //  num -obj =5
     hour1= hour1 -hour1;cout << hour1 << endl;//   obj -obj =12
     --hour1;cout << hour1 << endl;           //    --obj =11
     hour1--;cout << hour1 << endl;          //     obj-- =10
     hour1-=3;cout << hour1 << endl;        //      obj -=num  =7 
     hour1-=hour1;cout << hour1 << endl;   //       obj -=obj  =12
 }

    /**testing all operators of Mult**/
 void test3(){
    cout<<"Testing the Mult operator on CircularInt hour2 : "<<endl;
    CircularInt hour2 {1, 12};
    cout << hour2 << endl;                           // 1
    hour2= hour2 *2;cout << hour2 << endl;          // obj *num =2
    hour2= 4 *hour2;cout << hour2 << endl;         //  num *obj =8
    hour2= hour2 *hour2;cout << hour2 << endl;    //   obj *obj =4
    hour2*=2;cout << hour2 << endl;              //    obj*=num  =8 
    hour2*=hour2;cout << hour2 << endl;         //     obj*=obj  =4

 }
 
     /**testing all operators of Div**/
 void test4(){
    cout<<"Testing the Div operator on CircularInt hour3 : "<<endl;
    CircularInt hour3 {1, 12};
    hour3=hour3+5;
    cout << hour3 << endl;                                 // 6
    try{                                                  // 
      hour3= hour3 /2;cout << hour3 << endl;             //  obj/ num =3
}                                                       
catch (const string& message) {                        
 		cout << message << endl;                           
	}
    try{                                                  // 
      hour3= 1 /hour3 ;cout << hour3 << endl;            //  num/ obj =none
}                                                       
catch (const string& message) {                        
 		cout << message << endl;                           
	}
	    try{                                                  // 
      hour3= hour3 /hour3;cout << hour3 << endl;           //  obj/ obj =1
}                                                       
catch (const string& message) {                        
 		cout << message << endl;                           
	}
	    try{                                                  // 
      hour3= hour3 /=12;cout << hour3 << endl;             //  obj/=num =none
}                                                       
catch (const string& message) {                        
 		cout << message << endl;                           
	}
		    try{                                                  // 
      hour3= hour3 /=hour3;cout << hour3 << endl;            //  obj/=obj =1
}                                                       
catch (const string& message) {                        
 		cout << message << endl;                           
	}

 }
 
    /**testing all operators of Comp**/
 void test5(){
     cout<<"Testing the Comp operator on CircularInt hour4 : "<<endl;
     cout<<"(1 = True, 0 = False)"<<endl;
     CircularInt hour4 {1, 12};
     hour4=hour4+5;cout << hour4 << endl;              // hour4 = 6 
     cout << (hour4 == 5) << endl;                    // obj==num? false = 0 
     cout << (6 == hour4) << endl;                   //  num==obj? true = 1 
     cout << (hour4 == hour4) << endl;              //   obj==obj? true = 1 
     cout << (hour4 != 5) << endl;                 //    obj!=num? true = 1 
     cout << (6!= hour4) << endl;                 //     num!=obj? false = 0
     cout << (hour4 != hour4) << endl;           //      obj!=obj? false = 0 
     cout << (hour4 >= 5) << endl;                    // obj>=num? true = 1
     cout << (2 >= hour4) << endl;                   //  num>=obj? false = 0 
     cout << (hour4 >= hour4) << endl;              //   obj>=obj? true = 1 
     cout << (hour4 <= 5) << endl;                 //    obj<=num? false = 0 
     cout << (12 <= hour4) << endl;               //     num<=obj? false = 0 
     cout << (hour4 <= hour4) << endl;           //      obj<=obj? true = 1 
     cout << (hour4 > 5) << endl;                     // obj>num?  true = 1  
     cout << (10 > hour4) << endl;                   //  num>obj?  true = 1 
     cout << (hour4 > hour4) << endl;               //   obj>obj?  false = 0
     cout << (hour4 < 5) << endl;                  //    obj<num?  false = 0  
     cout << (5 < hour4) << endl;                 //     num<obj?  true = 1 
     cout << (hour4 < hour4) << endl;            //      obj<obj?  false = 0 
 }
 
 /**testing the Modulo operator**/
 void test6(){
    cout<<"Testing the modulo operator on CircularInt hour5 : "<<endl;
    CircularInt hour5 {1, 12};
    hour5=hour5+9;cout<<hour5<<endl;
   // hour5= hour5 % 0;cout<<hour5<<endl;
    try{                                                  // 
      hour5= hour5 %3 ;cout << hour5 << endl;            //  obj%num =1
}                                                       
catch (const string& message) {                        
 		cout << message << endl;                           
	}
	hour5 =hour5 +9;
	  try{                                                  // 
      hour5= 12 %hour5 ;cout << hour5 << endl;            //  num%obj =2
}                                                       
catch (const string& message) {                        
 		cout << message << endl;                           
	}
	cout<<"as we can see the answer to 2%2 should be 0 but since we r moduling according to hour 0 turns into a 12!!!"<<endl;
	    		    try{                                                  // 
      hour5= hour5 %hour5 ;cout << hour5 << endl;            //  obj%obj =12
}                                                       
catch (const string& message) {                        
 		cout << message << endl;                           
	}


   
 }

 int main() {
 	CircularInt hour {1, 12};                 // <hour is an integer between 1 and 12, like an hour on the clock>
 	cout << hour << endl;                     // 1
 	hour += 4;  cout << hour << endl;         // 5
 	(hour += 2)++;  cout << hour << endl;     // 8
 	hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
 	cout << -hour << endl;                    // 10  (2 hours before midnight)
 	hour = 1 - hour; cout << hour << endl;    // 11  (2 hours before 1)
 	cout << hour+hour << endl;                // 10 (11 hours after 11)
 	hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
 	cout << hour/2 << endl;                   // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).

 	try {
 		cout << hour/3;
	} catch (const string& message) {
 		cout << message << endl;     // "There is no number x in {1,12} such that x*3=10"
	}

 	// RIDDLES (not for submission):
 	//  * when is there exactly one answer to a/b?
 	//  * when are there two or more answers to a/b?
 	//	* when is there no answer to a/b? test1();

 test1();
 test2();
 test3();
 test4();
 test5();
 test6();
 }





