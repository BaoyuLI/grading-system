#include "grades.h"
// remainder_10(x,y) produce the 10 times of remainder of x divided by y
int remainder_10 (int x, int y) {
  return ((x % y) * 10)/y;
}

int round_closest(const int a, const int b) {
  if (remainder_10 (a,b) > 5) {
    return a/b + 1;
  } else {
    return a/b;
  }
}
// wrong(total,correct,absent) produce the the quantity of wrong answers
int wrong (int total,int correct,int absent) {
  return total - correct - absent;
}

// counted(total,correct) produce the quantity of answers that
// is counted in the clicker grade
int counted (int total,int correct) {
  if (correct>=total*3/4) {
    return 0;
  } else {
    return total*3/4 - correct;
  }
}

int clicker_grade(const int total, const int correct, const int absent) {
  if (correct>=total*3/4) {
    return 100;
  } else if (wrong(total,correct,absent)>=counted(total,correct)) {
    return 100*(correct*2+counted(total,correct))/(2* (total*3/4));
  } else {
    return 100*(correct*2+wrong(total,correct,absent))/(2*(total*3/4));
  }
}

int final_grade(const int part, const int assn, 
                const int midterm, const int final) {
  return round_closest(part*5+assn*20+midterm*25+final*50,100);
}

// min(orig,adj) produce the smaller value bewteen original 
// grade(orig) and adjusted grade(adj)
int min (int orig, int adj) {
  if (orig >= adj) {
    return adj;
  } else {
    return orig;
  }
}
int adjusted_final_grade(const int part, const int assn, 
                         const int midterm, const int final) {
  if ((assn < 50)||(midterm < 50)||(final < 50)) {
    return min (final_grade(part,assn,midterm,final),46);
  } else {
    return final_grade(part,assn,midterm,final);
  }
}
