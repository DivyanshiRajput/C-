#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#include "Goods.h"
#include "Perishable.h"
#include "Stationary.h"
#include "Clothes.h"

int main() {

    vector<string> logs;
    vector<string> out;
    string input, temp;

    getline(cin, input);

    stringstream ss(input);

    while (getline(ss,temp,' '))
    {
        //splitting with spaces
        logs.push_back(temp);
        // this will have all the logs
    }

    vector<Perishable> perishables;
    vector<Clothes> clothes;
    vector<Stationary> stationaries;

    while(!logs.empty())
    {
        vector<string> arr;
        stringstream ss(logs[0]);

        while (getline(ss,temp,','))
        {
            //splitting with spaces
            arr.push_back(temp);
            // this will have all the logs details
        }

        if(arr[1] == "A")
        {
            int day = stoi(arr[0]);
            string type = arr[2];
            if(type == "P"){
                int quan = stoi(arr[3]);
                Perishable p(quan, 10, 30);
                perishables.push_back(p);
                // make P object
            }

            else if(type == "S")
            {
                int quan = stoi(arr[4]);
                if(arr[3] == "B")
                {
                    int len = stoi(arr[5]);
                    // make S object with Binding
                    Stationary s(quan, 300, len, true);
                    stationaries.push_back(s);

                }
                else if(arr[3] == "NB")
                {
                    Stationary s(quan, 300, 0, false);
                    stationaries.push_back(s);
                    // make S object with without Binding
                }
            }

            else if(type == "C")
            {
                int quan = stoi(arr[3]);
                // make C object
                Clothes c(quan, 500);
                clothes.push_back(c);
            }

        }

        else if(arr[1] == "O")
        {
            out.push_back(logs[0]);
        }
        logs.erase(logs.begin()) ;
    }

    int total = 0;


    while(!out.empty())
    {

      vector<string> arr;
      stringstream ss(out[0]);

      while (getline(ss,temp,','))
      {
          //splitting with spaces
          arr.push_back(temp);
          // this will have all the logs details
      }

      int day = stoi(arr[0]);
      string type = arr[2] ;

      if(type == "P")
      {
          int quan = stoi(arr[3]);
          //removing inventory of type P
          if (quan <= perishables[0].getQuantity())
          {
            total += quan * 10;
            if (quan == perishables[0].getQuantity())
            {
              perishables.erase(perishables.begin());
            }
            else
            {
              perishables[0].setQuantity(perishables[0].getQuantity() - quan);
            }
          }

          else
          {
            total += perishables[0].getQuantity() * 10;
            perishables.erase(perishables.begin());
          }

      }

      else if(type == "S")
      {
        int quan = stoi(arr[3]);
        cout << quan ;

        if(arr[3] == "B")
        {
          cout << "inBind" ;
          // removing inventory of type SB
          if (quan <= stationaries[0].getQuantity())
          {
            total += (quan * 300) + 100*stationaries[0].length ;


            if (quan == stationaries[0].getQuantity())
            {
              stationaries.erase(stationaries.begin());
            }

            else
            {
              stationaries[0].setQuantity(stationaries[0].getQuantity() - quan);
            }
          }

          else
          {
            total += (stationaries[0].getQuantity() * 300) + (100 * stationaries[0].length);
            stationaries.erase(stationaries.begin());
          }

        }
        else if(arr[3] == "NB")
        {
          // removing inventory of type SNB
          if (quan <= stationaries[0].getQuantity())
          {
            total += quan * 300;
            if (stationaries[0].getQuantity() == quan)
            {
              stationaries.erase(stationaries.begin());
            }
            else
            {
              stationaries[0].setQuantity(stationaries[0].getQuantity() - quan);
            }
          }

          else
          {
            total += stationaries[0].getQuantity() * 300;
            stationaries.erase(stationaries.begin());
          }
        }
      }

      else if(type == "C")
      {
        int quan = stoi(arr[3]);
        // removing inventory of type C
        if (quan <= clothes[0].getQuantity())
        {
          total += quan * 500;
          if (clothes[0].getQuantity() == quan)
          {
            clothes.erase(clothes.begin());
          }
          else
          {
            clothes[0].setQuantity(clothes[0].getQuantity() - quan);
          }
        }

        else
        {
          total += clothes[0].getQuantity() * 500;
          clothes.erase(clothes.begin());
        }
      }

      out.erase(out.begin());
    }

    cout << total << endl;

    return 0;
}
