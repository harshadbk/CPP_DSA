#include<iostream>
using namespace std;

void towerofhonoi(int num,char from_rod,char to_rod,char auxroad){
   if(num==1){
      cout << "Move disk 1 from " << from_rod << " to " << to_rod << endl;
      return;
   }
   towerofhonoi(num-1,from_rod,auxroad,to_rod);
   cout << "move disk "<<num<<" from"<<from_rod << " to "<<to_rod<<endl;
   towerofhonoi(num-1,auxroad,to_rod,from_rod);
};

int main(){
    int n;
    cout << "Enter number of disks :";
    cin >> n;
    cout << "Sequence of Moves:";
    towerofhonoi(n,'a','b','c');
    cout << "Total no of moves required :"<<(1<<n)-1;
    return 0;
}