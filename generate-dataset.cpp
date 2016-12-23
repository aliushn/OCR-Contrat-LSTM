#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <dirent.h>
//#define FONTS_DIR "~/2016/Workspace/brexia/Decembre/CodeSource/OCR-Contrat/Text2Image/Fonts"
#define FONTS_DIR "/usr/share/fonts/WindowsFonts/"
#define DATA_DIR  "./data/"
using namespace std;
void createImage(string strFileTxt, string strFileImageOut, string strFontName)
{
  string strCommand;
  string strFontsDir=FONTS_DIR;
  strCommand="text2image --text="+strFileTxt+" --outputbase="+strFileImageOut+" --font='"+ strFontName+ "'" + " --degrade_image=true --exposure=-8 --fonts_dir="+strFontsDir;
  cout <<strCommand<<endl;
  const char *cstr = strCommand.c_str();
  system(cstr);
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
int main()
{
  string strFileTxt="Hello.txt";
  string strFileImageOut="Hello.png";
  string strFontName="Arial Italic";
  char* strFolderName=DATA_DIR;
  vector<string> lsFileData=readDirectoryData(strFolderName);
  vector<string>::iterator itrbegin = lsFileData.begin();
  vector<string>::iterator itrend = lsFileData.end();
  int count = 0;
  while(itrbegin != itrend)
  {
    cout<<*itrbegin;
    createImage(strFolderName+*itrbegin,"out"+*itrbegin+".png",strFontName);
    itrbegin++;
  }

    //createImage(strFileTxt,strFileImageOut,strFontName);
  return 0;
}
  