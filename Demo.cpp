/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

    sushi->move(tom);
    sushi->slash(tom);

    Team team_A(tom); 
    Point d (64,57);
    YoungNinja *Yogi= new YoungNinja("Yogi", d);
    team_A.add(Yogi);

    // Team b(tom); should throw tom is already in team a

     Team team_B(sushi); ///the problem is when tom,=0 and yogi =100
      Point c(12,81);
     TrainedNinja *Hikary =new TrainedNinja("Hikari", c);
     team_B.add(Hikary);

      cout<<"herre!!!!!"<<endl;


     while(team_A.stillAlive() > 0&& team_B.stillAlive() > 0 ){
       cout<<" new turn"<<endl;
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
       Yogi->getLocation().print();

        team_B.print();
       Hikary->getLocation().print();
       sushi->getLocation().print();
         
     }

     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}