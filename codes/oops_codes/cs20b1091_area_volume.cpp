//NAME   : B.MAHIDHAR REDDY
//ROLL NO: CS20B1091
//PROBLEM: CREATING TWO CLASSES WITH A SINGLE FRIEND FUNCTION
#include<iostream>
#include<iomanip>
using namespace std;

class AREA{
private :
float length,breadth,radius;
public :
AREA(float len=1, float bre=1, float r=1){
length = len; breadth = bre; radius = r;
}
friend inline float rectangle(AREA);
friend inline float circle(AREA);
};

inline float rectangle(AREA a){ return(a.length*a.breadth); }//friend function to calculate area of a rectangle
inline float circle(AREA a){return(3.14*a.radius*a.radius); }//friend function to calculate area of a circle

class VOLUME{
 private :
 float length,breadth,height,radius;
 public :
VOLUME(float len=1, float bre=1, float hei=1, float r=1){
    length = len; breadth = bre;
    height = hei;
    radius = r;
}
 inline void cuboid(VOLUME);
 inline void sphere(VOLUME);
 inline void compare_cuboid(VOLUME,VOLUME);
 inline void compare_sphere(VOLUME,VOLUME);
};

inline void VOLUME::cuboid(VOLUME p){  //function to find the volume of cuboid
    AREA s(p.length,p.breadth,p.radius);
    cout<<"volume of cuboid is : "<<this->height*rectangle(s)<<endl;
}

inline void VOLUME::sphere(VOLUME p){   //function to find the volume of sphere
    AREA s(p.length,p.breadth,p.radius);
    cout<<"volume of sphere : "<<this->radius*circle(s)*4/3<<endl;
}

inline void VOLUME::compare_cuboid(VOLUME p, VOLUME p1){   //function to compare two cuboids volume
    AREA s(p.length,p.breadth,p.radius),s1(p1.length,p1.breadth,p1.radius);
    if(p.height*rectangle(s)<this->height*rectangle(s1)){
        cout<<"2 is greater than 1\n";
    }else if(p.height*rectangle(s)>this->height*rectangle(s1)){
        cout<<"1 is greater than 2\n";
    }else{
        cout<<"both are equal ";
    }
}

inline void VOLUME::compare_sphere(VOLUME p, VOLUME p1){   //function to compare two spheres volume
    AREA s(p.length,p.breadth,p.radius),s1(p1.length,p1.breadth,p1.radius);
    if(p.radius<this->radius){
        cout<<"2 is greater than 1\n";
    }else if(p.radius>this->radius){
        cout<<"1 is greater than 2\n";
    }else{
        cout<<"both are equal";
    }
}



void find_area_of_rectangle(){  //function to enter which type of rectangle unit or values
    int choice,len,bre;
 cout<<"\n1. enter 1 to create a default/unit object \n2. enter 2 to create a specifi values object ";
  cout<<"\nenter choice : ";
           cin>>choice;
               if(choice==1){AREA R1; cout<<rectangle(R1)<<endl; }
               else if(choice==2){  
                     cout<<"enter length and breadth "; cin>>len>>bre;
                 AREA RE1(len,bre); cout<<"area of rectangle : " ; cout<<rectangle(RE1)<<endl;
                }else{
                    cout<<"enter a valid choice \n";
                    }
           
}

void find_the_area_of_circle(){  //function to enter which type of circle unit or values
    int choice,len,bre,hei,r;
cout<<"\n1. enter 1 to create a default/unit object \n2. enter 2 to create a specifi values object ";
 cout<<"\nenter choice : ";
           cin>>choice;
             if(choice==1){AREA R1; cout<<circle(R1)<<endl; }
              else if(choice==2){  
                     cout<<"enter radius : "; cin>>r;
                 AREA RE1(1,1,r); cout<<"area of circle : "; cout<<circle(RE1)<<endl;
                }else{
                    cout<<"enter a valid choice \n";
                    }
}

void find_the_volume_of_cuboid(){  //function to enter which type of cuboid unit or values
    int choice,len,bre,hei,r;
    cout<<"\n1. enter 1 to create a default/unit object \n2. enter 2 to create a specifi values object ";
        cout<<"\nenter choice : ";
           cin>>choice;
               if(choice==1){ VOLUME CU1; CU1.cuboid(CU1); }
               else if(choice==2){
                 cout<<"enter length breadth height "; cin>>len>>bre>>hei;
                 VOLUME CUB1(len,bre,hei); CUB1.cuboid(CUB1);
                 }else{
                    cout<<"enter a valid choice \n";
                    }
}

void find_the_volume_of_sphere(){   //function to enter which type of sphere unit or values
    int choice,len,bre,hei,r;
    cout<<"\n1. enter 1 to create a default/unit object \n2. enter 2 to create a specifi values object ";
     cout<<"\nenter choice : ";
           cin>>choice;
           if(choice==1){ VOLUME CU1; CU1.sphere(CU1); }
               else if(choice==2){
                 cout<<"enter radius : "; cin>>r;
                 VOLUME CUB1(1,1,1,r); CUB1.sphere(CUB1);
                 }else{
                    cout<<"enter a valid choice \n";
                    }
}



void compare_two_cuboids(){  //comparing two cuboids as user needs unit values or given inputs
    int choice,len,bre,hei,r,C,choice1;
cout<<"\n1. enter 1 to create a default/unit first object to compare \n2. enter 2 to create a specifi values of first object to compare";
cout<<"\nenter choice : ";
           cin>>choice;
             if(choice==1){  //creating first one default
                 VOLUME CU2;
                 cout<<"\n1. enter 1 to create a default/unit second object to copmare\n2. enter 2 to create a specifi values of second object to compare  "; 
                  cout<<"\nenter choice : "; cin>>choice1;
             if(choice1==1){ //creating second one default
               VOLUME CU3; CU3.compare_cuboid(CU2,CU3);
                }
              else if(choice1==2){ //creating second one user input
                  cout<<"enter length breadth height "; cin>>len>>bre>>hei; 
                       VOLUME CUB3(len,bre,hei); CUB3.compare_cuboid(CU2,CUB3);
              }else{
                    cout<<"enter a valid choice \n";
                    }
                 }
              else if(choice==2){ //creating first one user input
                  cout<<"enter length breadth height "; cin>>len>>bre>>hei; 
                       VOLUME CUB2(len,bre,hei); C=2;
                 cout<<"\n1. enter 1 to create a default/unit second object to compare \n2. enter 2 to create a specifi values of second object to compare";
                  cout<<"\nenter choice : "; cin>>choice1;
           if(choice1==1){ //creating second user input
               VOLUME CU3; CU3.compare_cuboid(CUB2,CU3);
                }
              else if(choice1==2){   //creating second one user input
                  cout<<"enter length breadth height "; cin>>len>>bre>>hei; 
                       VOLUME CUB3(len,bre,hei);  CUB3.compare_cuboid(CUB2,CUB3);
               }else{
                    cout<<"enter a valid choice \n";
                    }
              }else{
                    cout<<"enter a valid choice \n";
                    }
                 
           
}

void compare_two_spheres(){   //comparing two sphere as user needs unit values or given inputs
    int choice,len,bre,hei,r,C,choice1;
cout<<"\n1. enter 1 to create a default first object to compare \n2. enter 2 to create a specifi values of first object to compare";
 cout<<"\nenter choice : ";  cin>>choice;
             if(choice==1){  //creating first one default
                 VOLUME S2;  ;
                cout<<"\n1. enter 1 to create a default/unit second object to copmare\n2. enter 2 to create a specifi values of second object to compare  "; 
                 cout<<"\nenter choice : "; cin>>choice1;
             if(choice1==1){ //creating second one default
               VOLUME S3; S3.compare_sphere(S2,S3);
                }
              else if(choice1==2){ //creating second one user input
                  cout<<"enter radius : "; cin>>r; 
                       VOLUME SP3(1,1,1,r); SP3.compare_sphere(S2,SP3);
              }else{
                    cout<<"enter a valid choice \n";
                    }
                 }
             else if(choice==2){  //creating first one user input
                  cout<<"enter radius : "; cin>>r; 
                       VOLUME SP2(1,1,1,r); C=2;
        cout<<"\n1. enter 1 to create a default/unit second object to compare \n2. enter 2 to create a specifi values of second object to compare";
            cout<<"\nenter choice : ";  cin>>choice1;
           if(choice1==1){ //creating second user input
               VOLUME S3;  S3.compare_sphere(SP2,S3);
                }
             else if(choice1==2){  //creating second one user input
                  cout<<"enter radius : ";   cin>>r; 
                       VOLUME SP3(1,1,1,r);  SP3.compare_sphere(SP2,SP3);
               }else{
                    cout<<"enter a valid choice \n";
                    }
              }else{
                    cout<<"enter a valid choice \n";
                    }
                 
            
}


int main(){
int choice,len,bre,r,hei;
    cout<<"1. enter 1 to find rectangle area object \n2. enter 2 to find circle area object \n3. enter 3 to find cuboid volume \n4. enter 4 to find sphere volume";
    cout<<"\n5. enter 5 to compare volume of cuboids \n6. enter 6 to compare volume of spheres \n7. enter 7 to exit";
    cout<<"\nenter choice : ";
    cin>>choice;
    while(1){
    switch(choice){
        case 1: find_area_of_rectangle(); break;
        case 2: find_the_area_of_circle(); break;
        case 3: find_the_volume_of_cuboid(); break;
        case 4: find_the_volume_of_sphere(); break;
        case 5:  compare_two_cuboids(); break;
        case 6:  compare_two_spheres(); break;
        case 7: exit(0); break;
        default : cout<<"enter a valid choice \n"; 
    }
     cout<<"1. enter 1 to find rectangle area object \n2. enter 2 to find circle area object \n3. enter 3 to find cuboid volume \n4. enter 4 to find sphere volume";
    cout<<"\n5. enter 5 to compare volume of cuboids \n6. enter 6 to compare volume of spheres \n7. enter 7 to exit";
    cout<<"\nenter choice : ";
    cin>>choice;

    }
}