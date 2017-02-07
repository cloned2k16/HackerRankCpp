// HackerRankCpp.cpp : Defines the entry point for the console application.
//
  


#include "stdafx.h"
#include <conio.h>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "string"                        // std::getline !!

#include "SolutionBase.h"
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    struct                              _INIT                       {
	                                    _INIT                       ()                              {
		    std::cout << "_INIT finished" << std::endl;
	    }
    };
    _INIT                               static_init;
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    static std::streambuf *             cinbuf;
    static std::streambuf *             coutbuf;
    static const int                    max_path_len                = 1024;
    static char                         progName                    [max_path_len];
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    std::streambuf *                    redirect_from               (std::string fileName)          {
        std::ifstream in(fileName);
        std::streambuf * cinbuf = std::cin.rdbuf();                                                 //  save org buff
        //ios_base::sync_with_stdio(false);
        std::cin.tie    (0);
        std::cin.rdbuf  (in.rdbuf());                                                               //  redirect std::cin to fileName
        return cinbuf;                                                                              //  OK
    }
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    std::streambuf *                    redirect_to                 (std::string fileName)          {
        std::ofstream out(fileName);
        std::streambuf * coutbuf = std::cout.rdbuf();                                               //  save org buff
        std::cout.rdbuf(out.rdbuf());                                                               //  redirect std::cout to fileName
        return coutbuf;                                                                             //  OK
    }
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    bool                               exist                        (const char * fileName)         {
        struct stat buffer;
        return (stat(fileName, &buffer) == 0);
    }
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    int                                 test                        (char * name
                                                                    , std::vector <int> cases )     {
	    IFactory* factory = SolutionBase::solutionFactory()[name];
	    if (factory != NULL) {
            for (unsigned int tc=0; tc < cases.size() ;tc++){
		        SolutionBase* sol = factory->create();
                if (sol){
                    std::string path (progName);
                    std::size_t pos = path.find_last_of("\\");
                                pos = path.find_last_of("\\",pos-1);
                    path = path.substr(0,pos);

                    char testFile   [max_path_len];
                    char outFile    [max_path_len];
                    char resFile    [max_path_len];

                    //sprintf(testFile,"%s\\HackerRankCpp\\%s\\input%02d.txt",path.c_str(),name,cases[tc]);
                    int tN=cases[tc];
                    sprintf(testFile, "..\\HackerRankCpp\\%s\\input%02d.txt"    , name, tN);
                    sprintf(outFile , "..\\HackerRankCpp\\%s\\output%02d.txt"   , name, tN);
                    sprintf(resFile , "..\\HackerRankCpp\\%s\\res%02d.txt"      , name, tN);

                    //std::cout << "input file: " << testFile << std::endl;

                    if (exist(testFile) && exist(outFile)) {

                        std::ifstream in(testFile);
                        std::streambuf * cin_org = std::cin.rdbuf();
                        std::cin.tie(0);
                        std::cin.rdbuf(in.rdbuf());

                        std::ofstream out(resFile);
                        std::streambuf * cout_org = std::cout.rdbuf();
                        std::cout.rdbuf(out.rdbuf());
                        
                        std::vector <std::string> o;
                        std::vector <std::string> r;

                        if (cin_org && cout_org){
                            sol->main();

                            std::cin.rdbuf  (cin_org);                                                  //  restore standard input
                            std::cout.rdbuf (cout_org);                                                 //  restore standard output
                            in .close();
                            out.close();                                                                //  flush result!

                            std::ifstream file;
                            std::string line;

                            file.open(resFile, std::ifstream::in);
                            while (std::getline(file, line)) r.push_back(line);
                            file.close();

                            file.open(outFile, std::ifstream::in);
                            while (std::getline(file, line)) o.push_back(line);
                            file.close();


                            if (o.size() == r.size()) {
                                bool error=false;
                                for (int ln = 0; ln < o.size(); ln++) {
                                    if (o[ln] != r[ln]) {
                                        std::cerr << "ERROR at line: " << (ln + 1) << " ( " << o[ln] << " != " << r[ln] << ")" << std::endl;
                                        error=true;
                                    }
                                }
                                if (!error) {
                                    std::cout << "test [" << tN << "] SUCCESS!" << std::endl;
                                }
                                
                            }
                            else {
                                std::cerr << "ERROR result file size mismatch! out: " << o.size() << " res: " << r.size() << std::endl;
                            }
                        }
                        else {
                            std::cerr << "Sorry can't redirect standard IO" << std::endl;
                        }
                    }
                    else {
                        std::cout << "file: " << testFile << " or " << outFile << " doesn't exist!" << std::endl;
                    }
                }
                else {
                    
                }
            }
	    }
	    else {
		    std::cout << "sorry can't find class for " << name << std::endl;
	    }
	    return 0;
    }
//	-----------------------------------	---------------------------	-------------------------------	--------------------
    int                                 main                        (int argc, char* argv [])       {
	    std::cout << "here we go" << std::endl;
        if (argc<=1){
            if (std::strlen(argv[0]) >= max_path_len) { // >= !! 
                std::cerr << "Unexpected program name / path much too long!";
                return -1;
            }
            std::strcpy(progName,argv[0]);
            //std::cout << "args: " << progName << std::endl;

            test("SherlockPairs"            , { 0 , 3 });

            test("SherlockPermutations"     , { 7 });
        }
        else {

        }
        _getch();
    	return 0;
    }   
//	-----------------------------------	---------------------------	-------------------------------	--------------------

