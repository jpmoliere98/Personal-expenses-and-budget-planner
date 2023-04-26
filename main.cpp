// Created by 12397 on 4/11/2023.
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

//IN SUMMARY: this program takes a vector of float values as an argument (i.e., the housingVector we created) & finds
//the sum of all the values in the vector using a loop and an accumulator variable. Then the function return the final sum as a single float value.
std::vector<float> setHouseExp();
float sumHouse (std::vector <float> getVector);

std::vector<float> setTransportationExp ();
float sumTransportation (std::vector <float> getVector);

std::vector<float> setFoodExp ();
float sumFood (std::vector <float> getVector);

std::vector<float> setPersonalExp ();
float sumPersonal (std::vector <float> getVector);

std::vector<float> setEntertainmentExp ();
float sumEnter (std::vector <float> getVector);

std::vector<float> setHealthExp ();
float sumHealth (std::vector <float> getVector);

std::vector<float> setEducationExp ();
float sumEducation (std::vector <float> getVector);

std::vector<float> setSavings();
float sumSavings (std::vector <float> getVector);

std::vector<float> setIncome ();
float sumIncome (std::vector <float> getVector);

class UserProfile {
private:
    std::string occupation;
    int age{};
    std::string name;
    std::string lastName;

    // In order to access/modify private attributes we must use public set and get methods

public:

    //the set function is used to take in user input from outside the class to change value of a private attribute
    void setOccupation(std::string o){
        occupation = o;
    }

    void setAge(int x){
        age = x;
    }

    void setName(std::string n){
        name = n;
    }

    //the get method returns the value stored in a private attribute, therefore no longer void function
    std::string getName(){
        return name;
    }
    void setLastName(std::string ln){
        lastName = ln;
    }
    std::string getLastName(){
        return lastName;
    }
};



int main () {
    /*it is good practice to declare class attributes as private, to ensure that "sensitive" data is hidden from users.
    This creates encapsulation */
    std::cout << "Welcome to your Personal Expense & Budget Planner! ";
    std::cout << "Where we will help you track your monthly expenses, create summaries & budgets, as well as give you"
                 "our best financial tips and tricks!\n";
    std::cout << "To get started please fill out the following segments: \n";

    UserProfile user1;         //created first instance
    std::string firstName, last, occ;  //these variables were created to take user input & pass as parameters
    int a;

    std::cout << "First name: \n";
    std::cin >> firstName;
    user1.setName(firstName);   //

    std::cout << "Last name: \n";
    std::cin >> last;
    user1.setLastName(last);

    std::cout << "Age: \n";
    std::cin >> a;
    user1.setAge(a);

    std::cout << "From the choices below, choose an employment type that best matches your description and type its "
                 "corresponding number into the prompt. \n";
    std::cout << " 1 Employed \n 2 Unemployed \n Status:  \n";
    std::cin >> occ;
    user1.setOccupation(occ);

    std::cout << "Now that we've created your user profile " << user1.getName() << ", let's move into inputting "
                                                                                   "monthly expenses.\n" << std::endl;

//take user input for each vector expense

    std::cout << "Enter the total amount for the Housing Expense Category, this can include rent/mortgage, home insurance, "
                 "maintenance & repairs ,and utilities. \n ";
    std::cout << "(Once you are finished inputting expenses, enter a negative)\n";
    std::cout << "Housing Expense: \n";
    std::vector<float> housingVector = setHouseExp();
    //setHouseExp() is called implicitly b/c we  are asking it to assign the return vector to the variable we created

    /*necessary to create a new variable that stores the function setHouseExp b/c that way you can reuse the value
    i.e., the expenses stored in the vector, without prompting the user to re-enter the inputs. Which is what
     would happen if you simply pass the function setHouseExp as an argument*/

    std::cout << "Enter the following expense amounts within the Transportation Expense category. This can include "
                 "car payments, gas/fuel,car insurance, maintenance and repairs, public transportation. ";
    std::cout << "(Once you are finished inputting expenses, enter a negative number)\n";
    std::cout << "Transportation Expense: \n";
    std::vector<float> transVector = setTransportationExp();

    std::cout << "Enter the following amounts you spend on groceries. (Once you are finished inputting expenses, enter "
                 "a negative number)\n";
    std::cout << "Food Expense: \n";
    std::vector<float> foodVector = setFoodExp();

    std::cout << "Enter the following expense amounts within the Personal Care Expense category. This includes "
                 "beauty, hair,clothing, & gym memberships. (Once you are finished inputting expenses, "
                 "enter a negative number)\n";
    std::cout << "Personal Care Expense: \n";
    std::vector<float> careVector = setPersonalExp();

    std::cout << "Enter the following expense amounts within the Entertainment Expense category. This can include movies, concerts, sporting events, hobbies, video games, streaming services & dining out.\n";
    std::cout << "(Once you are finished inputting expenses, enter a negative number)\n";
    std::cout << "Entertainment Expense: \n";
    std::vector<float> enterVector = setEntertainmentExp();

    std::cout << "Enter the following expense amounts within the Health Expense category. This can include insurance,"
                 "co-pays, medications, & supplements (Once you are finished inputting expenses, enter a negative "
                 "number)\n";
    std::cout << "Health Expense: \n";
    std::vector<float> healthVector = setHealthExp();

    std::cout << "Enter the following expense amounts within the Education Expense category. This can include tuition,"
                 "textbooks, school supplies, & online courses. (Once you are finished inputting expenses,"
                 "enter a negative number)\n";
    std::cout << "Education Expense: \n";
    std::vector<float> eduVector = setEducationExp();

    std::cout << "Enter the amount going into your saving. (Enter a negative number when you are done)";
    std::cout << "Saving amount: \n";
    std::vector<float> savingVector = setSavings();

    std::cout << "Thank you for entering your expenses " << user1.getName() << "!\n" << std::endl;
    std::cout << "Now, please enter your income, which can be a single value or multiple amounts if you have "
                 "different sources of income. (Enter a negative number when done)\n";
    std::cout << "Income: \n";
    std::vector<float> incomeVector = setIncome();

    float transConstraint;
    float foodConstraint;
    float careConstraint;
    float enterConstraint;

    std::cout << "In order to make your budget, we need a few more things.\n";
    std::cout << "Assuming the categories House, Health, & Education are fixed expenses, we will only create budget constraints for variable expenses.\n";

    //ask user to enter budget constraints, to later be used to compare actual vs desired
    std::cout << "Enter the maximum amount you'd like to spend on Transportation: \n";
    std::cin >> transConstraint;
    std::cout << "Enter the maximum amount you'd like to spend on Food: \n";
    std::cin >> foodConstraint;
    std::cout << "Enter the maximum amount you'd like to spend on Personal Care: \n";
    std::cin >> careConstraint;
    std::cout << "Enter the maximum amount you'd like to spend on Entertainment: \n";
    std::cin >> enterConstraint;


    std::cout << "Perfect! You've finished entering all the necessary info!\n";
    std::cout << "Now you're all set to choose from the following options, just type the corresponding number "
                 "into the prompt. \n";

    //introduce menu

    int userChoice;  // this is outside, so that we can access it in the while loop
    do {
        std::cout << " 1 - Create an Expense Summary \n 2 - Create a Budget \n 3 - End the program \n ";
        std::cout << " ";
        std::cin >> userChoice;

        switch (userChoice) {
            case 1:
                std::cout << "You chose option 1, therefore your Expense Summary is found below.\n";
                std::cout
                        << "--------------------------------------------------------------------------------------------";
                std::cout << "                                " << user1.getName() << " " << user1.getLastName()
                          << " Expense Summary" << std::endl;
                std::cout << "\n Total Housing Expense: $" << sumHouse(housingVector);
                std::cout << "\n Total Transportation Expense: $" << sumTransportation(transVector);
                std::cout << "\n Total Food Expense: $" << sumHouse(foodVector);
                std::cout << "\n Total Personal Care Expense: $" << sumHouse(careVector);
                std::cout << "\n Total Entertainment Expense: $" << sumHouse(enterVector);
                std::cout << "\n Total Health Expense: $" << sumHouse(healthVector);
                std::cout << "\n Total Education Expense: $" << sumHouse(eduVector);
                std::cout << "\n Total Savings Account: $" << sumSavings(savingVector);
                std::cout << "\n Total Income: $" << sumIncome(incomeVector) << "\n";
                std::cout << "If you'd like to choose a different option, feel free to do so now, or end the program.\n";
                break;
            case 2:
                std::cout << "You chose option 2, therefore your Budget Planner is found below. As well as the "
                             "corresponding recommendations. \n";
                std::cout
                        << "--------------------------------------------------------------------------------------------";
                std::cout << "                                           " << user1.getName() << "'s Budget Planner" << std::endl;
                float housePercent;
                housePercent = (sumHouse(housingVector) / sumIncome(incomeVector)) *
                               100;  // this calculates the percentage of income that goes towards this expense
                std::cout << "Your Housing Expenses account for "<< housePercent << "% of your income.\n" << std::endl;

                float transPercent;
                transPercent = (sumTransportation(transVector) / sumIncome(incomeVector)) *
                               100;  // this calculates the percentage of income that goes towards this expense
                std::cout << "Your Transportation Expenses account for " << transPercent << "% of your income.\n"
                          << std::endl;

                float foodPercent;
                foodPercent = (sumFood(foodVector) / sumIncome(incomeVector)) *
                              100;  // this calculates the percentage of income that goes towards this expense
                std::cout << "Your Food Expenses account for " << foodPercent << "% of your income.\n" << std::endl;

                float personalPercent;
                personalPercent = (sumPersonal(careVector) / sumIncome(incomeVector)) *
                                  100;  // this calculates the percentage of income that goes towards this expense
                std::cout << "Your Personal Care Expenses account for " << personalPercent << "% of your income.\n"
                          << std::endl;

                float entertainmentPercent;
                entertainmentPercent = (sumEnter(enterVector) / sumIncome(incomeVector)) *
                                       100;  // this calculates the percentage of income that goes towards this expense
                std::cout << "Your Entertainment Expenses account for " << entertainmentPercent << "% of your income.\n"
                          << std::endl;

                float healthPercent;
                healthPercent = (sumHealth(healthVector) / sumIncome(incomeVector)) *
                                100;  // this calculates the percentage of income that goes towards this expense
                std::cout << "Your Health Expenses account for " << healthPercent << "% of your income.\n" << std::endl;

                float eduPercent;
                eduPercent = (sumEducation(eduVector) / sumIncome(incomeVector)) *
                             100;  // this calculates the percentage of income that goes towards this expense
                std::cout << "Your Education Expenses account for " << eduPercent << "% of your income.\n" << std::endl;

                float savingsPercent;
                savingsPercent = (sumSavings(savingVector) / sumIncome(incomeVector)) * 100;
                std::cout << "Your Saving's account for " << savingsPercent << "% of your income.\n" << std::endl;

                float totalExp;
                totalExp = sumHouse(housingVector) + sumTransportation(transVector) + sumFood(foodVector) +
                           sumPersonal(careVector) +
                           sumEnter(enterVector) + sumHealth(healthVector) + sumEducation(eduVector) + sumSavings(savingVector);

                //calculate the difference btw what user spent & what they wanted to spend

                float transVariance;
                transVariance = transConstraint - sumTransportation(transVector);
                float foodVariance;
                foodVariance = foodConstraint - sumFood(foodVector);
                float careVariance;
                careVariance = careConstraint - sumPersonal(careVector);
                float enterVariance;
                enterVariance = enterConstraint - sumEnter(enterVector);


                //create budget & check constraints
                if (totalExp < sumIncome(incomeVector)) {
                    std::cout << "Given this information, your total expenses do NOT exceed your overall income.\n";
                    std::cout << " Therefore, " <<user1.getName() << " you are doing good in terms of spending less "
                                                                     "than you make. However, we will still check your variable expenses to see if you met budget"
                                                                     "constraints.\n";

                    if (transVariance < 0){
                        std::cout << "You surpassed your Transportation Budget Constraint by $" << std::setprecision(2) << transVariance << "\n";
                        std::cout << "Therefore we recommend you try these cost-saving options:\n";
                        std::cout << "- Carpool with friends to school or work\n";
                        std::cout << "- Try using public transportation to reduce gas amount\n";
                        std::cout << "- Use gas stations that give you either cashback or discounted gas if you open an account with them\n";
                    } else {
                        std::cout << "You stayed within your Transportation budget constraint & are left with $" <<  transVariance << "\n";
                        std::cout << "Great work!";
                    }
                    std::cout << "                                                                           \n";

                    if (foodVariance < 0){
                        std::cout << "You surpassed your Food Budget Constraint by $" << std::setprecision(2) <<foodVariance << "\n";
                        std::cout << "Therefore we recommend these cost-saving options:\n";
                        std::cout << "- Try purchasing only the food you know you will eat to avoid spoiling goods\n";
                        std::cout << "- Use more coupons\n";
                    } else {
                        std::cout << "You stayed within your Food budget constraint & are left with $" <<std::setprecision(2) << foodVariance << "\n";
                        std::cout << "Great work!";}
                    std::cout << "                                                                           \n";

                    if (careVariance < 0){
                        std::cout << "You surpassed your Personal Care Budget Constraint by $" <<std::setprecision(2) << careVariance << "\n";
                        std::cout << "Therefore we recommend these cost-saving options:\n";
                        std::cout << "- Avoid going to the hairstylist too much, it really makes no difference for you\n";
                        std::cout << "- Limit the amount of online shopping you do\n";
                    } else{
                        std::cout << "You stayed within your Personal Care budget constraint & are left with $" <<std::setprecision(2) << careVariance << "\n";
                        std::cout << "Great work!";}
                    std::cout << "                                                                           \n";

                    if (enterConstraint < 0){
                        std::cout << "You surpassed your Entertainment Budget Constraint by $" <<std::setprecision(2) << enterVariance << "\n";
                        std::cout << "Therefore we recommend these cost-saving options:\n";
                        std::cout << "- To avoid eating out, try cooking more at home\n";
                        std::cout << "- Limit the amount of concerts/events you attend\n";
                        std::cout << "- Limit the amount of online shopping you do\n";
                    } else {
                        std::cout << "You stayed within your Entertainment budget constraint & are left with $" <<std::setprecision(2) << enterVariance << "\n";
                        std::cout << "Great work!";}
                }
                std::cout << "                                                                           \n";

                if (totalExp > sumIncome(incomeVector)) {
                    std::cout << "Given this information, your total expenses DO exceed your overall income.\n";
                    std::cout << "Therefore, " <<user1.getName() << " you are making bad financial decisions. Let's help you out!\n";
                    std::cout << "We'll start by seeing if you met your budget constraints.\n";
                    std::cout << "                                                                           \n";

                    if (transVariance < 0){
                        std::cout << "You surpassed your Transportation Budget Constraint by $" << std::setprecision(2) <<transVariance << "\n";
                        std::cout << "Therefore we recommend these cost-saving options:\n";
                        std::cout << "- Carpool with friends to school or work\n";
                        std::cout << "- Try using public transportation to reduce gas amount\n";
                        std::cout << "- Use gas stations that you give either cashback or discounted gas if you open an account with them\n";
                    } else {
                        std::cout << "You stayed within your Transportation budget constraint & are left with $" <<std::setprecision(2) << transVariance << "\n";
                        std::cout << "Great work!";
                    }
                    std::cout << "                                                                           \n";

                    if (foodVariance < 0){
                        std::cout << "You surpassed your Food Budget Constraint by $" << std::setprecision(2) <<foodVariance << "\n";
                        std::cout << "Therefore we recommend these cost-saving options:\n";
                        std::cout << "- Try purchasing only the food you know you will eat to avoid spoiling goods\n";
                        std::cout << "- Use more coupons\n";
                    } else {
                        std::cout << "You stayed within your Food budget constraint & are left with $" <<std::setprecision(2) << foodVariance << "\n";
                        std::cout << "Great work!";}
                    std::cout << "                                                                           \n";

                    if (careVariance < 0){
                        std::cout << "You surpassed your Personal Care Budget Constraint by $" <<std::setprecision(2) << careVariance << "\n";
                        std::cout << "Therefore we recommend these cost-saving options:\n";
                        std::cout << "- Avoid going to the hairstylist too much, it really makes no difference for you\n";
                        std::cout << "- Limit the amount of online shopping you do\n";
                    } else{
                        std::cout << "You stayed within your Personal Care budget constraint & are left with $" <<std::setprecision(2) << careVariance << "\n";
                        std::cout << "Great work!";}
                    std::cout << "                                                                           \n";

                    if (enterVariance < 0){
                        std::cout << "You surpassed your Entertainment Budget Constraint by $" << std::setprecision(2) <<enterVariance << "\n";
                        std::cout << "Therefore we recommend you try these options to try & stay within your budget for next month:\n";
                        std::cout << "- To avoid eating out, try cooking more at home\n";
                        std::cout << "- Limit the amount of concerts/events you attend\n";
                    } else {
                        std::cout << "You stayed within your Entertainment budget constraint & are left with $" <<std::setprecision(2) << enterVariance << "\n";
                        std::cout << "Great work!";}
                    std::cout << "                                                                           \n";
                }
                break;

            default:
                std::cout << "You've ended the program, " <<user1.getName() << "!" << std::endl;
                std::cout << " Thank you for using the Personal Expense & Budget Planner! \n";
                std::cout << "We hope we shed some light on your lack of "
                             "financial skills!";
        }

    }while (userChoice != 3);
}

//function definitions used to take in expenses

std::vector<float> setHouseExp(){
    float input;
    std::vector<float> housingVector; //this will store input values
    while (std::cin >> input) {
        if (input < 0) {   //for each value the function will check if < 0, & breaks if it is
            break;
        }
        housingVector.push_back(input);
    }
    return housingVector;  //this now contains all the expenses entered by the user

}

float sumHouse (std::vector <float> getVector) {   // b/c I want it to return a single float variable, I just declared as a float
    //later on in the main function, we will pass the housingVector returned in the function setHouseExp as an argument, which will therefore return its sum
    float sum = 0.0;  //sum here finds the sum of the elements in the housing_Vector
    int i;
    for (i = 0; i < getVector.size(); i++) {
        sum += getVector[i];
    }
    return sum;
}

std::vector<float> setTransportationExp () {
    float input;
    std::vector<float> transVector; //this will store input values
    while (std::cin >> input) {
        if (input < 0) {   //for each value the function will check if < 0, & breaks if it is
            break;
        }
        transVector.push_back(input);
    }
    return transVector;
}

float sumTransportation (std::vector <float> getVector) {
    float sum = 0.0;
    int i;
    for (i = 0; i < getVector.size(); i++) {
        sum += getVector[i];
    }
    return sum;
}


std::vector<float> setFoodExp () {
    float input;
    std::vector<float> foodVector;
    while (std::cin >> input) {
        if (input < 0) {
            break;
        }
        foodVector.push_back(input);
    }
    return foodVector;
}

float sumFood (std::vector <float> getVector) {
    float sum = 0.0;
    int i;
    for (i = 0; i < getVector.size(); i++) {
        sum += getVector[i];
    }
    return sum;
}

std::vector<float> setPersonalExp () {
    float input;
    std::vector<float> careVector;
    while (std::cin >> input) {
        if (input < 0) {
            break;
        }
        careVector.push_back(input);
    }
    return careVector;
}

float sumPersonal (std::vector <float> getVector) {
    float sum = 0.0;
    int i;
    for (i = 0; i < getVector.size(); i++) {
        sum += getVector[i];
    }
    return sum;
}

std::vector<float> setEntertainmentExp () {
    float input;
    std::vector<float> enterVector;
    while (std::cin >> input) {
        if (input < 0) {
            break;
        }
        enterVector.push_back(input);
    }
    return enterVector;
}

float sumEnter (std::vector <float> getVector) {
    float sum = 0.0;
    int i;
    for (i = 0; i < getVector.size(); i++) {
        sum += getVector[i];
    }
    return sum;
}

std::vector<float> setHealthExp () {
    float input;
    std::vector<float> healthVector;
    while (std::cin >> input) {
        if (input < 0) {
            break;
        }
        healthVector.push_back(input);
    }
    return healthVector;
}

float sumHealth (std::vector <float> getVector) {
    float sum = 0.0;
    int i;
    for (i = 0; i < getVector.size(); i++) {
        sum += getVector[i];
    }
    return sum;
}

std::vector<float> setEducationExp () {
    float input;
    std::vector<float> educationVector;
    while (std::cin >> input) {
        if (input < 0) {
            break;
        }
        educationVector.push_back(input);
    }
    return educationVector;
}

float sumEducation (std::vector <float> getVector) {
    float sum = 0.0;
    int i;
    for (i = 0; i < getVector.size(); i++) {
        sum += getVector[i];
    }
    return sum;
}

std::vector<float> setSavings () {
    float input;
    std::vector<float> savingsVector;
    while (std::cin >> input) {
        if (input < 0) {
            break;
        }
        savingsVector.push_back(input);
    }
    return savingsVector;
}

float sumSavings (std::vector <float> getVector) {
    float sum = 0.0;
    int i;
    for (i = 0; i < getVector.size(); i++) {
        sum += getVector[i];
    }
    return sum;
}

std::vector<float> setIncome (){
    float input;
    std::vector<float> incomeVector;
    while (std::cin >> input) {
        if (input < 0) {
            break;
        }
        incomeVector.push_back(input);
    }
    return incomeVector;
}

float sumIncome (std::vector <float> getVector) {
    float sum = 0.0;
    int i;
    for (i = 0; i < getVector.size(); i++) {
        sum += getVector[i];
    }
    return sum;
}


