// clicker_grade(total,correct,absent) calculate the iclicker 
// grade by counting the best 75% of total,correct questions 
// worth 2 points,incorrect question worth 1 points.
// requires: total is > 0 and divisible by 4
//           total >= correct + absent
int clicker_grade(const int total, const int correct, const int absent);

// round_closest(a,b) return the integer value of a/b rounded to 
// the closest integer,if (a/b)is exactly in between a and b,
// then it should round down.
// requires: a >= 0, b > 0
int round_closest(const int a, const int b);

// final_grade(part,assn,midterm,final) calculate the final 
// grade from 5% of part,20% of assn,25% of midterm and 50% of // final.the final grade should be rounded to the nearest integer.
// requires: 0 <= all parameters <= 100
int final_grade(const int part, const int assn, 
                const int midterm, const int final);


// requires: 0 <= all parameters <= 100
int adjusted_final_grade(const int part, const int assn, 
                const int midterm, const int final);
