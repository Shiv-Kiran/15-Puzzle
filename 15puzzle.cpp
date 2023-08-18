#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Radio_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Light_Button.H> // needed to use the Fl_Box class
#include<time.h>
#include<iostream>
using namespace std;

int main_i = 3 ;
int main_j = 3 ;

char* intToString(int value);
void change_label_of(const char* temp);
bool check_config();
void random_num();
void change_color();

class MyButton : public Fl_Button{
 int i, j;
    public:
    MyButton(int i, int j, int w, int h, const char* s) : Fl_Button(100*(j+1),100*(i+1),w,h,s){
  this->i=i;
  this->j=j;
  }
    int handle (int e) override {
        if (e==FL_PUSH){
            if (abs(i-main_i)+abs(j-main_j)==1){
    change_label_of(this->label());
    this->label("");
    this->color(FL_GREEN);
    change_color();
    main_i=i;
    main_j=j;
    return 1;
   }
        }
  return 0;
}
};

MyButton* button[4][4];


int main(int argc, char *argv[]) {
    Fl_Window *window;
 window = new Fl_Window (600, 600,"Puzzle");
 for (int i=0; i<4; i++){
  for (int j=0; j<4; j++){
   button[i][j] = new MyButton(i, j, 100, 100, intToString(4*i+j+1));
   button[i][j]->color(FL_BLUE);
  }
 }
 button[3 ][3 ]->label("");
 button[3 ][3 ]->color(FL_GREEN);

 random_num();

 window->show();
 window->end();

    return(Fl::run());
}

char *intToString (int value) {
 char *s = new char[10*sizeof(int)];
 sprintf(s,"%d",value);
 return s;
}
void change_label_of(const char* temp){
 button[main_i][main_j]->label(temp);
}
bool check_config(){
 for (int a=0; a<4; a++){
  for (int b=0; b<4; b++){
   if (!(a==3 &&b==3 )){
    if (strcmp(intToString(4*a+b+1),button[a][b]->label())){
     return false;
    }
   }
  }
 }
 return true;
}
void random_num(){
 int move = 0;
 srand(time(0));
 for(int i=0; i<1000; i++){
  int x = rand()%(4*4);
  move+=button[x/4][x%4]->handle(1);
 }
}
void change_color_(){
 button[main_i][main_j] -> color(FL_BLUE);
}


