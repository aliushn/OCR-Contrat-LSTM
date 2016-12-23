#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#define FONTS_DIR "~/2016/Workspace/brexia/Decembre/CodeSource/OCR-Contrat/Text2Image/Fonts"
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

int main()
{
  string strFileTxt="Hello.txt";
  string strFileImageOut="Hello.png";
  string strFontName="arial";
  createImage(strFileTxt,strFileImageOut,strFontName);
  return 0;
}