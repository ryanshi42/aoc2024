/*
 * Click `Run` to execute the snippet below!
 */

/*
We now want to extend the parsing capabilities to handle the situation when the max repetition quantifier is not specified like in the following example:

isMatch("aa","a{1,}") → true
isMatch("aabb","a{3,}b{1,}") → false
isMatch("aaabbb","a{1,}b{3,}") → true
isMatch("aaabbbc","a{1,}b{3,}") → false
 */
 /*
 We now want to extend the syntax we support to cover numeric ranges like in the following examples

isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("a", "a{5}") → false
isMatch("aa","a{2}") → true
isMatch("aa","a{1,3}") → true
isMatch("aaa","a{1,3}") → true
isMatch("ab","a{1,3}b{1,3}") → true
isMatch("ab","a{1,3}b{2,3}") → false
isMatch("abc","a{1,3}b{1,3}c") → true
isMatch("abbc","a{1,3}b{1,2}c") → true
isMatch("abbbc","a{1,3}b{1,2}c") → false
isMatch("abca","a{1,3}b{1,3}c") → false
isMatch("acbac","a{1,3}b{1,3}c") → false
isMatch("abccccc","a{1,3}b{1,3}cc{1,3}") → false

aaa{3}

You should expect that:
* we should still be supporting the base case (i.e. `a{2}`) on top of the new ranges
* both min and max number of repetitions are provided, in the right order (`1 <= min <= max <= 9`)
* for the sake of simplicity ambiguous patterns like `a{1,3}a{1,3}` should not be supported nor expected
* the regexes are _never_ malformed. I.e. it's not necessary to handle situations like `a{,}` or `a}`, etc
  */

import java.io.*;
import java.util.*;

/*
 * To execute Java, please define "static void main" on a class
 * named Solution.
 *
 * If you need more classes, simply define them inline.
 */

class Solution {
  public record Pattern(char c, int min, int max) {
    public Pattern(char c, int n) { this(c, n, n); }
    public Pattern(char c) { this(c, 1); }
  }

  static List<Pattern> parsePattern(String pattern) {
    List<Pattern> parsedPattern = new ArrayList<>();

    int i = 0;
    while (i < pattern.length()) {
      char c = pattern.charAt(i);

      Pattern curr;
      if (i < pattern.length() - 1 && pattern.charAt(i + 1) == '{') {
        int min = Character.digit(pattern.charAt(i + 2), 10);
        if (pattern.charAt(i + 3) == ',') {
          int max;
          if (pattern.charAt(i + 4) == '}') {
            max = Integer.MAX_VALUE;
            i += 5;
          } else {
            max = Character.digit(pattern.charAt(i + 4), 10);
            i += 6;
          }
          curr = new Pattern(c, min, max);
        } else {
          i += 4;
          curr = new Pattern(c, min);
        }
      } else {
        int count = 0;
        while (i < pattern.length() && pattern.charAt(i) == c) {
          if (i < pattern.length() - 1 && pattern.charAt(i + 1) == '{') break;
          count++;
          i++;
        }
        curr = new Pattern(c, count);
      }

      if (!parsedPattern.isEmpty() && parsedPattern.get(parsedPattern.size() - 1).c() == curr.c()) {
        parsedPattern.set(
          parsedPattern.size() - 1,
          new Pattern(
            curr.c,
            curr.min + parsedPattern.get(parsedPattern.size() - 1).min,
            curr.max + parsedPattern.get(parsedPattern.size() - 1).max
          )
        );
      } else {
        parsedPattern.add(curr);
      }
    }
  
    
    return parsedPattern;
  }

  static boolean isMatch(String str, String pattern) {
    List<Pattern> parsedPattern = parsePattern(pattern);

    int i = 0;
    for (Pattern p : parsedPattern) {
      int count = 0;
      while (i < str.length() && str.charAt(i) == p.c()) {
        i++;
        count++;
      }
      if (count < p.min() || count > p.max()) return false;
    }

    return i == str.length() && true;
  }

  public static void main(String[] args) {
    System.out.println(parsePattern("a{1,}b{3,}"));

     System.out.println("1 Expected: False, your code: " + isMatch("aa","a"));
     System.out.println("2 Expected: True, your code: " + isMatch("aa","aa"));
     System.out.println("3 Expected: False, your code: " + isMatch("aaa","a"));
     System.out.println("4 Expected: False, your code: " + isMatch("a","a{5}"));
     System.out.println("5 Expected: True, your code: " + isMatch("aa","a{2}"));
     System.out.println("6 Expected: False, your code: " + isMatch("aaa","a{2}"));
     System.out.println("7 Expected: True, your code: " + isMatch("ab","a{1}b{1}"));
     System.out.println("8 Expected: False, your code: " + isMatch("ab","a{2}b{1}"));
     System.out.println("9 Expected: True, your code: " + isMatch("abc","a{1}b{1}c"));

     System.out.println("10 Expected: True, your code: " + isMatch("aaaaa","aaa{3}"));

     System.out.println("11 Expected: True, your code: " + isMatch("aaaaaaaa","aaa{3}a{3}"));

     System.out.println("12 Expected: True, your code: " + isMatch("aaaaaa","aaa{3}a{1}"));
     
     System.out.println("13 Expected: True, your code: " + isMatch("aabc","aa{1}b{1}c{1}"));

     System.out.println("14 Expected: True, your code: " + isMatch("aaaa","a{2}a{2}"));

     // P2
     System.out.println("15 Expected: True, your code: " + isMatch("aa","a{1,3}"));
     System.out.println("16 Expected: True, your code: " + isMatch("ab","a{1,3}b{1,3}"));
     System.out.println("17 Expected: False, your code: " + isMatch("ab","a{1,3}b{2,3}"));
     System.out.println("18 Expected: True, your code: " + isMatch("abc","a{1,3}b{1,3}c"));
     System.out.println("19 Expected: True, your code: " + isMatch("abbc","a{1,3}b{1,2}c"));
     System.out.println("20 Expected: False, your code: " + isMatch("abbbc","a{1,3}b{1,2}c"));
     System.out.println("21 Expected: False, your code: " + isMatch("abca","a{1,3}b{1,3}c"));
     System.out.println("22 Expected: False, your code: " + isMatch("acbac","a{1,3}b{1,3}c"));
     System.out.println("23 Expected: False, your code: " + isMatch("abccccc","a{1,3}b{1,3}cc{1,3}"));
     
     System.out.println("24 Expected: True, your code: " + isMatch("aa","a{1,}"));
     System.out.println("25 Expected: False, your code: " + isMatch("aabb","a{3,}b{1,}"));
     System.out.println("26 Expected: True, your code: " + isMatch("aaabbb","a{1,}b{3,}"));
     System.out.println("27 Expected: False, your code: " + isMatch("aaabbbc","a{1,}b{3,}"));

     System.out.println("28 Expected: True, your code: " + isMatch("aaaaa","a{1,}a{2,8937498759823745897432985729837598734985}"));
  }
}




// # Test cases
// if __name__ == '__main__':
//     print(f'1 Expected: False, your code: {isMatch("aa","a")}')
//     print(f'2 Expected: True, your code: {isMatch("aa","aa")}')
//     print(f'3 Expected: False, your code: {isMatch("aaa","aa")}')
//     print(f'4 Expected: False, your code: {isMatch("a", "a{5}")}')
//     print(f'5 Expected: True, your code: {isMatch("aa","a{2}")}')
//     print(f'6 Expected: False, your code: {isMatch("aaa","a{2}")}')
//     print(f'7 Expected: True, your code: {isMatch("ab","a{1}b{1}")}')
//     print(f'8 Expected: False, your code: {isMatch("ab","a{2}b{1}")}')
//     print(f'9 Expected: True, your code: {isMatch("abc","a{1}b{1}c")}')