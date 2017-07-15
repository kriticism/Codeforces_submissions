#include <iostream>
#include <vector>
#include <string>
using namespace std;
// greedy
int main(){
  int src_r, src_c, dest_r, dest_c, steps = 0;
  char c;
  vector<string> path;
  cin>>c>>src_r;
  src_r--;
  src_c = ((int)c - (int)'a');

  cin>>c>>dest_r;
  dest_r--;
  dest_c = ((int)c - (int)'a');
  // cout<<src_r<<","<<src_c<<endl;
  // cout<<dest_r<<","<<dest_c<<endl;
  int curr_r = src_r, curr_c = src_c;
  while(1){
    if(curr_r > dest_r){
      if(curr_c < dest_c){
        path.push_back("RD");
        // cout<<"RD\n";
        steps++;
        curr_r--; curr_c++;
      }
      else if(curr_c == dest_c){

        while(curr_r != dest_r){
          path.push_back("D");
          // cout<<"D\n";
          steps++;
          curr_r--;
        }
      }
      else if(curr_c > dest_c){
        path.push_back("LD");
        // cout<<"LD\n";
        steps++;
        curr_r--; curr_c--;
      }
    }
    else if(curr_r == dest_r){
      if(curr_c < dest_c){
        while(curr_c!=dest_c){
          path.push_back("R");
          // cout<<"R\n";
          steps++;
          curr_c++;
        }
      }
      else if(curr_c == dest_c){
        break;
      }
      else if(curr_c > dest_c){
        while(curr_c != dest_c){
          path.push_back("L");
          // cout<<"L\n";
          steps++;
          curr_c--;
        }
      }
    }
    else if(curr_r < dest_r){
      if(curr_c < dest_c){
        path.push_back("RU");
        // cout<<"RU\n";
        steps++;
        curr_r++; curr_c++;
      }
      else if(curr_c == dest_c){
        for(int i = curr_r+1; i<=dest_r; i++){
          path.push_back("U");
          // cout<<"U\n";
          steps++;
          curr_r++;
        }
      }
      else if(curr_c > dest_c){
        path.push_back("LU");
        // cout<<"LU\n";
        steps++;
        curr_r++; curr_c--;
      }
    }
  }
  cout<<steps<<endl;
  for(vector<string>::iterator it=path.begin(); it!=path.end(); ++it)
    cout<<(*it)<<endl;
  return 0;
}
