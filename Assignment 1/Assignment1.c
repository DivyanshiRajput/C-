#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void normalize(int n, float v[n]) //function for normalizing the vector
{
  float sum = 0;
  for (int i = 0; i < n; i++) //calculates sum of all the components of the vector
  {
    sum += v[i];
  }

  for (int i = 0; i < n; i++) //normalizing the vector
  {
    v[i] = v[i]/sum;
  }
}


float euclideanDistance(int n, float v1[n], float v2[n]) //function for calculating euclidean distance
{
  float sum = 0; //stores the sum of squares of the difference of each component
  double result;
  for (int i = 0; i < n; i++) //loop for calculating sum
  {
    sum += pow(v2[i]-v1[i], 2); //calculates square of the term and add it to sum
  }
  result = sqrt(sum); //sqrt function for calculating root of sum

  return result;
}


float manhattanDistance(int n, float v1[n], float v2[n]) //function for calculating manhattan distance
{
  float sum = 0;//stores ans i.e. the sum of absolute value of the difference of each component
  for (int i = 0; i < n; i++) //loop for calculating sum
  {
    sum += fabs(v2[i]-v1[i]); //using fabs function for calculating absolute of difference
  }

  return sum;
}


float chebyshevDistance(int n, float v1[n], float v2[n]) //function for calculating chebyshev distance
{
  float sum = v2[0] - v1[0]; //stores the answer which is the maximum of absolute difference between each component of the vectors
  for (int i = 1; i < n; i++) //updates sum according to the conditions
  {
     if (sum > (v2[i] - v1[i]))
     {
       continue;
     }
     else
     {
       sum = v2[i] - v1[i];
     }
  }

  return sum;
}


float klDivergence(int n, float v1[n], float v2[n]) //function for calculating K.L. divergence
{
  float sum = 0; //for storing sum of divergence of each component of the vector
  for (int i = 0; i < n; i++)
  {
    sum += v1[i] * log(v1[i]/v2[i]); //formula for calculating K.L. divergence
  }

  return sum;
}


float jsDistance (int n, float v1[n], float v2[n]) //function for calculating J.S. distance
{
  float m[n]; //average of both the vectors used to calculate J.S. divergence
  for (int i = 0; i < n; i++ )
  {
    m[i] = 0.5 * (v1[i] + v2[i]);
  }
  float ans = sqrt(0.5 * (klDivergence(n, v1, m) + klDivergence(n, v2, m))); //formula for calculating J.S. distance = sqrt(js divergence)

  return ans;
}


int main()
{
  char input[100];
  scanf("%[^\n]%*c", input); //taking input
  char* ptr;
  char* token = strtok_r(input, " ", &ptr); //function for splitting input string.
  int j = 0; //for keeping count of number of components in the string
  int n = atoi(token); //stores the size of the vector, used atoi to convert character to integer

  if(n <= 0)
  {
    printf("%d\n",-1);
    return 0;
  }

  float v1[n]; //array to store first vector
  float v2[n]; //array to store second vector
  while (token != NULL) //loop for iterating over the total input string
  {

    if (j == 1 && strcmp(token,"-1") != 0)
    {
      printf("%d\n",-1);
      return 0;
    }

    else if (j == 2) //condition for storing first vector using address obtained by split function
    {
      char v[50];
      char* ptr1;
      strcpy(v, token); //making copy of the first vector string
      int i = 0;
      char* vector1 = strtok_r(v, ",", &ptr1); //splitting it with delimeter ","
      while(vector1 != NULL)
      {
        v1[i] = atof(vector1); //storing each component as float
        if (v1[i] <= 0)
        {
          printf("%d\n",-1);
          return 0;
        }
        vector1 = strtok_r(NULL, ",", &ptr1); //upadating vector1
        i++;
      }
    }

    else if (j == 3 && strcmp(token,"-1") != 0)
    {
      printf("%d\n",-1);
      return 0;
    }

    else if (j == 4) //condition for storing second vector using address obtained by split function
    {
      char u[50];
      char* ptr1;
      strcpy(u, token); //making copy of the second vector string
      int i = 0;
      char* vector2 = strtok_r(token, ",", &ptr1); //using the same split function to split it with delimeter ","
      while(vector2 != NULL)
      {
        v2[i] = atof(vector2); //storing each component as float
        if (v2[i] <= 0)
        {
          printf("%d\n",-1);
          return 0;
        }
        vector2 = strtok_r(NULL, ",", &ptr1); //upadating vector2
        i++;
      }
    }

    else if (j == 5 && strcmp(token,"-1") != 0)
    {
      printf("%d\n",-1);
      return 0;
    }

    token = strtok_r(NULL, " ", &ptr); //updating token for the outer while loop
    j++;
  }

  if (j < 6)
  {
    printf("%d\n",-1);
    return 0;
  }

  normalize(n, v1); //normalizing first vector
  normalize(n, v2); //normalizing second vector
  printf("%0.4f,", manhattanDistance(n, v1, v2)); //printing manhattan distance
  printf("%0.4f,", euclideanDistance(n, v1, v2)); //printing euclidean distance
  printf("%0.4f,", chebyshevDistance(n, v1, v2)); //printing chebyshev distance
  float kl1 = klDivergence(n, v1, v2);
  float kl2 = klDivergence(n, v2, v1);
  printf("%0.4f,", (kl1 + kl2)); //printing K.L. divergence
  printf("%0.4f\n", jsDistance(n, v1, v2)); //printing J.S. distance

  return 0;
}

//4 -1 3.4,1.3,2.51,3.24 -1 4.3,2.4,3.210,4.20 -1
