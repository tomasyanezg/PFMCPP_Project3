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
    TV();
    
    int broadcastedChannel = 25;
    int volumeLevel = 61;
    int amountDisplayPorts = 3;
    bool internetConnection = true;
    int amountSmartTVApps = 7;

    struct SmartTVApp
    {
        SmartTVApp();

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

TV::TV()
{
    std::cout << "TV is being constructed! \n"; 
}

TV::SmartTVApp::SmartTVApp()
{
    std::cout << "SmartTVApp is being constructed! \n";
}

int TV::increaseVolume(int increment)
{
    std::cout << "Volume increased by " << increment << std::endl;
    return increment;    
}

int TV::selectChannel(int channel, SmartTVApp appName)
{
    std::cout << "Selected Channel " << channel << " with " << appName.appName << std::endl;
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
    std::cout << "SmartTV connected to : " << phoneName << " and phone id :" << phoneId << std::endl;
    return true;
}

bool TV::SmartTVApp::buyApp(int creditCard, std::string fullName, bool appAlreadyPaid)
{
    std::cout << "An app was bought with the following credit card: " << creditCard << " and name " << fullName << std::endl;
    return appAlreadyPaid == true;
}



struct Laptop
{
    Laptop();

    int screenDisplayBrightness = 95;    
    bool keyboardLights = true;
    int mousepadSensitivity = 8;
    std::string modelManufacturer = "Dell, Inspiron 15";
    std::string processorSpecs = "Intel(R) Core(TM) i3 CPU @ 2.40GHz";

    struct SoundSystem
    {
        SoundSystem();

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

Laptop::Laptop()
{
    std::cout << "Laptop is being constructed! \n";
}

Laptop::SoundSystem::SoundSystem()
{
    std::cout << "SoundSystem is being constructed! \n";
}

int Laptop::setDisplayBrightness(int increment)
{
    std::cout << "Display brightness increased by " << increment << std::endl;
    return increment;
}

void Laptop::keyboardLightsToggle()
{
    std::cout << "Keyboard lights toggled" << std::endl;
}

int Laptop::increaseMousepadSensitivity(int increment)
{
    std::cout << "Mousepad sensitivity increased by " << increment << std::endl;
    return increment;
}

void Laptop::SoundSystem::setEqualizer(float frequencyRangeMin, float frequencyRangeMax, float gain)
{
    std::cout << "Equalizer set between : " << frequencyRangeMin << "Hz and " << frequencyRangeMax << "Hz. The gain was set to : " << gain << "dB." << std::endl;
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
    Supermarket();

    int amountVegetables = 25;
    int amountFruits = 15;
    int amountWorkers = 6;
    double maxStorageCapacity = 525.50;
    std::string address = "Grand Tree Street 54, Cherry Town, 22562";

    int getNewVegetables (int incrementVegetables);
    int getNewFruits (int incrementFruits);
    double changeMaxStorageCapacity (double newMaxStorageCapacity);  
};

Supermarket::Supermarket()
{
    std::cout << "Supermarket is being constructed! \n";
}

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
    std::cout << "The storage max capacity has been changed to " << newMaxStorageCapacity << "kg." << std::endl;
    return newMaxStorageCapacity;
}



struct Cinema
{    
    Cinema();

    int amountSeats = 82;
    double weeklyAmountPopcorn = 1200.00;
    int amountScreens = 5;
    std::string latestRelease = "The Double Standard by Michaelo DeLonginni";
    double weeklyCustomers = 1500.00; 

    float chargePopcorn (float amountPopcornServings, bool inCash);
    void availableScreens (int amountScreens);  
    void latestMovie (std::string latestRelease);
};

Cinema::Cinema()
{
    std::cout << "Cinema is being constructed! \n";
}

float Cinema::chargePopcorn(float amountPopcornServings, bool inCash)
{
    std::cout << "The amount of popcorn serving to be made are " 
              << amountPopcornServings    
              << " making a total of "
              << 2.99f * amountPopcornServings
              << "$"
              << (inCash ? " to be paid in cash " :  "to be paid with card.")
              << std::endl;
    
    return 2.99f * amountPopcornServings;
}

void Cinema::availableScreens(int newAmountScreens)
{
    std::cout << "The amount of available of screen for today is " << newAmountScreens << std::endl;
}

void Cinema::latestMovie(std::string newLatestRelease)
{
    std::cout << "The latest avaiable movie for today is " << newLatestRelease << std::endl;
}



struct Employee
{
    Employee();

    int amountEmployees = 1;
    double weeklyWorkedHours = 50;
    int socialSecurityNumber = 124565228;
    std::string fullName = "Christopher Calimbis";  
    int yearsOfExperience = 1;

    std::string serveDish (int amountCustomers, int tableNumber);
    void prepareIngredients (std::string ingredients);  
    void organizeInventory (int amountEmployees);
};

Employee::Employee()
{
    std::cout << "Employee is being constructed! \n";
}

std::string Employee::serveDish(int amountCustomers, int tableNumber)
{
    std::cout << "Serve main dish in table # " << tableNumber << " for a total of " << amountCustomers << " customers"<< std::endl;
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
    Customer();

    int amountCustomers = 2;
    bool priorReservation = true;
    std::string fullName = "Edgar Bossio";
    bool paymentInCash = false;
    float bill = 87.5f;

    float payBill (float bill, bool inCash);
    std::string eatFood (std::string mainDish, int amountDrinks);
    std::string drinkBeverage (std::string beverageName, int amountDrinks);
};

Customer::Customer()
{
    std::cout << "Customer is being constructed! \n";
}

float Customer::payBill(float newBill, bool inCash)
{
    std::cout << "The amount to be paid is " 
              << newBill 
              << "$ "
              << (inCash? "to be paid in cash" : "to be paid with card" ) 
              << std::endl;
    return bill;
}

std::string Customer::eatFood(std::string mainDish, int amountDrinks)
{
    std::cout << "The customer ate a " << mainDish << " together with " << amountDrinks << " drinks." << std::endl;
    return mainDish;
}

std::string Customer::drinkBeverage(std::string beverageName, int amountDrinks)
{
    std::cout << "The customer drinked a total of " << amountDrinks << " " << beverageName << std::endl;
    return beverageName;
}



struct MainDish
{
    MainDish();

    float price = 12.50f;   
    std::string ingredients = "flour, sugar, ground cinnamon, eggs, milk, carrot";  
    int forHowMany = 2;  
    bool menuOption = true;
    bool vegan = false;

    bool satisfiedHunger(std::string mainDishName, bool menuOption);
    bool inducedAllergicReaction (std::string ingredients, bool vegan);
    bool makesCustomerSick (std::string ingredients, bool decomposedFood);
};

MainDish::MainDish()
{
    std::cout << "MainDish is being constructed! \n";
}

bool MainDish::satisfiedHunger(std::string newMainDishName, bool newMenuOption)
{
    std::cout << "The customer was satisfied with the " << newMainDishName << std::endl;
    return newMenuOption;
}

bool MainDish::inducedAllergicReaction(std::string newIngredients, bool isItVegan)
{
    std::cout << "Caution! This dish contains possible allergic ingredients :" << newIngredients << std::endl;
    return isItVegan;
}

bool MainDish::makesCustomerSick(std::string newIngredients, bool decomposedFood)
{
    std::cout << "The following ingredients should be disposed : " << newIngredients << std::endl;
    return decomposedFood;
}



struct Dessert
{
    Dessert();

    float price = 8.75f;
    std::string allergies = "peanuts, almond";
    bool servedWarm = false;   
    bool takeToGo = true;  
    bool inCup = true;

    bool makesCustomerHappy (std::string dessertName);
    bool makesCustomerSick (std::string dessertName, int amountDesserts);
    bool isDessertMelted (std::string dessertName, bool servedWarm = false );
};

Dessert::Dessert()
{
    std::cout << "Dessert is being constructed! \n";
}

bool Dessert::makesCustomerSick(std::string dessertName, int amountDesserts)
{
    std::cout << "The dessert : " << dessertName << "after eating a total of " << amountDesserts << " cups, made the customer sick." << std::endl;
    return true;
}

bool Dessert::makesCustomerHappy(std::string dessertName)
{
    std::cout << "The dessert : " << dessertName << "was very tasty for the customer." << std::endl;
    return true;
}

bool Dessert::isDessertMelted(std::string dessertName, bool isItServedWarm)
{
    std::cout << "You waited too long, the " << dessertName << " dessert melted." << std::endl;
    return isItServedWarm;
}



struct Beverage
{
    Beverage();

    bool cold = true;  
    float price = 22.55f;  
    bool withAlcohol = true;  
    std::string name = "Heiniken";  
    int amountDrinks = 5;

    bool makeCustomerTipsy (int amountDrinks, float alcoholPercentage);
    int warmsCustomer (bool withAlcohol, int amountDrinks);
    int makesFoodTasteBetter (std::string name, std::string mainDishName);
};

Beverage::Beverage()
{
    std::cout << "Beverage is being constructed! \n";
}

bool Beverage::makeCustomerTipsy(int newAmountDrinks, float alcoholPercentage)
{
    std::cout << "After " << newAmountDrinks << " glasses with an alcohol percentage of " << alcoholPercentage << "%, the customer is looking very typsy." << std::endl;
    return true;
}

int Beverage::warmsCustomer(bool isItWithAlcohol, int newAmountDrinks)
{
    std::cout << "Customer is feeling warm after this amount of drinks : " << newAmountDrinks << std::endl;
    return isItWithAlcohol;
}

int Beverage::makesFoodTasteBetter(std::string newName, std::string mainDishName)
{
    std::cout << "You can drink a " << newName << " that makes " << mainDishName << " taste better. You should try it!" << std::endl;
    return amountDrinks;
}



struct Restaurant
{
    Restaurant();

    Employee markMinson;
    Customer familyGroup;    
    std::string bestSelling = "Pizza Napoli";
    Dessert chocolateIcecream;
    Beverage familySizeIcetea;

    int serveFoodAndDrink (int amountCustomers, int amountMainDishes, int amountBeverages);
    int reserveTable (std::string fullName, int amountCustomers, int tableNumber);
    bool chargeCustomer (float bill, bool inCash, int tableNumber);
};

Restaurant::Restaurant()
{
    std::cout << "Restaurant is being constructed! \n";
}

int Restaurant::serveFoodAndDrink(int amountCustomers, int amountMainDishes, int amountBeverages)
{
    std::cout << amountCustomers << " customers were served a total of " << amountMainDishes << " main dishes " << amountBeverages << " and drinks" << std::endl;
    return amountBeverages;
}

int Restaurant::reserveTable(std::string fullName, int amountCustomers, int tableNumber)
{
    std::cout << "Table# " << tableNumber << " has been reserved for an amount of " << amountCustomers << " customers," << " under the name of " << fullName << std::endl;
    return tableNumber;
}

bool Restaurant::chargeCustomer(float bill, bool inCash, int tableNumber)
{
    std::cout << "The customer in table #" << tableNumber << " has to pay " << bill << "$." << std::endl;
    return inCash;
}


int main()
{
    Example::main();

    //add your code below here:
    std::cout << "\n";
    TV SamsungTV;
    TV::SmartTVApp phoneStream;
    
    SamsungTV.changeDisplayPort();
    SamsungTV.increaseVolume(8);
    std::cout << "You are watching now channel " << SamsungTV.broadcastedChannel << std::endl;
    SamsungTV.selectChannel(22, phoneStream);
    

    phoneStream.startApp();
    phoneStream.connectedToPhone(6541, "Alejandro´s iPhone");
    phoneStream.buyApp(12215478, "Alejandro Paredes");
    std::cout << "A total of " << phoneStream.price << "$ has ben charged to your credit card." << std::endl;

    
    std::cout << "---------------" << std::endl;

    Laptop dell;
    Laptop::SoundSystem teufel;

    dell.setDisplayBrightness(100);
    dell.keyboardLightsToggle();
    std::cout << "Mousepad sensitivity is set at " << dell.mousepadSensitivity << std::endl;
    dell.increaseMousepadSensitivity(5);
    
    teufel.setEqualizer(50, 500, 1.5);
    teufel.toogleAudioOutput();
    std::cout << "A total of " << teufel.amountSpeakers << " speakers are connected." << std::endl;
    teufel.mute();

    std::cout << "---------------" << std::endl;

    Supermarket rewe;
    
    rewe.getNewFruits(20);
    std::cout << "The storage capacity right now is of " << rewe.maxStorageCapacity << "kg" << std::endl;
    rewe.changeMaxStorageCapacity(200);
    rewe.getNewFruits(12);

    std::cout << "---------------" << std::endl;

    Cinema cinexplex;

    std::cout << "Welcome to Cineplex!" << std::endl;
    cinexplex.availableScreens(8);
    std::cout << "Each hall has a total of " << cinexplex.amountSeats << " seats made for your conformt and all your family members" << std::endl;
    cinexplex.latestMovie("The Jimi Hendrix Experience");
    cinexplex.chargePopcorn(5, false);

    std::cout << "---------------" << std::endl;

    Employee cashier;

    cashier.organizeInventory(1);
    cashier.prepareIngredients(" tomatoes, vegetables, salad, onion and garlic");
    cashier.serveDish(4, 29);
    std::cout << "The employee of the month is " << cashier.fullName << " with a total of " << cashier.weeklyWorkedHours << " hours! Congratulations!" << std::endl;

    std::cout << "---------------" << std::endl;
    
    Customer annoyingCustomer;

    annoyingCustomer.drinkBeverage("Beers", 14);
    annoyingCustomer.eatFood("Cheeseburger", 0);
    annoyingCustomer.payBill(54, true);
    std::cout << "The customer under the name of " << annoyingCustomer.fullName << " refuses to pay! Local police has been informed." << std::endl;

    std::cout << "---------------" << std::endl;
    
    MainDish weeklySuggestion;

    weeklySuggestion.inducedAllergicReaction(" peanuts and cashew", false);
    weeklySuggestion.satisfiedHunger("Chicken lasagna", false);
    weeklySuggestion.makesCustomerSick("chicken", true);
    std::cout << "The price of the weekly suggestion has a discount of 20%, making it a total of " << weeklySuggestion.price << "$" << std::endl;
    
    std::cout << "---------------" << std::endl;

    Dessert iceCream;

    iceCream.isDessertMelted("ice cream");
    iceCream.makesCustomerHappy("ice cream ");
    iceCream.makesCustomerSick("chocolate pudding ", 6);

    std::cout << "The ice cream is for free! The total to be paid is of " << iceCream.price << "$"<< std::endl;

    std::cout << "---------------" << std::endl;

    Beverage wine;
    
    wine.warmsCustomer(true, 2);
    wine.makesFoodTasteBetter("wine", "frutti di mare");
    wine.makeCustomerTipsy(7, 8);

    std::cout << "Sir, I will have to ask you to leave the restaurant. You own a total of " << wine.price << "$. Its 10 am!" << std::endl;

    std::cout << "---------------" << std::endl;

    Restaurant mamaMia;

    mamaMia.reserveTable("Mario Barbarossa", 8, 15);
    mamaMia.serveFoodAndDrink(8, 6, 10);
    mamaMia.chargeCustomer(102, true, 15);

    std::cout << "We hope that you and your familiy liked our food! We have the best " << mamaMia.bestSelling << " in the city. See you next time, bye!" << std::endl;
    
    
    //and above here
    std::cout << "good to go!" << std::endl;
}
