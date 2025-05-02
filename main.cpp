#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <iomanip> // for setw function to properly display detail
#include<conio.h> //used for displaying the output in clear screen



using namespace std;

class CropDetermination
{
    
protected:
    string season;
    string Typeofsoil;

public:
    CropDetermination() // Unparameterized Constructor 
    {
        season = "";
        Typeofsoil = "";
    }
    CropDetermination(string s, string ts) // Parameterized Constructor
    {
        season = s;
        Typeofsoil = ts;
    }
    void Takeinput()
    {
        cout << "=====================================================================\n";
        cout << "||                                                                 ||\n";
        cout << "||         === WELCOME TO THE CROP MANAGEMENT SYSTEM ===           ||\n";
        cout << "||                                                                 ||\n";
        cout << "=====================================================================\n\n";

        cout << "Enter the Season in which you want to grow a crop (Summer, Monsoon, Winter): ";
        cin >> season;
//Asking Farmer to choose season to grow their crop
        cout << "\nRecommended Crop Season:\n";
        if (season == "summer" || season == "Summer")
        {
            cout << "Zaid crops can be grown in the " << season << " season (March to June).\n";
        }
        else if (season == "monsoon" || season == "Monsoon")
        {
            cout << "Kharif crops can be grown in the " << season << " season (June to July).\n";
        }
        else if (season == "Winter" || season == "winter")
        {
            cout << "Rabi crops can be grown in the Winter season (October to November).\n";
        }
else{
    cout<<"Error ! Please enter the valid season \n";
}
        cout << "\nEnter the Type of soil in your region (Red, Black, Desert, Forest): ";
        cin >> Typeofsoil;
//Asking farmer about the type of soil 
        cout << "\nSoil Type Analysis and Crop Recommendations:\n";

        if (Typeofsoil == "Red" || Typeofsoil == "red")
        {
            cout << "Red soil is well-drained, rich in iron, and suitable for various crops with proper fertilization.\n";
            cout << "Kharif Crops: Cotton, Millets, Pulses, Soybean\n";
            cout << "Rabi Crops  : Wheat, Barley, Gram, Mustard\n";
            cout << "Zaid Crops  : Watermelon, Muskmelon, Cucumber\n";
        }
        else if (Typeofsoil == "Black" || Typeofsoil == "black")
        {
            cout << "Black soil is also known as regur soil. It retains moisture and is ideal for cotton farming.\n";
            cout << "Kharif Crops: Cotton, Sorghum, Pearl Millet\n";
            cout << "Rabi Crops  : Wheat, Linseed, Virginia Tobacco\n";
            cout << "Zaid Crops  : Watermelon, Muskmelon, Cucumber\n";
        }
        else if (Typeofsoil == "Desert" || Typeofsoil == "desert")
        {
            cout << "Desert soil, or arid soil, is sandy with low organic matter, suited for drought-resistant crops.\n";
            cout << "Kharif Crops: Cluster Bean, Moth Bean, Sesame\n";
            cout << "Rabi Crops  : Barley, Mustard, Chickpea\n";
            cout << "Zaid Crops  : Onion and Garlic, Chillies, Cucumber\n";
        }
        else if(Typeofsoil == "Forest" || Typeofsoil == "forest")
        {
            cout << "Forest soil forms under dense vegetation in high-rainfall areas.\n";
            cout << "Kharif Crops: Maize, Paddy, Ragi\n";
            cout << "Rabi Crops  : Wheat, Barley\n";
            cout << "Zaid Crops  : Muskmelon, Watermelon, Tomato\n";
        }
        else{
            cout<<"Err ! please enter valid soil type\n";
        }
        cout << "\nCrop recommendation completed based on your input.\n";
        cout << "-------------------------------------------------------------------------------\n";
    }
};
class Recordkeeper
{
    
    //Keeping all the details of farmer in this class 
protected:
    struct FarmerRecord
    {
        string farmerName;
        string cropName;
        float area;
        float expectedYield;
        string season;
        double price;
        string region;
        double seedcost;
        double fertilizercost;
        double pesticidecost;
        double labourcost;
    };

    FarmerRecord records[100];
    int recordCount = 0;
    double Totalcost = 0;

public:
    void AddRecords()
    {
        cin.ignore();
        cout << "---------------------------------------------------------------------\n";
        cout << "                    FARMER RECORD KEEPER MODULE                      \n";
        cout << "---------------------------------------------------------------------\n";

        // Clear input buffer before taking getline input

        cout << "Enter the name of the farmer: ";
        getline(cin, records[recordCount].farmerName);

        cout << "Enter the region (state) in which you are contributing in farming: ";
        getline(cin, records[recordCount].region);

        cout << "Enter the name of the crop: ";
        getline(cin, records[recordCount].cropName);

        cout << "Enter the season in which the crop was harvested: ";
        getline(cin, records[recordCount].season);

        cout << "Enter the seed cost for your crop (Rs.): ";
        cin >> records[recordCount].seedcost;

        cout << "Enter the labour cost for your crop (Rs.): ";
        cin >> records[recordCount].labourcost;

        cout << "Enter the fertilizer cost for your crop (Rs.): ";
        cin >> records[recordCount].fertilizercost;

        cout << "Enter the pesticide cost for your crop (Rs.): ";
        cin >> records[recordCount].pesticidecost;

        cout << "Enter the area of land (in acres or hectares): ";
        cin >> records[recordCount].area;

        cout << "Enter the expected yield (in Kg): ";
        cin >> records[recordCount].expectedYield;

        cout << "Enter the expected price per Kg (Rs.): ";
        cin >> records[recordCount].price;

        // Save to file
        string filename = "data_" + records[recordCount].farmerName + ".txt";
        ofstream fout(filename, ios::app);

        if (fout)
        {
            fout << "------ Farmer Record Keeper ------" << endl;
            fout << "Farmer Name      : " << records[recordCount].farmerName << endl;
            fout << "Region (State)   : " << records[recordCount].region << endl;
            fout << "Crop             : " << records[recordCount].cropName << endl;
            fout << "Season           : " << records[recordCount].season << endl;
            fout << "Seed Cost        : Rs" << records[recordCount].seedcost << endl;
            fout << "Labour Cost      : Rs" << records[recordCount].labourcost << endl;
            fout << "Fertilizer Cost  : Rs" << records[recordCount].fertilizercost << endl;
            fout << "Pesticide Cost   : Rs" << records[recordCount].pesticidecost << endl;
            fout << "Land Area        : " << records[recordCount].area << " acres" << endl;
            fout << "----------------------------------" << endl;
            fout.close();
            cout << "Record saved to file: " << filename << endl;
        }
        //Exceptional handling used to detect,catch and throw error
        try
        {

            if (!fout)
            {
                throw runtime_error("Could not open file to save farmer record.");
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }

        recordCount++;
    }
    void ShowRecords()
    {
        system("CLS");
//Displaying records of farmer
        cout << "\n------ Farmer Records ------\n";
        cout << left
             << setw(15) << "Farmer"
             << setw(15) << "Region"
             << setw(15) << "Crop"
             << setw(12) << "Seed Cost"
             << setw(13) << "Labour Cost"
             << setw(17) << "Fertilizer Cost"
             << setw(17) << "Pesticide Cost"
             << setw(12) << "Season"
             << setw(10) << "Area"
             << setw(10) << "Yield"
             << setw(10) << "Price"
             << setw(15) << "Total Cost"
             << endl;

        cout << string(171, '-') << endl;

        for (int i = 0; i < recordCount; i++)
        {
            double Totalcost = records[i].seedcost + records[i].labourcost +
                               records[i].fertilizercost + records[i].pesticidecost;

            cout << left
                 << setw(15) << records[i].farmerName
                 << setw(15) << records[i].region
                 << setw(15) << records[i].cropName
                 << setw(12) << records[i].seedcost
                 << setw(13) << records[i].labourcost
                 << setw(17) << records[i].fertilizercost
                 << setw(17) << records[i].pesticidecost
                 << setw(12) << records[i].season
                 << setw(10) << records[i].area
                 << setw(10) << records[i].expectedYield
                 << setw(10) << records[i].price
                 << setw(15) << Totalcost
                 << endl;
        }
    }
    void SearchByCrop(string crop)
    {
        bool found = false;
        cout << "\n------ Farmers Growing Crop: " << crop << " ------\n";

        for (int i = 0; i < recordCount; i++)
        {
            if (records[i].cropName == crop)
            {
                cout << "Farmer Name : " << records[i].farmerName << endl;
                cout << "Region      : " << records[i].region << endl;
                cout << "Season      : " << records[i].season << endl;
                cout << "Area        : " << records[i].area << " acres" << endl;
                cout << "Yield       : " << records[i].expectedYield << " Kg" << endl;
                cout << "Price       : Rs. " << records[i].price << " per Kg\n";
                cout << "------------------------------------------\n";
                found = true;
            }
        }

        try
        {
            if (!found)
                throw runtime_error("No farmers found growing: " + crop);
        }
        catch (const exception &e)
        {
            cout << "Search Error: " << e.what() << endl;
        }
    }

    void UpdateCropQuantity()
    {
        cin.ignore();
        string farmer, crop;
        cout << endl
             << "Enter farmer's name: ";
        getline(cin, farmer);
        cout << "Enter crop name to update yield: ";
        getline(cin, crop);

        bool found = false;
        for (int i = 0; i < recordCount; i++)
        {
            if (records[i].farmerName == farmer && records[i].cropName == crop)
            {
                cout << "Current yield: " << records[i].expectedYield << "Kg" << endl;
                cout << "Enter new yield (in Kg): ";
                cin >> records[i].expectedYield;
                cout << "Yield updated successfully." << endl;
                found = true;
                break;
            }
        }
        try
        {
            if (!found)
                throw runtime_error("Error! Crop not found\n");
        }
        catch (const exception &e)
        {
            cout << "Search Error: " << e.what() << endl;
        }
    }
};
class ProfitEstimator : public Recordkeeper
{
    //Inheriting Profit estimator class from record keeper to estimate profit of farmer on basis of their total cost and revenue making access public to use protected variables
protected:
    double Marketprice;
    double yield;

public:
    void EstimateProfit()
    {system("CLS");
        string farmer;
        cout << "------PROFIT ESTIMATOR------\n";
        cout << "Enter the farmer's name for profit estimation: ";
        getline(cin, farmer);

        bool flag = false;

        for (int i = 0; i < recordCount; i++)
        {
            if (records[i].farmerName == farmer)
            {
                flag = true;

                cout << "Enter the market price of your crop (" << records[i].cropName << ") per Kg: ";
                cin >> Marketprice;

                cout << "Enter your expected yield (in Kg): ";
                cin >> yield;

                double revenue = Marketprice * yield;
                double cost = records[i].seedcost + records[i].labourcost + records[i].fertilizercost + records[i].pesticidecost;
                double profit = revenue - cost;

                cout << "\n------RESULT------\n";
                cout << "Total Revenue: Rs" << revenue << endl;
                cout << "Total Cost: Rs" << cost << endl;
                cout << "Estimated Profit: RS" << profit << endl;
//Making a new text file with farmer name to store profit of farmer
                string filename = "profit_" + records[i].farmerName + ".txt";
//Exceptional handling
                try
                {
                    ofstream fout(filename, ios::app);
                    if (!fout)
                    {
                        throw runtime_error("Error! Could not open file: " + filename);
                    }

                    fout << "Farmer Name: " << records[i].farmerName << endl;
                    fout << "Crop: " << records[i].cropName << endl;
                    fout << "Market Price: Rs" << Marketprice << " per Kg\n";
                    fout << "Expected Yield: " << yield << " Kg\n";
                    fout << "Total Cost: Rs" << cost << "\n";
                    fout << "Revenue: Rs" << revenue << "\n";
                    fout << "Estimated Profit: Rs" << profit << "\n";
                    fout << "-----------------------------\n";

                    fout.close();
                    cout << "Profit details saved to file: " << filename << endl;
                }
                catch (const exception &e)
                {
                    cout << "File Error: " << e.what() << endl;
                }

                break;
            }
        }

        try
        {
            if (!flag)
                throw runtime_error("No farmer record found with name: " + farmer);
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
};
class CropProblemDiagnosis : public Recordkeeper
{
    //Inheriting cropProblemDiagnosis from RecordKeeper keeping access public to use protected variables
public:
    void diagnoseProblem()
    {
        int choice;

        cout << "\n--- Crop Problem Diagnosis ---\n";
        cout << "Select the problem you are facing:\n";
        cout << "1. Yellowing of leaves\n";
        cout << "2. Wilting of plants\n";
        cout << "3. Pest attack\n";
        cout << "4. Stunted growth\n";
        cout << "5. Leaf spots\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        cout << "\nDiagnosis and Solution:\n";

        if (choice == 1)
        {
            cout << "Problem: Yellowing of Leaves\n";
            cout << "Explanation:\n";
            cout << "- Yellowing (chlorosis) happens when the green pigment (chlorophyll) breaks down.\n";
            cout << "- Common causes include:\n";
            cout << "  1. Nitrogen deficiency.\n";
            cout << "  2. Overwatering or underwatering.\n";
            cout << "  3. Poor soil drainage.\n";
            cout << "  4. Pests like aphids or diseases.\n";
            cout << "  5. Soil pH imbalance (affecting nutrient absorption).\n";
            cout << "Solution:\n";
            cout << "- Apply nitrogen-rich fertilizers like urea or ammonium nitrate.\n";
            cout << "- Adjust irrigation — neither too much nor too little.\n";
            cout << "- Improve drainage using raised beds or loosening compact soil.\n";
            cout << "- Use pest control if insects are seen.\n";
            cout << "- Test and adjust soil pH (ideal: 6.0-7.5).\n";
        }
        else if (choice == 2)
        {
            cout << "Problem: Wilting of Plants\n";
            cout << "Explanation:\n";
            cout << "- Wilting means plants are limp or drooping.\n";
            cout << "- Main causes include:\n";
            cout << "  1. Water stress — both excess and lack.\n";
            cout << "  2. Root rot due to overwatering or fungal infection.\n";
            cout << "  3. Hot weather and transpiration loss.\n";
            cout << "Solution:\n";
            cout << "- Ensure consistent but not excessive watering.\n";
            cout << "- Improve soil drainage to prevent fungal root rot.\n";
            cout << "- Apply fungicides if fungal infection is suspected (e.g., copper oxychloride).\n";
            cout << "- Mulch the soil to reduce water loss during hot days.\n";
        }
        else if (choice == 3)
        {
            cout << "Problem: Pest Attack\n";
            cout << "Explanation:\n";
            cout << "- Pests such as aphids, whiteflies, borers damage leaves, stems, and roots.\n";
            cout << "- They cause stunted growth, curled leaves, holes, or yellowing.\n";
            cout << "Solution:\n";
            cout << "- Use organic pesticides (e.g., neem oil) or recommended insecticides like imidacloprid.\n";
            cout << "- Introduce natural predators like ladybugs.\n";
            cout << "- Practice crop rotation and clean field practices.\n";
            cout << "- Avoid overcrowding of plants for better air circulation.\n";
        }
        else if (choice == 4)
        {
            cout << "Problem: Stunted Growth\n";
            cout << "Explanation:\n";
            cout << "- Stunted growth means the plant is smaller or weaker than expected.\n";
            cout << "- Causes include:\n";
            cout << "  1. Poor soil nutrition (NPK imbalance).\n";
            cout << "  2. Pests or disease attacking roots or stems.\n";
            cout << "  3. Waterlogging or drought.\n";
            cout << "Solution:\n";
            cout << "- Apply balanced fertilizers (containing nitrogen, phosphorus, potassium).\n";
            cout << "- Check for and treat pest infestation.\n";
            cout << "- Ensure soil drains well and irrigation is regulated.\n";
            cout << "- Use quality seeds and avoid overcrowding.\n";
        }
        else if (choice == 5)
        {
            cout << "Problem: Leaf Spots\n";
            cout << "Explanation:\n";
            cout << "- Leaf spots are dark or discolored patches caused by fungal or bacterial diseases.\n";
            cout << "- They spread rapidly in humid or wet conditions.\n";
            cout << "Solution:\n";
            cout << "- Remove and destroy affected leaves.\n";
            cout << "- Spray with fungicides like mancozeb or carbendazim.\n";
            cout << "- Water plants at the base to avoid wetting the leaves.\n";
            cout << "- Maintain good spacing between plants for air flow.\n";
        }
        else
        {
            cout << "Invalid choice. Please select a valid problem number (1-5).\n";
        }
    }
};

class LoanAwarnessGuide
{
public:
//Helping the farmers and creating awarness among them about the loan provided by government
    void showAvailableloans()
    {
        int choice;
        cout << "\n---------------------------------- LOAN AWARENESS FOR FARMERS ----------------------------------\n";
        cout << "Choose the type of loan you are interested in:\n";
        cout << "1. Crop Loan\n2. Equipment Loan\n3. Irrigation Loan\n4. Land Development Loan\n5. Animal Husbandry Loan\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nCrop Loan:\n";
            cout << "  - Purpose     : To buy seeds, fertilizers, pesticides, and cover cultivation costs.\n";
            cout << "  - Eligibility : Land-owning farmers or tenant farmers.\n";
            cout << "  - Application : Apply through local banks or cooperative societies.\n";
            cout << "  - Documents   : Land documents, Aadhaar card, bank passbook.\n";
            break;
        case 2:
            cout << "\nEquipment Loan:\n";
            cout << "  - Purpose     : For buying farm machinery like tractors and sprayers.\n";
            cout << "  - Eligibility : Farmers with valid land documents.\n";
            cout << "  - Application : Apply at government-approved banks or online portals.\n";
            cout << "  - Documents   : Equipment quotation, ID proof, land proof.\n";
            break;
        case 3:
            cout << "\nIrrigation Loan:\n";
            cout << "  - Purpose     : To install borewells, pipelines, or drip irrigation.\n";
            cout << "  - Eligibility : Farmers needing irrigation systems for their fields.\n";
            cout << "  - Application : Via rural bank branches or NABARD schemes.\n";
            cout << "  - Documents   : Irrigation layout, land documents, ID proof.\n";
            break;
        case 4:
            cout << "\nLand Development Loan:\n";
            cout << "  - Purpose     : For soil improvement, fencing, leveling, or bunding.\n";
            cout << "  - Eligibility : Farmers with undeveloped or uneven land.\n";
            cout << "  - Application : Through land development banks or cooperative societies.\n";
            cout << "  - Documents   : Work estimate, land papers, ID proof.\n";
            break;
        case 5:
            cout << "\nAnimal Husbandry Loan:\n";
            cout << "  - Purpose     : For dairy, poultry, or purchasing livestock.\n";
            cout << "  - Eligibility : Farmers involved in or planning animal farming.\n";
            cout << "  - Application : Apply through NABARD-linked rural banks.\n";
            cout << "  - Documents   : Purchase plan, ID proof, income details.\n";
            break;
        default:
            cout << "\nInvalid choice. Please select a valid option (1-5).\n";
        }

        cout << "\nNote: Interest rates, repayment terms, and subsidies vary by bank and scheme.\n";
        cout << "Visit your local bank or Krishi Vigyan Kendra for personalized support.\n";
    }
};

class ContactInfo
{
public:
//Helping farmers to reach government in case if they have any problem
    void ShowContactInfo()
    {
        cout << "\n---------------------------- FARMER HELP CENTRE CONTACT INFORMATION ----------------------------\n";

        cout << "\n1. Krishi Vigyan Kendra (KVK):\n";
        cout << "   - Usefulness : Provides field-level agricultural advisory, training, and demonstration.\n";
        cout << "   - Contact    : Visit your nearest KVK or visit www.kvkindia.gov.in\n";
        cout << "   - Phone      : 1800-180-1552\n";

        cout << "\n2. Agricultural Officer (District Level):\n";
        cout << "   - Usefulness : Assists in crop planning, fertilizer recommendations, soil testing, and subsidy schemes.\n";
        cout << "   - Contact    : Visit the local agricultural department office.\n";
        cout << "   - Phone      : 1800-180-1551\n";

        cout << "\n3. NABARD (National Bank for Agriculture and Rural Development):\n";
        cout << "   - Usefulness : Provides financial assistance for farm loans, irrigation projects, and rural development.\n";
        cout << "   - Website    : www.nabard.org\n";
        cout << "   - Phone      : 1800-222-522\n";

        cout << "\n4. PM Kisan Samman Nidhi Yojana Helpline:\n";
        cout << "   - Usefulness : For queries related to direct income support (₹6000/year) to eligible farmers.\n";
        cout << "   - Website    : pmkisan.gov.in\n";
        cout << "   - Phone      : 155261 or 011-24300606\n";

        cout << "\n5. Kisan Call Centre (KCC):\n";
        cout << "   - Usefulness : Toll-free 24x7 helpline for expert advice on agriculture and allied sectors.\n";
        cout << "   - Phone      : 1800-180-1551 (in local language)\n";

        cout << "\n6. Agricultural Loan Helpline:\n";
        cout << "   - Usefulness : For queries on how to apply for farm loans, eligibility, and documents.\n";
        cout << "   - Email      : loanhelp@agri.gov.in\n";
        cout << "   - Phone      : 1800-123-4567\n";

        cout << "\n7. State Agriculture Department Helpline:\n";
        cout << "   - Usefulness : Provides state-specific support for agriculture, schemes, and subsidies.\n";
        cout << "   - Contact    : Find your state's helpline number through the state agriculture department website.\n";
        cout << "   - Phone      : Varies by state.\n";

        cout << "\n8. Weather and Crop Advisory Helpline:\n";
        cout << "   - Usefulness : For weather forecasts, pest management, and crop disease advisories.\n";
        cout << "   - Phone      : 1800-425-1098 (ICAR)\n";
        cout << "   - Website    : agromet.imd.gov.in\n";

        cout << "\n9. Soil Health Management Helpline:\n";
        cout << "   - Usefulness : Assistance in soil testing, soil health reports, and improvement techniques.\n";
        cout << "   - Phone      : 1800-180-4311\n";
        cout << "   - Website    : soilhealth.dac.gov.in\n";

        cout << "\n10. Fertilizer Advisory Helpline:\n";
        cout << "    - Usefulness : For guidance on the correct use of fertilizers, types, and applications.\n";
        cout << "    - Phone      : 1800-180-1551\n";
        cout << "    - Email      : fertilizers@agri.gov.in\n";

        cout << "\n11. Farmer Welfare Helpline:\n";
        cout << "    - Usefulness : For information on welfare programs for farmers, insurance, and financial support.\n";
        cout << "    - Phone      : 1800-11-2366\n";
        cout << "    - Website    : www.farmerswelfare.gov.in\n";

        cout << "\n--------------------------------------------------------------------------------------------------\n";
        cout << "Tip: Farmers can also visit nearest Krishi Seva Kendra, Cooperative Banks, and Rural Banks for more details.\n";
        cout << "For any emergency situations related to agriculture, reach out to the nearest agricultural office or support center.\n";
        cout << "\n--------------------------------------------------------------------------------------------------\n";
    }
};

int main()
{
    const int MAX_SESSIONS = 10;//Setting max sessions using array
    ProfitEstimator system[MAX_SESSIONS];
    CropDetermination cropInfo[MAX_SESSIONS];
    CropProblemDiagnosis diagnosis[MAX_SESSIONS];
    int currentSession = 0; //intializing current session as zero

    int choice;
    do
    {
        cout << "\n================= Crop Management System Menu =================\n";
        cout << "Session #" << (currentSession + 1) << "\n";
        cout << "1. Crop Determination based on Soil and Season\n";
        cout << "2. Add Farmer Record\n";
        cout << "3. Display All Farmer Records\n";
        cout << "4. Search Farmers by Crop\n";
        cout << "5. Update Crop Quantity (Yield)\n";
        cout << "6. Estimate Profit for a Farmer\n";
        cout << "7. Diagnose Crop Problem\n";
        cout << "8. Loan Awareness Guide\n";
        cout << "9. Help Center Contacts\n";
        cout << "10. Switch Session\n";

        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cropInfo[currentSession].Takeinput();
            break;
        case 2:
            system[currentSession].AddRecords();
            break;
        case 3:
            system[currentSession].ShowRecords();
            break;
        case 4:
        {
            cin.ignore();
            string cropName;
            cout << "Enter crop name to search for: ";
            getline(cin, cropName);
            system[currentSession].SearchByCrop(cropName);
            break;
        }
        case 5:
            system[currentSession].UpdateCropQuantity();
            break;
        case 6:
            cin.ignore();
            system[currentSession].EstimateProfit();
            break;
        case 7:
            diagnosis[currentSession].diagnoseProblem();
            break;
        case 8:
        {
            LoanAwarnessGuide loan;
            loan.showAvailableloans();
            break;
        }
        case 9:
        {
            ContactInfo help;
            help.ShowContactInfo();
            break;
        }
        case 10:
            if (currentSession < MAX_SESSIONS - 1)
            {
                currentSession++;
                cout << "Switched to Session #" << (currentSession + 1) << endl;
            }
            else
            {
                cout << "Maximum sessions reached.\n";
            }
            break;
        case 0:
            cout << "Exiting Crop Management System. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
