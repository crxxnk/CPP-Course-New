/*
? What is Polymorphism?
* Fundamental to Object-Oriented Programming
! Polymorphism
  * Compile-time / early binding / static binding
  * Run-time / late binding / dynamic binding
? Runtime polymorphism
  * Being able to assign different meanings to the same function at run-time
? Allows us to program more abstractly
  * Think general vs. specific
  * Let C++ figure out which function to call at run-time
? Not the default in C++, run-time polymorphism is achieved via
  * Inheritance
  * Base class pointers or references
  * Virtual functions
! Types of Polymorphism in C++
  ? Compile-time
    * Function Overloading
    * Operator Overloading
  ? Run-time
    * Function Overriding
! Compile-time, early binding, static binding are all the same thing, and Run-time, late binding, dynamic binding too
* Static binding example:
Account a;
a.withdraw(1000); // Account::withdraw

Savings b;
b.withdraw(1000); // Savings::withdraw

Checking c;
c.withdraw(1000); // Checking::withdraw()

Trust d;
d.withdraw(1000); // Trust::withdraw()

Account *p = new Trust(); // Trust is an account so this is legal
p->withdraw(1000); // Calls the Account::withdraw() method because of static binding that is used by default

! Another problem:

void displayAccount(const Account &acc) {
  acc.display(); // will always use Account::display
}

Account a;
displayAccount(a);

Savings b;
displayAccount(b);

Checking c;
displayAccount(c);

Trust d;
displayAccount(d);

* Dynamic binding example:

! withdraw() is virtual in Account
Account a;
a.withdraw(1000); // Account::withdraw

Savings b;
b.withdraw(1000); // Savings::withdraw

Checking c;
c.withdraw(1000); // Checking::withdraw()

Trust d;
d.withdraw(1000); // Trust::withdraw()

Account *p = new Trust();
p->withdraw(1000); // Trust::withdraw()

! Second:

! display() is virtual in Account
void displayAccount(const Account &acc) {
  acc.display(); // will always call the display method depending on the object's type(RUN-TIME)
}

Account a;
displayAccount(a);

Savings b;
displayAccount(b);

Checking c;
displayAccount(c);

Trust d;
displayAccount(d);

! Using a Base class pointer
? For dynamic polymorphism we must have:
  * Inheritance
  * Base class pointer or Base class reference
  * Virtual functions
Account* p1 = new Account;
Account* p2 = new Savings;
Account* p3 = new Checking;
Account* p4 = new Trust;

p1->withdraw(1000); // Account::withdraw
p2->withdraw(1000); // Savings::withdraw
p3->withdraw(1000); // Checking::withdraw
p4->withdraw(1000); // Trust::withdraw

Account *array[] = {p1, p2, p3, p4};
for(size_t i = 0; i<4; i++)
  array[i]->withdraw(1000); // The correct withdraw method will be called based on the type of the object
                               that each pointer points to because of dynamic binding

* Vector example:

vector<Account*> accounts {p1, p2, p3, p4};
for(auto acc: accounts)
  acc->withdraw(1000);

delete p1, p2 etc.
*/

//! Virtual functions and how the class works in 11-virtual-functions.cpp