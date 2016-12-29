package ctci;

/**
 * Created by Soularpower on 12/12/2016.
 */
public abstract class solutions {

    // Chapter 1

    // 1.1
    // Implement an algorithm to determine if a string has all unique characters. What if
    // you cannot use additional data structures?
    public static boolean hasUniqueCharacter(String str) {
        int len = str.length();

        // Assuming ASCII only:
        boolean[] characters = new boolean[256]; // Synatax?

        for (int i = 0; i < len; i++) {
            int asciiValue = ( (int) str.charAt(i));
            if (characters[asciiValue] == true) {
                return false;
            } else {
                characters[asciiValue] = true;
            }
        }

        return true;
    }

    //1.2 Write a function in C or C++ that reverses a null terminated string
    // Obviously this is java, so this is just using similar syntax:
//
//    public static String reverseString(char[] str) {
//        int     front = 0,              // index of front
//                back = strlen(str) - 1; // index of back
//
//        if (strlen(str) <= 1) return str;
//        else {
//            while (front < back) {
//                swapCharInString(str, front, back);
//                // swapCharInString(str, i, j) { char tmp = str[i]; str[i] = str[j]; str[j] = tmp; }
//                front++; back--;
//            }
//        }
//
//        return str;
//    }

    // 1.3 Given two strings, write a method to decide if one is a permutation of the other
    // First idea: Just sort both strings and then compare them
    // Optimize by checking if they have the same length -- if not, of course not permutations
    public static boolean isPermutationOf(String a, String b) {
        if (a.length() != b.length()){
            return false;
        } else {
            String aSort = sortString(a);
            String bSort = sortString(b);
            return aSort.equals(bSort);
        }
    }

    public static String sortString(String str) {
        char[] chars = str.toCharArray();
        java.util.Arrays.sort(chars);
        return new String(chars);
    }


    // 1.4
    // Write a method to replace all spaces in a string with '%20'. You may assume that the
    //    string has sufficient space at the end of the string to hold the additional characters,
    //    and that you are given the "true" length of the string. (Note: if implementing in Ja
    public static char[] replaceSpaces(char[] str, int len) {

        // First, count the number of spaces in original str
        int spaceCount = countSpaces(str, len);

        // Start placing characters at the end of the string in the space we need
        int newLen = len + (spaceCount * 2); // mistake was here, I multiplied by 3 instead of 2 ... only need 2 MORE, total of 3 per space
        int i = len - 1;
        int j = newLen - 1;
        str[newLen] = '\0';

        while (i >= 0) {
            if (str[i] == ' ') {
                str[j] = '0';
                str[j - 1] = '2';
                str[j - 2] = '%';
                j = j - 3;
            }
            else {
                str[j-1] = str[i];
                j--;
            }
            i--;
            System.out.println(str);
        }
//        System.out.println("Orig:\t\'" + str + '\'');
//        System.out.println("Spaces:\t" + spaceCount);

        return str;
    }

    public static int countSpaces(char[] str, int len) {
        int count = 0;

        for (int i = 0; i < len; i++) {
            char letter = str[i];

            if (letter == ' ') {  // characters must be in single quotes!
                count++;
            }
        }
        return count;
    }




}
