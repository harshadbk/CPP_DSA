#include<iostream>
using namespace std;

void towerofhonoi(int num,char from_rod,char to_rod,char auxi_rod){
  if(num==1){
    cout << "disk moves from "<<from_rod << " to rod " << to_rod<<endl;
    return;
  }
  towerofhonoi(num-1,from_rod,auxi_rod,to_rod);
  cout << "disk moves from "<<from_rod << " to rod " << to_rod<<endl;
  towerofhonoi(num-1,auxi_rod,to_rod,from_rod);
};

int main(){
    int n;
    cout << "Enter total no of disks ";
    cin >> n;
    cout << "sequence of moves :\n";
    towerofhonoi(n,'a','b','c');
    cout << "Total moves Required for disk moves " <<(1<<n)-1; 
    return 0;
}