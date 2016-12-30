#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <dirent.h>
#include <time.h>       /* time */
#include <string>
#include <sstream>
//#define FONTS_DIR "~/2016/Workspace/brexia/Decembre/CodeSource/OCR-Contrat/Text2Image/Fonts"
//#define FONTS_DIR "/usr/share/fonts/truetype/msttcorefonts"
#define FONTS_DIR "/usr/share/fonts"
#define FONTS_FILE "./listfonts-out.txt"
#define DATA_DIR  "./data/"
using namespace std;
void createImage(string strFileTxt, string strFileImageOut, string strFontName, int iFontSize=12)
{
  string strCommand;
  string strFontsDir=FONTS_DIR;
  //char *intStr = itoa(iFontSize);
  stringstream ss;
  ss << iFontSize;
  string strFontSize = ss.str();
  
  strCommand="text2image --text="+strFileTxt+" --outputbase="+strFileImageOut+" --font='"+ strFontName+ "'"  + " --degrade_image=true --exposure=-8 --underline_start_prob=0.5 --fonts_dir="+strFontsDir+" ";
  //strCommand="text2image --text="+strFileTxt+" --outputbase="+strFileImageOut+" --font='"+ strFontName+ "'" + " --ptsize =" + strFontSize + " --degrade_image=true --exposure=-8 --underline_start_prob=0.5 --fonts_dir="+strFontsDir;
  
  //cout <<strCommand<<endl;
  char command[256];
  string st="--ptsize=%i";
  st=strCommand+st;
  //const char *cstr = strCommand.c_str();
  const char *cstr = st.c_str();
  string strCleanCommand;
  strCleanCommand="mv out* ./result/";
  const char *cstrClean=strCleanCommand.c_str();
  //
  snprintf(command, sizeof(command), cstr, iFontSize);
  cout<<command<<endl;
  system(command);
  //
  //system(cstr);
  system(cstrClean);
}

vector<string> readDirectoryData(char* strFolderName)
{
  DIR *dir;
  vector<string> lsFileData;
  struct dirent *ent;
  if ((dir = opendir (strFolderName)) != NULL) {
    /* print all the files and directories within directory */
    while ((ent = readdir (dir)) != NULL) {
      lsFileData.push_back(string(ent->d_name));
      printf ("%s\n", ent->d_name);
    }
    closedir (dir);
  } else {
    /* could not open directory */
    perror ("");
    //return EXIT_FAILURE;
  }
  return lsFileData;

}
vector<string> readFileFonts(char *strFileName)
{
  string line;
  vector<string> listFonts;
  ifstream myfile(strFileName);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
      listFonts.push_back(line);
    }
    cout<<strFileName<<endl;
    myfile.close();
    return listFonts; 
  }

  else cout << "Unable to open file";


}

int main()
{
  //string strFileTxt="Hello.txt";
  //string strFileImageOut="Hello.png";
  //string strFontName="Arial Italic";
  char* strFileFonts=FONTS_FILE;
  char* strFolderName=DATA_DIR;
  vector<string> lsFileData=readDirectoryData(strFolderName);
  vector<string> lsFonts=readFileFonts(strFileFonts);
  cout<<"Here"<<endl;
  vector<string>::iterator itrbegin = lsFileData.begin();
  vector<string>::iterator itrend = lsFileData.end();
  int count = 0;
  int i;
  int iFontSize;
  while(itrbegin != itrend)
  {
    cout<<*itrbegin;
    i=rand()%lsFonts.size();
    iFontSize=rand()%10+10;
    cout<<"Font:"<<i<<lsFonts[i]<<lsFonts.size()<<endl;
    createImage(strFolderName+*itrbegin,"out"+*itrbegin+".png",lsFonts[i],iFontSize);
    itrbegin++;
  }

    //createImage(strFileTxt,strFileImageOut,strFontName);
  return 0;
}
  