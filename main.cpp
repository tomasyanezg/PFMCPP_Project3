 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

/*
Thing 1) TV
*/
struct TV
{    
    //1) broadcasted channel (int)
    int broadcastedChannel = 25;
    //2) volume level (int)
    int volumeLevel = 61;
    //3) amount of display ports (int)
    int amountDisplayPorts = 3;
    //4) internet connection (bool)
    bool internetConnection = true;
    //5) amount of smartTV apps (int)
    int amountSmartTVApps = 7;

    struct SmartTVApp
    {
        std::string appName = "Stream your Phone";
        std::string version = "v1.3";
        bool requiresInternetConnection = true;
        bool androidCompatible = true;
        float price = 2.99f;

        void startApp ();
        bool connectedToPhone (int phoneId, std::string phoneName); //Id = Mobile Equipment Identity (IMEI), returns true if connected
        bool buyApp (int creditCard, std::string fullName, bool appAlreadyPaid = false); //returns true if app was bought 
    };

    //3 things it can do:
    //1) increase/decrease volume
    int increaseVolume(int increment); //returns volumeLevel  
    //2) select specific channel to be broadcast
    int selectChannel (int channel, SmartTVApp AppName); //return broadcastedChannel or SmartTVApp
    //3) change between display ports
    void changeDisplayPort (); //no return, just toggle between ports 

    SmartTVApp youtube;

};

/*
Thing 2) Laptop
*/
struct Laptop
{
    //1) screen display brightness (int)
    int screenDisplayBrightness = 95;    
    //2) keyboard lights (bool)
    bool keyboardLights = true;
    //3) mousepad sensitivity (int)
    int mousepadSensitivity = 8;
    //4) model and manufacturer (std::string) 
    std::string modelManufacturer = "Dell, Inspiron 15";
    //5) processor specs e.g.: Hz, kernels, company (std::string)
    std::string processorSpecs = "Intel(R) Core(TM) i3 CPU @ 2.40GHz";

    struct soundSystem
    {
        bool internalSoundSystem = false;
        std::string nameModel = "Teufel 5CT Theater";
        int powerRequirements = 50; // (W)
        int amountSpeakers = 4;
        bool boostedLows = true;

        void setEqualizer (float frequencyRangeMin, float frequencyRangeMax, float gain);
        int toogleAudioOutput ();//returns number for the selected outpout eg.: 0 Laptop speakers, 1 Teufel speakers, 2 bluetooth
        void mute ();
    };

    //3 things it can do:
    //1) set desired screen brightness
    int setDisplayBrightness (int increment); //returns screenDisplayBrightness  
    //2) toggle keyboard lights on/off    
    void keyboardLightsToggle();   
    //3) increase/decrease mousepad sensitivity
    int increaseMousepadSensitivity (int increment); //returns mousepadSensitivity

    soundSystem dolby;

    soundSystem initialize (soundSystem systemName); // returns soundSystem struct info/specs

};

/*
Thing 3)Supermarket
*/
struct Supermarket
{
    //1) amount of vegetables (int)
    int amountVegetables = 25; //(kg)
    //2) amount of fruits (int)
    int amountFruits = 15; //(kg)
    //3) amount of workers (int)
    int amountWorkers = 6;
    //4) max storage capacity (double)
    double maxStorageCapacity = 525.50; //(kg)
    //5) address/location (std::string)
    std::string address = "Grand Tree Street 54, Cherry Town, 22562";

    //3 things it can do:
    //1) get new vegetables
    int getNewVegetables (int incrementVegetables); //return amountOfVegetables
    //2) get new fruits
    int getNewFruits (int incrementFruits); //return amountVegetables    
    //3) change max storage capacity
    double changeMaxStorageCapacity (double newMaxStorageCapacity); //return maxStorageCapacity    
};

/*
Thing 4) Cinema
*/
struct Cinema
{    
    //1) amount of seats (int)
    int amountSeats = 82; //per hall
    //2) weekly amount of popcorn usage (double)
    double weeklyAmountPopcorn = 1200.00; //servings
    //3) amount of halls/screens (int)
    int amountScreens = 5;
    //4) name of the latest released movie (std::string)
    std::string latestRelease = "The Double Standard by Michaelo DeLonginni";
    //5) weekly amount of customers (double)
    double weeklyCustomers = 1500.00; 

    //3 things it can do:
    //1) charge popcorn serving
    float chargePopcorn (int amountPopcornServings, bool inCash); //return price/bill  
    //2) set amount of available halls/screens
    void availableScreens (int amountScreens);  
    //3) change latest released movie    
    void latestMovie (std::string latestRelease);
};

/*
Thing 5) employee
*/
struct Employee
{
    //1) amount of employees (int)
    int amountEmployees = 1;
    //2) weekly worked hours (double)
    double weeklyWorkedHours = 50;
    //3) social security number (int)
    int socialSecurityNumber = 124565228;
    //4) full name (std::string)
    std::string fullName = "Christopher Calimbis";  
    //5) years of experience (int)
    int yearsOfExperience = 1;

    //3 things it can do:
    //1) serve dish
    std::string serveDish (int amountCustomers, int tableNumber); //returns name of the Dish and the amount of portions to be served 
    //2) prepare ingredients
    void prepareIngredients (std::string ingredients);  
    //3) organize inventory
    void organizeInventory (int amountEmployees);
};

/*
Thing 6) customer
*/
struct Customer
{
    //1) amount of custumers (int)
    int amountCustomers = 2;
    //2) prior reservation (bool)
    bool priorReservation = true;
    //3) full name (std::string)
    std::string fullName = "Edgar Bossio";
    //4) payment in cash or with card (bool)
    bool paymentInCash = false;
    //5) bill to be paid (float)
    float bill = 87.5f;

    //3 things it can do:
    //1) pay bill
    float payBill (float bill, bool inCash); //returns amount to be paid and if in cash or card
    //2) eat food
    std::string eatFood (std::string mainDish, int amountDrinks);//returns state of the customer eg.: liked food, allergic reaction, wants more.
    //3) drink beverage
    std::string drinkBeverage (std::string beverageName, int amountDrinks);//returns state of customer
};

/*
Thing 7) main dish
*/
struct MainDish
{
    //1) price (float)
    float price = 12.50f;   
    //2) ingredients (std::string)
    std::string ingredients = "flour, sugar, ground cinnamon, eggs, milk, carrot";  
    //3) for how many people (int)
    int forHowMany = 2;  
    //4) menu option (bool)
    bool menuOption = true;   //milkshake + prezels  
    //5) vegan (bool)
    bool vegan = false;

    //3 things it can do:
    //1) fill customers´s hunger
    bool satisfiedHunger(std::string mainDishName, bool menuOption); //return true for satiesfied hunger  
    //2) induce allergic reaction
    bool inducedAllergicReaction (std::string ingredients, bool vegan); //returns true for allergic reaction
    //3) make customer sick
    bool makesCustomerSick (std::string ingredients, bool decomposedFood); //returns true if customer is sick
};

/*
Thing 8) dessert
*/
struct Dessert
{
    //1) price (float)
    float price = 8.75f;
    //2) allergies (std::string)
    std::string allergies = "peanuts, almond";
    //3) served cold or warm (bool)
    bool servedWarm = false;   
    //4) to go or to eat here (bool)
    bool takeToGo = true;  
    //5) in cup or cone (bool)
    bool inCup = true;

    //3 things it can do:
    //1) make customer happy
    bool makesCustomerHappy (std::string dessertName);//return true if customer is happy    
    //2) make customer sick
    bool makesCustomerSick (std::string dessertName, int amountDesserts);//returns true if customer is sick
    //3) melt    
    bool isDessertMelted (std::string dessertName, bool servedWarm = false );//returns true if dessert melted   
};

/*    
Thing 9) beverage
*/
struct Beverage
{
    //1) cold or warm (bool)
    bool cold = true;  
    //2) price (float)
    float price = 4.99f;  
    //3) with alcohol (bool)
    bool withAlcohol = true;  
    //4) name (std::string)
    std::string name = "Heiniken";  
    //5) amount of drinks
    int amountDrinks = 5;

    //3 things it can do:
    //1) make customer tipsy
    bool makeCustomerTipsy (int amountDrinks, float alcoholPercentage);//returns true if customer is tipsy
    //2) warms customer up
    int warmsCustomer (bool withAlcohol, int amountDrinks); //return by how much the customer warmed up eg.: 2 C°   
    //3) make food taste better
    int makesFoodTasteBetter (std::string name, std::string mainDishName);//returns percentage of extra tip eg.: 10 (%)
};

/*
Thing 10) Restaurant
*/
struct Restaurant
{
    Employee markMinson;
    Customer familyGroup;    
    MainDish pizzaNapoli;
    Dessert chocolateIcecream;
    Beverage familySizeIcetea;

    //3 things it can do:
    //1) serve food and drink
    int serveFoodAndDrink (int amountCustomers, int amountMainDishes, int amountBeverages); //returns table number that got served    
    //2) reserve a table for x customers
    int reserveTable (std::string fullName, int amountCustomers, int tableNumber);//returns table number
    //3) charge customer in cash or with card
    bool chargeCustomer (float bill, bool inCash, int tableNumber); //returns true if bill was paid
};



int main()
{
    std::cout << "good to go!" << std::endl;
}
