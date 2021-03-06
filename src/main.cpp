
#include "C:\\Users\\suyda\\GitHub\\Laundry-Board-Project\\src\\laundryBackend.cpp"
#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <set>
#include <map>
using namespace std;


void thresHolds(double, double);
vector<int> comprehend(string userInput);



int main()
{
    //Read in the users file

    string path = "C:\\Users\\suyda\\GitHub\\Laundry-Board-Project\\src\\fullInput.txt";
    ifstream inputFile(path);

    int n = 0;
    inputFile >> n;
    //AVLTree laundryTree;
    MapImplementation laundryMap;
    //SetImplementation laundrySet;
    for (int i = 0; i < n; i++)
    {
        // read in the next line and parse it into a constructor for a user node
        string firstName = "";
        string lastName = "";
        string fullName = "";
        string phone = "";
        string gatorID = "";
        string room = "";

        inputFile >> gatorID;
        inputFile >> firstName;
        inputFile >> lastName;
        inputFile >> room;
        inputFile >> phone;

        int gator1ID = stoi(gatorID);
        int roomNum = stoi(room);
        long phoneNum = 0;
        fullName = firstName + " " + lastName;
        
        // push that to the tree
        // laundryTree.setRoot(laundryTree.insertFromFile(laundryTree.getRoot(), gator1ID, fullName, phoneNum, roomNum));

        // push that to the map
        MapImplementation::MapUser newMapUser(gator1ID, fullName, phoneNum, roomNum);
        laundryMap.map.emplace(gator1ID, newMapUser);

        // push that to the set
       // SetImplementation::SetUser newSetUser(gator1ID, fullName, phoneNum, roomNum);
       // laundrySet.mset.emplace(i, newSetUser);

        
    }

    //Main Variables
    string userInput;
    bool running = true;
    vector<double> AVLInfo(5, 0.0);
    vector<double> mapInfo(5, 0.0);
    vector<double> setInfo(5, 0.0);
    
    while (running)
    {
        getline(cin,userInput);
        vector<int> commands = comprehend(userInput);
        int command = commands.at(0);
        switch (command)
        {
        case 1:
        {
            //AVLInfo.at(0) = totalAverageWashing(laundryTree.getRoot());
            mapInfo.at(0) = laundryMap.totalAverageWashing();
           // setInfo.at(0) = laundrySet.totalAverageWashing();
            break;
        }
        case 2:
        {
            //AVLInfo.at(1) = totalAverageDrying(laundryTree.getRoot());
            mapInfo.at(1) = laundryMap.totalAverageDrying();
            //setInfo.at(1) = laundrySet.totalAverageDrying();
            break;
        }
        case 3:
        {
            //User average washing

            //Get the gatorID of the user you want to find
            int userToFind = commands.at(1);

            //Get all of the nodes in the tree
            //vector<AVLTree::UserNode*> nodes = laundryTree.inorderTraversal(laundryTree.getRoot(), 0);
            //AVLTree::UserNode* avlUserToCalc = nullptr;

            //get all of the nodes in the map
            MapImplementation::MapUser mapUserToCalc = laundryMap.map.at(userToFind);
            vector<MapImplementation::MapUser> toAddSessionsTo = {mapUserToCalc};
            laundryMap.generate20Sesh(toAddSessionsTo);
            mapUserToCalc = toAddSessionsTo.at(0);
            int thisUserAverageWash = mapUserToCalc.userAverageWashing();
            cout << thisUserAverageWash;
            //Get all of the nodes in the set
            //vector<SetImplementation::SetUser*> setUsers = laundrySet.generateSetVector();
            //SetImplementation::SetUser* setUserToCalc = nullptr;
            /*for (int i = 0; i < setUsers.size(); i++)
            {
                if(setUsers.at(i)->getGator1ID() == userToFind)
                {
                    setUserToCalc = setUsers.at(i);
                }
            }
            if(setUserToCalc != nullptr)
            {
                setUserToCalc->setWashAverage(setUserToCalc->userAverageWashing());
            }
            else
            {
                cout << "ERRRIRRRAGJKRGkenrgvabjlaejlaj" <<endl;
            }*/

            //find the node that you want to calculate if it exists;
            // for (int i = 0; i < nodes.size(); i++)
            // {
            //     if(nodes.at(i)->getGator1ID() == userToFind)
            //     {
            //         avlUserToCalc = nodes.at(i);
            //     }
            // }
            // if(avlUserToCalc != nullptr)
            // {
            //     avlUserToCalc->setWashAverage(avlUserToCalc->userAverageWashing(avlUserToCalc));
            // }
            // else
            // {
            //     cout << "ERRRIRRRAGJKRGkenrgvabjlaejlaj" <<endl;
            // }
            
            break;
        }

        case 4:
        {
            //User average drying

            //Get the gatorID of the user you want to find
            int userToFind = commands.at(1);

            //Get all of the nodes in the tree
            //vector<AVLTree::UserNode*> nodes = laundryTree.inorderTraversal(laundryTree.getRoot(), 0);
            //AVLTree::UserNode* avlUserToCalc = nullptr;

            //get all of the nodes in the map
            MapImplementation::MapUser mapUserToCalc = laundryMap.map.at(userToFind);
            vector<MapImplementation::MapUser> toAddSessionsTo = {mapUserToCalc};
            laundryMap.generate20Sesh(toAddSessionsTo);
            mapUserToCalc = toAddSessionsTo.at(0);
            int thisUserAverageDry = mapUserToCalc.userAverageDrying();
            cout << thisUserAverageDry;
            //Get all of the nodes in the set
            //vector<SetImplementation::SetUser*> setUsers = laundrySet.generateSetVector();
            /*SetImplementation::SetUser* setUserToCalc = nullptr;
            for (int i = 0; i < setUsers.size(); i++)
            {
                if(setUsers.at(i)->getGator1ID() == userToFind)
                {
                    setUserToCalc = setUsers.at(i);
                }
            }
            if(setUserToCalc != nullptr)
            {
                setUserToCalc->setWashAverage(setUserToCalc->userAverageWashing());
            }
            else
            {
                cout << "ERRRIRRRAGJKRGkenrgvabjlaejlaj" <<endl;
            }*/


            //find the node that you want to calculate if it exists;
            // for (int i = 0; i < nodes.size(); i++)
            // {
            //     if(nodes.at(i)->getGator1ID() == userToFind)
            //     {
            //         userToCalc = nodes.at(i);
            //     }
            // }
            // if(userToCalc != nullptr)
            // {
            //     userToCalc->setDryAverage(userToCalc->userAverageDrying(userToCalc));
            // }
            // else
            // {
            //     cout << "ERRRIRRRAGJKRGkenrgvabjlaejlaj" <<endl;
            // }
            break;
        }
        case 5:
        {
            // vector<int> stuff = laundryTree.inorderTraversal(laundryTree.getRoot());
            // vector<int> washingTimes = inorderTraversalWashingTimes(laundryTree.getRoot());
            // vector<int> dryingTimes = inorderTraversalDrying(laundryTree.getRoot());
            mapInfo.at(0) = laundryMap.totalAverageWashing();
            mapInfo.at(1) = laundryMap.totalAverageDrying();
            thresHolds(mapInfo.at(0), mapInfo.at(1));
            break;
        }

        default:
            break;
        }



    }
    return 0;
}


vector<int> comprehend(string userInput)
{
    if(userInput.compare("Wash average")==0)
    {
        return {1};
    }
    if(userInput.compare("Dry average")==0)
    {
        return {2};
    }
    if(userInput.compare("Wash average - user")==0)
    {
        int userToFind = 0;
        cin >> userToFind;
        return {3, userToFind};
        
    }
    if(userInput.compare("Dry average - user")==0)
    {
        int userToFind = 0;
        cin >> userToFind;
        return {4, userToFind};
    }
    if(userInput.compare("Thresholds")==0)
    {
        return {5};
    }

    return {};
}

void thresHolds(double washing, double drying)
{
    ///24 hours ==bad
    //Green 2 hrs
    //Yellow 4 hrs
    //Red >4 hrs
    
    double avg= (washing+drying)/2;
    //drying
    if(drying<=2.0)
    {
        cout<<"Total Average Dryer use time is within GREEN threshold"<<endl;
    }
    if(drying>2.0&&drying<=4.0)
    {
        cout<<"Total Average Dryer use time is within YELLOW threshold"<<endl;
    }
    if(drying>4.0)
    {
        cout<<"Total Average Dryer use time is within RED threshold" << endl;
    }
    //washing
    if(washing<=2.0)
    {
        cout<<"Total Average Washing use time is within GREEN threshold" << endl; 
    }
    if(washing>2.0&&washing<=4.0)
    {
        cout<<"Total Average Washing use time is within YELLOW threshold" << endl; 
    }
    if(washing>4.0)
    {
        cout<<"Total Average Washing use time is within RED threshold" << endl; 
    }


    if(avg<=2.0)
    {
        cout<<"Total Average use time is within GREEN threshold"<<endl;
    }
    if(avg>2.0&&avg<=4.0)
    {
        cout<<"Total Average use time is within YELLOW threshold"<<endl;
    }
    if(avg>4.0)
    {
        cout<<"Total Average use time is within RED threshold"<<endl;
    }
    



}

