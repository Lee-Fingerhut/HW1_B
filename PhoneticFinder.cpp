//
//  PhoneticFinder.cpp
//  phonetic-search-a
//
//  Created by Lee Fingerhut on 21/03/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <cassert>
#include "PhoneticFinder.hpp"
using namespace std;

class exnotfound: public exception {
  virtual const char* what() const throw() {
    return "word was not found";
  }
} myexnotfound;

class exempty: public exception {
  virtual const char* what() const throw() {
    return "word is empty";
  }
} myexempty;

class notoneword: public exception {
  virtual const char* what() const throw() {
    return "illegale word";
  }
} myword
;
namespace phonetic {

bool is_equal(string src, string chk) {
    if(src.length() != chk.length()) {
        return 0 ;
    }
    int count_equal = 0 ;
    for(int i=0; i<src.length(); i++) {
        src[i] = towlower(src[i]);
        chk[i] = towlower(chk[i]);
            
        if(src[i] == chk[i]) {
            count_equal++;
            continue;
        }
        if( (src[i] == 'v' && chk[i] =='w') ||
            (src[i] == 'w' && chk[i] =='v') ) {
            count_equal++;
            continue;
        }
        if( (src[i] == 'b' && chk[i] =='f') ||
            (src[i] == 'f' && chk[i] =='b') ) {
            count_equal++;
            continue;
        }
        if( (src[i] == 'b' && chk[i] =='p') ||
            (src[i] == 'p' && chk[i] =='b') ) {
            count_equal++;
            continue;
        }
        if( (src[i] == 'f' && chk[i] =='p') ||
            (src[i] == 'p' && chk[i] =='f') ) {
            count_equal++;
            continue;
        }
        if( (src[i] == 'g' && chk[i] =='j') ||
            (src[i] == 'j' && chk[i] =='g') ) {
            count_equal++;
            continue;
        }
        if( (src[i] == 'c' && chk[i] =='q') ||
            (src[i] == 'q' && chk[i] =='c') ) {
            count_equal++;
            continue;
        }
        if( (src[i] == 'c' && chk[i] =='k') ||
            (src[i] == 'k' && chk[i] =='c') ) {
            count_equal++;
            continue;
        }
        if( (src[i] == 'q' && chk[i] =='k') ||
            (src[i] == 'k' && chk[i] =='q') ) {
            count_equal++;
            continue;
        }
        if( (src[i] == 's' && chk[i] =='z') ||
            (src[i] == 'z' && chk[i] =='s') ) {
            count_equal++;
            continue;
        }
        if( (src[i] == 'd' && chk[i] =='t') ||
            (src[i] == 't' && chk[i] =='d') ) {
            count_equal++;
            continue;
        }
        if( (src[i] == 'o' && chk[i] =='u') ||
            (src[i] == 'u' && chk[i] =='o') ) {
            count_equal++;
            continue;
        }
        if( (src[i] == 'i' && chk[i] =='y') ||
            (src[i] == 'y' && chk[i] =='i') ) {
            count_equal++;
            continue;
        }
    }
    return (count_equal == src.length());
}

string find(string text ,string word) {
    if (word.empty()) {
        throw myexempty;
    }
    for(int i=0; i<word.length(); i++)
    {
        if(word[i] == ' ')
        {
            throw myword;
        }
    }
    istringstream iss(text);
    do {
        string subs;
        iss >> subs;
        if (is_equal(word,subs)) {
            return subs ;
        }
    } while (iss);
    throw myexnotfound ;
}
}


