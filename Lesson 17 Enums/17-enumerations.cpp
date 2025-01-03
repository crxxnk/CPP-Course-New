/*
! Enumerations
? What is an enumeration?
  * A user-defined type that models a set of constant integral values
The days of the week(Mon, Tue, Wed,...)
The months of the year(Jan, Feb, Mar,...)
etc

! This is bad and enums replace ts
int state;
std::cin>>state;
if(state == 0)
  initiate(3); // random mapping that we don't know(used before enums)
else if(state == 1)
  initiate(4);
else if(state == 2)
  initiate(5);

* Replacement;
enum State { Engine_Failure = 0, Inclement_Weather = 1, Nominal = 2 };
enum Sequence { Abort = 3, Hold = 4, Launch = 5 };

int input;
std::cin>>input;
State state = State(input);

if(state == Engine_Failure)
  initiate(Abort);
else if(state == Inclement_Weather)
  initiate(Hold);
else if(state == Nominal)
  initiate(Launch);

! Created 2 functions that both return ints
int get_state() {
  return state_of_fridge;
}

int get_state() {
  return state_of_rocket;
}

? What if we use the wrong function?
int state = get_state();

* Ts can be fixed with enums

int get_state() {
  return state_of_fridge;
}

State getState() {
  return state_of_rocket;
}

State state = get_state(); //! Wrong function

! Does not compile so we good
if(state == Engine_Failure)
  initiate(Abort);
else if(state == Inclement_Weather)
  initiate(Hold);
else if(state == Nominal)
  initiate(Launch);

! Enum Syntax
enum-key enum-name : enumerator-type { };

* Simplest enum we can make
enum {Red, Green, Blue}; // Implicit initialization
       0      1     2    // The compiler initializes each value as shown(previous value + 1)

enum {Red = 1, Green = 2, Blue = 3}; // Explicit initialization

enum {Red = 1, Green, Blue}; // Explicit/Implicit initialization
                 2      3

enum {Red, Green, Blue}; // Underlying type: int
       0      1     2

enum {Red, Green, Blue = -32769}; // Underlying type: long
       0      1  -32769

enum : uint8_t {Red, Green, Blue}; // Underlying type: unsigned 8 bit int

enum : long long {Red, Green, Blue}; // Underlying type: long long

! Enumeration name
* Anonymous / No type safety
enum {Red, Green, Blue};
int myColor;
myColor = Green; //* Valid
myColor = 1; //* Also valid

* Named / Type safe
enum Color {Red, Green, Blue};
Color myColor;
myColor = Green; //* Valid
myColor = 4; //! Not valid
*/