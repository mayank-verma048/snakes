/* snakes2.45.cpp */
/* 
 *
 * Copyright 2013, 2014 Mayank Verma <mayank.verma048@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation;  either version 3 of the License, or (at your option)  any  later
 * version.
 *
 * This  program is distributed in the hope that it will be useful, but  WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR  A  PARTICULAR  PURPOSE.  See the GNU General  Public  License  for  more
 * details.
 *
 * You should have received a copy of the GNU General Public License along  with
 * this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * The GPL v3 text can be found at <./gpl.txt>.
 */


#include<iostream>
#include<conio.h>
#include<windows.h>
#include<winuser.h>

using namespace std;

const char DOWN='s',UP='w',LEFT='a',RIGHT='d';

struct Point{
    int x;
    int y;
};

class GamePiece{
    private:
        short is_init;
        int pX;
        int pY;
        char shape;


    public:
        class UninitialisedException{
            public:
                UninitialisedException(){cerr<<"The object is not initialised.";}
        };
        GamePiece(){}
        GamePiece(int x,int y,char c):pX(x),pY(y),shape(c){
            is_init=1;
        }
        void init_piece(int x,int y,char c){
            pX=x;
            pY=y;
            shape=c;
            is_init=1;
        }
        int getX(){
            is_initf();
            return pX;
        }
        int getY(){
            is_initf();
            return pY;
        }
        void setX(int i){
            is_initf();
            pX=i;
        }
        void setY(int i){
            is_initf();
            pY=i;
        }
        
        void setShape(char i){
            shape=i;
        }
        void is_initf(){
            if(!is_init)throw UninitialisedException();
        }
        void display(){
            is_initf();
            cout<<"X: "<<pX<<" Y: "<<pY<<" shape: "<<shape<<"\n";
        }
        void paint(int newX,int newY){
            is_initf();
            gotoxy(getX(),getY()); cout<<" \b";
            gotoxy(newX,newY); cout<<shape<<"\b";
            setX(newX); setY(newY);
        }
        void repaint(){
            is_initf();
            gotoxy(getX(),getY());cout<<shape<<"\b";
        }
        
};

class GameObject{
	GamePiece *g;
	int c,rSize;
public:
	void registerGamePiece(GamePiece &p){
		g[c++]=p;
		rSize++;
	}

	GamePiece *getRegisteredPieces(){
		return g;
	}

	 bool hitTest(GameObject g){
		 /*for(int i=0;i<getRegisteredSize();i++){
			 for(int j=0;j<g.getRegisteredSize();j++){
				 cout<<"Sx"<<getRegisteredPieces()[i].getX()<<" Wx"<<g.getRegisteredPieces()[j].getX()<<" Sy"<<getRegisteredPieces()[i].getY()<<" Wy"<<g.getRegisteredPieces()[j].getY()<<endl;
				 //if(getRegisteredPieces()[i].getX()==g.getRegisteredPieces()[j].getX()&&getRegisteredPieces()[i].getY()==g.getRegisteredPieces()[j].getY())return true;
			 }
		 }*/
		 cout<<"Default";
		 return false;
	 }

	 bool hitTest(GameObject g,Point p){

		 return false;
	 }

	 int getRegisteredSize(){
		 return rSize;
	 }


	 GameObject(){
		 c=0;
		 g=new GamePiece[200];
		 rSize=0;
	 }
    
    
};


class Snake:public GameObject{
    private:
        char s_dir;
        int tX,tY,tX1,tY1;
        int _max;
        GamePiece s[200];
        GamePiece head;
        void init(){
            head.init_piece(9,10,'O');
            head.repaint();
			registerGamePiece(head);
            for(int i=0;i<_max;i++){
                s[i].init_piece(wherex(),wherey()+1,'*');
                //s[i].repaint();
                if(i==_max-1){                                                   //this if is for test purposes only
                    s[i].init_piece(wherex(),wherey()+1,'X');
                //s[i].repaint();
                }
				registerGamePiece(s[i]);
            }
            gotoxy(head.getX(),head.getY());
        }
		
public:
    Snake():_max(5),s_dir(UP){
        init();
    }
    void display(){
        cout<<"Direction of snake is: "<<s_dir<<endl; head.display();
        for(int i=0;i<_max;i++){
            s[i].display();
        }
    }

    void snake_down(){
        if(s_dir==UP)snake_up();
        else{
            tX=head.getX(); tY=head.getY();
            if((head.getY()+1)>23)head.setY(0);
        head.paint(head.getX(),head.getY()+1);
        for(int i=0;i<_max;i++){
            if(i==(_max-1)){
                s[i].paint(tX,tY);
            }
            tX1=s[i].getX();tY1=s[i].getY();
            s[i].setX(tX);s[i].setY(tY);
            tX=tX1;tY=tY1;
            if(i==0){
                s[i].repaint();    
            }    
        }
        s_dir=DOWN;
        }

    }

    void snake_up(){
        if(s_dir==DOWN)snake_down();
        else{
            tX=head.getX(); tY=head.getY();
            if((head.getY()-1)<1)head.setY(23);
        head.paint(head.getX(),head.getY()-1);
        for(int i=0;i<_max;i++){
            if(i==(_max-1)){
                s[i].paint(tX,tY);
            }
            tX1=s[i].getX();tY1=s[i].getY();
            s[i].setX(tX);s[i].setY(tY);
            tX=tX1;tY=tY1;
            if(i==0){
                s[i].repaint();
            }
        }
        s_dir=UP;
        }

    }

    void snake_left(){
        if(s_dir==RIGHT)snake_right();
        else{
            tX=head.getX(); tY=head.getY();
            if((head.getX()-2)<1)head.setX(79);
        head.paint(head.getX()-2,head.getY());
        for(int i=0;i<_max;i++){
            if(i==(_max-1)){
                s[i].paint(tX,tY);
            }
            tX1=s[i].getX();tY1=s[i].getY();
            s[i].setX(tX);s[i].setY(tY);
            tX=tX1;tY=tY1;
            if(i==0){
                s[i].repaint();
            }
        }
        s_dir=LEFT;
        }

    }

    void snake_right(){
        if(s_dir==LEFT)snake_left();
        else{
            tX=head.getX(); tY=head.getY();
            if((head.getX()+2)>79)head.setX(1);
        head.paint(head.getX()+2,head.getY());
        for(int i=0;i<_max;i++){
            if(i==(_max-1)){
                s[i].paint(tX,tY);
            }
            tX1=s[i].getX();tY1=s[i].getY();
            s[i].setX(tX);s[i].setY(tY);
            tX=tX1;tY=tY1;
            if(i==0){
                s[i].repaint();
            }
        }
        s_dir=RIGHT;
        }

    }

    void snake_move(char dir){
        if(dir==LEFT)snake_left();
        if(dir==RIGHT)snake_right();
        if(dir==UP)snake_up();
        if(dir==DOWN)snake_down();
    }

	bool hitTest(GameObject g){
		for(int i=0;i<g.getRegisteredSize();i++){
			if((head.getX()==g.getRegisteredPieces()[i].getX()&&head.getY()==g.getRegisteredPieces()[i].getY())||(s[0].getX()==g.getRegisteredPieces()[i].getX()&&s[0].getY()==g.getRegisteredPieces()[i].getY()))return true;
		}
		return false;
	}
    
    void increase(){
        _max++;
        s[_max-2].setShape('*');
        s[_max-2].repaint();
        s[_max-1].init_piece(s[_max-2].getX(),s[_max-2].getY()+1,'X');
        s[_max-1].repaint();
    }

    bool selfhit(){
     for(int i=0;i<_max;i++){
      if(head.getX()==s[i].getX()&&head.getY()==s[i].getY())return true;
     }
    return false;
    }
};



class Wall: public GameObject{
private:
    GamePiece *w;
    
public:
    Wall(Point *p,int size){
        w=new GamePiece[size];
        for(int i=0;i<size;i++){
            w[i].init_piece(p[i].x,p[i].y,'#');
            w[i].repaint();
			registerGamePiece(w[i]);
        }
    }
    
};

void print(char *s);
void print(char *s, int n);

int main(){
    const A=23;
    const B=79;
    unsigned count =1,score=0;
    char last_move=UP;
    clrscr();
    print("               1010101  10    10    10    10  10  101010  1010101\n               10       1010  10  10  10  10 10   10      10 \n               1010101  10 10 10  101010  1010    10101   1010101\n                    10  10  1010  10  10  10 10   10           10\n               1010101  10   110  10  10  10  10  101010  1010101",5);
    gotoxy(1,15);
    print("Press any key to start...");
    getch();
    clrscr();
    Snake s;
    Point p[A+B+B+A];
    /*Test Points*/
    for(int i=0;i<A;i++){
     p[i].x=1; p[i].y=i+1;
    }
    for(int i=A;i<A+B;i++){
     p[i].x=i-A+1; p[i].y=23;
    }
    for(int i=A+B;i<A+B+B;i++){
     p[i].x=i-A-B+1; p[i].y=1;
    } 
    for(int i=A+B+B;i<A+B+B+A;i++){
     p[i].x=79; p[i].y=i-A-B-B+1;
    } 
    /*Test Points*/
    Wall w(p,A+B+B+A);
    
    while(1){
		if(s.hitTest(w)||s.selfhit()){
                   clrscr();
                   cout<<"Game Over.\nYour score:"<<score;
                   cin.get();exit(0);
                }
                if(count==10){
                 count=1;
                 s.increase();
                 score+=100;
                }
        if (GetAsyncKeyState(VK_DOWN) == -32767){
            //cout<<"DOWN";
            s.snake_move(DOWN);
            last_move=DOWN;
        }
        if (GetAsyncKeyState(VK_UP) == -32767){
            //cout<<"UP";
            s.snake_move(UP);
            last_move=UP;
        }
        
        if (GetAsyncKeyState(VK_LEFT) == -32767){
            //cout<<"LEFT";
            s.snake_move(LEFT);
            last_move=LEFT;
        }

        if (GetAsyncKeyState(VK_RIGHT) == -32767){
            //cout<<"RIGHT";
            s.snake_move(RIGHT);
            last_move=RIGHT;
        }else{
            s.snake_move(last_move);
        }

		if(GetAsyncKeyState(0x01)== -32767) exit(0);
        
        Sleep(20);                                 //Speed of snake
	count++;	
    }

}

void print(char *s){
 for(int i=0;s[i]!=0;i++){
  cout<<s[i];
  Sleep(50);
 }
 cout<<endl;
}

void print(char *s,int n){
 srand(time(NULL));
 int i,nl=0;
 for(i=0;s[i]!=0;i++)if(s[i]=='\n')nl++;
 int j=i-nl;
 int x=1;
 int y=n;
 while(j!=0){
  int k=rand()%i;
  if(s[k]==1||s[k]=='\n')continue;
  if(s[k]==' '){s[k]=1;j--;continue;}
  x=1;
  y=n;
  for(int l=0;l!=k;l++){
   if(s[l]=='\n'){
    y++;
    x=1;
   } else x++;
  }
  gotoxy(x,y);
  cout<<s[k];
  s[k]=1;
  Sleep(30);
  j--;
 }
 cout<<endl;
}



