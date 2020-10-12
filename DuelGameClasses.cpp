#include <iostream>
#include <cmath>
#include <ctime>
#include <ncurses.h> // ??? conio.h 

#define NO DEBUG

using namespace std;

// global constants:
const int MOD = 3;


// global variables: 
// nothing right now

// class.hpp:
class Unit {
  private:
    // atributes:
    string type;
    string mod_against;
  public:
    Unit() { // default constructor
      type = "archer";
      mod_against = "lancer";
    }
    Unit(string type, string mod) { // constructor
      this->type = type;
      mod_against = mod;
    }
    // methods:
    string get_unit_type() {
      return this->type;
    }
    string get_unit_mod() {
      return this->mod_against;
    }
};

class Player {
  private:
  // atributes:
    
  public:
  // constructor:
    Player() {
      name = "Player super class";
    }
    // overload:
    Player(string _name) {
      name = _name;
    }
  // destructor:
    ~Player() {
      cout << name << " are exit from programm" << endl;  
    }
  // methods:
    void produce_unit(string type);
    void random_unit();
    int rollD6();
    string get_name();
    string get_player_unit_type() {
      return player_unit.get_unit_type();
    }
    string get_player_unit_mod() {
      return player_unit.get_unit_mod();
    }
    int get_player_last_roll() {
      return last_roll;
    }
  protected:
  //allowed in heir class
    // atributes:
    string name;
    int last_roll;
    Unit player_unit;       
};

class HumanPlayer : public Player {
  private:
   
  public:
    HumanPlayer () {
      this->name = "Henry";
    }
    HumanPlayer (string _name) {
      this->name = _name;  
    }
    template <typename T> // templates
    T chat(T message) {
      cout << "You: " << message << endl;
      return message;
    }
};

class AIPlayer : public Player {
  public:
    AIPlayer () {
      this->name = "Karl";    
    }
    // methods:
    void battle_cry() {
      cout << ", i will kill you!" << endl; 
    }  
};

/*
template <class T, class T2> // class template
class Process {
  public:
    T var;
    T2 var2;
};
*/

// objects.cpp:
Unit knight("knight", "archer");
Unit lancer("lancer", "knight");
Unit archer;

// class.cpp:
// method definitions:
int Player::rollD6() {
  int acc;

  
  acc = 1 + rand() % 6;
  this->last_roll = acc;
  return acc;
}

string Player::get_name() {
  return name;
}

void Player::produce_unit(string _type) {
    this->player_unit = archer;
    if (_type == "knight") 
      this->player_unit = knight;
    else if (_type == "lancer")
      this->player_unit = lancer;           
}

void Player::random_unit() {
  int rnd_num = 1 + rand() % 3;
  switch (rnd_num) {
    case 1: 
      this->player_unit = archer;
      break;
    case 2:      
      this->player_unit = knight;
      break;
    case 3:       
      this->player_unit = lancer;
  }
}

void debug() {
  Unit archer; 
  HumanPlayer new_player; // create new object of HumanPlayer class
  // templates in action:
  new_player.chat("Hello!");
  new_player.chat(3.14);
  new_player.chat(NULL);
  new_player.chat(true);
  new_player.chat(false);
  new_player.chat("Answer is:");
  new_player.chat(42);
}

// main.cpp:
int main() {
#ifdef DEBUG   
    debug(); // if debug is needed
#endif

  bool game_over = false;
  bool right_input = false;
  int player_result;
  int computer_result;
  string player_input;

  srand(time(nullptr));

  cout << "Hello, what is your name?" << endl;
  cin >> player_input;
  HumanPlayer new_player(player_input);
  AIPlayer new_enemy;
  cout << "Against you play " << new_enemy.get_name() << endl;
  cout << "He`s battle cry is: " << new_player.get_name();
  new_enemy.battle_cry();
  cout << "Say something to him: ";
  cin >> player_input;
  new_player.chat(player_input);
  
  while (!right_input) {
    cout << "Now choose your unit: (a)rcher, (k)night, (l)ancer" << endl;
    cin >> player_input;
    if (player_input == "a") {
      new_player.produce_unit("archer");
      right_input = true;
    }
    else if (player_input == "k") {
      new_player.produce_unit("knight");
      right_input = true;
    }
    else if (player_input == "l") {
      new_player.produce_unit("lancer");
      right_input = true;
    } 
    else {
      cout << "please type a, k or l" << endl;
    }
  }

  new_enemy.random_unit();
  cout << "Your opponet's unit is: " << new_enemy.get_player_unit_type();
  cout << endl;

  while (!game_over) {
    cout << "press Enter to roll D6" << endl;
    cin.get();
    
    new_player.rollD6();
    new_enemy.rollD6();
    
    player_result = new_player.get_player_last_roll();
    computer_result = new_enemy.get_player_last_roll();
    
    if (new_player.get_player_unit_mod() == new_enemy.get_player_unit_type()) 
      player_result += MOD;
    else if (new_enemy.get_player_unit_mod() == new_player.get_player_unit_type())
      computer_result += MOD;

    cout << "your result is: " << player_result << endl << "result of your enemy is: " << computer_result << endl;

    if (player_result >= 6 && computer_result < 6) {
      // only player win
      cout << "You are win!!!" << endl;
      game_over = true;
    }
    else if (player_result < 6 && computer_result >= 6) {
      // only computer win
      cout << "You are lose(((" << endl;  
      game_over = true;
    }
    else if (player_result >= 6 && computer_result >= 6) {
      // both are lose 
      cout << "no winner in this battle" << endl;
      game_over = true;
    } 
    else {
      cout << "both of you remain on the battlefield" << endl;
      // both are still alive
    }
  }
  
  cout << "press Enter to exit" << endl;
  cin.get(); // wait input 
  return 0;
}
