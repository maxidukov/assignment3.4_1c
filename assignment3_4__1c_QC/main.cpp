#include <iostream>
#include <fstream>
#include <string>

class Address{
   //public:
   std::string city, street;
   int building, app;
   public:
   /*Address(std::string city, std::string street,
            int building, int app){
     this->city = city;
     this->street = street;
     this->building = building;
     this->app = app;
   }*/
   Address() {}
   Address(std::ifstream& fin){
     fin >> city >> street
        >>building >> app;
   }
   std::string ret_string(){
     return city + ", " +
            street + ", " +
            std::to_string(building) + ", " +
            std::to_string(app) + "\n";
   }
};

int main() {
  std::ifstream fin("in.txt");
  int num;
  Address* addrs;
  if(fin.is_open()){
     //std::string input;
    //int num;
    fin >> num;
    addrs = new Address[num];
    for(int i{};i<num&&fin;i++){
      addrs[i] = Address(fin);
    }
  }else{
    std::cout<<"Couldn't open file!\n";
    return 1;
  }
  fin.close();
  std::ofstream outfile("out.txt");
  outfile << num << "\n";
  for(int i=num-1;i>=0;i--){
      outfile << addrs[i].ret_string();
  }
  outfile.close();

  delete[] addrs;

  return 0;
}
