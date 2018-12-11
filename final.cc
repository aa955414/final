//Final exam program
//Alyssa Atkinson
//December 11, 2018

#include "gtest/gtest.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <stdio.h>
#include <stdarg.h>
#include <fstream>

using namespace std;


 /// @function countChar counts number of characters
 /// @param char *pName
int countChar(char *pName)
{
              
  FILE *fp = fopen(pName,"r");
  int ch=0;
  int charact=0;

  if (fp == NULL)
  return 0;

  charact++;
  while(!feof(fp))
{
  ch = fgetc(fp);
  charact++;
}
  fclose(fp);
  cout << charact << " Characters" << endl;
  return charact;
}

 /// @function countLine counts number of lines
 /// @param char *pName
int countLine(char *pName)
{
  // count the number of lines in the file called filename                                    
  FILE *fp = fopen(pName,"r");
  int ch=0;
  int lines=0;

  if (fp == NULL)
  return 0;

  lines++;
  while(!feof(fp))
{
  ch = fgetc(fp);
  if(ch == '\n')
  {
    lines++;
  }
}
  fclose(fp);
  cout << lines << " Lines" << endl;
  return lines;
}
 

  TEST(CharCount, DogFile)
{
  EXPECT_EQ(14, countChar("file1.txt"));
}

  TEST(CharCount, CatFile)
{
  EXPECT_EQ(76, countChar("file2.txt"));
}

 TEST(CharCount, BunnyFile)
{
  EXPECT_EQ(28, countChar("file3.txt"));
  }

 /// @function main function to run counts
 /// @param int argc
 /// @param char *argv[]
int main(int argc, char *argv[])
{
  ifstream fi;
  ofstream fo;
  int i = 1;
  if (argc < 1)
    {
      fi.open("file4.txt");
    countLine("file4.txt");
    fo.close();
          fi.open("file5.txt");
  countChar("file5.txt");
  fo.close();
    }
  else
    {
    countLine(argv[i]);
    countChar(argv[i]);
    }
  
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}

