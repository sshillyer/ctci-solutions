package ctci;

import java.util.ArrayList;

import static ctci.solutions.replaceSpaces;

public class Main {

    public static void main(String[] args) {
//        test1_1();
//        test1_3();
//        test1_4(); // this doesn't work, blahhhhh

        // Chapter 2 stuff....

        // See if MyLinkedList works:
        MyLinkedList list = new MyLinkedList();
        list.print();
        list.appendToTail(1);
        list.appendToTail(99);
        list.appendToTail(-913134);
        list.print();

    }



    public static void test1_1() {
        String[] testStrings = {"",     "A",    "aa", "abc", "Aa", "aaa", "BBB", "zAaZ"};
        Boolean[] hasUnique = { true,   true,   false, true,  true, false, false, true};

        for (int i = 0; i < testStrings.length; i++) {

            if (solutions.hasUniqueCharacter(testStrings[i]) != hasUnique[i] ) {
                System.out.println("Failure: " + testStrings[i] + " failed test.");
            } else {
                System.out.println("Pass: " + testStrings[i]);

            }
        }
    }

    public static void test1_3() {
        // 1.3
        String strs[] = {"codeChallenge",   "CodeChallenge", "ijefthi "};
        String strs2[] = {"ChallangeCode",  "ChallengeCode", "jifehi t"};

        for (int i = 0; i < strs.length; i++) {
            System.out.println("Is " + strs[i] + " permutation of " + strs2[i] + "? : " + solutions.isPermutationOf(strs[i], strs2[i]));
        }
    }

    public static void test1_4() {
        // 1.4
//        String strs[] = {   "I have several spaces.",
//                            "One space",
//                            " pre-space",
//                            "post-space ",
//                            "three spaces is not enough",
//                            "big       gap"
//        };

        int bigGapLen = 10;
        char[] bigGap = {'b', 'i', 'g', ' ', ' ', ' ', ' ', 'g', 'a', 'p', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};

        System.out.println("Original:\n");
        System.out.println(bigGap);
        System.out.println("\nReplaced:\n");
        replaceSpaces(bigGap, bigGapLen);
        System.out.println(bigGap);
    }

}
