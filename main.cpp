/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct TV
{    
    int broadcastedChannel = 25;
    int volumeLevel = 61;
    int amountDisplayPorts = 3;
    bool internetConnection = true;
    int amountSmartTVApps = 7;

    struct SmartTVApp
    {
        std::string appName = "Stream your Phone";
        std::string version = "v1.3";
        bool requiresInternetConnection = true;
        bool androidCompatible = true;
        float price = 2.99f;

        void startApp ();
        bool connectedToPhone (int phoneId, std::string phoneName);
        bool buyApp (int creditCard, std::string fullName, bool appAlreadyPaid = false);
    };
    int increaseVolume(int increment);
    int selectChannel (int channel, SmartTVApp appName);
    void changeDisplayPort ();

    SmartTVApp youtube;

};

int TV::increaseVolume(int increment)
{
    std::cout << "Volume increased by" << increment << std::endl;
    return increment;    
}

int TV::selectChannel(int channel, SmartTVApp appName)
{
    std::cout << "Selected Channel" << channel << "with " << appName.appName << std::endl;
    return channel;
}

void TV::changeDisplayPort()
{
    std::cout  << "Displayed port changed" << std::endl;       
}

void TV::SmartTVApp:: startApp()
{
    std::cout << "The following app was started: " << appName << std::endl;
}

bool TV::SmartTVApp::connectedToPhone(int phoneId, std::string phoneName)
{
    std::cout << "SmartTV connected to phone: " << phoneName << "and phone id :" << phoneId << std::endl;
    return true;
}

bool TV::SmartTVApp::buyApp(int creditCard, std::string fullName, bool appAlreadyPaid)
{
    std::cout << "An app was bought with the following credit card: " << creditCard << "and name" << fullName << std::endl;
    return appAlreadyPaid == true;
}



struct Laptop
{
    int screenDisplayBrightness = 95;    
    bool keyboardLights = true;
    int mousepadSensitivity = 8;
    std::string modelManufacturer = "Dell, Inspiron 15";
    std::string processorSpecs = "Intel(R) Core(TM) i3 CPU @ 2.40GHz";

    struct SoundSystem
    {
        bool internalSoundSystem = false;
        std::string nameModel = "Teufel 5CT Theater";
        int powerRequirements = 50; 
        int amountSpeakers = 4;
        bool boostedLows = true;

        void setEqualizer (float frequencyRangeMin, float frequencyRangeMax, float gain);
        int toogleAudioOutput ();
        void mute ();
    };

    int setDisplayBrightness (int increment);
    void keyboardLightsToggle();   
    int increaseMousepadSensitivity (int increment);

    SoundSystem dolby;

    SoundSystem initialize (SoundSystem systemName);
};

int Laptop::setDisplayBrightness(int increment)
{
    std::cout << "Display brightness increased by : " << increment << std::endl;
    return increment;
}

void Laptop::keyboardLightsToggle()
{
    std::cout << "Keyboard lights toggled" << std::endl;
}

int Laptop::increaseMousepadSensitivity(int increment)
{
    std::cout << "Mousepad sensitivity increased by :" << increment << std::endl;
    return increment;
}

void Laptop::SoundSystem::setEqualizer(float frequencyRangeMin, float frequencyRangeMax, float gain)
{
    std::cout << "Equalizer set between frequencies :" << frequencyRangeMin << "and" << frequencyRangeMax << ". The gain was set to :" << gain << std::endl;
}

int Laptop::SoundSystem::toogleAudioOutput()
{
    std::cout << "Audio output toggled" << std::endl;
    return 1;
}

void Laptop::SoundSystem::mute()
{
    std::cout << "Mute toggled" << std::endl;
}



struct Supermarket
{
    int amountVegetables = 25;
    int amountFruits = 15;
    int amountWorkers = 6;
    double maxStorageCapacity = 525.50;
    std::string address = "Grand Tree Street 54, Cherry Town, 22562";

    int getNewVegetables (int incrementVegetables);
    int getNewFruits (int incrementFruits);
    double changeMaxStorageCapacity (double newMaxStorageCapacity);  
};

int Supermarket::getNewVegetables(int incrementVegetables)
{
    std::cout << "Vegetables incremented by " << incrementVegetables << "kg." << std::endl;
    return incrementVegetables;
}

int Supermarket::getNewFruits(int incrementFruits)
{
    std::cout << "Fruits incremented by " << incrementFruits << "kg." << std::endl;
    return incrementFruits;
}

double Supermarket::changeMaxStorageCapacity(double newMaxStorageCapacity)
{
    std::cout << "The storage max capacity has been changed to : " << newMaxStorageCapacity << "kg." << std::endl;
    return newMaxStorageCapacity;
}



struct Cinema
{    
    int amountSeats = 82;
    double weeklyAmountPopcorn = 1200.00;
    int amountScreens = 5;
    std::string latestRelease = "The Double Standard by Michaelo DeLonginni";
    double weeklyCustomers = 1500.00; 

    float chargePopcorn (float amountPopcornServings, bool inCash);
    void availableScreens (int amountScreens);  
    void latestMovie (std::string latestRelease);
};

float Cinema::chargePopcorn(float amountPopcornServings, bool inCash)
{
    std::cout << "The amount of popcorn serving to be made are : " << amountPopcornServings << inCash << std::endl;
    
    return 2.99f * amountPopcornServings;
}

void Cinema::availableScreens(int newAmountScreens)
{
    std::cout << "The amount of available of screen for today is : " << newAmountScreens << std::endl;
}

void Cinema::latestMovie(std::string newLatestRelease)
{
    std::cout << "The latest avaiable movie for today is : " << newLatestRelease << std::endl;
}



struct Employee
{
    int amountEmployees = 1;
    double weeklyWorkedHours = 50;
    int socialSecurityNumber = 124565228;
    std::string fullName = "Christopher Calimbis";  
    int yearsOfExperience = 1;

    std::string serveDish (int amountCustomers, int tableNumber);
    void prepareIngredients (std::string ingredients);  
    void organizeInventory (int amountEmployees);
};

std::string Employee::serveDish(int amountCustomers, int tableNumber)
{
    std::cout << "Serve dish in table # : " << tableNumber << "for this amount of customer" << amountCustomers << std::endl;
    return "Table served!";
}

void Employee::prepareIngredients(std::string ingredients)
{
    std::cout << "Prepare the following ingredients :" << ingredients << std::endl;
}

void Employee::organizeInventory(int newAmountEmployees)
{
    std::cout << "The inventory has to be organized by this amount of employees : " << newAmountEmployees << std::endl;
}



struct Customer
{
    int amountCustomers = 2;
    bool priorReservation = true;
    std::string fullName = "Edgar Bossio";
    bool paymentInCash = false;
    float bill = 87.5f;

    float payBill (float bill, bool inCash);
    std::string eatFood (std::string mainDish, int amountDrinks);
    std::string drinkBeverage (std::string beverageName, int amountDrinks);
};

float Customer::payBill(float newBill, bool inCash)
{
    std::cout << "The amount to be paid is : " << newBill << inCash << std::endl;
    return bill;
}

std::string Customer::eatFood(std::string mainDish, int amountDrinks)
{
    std::cout << "The customer is eating a " << mainDish << "together with " << amountDrinks << "drinks." << std::endl;
    return mainDish;
}

std::string Customer::drinkBeverage(std::string beverageName, int amountDrinks)
{
    std::cout << "The customer drinks " << amountDrinks << beverageName << std::endl;
    return beverageName;
}



struct MainDish
{
    float price = 12.50f;   
    std::string ingredients = "flour, sugar, ground cinnamon, eggs, milk, carrot";  
    int forHowMany = 2;  
    bool menuOption = true;
    bool vegan = false;

    bool satisfiedHunger(std::string mainDishName, bool menuOption);
    bool inducedAllergicReaction (std::string ingredients, bool vegan);
    bool makesCustomerSick (std::string ingredients, bool decomposedFood);
};

bool MainDish::satisfiedHunger(std::string newMainDishName, bool newMenuOption)
{
    std::cout << "The customer was satisfied with the " << newMainDishName << std::endl;
    return newMenuOption;
}

bool MainDish::inducedAllergicReaction(std::string newIngredients, bool isItVegan)
{
    std::cout << "Caution! This dish contains possible allergid ingredients :" << newIngredients << std::endl;
    return isItVegan;
}

bool MainDish::makesCustomerSick(std::string newIngredients, bool decomposedFood)
{
    std::cout << "The following ingredients should be disposed : " << newIngredients << std::endl;
    return decomposedFood;
}



struct Dessert
{
    float price = 8.75f;
    std::string allergies = "peanuts, almond";
    bool servedWarm = false;   
    bool takeToGo = true;  
    bool inCup = true;

    bool makesCustomerHappy (std::string dessertName);
    bool makesCustomerSick (std::string dessertName, int amountDesserts);
    bool isDessertMelted (std::string dessertName, bool servedWarm = false );
};

bool Dessert::makesCustomerSick(std::string dessertName, int amountDesserts)
{
    std::cout << "The dessert : " << dessertName << "after eating a total of " << amountDesserts << "made the customer sick." << std::endl;
    return true;
}

bool Dessert::makesCustomerHappy(std::string dessertName)
{
    std::cout << "The dessert : " << dessertName << "was very tasty for the customer." << std::endl;
    return true;
}

bool Dessert::isDessertMelted(std::string dessertName, bool isItServedWarm)
{
    std::cout << "You waited too long, the dessert " << dessertName << "melted." << std::endl;
    return isItServedWarm;
}



struct Beverage
{
    bool cold = true;  
    float price = 4.99f;  
    bool withAlcohol = true;  
    std::string name = "Heiniken";  
    int amountDrinks = 5;

    bool makeCustomerTipsy (int amountDrinks, float alcoholPercentage);
    int warmsCustomer (bool withAlcohol, int amountDrinks);
    int makesFoodTasteBetter (std::string name, std::string mainDishName);
};

bool Beverage::makeCustomerTipsy(int newAmountDrinks, float alcoholPercentage)
{
    std::cout << "After " << newAmountDrinks << "with a alcohol percentage of " << alcoholPercentage << "customer is looking typsy." << std::endl;
    return true;
}

int Beverage::warmsCustomer(bool isItWithAlcohol, int newAmountDrinks)
{
    std::cout << "Customer is feeling warm after this amount of drinks" << newAmountDrinks << std::endl;
    return isItWithAlcohol;
}

int Beverage::makesFoodTasteBetter(std::string newName, std::string mainDishName)
{
    std::cout << "The custome with the name " << newName << "ate " << mainDishName << std::endl;
    return amountDrinks;
}



struct Restaurant
{
    Employee markMinson;
    Customer familyGroup;    
    MainDish pizzaNapoli;
    Dessert chocolateIcecream;
    Beverage familySizeIcetea;

    int serveFoodAndDrink (int amountCustomers, int amountMainDishes, int amountBeverages);
    int reserveTable (std::string fullName, int amountCustomers, int tableNumber);
    bool chargeCustomer (float bill, bool inCash, int tableNumber);
};

int Restaurant::serveFoodAndDrink(int amountCustomers, int amountMainDishes, int amountBeverages)
{
    std::cout << "Customer served :" << amountCustomers << "amount of main dishesh " << amountMainDishes << "and drinks" << amountBeverages << std::endl;
    return amountBeverages;
}

int Restaurant::reserveTable(std::string fullName, int amountCustomers, int tableNumber)
{
    std::cout << "Table # " << tableNumber << "for an amount of " << amountCustomers << "customers," << "was reserved under the name : " << fullName << std::endl;
    return tableNumber;
}

bool Restaurant::chargeCustomer(float bill, bool inCash, int tableNumber)
{
    std::cout << "The customer in table #" << tableNumber << "has to pay : " << bill << "$." << std::endl;
    return inCash;
}


int main()
{
    Example::main();

    //add your code below here:


    //and above here
    std::cout << "good to go!" << std::endl;
}
